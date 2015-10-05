int MOTOR2_PIN1 = 3;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 9;

int s0 = 0; // spate stg
int s1 = 0; // spate dr
int s2 = 0; // fata dr
int s3 = 0; // fata stg
int s4 = 0; // distanta

void setup() {
  // put your setup code here, to run once:
  // setam sloturile motoarelor pe output
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  // setam sloturile pentru input de la sezori
  pinMode(s0, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

s0 = analogRead(0);
s1 = analogRead(1);
s2 = analogRead(2);
s3 = analogRead(3);
s4 = analogRead(4);

//  Serial.println(s0);
//  Serial.println(s1);
//  Serial.println(s2);
//  Serial.println(s3);
//  Serial.println(s4);
//  delay(500);



  if(s2 < 100 && s3 < 100){ // alb fata complet
    go(-255,-255);
  }
  else if(s2 < 100){ // dc alb pe dreapta
    go(-255, 255);
    
  }
  else if(s3 < 100){ // dc alb pe stg
    go(255, -255);
    
  }
  else if(s4 > 200){ // daca dusman pe teritoriu, da-l afara
    go(255,255);
  }
  else
  {
//    go(255,255);
    go(-255,255);
  }
  


}

void go(int speedLeft, int speedRight) {
  if (speedLeft > 0) {
    analogWrite(MOTOR1_PIN1, speedLeft);
    analogWrite(MOTOR1_PIN2, 0);
  } 
  else {
    analogWrite(MOTOR1_PIN1, 0);
    analogWrite(MOTOR1_PIN2, -speedLeft);
  }
 
  if (speedRight > 0) {
    analogWrite(MOTOR2_PIN1, speedRight);
    analogWrite(MOTOR2_PIN2, 0);
  }else {
    analogWrite(MOTOR2_PIN1, 0);
    analogWrite(MOTOR2_PIN2, -speedRight);
  }
}

