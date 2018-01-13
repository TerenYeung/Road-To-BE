## Redis 简介

### Redis 是什么

REmote DIctionary Server(Redis) 是一个key-value存储系统；

REmote DIctionary Server(Redis) 是一个由Salvatore Sanfilippo写的key-value存储系统

Redis是一个开源的使用ANSI C语言编写、遵守BSD协议、支持网络、可基于内存亦可持久化的日志型、Key-Value数据库，并提供多种语言的API。

它通常被称为数据结构服务器，因为值（value）可以是 字符串(String), 哈希(Map), 列表(list), 集合(sets) 和 有序集合(sorted sets)等类型。

Redis支持数据的备份，即 master-slave 模式的数据备份。

### Redis 的优点

- 性能极高
- 丰富的数据类型
- 原子性：Redis的所有操作都是原子性的，意思就是要么成功执行要么失败完全不执行。单个操作是原子性的。多个操作也支持事务，即原子性，通过 MULTI 和 EXEC 指令包起来。
- 丰富的特性： Redis还支持 publish/subscribe, 通知, key 过期等等特性

> 什么是原子性,什么是原子性操作？

举个例子：

A想要从自己的帐户中转1000块钱到B的帐户里。那个从A开始转帐，到转帐结束的这一个过程，称之为一个事务。在这个事务里，要做如下操作：

 1. 从A的帐户中减去1000块钱。如果A的帐户原来有3000块钱，现在就变成2000块钱了。
 2. 在B的帐户里加1000块钱。如果B的帐户如果原来有2000块钱，现在则变成3000块钱了。
如果在A的帐户已经减去了1000块钱的时候，忽然发生了意外，比如停电什么的，导致转帐事务意外终止了，而此时B的帐户里还没有增加1000块钱。那么，我们称这个操作失败了，要进行回滚。回滚就是回到事务开始之前的状态，也就是回到A的帐户还没减1000块的状态，B的帐户的原来的状态。此时A的帐户仍然有3000块，B的帐户仍然有2000块。

我们把这种要么一起成功（A帐户成功减少1000，同时B帐户成功增加1000），要么一起失败（A帐户回到原来状态，B帐户也回到原来状态）的操作叫原子性操作。

如果把一个事务可看作是一个程序,它要么完整的被执行,要么完全不执行。这种特性就叫原子性。

### Redis 的启动

```
$ cp redis-server /usr/local/bin/
$ cp redis-cli /usr/local/bin/
$ redis-server
$ redis-cli
```

### Redis 数据类型

Redis中，value不仅仅支持字符串，还支持更多的复杂结构，包括列表，集合，哈希表等，Redis keys是采用二进制安全。

#### Strings

Redis 字符串是二进制安全的，这意味着一个 Redis 字符串能包含任意类型的数据，例如 一张 jpeg 格式的图片或一个序列化的 Ruby 对象；

```
> set mykey somevalue
> get mykey
# set 命令将取代现有的任何存在的 key，可通过添加参数让 set 在没有相同 key 情况下成功
> set mykey newval nx
(nil)
> set mykey newval xx
OK
```

字符串也可以进行计算
```
> set counter 100
> incr counter
> incrby counter 50
```

Redis 可使用 mset and mget 一次性完成多个 key-value 的对应关系，使用 mget 返回一个 value 数组
```
> mset a 10 b 20 c 30
> mget a b c
```

#### Lists

Redis 列表是简单的字符串列表，可使用 lpush 命令在头部插入一个新元素，rpush 命令在尾部插入新元素，lrange list_name start_index end_index 展示 list 数据；

```
> rpush mylist A
> rpush mylist B C D 1 2 3 "foo bar"
> lpush mylist first
> lrange mylist 0 -1
```

```
# POP 取出 list 元素
> del mylist
> rpop mylist
> lpop mylist
```

#### Hashes

Redis Hashes 是字符串字段和字符串值之间的映射；

```
> hmset user:1000 username hello birthyear 1977
> hget user:1000 username
> hgetall user:1000
> hmget user:1000 username birthyear
```

#### Set 无序集合

Redis Set 是一个无序的字符串集合，具有不允许包含相同成员的属性；

Redis 集合支持集合运算，如进行并集、交集等

```
# 创建一个无序集合
> sadd myset 1 2 3
# 查看集合
> smembers myset
# 查看集合是否存在，匹配成功返回 1 ，否则返回 0
> sismember myset 3
```

#### 有序集合

有序集合的每个成员都关联一个评分，这个评分用来按照由低到高方式排序成员；

因为元素是有序的, 所以你也可以很快的根据评分（score）或者次序（position）来获取一个范围的元素。访问有序集合的中间元素也是非常快的,因此你能够使用有序集合作为一个没有重复成员的智能列表。在有序集合中，你可以很快捷的访问一切你需要的东西：有序的元素，快速的存在性测试，快速访问集合的中间元素！ 简而言之使用有序集合你可以做完成许多对性能有极端要求的任务，而那些任务使用其他类型的数据库真的是很难完成的。

```
# zadd 在元素之前多一个参数用于排序
> zadd hackers 1940 'Alan Kay'
> zadd hackers 1957 'Sophie Wilson'
# 查询集合，按正序
> zrange hackers 0 -1 withscores
# 查看集合，按反序
> zrevrange hackers 0 -1
```

---

### Redis 系统管理

#### 适用全体类型的常用命令

```
# 判断 key 是否存在
> set mykey hello
> exists mykey
# 删除 key
> del mykey
# 返回 key 的数据类型
> type mylist
# 返回匹配的 key 列表
> keys my*
# 随机获取一个已存在的 key
> randomkey
# 重命名 key，rename or renamenx
> rename mylist newlist
# 返回当前数据库 key 的总数
> dbsize
# help，帮助命令
> help set
```

#### 时间相关命令

```
# 限定 key 生存时间，对于临时存储有用
> set mykey hello
> expire mykey 10
> get key
# after 10s
> get key
(nil)
# 查询 key 剩余生存时间
> set mykey hello ex 30
> ttl key
# 清除当前数据库的所有 key
> flushdb
# 清除所有数据库中的所有 key
```

#### 设置相关命令

```
# config get 读取 Redis 服务器的配置参数
# config set 设置配置参数
> config get requirepass
> config set requirepass 123456
> config get requriepass (noauth)
> auth 123456
> config get reuiqrepass
```

##### 查询信息

```
# info 命令
> info server
> info memory 存储占用相关信息
> info all
> info default
```

----

### Redis 高级应用

#### 安全性设置

设置密码方式两种：

（1） 使用config set 命令的requirepass 参数，具体格式为config set requirepass “password”。

（2） 配置redis.conf 中设置requirepass属性，后面为密码。

输入认证的方式也有两种：

（1） 登录时可以 redis-cli -a password

（2）登录后使用 auth password

#### 主从复制

#### 事务处理
Redis的事务处理比较简单。只能保证client发起的事务中的命令可以连续的执行，而且不会插入其他的client命令，当一个client在连接中发出multi命令时，这个连接就进入一个事务的上下文，该连接后续的命令不会执行，而是存放到一个队列中，当执行exec命令时，redis会顺序的执行队列中的所有命令。如果其中执行出现错误，执行正确的不会回滚，不同于关系型数据库的事务。

#### 持久化机制
Redis是一个支持持久化的内存数据库，Redis需要经常将内存中的数据同步到磁盘来保证持久化。

Redis 支持两种持久化方式
1. snapshotting，将数据存放到文件，默认方式。

是将内存中的数据已快照的方式写入到二进制文件中，默认文件dump.rdb，可以通过配置设置自动做快照持久化的方式。可配置Redis在n秒内如果超过m个key被修改就自动保存快照。

save 900 1 #900秒内如果超过1个key被修改，则发起快照保存

save 300 10 #300秒内如果超过10个key被修改，则快照保存

2、 Append-only file（缩写为aof），将读写操作存放到文件中。

由于快照方式在一定间隔时间做一次，所以如果Redis意外down掉的话，就会丢失最后一次快照后的所有修改。

aof比快照方式有更好的持久化性，是由于使用aof时，redis会将每一个收到的写命令都通过write函数写入到文件中当redis启动时会通过重新执行文件中保存的写命令来在内存中重新建立整个数据库的内容。

由于os会在内核中缓存write做的修改，所以可能不是立即写到磁盘上，这样aof方式的持久化也还是有可能会丢失一部分数据。可以通过配置文件告诉redis我们想要通过fsync函数强制os写入到磁盘的时机。

配置文件中的可配置参数：

```
appendonly   yes     //启用aof持久化方式

#appendfsync  always //收到写命令就立即写入磁盘，最慢，但是保证了数据的完整持久化

appendfsync   everysec  //每秒中写入磁盘一次，在性能和持久化方面做了很好的折中

#appendfsync  no     //完全依赖os，性能最好，持久化没有保证
```

```
> help save

>save
```

#### 虚拟内存的使用
Redis的虚拟内存是暂时把不经常访问的数据从内存交换到磁盘中，从而腾出内存空间用于其他的访问数据，尤其对于redis这样的内存数据库，内存总是不够用的。除了分隔到多个redis server外，提高数据库的容量的方法就是使用虚拟内存，把那些不常访问的数据交换到磁盘上。

通过配置vm相关的redis.config配置：

```
vm-enable  yes                   #开启vm功能
vm-swap-file    /tmp/redis.swap  #交换出来的value保存的文件路径
vm-max-memory    10000000        #redis使用的最大内存上限
vm-page-size   32       #每个页面的大小32字节
vm-pages     123217729    #最多使用多少个页面
vm-max-threads     4        #用于执行value对象换入的工作线程数量
```

#### 发布订阅

```
在实例中创建了订阅频道名为 redisChat:

redis 127.0.0.1:6379> SUBSCRIBE redisChat

Reading messages... (press Ctrl-C to quit)
1) "subscribe"
2) "redisChat"
3) (integer) 1

重新开启个 redis 客户端，然后在同一个频道 redisChat 发布两次消息，订阅者就能接收到消息。

redis 127.0.0.1:6379> PUBLISH redisChat "Redis is a great caching technique"

(integer) 1

redis 127.0.0.1:6379> PUBLISH redisChat "Learn redis

(integer) 1

# 订阅者的客户端会显示如下消息
1) "message"
2) "redisChat"
3) "Redis is a great caching technique"
1) "message"
2) "redisChat"
3) "Learn redis"
```