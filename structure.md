# 结构





## 发送视频



​	服务器端，有一个关于udp的vector, 包含clientinfo( id ,room_id, ip, port)

​	服务器端有两个udpsocket对应两个端口，a(注册端口)与b（流端口）,

​	首先主播进入房间，需要通过 udp往服务器的端口a发送注册协议,注册一下，也就是在服务器端的vector中放入自己的信息

​	然后马上开启一个线程，此线程将不断往端口b发送 数据流, 以end为结束。

​	服务器收到数据流后，通过ip与端口在vector中检索，找出该主播对应的观众。向这些观众群发这些包

​	

​	观众收到包，将他添加到 缓存区，如果这个包是end，则将之前所有缓存区内的数据转化为图片并打印，同时清空缓存区。

​	











## 文件

### server

main

my_server_tcp

my_socket_tcp

db_handler

protocol

Common

w1





### client



main

Client

common

protocol

Wd1

Wd2

Wd3





## 数据库

### user

id	username	password	status	balance	credit	 



### room

Id	title	owner_id





















​	



​	