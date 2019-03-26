void HappyState();
void InteractHappy();
void SadState();
void InteractSad();
void ScaredState();
void InteractScared();
void AngerState();
void InteractAnger();
void LoveState();
void InteractLove();
void LethargicState();
void InteractLethargic();
void AnxiousState();
void InteractAnxious();

void lightshow();
void lightshowf();
void lightshowff();
void backup();
float distance_cm();
void attack();
void LetsGetIt();
void Jitter();
int Ping();

int gameover1();
int gameover2();
int gameover3();
void mobamba();
void mobamba1();
void mobamba2();
void mobamba3();


#define MEASURE_TIME           2000  /* Time in ms for 1 measure (1 full note) - should be divisible by 16 */
  #define FULL_NOTE                 MEASURE_TIME
  #define HALF_NOTE                 MEASURE_TIME / 2
  #define QUARTER_NOTE          MEASURE_TIME / 4
  #define EIGHTH_NOTE             MEASURE_TIME / 8
  #define SIXTEENTH_NOTE        MEASURE_TIME / 16
  #define FN                        FULL_NOTE                 
  #define HN                        HALF_NOTE                 
  #define QN                        QUARTER_NOTE              
  #define EN                        EIGHTH_NOTE               
  #define SN                        SIXTEENTH_NOTE

  #define C0	    16.35
  #define Cs0Db0 	17.32	
  #define D0	    18.35	
  #define Ds0Eb0 	19.45	
  #define E0	    20.60	
  #define F0	    21.83	
  #define Fs0Gb0 	23.12	
  #define G0	    24.50	
  #define Gs0Ab0 	25.96	
  #define A0	    27.50	
  #define As0Bb0 	29.14	
  #define B0	    30.87	
  #define C1	    32.70	
  #define Cs1Db1 	34.65	
  #define D1	    36.71	
  #define Ds1Eb1 	38.89	
  #define E1	    41.20	
  #define F1	    43.65	
  #define Fs1Gb1 	46.25	
  #define G1	    49.00	
  #define Gs1Ab1 	51.91	
  #define A1	    55.00	
  #define As1Bb1 	58.27	
  #define B1	    61.74	
  #define C2	    65.41	
  #define Cs2Db2 	69.30	
  #define D2	    73.42	
  #define Ds2Eb2 	77.78	
  #define E2	    82.41	
  #define F2	    87.31	
  #define Fs2Gb2 	92.50	
  #define G2	    98.00	
  #define Gs2Ab2 	103.83	
  #define A2	    110.00	
  #define As2Bb2 	116.54	
  #define B2	    123.47	
  #define C3	    130.81	
  #define Cs3Db3 	138.59	
  #define D3	    146.83	
  #define Ds3Eb3 	155.56	
  #define E3	    164.81	
  #define F3	    174.61	
  #define Fs3Gb3 	185.00	
  #define G3	    196.00
  #define Gs3Ab3 	207.65	
  #define A3	    220.00	
  #define As3Bb3 	233.08	
  #define B3	    246.94	
  #define C4	    261.63	
  #define Cs4Db4 	277.18	
  #define D4	    293.66	
  #define Ds4Eb4 	311.13	
  #define E4	    329.63	
  #define F4	    349.23	
  #define Fs4Gb4 	369.99	
  #define G4	    392.00
  #define Gs4Ab4 	415.30	
  #define A4	    440.00	
  #define As4Bb4 	466.16	
  #define B4	    493.88	
  #define C5	    523.25	
  #define Cs5Db5 	554.37	
  #define D5	    587.33	
  #define Ds5Eb5 	622.25
  #define E5	    659.25	
  #define F5	    698.46	
  #define Fs5Gb5 	739.99	
  #define G5	    783.99	
  #define Gs5Ab5 	830.61	
  #define A5      880.00	
  #define As5Bb5 	932.33	
  #define B5	    987.77	
  #define C6	    1046.50	
  #define Cs6Db6 	1108.73	
  #define D6	    1174.66	
  #define Ds6Eb6 	1244.51	
  #define E6	    1318.51	
  #define F6	    1396.91	
  #define Fs6Gb6 	1479.98	
  #define G6	    1567.98	
  #define Gs6Ab6 	1661.22	
  #define A6	    1760.00	
  #define As6Bb6 	1864.66	
  #define B6	    1975.53	
  #define C7	    2093.00	
  #define Cs7Db7 	2217.46	
  #define D7	    2349.32	
  #define Ds7Eb7 	2489.02	
  #define E7	    2637.02	
  #define F7	    2793.83	
  #define Fs7Gb7 	2959.96	
  #define G7	    3135.96	
  #define Gs7Ab7 	3322.44	
  #define A7	    3520.00
  #define As7Bb7 	3729.31
  #define B7	    3951.07	
  #define C8	    4186.01	
  #define Cs8Db8 	4434.92	
  #define D8	    4698.63	
  #define Ds8Eb8 	4978.03	
  #define E8	    5274.04	
  #define F8	    5587.65	
  #define Fs8Gb8 	5919.91	
  #define G8	    6271.93	
  #define Gs8Ab8 	6644.88	
  #define A8	    7040.00	
  #define As8Bb8 	7458.62	
  #define B8	    7902.13
