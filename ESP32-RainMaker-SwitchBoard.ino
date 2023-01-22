#include "EEPROM.h"
#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"

// This is the starting point of the entire program.

// The main Rainmaker node which contains all the devices
Node node;

void sysProvEvent(arduino_event_t *sys_event);
