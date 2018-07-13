#include <Arduino.h>
#include <chrono>
#include <ratio>
#include <ctime>

const int ttlpulseout = 2;
const int cam = 4;


void setup() {
  pinMode(ttlpulseout, OUTPUT);
  pinMode(cam, OUTPUT);
  using namespace std::chrono;
  typedef std::chrono:high_resolution_clock Time;
  typedef std::chrono::duration<float> fsec;
  t0 = Time::now();
  digitalWrite(ttlpulseout, HIGH);
  cycle = 0;
}
void loop() {
  t1 = Time::now();
  fsec time_span = t1 -t0;
  while (time_span.count() > 0 && cycle <= 500) {
    t1 = Time::now();
    fsec time_span = t1 - t0;
    t2 = Time::now();
    fsec check_high = 0;
    while (check_high.count() <= 0.001) {
      t3 = Time::now();
      fsec time_span = t3 - t2;
      digitalWrite(cam, HIGH);
    }
    t4 = Time::now();
    fsec check_low = 0;
    while (check_low.count() <= 0.001) {
      t5 = Time::now();
      fsec check_low = t5 - t4;
      digitalWrite(cam, LOW)
    }
    cycle++
  }
  digitalWrite(ttlpulseout, LOW);
}
