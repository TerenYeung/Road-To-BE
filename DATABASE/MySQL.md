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

如果你忘记了表格字段的数据类型，可用

```
mysql> describe book;
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

```
# 增加关键字 distinct 可检索出每条唯一输出记录
```

分组查询

```
# 查出 owner 中的宠物数
mysql> select owner, count(*) from pet group by owner;
```

联表查询

```
# pet table and event table
# 查询当宠物生孩子时的年龄
mysql> 
```

获取当前激活的数据库

```
mysql> show database();
```

```
# 当需要退出 SQL 语句时，输入 \c 取消它；
mysql> select
    -> user()
    -> ,
    ->
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

---

##### 数据库及表的修改和删除

- 重命名一张表

```
mysql> rename table old_name to new_name;
``

- 删除一张表

```
mysql> drop table table_name;
```

- 对一列的修改

```
# 增加一列
mysq> alter table employee add height int(4) default 170 [after col_name] || first;

mysql> alter table employee add weight int(4) default 120 after before height;

mysql> 
```
# 删除一列

```
mysql> alter table employee drop test;
```

# 重命名一列
```
mysql> alter table employee change height shengao int(4) default 170;
```

# 修改表内容

```
mysql> update employee set age = 21, salary = 3000 where name = 'Tom';
```

# 删除一行记录
```
mysql> delete from employee where name = 'Tom';
```

---

##### 数据库其他操作：索引、视图、导入、导出、备份和恢复

- 索引 ?
当表中有大量记录时，若要对表进行查询，没有索引的情况是全表搜索：将所有记录一一取出，和查询条件进行一一对比，然后返回满足条件的记录。这样做会消耗大量数据库系统时间，并造成大量磁盘 I/O 操作。

而如果在表中已建立索引，在索引中找到符合查询条件的索引值，通过索引值就可以快速找到表中的数据，可以大大加快查询速度。

索引可以分为单列索引和组合索引，单列索引，即一个索引只包含单个列。组合索引，即一个索引包含多个列。

虽然索引大大提高了查询速度，同时却会降低更新表的速度，如对表进行INSERT、UPDATE和DELETE。因为更新表时，MySQL不仅要保存数据，还要保存一下索引文件。

建立索引会占用磁盘空间的索引文件。

```
# 创建索引
mysql> create index idx_name on employee(name);
# 删除索引
mysql> drop index idx_name on employee;
# 显示表的索引
mysql> show index from employee;
```

- 视图
视图是从一个或多个表中导出来的表，是一种虚拟存在的表。

数据库中只存放了视图的定义，而没有存放视图中的数据，这些数据存放在原来的表中；

视图中的数据依赖于原来表中的数据，一旦表中数据发生改变，显示在视图中的数据也会发生改变

```
# 创建视图
mysql> create view v_emp(v_name, v_age, v_phone) as select name, age, phone from employee;
mysql> select * from v_emp;
# 删除视图
mysql> drop view v_emp;
```

- 导入
将文件中的数据导入一张表

```
mysql> load data infile 'path/to/file' into table employee;
```

- 导出

```
# 导出数据
mysql> select * into outfile 'path/to/file' from employee;
```

- 备份

```
$ mysqldump -u root databse_name > bak_name;
$ mysqldump -u root database_name table_name > bak_name;
$ mysqldump -u root -p mysql_shiyan > bak.sql;
```

- 恢复

```
mysql> source /path/to/demo.sql
```

---

关于 null

任何变量和 null 使用运算符比较都是 null；

因此，判断一个数是不是 null，使用 is null or is not null；

---

模式匹配

```
mysql> select * from pet where name like 'b%';
mysql> select * from pet where name like '_____';
mysql> select * from pet where name regexp '^b';

```



---

常用查询

```
# 寻找列最大值
mysql> select max(price) as price from shop;
# 按价格降序查询并显示前 3 条记录
mysql> select * from shop order by price limit 3;
# 使用用户变量
mysql> SET @var_name := expr [, @var_name := expr] ...
mysql> select @min_price:=min(price), @max_price:=max(price) from shop;
mysql> select * from shop where price = @min_price or price = @max_price; 
# 使用外键 ？
# UNION 联合查询
mysql> select * from shop where dealer = 'D' union select * from shop where price > 15; 
```
> MySQL用户变量：基于会话变量实现的，可以暂存值，并传递给同一连接里的下一条sql使用的变量，当客户端连接退出时，变量会被释放。

MySQL用户变量应用场景：同一连接，未关闭情况下，帮你暂存一些计算结果。
---

##### 基本函数和操作符

- 日期函数
```
mysql> select name, birth, curdate(), timestampdiff(year(curdate)-year(birth)) as age from pet;
```

```
mysql> select name, birth from pet where month(birth) = month(date_add(curdate(), interval 1 month));
```

---

### MySQL 语言结构

---

### MySQL 触发器

触发器是与表有关的固定的数据库对象，当表上出席那特定事件时，将激活该对象；

```
# 创建 Trigger
# create trigger trigger_name before|after(触发时机) insert|update|delete(激活触发程序的事件) for each row
mysql> create trigger ins_sum before insert on account for each row set @sum = @sum + new.amount;
# 销毁 Trigger
mysql> drop trigger database.ins_sum; 
```

使用 old 和 new 关键字，能够访问受触发程序影响的行中的列。

在 insert 触发程序中，仅能使用 new.col_name；
在 delete 触发程序中，仅能使用 old.col_name;
在 update 触发程序中，既能使用 old 又能使用 new;

---

### MySQL View

---

### MySQL 数据库管理

#### 权限管理

#### 用户管理

```
# 创建用户
mysql> GRANT ALL PRIVILEGES ON *.* TO 'monty'@'localhost'
    ->     IDENTIFIED BY 'some_pass' WITH GRANT OPTION;

mysql> GRANT ALL PRIVILEGES ON *.* TO 'monty'@'%'
    ->     IDENTIFIED BY 'some_pass' WITH GRANT OPTION;

mysql> GRANT RELOAD,PROCESS ON *.* TO 'admin'@'localhost';

mysql> GRANT USAGE ON *.* TO 'dummy'@'localhost';
```


