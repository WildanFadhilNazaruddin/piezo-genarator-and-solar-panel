const int piezoPin = A0;       // Pin analog untuk piezo
const int solarPin = A1;       // Pin analog untuk solar panel

const float vRef = 5.0;        // Tegangan referensi Arduino
const float adcMax = 1023.0;   // Resolusi ADC

// Misal: pembagi tegangan 100k:20k untuk 30V ke 5V, divider = (100+20)/20 = 6
const float piezoDivider = 6.0;
const float solarDivider = 6.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Baca tegangan piezo
  int piezoADC = analogRead(piezoPin);
  float piezoVoltage = piezoADC * vRef / adcMax * piezoDivider;

  // Baca tegangan solar panel
  int solarADC = analogRead(solarPin);
  float solarVoltage = solarADC * vRef / adcMax * solarDivider;

  // Tampilkan di Serial Monitor
  Serial.print("Tegangan Piezo: ");
  Serial.print(piezoVoltage, 2);
  Serial.print(" V | Tegangan Solar Panel: ");
  Serial.print(solarVoltage, 2);
  Serial.println(" V");

  delay(1000);
}