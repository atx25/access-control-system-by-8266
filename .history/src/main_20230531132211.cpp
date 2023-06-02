#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
 IPAddress server_addr(192, 168, 33, 1); // MySQL服务器IP地址
char user[] = "root"; // 登录MySQL的用户名
char password[] = "1324897195"; // 登录MySQL的密码
char db[] = "drom"; // 数据库名称
 WiFiClient client;
MySQL_Connection conn((Client *)&client);
 void setup() {
  Serial.begin(115200);
  WiFi.begin("ssid", "password"); // 连接WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
   Serial.println("Connecting to MySQL Server...");
  while (!conn.connect(server_addr, &user, password)) { // 连接MySQL
    delay(1000);
    Serial.println("Connecting to MySQL Server...");
  }
  Serial.println("Connected to MySQL Server");
   delay(1000);
   // 创建数据库
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute("CREATE DATABASE IF NOT EXISTS drom");
  delete cur_mem;
   // 选择数据库
  MySQL_Cursor *cur_sel = new MySQL_Cursor(&conn);
  cur_sel->execute("USE drom");
  delete cur_sel;
   Serial.println("Setup finished");
}
 void loop() {
  // 主代码部分
}