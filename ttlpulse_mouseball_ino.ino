const int out = 2;

void setup(){
  Serial.begin(9600); 
  pinMode(out, OUTPUT);
}

void loop(){
  digitalWrite(out, HIGH);
  delay(1);
  digitalWrite(out, LOW);
  delay(1);
  Serial.print(millis());
}
