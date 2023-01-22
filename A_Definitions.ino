// Name of this Node
const char *NODE_NAME = "HallNode"; 

// The Bluetooth Name and Password for this ESP32 device
const char *BLE_DEVICE_NAME = "HallNode";
const char *BLE_DEVICE_PASS = "hall1234";

// Device Name(s)
const char *DEVICE_FAN = "Fan";
const char *DEVICE_LIGHTS = "Lights";
const char *DEVICE_DOORLIGHT ="Door Light";
const char *DEVICE_CHANDELIER = "Chandelier";

// Input button to control things
static int BOOT_BUTTON = 0;

// Out Pins
static int FAN_RELAY_PIN = 5;
static int LIGHTS_RELAY_PIN = 18;
static int DOORLIGHT_RELAY_PIN = 19;
static int CHANDELIER_RELAY_PIN = 21;

// EEPROM Address
static int FAN_EEPROM_ADDRESS = 0;
static int LIGHTS_EEPROM_ADDRESS = 1;
static int DOORLIGHT_EEPROM_ADDRESS = 2;
static int CHANDELIER_EEPROM_ADDRESS = 3;
