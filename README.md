# 🤖 Robotic Arm with Mecanum Wheels

This project is a **final thesis** for the vocational matura exam.  
It is a mobile robot with **mecanum wheels** and a **robotic arm**, controllable via **Bluetooth** using a custom mobile app.  
The project combines **mechanical engineering, electronics, and programming** – from CAD design and 3D printing, to PCB design, Arduino programming, and mobile app development.

---

## 📌 Features

- Omni-directional movement with **mecanum wheels**  
- **Robotic arm** with multiple degrees of freedom (servo motors)  
- Custom-designed **PCB** for component management  
- **Arduino Mega 2560** as the main controller  
- Control via **Bluetooth module HC-05** and a mobile app (MIT App Inventor)  
- **3D-printed parts** made from PETG filament  
- Powered and tested with **11.1V 3300 mAh LiPo battery**  

---

## 🛠️ Components Used

- Arduino Mega 2560  
- Servo motors (MG996R, SG90)  
- Bipolar stepper motors + **DRV8825 drivers**  
- Bluetooth module **HC-05**  
- Voltage regulator **LM2596**  
- Custom-designed **PCB** (Eagle CAD)  
- 3D-printed parts (Autodesk Inventor + PrusaSlicer, Ender 3 S1 printer)  

---

## 📱 Mobile App

Developed with **MIT App Inventor**.  
Main features:  
- Control of chassis movement (forward/backward/left/right/diagonal)  
- Control of robotic arm (individual joints)  
- Save and execute movement sequences  
- Adjust motor speeds  

---

## 💻 Arduino Code

The Arduino firmware is organized into several modules:  
- **Main program** (initialization, Bluetooth connection)  
- **Chassis movement control**  
- **Robotic arm control**  
- **Movement sequence storage and execution**  
- **Battery voltage monitoring** with LED warning  

---

## 🚀 Getting Started

1. Assemble the robot (chassis, arm, PCB, and wiring).  
2. Upload the Arduino code to **Arduino Mega 2560**.  
3. Install the mobile app (APK) on your smartphone.  
4. Pair with the **HC-05 Bluetooth module**.  
5. Start controlling the robot and test the functionalities.  

---

## 📊 Testing Results

- Battery runtime: ~30 minutes  
- Stepper motor driver temperature after 30 minutes: **45–55 °C**  
- Robot successfully performs omni-directional movements and basic manipulation tasks  

---

## 🔮 Future Improvements

- Add **LCD display** for battery monitoring and step sequence display  
- Support for **Xbox / other Bluetooth controllers**  
- Further PCB optimization and cable management  

---

## 👤 Author

**Marko Koren**  
Mentor: **Peter Zoroja**  
Šolski center Nova Gorica, 2024  
