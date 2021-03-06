//
// Created by joelm on 2016-01-25.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#define WIDTH 80
#define HEIGHT 21
#define MIN_ROOMS 5
#define MAX_ROOMS 7
#define ROOM_WIDTH_MIN 3
#define ROOM_WIDTH_MAX 20
#define ROOM_HEIGHT_MIN 2
#define ROOM_HEIGHT_MAX 10

#define ROCK_HARDNESS_MAX 5

enum material_enum {
    room = '.',
    corridor = '#',
    rock = ' '
};

typedef enum direction_enum {
    nowhere =   0b0000,
    north =     0b0001,
    northeast = 0b0011,
    east =      0b0010,
    southeast = 0b0110,
    south =     0b0100,
    southwest = 0b1100,
    west =      0b1000,
    northwest = 0b1001
} direction_t;

typedef struct room_struct {
    int x;
    int y;
    int height;
    int width;
} room_t;

typedef struct gridCell_struct {
    int hardness;
    enum material_enum material;
} gridCell_t;

int roomDist(room_t room1, room_t room2);
void connectRooms(gridCell_t **grid, room_t* rooms, int roomCount);
void connectTwoRooms(gridCell_t **grid, room_t room1, room_t room2);
direction_t calculateDirection(int x, int y, int targetX, int targetY);
int generateRoom(room_t* generatedRoom, room_t* rooms, int roomCount);
int validateRoom(room_t* rooms, int roomCount, room_t room);
int validateTwoRooms(room_t room1, room_t room2);
void printGrid(gridCell_t** grid);
gridCell_t** populateGrid(room_t* rooms, int roomCount);
void populateRooms(gridCell_t** grid, room_t* rooms, int roomCount);
int malloc2DGrid(gridCell_t*** grid, int width, int height);
void free2DGrid(gridCell_t** grid, int height);

#endif //PROJECT_MAIN_H