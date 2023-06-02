/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-29 11:37:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-30 23:10:52
 * @FilePath: \1\src\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by atx25, All Rights Reserved. 
 */
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
MySQL_Cursor* cursor;	
int Rxbyte[3];
bool Receivebyte()
{
    int i,dn;
    for(i=0;i<3;++i)
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

void txmss(unsigned char txb[]){
  int i;
  for(i=0;i<4;++i){
    Serial.write(txb[i]);
    delay(5);  
  }

}
void addData(String data,int val) { 
  char query[128]; 
  sprintf(query, "INSERT INTO  txt  ( id,name ) VALUES ('%d','%s')",val,data.c_str()); 
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
  if (conn.connect(server_addr, 3306, user, password,"drom"))         // 连接数据库
    Serial.println("OK.");   
  else
    Serial.println("FAILED.");
  cursor = new MySQL_Cursor(&conn);    // 创建一个数据库游标实例
}

void loop()
{ 
  if(Receivebyte()==1)
  {
    if(Rxbyte[0]==0&&Rxbyte[1]==0&&Rxbyte[2]==1)
    {
      insert into t_record values(null,,?,?,?,?,?)
    }
  }
}
