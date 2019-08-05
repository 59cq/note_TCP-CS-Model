# note_TCP-CS-Model
基于TCP协议的C/S模型


- `int listen(int sockfd, int backlog);`
    - 设置等待连接的最大数量
    - sockfd 被监听的socket描述符
    - backlog 等待连接的最大数量(排队的数量)
    - 返回值 0成功 -1失败

- `int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);`
    - 等待连接,sockfd连接
    - addr 获取连接的地址
    - addrlen 设置连接地址的长度
    - 返回值 专门用于通信的描述符

- `int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);`
    - 建立与指定socket的连接
    - 参数与accept相同

## 编程模型

|Server|Client|
|:-:|:-:|
|创建socket套接字|创建socket套接字|
|准备地址(sockaddr_in,本机地址)|准备地址(服务端地址)|
|绑定(bind)|...|
|监听(listen)|...|
|等待连接(accept,fork)|连接(connect)|
|接收请求(read/recv)|发送请求(write/send)|
|响应请求(write/send)|接收响应(read/recv)|
|关闭(close)|关闭(close)|
