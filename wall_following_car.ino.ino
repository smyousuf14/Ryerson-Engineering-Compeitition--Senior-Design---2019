#include <Servo.h>

Servo myservo; // Create a servo object
Servo myservo2;

int servoPin1 = 9;
int servoPin2 = 10;

int sensorpin1 = 0;
int sensorpin2 = 1;

int val = 0;
int val2 = 0;

int minDistance = 40;

void setup() {
  // Setup the pins.
  myservo.attach(servoPin1);
  myservo2.attach(servoPin2);

  
  Serial.begin(9600);
    
  
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(180);
  myservo2.write(0);

  val = analogRead(sensorpin1);       // reads the value of the sharp sensor
  Serial.println(val);

  val2 = analogRead(sensorpin2);
  Serial.println(val2);
   
  delay(1000);
  myservo.write(90);
  myservo2.write(90);
  
  delay(1000);
  myservo.write(0);
  myservo2.write(180);
 
  
  delay(1000);

  // Apply the right wall rule.
  if(val <= minDistance &&  val2 <= minDistance)
  {
    //  both front and left is on.
    myservo.write(0);
    myservo2.write(0);
  
    val2 = analogRead(sensorpin2);
    Serial.println(val2);
     
    delay(1000);
    myservo.write(90);
    myservo2.write(0);
    
    delay(1000);
    myservo.write(180);
    myservo2.write(0);
   
  }
  else
  if(val <= minDistance && val2 >= minDistance)
  {
      // Front is on and left is off.
      myservo.write(0);
      myservo2.write(0);
    
      val2 = analogRead(sensorpin2);
      Serial.println(val2);
       
      delay(1000);
      myservo.write(90);
      myservo2.write(0);
      
      delay(1000);
      myservo.write(180);
      myservo2.write(0);  
    
  }
  
}
