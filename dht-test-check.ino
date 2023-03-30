 #include <dht.h>

dht DHT;

#define DHT11_PIN 7

const int trigPin = 3;
const int echoPin = 2;

long duration, cm, inches;
bool heading = true;
String heading1 = "Temperature";
String heading2 = "Humidity";
String heading3 = "Distance";


void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  //setting headings
  while(heading) {
      Serial.print(heading1);
      Serial.print(",");
      Serial.print(heading2);
      Serial.print(",");
      Serial.println(heading3);
      heading = false;
    }
  
  int chk = DHT.read11(DHT11_PIN);
  
  //
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  //read data
  Serial.print(DHT.temperature);
  Serial.print(",");
  Serial.print(DHT.humidity);
  Serial.print(",");
  Serial.println(cm);
  delay(10000);
  
}
