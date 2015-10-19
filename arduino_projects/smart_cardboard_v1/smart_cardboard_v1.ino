// Cod Smart Cardboard v1.0

int MOTOR2_PIN1 = 3;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 9;

int s0 = 0; // fata
int s1 = 0; // lateral stg
int s2 = 0; // lateral dr
int s3 = 0; // culoare spate
int s4 = 0; // culoare stg
int s5 = 0; // culoare dr

unsigned long now1;

void setup() {
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

  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
  s4 = analogRead(4);
  s5 = analogRead(5);
  
//  Serial.println(s0);

//  Serial.print("spate = ");
//  Serial.println(s3);
//  Serial.print("stg = ");
//  Serial.println(s4);
//  Serial.print("dr = ");
//  Serial.println(s5);
//  Serial.println();
//  delay(300);
  
  if(s4 < 900 && s5 < 900){ // alb fata complet
//    Serial.print("stg = ");
//    Serial.println(s4);
    
  
//      now1 = millis();
//      while(millis() - now1 < 800)
        go(-50,-50);
  }
  else if(s3 < 800) // culoare spate
  {
//    now1 = millis();
//    while(millis() - now1 < 800)
      go(50,50);
  }
  else if(s5 < 900){ // dc alb pe dreapta
//    now1 = millis();
Serial.print("dr = ");
    Serial.println(s5);
//    while(millis() - now1 < 800)
      go(50, -50);
    
  }
  else if(s4 < 800){ // dc alb pe stg
//    now1 = millis();
//    while(millis() - now1 < 800)
      go(-50, 50);
    
  }
//  else if(s0 > 250){ // daca dusman pe teritoriu, da-l afara
//    go(50,50);
//  }
  else // cauta
  {
    go(50,50);
//    now1 = millis();
//    while(millis() - now1 < 800)
//      go(200,200);
//    now1 = millis();
//    while(millis() - now1 < 300)
//      go(200,-200);
  }

//
//if(s0 > 300)
//{
//  go(255,255);
//}
//else
//{
//  go(0,0);
//}
 


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

