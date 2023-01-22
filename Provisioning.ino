
/**
 * WiFi Provisioning Management
 * ****************************************************************
 * 
 * The WiFi provisioning event handler.
 * This is called when the WiFi provisioning is started, stopped, or when a credential is received.
 */
void sysProvEvent(arduino_event_t *sys_event) {
    switch (sys_event->event_id) {
      
        case ARDUINO_EVENT_PROV_START:
            Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on BLE\n", BLE_DEVICE_NAME, BLE_DEVICE_PASS);
            printQR(BLE_DEVICE_NAME, BLE_DEVICE_PASS, "ble");
            break;
            
        case ARDUINO_EVENT_PROV_INIT:
            wifi_prov_mgr_disable_auto_stop(10000);
            break;
            
        case ARDUINO_EVENT_PROV_CRED_SUCCESS:
            wifi_prov_mgr_stop_provisioning();
            break;
            
        default:;
    }
}

/**
 * Initialize the WiFi Provisioning
 * ****************************************************************
 * 
 * Instead of us manually entering the WiFi credentials, we can use the WiFi provisioning
 * to automatically connect to the WiFi network.
 */
void initProv() {
  
    // On all wifi events, call the sysProvEvent handler
    WiFi.onEvent(sysProvEvent);

    // Start the WiFi provisioning
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, BLE_DEVICE_PASS, BLE_DEVICE_NAME);
}
