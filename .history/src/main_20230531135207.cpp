#include <ESP8266WiFi.h>             // esp8266库
#include <MySQL_Connection.h>    // Arduino连接Mysql的库
#include <MySQL_Cursor.h>


IPAddress server_addr(10,204,29,47);   // 安装Mysql的电脑的IP地址
char user[] = "root";              // Mysql的用户名
char password[] = "1324897195";        // 登陆Mysql的密码

int Rxbyte[12];
char ssid[] = "ATX";         // WiFi名
char pass[] = "123456789";     // WiFi密码
int i=0;
WiFiClient client;                 // 声明一个Mysql客户端，在lianjieMysql中使用
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;		// 
void addData(String data,int val) { 
  char query[128];
  sprintf(query, "INSERT INTO  txt  ( id,name ) VALUES ('%d','%s')",val,data.c_str()); 
  if (conn.connected()) { 
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn); 
    cur_mem->execute(query); 
    delete cur_mem; 
  } 
}
bool Receivebyte()
{
    int i,dn;
    for(i=0;i<12;++i)
    {
        dn=0;
        while(1)
        {
            if(dn<30)
            {
                if(Serial.available()>0)
                {
                    Rxbyte[i]=Serial.read();
                    break;
                }
                else
                {
                    delay(1);
                    dn+=1;
                }
            }
            else return false; 
        }
    }
        

    return true;
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
  if(Receivebyte()==true)
  {
    addDate("atx",i++);
  }
}
