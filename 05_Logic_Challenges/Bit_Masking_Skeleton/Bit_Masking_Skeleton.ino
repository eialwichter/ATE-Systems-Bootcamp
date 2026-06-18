/*
 * Bit Masking & Register Control Skeleton
 * 
 * Objective: Control ESP32 GPIOs using direct register manipulation for speed.
 */

// Note: For ESP32, we use GPIO_OUT_REG, GPIO_OUT_W1TS_REG (Set), GPIO_OUT_W1TC_REG (Clear)
// These are defined in the ESP-IDF / Arduino core.
unsigned long  previousMillis=0;
const long interval=1000;

void setup() {
  // TODO: Set GPIO 2 (LED) as output using BIT MASKING
  // Using standard pinMode for setup is okay, but use registers for loop.
  pinMode(2, OUTPUT);//set pin 2 as output mode
}

void loop() 
{
  unsigned long currentMillis = millis();
  // TODO: Toggle GPIO 2 using XOR or specific Set/Clear registers
  //Example (Conceptual):
  if(currentMillis - previousMillis>=interval)
  {
    previousMillis = currentMillis;
    if(REG_READ(GPIO_OUT_REG) &  (1 << 2))//check if pin 2 is currently HIGH
   {
    REG_WRITE(GPIO_OUT_W1TC_REG, (1 << 2)); // if high, SET LOW
   }
  else
   {
    REG_WRITE(GPIO_OUT_W1TS_REG, (1 << 2)); // if low, SET HIGH
   }

  }
  
  // TODO: Implement a mask to check the state of multiple pins at once
  uint32_t mask = (1<<2) | (1<<4);// create mask for pins 2 and 4
  uint32_t pins_state = REG_READ(GPIO_IN_REG) & mask;// isolate and read only these pins
}







