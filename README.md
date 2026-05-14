# CAN-Bus-Based-Vehicle-Body-Control-System-Using-LPC2148
CAN Bus based Vehicle Body Control System using LPC2148 ARM7 microcontrollers with real-time CAN communication for headlight, indicator, LCD, UART, onboard ADC for speed and buzzer control using Embedded C and interrupt-driven architecture.

## Overview

This project demonstrates a CAN (Controller Area Network) Bus based Vehicle Body Control System using two LPC2148 ARM7TDMI-S microcontroller nodes.

The system simulates automotive body electronics by controlling:
- Headlights
- Left Indicator
- Right Indicator
- Hazard Logic
- LCD Display
- UART Monitoring
- Buzzer Feedback

Communication between the two nodes is achieved using the CAN protocol at 125 Kbps.

---

# Features

- CAN communication using LPC2148 CAN1 controller
- Interrupt-driven switch handling
- Headlight ON/OFF control
- Left and Right indicator control
- Hazard / mutual exclusion logic
- Indicator blinking with buzzer feedback
- UART terminal monitoring
- LCD status display
- CAN Acceptance Filter implementation
- Modular Embedded C firmware design

---

# Hardware Used

- LPC2148 ARM7 Development Boards (2 Nodes)
- MCP2551 / SN65HVD230 CAN Transceiver
- Push Buttons
- LEDs
- 16x2 LCD Display
- Buzzer
- USB-UART Module
- 120Ω CAN Termination Resistors

---

# Software Used

- Embedded C
- Keil uVision IDE
- ARM-MDK Compiler

---

# System Architecture

Switch Press (Node A)
        ↓
External Interrupt
        ↓
CAN Frame Transmission
        ↓
CAN Bus
        ↓
CAN RX Interrupt (Node B)
        ↓
Output Actuation
(LEDs / LCD / UART / Buzzer)
