/* Note lengths */
#define MEASURE_TIME              2000  /* Time in ms for 1 measure (1 full note) - should be divisible by 16 */
#define FULL_NOTE                 (MEASURE_TIME)
#define HALF_NOTE                 (MEASURE_TIME / 2)
#define QUARTER_NOTE              (MEASURE_TIME / 4)
#define EIGHTH_NOTE               (MEASURE_TIME / 8)
#define SIXTEENTH_NOTE            (MEASURE_TIME / 16)

#define FNj                        FULL_NOTE
#define HNj                        HALF_NOTE
#define QNj                        QUARTER_NOTE
#define ENj                        EIGHTH_NOTE
#define SNj                        SIXTEENTH_NOTE

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
