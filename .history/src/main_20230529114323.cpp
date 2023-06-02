/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-29 10:06:45
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-29 11:37:21
 * @FilePath: \1e:\Astm32\8266\Rc522\rc522\src\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by atx25, All Rights Reserved. 
 */
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
 // WiFi网络的名称和密码
const char* ssid = "502-2.4G";
const char* password = "123456789";
 // MFRC522的引脚连接
const int RST_PIN = D3; // 重置引脚
const int SS_PIN = D1;  // 选择信号引脚
MFRC522 mfrc522(SS_PIN, RST_PIN);   // 创建MFRC522实例

 // 检查该UID是否已授权
bool isAuthorized(String uid) {
  // TODO: 实现从数据库中检查该UID是否已授权的代码
  return true; // 默认返回true，表示已授权
}
 // 解锁门禁系统
void unlockDoor() {
  // TODO: 添加控制锁的代码
  Serial.println("Access granted");
}

 void setup() {
  Serial.begin(115200);
  SPI.begin();      // 初始化SPI通信
  mfrc522.PCD_Init();  // 初始化MFRC522
  WiFi.begin(ssid, password); // 连接WiFi
   while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
   Serial.println("Connected to WiFi");
}
 void loop() {
  // 检查是否有新卡片出现
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // 获取卡片UID
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }
     Serial.println("Access granted");
     // 检查该UID是否已授权
    if (isAuthorized(uid)) {
      // 允许进入
      unlockDoor();
    } else {
      // 不允许进入
      Serial.println("Access denied");
    }
     mfrc522.PICC_HaltA(); // 停止卡片
    mfrc522.PCD_StopCrypto1(); // 关闭Crypto1加密
  }
}