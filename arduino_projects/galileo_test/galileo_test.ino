int led = 13;
int s0 = 0;
int s1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);

//  s0 = analogRead(0);
////  s1 = analogRead(5);
//  Serial.println(s0);
////  Serial.println(s1);
//  delay(500);
}
