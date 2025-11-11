#include "system_mode.h"

const char* modeToString(SystemMode mode) {
    switch(mode) {
        case MODE_IDLE:    return "IDLE";
        case MODE_ON:      return "ON";
        case MODE_INIT:    return "INIT";
        case MODE_OFF:     return "OFF";
        case MODE_REVERSE: return "REVERSE";
        default:           return "UNKNOWN";
    }
}
