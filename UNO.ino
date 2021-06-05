#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(3,2);

void setup(){
	
	Serial.begin(9600);
	ArduinoUno.begin(4800);

}

void loop(){
  while(ArduinoUno.available()>0){
	float val = ArduinoUno.parseFloat();
	if(ArduinoUno.read()== '\n'){
	if(val == 999){
  Serial.println("Access Granted: ");
	Serial.println(val," Door is Unlocked");
  digitalWrite(9,HIGH);
	}
  if(val == 1){
  Serial.println("Door is Locked.");
  digitalWrite(9,LOW);
  }
  if (val == 0){
  Serial.println("Door is Locked.");
  digitalWrite(9,LOW);
  }
	}
 }
delay(30);
}
