#include <ESP8266WiFi.h>
#include<Arduino.h>
// #include <ESP8266Ping.h>

#define BAUDRATE 115200         // 串口波特率
IPAddress apIP(192, 168, 4, 1); // 8266 DNS的AP-IP地址
WiFiServer server(80);          //启动服务器

String ssid = "WIFINAME"; //默认SSID
String pssd = "88888888";    //默认密码

void setup()
{
    Serial.begin(BAUDRATE);
    WiFi.hostname("8266-AP"); // 设置ESP8266设备名
    WiFi.mode(WIFI_AP);
    if (WiFi.softAP(ssid, pssd, 6, false)) // 接入点是否隐藏SSID:false
    {
        Serial.println("[success]esp8266-ap-is-readdy");
    }
    IPAddress ip = WiFi.softAPIP(); //获取ip地址
    // Serial.println(ip);             //打印出来ip地址
    server.begin();
}

WiFiClient client;
void loop()
{
    delay(500);
    Serial.println("waiting for client connection");
    client = server.available();

    if (client)
    {
        if (client.connected())
        {
            Serial.print("[success]client connected!");
            Serial.println(client.remoteIP());
        }

        while (client.connected())
        {
            while (client.available() > 0)
            {
                Serial.write(client.read()); // 读取从连接的设备的数据
            }
            while (Serial.available() > 0)
            {
                client.write(Serial.read()); // 从串口读取数据发送给连接的客户端
            }
        }
        client.stop();
        Serial.println("[fail]client disconnected");
    }
}
