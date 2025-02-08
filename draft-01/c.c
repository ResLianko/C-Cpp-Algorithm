//Chapter 1

#include <stdio.h>

#include <math.h>

int main()
{
//helloworld

    printf("Hello World!");
    


//\n换行与转义字符

printf("Hello World!");//打印格式化的字符串
printf("Hello World!\n");//引号内\n，换行，类似Golang中的fmt.Println，但是\n是单独作用的
printf("Hello World!\n");

printf("Hello World!\\n");
printf("Hello World!\\n\n");



//Calculation

printf("%d\n", 1 + 1);//%d表示输出整数，勿写反为d percent
printf("1 + 1 = %d\n", 1 + 1);

printf("%d\n", 12 % 2);
printf("%d\n", 11 % 2);//q%p 模p取余



//var 变量

int price = 0;//赋初值地声明变量（变量定义同时赋值，即初始化）；变量保存数据

printf("price=%d\n",price);

int price01;

int herAge;//不带初值地声明变量；这里采用了小驼峰命名

int price02, price03;

price01 = 9; price02 = 8; price03 = 7; herAge = 16;

int price04 = 0, price05 = 1;

printf("%d %d %d %d %d %d\n", price01, price02, price03, price04, price05, herAge);//test

int amount = price01 + price02;

printf("%d\n",amount);

/*ATTENTION：命名规则
1 只由数字，字母，下划线组成
2 不得以数字开头
3 不得使用C的关键字
*/

//scanf, printf, f := formated
//我们利用scanf函数实现输入

int sq = 0;
printf("请输入要作平方的数字：");
scanf("%d", &sq);//注意and符的使用，参见指针部分
printf("其平方为：%d\n", sq*sq);

int a, b;
printf("请输入要求和的两数：");
scanf("%d %d", &a, &b);
printf("%d + %d = %d\n", a, b, a + b);

//若在sq位置上输入非int类型的内容，譬如abc，则其将被默认为0，参与后续过程；而scanf输入，类似错误则会导向与内存相关的一个怪异的值
//%lf 浮点数
//scanf有一定的规则，（）中有何者，程序就希望读到何者，亦即需要输入何者



//constant 常量

const int EEE = 3;//注意空格规范（其往往不影响执行，但关乎美观）

printf("%d\n", EEE);

//若直接写入数值，而非如上先定义，则称直接量(literal(:字面的))
//先定义是推荐的做法
//constant不可被修改，且一般全大写

//%f代表单精度浮点数（float)，占32位
//%lf代表双精度浮点数（double），占64位

//与数学上不同，计算机认为，整数（类型）运算结果必是整数，例如

int a1 = 10, a2 = 3;
printf("%d\n", a1 / a2);//3

int a3 = 5, a4 = 2;
printf("%d\n", a3 / a4);//2

//注意结果不是四舍五入而来，而是去除小数部分而来

//试试负数情形
int a5 = -5, a6 = 2;
printf("%d\n", a5/a6);

//若将%d换为%f，仍无法得到基本正确的结果，而是得到某种不合法引起的病态的结果，可能是0.000000

//考虑

printf("%d\n", 10/3);//3 false

printf("%f\n", 10.0/3);//3.333333 true

//浮点数与整数同时参与运算，C会将int转化为float，再进行f运算

//浮点数输入必须用%lf，输出可用%f

//另一个方案是定义时就用double

double a7 = 10, a8 = 3;
printf("%f\n", a7/a8);

//一些实验
printf("%.1f\n", 8.0/5.0);
printf("%.2f\n", 8.0/5.0);
printf("%f\n", 8.0/5.0);
printf("%.1f\n", 8/5);//problem
printf("%d\n", 8.0/5.0);//p...m

//一些实验（被注释掉了）

/*
printf("%d\n", 11111*11111);
printf("%d\n", 111111*111111);//integer overflow(整数溢出)
printf("%d\n", 111111111*111111111);//同上

printf("%f\n", 11111.0*11111.0);
printf("%f\n", 111111.0*111111.0);
printf("%f\n", 111111111.0*111111111.0);//success
printf("%f\n", 1111111111111111111.0*1111111111111111111.0);//p...m

printf("%f\n", sqrt(-10));pm
printf("%f\n", 1.0/0.0);//same
printf("%f\n", 0.0/0.0);//same
printf("%d\n", 1/0);//报错
*/

//printf中占位符必须与变量类型保持一致，float变量用%d输出，不是取整，而是根本不能正确输出
float fff = 1.23456;
printf("%d\n", fff);//0

printf("love\nyou\n");

//输出"%d"
printf("%%d\n");

//printf("%d\n");是不行的

//试试取商取余
int t = 70;
printf("%d小时%d分钟\n", t/60, t%60);

//运算符优先级：单目 高于 乘除取余 高于 加减 高于 赋值
//单目：a乘b，a乘负b，记：a*+b, a*-b
//一般自左向右计算
//=自右向左结合，a=b=m即a=(b=m)，单目也是自右向左结合
//勿作复杂的，歧义的，嵌入的表达

//双变量值交换：引入新变量

int aa = 1;
int bb = 0;
int tt;
printf("%d %d\n", aa, bb);

tt = aa;//用t存储a
aa = bb;//a的值已被保管，a可以被覆盖，a=原b（将b值赋给a）
bb = tt;//b=原a

printf("%d %d\n", aa, bb);

//复合赋值
//a += k, 即a = a+k   a *= p+q, 即a = a*(p+q)
//a++, 即a = a+1;a--, 即a = a-1 这两个算符是单目的
//a++和++a的效果都是令a的值+1，但a++是a加一之前的值，而++a则是a加一以后的值

//正3位数逆序（尾0要除去）

int sws, sws01;
printf("请输入要逆序的正三位数：");
scanf("%d", &sws);
int bai, shi, ge;
    bai = sws/100;
    shi = (sws-bai*100)/10;
    ge = (sws-bai*100-shi*10);//模10取余更简便，即sws%10
sws01 = bai+shi*10+ge*100;
printf("逆序结果为：%d\n", sws01);

//0x是十六进制数的前缀，表示其后的数是十六进制的
//10进制转16进制，可用除（以）16取余法，也可采取如下简便方法
printf("%x\n", 255);
printf("%x\n", 4660);

//0字体的斜线设计是为了与大O区分



//if 条件判断

//下面我们利用if语句实现符号函数（但并未定义计科意义上的函数）

double x;

printf("请输入sgn(x)的自变量：");

scanf("%lf", &x);

if (x>0) {
    printf("sgn(x) = 1\n");
} else if (x==0) {
    printf("sgn(x) = 0\n");
} else {
    printf("sgn(x) = -1\n");
}

//C没有elif关键字，Python里是有的
//简单情形下，if可以不结合else而单独使用

//无大括号的写法

double y;

printf("请输入sgn(y)的自变量：");

scanf("%lf", &y);

if (y>0)
    printf("sgn(y) = 1\n");
else if (y==0)
    printf("sgn(y) = 0\n");
else
    printf("sgn(y) = -1\n");

//一个条件下要执行多条语句时，不得使用无大括号的写法

//if的嵌套 e.g.三数取最大值

printf("Please enter three real numbers. ");

double p1, p2, p3;

scanf("%lf %lf %lf", &p1, &p2, &p3);

double max;

if (p1>=p2) {
    if (p1>=p3) {
        max = p1;
    } else {
        max = p3;
    }
} else {
    if (p2>=p3) {
        max = p2;
    } else {
        max = p3;
    }
}

printf("The max is %lf\n", max);

/*简化一下这个程序的核心部分
    max = p1;  
    if (p2 > max) max = p2;  
    if (p3 > max) max = p3;
*/

//关系判断
//> < ==（非“=”） >= <= !=（不等于）
//关系运算符的结果是1或0，成立为1，不成立为0，这一点完全可以用printf来验证

printf("%d\n", 1==2);//0

//关系运算符的优先级低于加减乘除，高于赋值（=）
//=和!=的优先级低于><，这就允许我们写出5>3==6>4,判断两个真值的相等性
//6>5>4，自左向右结合，即0
//a==b==c，亦自左向右结合，依次计算

//\pi常数的表示
const double pi = acos(-1.0);
printf("%lf\n", pi);

/*
++x&&++y||++z
我们允许这样的语句单独成句，并强调
1.&&优先级高于||
2.&&，LHS为0时短路   ||，LHS为1时短路
*/

//关于 a = ++a+a+++a++
/*
首先，其结构是清晰的
a = ++a + a++ + a++
其次，我们指出，尽管+的运算是从左向右结合的，上式的运算顺序并不确定
上式是UB，应该避免写出，而非讨论结果
*/

//Single-character input and put (getchar / putchar)

char ch;
ch = getchar();
putchar(ch);

putchar('\n');//单独输出空行
putchar(65);//A    (ASCII)
putchar(48);//0
printf("%c\n", 65);
printf("%c\n", 'B');



//Appendix:some scattered knowledge points

//i = i++ is UB

//重要的ASCII码
/*
SP    32                                  SP  32              //space
'0'    48                                 0   48
    '2'    50//48+(2-0)
    '9'    57//48+9=57
'A'    65                                 A   65
    'Z'    90//65+25=90=65+(26-1)
'a'    97                                 a   97
    'z'    122//97+25
*/

/*NUL~0*/

//C是强类型语言

//variable name(变量名)
/*
是identifier(标识符)的一种，要求
只由(大小写敏感的)英文字母a~z A~Z，数字0~9，下划线_组成
不得数字开头
不得使用关键字(保留字)
可包含任意数量的字符，但只有前31个有意义(对于C编译器而言)
*/
//不建议命为main def之类 Main可以   decimal不存在于C中

//1Byte=8bit 1字节=8位
//sizeof操作符返回类型或变量或表达式在内存中占用的字节数
printf("%d\n", sizeof(int));//4
printf("%d\n", sizeof(long));//4
printf("%d\n", sizeof(long long));//8

//无符号整型
unsigned int v1;//%u
unsigned long int v2;//%lu

//%g 有时用于去除不必要的0
double myDb = 1.5;
printf("%f", myDb);//1.500000(%f可以认为一般默认保留小数点后6位)
printf("%g", myDb);//1.5

//用%d输出char，输出ASCII码
printf("%d", 'A');//65

//null /nAl/

//C中不可写0<x<=100，应用&&

//\n 换行 \t TAB \f 换页 \r 回车

printf("test1\n");
printf("1");
printf("\n");//真正换行，新起一行
printf("1");

printf("\n\n");

printf("test1\n");
printf("1");
printf("\r");//返回当前行的开头
printf("1");

/*
test1
1
1

test1
1
*/

//浮点型一般不直接判等，而是看差值是否充分小，如小于1e-9

//width and precision 域宽与精度
//%5.2f
//域宽5四舍五入保留小数点后2位，右对齐
//若要左对齐，%-5.2f
//一个数字or一个小数点or一个负号 占一个宽度
//本身宽超出域宽时，域宽失效，按本身原样输出

//%s string %o 八进制 %x 十六进制

//&取地址运算符 %p输出地址 首字节地址作地址 见后

//j+++j 一般视为UB 若强行考察，视为(j++)+j
/*int j = 5;
printf("%d\n", j+++j);//11*/


//char可以参与运算，视为ASCII，如下
printf("%d", 100 - 'A' / 5);//87

//小写字母转大写字母

char dx;
scanf("%c", &dx);
dx = (dx>='a' && dx<='z') ? (dx - ('a' - 'A')) : dx;
putchar(dx);

//for 的等价改写

for (int t1 = 1;t1<=10;t1++) {
    printf("%d", t1);
}

int t2 = 1;
for (;;) {
    if (t2>10) break;
    printf("%d", t2);
    t2++;
}

//输入整数，输出位数

int numint, nnn = 0;//注意，这里并没有为numint赋初值
scanf("%d", &numint);
numint = numint>0 ? numint : -numint;
for (;numint != 0;) {
    nnn++;
    numint/=10;
}
printf("%d\n", nnn);

//上面是认为0不是1位数的写法，若认为是，考虑如下

/*int numint, nnn = 0;
scanf("%d", &numint);
numint = numint>0 ? numint : -numint;
if (numint == 0) {
    printf("1\n");
} else {
    for (;numint != 0;) {
    nnn++;
    numint/=10;
}
printf("%d\n", nnn);
}*/

//认为不是的前提下，考虑用对数(in math.h)
//log(double x)是自然对数，相当于ln(x)
//log10(double x)是常用对数，相当于lg(x)

int numint2;
scanf("%d", &numint2);
printf("%d\n", (int)(log10((double)(fabs(numint2)))) + 1);

//Codeforces watermelon
int w;
scanf("%d", &w);
if (w%2==0 && w != 2) {
    printf("YES");
} else {
    printf("NO");
}
//注意这不是简单的奇偶判断 2不能被拆成2个正偶数

//该例可以先跳过（凑字数用的一个例题）
//一种循环输入和递推手法级数求和
int n;
double x8;

for(;scanf("%d%lf", &n, &x8)!=EOF;)//EOF（end of file）可ctrl + Z~Enter结束输入
{
double item = -1, sum = 0;
for (int i = 1; i<=n; i++)
{
item = -item*x8/i;
sum += item;
}

printf("sum = %lf\n", sum);
}

//混合形式地声明变量
int x9, n9 = 0, min9, max9, s9 = 0;
printf("%d", x9);
//尽管打印出了0，也不能证明x9被初始化或默认初始化为了0
//x9事实上并没有被赋初值

//%3d 域宽3，右对齐，补空格    %03d 域宽3，右对齐，补0
/*
int p = 23;
printf("%3d\n", p);     // 23
printf("%03d\n", p);    //023
*/
return 0;
}