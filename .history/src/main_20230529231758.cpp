/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-29 11:37:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-29 23:17:13
 * @FilePath: \1\src\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by atx25, All Rights Reserved. 
 */
#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
void setup() {
  // 尝试连接到WiFi
  Serial.begin(115200);
  WiFi.begin("ATX", "123456789");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
   // 连接到 MySQL 数据库
  IPAddress server_addr(10, 204, 80, 48);  // MySQL 服务器 IP 地址
  char user[] = "root";  // MySQL 用户名
  char password[] = "1324897195";  // MySQL 密码
  char db[] = "drom";  // 数据库名称
  MySQL_Connection conn((Client *)&client);
  if (conn.connect(server_addr, 3306, user, password, db)) {
    Serial.println("Connected to MySQL");
  } else {
    Serial.println("Connection failed");
  }
}
void loop(){
  
}
void add_data() {
  MySQL_Cursor *cursor = new MySQL_Cursor(&conn);
  char query[256];
  sprintf(query, "INSERT INTO your_table_name (column1, column2) VALUES ('value1', 'value2')");
  cursor->execute(query);
  delete cursor;
}
void delete_data() {
  MySQL_Cursor *cursor = new MySQL_Cursor(&conn);
  char query[256];
  sprintf(query, "DELETE FROM your_table_name WHERE id = your_id");
  cursor->execute(query);
  delete cursor;
}