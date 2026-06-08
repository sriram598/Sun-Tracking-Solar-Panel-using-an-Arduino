#  Automatic Solar Tracking System Using Arduino

##  Overview

The Automatic Solar Tracking System is designed to improve the efficiency of solar panels by automatically orienting them toward the direction of maximum sunlight. The system uses two Light Dependent Resistors (LDRs) to detect sunlight intensity and an Arduino UNO to control the motor movement.

##  Features

- Automatic solar panel tracking
- Real-time sunlight detection using LDR sensors
- LCD display for system status
- Low-cost and energy-efficient design
- Suitable for educational and renewable energy projects

##  Components Required

- Arduino UNO
- 2 × LDR Sensors
- 16×2 I2C LCD Display
- DC Motor / Geared Motor
- Motor Driver (L293D/L298N)
- Resistors
- Jumper Wires
- Power Supply

##  Circuit Connections

| Component | Arduino Pin |
|------------|------------|
| East LDR | D2 |
| West LDR | D3 |
| Motor IN1 | D4 |
| Motor IN2 | D5 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |

##  Working

1. The East and West LDRs continuously monitor sunlight intensity.
2. Arduino compares the sensor readings.
3. If the East LDR receives more light, the motor rotates the panel toward the East.
4. If the West LDR receives more light, the motor rotates the panel toward the West.
5. When both sensors receive similar light intensity, the motor stops.
6. The LCD displays the current system status and tracking direction.


