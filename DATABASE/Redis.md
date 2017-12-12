## Redis 简介

### Redis 是什么

REmote DIctionary Server(Redis) 是一个key-value存储系统；

REmote DIctionary Server(Redis) 是一个由Salvatore Sanfilippo写的key-value存储系统

### Redis 的优点

- 性能极高
- 丰富的数据类型
- 原子性：Redis 的所有操作都是原子性的
- 丰富的特性： Redis还支持 publish/subscribe, 通知, key 过期等等特性

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