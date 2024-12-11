# Arduino-Based Smart Water Dispenser

A smart water dispenser project designed with Arduino, featuring real-time environmental monitoring and error alerts. The system includes an ultrasonic sensor to measure water level, temperature, and humidity sensors for environmental monitoring, and multiple LEDs and a buzzer for status indication and error alerts.

## Features

- **Real-Time Monitoring**: Displays temperature, humidity, and water level on a 16x2 LCD screen.
- **Error Alerts**: Activates a buzzer and red LED when:
  - The water tank is empty (distance > 50 cm).
  - The temperature exceeds 40°C.
- **Status LEDs**:
  - Blue LED for cool water.
  - Green LED for normal water.
  - Yellow LED for hot water.
  - Red LED for errors.
- **User-Friendly Display**: LCD shows live updates on temperature and humidity.

## Components Used

1. **Arduino Uno** (or compatible board)
2. **Ultrasonic Sensor** (HC-SR04)
3. **16x2 LCD Display** with I2C or standard pin connections
4. **Temperature and Humidity Sensors** (simulated using potentiometers)
5. **LEDs** (Blue, Green, Yellow, Red)
6. **Buzzer**
7. **Resistors** (for LEDs and sensors)
8. **Potentiometers** (to simulate temperature and humidity sensors)

## Circuit Diagram

Include a detailed circuit diagram here or link to an image if hosted online.

## How It Works

1. **Water Level Monitoring**:
   - The ultrasonic sensor measures the distance to the water surface.
   - If the distance is greater than 50 cm, it triggers an error state.
2. **Temperature Monitoring**:
   - The temperature is simulated using a potentiometer.
   - If the temperature exceeds 40°C, the system triggers an error state.
3. **LED Indicators**:
   - LEDs indicate the current water temperature (Cool, Normal, or Hot).
   - A red LED activates for error states.
4. **Buzzer Alerts**:
   - The buzzer beeps three times during an error state to alert the user.

## Setup and Installation

1. **Hardware Setup**:
   - Connect all components as per the circuit diagram.
   - Ensure proper power supply to the Arduino and connected devices.

2. **Software Setup**:
   - Install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).
   - Connect your Arduino board to the computer.
   - Upload the provided `WaterDispenser.ino` file to the board.

3. **Libraries Required**:
   - [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal): Built-in with the Arduino IDE.

4. **Simulating Inputs**:
   - Use potentiometers to simulate temperature and humidity variations.
   - Move an object closer or farther from the ultrasonic sensor to test water level changes.

## Code

The source code for this project is included in the repository as `WaterDispenser.ino`.

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/arduino-water-dispenser.git

