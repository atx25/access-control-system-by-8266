/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-29 11:37:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-31 20:36:16
 * @FilePath: \1\src\main.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by atx25, All Rights Reserved. 
 */
#include <ESP8266WiFi.h>             // esp8266库
#include <MySQL_Connection.h>    // Arduino连接Mysql的库
#include <MySQL_Cursor.h>
struct key
{
  /* data */
  int key[9];
  int id;
};
struct key ks[3]={ {50,48,50,68,65,54,50,48},0,{66,48,48,53,49,69,68,65}}

int key1[]={50,48,50,68,65,54,50,48};
int key2[]={66,48,48,53,49,69,68,65};
int key3[]={56,54,49,66,50,49,69,65};
IPAddress server_addr(192,168,0,205);   // 安装Mysql的电脑的IP地址
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
  Serial.begin(9600);
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
  if(Receivebyte()==true)
  {
    for(int i=1;i<9;i++)
    {
      if(Rxbyte[i]==key1[i-1])
      {

      }
      Serial.println(Rxbyte[i]);
    }
    addData("atx",i++);
  }
}
