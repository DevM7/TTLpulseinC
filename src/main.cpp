#include <Arduino.h>
#include <DigitalIO.h>

const int ttlpulseout = 2;
const int cam = 4;
int cycle;
float t2, t4;

void setup() {
  fastPinMode(ttlpulseout, OUTPUT);
  fastPinMode(cam, OUTPUT);
  cycle = 0;
}
void loop() {
  fastDigitalWrite(ttlpulseout, HIGH);
  while (cycle <= 500) {
    t2 = micros();
    fastDigitalWrite(cam, HIGH);
    while (micros()-t2 < 1000) {
    }
    t4 = micros();
    fastDigitalWrite(cam, LOW);
    while ((micros()-t4) < 1000) {
    }
    cycle++;
  }
  fastDigitalWrite(ttlpulseout, LOW);
}
