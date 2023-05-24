#ifndef CUBE_CUBE_H
#define CUBE_CUBE_H
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdint.h>

/*F, B, U, D, L, R - 90-degree turns of the front, back, up, down, left, and right faces, respectively.
 * An apostrophe (’) designates a 90-degree counterclockwise “prime” twist
 * “2” suffix indicates a 180-degree twist*/

/*
 *
 *     *-*-*-*
 *     |00|01|02|
 *     *-*-*-*-*
 *     |10|11|12|
 *     *-*-*-*-*
 *     |20|21|22|
 *     *-*-*-*-*
 *       face
 *
 *   the way we are holding rubics cube: white face if at the bottom (1), yellow face is top (0), green face is front (2),
 *   red face is left (3), blue face is back (4) and orange face is right (5)
*/
enum class FACE: uint8_t {UP, LEFT, FRONT, RIGHT, BACK, DOWN};
enum COMMANDS: uint8_t {U, Uprime, U2, F, Fprime, F2, L, Lprime, L2, R, Rprime, R2, B, Bprime, B2, D, Dprime, D2};
enum COLOR : uint8_t {YELLOW, WHITE, GREEN, RED, BLUE, ORANGE};
enum CORNER {ULB, URB, URF, ULF, DLF, DLB, DRB, DRF}; //position is a solved state
enum CORNERS_COLOR {YRB, YOB, YOG, YRG, WRG, WRB, WOB, WOG};
enum EDGE {UB, UR, UF, UL, FR, FL, BL, BR, DF, DL, DB, DR}; // position in s solved state
enum EDGES_COLOR {YB, YO, YG, YR, GO, GR, BLUERED, BO, WG, WR, WB, WO};

typedef uint8_t (*COLOR_cube)[3][3];
typedef uint8_t (*face_cube)[3];

/*class Cubie {
private:
    COLOR right_color;
    COLOR left_color;
    COLOR top_color;
public:
    COLOR getCubieRight();
    COLOR getCubieLeft();
    COLOR getCubieTop();
};*/

struct Face {
    enum FACE_TYPE {
        top,
        bottom,
        front,
        back,
        left,
        right,
    };
    COLOR C[9];
};

class Cube {
private:
    uint8_t cube[6][3][3];
    //std::string cornerNames[8] = {"URF", "UBR", "DLF", "DFR", "ULB", "UFL", "DRB", "DBL"};
    //std::string edgeNames[12] = {"UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "BR", "BL", "FL"};
public:
    Cube();
    void Read(const std::string& filename);
    void Shuffle();
    void Write(const std::string& filename);
    void printCube();

    uint8_t inputToInt(char x);
    char outputToChar(uint8_t x);
    std::string printColor(uint8_t x);
    /*COLOR getCubieRight(int side, int row, int column);
    COLOR getCubieLeft(int side, int row, int column);
    COLOR getCubieTop(int side, int row, int column);*/
    COLOR_cube getCube();
    face_cube getFace(int index);

    bool checkWhiteCross();
    void Generate();
    Cube& operator=(const Cube &a);
    bool operator==(const Cube &a);
    bool isSolved();
    //Solve();
    void Rotate(COMMANDS command);
    void Front(int amount);
    void FrontPrime(int amount);
    void Down(int amount);
    void DownPrime(int amount);
    void Up(int amount);
    void UpPrime(int amount);
    void Left(int amount);
    void LeftPrime(int amount);
    void Right(int amount);
    void RightPrime(int amount);
    void Back(int amount);
    void BackPrime(int amount);
    //COLOR getColor(FACE face, unsigned row, unsigned col);
};
#endif
