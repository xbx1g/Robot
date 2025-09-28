#include <SoftwareSerial.h>             // uvoz knjižnic v arduino program
#include <AccelStepper.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>


Servo Servo_baza;                       // Imena sklopov robota
Servo Servo_rama;
Servo Servo_komolec;
Servo Servo_rotacija;
Servo Servo_gripper_premik;
Servo Servo_gripper_stisk;

SoftwareSerial BT(A8, 42); // Arduino(RX, TX) - HC-05 BT (TX, RX)
AccelStepper LevoZadajKolo(1, 37, 36);   // Koračni motor 1   (vrsta krmilnika koračnega motorja, DIR, STEP)
AccelStepper LevoSpredajKolo(1, 31, 30);  // Koračni motor 2
AccelStepper DesnoZadajKolo(1, 35, 34);  // Koračni motor 3
AccelStepper DesnoSpredajKolo(1, 33, 32); // Koračni motor 4

#define led 14          // led dioda za ponazoritev prazne baterije

int hitrostKoles = 2000;

int lbw[50], lfw[50], rbw[50], rfw[50]; // polja za shranjevanje pozicij/korakov

int Servo_bazaPos, Servo_ramaPos, Servo_komolecPos, Servo_rotacijaPos, Servo_gripper_premikPos, Servo_gripper_stiskPos; // trenutna pozicija
int Servo_bazaPPos, Servo_ramaPPos, Servo_komolecPPos, Servo_rotacijaPPos, Servo_gripper_premikPPos, Servo_gripper_stiskPPos; // prejšna pozicija
int Servo_bazaSP[50], Servo_ramaSP[50], Servo_komolecSP[50], Servo_rotacijaSP[50], Servo_gripper_premikSP[50], Servo_gripper_stiskSP[50]; // polja za shranjevanje pozicij/korakov servo motorjev
int speedDelay = 20;
int index = 0;
int dataIn;
int korak = 0;

void setup() {
  // Začetna hitrost koračnih motorjev
  LevoSpredajKolo.setMaxSpeed(1000);
  LevoZadajKolo.setMaxSpeed(1000);
  DesnoSpredajKolo.setMaxSpeed(1000);
  DesnoZadajKolo.setMaxSpeed(1000);
  pinMode(led, OUTPUT);
  Servo_baza.attach(2);
  Servo_rama.attach(3);
  Servo_komolec.attach(4);
  Servo_rotacija.attach(5);
  Servo_gripper_premik.attach(6);
  Servo_gripper_stisk.attach(7);
  BT.begin(38400); // Privzeta hitrost prenosa modula HC-05
  BT.setTimeout(5);
  delay(20);
  Serial.begin(38400);

  // Premik robotske roke na začetno pozicijo
  Servo_bazaPPos = 95;
  Servo_baza.write(Servo_bazaPPos);
  Servo_ramaPPos = 90;
  Servo_rama.write(Servo_ramaPPos);
  Servo_komolecPPos = 180;
  Servo_komolec.write(Servo_komolecPPos);
  Servo_rotacijaPPos = 95;
  Servo_rotacija.write(Servo_rotacijaPPos);
  Servo_gripper_premikPPos = 80;
  Servo_gripper_premik.write(Servo_gripper_premikPPos);
  Servo_gripper_stiskPPos = 90;
  Servo_gripper_stisk.write(Servo_gripper_stiskPPos);
}

void loop() {
  // Preveri prihajajoče podatke
  if (BT.available() > 0) {
    preimenovanje();
    koraki();
    roka();
    pozicije();
  }
  LevoSpredajKolo.runSpeed(); 
  LevoZadajKolo.runSpeed();
  DesnoSpredajKolo.runSpeed();
  DesnoZadajKolo.runSpeed();

  // Napetost baterije
  int sensorValue = analogRead(A0);
  float napetost = sensorValue * (5.0 / 1023.00) * 3; // pretvori 5V v 12V za branje napetosti baterije
  // Če napetost pade pod 11V se bo lučka prižgala
  if (napetost < 11.6) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
