#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <Arduino.h>
 // WiFi网络信息
const char* ssid = "ATX";
const char* password = "123456789";
 // MySQL数据库信息
IPAddress server_addr(10, 204, 80, 48);  // 数据库IP地址
const char* user = "root";  // 数据库用户名
const char* password = "1324897195"; // 数据库密码名
const char* database = "drom";  // 数据库名字 
 // WiFi客户端和MySQL连接
WiFiClient client;
MySQL_Connection conn((Client *)&client);
 void setup()
{
    // 连接WiFi网络
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("WiFi connected");
     // 连接MySQL数据库
    if (conn.connect(server_addr, user, password)) {
        Serial.println("Connected to MySQL database");
    } else {
        Serial.println("Connection to MySQL database failed");
    }
}
 void loop()
{
    // 在这里添加增加和删除数据库数据的代码
}