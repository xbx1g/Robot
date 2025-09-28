void koraki() {
  if (korak == 4) {
    LevoPostrani();
  }
  if (korak == 5) {
    DesnoPostrani();
  }
  if (korak == 2) {
    Naprej();
  }
  if (korak == 7) {
    Nazaj();
  }
  if (korak == 3) {
    DesnoNaprej();
  }
  if (korak == 1) {
    LevoNaprej();
  }
  if (korak == 8) {
    DesnoNazaj();
  }
  if (korak == 6) {
    LevoNazaj();
  }
  if (korak == 9) {
    LevoRotacija();
  }
  if (korak == 10) {
    DesnoRotacija();
  }

  if (korak == 0) {
    Stop();
  }
  // Hitrost podvozja
  if (dataIn > 30 & dataIn < 100) {
    hitrostKoles = dataIn * 20;
  }
}

void Naprej() {
  LevoSpredajKolo.setSpeed(-hitrostKoles);
  LevoZadajKolo.setSpeed(hitrostKoles);
  DesnoSpredajKolo.setSpeed(hitrostKoles);
  DesnoZadajKolo.setSpeed(-hitrostKoles);
}
void Nazaj() {
  LevoSpredajKolo.setSpeed(hitrostKoles);
  LevoZadajKolo.setSpeed(-hitrostKoles);
  DesnoSpredajKolo.setSpeed(-hitrostKoles);
  DesnoZadajKolo.setSpeed(hitrostKoles);
}
void DesnoPostrani() {
  LevoSpredajKolo.setSpeed(-hitrostKoles);
  LevoZadajKolo.setSpeed(-hitrostKoles);
  DesnoSpredajKolo.setSpeed(-hitrostKoles);
  DesnoZadajKolo.setSpeed(-hitrostKoles);
}
void LevoPostrani() {
  LevoSpredajKolo.setSpeed(hitrostKoles);
  LevoZadajKolo.setSpeed(hitrostKoles);
  DesnoSpredajKolo.setSpeed(hitrostKoles);
  DesnoZadajKolo.setSpeed(hitrostKoles);
}
void LevoRotacija() {
  LevoSpredajKolo.setSpeed(hitrostKoles);
  LevoZadajKolo.setSpeed(-hitrostKoles);
  DesnoSpredajKolo.setSpeed(hitrostKoles);
  DesnoZadajKolo.setSpeed(-hitrostKoles);
}
void DesnoRotacija() {
  LevoSpredajKolo.setSpeed(-hitrostKoles);
  LevoZadajKolo.setSpeed(hitrostKoles);
  DesnoSpredajKolo.setSpeed(-hitrostKoles);
  DesnoZadajKolo.setSpeed(hitrostKoles);
}
void DesnoNaprej() {
  LevoSpredajKolo.setSpeed(-hitrostKoles);
  LevoZadajKolo.setSpeed(0);
  DesnoSpredajKolo.setSpeed(0);
  DesnoZadajKolo.setSpeed(-hitrostKoles);
}
void DesnoNazaj() {
  LevoSpredajKolo.setSpeed(0);
  LevoZadajKolo.setSpeed(-hitrostKoles);
  DesnoSpredajKolo.setSpeed(-hitrostKoles);
  DesnoZadajKolo.setSpeed(0);
}
void LevoNaprej() {
  LevoSpredajKolo.setSpeed(0);
  LevoZadajKolo.setSpeed(hitrostKoles);
  DesnoSpredajKolo.setSpeed(hitrostKoles);
  DesnoZadajKolo.setSpeed(0);
}
void LevoNazaj() {
  LevoSpredajKolo.setSpeed(hitrostKoles);
  LevoZadajKolo.setSpeed(0);
  DesnoSpredajKolo.setSpeed(0);
  DesnoZadajKolo.setSpeed(hitrostKoles);
}
void Stop() {
  LevoSpredajKolo.setSpeed(0);
  LevoZadajKolo.setSpeed(0);
  DesnoSpredajKolo.setSpeed(0);
  DesnoZadajKolo.setSpeed(0);
}
