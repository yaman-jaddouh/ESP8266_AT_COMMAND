#include <SoftwareSerial.h>
#include <Arduino_JSON.h>
SoftwareSerial esp(10, 11);     //rx,tx arduino
String ssid = "XXXXXXX";       //Put the SSID of your network
String passowrd = "XXXXXXX";  //Put the Password of your network
String thingboard_token = "XXXXXXXXXXXXXX";
String api_post = "http://thingsboard.cloud/api/v1/" + thingboard_token + "/attributes";                    //Put the token of your Account  https://thingsboard.cloud/
String api_get = "http://thingsboard.cloud/api/v1/" + thingboard_token + "/attributes?clientKeys=message";  // replace the message with your owns key
String response_api = "";
String checkWiFi();
String connectWiFi(String ssid, String password);
String httpGET(String URL);
void setup() {
  Serial.begin(9600);
  esp.begin(9600);
  delay(100);
  while (checkWiFi() == "NO WIFI CONNECTED") {
    connectWiFi(ssid, passowrd);
  }
  Serial.println("done");
  delay(1000);
}

void loop() {
  JSONVar dataPOST;
  dataPOST["message"] = "hi there";
  httpPOST(api_post, JSON.stringify(dataPOST));
  delay(1000);
  response_api = httpGET(api_get);
  Serial.println(response_api);
  Serial.print("Response Code :");
  Serial.println(response_api.substring(0, response_api.indexOf(',')));
  Serial.print("Response Data :");
  Serial.println(response_api.substring(1 + response_api.indexOf(',')));
  JSONVar dataGET = JSON.parse(response_api.substring(1 + response_api.indexOf(',')));
  Serial.println(response_api.substring(1 + response_api.indexOf(',')));
  Serial.println(dataGET["client"]["message"]);
  delay(1000);
}

String checkWiFi() {
  String response = "";
  esp.println("AT+WICON?");
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}
String connectWiFi(String ssid, String password) {
  String response = "";
  esp.println("AT+WICON=" + ssid + "," + password);
  delay(5000);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}
String httpGET(String URL) {
  String response = "";
  unsigned long t1 = millis();
  esp.println("AT+HTGET=" + URL);
  while (esp.available() <= 0 && millis() - t1 < 5000) {}
  while (esp.available() > 0) {
    response += (char)esp.read();
    // Serial.write(esp.read());
    delay(1);
  }
  return response;
}
String httpPOST(String URL, String Data) {
  String response = "";
  unsigned long t1 = millis();
  esp.println("AT+HTPOST=" + URL + "," + Data);
  while (esp.available() <= 0 && millis() - t1 < 5000) {}
  while (esp.available() > 0) {
    response += (char)esp.read();
    // Serial.write(esp.read());
    delay(1);
  }
  return response;
}
