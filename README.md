_**Algae-Based Photosynthetic Air Purifier**_

**Project Overview**
The Algae-Based Photosynthetic Air Purifier is an Arduino Uno-based system that combines algae-supported photosynthesis with continuous airflow and gas-sensor monitoring. The system is designed to facilitate air circulation through an algae solution and monitor changes in gas-related sensor readings at the inlet and outlet chambers.

**Key Features**

1. Algae-Based Photosynthesis:Uses an illuminated algae culture to support photosynthesis, which consumes carbon dioxide and releases oxygen under suitable conditions.
2. Continuous Airflow:Four fans, with two inlet fans and two outlet fans, maintain continuous airflow.
3. Air Circulation:An air pump circulates air through the algae solution.
4. Oxygen-Enriched Air Transfer:An additional blower transfers air from the algae chamber to the outlet chamber.
5. Gas Monitoring:Two MQ135 sensors monitor carbon-related readings in the inlet and outlet chambers.
6. Air-Quality Monitoring:An additional MQ gas sensor monitors gas-related readings.
7. LCD Display:Displays the rate of change of inlet and outlet sensor readings, alternating with a relative gas index from the third sensor.
8. Continuous Operation:Fans, pump, blower, and algae light remain ON whenever the system is plugged in.

**Components Used**

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| 2 × MQ135 sensors | Inlet and outlet gas monitoring |
| 1 × MQ gas sensor | Additional gas monitoring |
| 16×2 I2C LCD | Display of sensor readings |
| 4 × Fans | Inlet and outlet airflow |
| Air pump | Air circulation through algae solution |
| Additional blower | Transfers air to the outlet chamber |
| Algae culture light | Supports photosynthesis |
| Algae solution | Biological component of the system |
| AC power supply | Power for the system through suitable supplies |

**Working Principle**

1. The inlet fans draw air into the system.
2. The air pump circulates air through the algae solution.
3. With sufficient light and suitable culture conditions, the algae perform photosynthesis, consuming CO₂ and releasing O₂.
4. The additional blower transfers air from the algae chamber to the outlet chamber.
5. The outlet fans exhaust air from the system.
6. Two MQ135 sensors monitor gas-related readings at the inlet and outlet.
7. The Arduino Uno processes the analog sensor readings and calculates their rate of change.
8. The LCD alternates between inlet/outlet sensor changes and the additional MQ sensor's relative gas index.

**LCD Display**
The LCD alternates between two screens:
Screen 1 — Inlet and Outlet Changes
- Inlet sensor reading change per minute
- Outlet sensor reading change per minute
Screen 2 — Gas Sensor
- Relative gas index
- Raw analog sensor reading

**Software and Libraries**

1. Arduino IDE
2. Arduino Uno board package
3. LiquidCrystal I2C library
4. Wire library

**Installation and Setup**

1. Clone or download this repository.
2. Open the Arduino source file in Arduino IDE.
3. Install the LiquidCrystal I2C library.
4. Connect the sensors to analog pins A0, A1, and A2.
5. Connect the I2C LCD to SDA (A4) and SCL (A5).
6. Verify the LCD I2C address and update it in the code if required.
7. Upload the program to the Arduino Uno.
8. Allow the MQ sensors to warm up and stabilize before interpreting readings.

**Power Supply**
The system operates from an AC power source through appropriate power supplies for the Arduino and connected components. The fans, air pump, additional blower, and algae light operate continuously while power is supplied.

**Safety**
Use properly rated, isolated power supplies and safe enclosures for all AC connections.

**Limitations**

- MQ sensors are sensitive to multiple gases and do not directly provide reliable CO₂ concentration measurements without appropriate calibration.
- The relative gas index displayed by the program is not a certified Air Quality Index (AQI).
- Actual oxygen production and CO₂ reduction depend on algae species, culture health, light intensity, temperature, airflow, and other environmental conditions.
- Experimental testing with calibrated instruments is needed to validate purification performance.

**Future Improvements**

- Integration of a calibrated CO₂ sensor.
- Improved gas measurement and air-quality assessment.
- Data logging for long-term performance analysis.
- Monitoring of algae culture conditions.
- Experimental validation of CO₂ reduction and oxygen production.

**Conclusion**
This project explores the integration of biological photosynthesis, embedded systems, and continuous air circulation in an algae-based air purifier prototype. It provides real-time monitoring of gas-related sensor readings and a platform for further experimentation in sustainable air-treatment technologies.
