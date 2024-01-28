#include <SoftwareSerial.h>
SoftwareSerial esp(10, 11);  // rx,tx arduino
String FileAppend(String fileName, String contentFile);
String listFiles();
String removeFile(String fileName);
String FileWrite(String fileName, String contentFile);
void setup() {
  Serial.begin(9600);
  esp.begin(9600);
  delay(1000);
  Serial.print(appendFile("1.txt", "Hello from Arduino"));
  Serial.print(appendFile("1.txt", "Hello from Arduino"));
  delay(100);
  Serial.print(listFiles());
  delay(100);
  Serial.print(readFile("1.txt"));
  delay(100);
  Serial.print(removeFile("1.txt"));
  delay(100);
  Serial.print(listFiles());
  delay(100);
  Serial.print(writeFile("1.txt", "Hello from Arduino"));
  delay(100);
  Serial.print(writeFile("1.txt", "Hello There!"));
  delay(100);
  Serial.print(readFile("1.txt"));
  delay(100);
  Serial.print(removeFile("1.txt"));
}
void loop() {
}
String appendFile(String fileName, String contentFile) {
  String response = "";
  esp.println("AT+FSADD=" + fileName + "," + contentFile);
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}
String listFiles() {
  String response = "";
  esp.println("AT+FSLIST?");
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}

String removeFile(String fileName) {
  String response = "";
  esp.println("AT+FSREMOVE=" + fileName);
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}
String readFile(String fileName) {
  String response = "";
  esp.println("AT+FSREAD=" + fileName);
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}

String writeFile(String fileName, String contentFile) {
  String response = "";
  esp.println("AT+FSWRITE=" + fileName + "," + contentFile);
  delay(100);
  while (esp.available() > 0) {
    response += (char)esp.read();
    delay(1);
  }
  return response;
}