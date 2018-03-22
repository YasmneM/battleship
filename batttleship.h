/*
 * batttleship.h
 *
 *  Created on: Mar 20, 2018
 *      Author: ym7988
 */

#ifndef BATTTLESHIP_H_
#define BATTTLESHIP_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/* CONSTANT MACROS */

#define ROWS 10
#define COLS 10

#define LOG_FILE_NAME "battleship.log"

#define NUM_OF_SHIPS  5

#define HORIZONTAL    0
#define VERTICAL      1

#define PLAYER_ONE    0
#define PLAYER_TWO    1


#define WATER         '~'
#define HIT           '*'
#define MISS          'm'

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3

/* ENUMERATED TYPES */

typedef enum {
	FALSE, TRUE
} Boolean;

typedef enum {
	CARRIER_L    = 5,
	BATTLESHIP_L = 4,
	CRUISER_L    = 3,
	SUBMARINE_L  = 3,
	DESTROYER_L  = 2
} ShipType;

/* STRUCT TYPES */

typedef struct watercraft {
	char   symbol;
	short  length;
	char   *name;
} WaterCraft;

typedef struct stats {
	int        numHits;
	int        numMisses;
	int        totalShots;
	double     hitMissRatio;
} Stats;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;
typedef struct coord {
		int        row;
		int        column;
	} Coordinate_t;

typedef struct cell {
	char       symbol;
	Coordinate position;
} Cell;

/* FUNCTION PROTOTYPES */

void         welcomeScreen                  (void);
void         initializeGameBoard            (Cell gameBoard[][COLS]);
void         printGameBoard                 (Cell gameBoard [][COLS], Boolean showPegs);
void         putShipOnGameBoard             (Cell gameBoard[][COLS], WaterCraft ship, Coordinate_t * position, int direction);
void         manuallyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);
void         randomlyPlaceShipsOnGameBoard  (Cell gameBoard[][COLS], WaterCraft ship[]);
void         updateGameBoard                (Cell gameBoard[][COLS], Coordinate_t * target);
void         checkBoundsOfCardinal          (Boolean cardinals[], int bound, int direction);
void         systemMessage                  (char *message);

Boolean      checkSunkShip                  (short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream);
Boolean      isValidLocation                (Cell gameBoard[][COLS], Coordinate_t * position, int direction, int length);
Boolean      convertStringtoPosition        (Coordinate_t * position[], char *stringPosition, int length);
Boolean      isWinner                       (Stats players[], int player);
Coordinate_t *  generatePosition               (int direction, int length);
Coordinate_t *  getTarget                      (void);

short        checkShot                      (Cell gameBoard[][COLS], Coordinate_t * target);
int          getRandomNumber                (int lowest, int highest);




#endif /* BATTTLESHIP_H_ */
