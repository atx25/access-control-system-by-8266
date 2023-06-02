#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
 IPAddress server_addr(192, 168, 33, 1); // MySQL服务器IP地址
char user[] = "root"; // 登录MySQL的用户名
char password[] = "1324897195"; // 登录MySQL的密码
char db[] = "drom"; // 数据库名称
 WiFiClient client;
 MySQL_Cursor* cursor;	
MySQL_Connection conn((Client *)&lient);
void addData(String data,int val) { 
  char query[128]; 
  sprintf(query, "INSERT INTO  txt  ( id,name ) VALUES ('%d','%s')",val,data.c_str()); 
  if (conn.connected()) { 
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn); 
    cur_mem->execute(query); 
    delete cur_mem; 
  } 
}
 void setup() {
  Serial.begin(115200);
  WiFi.begin("ATX", "123456789"); // 连接WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("Connecting to MySQL Server...");
  while (!conn.connect(server_addr,3306, user, password,db)) { // 连接MySQL
    delay(1000);
    Serial.println("Connecting to MySQL Server...");
  }
  Serial.println("Connected to MySQL Server");
  delay(1000);
   // 创建数据库
  cursor = new MySQL_Cursor(&conn);    // 创建一个数据库游标实例
  addData("atx",1);
}
 void loop() {
  // 主代码部分
}