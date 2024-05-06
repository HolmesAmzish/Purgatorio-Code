#include <WiFi.h>   //接入Wifi的头文件
#include <PubSubClient.h>  //发布订阅操作的头文件
#include <ArduinoJson.h>   //解析Json数据的头文件
#include "DFRobot_Aliyun.h"  //Dfrobot提供的阿里云接入验证的头文件
#include "DFRobot_DHT11.h"  //Dfrobot提供的DHT11温湿度模块操作头文件
            
#define DHT11_PIN D2
  //定义温湿度传感器对应的数字接口
            
            /*配置WIFI名和密码*/
            const char * WIFI_SSID     = "
qwerasdf
";
            const char * WIFI_PASSWORD = "
qwerasdf
";
            
            /*配置设备证书信息*/
            String ProductKey = "
k0ziscdIXto
";
            String ClientId = "
12345
";
            String DeviceName = "
AirConditioner
";
            String DeviceSecret = "
45c74e82cd732d6964c7e1fb8fe84b02
";
            
            /*配置域名和端口号*/
            String ALIYUN_SERVER = "
iot-as-mqtt.cn-shanghai.aliyuncs.com
";
            uint16_t PORT = 
1883
;
            
            /*需要操作的产品标识符(温度和湿度两个标识符)*/
            String TempIdentifier = "
temperatrue
";
            String HumiIdentifier = "
humidity
";
            
            /*需要上报和订阅的两个TOPIC*/
            const char * subTopic = "
/sys/k0ziscdIXto/AirConditioner/thing/event/property/post_reply
";//订阅（物模型通信Topic）
            const char * pubTopic = "
/sys/k0ziscdIXto/AirConditioner/thing/event/property/post /sys/k0ziscdIXto/${deviceName}/thing/event/property/post
";//发布（物模型通信Topic）
            
            DFRobot_Aliyun myAliyun; //DFRobot_Aliyun对象，用于配置接入阿里云所需的参数，并用通过计算HMAC获得MQTT接入密码
            WiFiClient espClient;  //是WiFiClient对象，用于为发布订阅客户端指明实际的WiFi载体
            PubSubClient client(espClient); //Client是PubSubClient对象，由espClient创建出的实例，用于操作MQTT的接入
            DFRobot_DHT11 DHT; //温湿度传感器控制对象
            
            void connectWiFi(){
              Serial.print("Connecting to ");
              Serial.println(WIFI_SSID);
              WiFi.begin(
WIFI_SSID
, 
WIFI_PASSWORD
); //连接房间WIFI
              while(WiFi.status() != WL_CONNECTED){
                delay(500);
                Serial.print(".");
              }
              Serial.println();
              Serial.println("WiFi connected");
              Serial.print("IP Adderss: ");
              Serial.println(WiFi.localIP()); //显示获得的IP地址
            }
            
            void callback(char * topic, byte * payload, unsigned int len){
              Serial.print("Recevice [");
              Serial.print(topic);
              Serial.print("] ");
              for (int i = 0; i < len; i++){
                Serial.print((char)payload[i]);
              }
              Serial.println();
            }
            
            void ConnectAliyun(){
              while(!client.connected()){
                Serial.print("Attempting MQTT connection...");
                /*根据自动计算的用户名和密码连接到Alinyun的设备，这里需要填写MQTT连接所需提交的三个参数*/
                if(client.connect(myAliyun.
client_id
,myAliyun.
username
,myAliyun.
password
)){
                  Serial.println("connected");
                  client.subscribe(
subTopic
); //订阅主题
                }else{
                  Serial.print("failed, rc=");
                  Serial.print(client.state());
                  Serial.println(" try again in 5 seconds");
                  delay(5000);
                }
              }
            }
            void setup(){
              Serial.begin(115200);
              
              /*连接WIFI*/
              
connectWiFi();

              
              /*初始化Alinyun的配置，可自动计算用户名和密码*/
              myAliyun.init(ALIYUN_SERVER,ProductKey,ClientId,DeviceName,DeviceSecret);
              
              client.setServer(myAliyun.mqtt_server,PORT);
              
              /*设置回调函数，当收到订阅信息时会执行回调函数*/
              client.setCallback(
callback
);
              
              /*连接到Aliyun*/
              
ConnectAliyun();

            }
            
            uint8_t tempTime = 0;
            void loop(){
              if(!client.connected()){
                
ConnectAliyun();
 //如果连接阿里云不成功，需要重复连接
              }
              /*一分钟上报N次温湿度信息，N取决于循环次数或者Delay时间。
            目前本虚仿程序仅允许设置以下三种上报频率：
            每分钟上报2次、每分钟上报1次、每两分钟上报1次，
            其他设置均判定为错误。*/
              if(tempTime > 
60
){//30,60,120
                tempTime = 0;
                DHT.read(
DHT11_PIN
);  //读取温湿度的值返回到DHT对象
                Serial.print("DHT.temperature=");
                Serial.println(DHT.temperature);
                Serial.print("DHT.humidity=");
                Serial.println(DHT.humidity);
                client.publish(pubTopic,("{\"id\":"+
ClientId
+",\"params\":{\""+
                
TempIdentifier
+"\":"+
                DHT.
temperature
+",\""+
                
HumiIdentifier
+"\":"+
                DHT.
humidity
+"},\"method\":\"thing.event.property.post\"}").c_str());
              }else{
                tempTime++;
                delay(1000);
              }
              client.loop();
            }            
        