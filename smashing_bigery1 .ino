#define RMS 5
#define RMP 6
#define RMN 7
#define LMS 4
#define LMP 2
#define LMN 3

const int trigPin = 11;
const int echoPin = 12;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RMS, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMS, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  digitalWrite(RMS, HIGH);
  digitalWrite(LMS, HIGH);
}

void loop() {
  sense();
  if(distance>50)
  {
    forward();
  }  
  else
  {
    stops();
    delay(2000);
    backward();
    delay(500);
    left();
    delay(2500);
  }
}

void sense()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}

void forward()
{
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}

void stops()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}

void backward()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
}

void left()
{
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}

void right()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}
