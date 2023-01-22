/**
 * Allow device to be reset to factory settings
 */
void initReset() {

  // Set boot button as input
  pinMode(BOOT_BUTTON, INPUT);
}


/**
 * This is a fallback in case one would like to 
 * change the Wifi Password or completely reset/reboot the 
 * whole device.
 */
void readReset() {

      if(digitalRead(BOOT_BUTTON) == LOW) { // Push button pressed

        // Key debounce handling
        delay(100);

        // Measure the delay till released
        int startTime = millis();
        while(digitalRead(BOOT_BUTTON) == LOW) delay(50);
        int endTime = millis();

        // If key pressed for more than 10secs, reset all
        if ((endTime - startTime) > 10000) {
          Serial.printf("Reset to factory.\n");
          RMakerFactoryReset(2);
          
        } 
        // If key pressed for more than 3secs, but less than 10, reset Wi-Fi
        else if ((endTime - startTime) > 3000) {
          Serial.printf("Reset Wi-Fi.\n");
          RMakerWiFiReset(2);
          
        } 
        // Do nothing1
        else {
          // no-op
        }
    }
    delay(100);
}
