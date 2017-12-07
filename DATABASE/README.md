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

更新数据

```
mysql> update book set name='cook' where id = 1;
```

- 登出
```
mysql> quit;
mysql> exit;
```

- SQL 的约束
约束是一种限制，它通过对表的行或列的数据做出限制，来确保表的数据的完整性、唯一性。

在MySQL中，通常有这几种约束：

```
约束类型：	主键	默认值	唯一	外键	非空
关键字：	PRIMARY KEY	DEFAULT	UNIQUE	FOREIGN KEY	NOT NULL
```

主键 (PRIMARY KEY)是用于约束表中的一行，作为这一行的唯一标识符，在一张表中通过主键就能准确定位到一行

主键不能有重复且不能为空。

```
# 主键
mysql> create table employee(id int(10) primary key); 
# 自定义主键
mysql> create table department(dpt_name char(20) not null,constraint dpt_pk primary key(dpt_name))
# 复合主键
mysql> create table department(constraint proj_pk primary key(proj_num, proj_name));
```

默认值约束 (DEFAULT) 规定，当有 DEFAULT 约束的列，插入数据为空时，将使用默认值。

UNOQUE 规定一张表中指定的一列的值必须不能有重复值，即这一列每个值都是唯一的。

外键 (FOREIGN KEY) 既能确保数据完整性，也能表现表之间的关系。

一个表可以有多个外键，每个外键必须 REFERENCES (参考) 另一个表的主键，被外键约束的列，取值必须在它参考的列中有对应值。


```
mysql> drop database demo;
```

加载外部 sql 文件

```
mysql> source path/to/demo.sql;
```

删除数据库

```
mysql> drop database demo;
```

删除数据表

```
mysql> drop table book;
```

---

##### SELECT 语句

```
mysql> select col_ame from table_name where condition;
```


```
# > < >= <= =
mysql> select name, age from employee where age > 25;
```

```
# and or (between and, 包括收尾数字)
mysql> select name, age from employee where age > 25 and name != 'Jim' 
mysql> select name, age from employee where age between 25 and 30;
```

```
# in not in
mysql> select name, age, phone, in_dpt from employee where in_dpt in('dpt3', 'dpt4');
```

```
# like 常和通配符一起使用，其中 _ 代表一个未指定字符，% 代表不定个未指定字符；
mysql> select name, age from employee where phone like '1101__';
```

```
# 对结果排序，order by asc/desc
mysql> select name, age, salary from employee order by salary desc;
```

```
# SQL 内置函数和计算
函数名：	COUNT	SUM	AVG	MAX	MIN
作用：	计数	求和	求平均值	最大值	最小值

mysql> select max(salary) as max_salary, min(salary) from employee;
```

```
# 子查询，查询里面包含查询
mysql>  select of_dpt, count(proj_name) as count_project from project where of_dpt in (select in_dpt from employee where name='Tom');
```

```
# 连接查询，如果需要显示两个以上表的数据，需要使用 join 操作；
mysql> select id, name, people_num from employee, department where employee.in_dpt = department.dpt_name order by id;
mysql> select id, name, people_num from employee join department on employee.in_dpt = department.dpt_name order by id;
```
