## OpenMuZiClock
一个桌面小摆件，可以查看时间和天气还有可爱的太空人，可切换黑白主题，可以推送本机的cpu 内存和网络的占用给这个小摆件进行显示，全部代码开源
## 最终效果图

![](https://github.com/lzq-hopego/muziclock/raw/main/demo/demo1.jpg)

## 耗材
|名字|数量|参考价格|
|---|---|--|
|esp32c3开发板|1|9.9|
|屏幕转接板|1|0|
|2.4寸tft 240x320 st7789v屏幕|1|13.5|
|r1  5.1r贴片电阻1206|1|2|
|r2  20r贴片电阻1206|1|2|
|fpc连接器 10p 5mm间距 翻盖下接|1|0.2|
|12\*12\*6轻触开关直插|1|2.8|
|无源蜂鸣器|1|1.5|
|5582光敏电阻|1|2.9|
|10k电阻|1|2.3|

## 接线图

![](https://github.com/lzq-hopego/OpenMuZiClock/raw/main/demo/connection.png)

## 烧录
- 方法一，使用esptool
  ```
  esptool --chip esp32c3 --port "COMx" --baud 921600  --before default_reset --after hard_reset write_flash -e -z --flash_size 4MB 0x00 "OpenMuZiClock.v1.0.bin"
  ```
- 方法二，使用MuziClockUpdate.exe

  ![](https://github.com/lzq-hopego/OpenMuZiClock/raw/main/demo/upload.png)


## 使用
1. 连接MuZi Clock热点
2. 热点连接成功后会自动跳转到自动配网页面，配置即可
   - 要想显示天气就必须要注册一个和风天气的账号，然后在web配网页面中填写key
   - 设备名，则是主页显示的名字，如果为中文请手动编译固件，编译字体文件替换font目录中的simyou30.h
3. 使用MuZiClockDriver.exe驱动时，muziclock需切换至manager页面后驱动才能正常用
   - 注意muziclock的ip地址，需要在驱动中填写
4. 剩下的功能请读者慢慢品读


## 区别
- 本项目根据b站大聪明的二手脑袋老师的dudu时钟魔改而来，那么本项目和dudu时钟的区别是什么呢？

||DuDu Clock|MuZi Clock|
|---|- |- |
|wifi配网 | √ | √ |
|自动跳配网页面 |  | √ |
|空气质量 | √ | √ |
|更改主题 | √ | √ |
|计时器 | √ | √ |
|重置出厂 | √ | √ |
|可用驱动 |  | √ |
|闹钟 |  | √ |
|显示电脑的cpu等信息 |  | √ |
|自定义标题 |  | √ |
|自动调整主题(根据环境光) |  | √ |

