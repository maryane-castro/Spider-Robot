#include <Servo.h> //servos
#include <SoftwareSerial.h> //biblioteca bluetth

//definição dos pinos dos servos

SoftwareSerial serialblue(1, 2); //entrada do bluetth
int blue; //variavel pra receber valor do blue


int pos = 0;

Servo myServo_2;
Servo myServo_3;
Servo myServo_4;
Servo myServo_5;
Servo myServo_6;
Servo myServo_7;
Servo myServo_8;
Servo myServo_9;





// calibração
int da =  -12,  // Left Front Pivot
    db =   10,  // Left Back Pivot
    dc =  -18,  // Right Back Pivot
    dd =   12;  // Right Front Pivot

// posição inicia e caaalibração
int a90  = (90  + da),
    a120 = (120 + da),
    a150 = (150 + da),
    a180 = (180 + da);

int b0   = (0   + db),
    b30  = (30  + db),
    b60  = (60  + db),
    b90  = (90  + db);

int c90  = (90  + dc),
    c120 = (120 + dc),
    c150 = (150 + dc),
    c180 = (180 + dc);

int d0   = (0   + dd),
    d30  = (30  + dd),
    d60  = (60  + dd),
    d90  = (90  + dd);

// ponto inicial dos servos caso dê merda
int s11 = 90; // Front Left Pivot Servo
int s12 = 90; // Front Left Lift Servo
int s21 = 90; // Back Left Pivot Servo
int s22 = 90; // Back Left Lift Servo
int s31 = 90; // Back Right Pivot Servo
int s32 = 90; // Back Right Lift Servo
int s41 = 90; // Front Right Pivot Servo
int s42 = 90; // Front Right Lift Servo

int f    = 0;
int b    = 0;
int l    = 0;
int r    = 0;
int spd  = 3;  // Speed of walking motion, larger the number, the slower the speed ???
int high = 0;   // How high the robot is standing


void setup() {
  //inicializar bluethh
  Serial.begin(9600);

  
  //inicializaar os servos
  myServo_2.attach(2, 500, 2500);
  myServo_3.attach(3, 500, 2500);    //testado no tinkercad!!
  myServo_4.attach(4, 500, 2500);
  myServo_5.attach(5, 500, 2500);
  myServo_6.attach(10, 500, 2500);
  myServo_7.attach(11, 500, 2500);
  myServo_8.attach(8, 500, 2500);
  myServo_9.attach(9, 500, 2500);

  Serial.begin(9600);
}

void loop() {
  
  unsigned long value;
  unsigned long lastValue;
  
  center_servos();  // Center all servos
  high = 15;        // Set hight to 15
  spd = 10;          // Set speed to 3

  while (1 == 1){
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=



    if (Serial.available()){  //se o bluethh estiver disponivel ele começa a ler e receber os valores
      blue = Serial.read();

    
  
          if(blue == 'F'){
              lastValue = 'F';
              forward();
          }
              
          
          
          if(blue == 'B'){
              lastValue = 'B';
              back();
          }
              
          
              
            if(blue == 'D'){
              lastValue = 'D';
              turn_right();
            }
              
          

            if(blue == 'E'){
              lastValue = 'E';
              turn_left();
              }


            if(blue == 'C'){
              lastValue = 'C';
              dance();
              }

            if(blue == 'W'){
              lastValue = 'W';
              wave();
              }

    }




    
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  } //fim do while

}



void wave()
{
  /*
  myServo1 - Front Left Pivot Servo
  myServo2 - Front Left Lift Servo
  myServo3 - Back Left Pivot Servo
  myServo4 - Back Left Lift Servo
  myServo5 - Back Right Pivot Servo
  myServo6 - Back Right Lift Servo
  myServo7 - Front Right Pivot Servo
  myServo8 - Front Right Lift Servo
  */

  center_servos();
  myServo_4.write(45);
  myServo_6.write(45);
  delay(200);
  myServo_8.write(0);
  delay(200);
  myServo_7.write(180);
  delay(200);
  myServo_7.write(30);
  delay(300);
  myServo_7.write(180);
  delay(300);
  myServo_7.write(30);
  delay(300);
  myServo_7.write(s41);
  delay(300);
  myServo_8.write(s42);
  center_servos();

}


//=-==-=-=-=-==
void dance()
{
  center_servos();
  delay(100);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(300);
  lean_left();
  delay(300);
  lean_right();
  delay(800);
  center_servos();
  delay(300);
  bow();
  center_servos();
}
void bow()
{
  center_servos();
  delay(200);
  myServo_2.write(15);
  myServo_8.write(15);
  delay(700);
  myServo_2.write(90);
  myServo_8.write(90);
  delay(700);
}


void lean_left()
{
  myServo_2.write(15);
  myServo_4.write(15);
  myServo_6.write(150);
  myServo_8.write(150);
}

//== Lean_Right ============================================================================

void lean_right()
{
  myServo_2.write(150);
  myServo_4.write(150);
  myServo_6.write(15);
  myServo_8.write(15);
}
//=-=-=-=-=-=-=-=



void center_servos()
{
  myServo_2.write(90);
  myServo_3.write(90);
  myServo_4.write(90);
  myServo_5.write(90);
  myServo_6.write(90);
  myServo_7.write(90);
  myServo_8.write(90);
  myServo_9.write(90);

  int s11 = 90; // Front Left Pivot Servo
  int s12 = 90; // Front Left Lift Servo
  int s21 = 90; // Back Left Pivot Servo
  int s22 = 90; // Back Left Lift Servo
  int s31 = 90; // Back Right Pivot Servo
  int s32 = 90; // Back Right Lift Servo
  int s41 = 90; // Front Right Pivot Servo
  int s42 = 90; // Front Right Lift Servo
}


void forward()
{

  // Left Front Pivot
  a90 = (90 + da),
  a120 = (120 + da),
  a150 = (150 + da),
  a180 = (180 + da);

  // Left Back Pivot
  b0 = (0 + db),
  b30 = (30 + db),
  b60 = (60 + db),
  b90 = (90 + db);

  // Right Back Pivot
  c90 = (90 + dc),
  c120 = (120 + dc),
  c150 = (150 + dc),
  c180 = (180 + dc);

  // Right Front Pivot
  d0 = (0 + dd),
  d30 = (30 + dd),
  d60 = (60 + dd),
  d90 = (90 + dd);

  // set servo positions and speeds needed to walk forward one step  (???)
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(a180, b0 , c120, d60, 42,  33,  33,  42,  1,  3,  1,  1);
  srv( a90, b30, c90,  d30, 6,   33,  33,  42,  3,  1,  1,  1);
  srv( a90, b30, c90,  d30, 42,  33,  33,  42,  3,  1,  1,  1);
  srv(a120, b60, c180, d0,  42,  33,  6,   42,  1,  1,  3,  1);
  srv(a120, b60, c180, d0,  42,  33,  33,  42,  1,  1,  3,  1);
  srv(a150, b90, c150, d90, 42,  33,  33,  6,   1,  1,  1,  3);
  srv(a150, b90, c150, d90, 42,  33,  33,  42,  1,  1,  1,  3);
  srv(a180, b0,  c120, d60, 42,  6,   33,  42,  1,  3,  1,  1);
  //srv(a180, b0,  c120, d60, 42,  15,  33,  42,  1,  3,  1,  1);
  
}



void back ()
{
  // set servo positions and speeds needed to walk backward one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(180, 0,  120, 60, 42, 33, 33, 42, 3,  1, 1, 1);
  srv(150, 90, 150, 90, 42, 18, 33, 42, 1,  3, 1, 1);
  srv(150, 90, 150, 90, 42, 33, 33, 42, 1,  3, 1, 1);
  srv(120, 60, 180, 0,  42, 33, 33, 6,  1,  1, 1, 3);
  srv(120, 60, 180, 0,  42, 33, 33, 42, 1,  1, 1, 3);
  srv(90,  30, 90,  30, 42, 33, 18, 42, 1,  1, 3, 1);
  srv(90,  30, 90,  30, 42, 33, 33, 42, 1,  1, 3, 1);
  srv(180, 0,  120, 60, 6,  33, 33, 42, 3,  1, 1, 1);

}


void turn_right ()
{
  // set servo positions and speeds needed to turn right one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv( 90, 30, 150, 90, 6,  33, 33, 42, 3, 1, 1, 1);
  srv( 90, 30, 150, 90, 42, 33, 33, 42, 3, 1, 1, 1);
  srv(120, 60, 180, 0,  42, 33, 33, 6,  1, 1, 1, 3);
  srv(120, 60, 180, 0,  42, 33, 33, 42, 1, 1, 1, 3);
  srv(150, 90, 90,  30, 42, 33, 6,  42, 1, 1, 3, 1);
  srv(150, 90, 90,  30, 42, 33, 33, 42, 1, 1, 3, 1);
  srv(180, 0,  120, 60, 42, 6,  33, 42, 1, 3, 1, 1);
  srv(180, 0,  120, 60, 42, 33, 33, 42, 1, 3, 1, 1);
}

void turn_left ()
{
  // set servo positions and speeds needed to turn left one step
  // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
  srv(150,  90, 90,  30, 42, 6,  33, 42, 1, 3, 1, 1);
  srv(150,  90, 90,  30, 42, 33, 33, 42, 1, 3, 1, 1);
  srv(120,  60, 180, 0,  42, 33, 6,  42, 1, 1, 3, 1);
  srv(120,  60, 180, 0,  42, 33, 33, 24, 1, 1, 3, 1);
  srv(90,   30, 150, 90, 42, 33, 33, 6,  1, 1, 1, 3);
  srv(90,   30, 150, 90, 42, 33, 33, 42, 1, 1, 1, 3);
  srv(180,  0,  120, 60, 6,  33, 33, 42, 3, 1, 1, 1);
  srv(180,  0,  120, 60, 42, 33, 33, 33, 3, 1, 1, 1);
}


void srv( int  p11, int p21, int p31, int p41, int p12, int p22, int p32, int p42, int sp1, int sp2, int sp3, int sp4)
{

  // p11: Front Left Pivot Servo
  // p21: Back Left Pivot Servo
  // p31: Back Right Pivot Servo
  // p41: Front Right Pivot Servo
  // p12: Front Left Lift Servo
  // p22: Back Left Lift Servo
  // p32: Back Right Lift Servo
  // p42: Front Right Lift Servo
  // sp1: Speed 1
  // sp2: Speed 2
  // sp3: Speed 3
  // sp4: Speed 4

  // Multiply lift servo positions by manual height adjustment
  p12 = p12 + high * 3;
  p22 = p22 + high * 3;
  p32 = p32 + high * 3;
  p42 = p42 + high * 3;

  while ((s11 != p11) || (s21 != p21) || (s31 != p31) || (s41 != p41) || (s12 != p12) || (s22 != p22) || (s32 != p32) || (s42 != p42))
  {

    // Front Left Pivot Servo
    if (s11 < p11)            // if servo position is less than programmed position
    {
      if ((s11 + sp1) <= p11)
        s11 = s11 + sp1;      // set servo position equal to servo position plus speed constant
      else
        s11 = p11;
    }

    if (s11 > p11)            // if servo position is greater than programmed position
    {
      if ((s11 - sp1) >= p11)
        s11 = s11 - sp1;      // set servo position equal to servo position minus speed constant
      else
        s11 = p11;
    }

    // Back Left Pivot Servo
    if (s21 < p21)
    {
      if ((s21 + sp2) <= p21)
        s21 = s21 + sp2;
      else
        s21 = p21;
    }

    if (s21 > p21)
    {
      if ((s21 - sp2) >= p21)
        s21 = s21 - sp2;
      else
        s21 = p21;
    }

    // Back Right Pivot Servo
    if (s31 < p31)
    {
      if ((s31 + sp3) <= p31)
        s31 = s31 + sp3;
      else
        s31 = p31;
    }
 
    if (s31 > p31)
    {
      if ((s31 - sp3) >= p31)
        s31 = s31 - sp3;
      else
        s31 = p31;
    }

    // Front Right Pivot Servo
    if (s41 < p41)
    {
      if ((s41 + sp4) <= p41)
        s41 = s41 + sp4;
      else
        s41 = p41;
    }

    if (s41 > p41)
    {
      if ((s41 - sp4) >= p41)
        s41 = s41 - sp4;
      else
        s41 = p41;
    }

    // Front Left Lift Servo
    if (s12 < p12)
    {
      if ((s12 + sp1) <= p12)
        s12 = s12 + sp1;
      else
        s12 = p12;
    }

    if (s12 > p12)
    {
      if ((s12 - sp1) >= p12)
        s12 = s12 - sp1;
      else
        s12 = p12;
    }

    // Back Left Lift Servo
    if (s22 < p22)
    {
      if ((s22 + sp2) <= p22)
        s22 = s22 + sp2;
      else
        s22 = p22;
    }

    if (s22 > p22)
    {
      if ((s22 - sp2) >= p22)
        s22 = s22 - sp2;
      else
        s22 = p22;
    }

    // Back Right Lift Servo
    if (s32 < p32)
    {
      if ((s32 + sp3) <= p32)
        s32 = s32 + sp3;
      else
        s32 = p32;
    }

    if (s32 > p32)
    {
      if ((s32 - sp3) >= p32)
        s32 = s32 - sp3;
      else
        s32 = p32;
    }

    // Front Right Lift Servo
    if (s42 < p42)
    {
      if ((s42 + sp4) <= p42)
        s42 = s42 + sp4;
      else
        s42 = p42;
    }

    if (s42 > p42)
    {
      if ((s42 - sp4) >= p42)
        s42 = s42 - sp4;
      else
        s42 = p42;
    }
    
    // Write Pivot Servo Values

    //escreve as posiçõa dos servos motores
    myServo_2.write(s11 + da);
    myServo_4.write(s21 + db);
    myServo_6.write(s31 + dc);
    myServo_8.write(s41 + dd);

    // Write Lift Servos Values
    myServo_3.write(s12);
    myServo_5.write(s22);
    myServo_7.write(s32);
    myServo_9.write(s42);

    delay(spd); // Delay before next movement

  }//while
} //srv
