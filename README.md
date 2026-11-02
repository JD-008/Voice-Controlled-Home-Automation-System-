# Voice-Controlled Home Automation System

A smart home project that allows appliances to be controlled using voice commands through Google Assistant, IFTTT, and Adafruit IO. The system uses an embedded controller to receive commands and switch appliances such as lights or fans using relays, while also displaying status information on an LCD/OLED display.

## Overview

This project demonstrates an IoT-based home automation system that combines:
- Voice assistant integration (Google Assistant)
- Cloud automation (IFTTT)
- MQTT messaging (Adafruit IO)
- Embedded control logic on 8051/ESP8266 or ESP32
- Real-time appliance switching via relay modules

The main objective is to provide a low-cost, practical home automation solution for remotely controlling home appliances using voice input and cloud services.

## System Architecture

The basic workflow is as follows:

Google Assistant
   ↓
IFTTT applet
   ↓
Adafruit IO feed
   ↓
ESP8266 / ESP32 MQTT client
   ↓
Relay module / appliance control
   ↓
LCD/OLED status display

## Features

- Voice-controlled appliance switching
- Wi-Fi and MQTT-based communication
- Real-time status monitoring
- Relay-driven ON/OFF control
- Display of appliance state on LCD/OLED
- Support for integration with Google Assistant through IFTTT
- Suitable for smart lighting and home automation experiments

## Hardware Components

- 8051 microcontroller (assembly-based design)
- ESP8266 Wi-Fi module (Arduino IDE)
- ESP32 with FreeRTOS version (alternative implementation)
- Relay module
- LCD/OLED display
- Power supply
- Connecting wires and breadboard
- Appliances such as bulbs or fans

## Software Stack

- Keil µVision for 8051 assembly development
- Arduino IDE for ESP8266/ESP32 firmware
- IFTTT for voice command automation
- Adafruit IO for MQTT feeds
- C/C++ embedded code

## Project Files

- `esp8266_code.ino` — ESP8266 implementation
- `FREERTOS version` — ESP32 + FreeRTOS implementation
- `image.png` — project image/reference
- `mci_report.pdf` — project report
- `README.md` — project documentation

## Working Principle

1. The user gives a voice command via Google Assistant.
2. The command triggers an IFTTT applet.
3. The applet updates an Adafruit IO feed.
4. The ESP8266/ESP32 subscribes to that feed using MQTT.
5. The microcontroller receives the command.
6. A relay is switched ON or OFF based on the received signal.
7. The appliance status is displayed on the LCD/OLED.

## Setup Instructions

### 1. Configure Wi-Fi and IoT Services
- Set up your Wi-Fi credentials.
- Create a feed on Adafruit IO.
- Configure IFTTT applets to send commands to the feed.

### 2. Program the Microcontroller
- Open the Arduino sketch in Arduino IDE.
- Update the Wi-Fi SSID and password.
- Update the Adafruit IO username and key.
- Select the correct board and port.
- Upload the code.

### 3. Connect Hardware
- Connect the relay module to the control pin.
- Attach the appliance to the relay output.
- Wire the LCD/OLED display to the appropriate pins.
- Ensure proper power connections and safety measures.

## Usage

After setup:
- Say a command like “Turn on the light” using Google Assistant.
- The command is sent through IFTTT to Adafruit IO.
- The ESP8266/ESP32 receives the MQTT message.
- The relay toggles the connected appliance.
- The status is shown on the display.

## Notes

- This project is educational and suitable for learning IoT, embedded systems, and home automation.
- For real-world deployment, consider adding:
  - password protection
  - secure cloud authentication
  - sensor integration
  - safety interlocks
  - mobile app support

## Future Improvements

- Add support for multiple appliances
- Implement timer-based automation
- Add mobile app or web dashboard
- Use secure MQTT with TLS
- Add sensor-based automation (temperature, motion, occupancy)
- Improve UI and reporting on the display

## License

This project is intended for academic and learning purposes. Please use responsibly.

## Acknowledgements

This project was developed as a smart home automation prototype using embedded systems and IoT technologies. It demonstrates the integration of voice assistants, cloud automation, and microcontroller-driven appliance control.
