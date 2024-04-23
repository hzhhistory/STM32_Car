# Smart Car

### 通讯

通讯方式：./FirmWare/connect中分别为esp8266的连接和发送端的固件代码。

平台：platfromIO

编译软件：vscode

使用STA+AP模式进行通信支持上电即连IP和端口默认直连

![image-20231205213635601](.\image\image-20231205213635601.png)

### 遥控器

#### 软件

放置在./FirmWare/yaokong中

平台：Clion＋STM32cubeMX

系统：FreeRTOS

#### 硬件

包括小车的硬件图原理图和遥控器的板框图。

![image-20240423105901872](.\image\image-20240423105901872.png)

### STM32小车

放置在./FirmWare/STM32_CAR中

平台：Clion＋STM32cubeMX

系统：FreeRTOS

### Qt软件

放置在SoftWare中的一个Qt的小程序，的上位机控制功能。