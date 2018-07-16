#include <Arduino.h>
#include <DigitalIO.h>
#include <delay_cycles_avr.h>

const int ttlpulseout = 2;
const int cam = 4;
const int MHz = 16;
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
    _delay_cycles(1000*MHz);
    t4 = micros();
    fastDigitalWrite(cam, LOW);
    _delay_cycles(1000*MHz);
    cycle++;
  }
  fastDigitalWrite(ttlpulseout, LOW);
}
