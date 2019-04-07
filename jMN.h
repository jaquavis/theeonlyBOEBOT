/* Note lengths */
#define MEASURE_TIMEj              1000  /* Time in ms for 1 measure (1 full note) - should be divisible by 16 */
#define FULL_NOTEj                 (MEASURE_TIMEj)
#define HALF_NOTEj                 (MEASURE_TIMEj / 2)
#define QUARTER_NOTEj              (MEASURE_TIMEj / 4)
#define EIGHTH_NOTEj               (MEASURE_TIMEj / 8)
#define SIXTEENTH_NOTEj            (MEASURE_TIMEj / 16)

#define FNj                        FULL_NOTEj
#define HNj                        HALF_NOTEj
#define QNj                        QUARTER_NOTEj
#define ENj                        EIGHTH_NOTEj
#define SNj                        SIXTEENTH_NOTEj

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
#define C3j                   NOTE_C3
#define C3Sj                  NOTE_C3_SHARP
#define D3j                   NOTE_D3
#define D3Sj                  NOTE_D3_SHARP
#define E3j                   NOTE_E3
#define F3j                   NOTE_F3
#define F3Sj                  NOTE_F3_SHARP
#define G3j                   NOTE_G3
#define G3Sj                  NOTE_G3_SHARP
#define A3j                   NOTE_A3
#define A3Sj                  NOTE_A3_SHARP
#define B3j                   NOTE_B3
#define C4j                   NOTE_C4  /* Middle C */
#define C4Sj                  NOTE_C4_SHARP
#define D4j                   NOTE_D4
#define D4Sj                  NOTE_D4_SHARP
#define E4j                   NOTE_E4
#define F4j                   NOTE_F4
#define F4Sj                  NOTE_F4_SHARP
#define G4j                   NOTE_G4
#define G4Sj                  NOTE_G4_SHARP
#define A4j                   NOTE_A4
#define A4Sj                  NOTE_A4_SHARP
#define B4j                   NOTE_B4
#define C5j                   NOTE_C5
#define C5Sj                  NOTE_C5_SHARP
#define D5j                   NOTE_D5
#define D5Sj                  NOTE_D5_SHARP
#define E5j                   NOTE_E5
#define F5j                   NOTE_F5
#define F5Sj                  NOTE_F5_SHARP
#define G5j                   NOTE_G5
#define G5Sj                  NOTE_G5_SHARP
#define A5j                   NOTE_A5
#define A5Sj                  NOTE_A5_SHARP
#define B5j                   NOTE_B5
#define C6j                   NOTE_C6
#define C6Sj                  NOTE_C6_SHARP
#define D6j                   NOTE_D6
#define D6Sj                  NOTE_D6_SHARP
#define E6j                   NOTE_E6
#define F6j                   NOTE_F6
#define F6Sj                  NOTE_F6_SHARP
#define G6j                   NOTE_G6
#define G6Sj                  NOTE_G6_SHARP
#define A6j                   NOTE_A6
#define A6Sj                  NOTE_A6_SHARP
#define B6j                   NOTE_B6
#define NOj                   NONE




////other notes////
  #define MEASURE_TIME           2000  /* Time in ms for 1 measure (1 full note) - should be divisible by 16 */
  #define FULL_NOTE              MEASURE_TIME
  #define HALF_NOTE              MEASURE_TIME / 2
  #define QUARTER_NOTE           MEASURE_TIME / 4
  #define EIGHTH_NOTE            MEASURE_TIME / 8
  #define SIXTEENTH_NOTE         MEASURE_TIME / 16

  #define FN                     FULL_NOTE                 
  #define HN                     HALF_NOTE                 
  #define QN                     QUARTER_NOTE              
  #define EN                     EIGHTH_NOTE               
  #define SN                     SIXTEENTH_NOTE

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
