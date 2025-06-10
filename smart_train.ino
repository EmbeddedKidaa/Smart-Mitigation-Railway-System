
const int duration=500;
unsigned long prevmillis = 0;




void setup() {

  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,INPUT);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  Serial.begin(9600);
}

void loop() {
  Read();
}
