## 目录

- 数据库
- SQL
- MySQL

---

### 数据库和 SQL

#### 数据库
数据库（Database）是按照数据结构来组织、存储和管理数据的仓库；

#### SQL

结构化查询语言(Structured Query Language)简称 SQL，用于对数据库进行操作的语言；

#### MySQL

MySQL 是一个 DBMS（数据库管理系统）是最流行的关系型数据库管理系统（关系数据库，是建立在关系数据库模型基础上的数据库，借助于集合代数等概念和方法来处理数据库中的数据）。

##### 基本命令

- 服务启动

不同版本下的 MySQL 启动命令会有不同
```
$ mysql.server start
```

- 用户登录

```
$ mysql -u root -p
# 输入密码
Enter password:
```

- 新建数据库和数据表

创建数据库

```
$ create database demo;
```

连接数据库

```
$ use demo'
```

查看数据表
数据表（table）简称表，它是数据库最重要的组成部分之一。

而一个数据库中一般会有多张表，这些各自独立的表通过建立关系被联接起来，才成为可以交叉查阅、一目了然的数据库。

eg:
```
ID	name	phone
01	Tom	110110110
02	Jack	119119119
03	Rose	114114114
```

```
$ show tablses;
```

新建数据表

```
$ create table book(id int(10), name char(20), author char(20));

mysql> create table author
    -> (
    ->  name char(20),
    ->  age int(20)
    -> );
```

数据类型

MySQL 常用数据类型

```
数据类型	大小(字节)	用途	格式
INT	4	整数	
FLOAT	4	单精度浮点数	
DOUBLE	8	双精度浮点数	
ENUM		单选,比如性别	ENUM('a','b','c')
SET		多选	SET('1','2','3')
DATE	3	日期	YYYY-MM-DD
TIME	3	时间点或持续时间	HH:MM:SS
YEAR	1	年份值	YYYY
CHAR	0~255	定长字符串	
VARCHAR	0~255	变长字符串	
TEXT	0~65535	长文本数据	
```
* char 和 varchar 的区别

char 的长度是固定的，varchar 则是变化的；
比如，存储字符 'abc'，char(10) 表示存储字符占据 10 个字节（包括 7 个 空字符），而 varchar(12) 则占用 4 个字节，增加一个额外字节存储字符串本身长度，12 是最大字节数；

查看数据

```
mysql> select * from book;
```

插入数据

```
mysql> insert into book(id, name, author) values(01, 'SPIC', 'Tom');
```

- 登出
```
mysql> quit;
mysql> exit;
```

- SQL 的约束
约束是一种限制，它通过对表的行或列的数据做出限制，来确保表的数据的完整性、唯一性。


