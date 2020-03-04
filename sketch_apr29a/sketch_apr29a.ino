const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(115200); // Starting Serial Terminal
}

void loop() {
   Serial.print("Length of filled trash in dustbin 18");
   //Serial.println(getcorrecteddata());
   delay(100);
}
int getcorrecteddata(){
  int c=1500;
  int k=c+1;
  while(k>c){
    k=getdata();
    //Serial.println(k);
  }
  return k;
}
int getdata(){
  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   return cm;
}
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
