// Carlos Gomez


int dirPin = 8;
int stpPin = 9;
int ENpin = 5;
int RSTpin = 4;
int SLPpin = 3;

const int analogInPin = 0;
int sensorValue = 0;
int setpoint = 510; 

void setup() {
  Serial.begin(9600);

  pinMode(dirPin, OUTPUT);
  pinMode(stpPin, OUTPUT);

  digitalWrite(ENpin, LOW);
  digitalWrite(RSTpin, HIGH);
  digitalWrite(SLPpin, HIGH);

}

void step(boolean dir,int steps)
{
  digitalWrite(dirPin,dir);
  delay(5);
  for(int i=0;i<steps;i++)
  {
    digitalWrite(stpPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stpPin, LOW);
    delayMicroseconds(800); 
  }
}

void loop()
{
  sensorValue = analogRead(analogInPin);            
 
  Serial.print("sensor = " );                       
  Serial.println(sensorValue); 
  
  if(sensorValue> setpoint + 10)
  {
    step(1,100);
    delay(.1);
  }
    if(sensorValue< setpoint - 10)
  {
    step(0,100);
    delay(.1);
  }

if(sensorValue > setpoint-10 && sensorValue < setpoint+10)
{
  delay(1);
}
  delay(1);
}
  
