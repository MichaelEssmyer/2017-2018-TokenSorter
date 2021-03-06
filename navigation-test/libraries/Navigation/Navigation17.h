#ifndef INC_2017_2018_TOKENSORTER_NAVIGATION17_H
#define INC_2017_2018_TOKENSORTER_NAVIGATION17_H

#include <Arduino.h>
#include "Movement.h"
#include "Coordinate.h"


class Navigation17 {
private:
    const static int MAX_R = 7;  // r coordinate for drop locations - TODO: verify

    Movement* movement;
    Coordinate current_position;
    Direction facing;
    Coordinate available_directions[DIRECTION_COUNT];
    Approach approaches[DIRECTION_COUNT];

    /** call this when arriving somewhere **/
    void set_available_directions();  // and approaches
    /** 1 for left, -1 for right **/
    bool turn(const int& direction);
public:
    // TODO: starting position and starting facing direction
    Navigation17() : movement(nullptr),
                     current_position(6, 7),
                     facing(NORTH) {
        set_available_directions();
    }
    explicit Navigation17(Movement* _movement) : movement(_movement),
                                                 current_position(6, 7),
                                                 facing(NORTH) {
        set_available_directions();
    }

    bool turnLeft();
    bool turnRight();
    bool goForward();
    bool goBackward();

    String getCurrentStateInfo();
};

#endif //INC_2017_2018_TOKENSORTER_NAVIGATION17_H
