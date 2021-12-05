#include <LiquidCrystal.h>
#include <Servo.h>

const int BUTTON_PIN = 8; // Arduino pin connected to button's pin
int lastButtonState;      // the previous state of button
int currentButtonState;   // the current state of button

Servo CandyServo;
const int SERVO_PIN = 7;
int angle = 0;            //the current angle of servo motor

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // LCD pins for registers
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //LCD object

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode for button

  //Servo setup:
  CandyServo.attach(SERVO_PIN); //initializing servo with pin
  CandyServo.write(angle); //Servo Initial Angle
  currentButtonState = digitalRead(BUTTON_PIN); //reading pin state
  
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
}


void loop() {
  //Intro message for the LCD
  lcd.print("Welcome! Press");
  lcd.setCursor(0,1); //Setting cursor to the next line on the LCD
  lcd.print("Button for Candy!");

  //Servo activation function below
  ServoActuate();
}


void ServoActuate(){
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  //Checking the state of pin 8
  if(lastButtonState == HIGH && currentButtonState == LOW) {

    // change angle of servo motor
    if(angle == 0){
      angle = 180;
    }

 
    CandyServo.write(angle); //control servo motor arccoding to the angle
    
    //Write ending message on the LCD
    lcd.clear();
    lcd.print("Enjoy Your");
    lcd.setCursor(0,1);
    lcd.print("Candy!");
    delay(1000); // give 1 sec delay
    CandyServo.write(0); //set servo back to 0
    lcd.clear(); //clear the LCD for into message
  }
}
