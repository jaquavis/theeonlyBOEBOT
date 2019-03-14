#include "simpletools.h"                      // Include simple tools
#include "adcDCpropab.h"
#include "servo.h"

void lightshow();
void lightshowf();
void lightshowff();
void backup();
float distance_cm();
void attack();
void HappyState();
void InteractHappy();
void SadState();
void InteractSad();
void ScaredState();
void InteractScared();
void LetsGetIt();
void AngerState();
void InteractAnger();
void Jitter();
int Ping();
void GameOver();

int main()
{
  pause(1000);
  adc_init(21, 20, 19, 18);                   // CS=21, SCL=20, DO=19, DI=18 
  while(1)
  { 
    ///////SWITCH////////
    int button = input(11);
    print("button = %d\n", button);
    if (button == 1)
    {
      HappyState();
    }   
    pause(100);     
    ///////SWITCH////////
  }
  return 0;
}


///////////***EMOTION***///////////
void HappyState()
{
  pause(1000);
  while(1)
  {
    ///////SWITCH////////
    int button = input(11);
    print("button = %d\n", button);
    if (button == 1)
    {
      SadState();
    }
    ///////SWITCH////////  
    
    servo_speed(14,0);
    servo_speed(15,0);
    
    adc_init(21, 20, 19, 18);
    float v1;
  
    v1 = adc_volts(2);                  // Check A/D 1
    print("Sound Happy %f V\n", v1);                // Display volts
  
    if(v1 > 0.5)
    {
      InteractHappy();
    }      
    pause(100);                        // Wait 1/10 s
  }
  return;    
}  

void InteractHappy()
{
  servo_speed(14,200);
  servo_speed(15,200);
  high(26);
  high(27);
  pause(2000);
  low(26);
  low(27);
  return;
}

void SadState()
{
  pause(1000);
  while(1)
  {
    ///////SWITCH////////
    int button = input(11);
    print("button = %d\n", button);
    if (button == 1)
    {
      ScaredState();
    }
    ///////SWITCH//////// 
    
    ////////PING/////////
    float i = -1;
    i = Ping(12,13);           
    i = i / 148;                      //divide the ping by 148 to get inches, or by 54 to get centimeters
    if(i < 10)
    {
      //Turning the Robot 180 degrees
      servo_speed(14, 100);
      servo_speed(15, 100);
      pause(1200);
    
      servo_speed(14, 0);
      servo_speed(15, 0);
      pause(100);
  
      servo_speed(14, -50);
      servo_speed(15, 50);
    }
    else
    {
      servo_speed(14, -50);
      servo_speed(15, 50);
    }
    ////////PING/////////
    
    adc_init(21, 20, 19, 18);
    float v1;
  
    v1 = adc_volts(2);                  // Check A/D 1
    print("Sound Sad %f V\n", v1);                // Display volts
  
    if(v1 > 0.2)
    {
      InteractSad();
    }      
    pause(100); 
  }
  return;   
}  

void InteractSad()
{
  int count = 0;
  while(count < 20)
  {
    ////////PING/////////
    float i = -1;
    i = Ping(12,13);           
    i = i / 148;                      //divide the ping by 148 to get inches, or by 54 to get centimeters
    if(i < 10)
    {
      //Turning the Robot 180 degrees
      servo_speed(14, 100);
      servo_speed(15, 100);
      pause(1200);
    
      servo_speed(14, 0);
      servo_speed(15, 0);
      pause(100);
  
      servo_speed(14, -200);
      servo_speed(15, 200);
      pause(2000);
      
      GameOver();
    }  
    ////////PING/////////
    count++;
  }   
  return;
}

void ScaredState()
{
  pause(1000);
  while(1)
  {
    ///////SWITCH////////
    int button = input(11); 
    print("button = %d\n", button);                   
    if (button == 1)
    {
      AngerState();
    }
    ///////SWITCH////////
    
    float LDRVoltageValue;      
                   
    LDRVoltageValue = adc_volts(1);            // Check A/D 0
    print("LDR Value = %f \n", LDRVoltageValue); // Display LDR voltage value
    Jitter();                                 // Calling Jitter Function
    
    if (LDRVoltageValue < 3.13)                  // Checking to see LDR Value
    {
      InteractScared();
    }
  }
  return;
}

void InteractScared()
{
  LetsGetIt();
  
  //Turning the Robot 180 degrees
  servo_speed(14, 200);
  pause(3000);
  
  servo_speed(14, 0);                     // Move pin 14 motor by speed 0
  servo_speed(15, 0);                     // Move pin 15 motor by speed 0
  pause(4000);                            // Pause for 4 seconds
  return;
}

void AngerState()
{
  pause(1000);
  int *lightshow_cog = cog_run(lightshow, 1000);
  while(1)
  {
    ///////SWITCH////////
    int button = input(11);
    if (button == 1)
    {
      print("button = %d\n", button);
      HappyState();
    }   
    ///////SWITCH////////
    float flex = adc_volts(0);
    print("Flex = %f V\n", flex);
    if(flex>1.87 || flex<1.47)
    {
      cog_end(lightshow_cog);
      InteractAnger();
      lightshow_cog = cog_run(lightshow, 128);
      pause(2000);
    }
  }
  cog_end(lightshow_cog);
  return;
}

void InteractAnger()
{
int counter = 0;
  int *lightshowf_cog = cog_run(lightshowf, 128);
  int *backup_cog = cog_run(backup, 128);
  while(counter<100){
    float distance = distance_cm();
    if (distance < 10){
      counter=0;
      cog_end(lightshowf_cog);
      cog_end(backup_cog);
      attack();
      lightshowf_cog = cog_run(lightshowf, 128);
      backup_cog = cog_run(backup, 128);
      pause(2000);
    }
    counter++;
  }
  cog_end(lightshowf_cog);
  cog_end(backup_cog);
  servo_speed(14,0);
  servo_speed(15,0);
  return;
}
///////////***EMOTION***///////////


///////////***MISC***//////////////
void LetsGetIt(void)
{
  int LightTime = 100;
  int FrequencyTime = 200;
  int FrequencyLevel = 500;
  
  int count = 0;              // Count value          
  int x = 100;
  
  while(x < 2000)
  {
    freqout(0,20,x);
    x = x + 10;
  }
  
                            
  while(count < 6)
  {
    freqout(0, FrequencyTime, FrequencyLevel);
    high(26);
    low(27);
    pause(LightTime);
    high(27);
    low(26);
    pause(LightTime);
    count++;
    LightTime = 75 + LightTime;
    FrequencyLevel = FrequencyLevel + 100;
    FrequencyTime = FrequencyTime + 100;
  }
  return;
}  
  
void Jitter()
{
  servo_speed(14, 100);                      // Move pin 14 motor by speed 100
  servo_speed(15, -100);                     // Move pin 15 motor by speed -100
  pause(200);                               // Pause for 0.2 seconds
  servo_speed(14, -100);                      // Move pin 14 motor by speed 100
  servo_speed(15, 100);                     // Move pin 15 motor by speed -100
  pause(200);                               // Pause for 0.2 seconds
  return;
}   

int Ping(int trig, int echo)//trig is trigger pin, echo is echo pin
{
  low(trig);//set trig low for start pulse
  low(echo);//set echo low to be safe
  pulse_out(trig, 10);//send the minimum 10 ms pulse on trig to start a ping
  return pulse_in(echo, 1);//get the pulse duration back on echo pin
}

float distance_cm(){
  float i = -1;
  float distancecm;
  i = Ping(12,13);
  distancecm = i/54;
  print("Distance %f\n", distancecm); //divide the ping by 148 to get inches, or by 54 to get centimeters
  return distancecm;
}

void attack(){
  int *lightshowff_cog = cog_run(lightshowff, 128);
  servo_speed(14,-200);
  servo_speed(15,200);
  pause(500);
  servo_speed(14,0);
  servo_speed(15,0);
  cog_end(lightshowff_cog);
  return;
}

void backup(){
  while(1){
    servo_speed(14,25);
    servo_speed(15,-10);
    pause(500);
    servo_speed(14,0);
    servo_speed(15,0);
    pause(500);
    servo_speed(14,10);
    servo_speed(15,-25);
    pause(500);
    servo_speed(14,0);
    servo_speed(15,0);
    pause(500);
  }
  return; 
}

void lightshow(){
 while(1){
   high(26);
   low(27);
   pause(500);  
   low(26);
   high(27);
   pause(500);    
 }
 return;
}

void lightshowf(){
 while(1){
   high(26);
   low(27);
   pause(200);
   low(26);
   high(27);
   pause(200);
 }  
 return;
}

void lightshowff(){
 while(1){
   high(26);
   low(27);
   pause(50);
   low(26);
   high(27);
   pause(50);
 }
 return; 
}
///////////***MISC***//////////////


/* Note lengths */
#define MEASURE_TIME              2000  /* Time in ms for 1 measure (1 full note) - should be divisible by 16 */
#define FULL_NOTE                 (MEASURE_TIME)
#define HALF_NOTE                 (MEASURE_TIME / 2)
#define QUARTER_NOTE              (MEASURE_TIME / 4)
#define EIGHTH_NOTE               (MEASURE_TIME / 8)
#define SIXTEENTH_NOTE            (MEASURE_TIME / 16)

#define FN                        FULL_NOTE                 
#define HN                        HALF_NOTE                 
#define QN                        QUARTER_NOTE              
#define EN                        EIGHTH_NOTE               
#define SN                        SIXTEENTH_NOTE            

/* Note length adjustments */
#define REGULAR_NOTE_ADJUSTMENT   50
#define STACCATO_NOTE_TIME        75
#define HOLD_NOTE_ADJUSTMENT      0

#define RT                        REGULAR_NOTE_ADJUSTMENT
#define ST                        STACCATO_NOTE_TIME        
#define HT                        HOLD_NOTE_ADJUSTMENT            

/* Musical note definitions */
#define NOTE_C3                   131
#define NOTE_C3_SHARP             139
#define NOTE_D3_FLAT              139
#define NOTE_D3                   147
#define NOTE_D3_SHARP             156
#define NOTE_E3_FLAT              156
#define NOTE_E3                   165
#define NOTE_F3                   175
#define NOTE_F3_SHARP             185
#define NOTE_G3_FLAT              185
#define NOTE_G3                   196
#define NOTE_G3_SHARP             208
#define NOTE_A3                   220
#define NOTE_A3_SHARP             233
#define NOTE_B3                   245
#define NOTE_C4                   262
#define NOTE_C4_SHARP             277
#define NOTE_D4                   294
#define NOTE_D4_SHARP             311
#define NOTE_E4                   330
#define NOTE_F4                   349
#define NOTE_F4_SHARP             370
#define NOTE_G4                   392
#define NOTE_G4_SHARP             415
#define NOTE_A4                   440
#define NOTE_A4_SHARP             466
#define NOTE_B4                   494
#define NOTE_C5                   523
#define NOTE_C5_SHARP             554
#define NOTE_D5                   587
#define NOTE_D5_SHARP             622
#define NOTE_E5                   659
#define NOTE_F5                   698
#define NOTE_F5_SHARP             740
#define NOTE_G5                   784
#define NOTE_G5_SHARP             831
#define NOTE_A5                   880
#define NOTE_A5_SHARP             932
#define NOTE_B5                   988
#define NOTE_C6                   1047
#define NOTE_C6_SHARP             1109
#define NOTE_D6                   1175
#define NOTE_D6_SHARP             1245
#define NOTE_E6                   1319
#define NOTE_F6                   1397
#define NOTE_F6_SHARP             1480
#define NOTE_G6                   1568
#define NOTE_G6_SHARP             1661
#define NOTE_A6                   1760
#define NOTE_A6_SHARP             1865
#define NOTE_B6                   1976
#define NONE                      0

/* Musical note definitions - short hand */
#define C3                   NOTE_C3
#define C3S                  NOTE_C3_SHARP
#define D3                   NOTE_D3
#define D3S                  NOTE_D3_SHARP
#define E3                   NOTE_E3
#define F3                   NOTE_F3
#define F3S                  NOTE_F3_SHARP
#define G3                   NOTE_G3
#define G3S                  NOTE_G3_SHARP
#define A3                   NOTE_A3
#define A3S                  NOTE_A3_SHARP
#define B3                   NOTE_B3
#define C4                   NOTE_C4  /* Middle C */
#define C4S                  NOTE_C4_SHARP
#define D4                   NOTE_D4
#define D4S                  NOTE_D4_SHARP
#define E4                   NOTE_E4
#define F4                   NOTE_F4
#define F4S                  NOTE_F4_SHARP
#define G4                   NOTE_G4
#define G4S                  NOTE_G4_SHARP
#define A4                   NOTE_A4
#define A4S                  NOTE_A4_SHARP
#define B4                   NOTE_B4
#define C5                   NOTE_C5
#define C5S                  NOTE_C5_SHARP
#define D5                   NOTE_D5
#define D5S                  NOTE_D5_SHARP
#define E5                   NOTE_E5
#define F5                   NOTE_F5
#define F5S                  NOTE_F5_SHARP
#define G5                   NOTE_G5
#define G5S                  NOTE_G5_SHARP
#define A5                   NOTE_A5
#define A5S                  NOTE_A5_SHARP
#define B5                   NOTE_B5
#define C6                   NOTE_C6
#define C6S                  NOTE_C6_SHARP
#define D6                   NOTE_D6
#define D6S                  NOTE_D6_SHARP
#define E6                   NOTE_E6
#define F6                   NOTE_F6
#define F6S                  NOTE_F6_SHARP
#define G6                   NOTE_G6
#define G6S                  NOTE_G6_SHARP
#define A6                   NOTE_A6
#define A6S                  NOTE_A6_SHARP
#define B6                   NOTE_B6
#define NO                   NONE

///////////***MUSIC***/////////////
void GameOver(){
  int pin0 = 0; //right hand
  int pin6 = 6; //left hand
  
  ///////RIGHTHAND/////////
  freqout(pin0, QN, C5);
  pause(QN);
  pause(QN);
  freqout(pin0, QN, G4);
  pause(HN);
  freqout(pin0, HN, E4);
  freqout(pin0, HN, A4);
  freqout(pin0, HN, B4);
  freqout(pin0, HN, A4);
  freqout(pin0, HN, F4);
  freqout(pin0, HN, G4S);
  freqout(pin0, HN, A4S);
  freqout(pin0, HN, G4S);
  freqout(pin0, HN+FN, G4);
  freqout(pin0, QN, D4);
  freqout(pin0, FN, E4);
  ///////RIGHTHAND/////////
  
  ///////LEFTHAND/////////
  freqout(pin6, QN, G3);
  pause(QN);
  pause(QN);
  freqout(pin6, QN, E3);
  pause(HN);
  freqout(pin6, HN, C3);
  freqout(pin6, FN, F3);
  freqout(pin6, FN+HN, C3S);
  freqout(pin6, FN+HN, C3);
  ///////LEFTHAND/////////
  return;
}
///////////***MUSIC***/////////////