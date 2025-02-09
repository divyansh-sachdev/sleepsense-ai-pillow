#ifndef POSTURE_MODEL_H
#define POSTURE_MODEL_H

#include <Arduino.h>

enum SleepPosture {
    POSTURE_ABSENT,
    POSTURE_BACK,
    POSTURE_LEFT_SIDE,
    POSTURE_RIGHT_SIDE,
    POSTURE_PRONE
};

inline SleepPosture classifyPosture(int left, int center, int right) {
    int total = left + center + right;
    if (total < 300) return POSTURE_ABSENT;
    if (center > left * 1.5 && center > right * 1.5) return POSTURE_BACK;
    if (left > right * 1.4) return POSTURE_LEFT_SIDE;
    if (right > left * 1.4) return POSTURE_RIGHT_SIDE;
    return POSTURE_PRONE;
}

#endif
