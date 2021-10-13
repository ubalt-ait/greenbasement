#include <ArduinoJson.h>

bool verbose;

void setup() {
  Serial.begin(9600);
  verbose = false;
  if ( verbose ) Serial.write(49);
  if ( verbose ) Serial.write('\n');
  if ( verbose ) Serial.write("Ready to listen...\n");
}

void loop() {
  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
  String message = Serial.readString();
  //Serial.print("Message: ");
  //Serial.println(message);
  // {"cmd":"Temp"}
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, message);
  const char* command = doc["cmd"];
  if ( verbose ) Serial.print("Command: ");
  if ( verbose ) Serial.println(command);
  if ( strcmp(command,"Temp")==0 )
  {
    doc["value"] = 34;
    serializeJson(doc, Serial);
    Serial.print("\n");
  }
  delay(500);
}
