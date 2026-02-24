## 固件说明

1. 固件 **不可商用** ，如果商用需要通过邮箱联系我3101978435@qq.com
2. 不开放源代码

## 新旧版本说明
带 **old**的为旧版本(支持jwt获取和风天气)，旧版本指的是旧的接线图，可参考dudu时钟的屏幕接线方案，蜂鸣器io0、光敏电阻io1，ds18b20为io6
结尾带日期的为新版本(支持jwt获取和风天气以及一些小bug的修复)，旧版本只会修复重要功能，新版本为主要更新版本，新版本io如下表所示:
| 引脚编号 | 功能用途                | 所属模块/说明                     | 
|----------|-------------------------|-----------------------------------|
| 0        | BUZZER（蜂鸣器）        | 音频输出                          | 
| 1        | ldrPin（左侧光敏电阻）  | 模拟/数字输入（光敏电阻检测）     |
| 2        | TFT_RST（TFT屏幕复位）  | TFT液晶屏控制                     |  
| 3        | TFT_SCLK（TFT屏幕时钟） | TFT液晶屏SPI通信                  | 
| 5        | ONE_WIRE_BUS            | 单总线（如DS18B20温度传感器）     |
| 6        | TFT_CS（TFT屏幕片选）   | TFT液晶屏SPI片选                  | 
| 7        | TFT_MOSI/SDA（TFT屏幕数据） | TFT液晶屏SPI通信                  | 
| 8        | BUTTON（按钮）          | 按键输入       | 
| 10       | TFT_DC（TFT屏幕数据/命令） | TFT液晶屏控制                   | 


## 密钥生成说明
建议本地生成密钥，可使用`python`进行生成，安装第三方库`cryptography`
运行以下代码进行生成
```
from cryptography.hazmat.primitives.asymmetric import ed25519
from cryptography.hazmat.primitives import serialization
# 生成私钥
private_key = ed25519.Ed25519PrivateKey.generate()
public_key = private_key.public_key()
# 保存私钥（PEM格式）
with open("ed25519_private_私钥.pem", "wb") as f:
   f.write(private_key.private_bytes(
       encoding=serialization.Encoding.PEM,
       format=serialization.PrivateFormat.PKCS8,
       encryption_algorithm=serialization.NoEncryption()
   ))
# 保存公钥（PEM格式）
with open("ed25519_public_公钥.pem", "wb") as f:
   f.write(public_key.public_bytes(
       encoding=serialization.Encoding.PEM,
       format=serialization.PublicFormat.SubjectPublicKeyInfo
   ))
```
