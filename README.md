🔥 Gas & Fire Detection Alarm System
A smart kitchen safety system designed to detect gas leaks, monitor temperature and humidity, and trigger an alarm when thresholds are exceeded. Built using an ESP8266 microcontroller, DHT11 sensor (for temperature and humidity), and an MQ2 gas sensor.

🚀 Features
🔍 Real-time monitoring of:

Gas concentration (smoke, LPG, etc.)

Ambient temperature

Humidity levels

🔔 Buzzer alarm activated when dangerous levels are detected

🧠 Simple and efficient C-based programming for microcontrollers

📊 Serial monitor output for live data visualization

🛠️ Components Used
Component	Description
ESP8266	Microcontroller (NodeMCU)
DHT11	Temperature & Humidity Sensor
MQ2	Gas/Smoke Sensor
Buzzer	For audio alert
Jumper Wires	Connection between components
Breadboard	Prototyping base
📐 Circuit Diagram
DHT11 connected to D4 (GPIO2)

MQ2 AOUT to A0

MQ2 DOUT to D1 (GPIO5)

Buzzer to D2 (GPIO4)

⚙️ Thresholds
Parameter	Threshold Value
Temperature	> 30°C
Humidity	> 70%
Gas Level	Analog > 300
Gas Detected	Digital = HIGH
🧾 How it Works
The ESP8266 reads:

Temperature and humidity from the DHT11.

Analog and digital gas values from the MQ2.

If any value exceeds the predefined threshold:

The buzzer is activated to alert the user.

The readings are also printed on the Serial Monitor for debugging or observation.

🧠 Code Summary
cpp
Copier
Modifier
if (t > TEMP_THRESHOLD || h > HUM_THRESHOLD || mq2AValue > MQ2_THRESHOLD || mq2DValue == HIGH) {
  digitalWrite(BUZZERPIN, HIGH);  // Alarm!
} else {
  digitalWrite(BUZZERPIN, LOW);   // All safe
}
🔧 Setup & Upload
Install Arduino IDE.

Add ESP8266 board support via Board Manager.

Install the DHT sensor library from Library Manager.

Connect your ESP8266 to PC via USB.

Select the correct board (NodeMCU 1.0) and COM port.

Upload the code.

📦 Libraries Required
ESP8266WiFi.h

DHT.h

Install them from the Arduino Library Manager.

🔐 Future Improvements
Add Wi-Fi connectivity to send alerts via email or phone.

Display real-time data on a web dashboard.

Add flame detection or CO sensors for expanded safety.
