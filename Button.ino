
/**
 * Button Class
 * ****************************************************************
 * 
 * A custom wrapper that manages the Rain Maker Device, the EEPROM (remmembering the last state) and the actual button.
 */
class Button {

  // Private members
  private:
    
    const char *_name; // The name of this button
    int _pin; // The pin number of where the relay is connected
    int _address; // The EEPROM address to store the last state
    int _state; // The last known state of this button
    Device _device; // The Rain Maker Device
    const char *_deviceType; // The type of the Rain Maker Device
    

    /**
     * Initialize the button
     */
    void _init() {
      // setup the pin as a digital output pin
      pinMode (_pin, OUTPUT);
      
      // Make Sure its off in start
      digitalWrite (_pin, HIGH);

      // Read the last known state of this button
      _state = EEPROM.read(_address);

      // Set the state if present
      if(_state == LOW) {
        ON(); 
      }
    }

    /**
     * Bind this button as a Rain Maker Device
     */
    void _bindDevice() {

      // The relay states are opposite to the Rain Maker's. Invert them
      bool power = _state == HIGH ? false : true;

      // Init this as one of the Rain Maker Device
      if(strcmp(_deviceType, ESP_RMAKER_DEVICE_LIGHTBULB) == 0) {
        _device = LightBulb(_name, this, power);
      } 
      else if (strcmp(_deviceType, ESP_RMAKER_DEVICE_FAN) == 0) {
        _device = Fan(_name, this, power);
      } 
      else {
        _device = Switch(_name, this, power);                    
      }
      
      // Add a callback on RainMaker update event
      _device.addCb(_cb);

      // Add this device to the Main Node
      node.addDevice(_device);
    }
    
    /**
     * Persist the state of this button.
     * This is used to remember the last state of this button in the event
     * of a power failure or disconnection from the power source.
     */
    void _persist(int state) {
      _state = state;
      EEPROM.write(_address, _state);
      EEPROM.commit();
    }

    /**
     * The callback for RainMaker events
     */
    static void _cb(Device *device, Param *param, const param_val_t val, void *priv_data, write_ctx_t *ctx)
    {
        const char *device_name = device->getDeviceName();
        const char *param_name = param->getParamName();
    
        // If this is a Power State change event
        if(strcmp(param_name, "Power") == 0) {

            Serial.printf("%s - %s: Received value = %s\n", device_name, param_name, val.val.b ? "true" : "false");

            // Get the button instance associated with this device
            Button *button = (Button *)(priv_data);

            // Update the state of the button
            button->SWITCH(val.val.b);

            // Tell the App that the state has been updated. (The button toggle animation on the App)
            param->updateAndReport(val);
        }
    }

  // Public members
  public:

    Button(const char *buttonName, int buttonPin, int eepromAddress, const char *type) {
      _name = buttonName;
      _pin = buttonPin;
      _address = eepromAddress;
      _deviceType = type;
      _init();
      _bindDevice();
      Serial.printf("Created button: %s", _name);
      Serial.println();
    }
    
    void ON() {
      digitalWrite (_pin, LOW); 
      _persist(LOW);
    }
    void OFF() {
      digitalWrite (_pin, HIGH); 
      _persist(HIGH);
    }
    void SWITCH(bool value) {
      int state = value == true ? LOW : HIGH;
      digitalWrite (_pin, state); 
      _persist(state);
    } 
    int getState() {
      return _state;
    }
    Device getDevice() {
      return _device;
    }
};
