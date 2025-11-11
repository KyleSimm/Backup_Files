/* 
 * File:   system_mode.h
 * Author: School Coding
 *
 * Created on November 5, 2025, 2:36 PM
 */

#ifndef SYSTEM_MODE_H
#define	SYSTEM_MODE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
//Global Variables


//System Modes    
typedef enum {
    MODE_IDLE = 0,
    MODE_ON,
    MODE_INIT,
    MODE_OFF,
    MODE_REVERSE
} SystemMode;

const char* modeToString(SystemMode mode);

// Declare the global variable (extern)
extern SystemMode currentMode;

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_MODE_H */

