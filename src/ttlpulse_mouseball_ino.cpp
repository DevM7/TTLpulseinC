#include <Arduino.h>
#include <Chrono.h>
#include <ratio>
#include <ctime>

const int ttlpulseout = 2;
const int cam = 4;


void setup() {
  pinMode(ttlpulseout, OUTPUT);
  pinMode(cam, OUTPUT);
  using namespace std::chrono;
  high_resolution_clock::time_point timecheck = high_resolution_clock::now();
  digitalWrite(ttlpulseout, HIGH);
}
void loop() {
  duration<double> time_span = duration_cast<duration<double>>(t1 - timecheck);
  cycle = 0;
  while (time_span.count() > 0 && cycle <= 500) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t1 - timecheck);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> check_high = duration_cast<duration<double>>(t2 - t2);
    while (check_high.count() <= 0.001) {
      high_resolution_clock::time_point t3 = high_resolution_clock::now();
      duration<double> check_high = duration_cast<duration<double>>(t3 - t2);
      digitalWrite(cam, HIGH);
    }
    high_resolution_clock::time_point t4 = high_resolution_clock::now();
    duration<double> check_low = duration_cast<duration<double>>(t4 - t4);
    while (check_low.count() <= 0.001) {
      high_resolution_clock::time_point t5 = high_resolution_clock::now();
      duration<double> check_low = duration_cast<duration<double>>(t5 - t4);
      digitalWrite(cam, LOW)
    }
    cycle++
  }
  digitalWrite(ttlpulseout, LOW);
}
