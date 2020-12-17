#define DEBUG

#include <SPI.h>

const int switch1 = 7; // reed switch 1
const int switch2 = 8; // reed switch 2
const int switch3 = 9; // reed switch 3
const int switch4 = 12; // reed switch 4

const int led1 = A0; // led 1 for reed switch 1
const int led2 = A1; // led 2 for reed switch 2
const int led3 = A2; // led 3 for reed switch 3
const int led4 = A3; // led 4 for reed switch 4

const int led5 = A4; // led 5 to check if the puzzle is solved
// Could be replaced with Magnet to open a door or something

const byte pinLock = A4;

int status1 = 0;
int status2 = 0;
int status3 = 0;
int status4 = 0;

void setup() {

#ifdef DEBUG
  Serial.begin(9600);
  Serial.println(F("Serial communicatin started"));
#endif

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(pinLock, OUTPUT);
  digitalWrite(pinLock, HIGH);
}

void loop() {
  bool solved = false;
  //flags
  int st1 = 0;
  int st2 = 0;
  int st3 = 0;
  int st4 = 0;
  int statusOne = 0;
  int statusTwo = 0;
  int statusThree = 0;
  int statusFour = 0;

  int one = digitalRead(led1);
  int two = digitalRead(led2);
  int three = digitalRead(led3);
  int four = digitalRead(led4);

  if (solved == false) {
    status1 = digitalRead(switch1);
    status2 = digitalRead(switch2);
    status3 = digitalRead(switch3);
    status4 = digitalRead(switch4);
  }

  // Led lights are used as checking points

  if (switchOne() == 1) {
    statusOne = statusOne + 1;
    st1 = statusOne;
    digitalWrite(led1, HIGH);
  }

  if (one == HIGH) {
    if (switchTwo() == 1) {
      statusTwo = statusTwo + 1;
      st2 = statusTwo;
      digitalWrite(led2, HIGH);
    }
  }

  if (two == HIGH) {
    if (switchThree() == 1) {
      statusThree = statusThree + 1;
      st3 = statusThree;
      digitalWrite(led3, HIGH);
    }
  }

  if (three == HIGH) {
    if (switchFour() == 1) {
      statusFour = statusFour + 1;
      st4 = statusFour;
      digitalWrite(led4, HIGH);
    }
  }



  if (one == HIGH) {
    Serial.println("led1");
    if (one == HIGH and two == HIGH) {
      Serial.println("led2");
      if (one == HIGH and two == HIGH and three == HIGH) {
        Serial.println("led3");
        if (one == HIGH and two == HIGH and three == HIGH and st4 == 1) {
            onSolveEasy();
            solved = true;
            delay(60);
        }
      }
    }
  }
}

int switchOne() { // checks if the reed switch is HIGH
  int counter1 = 0;
  int max1 = 0;

  if (status1 == HIGH) {
    counter1 = counter1 + 1;
    max1 = counter1;
  }
  return max1;
}

int switchTwo() { // checks if the reed switch is HIGH
  int counter2 = 0 ;
  int max2 = 0;
  if (status2 == HIGH) {
    counter2 = counter2 + 1;
    max2 = counter2;
  }

  return max2;
}

int switchThree() { // checks if the reed switch is HIGH
  int counter3 = 0;
  int max3 = 0;
  if (status3 == HIGH) {
    counter3 = counter3 + 1;
    max3 = counter3;
  }
  return max3;
}
int switchFour() { // checks if the reed switch is HIGH
  int counter4 = 0;
  int max4 = 0;
  if (status4 == HIGH) {
    counter4 = counter4 + 1;
    max4 = counter4;
  }
  return max4;
}

void onSolveEasy() {
#ifdef DEBUG
  Serial.println(F("Puzzle Solved"));
#endif
  digitalWrite(led5, HIGH);
  digitalWrite(pinLock, LOW);

  while (true) {

  }
}
