void pozicije() {
  // Če je pritisnjena tipka shrani
  if (korak == 12) {
    if (index == 0) {
      LevoZadajKolo.setCurrentPosition(0);
      LevoSpredajKolo.setCurrentPosition(0);
      DesnoZadajKolo.setCurrentPosition(0);
      DesnoSpredajKolo.setCurrentPosition(0);
    }
    lbw[index] = LevoZadajKolo.currentPosition();  // shrani pozicijo v array
    lfw[index] = LevoSpredajKolo.currentPosition();
    rbw[index] = DesnoZadajKolo.currentPosition();
    rfw[index] = DesnoSpredajKolo.currentPosition();

    Servo_bazaSP[index] = Servo_bazaPPos;  // shrani pozicijo v array
    Servo_ramaSP[index] = Servo_ramaPPos;
    Servo_komolecSP[index] = Servo_komolecPPos;
    Servo_rotacijaSP[index] = Servo_rotacijaPPos;
    Servo_gripper_premikSP[index] = Servo_gripper_premikPPos;
    Servo_gripper_stiskSP[index] = Servo_gripper_stiskPPos;
    index++;                        // povečaj številko indexa v arrayu
    korak = 0;
  }



  // Če je pritisnjena tipka zaženi
  if (korak == 14) {
    runSteps();

    // Če je pritisnejna tipka reset
    if (dataIn != 14) {
      Stop();
      memset(lbw, 0, sizeof(lbw)); // Počisti array in zapiši začeno vrednost koračnih motorjev
      memset(lfw, 0, sizeof(lfw));
      memset(rbw, 0, sizeof(rbw));
      memset(rfw, 0, sizeof(rfw));
      memset(Servo_bazaSP, 0, sizeof(Servo_bazaSP)); // Počisti array in zapiši začeno vrednost servo motorjev
      memset(Servo_ramaSP, 0, sizeof(Servo_ramaSP));
      memset(Servo_komolecSP, 0, sizeof(Servo_komolecSP));
      memset(Servo_rotacijaSP, 0, sizeof(Servo_rotacijaSP));
      memset(Servo_gripper_premikSP, 0, sizeof(Servo_gripper_premikSP));
      memset(Servo_gripper_stiskSP, 0, sizeof(Servo_gripper_stiskSP));
      index = 0;  // Index to 0
    }
  }
}
void runSteps() {
  while (dataIn != 13) {   // Izvajanje korakov znova in znova, dokler ne pritisnemo gumba "RESETIRAJ".
    for (int i = 0; i <= index - 2; i++) {  // Izvedi vse korake ki so v indexu
      if (BT.available() > 0) {      // Preveri prihajajoče podatke
        dataIn = BT.read();
        if ( dataIn == 15) {           // Če je tipka "PAVZA" pritisnjena
          while (dataIn != 14) {         // Počakaj dokler tipka "ZAŽENI" ni spet pritisnjena
            if (BT.available() > 0) {
              dataIn = BT.read();
              if ( dataIn == 13) {
                break;
              }
            }
          }
        }
        // če je hitrost spremenjena med delovanjem
        if (dataIn > 101 & dataIn < 250) {
          speedDelay = dataIn / 10; // Spremeni hitrost servo motorjev
        }
        // Spremeni hitrost koračnih motorjev
        if (dataIn > 30 & dataIn < 100) {
          hitrostKoles = dataIn * 10;
          dataIn = 14;
        }
      }
      LevoSpredajKolo.moveTo(lfw[i]);
      LevoSpredajKolo.setSpeed(hitrostKoles);
      LevoZadajKolo.moveTo(lbw[i]);
      LevoZadajKolo.setSpeed(hitrostKoles);
      DesnoSpredajKolo.moveTo(rfw[i]);
      DesnoSpredajKolo.setSpeed(hitrostKoles);
      DesnoZadajKolo.moveTo(rbw[i]);
      DesnoZadajKolo.setSpeed(hitrostKoles);

      while (LevoZadajKolo.currentPosition() != lbw[i] & LevoSpredajKolo.currentPosition() != lfw[i] & DesnoSpredajKolo.currentPosition() != rfw[i] & DesnoZadajKolo.currentPosition() != rbw[i]) {
        LevoSpredajKolo.runSpeedToPosition();
        LevoZadajKolo.runSpeedToPosition();
        DesnoSpredajKolo.runSpeedToPosition();
        DesnoZadajKolo.runSpeedToPosition();
      }
      // Servo 1
      if (Servo_bazaSP[i] == Servo_bazaSP[i + 1]) {
      }
      if (Servo_bazaSP[i] > Servo_bazaSP[i + 1]) {
        for ( int j = Servo_bazaSP[i]; j >= Servo_bazaSP[i + 1]; j--) {
          Servo_baza.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_bazaSP[i] < Servo_bazaSP[i + 1]) {
        for ( int j = Servo_bazaSP[i]; j <= Servo_bazaSP[i + 1]; j++) {
          Servo_baza.write(j);
          delay(speedDelay);
        }
      }

      // Servo 2
      if (Servo_ramaSP[i] == Servo_ramaSP[i + 1]) {
      }
      if (Servo_ramaSP[i] > Servo_ramaSP[i + 1]) {
        for ( int j = Servo_ramaSP[i]; j >= Servo_ramaSP[i + 1]; j--) {
          Servo_rama.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_ramaSP[i] < Servo_ramaSP[i + 1]) {
        for ( int j = Servo_ramaSP[i]; j <= Servo_ramaSP[i + 1]; j++) {
          Servo_rama.write(j);
          delay(speedDelay);
        }
      }

      // Servo 3
      if (Servo_komolecSP[i] == Servo_komolecSP[i + 1]) {
      }
      if (Servo_komolecSP[i] > Servo_komolecSP[i + 1]) {
        for ( int j = Servo_komolecSP[i]; j >= Servo_komolecSP[i + 1]; j--) {
          Servo_komolec.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_komolecSP[i] < Servo_komolecSP[i + 1]) {
        for ( int j = Servo_komolecSP[i]; j <= Servo_komolecSP[i + 1]; j++) {
          Servo_komolec.write(j);
          delay(speedDelay);
        }
      }

      // Servo 4
      if (Servo_rotacijaSP[i] == Servo_rotacijaSP[i + 1]) {
      }
      if (Servo_rotacijaSP[i] > Servo_rotacijaSP[i + 1]) {
        for ( int j = Servo_rotacijaSP[i]; j >= Servo_rotacijaSP[i + 1]; j--) {
          Servo_rotacija.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_rotacijaSP[i] < Servo_rotacijaSP[i + 1]) {
        for ( int j = Servo_rotacijaSP[i]; j <= Servo_rotacijaSP[i + 1]; j++) {
          Servo_rotacija.write(j);
          delay(speedDelay);
        }
      }

      // Servo 5
      if (Servo_gripper_premikSP[i] == Servo_gripper_premikSP[i + 1]) {
      }
      if (Servo_gripper_premikSP[i] > Servo_gripper_premikSP[i + 1]) {
        for ( int j = Servo_gripper_premikSP[i]; j >= Servo_gripper_premikSP[i + 1]; j--) {
          Servo_gripper_premik.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_gripper_premikSP[i] < Servo_gripper_premikSP[i + 1]) {
        for ( int j = Servo_gripper_premikSP[i]; j <= Servo_gripper_premikSP[i + 1]; j++) {
          Servo_gripper_premik.write(j);
          delay(speedDelay);
        }
      }

      // Servo 6
      if (Servo_gripper_stiskSP[i] == Servo_gripper_stiskSP[i + 1]) {
      }
      if (Servo_gripper_stiskSP[i] > Servo_gripper_stiskSP[i + 1]) {
        for ( int j = Servo_gripper_stiskSP[i]; j >= Servo_gripper_stiskSP[i + 1]; j--) {
          Servo_gripper_stisk.write(j);
          delay(speedDelay);
        }
      }
      if (Servo_gripper_stiskSP[i] < Servo_gripper_stiskSP[i + 1]) {
        for ( int j = Servo_gripper_stiskSP[i]; j <= Servo_gripper_stiskSP[i + 1]; j++) {
          Servo_gripper_stisk.write(j);
          delay(speedDelay);
        }
      }
    }
  }
}
