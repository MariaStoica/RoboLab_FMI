// 26 Oct 2015
// code for Andrei and Maria's prototype 1: Whiteboard - from SmartCardboard

// !!! Attention 1 !!!
// check motor pins so that the movements correspond to the code
int MOTOR2_PIN1 = 5;
int MOTOR2_PIN2 = 3;
int MOTOR1_PIN1 = 9;
int MOTOR1_PIN2 = 6;
int color_threshold = 680; // a threshold between black and white according to the color sensors
// senzorii distance - pe baterie - vad < 100 la nimic pana la 500 la distanta max a lui
// senzorii distance - pe cablu - vad 150 la nimic
//PROBLEM 1: nu merge senzorul dreapta lateral !!!
// senzorii coloare... sunt haotici

static int distance_front, distance_left, distance_right;
static int color_back, color_left, color_right;
int now;

void setup() {
  // this code runs once, in the beginning

  // setam sloturile motoarelor pe output
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);

  // setam sloturile pentru input de la sezori
  pinMode(distance_front, INPUT);
  pinMode(distance_left, INPUT);
  pinMode(distance_right, INPUT);
  pinMode(color_back, INPUT);
  pinMode(color_left, INPUT);
  pinMode(color_right, INPUT);

  Serial.begin(9600);
} // end of setup
// -------------------------------------------

// methods:
// go(int speedLeft, int speedRight) // lowlevel method for interacting with the wheels
// explore_front() // goes front with speed 150
// charge()        // goes front with speed 255
// go_back()       // speed 150
// turn_left()     // turns with 150
// turn_right()    // turns with 150

// read_sensors()  // reads into all the 6 values of sensors
// color_check()   // if it detects white it runs from it

void loop() {
  
  // strategy:
  // if on black then search for enemy
  // else get back in ring
  //
  // search for enemy:
  // if nobody then search
  // else attack
  
  read_sensors();
  //  Serial.println(distance_front);
  //  Serial.println(distance_left);
  //  Serial.println(distance_right);
  
  if(color_check() == true)
  {
    search_for_enemy();
  }
  // else is tacked in the color_check()

} // end of loop




// -------------------------------
// additional methods
// -------------------------------

//DONE: detect algo
//TODO: search algo

void read_sensors() {
  distance_front = analogRead(0);
  distance_left  = analogRead(1);
  distance_right = analogRead(2);
  color_back     = analogRead(3);
  color_left     = analogRead(4);
  color_right    = analogRead(5);
  
} // end of read_sensors

bool color_check() {
  if (color_left < color_threshold && color_right < color_threshold) {
    go_back();
    return false;
  }
  if (color_left < color_threshold) {
    turn_right(90);
    return false;
  }
  if (color_right < color_threshold) {
    turn_left(90);
    return false;
  }
  
  return true;
  //TODO: not using color_back
} // end of color_check

void search_for_enemy(){
  // DETECT // senzorii de distanta au prioritate egala
  if(distance_front > 180) // vede ceva in fata - <100 baterie - <180 cablu
  {
    charge();
  }
  if (distance_left > 250) // - <100 baterie - <180 cablu
  {
    turn_left(90); //done: la 90 grade
  }
  // nu merge distante pe dreapta
  //  if(distance_right > 180) // - <100 baterie - <180 cablu
  //  {
  //    turn_right(90); //TDOD: la 90 grade
//  //    charge(); //TODO: pana ajungi la enemy
  //  }
  if(distance_front < 180 && distance_left < 250 && distance_right < 250) // daca nu vezi nimic
  {
//    go(0, 0); // seems corelated with problem 2
      explore_front();
  }

} // end of search for enemy

void go_back() {
  go(-255, -250);
}

void turn_right(int degrees) {
  if (degrees == 90)
  {
    now = millis();
    while (millis() - now < 200) //  300 pe baterie. 550 pe cablu pt 255 speed
    {
      // it is blind here - doesn't react to sensors
      go(-255, 255);
    }
  }
}

void turn_left(int degrees) {
  Serial.println("IN TURN  LEFT");
  //PROBLEM 2: dupa o vreme, doar intra in metoda dar nu mai intra in if-ul cu 90. si doar print in turn left si atat. fara sa se miste
  if (degrees == 90)
  {
    now = millis();
    while (millis() - now < 200) //  300 pe baterie. 550 pe cablu pt 255 speed
    {
      Serial.println("left");
      // it is blind here - doesn't react to sensors
      go(255, -255);
    }
  }
}

void explore_front() {
  go(150, 150);
}

void explore_angle(char* direct){
  if(strcmp(direct,"left")){
    go(150,160);
  }
  else if(strcmp(direct,"right")){
    go(160,150);
  }
}

void charge() {
  go(255, 255);
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
  } else {
    analogWrite(MOTOR2_PIN1, 0);
    analogWrite(MOTOR2_PIN2, -speedRight);
  }
} // end of go

