# Chapter 1 程序的基本概念
## 1.1 程序和编程语言
1、解释执行的语言相比编译执行的语言有什么优缺点？

首先，二者都是将高级语言最终转换成机器码，差别在于转换时机。编译型语言在执行前，将代码翻译成特定平台（架构）的机器码，而解释型则在执行时逐条翻译。在执行效率上，编译型通常显著优于解释型，因为已生成机器码，可由硬件直接执行。在平台相关性上，解释型则无关（最终依靠相应解释器），编译型强相关。

## 1.2 自然语言和形式语言

## 1.3 程序的调试

## 1.4 第一个程序

# Chapter 2 常量、变量和表达式

## 2.1 继续Hello World

## 2.2 常量
`2.2-test.c`如下：
```
#include<stdio.h>

int main() {
    printf("test: \%. \n"); // wrong
    printf("test: %%. \n"); // right

    return 0;
}
```
运行结果如下：

```
zhaozy@PC:~/Desktop/ysyx-version7/Phase E/E1$ gcc 2.2-test.c -o 2.2-test
2.2-test.c: In function ‘main’:
2.2-test.c:4:22: warning: unknown conversion type character ‘ ’ in format [-Wformat=]
    4 |     printf("test: \%. \n"); // wrong
      |                      ^
zhaozy@PC:~/Desktop/ysyx-version7/Phase E/E1$ ./2.2-test 
test: %.0 
test: %. 
```
解释如下： 

* \ 是转义字符，只对特定字符生效：\n \t \\ \" 等
* \% 不是合法转义序列！C 语言不认识它
* 编译器会忽略无效的 \，把 \% 当成 %

`test: %.0 `解释：

GCC 遇到不合法的 %. 时，会做一个兼容处理：把不合法的格式符 默认当成 % f（浮点数），但因为没有提供浮点数，就用 0.0 填充。
所以：
```
printf("test: \%. \n"); // wrong
```
会被处理成：
```
printf("test: %.0f \n", 0.0);
```
所以输出为：`test: %.0`.

## 2.3 变量

## 2.4 赋值
初始化是一种特殊的声明，而不是一种赋值语句。

有些东西只能初始化，不能赋值。这些是硬性规则，没商量：

    const 变量
    引用 &
    数组整体赋值
    没有默认构造函数的对象

它们生下来就必须有值，赋值根本做不到。在性能方面：少跑一次默认构造，直接一步到位
C++ 对象：

    初始化：直接调用目标构造函数 1 次
    赋值：
        先调用默认构造（浪费）
        再调用赋值运算符

初始化 = 少一次构造 + 少一次赋值开销。

## 2.5 表达式
### Question: 
假设变量x和n是两个正整数，我们知道x/n这个表达式的结果要取Floor，例如x是17，n是4，则结果是4。如果希望结果取Ceiling应该怎么写表达式呢？例如x是17，n是4，则结果是5；x是16，n是4，则结果是4。

Ans: 
```
Expr = (x + n - 1) / n;
```

## 2.6 字符类型与字符编码

| 转义序列 | 含义 | ASCII 十进制 | ASCII 十六进制 |
| -- | -- | -- | -- |
|\0	 | 空字符 NULL | 0 | 0x00 |
|\a	| 响铃 BEL | 7 | 0x07 |
|\b	| 退格 BS | 8 |	0x08 |
|\t	| 水平制表 HT | 9 | 0x09 |
|\n	| 换行 LF | 10 | 0x0A |
|\v	| 垂直制表 VT |	11 | 0x0B |
|\f	| 换页 FF |	12 | 0x0C |
|\r	| 回车 CR |	13 | 0x0D |
|'	| 单引号 | 39 |	0x27 |
|"	| 双引号 | 34 |	0x22 |
|?	| 问号 | 63	| 0x3F|
|\	| 反斜杠 | 92 |	0x5C |
|\e	| 转义 ESC （扩展）| 27	| 0x1B |

# Chapter 3 简单函数

## 3.1 数学函数

## 3.2 自定义函数
>！代码风格!

`void threeline();`

这个声明并没有明确指出参数类型和个数，所以不算函数原型，这个声明提供给编译器的信息只有函数名和返回值类型。如果在这样的声明之后调用函数，编译器不知道参数的类型和个数，就不会做语法检查，所以很容易引入Bug。读者需要了解这个知识点以便维护别人用Old Style C风格写的代码，但绝不应该按这种风格写新的代码。

## 3.3 形参和实参

### Man Page
| Section | 描述 |
| -- | -- |
1	| 用户命令，例如ls(1)
2	| 系统调用，例如_exit(2)
3	| 库函数，例如printf(3)
4	| 特殊文件，例如null(4)描述了设备文件/dev/null、/dev/zero的作用
5	| 系统配置文件的格式，例如passwd(5)描述了系统配置文件/etc/passwd的格式
6	| 游戏
7	| 其它杂项，例如bash-builtins(7)描述了bash的各种内建命令
8	| 系统管理命令，例如ifconfig(8)

Man Page中有些页面有重名，比如敲man printf命令看到的并不是C函数printf，而是位于第1个Section的系统命令printf，要查看位于第3个Section的printf函数应该敲man 3 printf，也可以敲man -k printf命令搜索哪些页面的主题包含printf关键字。

### Ques:
1.定义一个函数increment，它的作用是把传进来的参数加1。例如：
```
void increment(int x)
{
	x = x + 1;
}

int main(void)
{
	int i = 1, j = 2;
	increment(i); /* i now becomes 2 */
	increment(j); /* j now becomes 3 */
	return 0;
}
```
我们在main函数中调用increment增加变量i和j的值，这样能奏效吗？为什么？

Ans:
不奏效。函数执行完后，没有将值返回。

2.如果在一个程序中调用了printf函数却不包含头文件，例如int main(void) { printf("\n"); }，编译时会报警告：warning: incompatible implicit declaration of built-in function ‘printf’。请分析错误原因。

Ans：
没写 #include <stdio.h>，编译器不知道 printf 是什么，就自己瞎猜了一个声明（这就是`implicit declaration`），然后发现和真实的 printf 对不上（`imcompatible`），所以报：

    incompatible implicit declaration of built-in function ‘printf’

## 3.4 全局变量、局部变量和作用域
全局变量只能用常量表达式初始化，如果全局变量在定义时不初始化则初始值是0，如果局部变量在定义时不初始化则初始值是不确定的。

# Chapter 4 分支语句

## 4.1 if语句
__左结合__: 算数、关系、逻辑

__右结合__: 赋值、单目（++、--、!、~、&、*、+、-）、三目（？:）

### Ques：
1. 以下程序段编译能通过，执行也不出错，但是执行结果不正确（根据第 3 节 “程序的调试”的定义，这是一个语义错误），请分析一下哪里错了。还有，既然错了为什么编译能通过呢？
```
int x = -1;
if (x > 0);
	printf("x is positive.\n");
```

Ans:
此案例中的if分支的执行语句是空语句，所以无论x是否大于0，都会执行printf。

## 4.2 if/else 语句
### Ques:
1. 写两个表达式，分别取整型变量x的个位和十位。
```
    m = (x % 100) / 10;
    n = (x % 100) / 10;
```

## 4.3 布尔代数
### Ques：
1. 、把代码段
```
if (x > 0 && x < 10);
else
	printf("x is out of range.\n");
```
改写成下面这种形式：
```
if (____ || ____)
	printf("x is out of range.\n");
```
____应该怎么填？

Ans:

x <= 0 || x >= 10

2. 把代码段：
```
if (x > 0)
	printf("Test OK!\n");
else if (x <= 0 && y > 0)
	printf("Test OK!\n");
else
	printf("Test failed!\n");
```
改写成下面这种形式：
```
if (____ && ____)
	printf("Test failed!\n");
else
	printf("Test OK!\n");
```
____应该怎么填？

Ans:

```
x <= 0 && y <= 0
```

3. 有这样一段代码：
```
if (x > 1 && y != 1) {
	...
} else if (x < 1 && y != 1) {
	...
} else {
	...
}
```
要进入最后一个else，x和y需要满足条件____ || ____。这里应该怎么填？

Ans:
```
y == 1 || x == 1
```

4. 以下哪一个if判断条件是多余的可以去掉？这里所谓的“多余”是指，某种情况下如果本来应该打印Test OK!，去掉这个多余条件后仍然打印Test OK!，如果本来应该打印Test failed!，去掉这个多余条件后仍然打印Test failed!。
```
if (x<3 && y>3)
	printf("Test OK!\n");
else if (x>=3 && y>=3)
	printf("Test OK!\n");
else if (z>3 && x>=3)
	printf("Test OK!\n");
else if (z<=3 && y>=3)
	printf("Test OK!\n");
else
	printf("Test failed!\n");
```

Ans:

第一个和第二个合并，则有y>=3时 OK，那么第四个条件就没有意义了。

## 4.4 switch语句
* case后面跟表达式的必须是常量表达式，这个值和全局变量的初始值一样必须在编译时计算出来。

* “if/else语句”讲过浮点型不适合做精确比较，所以C语言规定case后面跟的必须是整型常量表达式。

有时候编译器会对switch语句做优化，使之比等价的if/else效率更高

# Chapter 5 深入理解函数
## 5.1 return语句

## 5.2 增量式开发

## 5.3 递归

# Chapter 6 循环语句

## 6.1 while语句

## 6.2 do/while循环

## 6.3 for循环

## 6.4 break和continue语句
### Ques:
1. 求素数这个程序只是为了说明break和continue的用法才这么写的，其实完全可以不用break和continue，请读者修改一下控制流程，去掉break和continue而保持功能不变。

原程序：
```
#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			break;
	if (i == n)
		return 1;
	else
		return 0;
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) {
		if (!is_prime(i))
			continue;
		printf("%d\n", i);
	}
	return 0;
}
```
修改后：
```
#include <stdio.h>

int is_prime(int n)
{
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			if (i == n)
				return 1;
			else
				return 0;
		}
	}
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) {
		if (is_prime(i))
			printf("%d\n", i);
			// continue;
	}
	return 0;
}
```

2. while循环有`continue`是有可能跳过increment，导致死循环的。

## 6.5 嵌套循环

## 6.6 goto语句和标号
goto能不用不用

# Chapter 7 结构体
## 7.1 复合类型与结构体

## 7.2 数据抽象
### Ques:
1. 打印算是复数运算层？

## 7.3 数据类型标志
###	Ques:
2. 编译运行下面这段程序：
```
#include <stdio.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void)
{
	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}
```
结果是什么？并解释一下为什么是这样的结果。

Ans:
```
zhaozy@PC:~/Desktop/ysyx-version7/Phase E/E1$ gcc -Wall ./7.3-ques2.c -o 7.3-ques2 
./7.3-ques2.c: In function ‘main’:
./7.3-ques2.c:8:9: warning: ‘RECTANGULAR’ is used uninitialized [-Wuninitialized]
    8 |         printf("%d %d\n", RECTANGULAR, POLAR);
      |         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
zhaozy@PC:~/Desktop/ysyx-version7/Phase E/E1$ ./7.3-ques2 
0 2
```
局部变量会遮蔽同名的全局标识符，包括枚举常量。这里`0`其实是栈上的随机值。

## 7.4 嵌套结构体

# Chapter 8 数组
## 8.1 数组的基本概念
**Memberwise Initialization** C99 
```
int count[4] = { [2] = 3 }; // 会将index为2的设置为3，其余为0
```

* 不能相互赋值和初始化
* 同理，不能将数组类型作为参数或者返回值，实际操作中数组作右值时，会转化为**指针**

## 8.2 数组应用实例：统计随机数
### Ques:
1、用rand函数生成[10, 20]之间的随机整数，表达式应该怎么写？

Ans: 
```
int x = rand() % 11 +10;
```

## 8.3 数组应用实例：直方图

## 8.4 字符串

## 8.5 多维数组
例 8.5. 剪刀石头布
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char gesture[3][10] = { "scissor", "stone", "cloth" };
	int man, computer, result, ret;

	srand(time(NULL));
	while (1) {
		computer = rand() % 3;
	  	printf("\nInput your gesture (0-scissor 1-stone 2-cloth):\n");
		ret = scanf("%d", &man);
	  	if (ret != 1 || man < 0 || man > 2) {
			printf("Invalid input! Please input 0, 1 or 2.\n");
			continue;
		}
		printf("Your gesture: %s\tComputer's gesture: %s\n", 
			gesture[man], gesture[computer]);

		result = (man - computer + 4) % 3 - 1;
		if (result > 0)
			printf("You win!\n");
		else if (result == 0)
			printf("Draw!\n");
		else
			printf("You lose!\n");
	}
	return 0;
}
```
留给读者思考的问题是：(man - computer + 4) % 3 - 1这个神奇的表达式是如何比较出0、1、2这三个数字在“剪刀石头布”意义上的大小的？

这确实是个很妙的实现，我从结果的角度解释一下。当人机出手相同，结果为零，认为平；当人胜机，则`man-computer+4`为2或者5，结果为1；当机胜人，`man-computer+4`为3或6，结果为-1。毫无疑问，肯定要模3，实际上，+4等同于+1，+1又可以与后面的-1抵消，所以判断可以改为
```
		if (result == 1 || result == -2)
			printf("You win!\n");
		else if (result == 0)
			printf("Draw!\n");
		else
			printf("You lose!\n");
```

# Chapter 9

