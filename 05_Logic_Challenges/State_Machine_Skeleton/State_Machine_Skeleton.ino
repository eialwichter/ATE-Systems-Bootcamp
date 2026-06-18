/*
 * State Machine Skeleton
 * 
 * Objective: Implement a robust state machine for a testing sequence.
 * States: 
 *   - IDLE: Waiting for trigger.
 *   - TESTING: Running measurement for 3 seconds.
 *   - RESULT: Displaying outcome (PASS/FAIL).
 */

enum SystemState {
  IDLE,
  TESTING,
  RESULT
};

SystemState currentState = IDLE;
unsigned long stateStartTime = 0;

void setup() 
{
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case IDLE:
      //TODO: Check for Serial command or button press to start test
      Serial.println("System IDLE. Send 'S' to Start.");//print status to start command
      if(Serial.available()>0)//check if received info
      {
        char incomingChar=Serial.read();//read the incoming character

        if(incomingChar=='S'|| incomingChar=='s')//check if received the letter or capittal letter 's'
        {
          Serial.println("starting test...");//print status message to the user
          stateStartTime = currentMillis;//save the state start time for non blocking  timing
          currentState = TESTING;// transition to the next state
        }
      }
      break;

    case TESTING:
      // TODO: Measure sensor values using non-blocking timer
      bool testPassed; // boolean variable to check if the test passed or failed
      if(currentMillis-stateStartTime>=3000)//non blocking timer for 3 seconds
      {
        int sensorValue = analogRead(A0);// read the actual value from the sensor
        if (sensorValue>500)// the sensor values the test outcome
        {
          testPassed = true;// PASSED
        }
        else
        {
          testPassed = false;// FAILED

        }
        stateStartTime = currentMillis;//save the state start time for non blocking  timing
        currentState=RESULT;// transition to the next state
      }
      
      break;

    case RESULT:
      // TODO: Display results for 2 seconds then return to IDLE
      if (currentMillis - stateStartTime >= 2000)// non blocking timer for 2 seconds
      {
        if(testPassed)// check if the test passed
        {
          Serial.println("PASS");//message to the user that pass
        }
        else
        {
          Serial.println("FAIL");// message to the user that fail
        }
        currentState = IDLE;// transition back to IDLE 
      }
      break;
  }
}
