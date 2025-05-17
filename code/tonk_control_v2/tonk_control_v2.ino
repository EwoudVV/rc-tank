/*
++++++++++++++ VERSION LOG ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#define SKETCH_VERSION "2"
#define SKETCH_DATE "2024-05-26"
#define SKETCH_TO_FIX ""
#define SKETCH_TO_DO ""

/*
++++++++++++++ DEBUG MODE +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#define DEBUG  // Comment this line to stay out of DEBUG mode

#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif

/*
++++++++++++++ BOARDS & PINS ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#define ARDUINO_MOTORSHIELD_REV3  // Uncomment if not applicable   https://store.arduino.cc/products/arduino-motor-shield-rev3
#ifdef ARDUINO_MOTORSHIELD_REV3   // WARNING: This motorshield uses pins D8 and D9 for brake, and A0 and A1 for current sensing!    https://store.arduino.cc/products/arduino-motor-shield-rev3
#define LEFT_DIRECTION_PIN 13
#define LEFT_PWM_PIN 11
#define RIGHT_DIRECTION_PIN 12
#define RIGHT_PWM_PIN 3
#define LEFT_CHANNEL_PIN 5   // Must be an external interrupt pin! Make sure the flwg. pins are not already used in the previous 4 lines!
#define RIGHT_CHANNEL_PIN 6  // Must be an external interrupt pin!
#endif

/*
++++++++++++++ OTHER DEFINES ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#define SERIAL_BAUDRATE 115200
#define PULSEIN_TIMEOUT_MICROSEC 1000000
#define PPM_PIXHAWK_MIN 1000
#define PPM_PIXHAWK_MAX 2000
#define LEFT_MOTOR 0  // Reverse if necessary, to change side, turning direction, ...
#define RIGHT_MOTOR !LEFT_MOTOR
#define LEFT_FORWARD 1
#define LEFT_REVERSE !LEFT_FORWARD
#define RIGHT_FORWARD 0
#define RIGHT_REVERSE !RIGHT_FORWARD
#define IDLE_SPEED_LAG 20  // Integer

/*
++++++++++++++ VARIABLES ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

void motorshield(void);
void pulsewidth(void);

int leftSpeed, rightSpeed, modus, previousModus;
unsigned long leftPulsewidth, rightPulsewidth, modePulsewidth;


void setup() {
#ifdef DEBUG
  Serial.begin(SERIAL_BAUDRATE);
#endif
  sketchInfo();
  setupMotorshield();
  delay(10);  // Delay to allow the Frsky receiver to start up after powering up the explorer
  setupReceiver();
}


void loop() {
  pw2speed();
  printPulsewidths();
  printSpeeds();
}


void sketchInfo() {
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("");
  DEBUG_PRINT("SKETCH VERSION:   ");
  DEBUG_PRINTLN(SKETCH_VERSION);
  DEBUG_PRINT("SKETCH DATE:      ");
  DEBUG_PRINTLN(SKETCH_DATE);
  DEBUG_PRINT("STILL TO FIX:     ");
  DEBUG_PRINTLN(SKETCH_TO_FIX);
  DEBUG_PRINT("STILL TO DO:      ");
  DEBUG_PRINTLN(SKETCH_TO_DO);
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("");
  DEBUG_PRINTLN("");
  delay(5000);
}
