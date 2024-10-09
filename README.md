# Rover X

## Project Description

**Rover X** is an autonomous rover developed using a Raspberry Pi, with the primary goal of collecting and visualizing environmental data. The rover is equipped with sensors to measure **temperature**, **humidity**, and **atmospheric pressure**, enabling real-time monitoring of its operating environment. 

The collected data is transmitted to a server via a designated endpoint, ensuring storage for later analysis.

Once the data reaches the server, it is displayed on a dynamic graph, allowing real-time visualization of the three monitored variables (temperature, humidity, and pressure). This implementation leverages web technologies and communication protocols between the rover and the server, ensuring accurate and accessible visualization from any device with an Internet connection.

This project has potential applications in:
- Scientific research
- Environmental monitoring
- Development of autonomous systems

Rover X exemplifies the seamless integration of **hardware** (Raspberry Pi) with **software** (web server and endpoints) to create useful and scalable technological solutions.

## Features
- **Real-time data collection:** Monitors temperature, humidity, and pressure in real-time.
- **Dynamic visualization:** Displays live data on a graph accessible from any internet-connected device.
- **Server integration:** Data is sent via endpoints and stored for further analysis.

## Technology Stack
- **Hardware:** Raspberry Pi, sensors (temperature, humidity, pressure)
- **Software:** Python, Flask (server), Matplotlib (data visualization)
- **Protocols:** HTTP (for endpoint communication)

## Application
Rover X is well-suited for:
- Environmental monitoring
- Field research in various industries
- Autonomous system development

## Project Images

![Rover Robot](https://github.com/Roodrrigoo/Rover-X/blob/main/img/rover%20robot.png?raw=true)
*Image 1: Rover Robot*

![Rover Sensors](https://github.com/Roodrrigoo/Rover-X/blob/main/img/sensores%20rover.png?raw=true)
*Image 2: Sensors used on the Rover*

---

## How to Run the Project

1. Clone this repository:
    ```bash
    git clone https://github.com/Roodrrigoo/Rover-X.git
    ```

2. Set up the environment on your Raspberry Pi by installing the required libraries:
    ```bash
    pip install -r requirements.txt
    ```

3. Run the server to collect and visualize data:
    ```bash
    python server.py
    ```

