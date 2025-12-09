# 🚀 Smart Industrial Fan – Temperature-Based Speed Control

Automatically adjusts fan speed based on ambient temperature using Arduino PWM control, with manual override, LED speed indicators, LCD display, and critical temperature alarm.

---

## 📌 **Project Overview**

This project implements an **automatic industrial cooling fan controller** using an Arduino Nano, DHT11 temperature sensor, and MOSFET-driven DC fan.
The system continuously monitors temperature and adjusts fan speed across three levels — **LOW, MEDIUM, HIGH**.
For safety, it activates a **buzzer alarm** at critical temperature. The user can also switch to **Manual Override Mode** to force maximum fan speed at any time.

---

## ✨ **Features**

### 🔥 Temperature-Based Fan Control

* Reads real-time temperature using **DHT11 sensor**
* Fan operates at 3 step-wise speeds:

  * **LOW** (< 30°C)
  * **MEDIUM** (30–40°C)
  * **HIGH** (> 40°C)

### 🚨 Critical Temperature Alarm

* When temperature exceeds **45°C**, buzzer + red LED alarm triggers
* LCD displays **“CRITICAL TEMP!”**

### 🟢 Manual Override Mode

* Push-button toggles between:

  * **AUTO MODE**
  * **MANUAL OVERRIDE (100% Fan Speed)**
* Uses simple, reliable toggle logic with `INPUT_PULLUP`

### 💡 LED Speed Indicator Bar

* **LED1 → LOW**
* **LED1 + LED2 → MEDIUM**
* **LED1 + LED2 + LED3 → HIGH / MANUAL / CRITICAL**

### 📟 LCD Display

Shows:

```
Temp: XX.X C
Mode: LOW / MED / HIGH / MANUAL / CRITICAL
```

### ⚡ MOSFET-Based Fan Driver

* Safe interfacing between Arduino PWM signal and 12V DC fan
* Back-EMF protection using diode
* Supports high-current motors safely

---

## 🛠️ **Components Used**

| Component                                     | Quantity | Purpose             |
| --------------------------------------------- | -------- | ------------------- |
| Arduino Nano                                  | 1        | Main controller     |
| DHT11 Sensor                                  | 1        | Temperature sensing |
| 12V DC Fan                                    | 1        | Cooling fan         |
| N-Channel MOSFET(IRFZ44N)                     | 1        | Fan driver          |
| 5V Active Buzzer                              | 1        | Critical alarm      |
| 16x2 I2C LCD                                  | 1        | Display             |
| LEDs (4 pcs)                                  | 3        | Speed indicator     |
| Push Button                                   | 1        | Manual override     |
| 10kΩ Resistor (optional)                      | 1        | Button stability    |
| Wires + Breadboard                            | —        | Prototyping         |

---

## 🔧 **Circuit Overview**

### **Connections Summary**

* **DHT11 → D2**
* **Button → D3 (with INPUT_PULLUP)**
* **Fan PWM → D9 → MOSFET gate**
* **Buzzer/Alarm → D8**
* **LEDs → D4, D5, D6**
* **LCD → I2C (A4 SDA, A5 SCL)**
* **Common ground** between Arduino, MOSFET, and fan supply

---

## 🧠 **How It Works**

1. Arduino reads temperature from DHT11
2. Based on thresholds, selects PWM duty cycle
3. Adjusts fan speed (LOW/MED/HIGH)
4. Updates LED indicators and LCD display
5. If critical temperature (>45°C), alarm is triggered
6. Button toggles manual override mode, forcing full-speed operation

---

## 📄 **Arduino Code**

👉 Full working code is included inside `/src/` directory in this repo.
It includes:

* Manual override logic (toggle-based)
* DHT11 reading
* LCD control
* 3-level speed bar LEDs
* Alarm system
* PWM fan control

---

## 📊 **Performance Testing**

| Temperature Range | Expected Speed   | Verified |
| ----------------- | ---------------- | -------- |
| < 30°C            | LOW              | ✅        |
| 30–40°C           | MEDIUM           | ✅        |
| > 40°C            | HIGH             | ✅        |
| > 45°C            | CRITICAL + Alarm | ✅        |
| Manual Override   | MAX Speed        | ✅        |
