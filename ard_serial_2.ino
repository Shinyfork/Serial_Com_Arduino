#include <Wire.h>

const int emitterPin = 9;
const int sensorIntegrationPin = A0;
const int sensorGainPin = A1;

int emitterIntensity = 128;
int sensorIntegration = 2;
int sensorGain = 1;
int averagingNumber = 5;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  while (!Serial) {
    __asm("nop;");
  };

  Wire.begin();
  pinMode(emitterPin, OUTPUT);
  pinMode(sensorIntegrationPin, OUTPUT);
  pinMode(sensorGainPin, OUTPUT);
  setInitialSettings();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('#');
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    processCommand(command);
    Serial.flush();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }

  int sampleValue1 = random(0, 65001);
  int sampleValue2 = random(0, 65001);
  int refValue1 = random(0, 65001);
  int refValue2 = random(0, 65001);
  int bgValue1 = random(0, 65001);
  int bgValue2 = random(0, 65001);
  String timeStamp = "2023-10-24T12:00:00";

  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  sendData(sampleValue1, sampleValue2, refValue1, refValue2, bgValue1, bgValue2, timeStamp);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);

  delay(1000);
}

void processCommand(String command) {
  
}

void setInitialSettings() {
  
}

void sendData(int sampleValue1, int sampleValue2, int refValue1, int refValue2, int bgValue1, int bgValue2, String timeStamp) {
  Serial.print("DATA;Smp,");
  Serial.print(sampleValue1);
  Serial.print(",");
  Serial.print(sampleValue2);
  Serial.print(",Ref,");
  Serial.print(refValue1);
  Serial.print(",");
  Serial.print(refValue2);
  Serial.print(",BG,");
  Serial.print(bgValue1);
  Serial.print(",");
  Serial.print(bgValue2);
  Serial.print(",");
  Serial.println(timeStamp);
}

void setEmitterIntensity(int intensityValue) {
  
}

void setSensorIntegration(int integrationValue) {
  
}

void setSensorGain(int gainValue) {
  
}

void setAveragingNumber(int numberValue) {

}
