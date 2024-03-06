# Smart-Attendance-using-RFID


Here are the pinouts and connections for the RFID-based attendance system project using Arduino Nano:

### Pinouts:

- **RFID Module (MFRC522)**:
    
    - **SDA**: Connect to Arduino Nano pin 10 (SS_PIN)
    - **SCK**: Connect to Arduino Nano pin 13 (SCK)
    - **MOSI**: Connect to Arduino Nano pin 11 (MOSI)
    - **MISO**: Connect to Arduino Nano pin 12 (MISO)
    - **IRQ**: Not connected (optional)
    - **GND**: Connect to Arduino Nano GND
    - **RST**: Connect to Arduino Nano pin 9 (RST_PIN)
    - **3.3V**: Connect to Arduino Nano 3.3V
- **Buzzer**:
    
    - Connect the positive terminal to Arduino Nano pin 7 (BUZZER_PIN)
    - Connect the negative terminal to Arduino Nano GND
- **I2C LCD Display**:
    
    - **SDA**: Connect to Arduino Nano A4 (SDA)
    - **SCL**: Connect to Arduino Nano A5 (SCL)
    - **VCC**: Connect to Arduino Nano 5V
    - **GND**: Connect to Arduino Nano GND


### Description:

- **RFID Module (MFRC522)**: This module reads RFID cards/tags and communicates with the Arduino Nano via SPI protocol. It is used to identify and authenticate users during attendance.
    
- **Buzzer**: The buzzer produces sound signals to indicate the success or failure of RFID card scanning. It buzzes briefly when a valid RFID card is scanned.
    
- **I2C LCD Display**: This display is used to provide visual feedback to users. It shows messages such as "Attendance Here" and "Scan Your ID". Once a valid RFID card is scanned, it displays a welcome message along with the name of the person.
    

### Project Description:

The project is an RFID-based attendance system using Arduino Nano. When an RFID card/tag is brought close to the RFID reader, the system reads the unique ID of the card. If the ID matches the authorized ID, the system displays a welcome message along with the name of the person on the LCD display and activates the buzzer briefly. Otherwise, it displays an "Unauthorized Access" message.

Ensure proper wiring and connections, and also make sure that you have installed the required libraries for the RFID module and the LCD display before uploading the code to the Arduino Nano.
