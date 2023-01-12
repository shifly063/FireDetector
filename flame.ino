#include <ESP8266WiFi.h>
#define BLYNK_MAX_SENDBYTES 256
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
int pinBuz = D2;
int pinFlame = D1;
BlynkTimer timer;
char auth[] = "exampleabcdefgh12345"; //Auth code sent via Email
char ssid[] = "ABCD"; //Wifi name
char pass[] = "xxxxx";  //Wifi Password
int state = 0;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pinFlame, INPUT);
  pinMode(pinBuz, OUTPUT);
}
void loop()
{
  int a = digitalRead(pinFlame);
  if (a==LOW){
    digitalWrite(pinBuz, HIGH);
    Serial.println("api");
    if(state==0){
      Blynk.notify("Ada api");
    }
    state = 1;
  }else{
    digitalWrite(pinBuz, LOW);
    state = 0;
  }
  delay(500);
  Blynk.run();
  timer.run();
}
