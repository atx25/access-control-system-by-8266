/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-29 10:06:45
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-29 22:53:37
 * @FilePath: \1\src\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by atx25, All Rights Reserved. 
 */
#include <Arduino.h>
#include <ESP8266WiFi.h> 
#include <MySQL_Connection.h> 
#include <MySQL_Cursor.h> 
void deleteData(int id);
void addData(String data);
// 替换为你的网络信息 
const char* ssid = "ATX"; 
const char* password = "123456789"; 
String usename = "root";
String usepwd = "1324897195";
char *username[]=(char*)usename.c_str();
cchar *userpwd[]=(char*)usepwd.c_str();
// 替换为你的MySQL服务器IP地址 
IPAddress server(10,204,80,48); 
 
WiFiClient client; 
MySQL_Connection conn((Client *)&client); 
 
void setup() { 
  Serial.begin(115200); 
 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(1000); 
    Serial.println("Connecting to WiFi..."); 
  } 
  Serial.println("Connected to WiFi"); 
 
  if (conn.connect(server, 3306,username,userpwd)) { 
    Serial.println("Connected to MySQL server"); 
  } else { 
    Serial.println("Connection failed"); 
  } 
} 
 
void loop() { 
  // 添加数据到数据库 
  addData("Data 1"); 
 
  // 从数据库中删除数据 
  deleteData(1); 
 
  delay(5000); 
} 
 
void addData(String data) { 
  char query[128]; 
  sprintf(query, "INSERT INTO  txt  ( name ) VALUES ('%s')", data.c_str()); 
 
  if (conn.connected()) { 
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn); 
    cur_mem->execute(query); 
    delete cur_mem; 
  } 
} 
 
void deleteData(int id) { 
  char query[128]; 
  sprintf(query, "DELETE FROM  txt  WHERE  id =%d", id); 
 
  if (conn.connected()) { 
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn); 
    cur_mem->execute(query); 
    delete cur_mem; 
  } 
} 