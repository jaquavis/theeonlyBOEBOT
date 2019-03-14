#include "simpletools.h"                      // Include simple tools
#include "adcDCpropab.h"
#include "servo.h"
#include "boebot.h"

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
  pause(2000);
  int *lightshow_cog = cog_run(lightshow, 128);
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
