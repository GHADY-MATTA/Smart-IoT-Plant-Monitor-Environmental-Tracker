# 🌱 Smart IoT Plant Monitor & Environmental Tracker

![Platform](https://img.shields.io/badge/platform-ESP8266%20%7C%20Blynk-blue.svg)
![Sensor](https://img.shields.io/badge/sensors-DHT11%20%7C%20Soil%20Moisture%20-green.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

A fully working IoT system that monitors **temperature**, **humidity**, and **soil moisture**, using an **ESP8266 microcontroller**, the **DHT11** sensor, a **soil moisture probe**, and **Blynk**. Includes voice control support via **Google Assistant + IFTTT** for remote activation.

---

## 📸 Demo GIF

![Demo](mpu-working.gif)

---

## 🔧 Hardware Components

| Component         | Description                        |
| ----------------- | ---------------------------------- |
| ESP8266 (NodeMCU) | Main controller board              |
| DHT11             | Measures temperature and humidity  |
| Soil Moisture     | Analog probe to detect wetness     |
| LEDs (D0, D1, D2) | Visual indicators (temp, moisture) |

---

## 📲 Features

* 🌡️ Real-time **temperature** and **humidity** readings
* 💧 Live **moisture level** feedback with alerts
* 🌐 Internet-connected dashboard via **Blynk**
* 🗣️ **Voice command control** using **Google Assistant + IFTTT**
* 📊 Serial logging for debugging

---

## 📱 Blynk Virtual Pins

| Virtual Pin | Function            |
| ----------- | ------------------- |
| V0          | Temperature (°C)    |
| V1          | Humidity (%)        |
| V6          | Moisture Value      |
| V2          | LED Control (Voice) |
| V3          | Secondary LED       |

---

## 🧠 Arduino Code Summary

### Sensors & Initialization

```cpp
#include <DHT.h>
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int moisturePin = A0;
float t, h;
```

### Voice-Controlled LED Logic

```cpp
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(D1, value);
  digitalWrite(D6, value == 0 ? HIGH : LOW);
}
```

### Moisture Sensor Logic

```cpp
int moistureValue = analogRead(moisturePin);
if (moistureValue < 300) {
  digitalWrite(D2, HIGH); // LED ON
} else {
  digitalWrite(D2, LOW);
}
Blynk.virtualWrite(V6, moistureValue);
```

---

## 🗣️ Voice Assistant Integration

You can control this system using your **voice** via **Google Assistant** + **IFTTT + Webhooks** → Blynk API.

### Example Command Flow

```text
"Hey Google, water the plant" → IFTTT Webhook → Blynk V2 → Turn on LED pump or notifier
```

### Sample IFTTT Webhook

```
URL: https://blynk.cloud/external/api/update?token=YOUR_BLYNK_TOKEN&V2=1
Method: POST
```

---

## 📁 File Structure

```
iot-smart-monitor/
├── main.ino                  # Arduino source code
├── mpu-working.gif           # Demo visualization
├── README.md                 # This documentation
```

---

## 📌 Applications

* 🪴 Smart garden or indoor plant care
* 📊 IoT environmental monitoring
* 🗣️ Voice-activated control systems
* 🌍 Remote dashboard integration

---

## 📃 License

This project is licensed under the MIT License.

---

**Built with 💚 by Ghady Matta** · GitHub: [@GHADY-MATTA](https://github.com/GHADY-MATTA)
