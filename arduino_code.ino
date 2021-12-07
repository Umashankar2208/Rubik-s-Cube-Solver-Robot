String formula;

int grip1_pos0 = 24;
int grip2_pos0 = 29;
int grip3_pos0 = 31;
int grip4_pos0 = 20;

#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;
Servo myservo7;
Servo myservo8;

int pos = 0;

void setup(){
  Serial.begin(9600);
  
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);
  myservo6.attach(7);
  myservo7.attach(8);
  myservo8.attach(9);
  

  myservo1.write(25);
  myservo2.write(25);
  myservo3.write(25);
  myservo4.write(25);
  myservo5.write(grip1_pos0);
  myservo6.write(grip2_pos0);
  myservo7.write(grip3_pos0);
  myservo8.write(grip4_pos0);
}


void arm1_front(){
  myservo1.write(25);
  delay(500);
}
void arm1_back() {
  myservo1.write(150);
  delay(500);
}

void arm2_front(){
  myservo2.write(25);
  delay(500);
}
void arm2_back() {
  myservo2.write(150);
  delay(500);
}

void arm3_front(){
  myservo3.write(25);
  delay(500);
}
void arm3_back() {
  myservo3.write(150);
  delay(500);
}

void arm4_front(){
  myservo4.write(25);
  delay(500);
}
void arm4_back() {
  myservo4.write(150);
  delay(500);
}

void expand(){
  myservo1.write(150);
  delay(100);
  myservo2.write(150);
  delay(100);
  myservo3.write(150);
  delay(100);
  myservo4.write(150);
  delay(100);
}

void hold1() {
  arm1_front();
  arm3_front();
  delay(1000);
  arm2_back();
  arm4_back();
  delay(500);
}

void hold2() {
  arm2_back();
  arm4_back();
  delay(1000);
  arm1_back();
  arm3_back();
  delay(500);
  }

void hold_all() {
  arm1_front();
  arm3_front();
  delay(3000);
  arm2_front();
  arm4_front();
  }


void check_arm1(){
for(int i=0;i<=5;i++){
  arm1_back();
  delay(1000);
  arm1_front();
  delay(1000); 
}
}

void check_arm2(){
  for(int i=0;i<=5;i++){
    arm2_back();
  delay(1000);
  arm2_front();
  delay(1000);
  }
}

void check_arm3(){
  for(int i=0;i<=5;i++){
    arm3_back();
  delay(1000);
  arm3_front();
  delay(1000);
  }
}

void check_arm4(){
  for(int i=0;i<=5;i++){
    arm4_back();
  delay(1000);
  arm4_front();
  delay(1000);
  }
}

void check_all_arm(){
arm1_back();
delay(1000);
arm1_front();
delay(1000);
arm2_back();
delay(1000);
arm2_front();
delay(1000);
arm3_back();
delay(1000);
arm3_front();
delay(1000);
arm4_back();
delay(1000);
arm4_front();
delay(1000);
}

//grip 1 horizontal mean position
void grip_1_clock(){
  arm1_back();
  myservo5.write(122);
  delay(500);
}

//grip 1 vertical mean position
void grip_1_anticlock(){
  arm1_back();
  myservo5.write(24);
  delay(500);
}

void grip_1_adjust(){
  grip_1_anticlock();
  arm1_front();
}

void front_clock(){
  grip_1_adjust();
  myservo5.write(133);//grip 1 clock rotation
  delay(1000);
  grip_1_adjust();
}

void front_anticlock(){
  grip_1_clock();
  arm1_front();
  myservo5.write(18);//grip 1 anticlock rotation
  delay(1000);
  grip_1_adjust();
}

void front_clock_twice(){
  front_clock();
  delay(500);
  front_clock();
  delay(500);
}

void front_anticlock_twice(){
  front_anticlock();
  delay(500);
  front_anticlock();
  delay(500);
}



//grip 2 horizontal mean position
void grip_2_clock(){
  arm2_back();
  myservo6.write(128);
  delay(500);
}

//grip 2 vertical mean position
void grip_2_anticlock(){
  arm2_back();
  myservo6.write(29);
  delay(500);
}

void grip_2_adjust(){
  grip_2_anticlock();
  arm2_front();
}

void left_down(){
  grip_2_adjust();
  myservo6.write(139);//grip 2 clock rotation
  delay(1000);
  grip_2_adjust();
}

void left_up(){
  grip_2_clock();
  arm2_front();
  myservo6.write(20);//grip 2 anticlock rotation
  delay(1000);
  grip_2_adjust();
}

void left_up_twice(){
  left_up();
  delay(500);
  left_up();
  delay(500);
}

void left_down_twice(){
  left_down();
  delay(500);
  left_down();
  delay(500);
}


//grip 3 horizontal mean position
void grip_3_clock(){
  arm3_back();
  myservo7.write(126);
  delay(500);
}

//grip 3 vertical mean position
void grip_3_anticlock(){
  arm3_back();
  myservo7.write(31);
  delay(500);
}

void grip_3_adjust(){
  grip_3_anticlock();
  arm3_front();
}

void back_clock(){
  grip_3_adjust();
  myservo7.write(137);//grip 3 clock rotation
  delay(1000);
  grip_3_adjust();
}

void back_anticlock(){
  grip_3_clock();
  arm3_front();
  myservo7.write(24);//grip 3 anticlock rotation
  delay(1000);
  grip_3_adjust();
}

void back_clock_twice(){
  back_clock();
  delay(500);
  back_clock();
  delay(500);
}

void back_anticlock_twice(){
  back_anticlock();
  delay(500);
  back_anticlock();
  delay(500);
}


//grip 4 horizontal mean position
void grip_4_clock(){
  arm4_back();
  myservo8.write(118);
  delay(500);
}

//grip 4 vertical mean position
void grip_4_anticlock(){
  arm4_back();
  myservo8.write(20);
  delay(500);
}

void grip_4_adjust(){
  grip_4_anticlock();
  arm4_front();
}

void right_up(){
  grip_4_adjust();
  myservo8.write(132);//grip 4 clock rotation
  delay(1000);
  grip_4_adjust();
}

void right_down(){
  grip_4_clock();
  arm4_front();
  myservo8.write(12);//grip 4 anticlock rotation
  delay(1000);
  grip_4_adjust();
}

void right_up_twice(){
  right_up();
  delay(500);
  right_up();
  delay(500);
}

void right_down_twice(){
  right_down();
  delay(500);
  right_down();
  delay(500);
}


void rotate_cube_clock(){
  grip_3_clock();
  arm3_front();
  
  arm2_back();
  arm4_back();
   
  myservo7.write(32);
  myservo5.write(120);
  delay(500); 
  
  myservo2.write(30);
  delay(500);
  myservo4.write(30);
  delay(500);
  
  grip_1_adjust();
  grip_3_adjust();
  grip_2_adjust();
  grip_4_adjust();
 }

void rotate_cube_anticlock(){
  grip_1_clock();
  arm1_front();
  
  arm2_back();
  arm4_back(); 

  myservo5.write(26);
  myservo7.write(134);
  delay(500);

  myservo2.write(30);
  delay(500);
  myservo4.write(30);
  delay(500);
  
  grip_1_adjust();
  grip_3_adjust();
  grip_2_adjust();
  grip_4_adjust();    
}



void up_clock(){
  rotate_cube_clock();
  delay(500);
  right_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void up_clock_twice(){
  rotate_cube_clock();
  delay(500);
  right_up();
  delay(1000);
  right_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void up_anticlock(){
  rotate_cube_clock();
  delay(500);
  right_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void up_anticlock_twice(){
  rotate_cube_clock();
  delay(500);
  right_down();
  delay(1000);
  right_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}



void down_clock(){
  rotate_cube_clock();
  delay(500);
  left_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void down_clock_twice(){
  rotate_cube_clock();
  delay(500);
  left_down();
  delay(1000);
  left_down();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void down_anticlock(){
  rotate_cube_clock();
  delay(500);
  left_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}

void down_anticlock_twice(){
  rotate_cube_clock();
  delay(500);
  left_up();
  delay(1000);
  left_up();
  delay(500);
  rotate_cube_anticlock();
  delay(500);
}


void adjust_all(){
  grip_1_adjust();
  grip_2_adjust();
  grip_3_adjust();
  grip_4_adjust();
}

void complete_check(){
  front_clock();
  delay(500);
  front_anticlock();
  delay(500);

  left_up();
  delay(500);
  left_down();
  delay(500);

  back_clock();
  delay(500);
  back_anticlock();
  delay(500);

  right_up();
  delay(500);
  right_down();
  delay(500);

  up_clock_twice();
  delay(500);
  up_anticlock_twice();
  delay(500);

  down_clock_twice();
  delay(500);
  down_anticlock_twice();
  delay(500);
}


void loop(){
  if(Serial.available() > 1)
  {
    formula = Serial.readString();
        
    if(formula == "expand"){
     expand();
    }
    if(formula == "hold 1 3"){
      hold1();
    }
    if(formula == "hold 2 4"){
      hold2();
    }
    if(formula == "hold all"){
      hold_all();
    }

    
    if(formula == "arm 1 back"){
      arm1_back();
    } 
    if(formula == "arm 2 back"){
      arm2_back();
    }
    if(formula == "arm 3 back"){
      arm3_back();
    }
    if(formula == "arm 4 back"){
      arm4_back();
    }
    if(formula == "arm 1 front"){
      arm1_front();
    }
    if(formula == "arm 2 front"){
      arm2_front();
    }
    if(formula == "arm 3 front"){
      arm3_front();
    }
    if(formula == "arm 4 front"){
      arm4_front();
    } 

    
    if(formula == "check arm 1"){
      check_arm1();
    }
    if(formula == "check arm 2"){
      check_arm2();
    }
    if(formula == "check arm 3"){
      check_arm3();
    }
    if(formula == "check arm 4"){
      check_arm4();
    }
    if(formula == "check arm all"){
      check_all_arm();
    }

    
    if(formula == "grip 1 clock"){
      grip_1_clock();
    }
    if(formula == "grip 1 anticlock"){
      grip_1_anticlock();
    }
    if(formula == "grip 1 adjust"){
      grip_1_adjust();
    }
    if(formula == "front clock"){
      front_clock();
    }
    if(formula == "front anticlock"){
      front_anticlock();
    }
    if(formula == "front clock twice"){
      front_clock_twice();
    }  
    if(formula == "front anticlock twice"){
      front_anticlock_twice();
    } 
    

    if(formula == "grip 2 clock"){
      grip_2_clock();
    }
    if(formula == "grip 2 anticlock"){
      grip_2_anticlock();
    }
    if(formula == "grip 2 adjust"){
      grip_2_adjust();
    }
    if(formula == "left down"){
      left_down();
    }
    if(formula == "left up"){
      left_up();
    }
    if(formula == "left down twice"){
      left_down_twice();
    }
    if(formula == "left up twice"){
      left_up_twice();
    }




    if(formula == "grip 3 clock"){
      grip_3_clock();
    }
    if(formula == "grip 3 anticlock"){
      grip_3_anticlock();
    }
    if(formula == "grip 3 adjust"){
      grip_3_adjust();
    }
    if(formula == "back clock"){
      back_clock();
    }
    if(formula == "back anticlock"){
      back_anticlock();
    }
    if(formula == "back clock twice"){
      back_clock_twice();
    }
    if(formula == "back anticlock twice"){
      back_anticlock_twice();
    }



    if(formula == "grip 4 clock"){
      grip_4_clock();
    }
    if(formula == "grip 4 anticlock"){
      grip_4_anticlock();
    }
    if(formula == "grip 4 adjust"){
      grip_4_adjust();
    }
    if(formula == "right up"){
      right_up();
    }
    if(formula == "right down"){
      right_down();
    }
    if(formula == "right up twice"){
      right_up_twice();
    }
    if(formula == "right down twice"){
      right_down_twice();
    }

    

    if(formula == "rotate cube clock"){
      rotate_cube_clock();
    }
    if(formula == "rotate cube anticlock"){
      rotate_cube_anticlock();
    }
    

    if(formula == "up clock"){
      up_clock();
    }
    if(formula == "up clock twice"){
      up_clock_twice();
    }
    if(formula == "up anticlock"){
      up_anticlock();
    }
    if(formula == "up anticlock twice"){
      up_anticlock_twice();
    }


    if(formula == "down clock"){
      down_clock();
    }
    if(formula == "down clock twice"){
      down_clock_twice();
    }
    if(formula == "down anticlock"){
      down_anticlock();
    }
    if(formula == "down anticlock twice"){
      down_anticlock_twice();
    }

    
    if(formula == "adjust all"){
      adjust_all();
    }
    if(formula == "complete check"){
      complete_check();
    }
    
}   
}
