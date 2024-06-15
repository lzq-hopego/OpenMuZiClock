#ifndef __NET_H
#define __NET_H
#include "common.h"

void wifiConfigBySoftAP(void);
void doClient(void);
void connectWiFi(int timeOut_s);
void getNowWeather(void);
void getFutureWeather(void);
void getAir(void);
void getNTPTime(void);
void getCityID(void);
void checkWiFiStatus(void);
void restartSystem(String msg, bool endTips);
void scanWiFi();
extern bool queryNowWeatherSuccess;
extern bool queryFutureWeatherSuccess;
extern bool queryAirSuccess;
extern String ssid;
extern String pass;
extern String city;
extern String key;
extern String adm;
extern String location;
extern String title;
extern String ziti_style;
extern bool isStartQuery;
extern int minutel;
extern int minuter;
extern int hourl;
extern int hourr;
extern int songNum;
extern bool RingingBell;
// 
#endif