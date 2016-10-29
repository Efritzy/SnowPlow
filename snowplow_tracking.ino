#include <Servo.h>

Servo rotservo;  
Servo xservo;
Servo yservo;
Servo clawservo;// servos for x and y
//set initial values for x and y
int ypos = 0;
int xpos= 90;

void setup(){
  
  xservo.attach(15);
  xservo.write(90);
  
 
  Serial.begin(19200); // 19200 is the rate of communication
  Serial.println("Rolling"); // some output for debug purposes.
 
}

void loop() {
  static int v = 0; // value to be sent to the servo (0-180)
  if ( Serial.available()) {
    char ch = Serial.read(); // read in a character from the serial port and assign to ch
    switch(ch) { // switch based on the value of ch
      case '0'...'9': // if it's numeric
        v = v * 10 + ch - '0';
        /*
           so if the chars sent are 45x (turn x servo to 45 degs)..
           v is the value we want to send to the servo and it is currently 0
           The first char (ch) is 4 so
           0*10 = 0 + 4 - 0 = 4;
           Second char is 4;
           4*10 = 40 + 5 = 45 - 0 = 45;
           Third char is not a number(0-9) so we  drop through...
        */
        break;
      
      
      case 'x':
        if(v<80){
          xservo.write(xpos+1);
          xpos=xpos+1;
          
        }
        if(v>100){
          xservo.write(xpos-1);
          xpos=xpos-1;
          
        }
        v = 0;
        break;
       
    }
  }
}
