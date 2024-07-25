#include <Preferences.h>
#include "net.h"
#include "tftUtil.h"

Preferences prefs; // 声明Preferences对象
String default_title="李木子的时钟"; //默认时钟名

// 读取Wifi账号、密码和城市名称
void getWiFiCity(){
  prefs.begin("clock");
  ssid = prefs.getString("ssid", "");
  pass = prefs.getString("pass", "");
  city = prefs.getString("city", "");
  key=prefs.getString("key", "");
  adm = prefs.getString("adm", "");
  location = prefs.getString("location", "");
  title = prefs.getString("title", "");
  prefs.end();
}

// 写入Wifi账号、密码和城市名称
void setWiFiCity(){
  prefs.begin("clock");
  prefs.putString("ssid", ssid);
  prefs.putString("pass", pass);
  prefs.putString("city", city);
  prefs.putString("adm", adm);
  prefs.putString("key", key);
  prefs.putString("location", location);
  if(title.length()>1){
    prefs.putString("title", title);
  }else{
    prefs.putString("title", default_title);
  }
  prefs.end();
}

// 清除Wifi账号、密码和城市相关信息
void clearWiFiCity(){
  prefs.begin("clock");
  prefs.remove("ssid");
  prefs.remove("pass");
  prefs.remove("city");
  prefs.remove("adm");
  prefs.remove("key");
  prefs.remove("location");
  prefs.remove("backColor");
  prefs.putString("title",default_title);
  prefs.end();
}

// 获取屏幕背光颜色
void getBackColor(){
  prefs.begin("clock");
  backColor = prefs.getInt("backColor",BACK_BLACK);
  prefs.end();
}

// 设置屏幕背光颜色
void setBackColor(int backColor){
  prefs.begin("clock");
  prefs.putInt("backColor",backColor);
  prefs.end();
}

// 使用驱动设置城市
void setUdpCity(String city,String adm){
  prefs.begin("clock");
  prefs.putString("city",city);
  prefs.putString("adm",adm);
  prefs.end();
}

// 使用驱动设置wifi
void setUdpWifi(String ssid,String pass){
  prefs.begin("clock");
  prefs.putString("ssid",ssid);
  prefs.putString("pass",pass);
  prefs.end();
}

// 使用驱动设置title
void setUdpTitle(String title){
  prefs.begin("clock");
  if(title.length()>1){
    prefs.putString("title", title);
  }else{
    prefs.putString("title", default_title);
  }
  prefs.end();
}

// 使用驱动更改主页标题字体
void setUdpTitleFont(String ziti_style){
  prefs.begin("font");
  prefs.putString("ziti_style", ziti_style);
  prefs.end();
  Serial.println(ziti_style);

}
//获取字体
void GetTitleFont(){
  prefs.begin("font");
  ziti_style=prefs.getString("ziti_style", "");
  prefs.end();
}
//获取设备名
void getUdpTitle(){
  prefs.begin("clock");
  title = prefs.getString("title", "");
  prefs.end();
}
//设置时钟响铃时间
void setClockTimer(){
  prefs.begin("clock");
  prefs.putInt("hourl", hourl);
  prefs.putInt("hourr", hourr);
  prefs.putInt("minuter", minuter);
  prefs.putInt("minutel", minutel);
  prefs.putInt("songNum", songNum);
  prefs.putBool("RingingBell", RingingBell);
  prefs.end();
}

//设置时钟响铃时间
void setUdpClockTimer(int hr,int hl,int mr,int ml,int sn,String ring){
  prefs.begin("clock");
  prefs.putInt("hourl",hl );
  prefs.putInt("hourr", hr);
  prefs.putInt("minuter", mr);
  prefs.putInt("minutel", ml);
  prefs.putInt("songNum", sn);
  if(ring=="no"){
    prefs.putBool("RingingBell", false);
  }else{
    prefs.putBool("RingingBell", true);
  }
  prefs.end();
}

//获取时钟响铃时间
void getClockTimer(){
  prefs.begin("clock");
  hourl = prefs.getInt("hourl", 0);
  hourr = prefs.getInt("hourr", 0);
  minuter = prefs.getInt("minuter", 0);
  minutel = prefs.getInt("minutel", 0);
  songNum = prefs.getInt("songNum", 0);
  RingingBell = prefs.getBool("RingingBell", false);
  prefs.end();
}

// 测试用，在读取NVS之前，先写入自己的Wifi信息，免得每次浪费时间再配网
void setInfo4Test(){
  prefs.begin("clock");
  prefs.putString("ssid", "李木子的iqoo");
  prefs.putString("pass", "limuzi0228");
  prefs.putString("city", "陕州");
  prefs.putString("adm", "三门峡");
  prefs.putString("location", "");
  prefs.end();
}



//设置主题切换模式
void setThemeMode(){
  prefs.begin("clock");
  prefs.putBool("thememode", thememode);//0为手动，1为自动
  prefs.end();
}


//设置主题切换模式
void getThemeMode(){
  prefs.begin("clock");
  prefs.getBool("thememode", false);//0为手动，1为自动
  prefs.end();
}