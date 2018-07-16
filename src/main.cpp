#include <Arduino.h>
#include <DigitalIO.h>
#include <delay_cycles_avr.h>
#include <time.h>

const int ttlpulseout = 2;
const int cam = 4;
const int MHz = 16000000;
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
    _delay_cycles(1000*MHz);
    fastDigitalWrite(cam, LOW);
    _delay_cycles(1000*MHz);
    Serial.print(millis());
    cycle++;
  }
  fastDigitalWrite(ttlpulseout, LOW);
}
