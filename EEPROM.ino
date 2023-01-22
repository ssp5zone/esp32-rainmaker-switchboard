/**
 * EEPROM
 * ************************************************************
 * Initialize the EEPROM
 */
void initEEPROM() {
  
  // initialize EEPROM with predefined size
  EEPROM.begin(10);
  
  // Without wait caused some issues. So wait for it to init.
  delay(1000);
  
  Serial.println("EEPROM: Ready!");
}
