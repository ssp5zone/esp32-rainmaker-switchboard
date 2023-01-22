void initRain() {

  // Initialize the Main Node
  node = RMaker.initNode("Bangalore - Main Hall");
  
  //This is optional
  RMaker.enableOTA(OTA_USING_TOPICS);
  
  //If you want to enable scheduling, set time zone for your region using setTimeZone().
  //The list of available values are provided here https://rainmaker.espressif.com/docs/time-service.html
  // RMaker.setTimeZone("Asia/Shanghai");
  // Alternatively, enable the Timezone service and let the phone apps set the appropriate timezone
  RMaker.enableTZService();

  RMaker.enableSchedule();

  RMaker.enableScenes();
}


void letItRain() {
  
  RMaker.start();
}
