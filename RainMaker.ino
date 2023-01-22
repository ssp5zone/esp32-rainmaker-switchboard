/**
 * Initialize the RainMaker and various services
 */
void initRain() {

  // Initialize the Main Node
  node = RMaker.initNode(NODE_NAME);
  
  //This is optional
  RMaker.enableOTA(OTA_USING_TOPICS);
  
  // Get the Tiemzone from the User's Mobile
  RMaker.enableTZService();

  // Enable the Schedule Service.
  RMaker.enableSchedule();

  // Enable the Scenes Service.
  RMaker.enableScenes();
}

/**
 * Start the RainMaker
 */
void letItRain() {
  
  RMaker.start();
}
