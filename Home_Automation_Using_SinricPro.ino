#define ENABLE_DEBUG
#ifdef  ENABLE_DEBUG
       #define DEBUG_ESP_PORT_SERIAL
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"
#include <map>

#define WIFI_SSID   "OnePlus Nord CE3 5G"
#define WIFI_PASSWORD "12345678"
#define APP_KEY        ""
#define APP_SECRET     ""

#define DeviceID1      ""
#define DeviceID2      ""
#define DeviceID3      ""

#define WifiPin 16   //D0
#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14 //D5
#define RelayPin4 12 //D6
#define BAUD_RATE   9600

typedef struct{
  int relayPin;
}deviceconfigpin;

std::map<String,deviceconfigpin> devices = {
  {DeviceID1,{RelayPin1}},
  {DeviceID2,{RelayPin2}},
  {DeviceID3,{RelayPin3}},
};

void setupRelays() {
  for (auto &device : devices) {
    int relayPIN = device.second.relayPIN;
    pinMode(relayPIN, OUTPUT);
    digitalWrite(relayPIN, HIGH);
  }
}


}