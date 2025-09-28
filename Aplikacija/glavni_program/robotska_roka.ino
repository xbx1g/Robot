void roka() {
  // Premik servo 1 v plus smer
  while (korak == 16) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_baza.write(Servo_bazaPPos);
    Servo_bazaPPos++;
    delay(speedDelay);
  }
  // Premik servo 1 v minus smer
  while (korak == 17) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_baza.write(Servo_bazaPPos);
    Servo_bazaPPos--;
    delay(speedDelay);
  }
  // Move servo 2
  while (korak == 19) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_rama.write(Servo_ramaPPos);
    Servo_ramaPPos++;
    delay(speedDelay);
  }
  while (korak == 18) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_rama.write(Servo_ramaPPos);
    Servo_ramaPPos--;
    delay(speedDelay);
  }
  // Move servo 3
  while (korak == 20) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_komolec.write(Servo_komolecPPos);
    Servo_komolecPPos++;
    delay(speedDelay);
  }
  while (korak == 21) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_komolec.write(Servo_komolecPPos);
    Servo_komolecPPos--;
    delay(speedDelay);
  }
  // Move servo 4
  while (korak == 23) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_rotacija.write(Servo_rotacijaPPos);
    Servo_rotacijaPPos++;
    delay(speedDelay);
  }
  while (korak == 22) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_rotacija.write(Servo_rotacijaPPos);
    Servo_rotacijaPPos--;
    delay(speedDelay);
  }
  // Move servo 5
  while (korak == 25) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_gripper_premik.write(Servo_gripper_premikPPos);
    Servo_gripper_premikPPos++;
    delay(speedDelay);
  }
  while (korak == 24) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_gripper_premik.write(Servo_gripper_premikPPos);
    Servo_gripper_premikPPos--;
    delay(speedDelay);
  }
  // Move servo 6
  while (korak == 26) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_gripper_stisk.write(Servo_gripper_stiskPPos);
    Servo_gripper_stiskPPos++;
    delay(speedDelay);
  }
  while (korak == 27) {
    if (BT.available() > 0) {
      korak = BT.read();
    }
    Servo_gripper_stisk.write(Servo_gripper_stiskPPos);
    Servo_gripper_stiskPPos--;
    delay(speedDelay);
  }

  // Hitrost robotske roke
  if (dataIn > 101 & dataIn < 250) {
    speedDelay = dataIn / 10; // Change servo speed (delay time)
  }
}
