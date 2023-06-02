#include <ESP8266WiFi.h>             // esp8266库
#include <MySQL_Connection.h>    // Arduino连接Mysql的库
#include <MySQL_Cursor.h>
#include <Arduino.h>

IPAddress server_addr(192,168,164,237);   // 安装Mysql的电脑的IP地址
char user[] = "root";              // Mysql的用户名
char password[] = "1324897195";        // 登陆Mysql的密码

// Mysql中添加一条数据的命令
// arduino_test，test1：刚才创建的数据和表

char ssid[] = "ATX";         // WiFi名
char pass[] = "123456789";     // WiFi密码

WiFiClient client;                 // 声明一个Mysql客户端，在lianjieMysql中使用
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;		// 

void insertData()
{
  MySQL_Cursor *cursor = new MySQL_Cursor(&conn);

  // 使用参数化查询插入数据
  char *query = "INSERT INTO txt (column_1, column_2) VALUES (?, ?)";
  MySQL_Stmt *stmt = conn.prepareStatement(query);
  stmt->setString(0, "value_1");
  stmt->setString(1, "value_2");
  stmt->execute();
  delete stmt;

  delete cursor;
}

void deleteData()
{
  MySQL_Cursor *cursor = new MySQL_Cursor(&conn);

  // 使用参数化查询删除数据
  char *query = "DELETE FROM your_table_name WHERE column_1 = ?";
  MySQL_Stmt *stmt = conn.prepareStatement(query);
  stmt->setString(0, "value_1");
  stmt->execute();
  delete stmt;

  delete cursor;
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);      //  等待端口的释放
  Serial.printf("\nConnecting to %s", ssid);
  WiFi.begin(ssid, pass);         // 连接WiFi
  while (WiFi.status() != WL_CONNECTED) {       // 如果WiFi没有连接，一直循环打印点
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected to network");
  Serial.print("My IP address is: ");
  Serial.println(WiFi.localIP());     // 打印开发板的IP地址

  Serial.print("Connecting to SQL...  ");
  if (conn.connect(server_addr, 3306, user, password))         // 连接数据库
    Serial.println("OK.");   
  else
    Serial.println("FAILED.");
  cursor = new MySQL_Cursor(&conn);    // 创建一个数据库游标实例
}

void loop()
{   
  delay(5000);
}
