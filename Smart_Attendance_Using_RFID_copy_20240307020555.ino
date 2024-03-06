#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER_PIN 7

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the address to your LCD's address
MFRC522 mfrc522(SS_PIN, RST_PIN);

bool authorized = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial monitor initialized.");
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init(); // Initialize the LCD
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Attendance Here");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your ID");
  delay(3000);
  lcd.clear();
}


void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    authorized = false;
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  String rfidTag = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfidTag += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    rfidTag += String(mfrc522.uid.uidByte[i], HEX);
  }
  rfidTag.toUpperCase();

  // Replace "75AEE13F" with the actual RFID tag you want to match
  String allowedRFIDTag = "75AEE13F";

  Serial.print("Scanned RFID Tag: ");
  Serial.println(rfidTag);

 if (rfidTag == allowedRFIDTag) {
    authorized = true;
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome!");
    lcd.setCursor(0, 1);
    lcd.print("Suwarna-Present");
    Serial.println("RFID Tag authorized. Suwarna is Present.");
    delay(200); // Buzzer sounds for 1 second
    digitalWrite(BUZZER_PIN, LOW);
    delay(2000); // Display stays for 2 seconds
    lcd.clear();
    Serial.println("Welcome, Suwarna!!");
}
else {
    if (!authorized) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Unauthorized");
      lcd.setCursor(0, 1);
      lcd.print("Access!");
      Serial.println("Unauthorized RFID Tag detected. Access denied.");
      delay(3000);
      lcd.clear();
    }
  }

  Serial.println("Waiting for next scan...");
  delay(1000);
}
