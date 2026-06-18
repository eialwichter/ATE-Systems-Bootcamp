/*
 * Software Debounce Skeleton
 * 
 * Objective: Read a physical button without using delay() or hardware filters.
 */

const int BUTTON_PIN = 4;
const unsigned long DEBOUNCE_DELAY = 50; 

int buttonState;             
int lastButtonState = LOW;   
unsigned long lastDebounceTime = 0; 

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // TODO: Implement timer-based debounce logic
  // Check if the switch changed state due to noise or actual press
  
  if (reading != lastButtonState) 
  {
    lastDebounceTime = millis();//reset the debounce timer to current time
  }
  
  if (millis() - lastDebounceTime > DEBOUNCE_DELAY) 
  {
   if (reading != buttonState) 
   {
    buttonState=reading;// update the official stable button state
    if(buttonState= LOW)//if the button is currently pressed
    {
      Serial.println("Button Pressed");//print message to the user that button pressed  
    }
   } 
  }

  lastButtonState = reading;
}
