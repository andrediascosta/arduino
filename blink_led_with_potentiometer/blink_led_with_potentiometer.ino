/*
  Blink

  Turns an LED on, then off, repeatedly.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// min interval for blinking
int MIM_BLINK_INTERVAL = 50;
// the resistor value
int MAX_VARIABLE_RESISTENCE_VAL = 1023;

int LED_BRIGHTNER = 3;
int MAX_BRIGHTNESS = 255;

int sensorValue;
float voltage;
int brightness;    // how bright the LED is

// the setup function runs once when you press reset or power the board
void setup() { 
  Serial.begin(9600);  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize pin led as an output for brightness.
  pinMode(LED_BRIGHTNER, OUTPUT);  
}

// the loop function runs over and over again forever
void loop() {
  // for a 10K var resistor, connect the middle to arduino Analog IN 0 (A0), the 1st to the power 5V and the 3th to GRD
  sensorValue = analogRead(A0);
  // print out the value you read
  Serial.print("Resistor readings (ohm): ");
  Serial.println(sensorValue);
  Serial.print("Voltage readings (v): ");
  Serial.println(ohms_to_volts(sensorValue));

  // to blink the led (can use the arduino built in or other from digital)
//  blink_led(MIM_BLINK_INTERVAL + (MAX_VARIABLE_RESISTENCE_VAL - sensorValue) * 2);

  // to change the led intensity connect one led with a resistor (220 ohm) to the LED pin
  change_led_brightness(normalize_ohms(sensorValue));  
}

// changes the interval of led blinking
void blink_led(int delay_time) { 
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delay_time);                 // wait some time
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(delay_time); 
}

//changes de led brigthness
void change_led_brightness(float value) {  
  brightness = value * MAX_BRIGHTNESS;
  
  Serial.print("Brightness: ");
  Serial.println(brightness);
  /*
  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" or "PWM" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.
  */
  analogWrite(LED_BRIGHTNER, brightness);
  delay(10);
}

float ohms_to_volts(int ohms_value) {
  //5V is the max voltage
  return ohms_value * (5.0 / MAX_VARIABLE_RESISTENCE_VAL);
}
float normalize_ohms(int ohms_value) {
  return ohms_value * (1.0 / MAX_VARIABLE_RESISTENCE_VAL);
}

