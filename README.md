# Victory.exe_AMUHACKS4.0

#AMUHACKS 4.0 #CSSAMU #AMU
# 🚦 Smart Traffic Light System for Ambulance Detection

A simple Arduino-based project that detects ambulance sirens using sound sensors and automatically controls traffic lights to give way. Ideal for smart city traffic management solutions!

## 🔍 What It Does

- Listens for ambulance sirens using sound sensors.
- Automatically changes the traffic lights based on the direction of the sound.
- Displays real-time messages on an LCD.
- Helps ambulances pass smoothly through intersections.


## 🚨 How It Works

| Sound Detected From | Action |
|---------------------|--------|
| **Sensor 1**        | Only **Green** light turns ON. LCD shows: `Ambulance Detected` |
| **Sensor 2**        | All lights (Red, Yellow, Green) turn ON.|
| **Sensor 3**        | No change in the display and traffic lights but detects the movement of the ambulance. |
| **Sensor 4**        | **Red** light stays ON. LCD shows: `Ambulance Passed` |

---

## 🧰 Components Required

- Arduino Uno
- 4 × Sound Sensors
- 3 × LEDs (Red, Yellow, Green)
- 16x2 LCD Display
- Potentiometer (for LCD contrast)
- Resistors (for LEDs)
- Breadboard + Jumper Wires


## 🎯 Why This Project?

This system mimics how future smart traffic signals can help prioritize emergency vehicles, reducing delay and saving lives. It’s beginner-friendly and great for learning about **sensors, decision logic**, and **hardware interfacing**.

---

## 🌱 Future Enhancements

- Add more sound sensors for accurate direction sensing.
- Include timers or real-time clocks for scheduled light control.
- Integrate GPS or IoT for live ambulance tracking and coordination.


## 👩‍💻 Developed By

**Janani Somasundaram**  
*2nd Year CSE Student*  
**SRM Institute of Science and Technology**

**Jecin Elizabeth Rajesh**  
*2nd Year CSE Student*  
**SRM Institute of Science and Technology**

**Mithuna Rajendran**  
*2nd Year CSE Student*  
**SRM Institute of Science and Technology**

**Supriya Namsivayam**  
*2nd Year CSE Student*  
**SRM Institute of Science and Technology**


---

> 🤖 *Feel free to fork and modify! PRs are welcome.*
