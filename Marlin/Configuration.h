#pragma once

#define CONFIGURATION_H_VERSION 020000
#define STRING_CONFIG_H_AUTHOR "(TH3D Studio)" // Who made the changes.
#define SHOW_BOOTSCREEN
#define STRING_SPLASH_LINE1 SHORT_BUILD_VERSION // will be shown during bootup in line 1
#define STRING_SPLASH_LINE2 WEBSITE_URL         // will be shown during bootup in line 2

#define SHOW_CUSTOM_BOOTSCREEN
#define CUSTOM_STATUS_SCREEN_IMAGE

#define SERIAL_PORT -1

#define BAUDRATE 115200

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_TH3D_TOUGH_CONTROLLER
#endif

#define CUSTOM_MACHINE_NAME "Ender 3"

#define EXTRUDERS 1

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

#define POWER_SUPPLY 0

#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_CHAMBER 0
#define CHAMBER_HEATER_PIN -1  // On/off pin for enclosure heating system

// Extruder temperature must be close to target for this long before M109 returns success
#define TEMP_RESIDENCY_TIME 10  // (seconds)
#define TEMP_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

// Bed temperature must be close to target for this long before M190 returns success
#define TEMP_BED_RESIDENCY_TIME 10  // (seconds)
#define TEMP_BED_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_BED_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP HEATER_0_MINTEMP
#define HEATER_2_MINTEMP HEATER_0_MINTEMP
#define HEATER_3_MINTEMP HEATER_0_MINTEMP
#define HEATER_4_MINTEMP HEATER_0_MINTEMP
#define HEATER_5_MINTEMP HEATER_0_MINTEMP
#define BED_MINTEMP HEATER_0_MINTEMP

#define HEATER_0_MAXTEMP 290
#define HEATER_1_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_2_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_3_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_4_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_5_MAXTEMP HEATER_0_MAXTEMP
#define BED_MAXTEMP 120

#define PIDTEMP
#define BANG_MAX 255     // Limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // Limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#define PID_K1 0.95      // Smoothing factor within any PID loop
#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU           // Add PID editing to the "Advanced Settings" menu. (~700 bytes of PROGMEM)
  #define PID_AUTOTUNE_MENU       // Add PID auto-tuning to the "Advanced Settings" menu. (~250 bytes of PROGMEM)
  #define PID_FUNCTIONAL_RANGE 10
  #define DEFAULT_Kp 21.73
  #define DEFAULT_Ki 1.54
  #define DEFAULT_Kd 76.55
#endif

#define PIDTEMPBED

#define MAX_BED_POWER 255

#if ENABLED(PIDTEMPBED)
  #define DEFAULT_bedKp 10.00
  #define DEFAULT_bedKi .023
  #define DEFAULT_bedKd 305.4
#endif

//#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 1000

#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

#define ENDSTOPPULLUPS

#define X_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING true // set to true to invert the logic of the probe.

#define X_DRIVER_TYPE  TMC2208
#define Y_DRIVER_TYPE  TMC2208
#define Z_DRIVER_TYPE  TMC2208
#define E0_DRIVER_TYPE TMC2208

/**
 * Endstop Noise Threshold
 *
 * Enable if your probe or endstops falsely trigger due to noise.
 *
 * - Higher values may affect repeatability or accuracy of some bed probes.
 * - To fix noise install a 100nF ceramic capacitor inline with the switch.
 * - This feature is not required for common micro-switches mounted on PCBs
 *   based on the Makerbot design, which already have the 100nF capacitor.
 *
 * :[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 463 }

#define DEFAULT_MAX_FEEDRATE          { 500, 500, 15, 50 }

#define DEFAULT_MAX_ACCELERATION      { 500, 500, 100, 5000 }

#define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   500    // X, Y, Z acceleration for travel (non printing) moves

#define JUNCTION_DEVIATION
#if ENABLED(JUNCTION_DEVIATION)
  #define JUNCTION_DEVIATION_MM 0.02  // (mm) Distance from real junction edge
#endif

#if DISABLED(JUNCTION_DEVIATION)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
#endif

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance

#define S_CURVE_ACCELERATION

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

#define FIX_MOUNTED_PROBE

#define X_PROBE_OFFSET_FROM_EXTRUDER -44  // X offset: -left  +right  [of the nozzle]
#define Y_PROBE_OFFSET_FROM_EXTRUDER -10  // Y offset: -front +behind [the nozzle]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0    // Z offset: -below +above  [the nozzle]

#define MIN_PROBE_EDGE 5

#define XY_PROBE_SPEED 12000

#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

#define MULTIPLE_PROBING 2

#define Z_CLEARANCE_DEPLOY_PROBE    5
#define Z_CLEARANCE_BETWEEN_PROBES  3
#define Z_CLEARANCE_MULTI_PROBE     3
#define Z_AFTER_PROBING           5

#define Z_PROBE_LOW_POINT          -3

#define Z_PROBE_OFFSET_RANGE_MIN -5
#define Z_PROBE_OFFSET_RANGE_MAX 2

#define Z_MIN_PROBE_REPEATABILITY_TEST

#define PROBING_HEATERS_OFF       // Turn heaters off when probing

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_REDUCED_ACCURACY_WARNING

#define DISABLE_E false

#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false

//#define UNKNOWN_Z_NO_RAISE // Don't raise Z (lower the bed) if Z is "unknown." For beds that fall when Z is powered off.

#define Z_HOMING_HEIGHT 4

#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define X_BED_SIZE 235
#define Y_BED_SIZE 235

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 250

#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     
  #define FIL_RUNOUT_INVERTING false 
  #define FIL_RUNOUT_PULLUP          
  #define FILAMENT_RUNOUT_SCRIPT "M600"

#endif

#define AUTO_BED_LEVELING_BILINEAR

#define RESTORE_LEVELING_AFTER_G28

#if ENABLED(MESH_BED_LEVELING) || ENABLED(AUTO_BED_LEVELING_BILINEAR) || ENABLED(AUTO_BED_LEVELING_UBL)
  #define ENABLE_LEVELING_FADE_HEIGHT
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0

#endif

#if ENABLED(AUTO_BED_LEVELING_LINEAR) || ENABLED(AUTO_BED_LEVELING_BILINEAR)
  
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
  
  #define EZABL_PROBE_EDGE 30
  #define LEFT_PROBE_BED_POSITION (max(EZABL_PROBE_EDGE, X_PROBE_OFFSET_FROM_EXTRUDER))
  #define RIGHT_PROBE_BED_POSITION (min(X_BED_SIZE - EZABL_PROBE_EDGE, X_BED_SIZE + X_PROBE_OFFSET_FROM_EXTRUDER))
  #define FRONT_PROBE_BED_POSITION (max(EZABL_PROBE_EDGE, Y_PROBE_OFFSET_FROM_EXTRUDER))
  #define BACK_PROBE_BED_POSITION (min(Y_BED_SIZE - EZABL_PROBE_EDGE, Y_BED_SIZE + Y_PROBE_OFFSET_FROM_EXTRUDER))
  
  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
    #define EXTRAPOLATE_BEYOND_GRID
  #endif

#endif

#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET 30
  #define LEVEL_CORNERS_Z_HOP  4.0
#endif

#define MANUAL_X_HOME_POS 0
#define MANUAL_Y_HOME_POS 0
#define MANUAL_Z_HOME_POS 0

#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT ((X_BED_SIZE) / 2)
  #define Z_SAFE_HOMING_Y_POINT ((Y_BED_SIZE) / 2)
#endif

#define HOMING_FEEDRATE_XY (40*60)
#define HOMING_FEEDRATE_Z  (8*60)


#define VALIDATE_HOMING_ENDSTOPS

#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT

#define HOST_KEEPALIVE_FEATURE        
#define DEFAULT_KEEPALIVE_INTERVAL 2  
#define BUSY_WHILE_HEATING            

#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 200
#define PREHEAT_1_TEMP_BED     60
#define PREHEAT_1_FAN_SPEED     0

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    100
#define PREHEAT_2_FAN_SPEED     0

#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_XY_FEEDRATE 100
  #define NOZZLE_PARK_Z_FEEDRATE 5
#endif

#define PRINTJOB_TIMER_AUTOSTART
#define LCD_LANGUAGE en
#define DISPLAY_CHARSET_HD44780 WESTERN
#define LCD_INFO_SCREEN_STYLE 0
#define SDSUPPORT
#define INDIVIDUAL_AXIS_HOMING_MENU
#define SPEAKER
#define CR10_STOCKDISPLAY

#include "Configuration_backend.h"

#define UNIFIED_VERSION "TH3D U1.R2.9c"

