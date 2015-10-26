// Cod Magician

int MOTOR2_PIN1 = 3;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 9;

int s0 = 0; // distanta
int s1 = 0; // left
int s2 = 0; // right
int s3 = 0; // culoare spate
int s4 = 0; // culoare stanga
int s5 = 0; // culoare dreapta

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
s5 = analogRead(5);

//  Serial.println(s0);
//  Serial.println(s1);
//  Serial.println(s2);
//  Serial.println(s3);
//  Serial.println(s4);
//  Serial.println(s5);
//  delay(500);

//go(100,100);

  if(s4 < 700 && s5 < 700){ // alb fata complet
    go(-100,-100);
  }
  else if(s5 < 700){ // dc alb pe dreapta
    go(100, -100);
    
  }
  else if(s4 < 700){ // dc alb pe stg
    go(-100, 100);
    
  }
  else if(s0 > 700){ // daca dusman pe teritoriu, da-l afara
    go(100,100);
  }
  else
  {
    go(100,100);
  }
//  
//  go(255, 255);
//  Serial.println(s4);


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

