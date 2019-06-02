int shockSensorPin  = 2; //interruptpin 0
boolean sleeping;
int loopcounter = 0;
long starttimer = 0;
long betweenTime= 1000; // 5 seconds  or change it to the time you want it.
long awake = 0;


void setup() {
  // put your setup code here, to run once:

  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(shockSensorPin, INPUT);
attachInterrupt(0,shakeInterrupt, FALLING);
}
void loop() {
  // put your main code here, to run repeatedly:
if(sleeping){   // if sleeping is true
  loopcounter++;
  if(loopcounter == 30000){               //write and reset after 30 000 loops It will write to the serial monitor once a second.
  Serial.println("speedoMeter is sleeping");
  loopcounter = 0;
  }

  
 }else if(sleeping == false){
    loopcounter++;
   if(loopcounter == 30000){
    Serial.println("awake");
    loopcounter = 0;
    }
    awake = millis() - starttimer;
    if(awake > betweenTime){
      sleeping = true;
      Serial.println("fall asleep");
    }
  }



}
void shakeInterrupt(){
  sleeping = false;
  starttimer = millis();
}
