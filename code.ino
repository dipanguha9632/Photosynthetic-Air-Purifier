
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int MQ135_INLET  = A0;
const int MQ135_OUTLET = A1;
const int MQ_AIR       = A2;

const unsigned long SAMPLE_INTERVAL = 5000;
const unsigned long SCREEN_INTERVAL = 4000;

unsigned long lastSample = 0;
unsigned long lastScreen = 0;

int inletRaw = 0;
int outletRaw = 0;
int airRaw = 0;

int previousInlet = 0;
int previousOutlet = 0;

float inletRate = 0;
float outletRate = 0;

bool firstSample = true;
bool showAirQuality = false;

int readAverage(int pin) {
  long total = 0;

  for (int i = 0; i < 10; i++) {
    total += analogRead(pin);
    delay(5);
  }

  return total / 10;
}

void sampleSensors() {
  inletRaw = readAverage(MQ135_INLET);
  outletRaw = readAverage(MQ135_OUTLET);
  airRaw = readAverage(MQ_AIR);

  if (!firstSample) {
    inletRate =
      (inletRaw - previousInlet) * 60000.0
      / SAMPLE_INTERVAL;

    outletRate =
      (outletRaw - previousOutlet) * 60000.0
      / SAMPLE_INTERVAL;
  } else {
    inletRate = 0;
    outletRate = 0;
    firstSample = false;
  }

  previousInlet = inletRaw;
  previousOutlet = outletRaw;
}

void displayChamberReadings() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("IN:");
  lcd.print(inletRate, 0);

  lcd.setCursor(0, 1);
  lcd.print("OUT:");
  lcd.print(outletRate, 0);
}

void displayAirQuality() {
  int gasIndex = map(airRaw, 0, 1023, 0, 500);
  gasIndex = constrain(gasIndex, 0, 500);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("GAS INDEX:");

  lcd.setCursor(0, 1);
  lcd.print(gasIndex);
  lcd.print(" R:");
  lcd.print(airRaw);
}

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  sampleSensors();

  lastSample = millis();
  lastScreen = millis();

  displayChamberReadings();
}

void loop() {
  unsigned long now = millis();

  if (now - lastSample >= SAMPLE_INTERVAL) {
    lastSample = now;
    sampleSensors();

    Serial.print("Inlet: ");
    Serial.print(inletRaw);
    Serial.print(" | Outlet: ");
    Serial.print(outletRaw);
    Serial.print(" | Air: ");
    Serial.println(airRaw);

    Serial.print("Inlet change/min: ");
    Serial.print(inletRate);
    Serial.print(" | Outlet change/min: ");
    Serial.println(outletRate);
  }

  if (now - lastScreen >= SCREEN_INTERVAL) {
    lastScreen = now;
    showAirQuality = !showAirQuality;

    if (showAirQuality) {
      displayAirQuality();
    } else {
      displayChamberReadings();
    }
  }
}
