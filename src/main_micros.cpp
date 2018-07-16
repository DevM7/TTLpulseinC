#include <Arduino.h>
#include <DigitalIO.h>
#include <time.h>

const int ttlpulseout = 2;
const int cam = 4;
int cycle;

void setup() {
  fastPinMode(ttlpulseout, OUTPUT);
  fastPinMode(cam, OUTPUT);
  cycle = 0;
}
void loop() {
  fastDigitalWrite(ttlpulseout, HIGH);
  while (cycle <= 500) {
    fastDigitalWrite(cam, HIGH);
    delayMicroseconds(1000);
    fastDigitalWrite(cam, LOW);
    delayMicroseconds(1000);
    Serial.print(millis());
    cycle++;
  }
  fastDigitalWrite(ttlpulseout, LOW);
}
