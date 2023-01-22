Button *fan;
Button *lights;
Button *bulb;
Button *extra;

void setup() {
  Serial.begin(115200);

  // Init EEPROM
  initEEPROM();

  // Init Rain Maker
  initRain();

  // Init Buttons
  initButtons();

  // Begin Rain Maker
  letItRain();

  // Begin Provisioning
  initProv();
}

void loop() {

  // Keep Reading reset button
  readReset();
}


void initButtons() {
  fan = new Button(DEVICE_FAN, FAN_RELAY_PIN, FAN_EEPROM_ADDRESS, ESP_RMAKER_DEVICE_FAN);
  lights = new Button(DEVICE_LIGHTS, LIGHTS_RELAY_PIN, LIGHTS_EEPROM_ADDRESS, ESP_RMAKER_DEVICE_LIGHTBULB);
  bulb = new Button(DEVICE_DOORLIGHT, DOORLIGHT_RELAY_PIN, DOORLIGHT_EEPROM_ADDRESS, ESP_RMAKER_DEVICE_LIGHTBULB);
  extra = new Button(DEVICE_CHANDELIER, CHANDELIER_RELAY_PIN, CHANDELIER_EEPROM_ADDRESS, ESP_RMAKER_DEVICE_SWITCH);
}
