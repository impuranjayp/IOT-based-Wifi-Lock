#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#define WIFISSID "Meet"
#define WIFIPW "mmeett99"
#define AUTH "Ht9-7bdtA_EdfbySi1IqcUkBVs8OMCLu"
SoftwareSerial NodeMCU(D2,D3);
int pass;

void setup(){
	Serial.begin(9600);
  Blynk.begin(AUTH,WIFISSID,WIFIPW);
   // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(WIFISSID);

  
  WiFi.begin(WIFISSID, WIFIPW);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  
  
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());

	NodeMCU.begin(4800);
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);
}
BLYNK_WRITE(V5) // V5 is the number of Virtual Pin  
{
  pass = param.asFloat();
  Serial.println(pass);
  Blynk.virtualWrite(V5,"WELCOME");
}
BLYNK_WRITE(V6) // V6 is the number of Virtual Pin  
{
  pass = param.asFloat();
  Serial.println(pass);
}
void loop(){
  Blynk.run();
	int i = pass;
	NodeMCU.print(i);
	NodeMCU.println("\n");
	delay(30);
}
