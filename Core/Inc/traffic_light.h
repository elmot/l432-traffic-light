#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "main.h"

typedef enum {
    PHASE_RED,
    PHASE_RED_YELLOW,
    PHASE_GREEN,
    PHASE_YELLOW
} TrafficLightPhase;

void traffic_light_loop(void);

#endif // TRAFFIC_LIGHT_H
