//Chapter 2

#include <stdio.h>

#include <math.h>

#include <time.h>

#include <string.h>

#include <stdbool.h>

int main()
{
/*
为便于代码调试与变量命名，我们将注释掉相当一部分既验证的代码
*/

//exercises

//average

/*int a, b, c;
double ave;
scanf("%d%d%d", &a, &b, &c);
ave = ((double)a + (double)b + (double)c)/3;
printf("%.3f\n", ave);*/

//temperature

/*double f, c;
scanf("%lf", &f);
c = 5*(f - 32)/9;
printf("%.3f\n", c);*/

//sum 连续和

/*int n, sum;
scanf("%d", &n);
sum = n*(n+1)/2;
printf("%d\n", sum);*/

//sin&cos

/*int n;
double s, c, hd;
scanf("%d", &n);
hd = n*acos(-1.0)/180;
s = sin(hd);
c = cos(hd);
printf("%f %f", s, c);*/

//discount

/*int n;
double total;
scanf("%d", &n);
total = 95.0*n;
if (total>=300) {
    total = total*0.85;
}
printf("%.2f", total);*/

//triangle

/*int a, b, c;
scanf("%d%d%d", &a, &b, &c);
if (a+b>c&&b+c>a&&c+a>b) {
    if (a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
} else {
    printf("not a triangle\n");
}*/

//year

/*int year;
scanf("%d", &year);
if (year%100==0) {
    if (year%400==0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
} else {
    if (year%4==0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}*/

//取地址运算符实验

/*int a = 1;
printf("%p\n", &a);*/

/*float a = 1;
printf("%p\n", &a);*/



//for循环，while循环和do-while循环
//略，参见后续习题



//一些补充

//关于宽度
/*int i=234;
float x=-513.624;
printf("i=%5d x=%7.4f\n",i,x);【默认右对齐】【超宽度，则宽度失效，原样输出，保留位仍有效】【小数点，负号，分别占一位】*/

/*float alfa=60,pi=3.141592653589793;
printf("sin(%3.0f*%f/180)\n",alfa,pi);【%f一般默认小数点后六位】*/

/*char ch='$';
float x=153.45;
printf("%c%-8.2f\\n",ch,x);【'-'表示左对齐】*/

//一个失真的例子
/*float x = 256.81;
double pi = 3.1415926535;
printf("x=%f pi=%f\n",x,pi);【输出x=256.809998 pi=3.141593，但也可能是xxx256.800000xxx】*/

/*double x = 256.81;
double pi = 3.1415926535;
printf("x=%f pi=%f\n",x,pi);【这个结果是合理的】*/

//取绝对值
/*double a, z;
scanf("%lf", &a);
z = fabs(a);
printf("%f", z);*/
//省略000...
//1.5 1.5
//2.6 2.6
//-3.1 3.1

//取整，取整函数与负小数取整
/*double a;
int z,w;
scanf("%lf", &a);
z = floor(a);
printf("%d\n", z);*/
//1.6 1
//-2.5 -3
/*w = (int)a;
printf("%d", w);*/
//1.6 1
//-2.5 -2

//e.g.
/*float x=2.5,y=4.7; int a=7;
double s;
s = x+a%3*(int)(x+y)%2/4;//输出2.500000，说明第二项首先被视为整型间的运算，且int作用于(x+y)
printf("%lf", s);*/

/*
int a=1, b=2, c=3;

int d=0;

printf("%d", --a);//0
*/



//clock 计时函数

/*for(int i = 0;i<=1000;i++)
    printf("喵");
printf("\n");
printf("Time used = %.2f\n", (double)clock()/CLOCKS_PER_SEC);*/

//利用命令行避免输入时间的影响
/*int a;
scanf("%d", &a);
for(int i = 0;i<=1000;i++)
    printf("%d%d%d\n", a, a, a);
printf("Time used = %.2f\n", (double)clock()/CLOCKS_PER_SEC);
//命令行/cd/eho 所要输入数据|程序名*/



//竞赛中的输入输出
//I/O

//多个数据输入
/*int x;
while (scanf("%d", &x)==1)
{
    printf("%d\n", 2*x);
}*/

//重定向【使用文件】freopen

/*freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);*/

/*int a;
scanf("%d", &a);
printf("%d", a);*/
/*
ATTENTION
1   input文件是命名为input的文本文档，不要加.txt，否则变为input.txt.txt
2   input文件应与 文件名.c 置于同一个文件夹下，而不是建在桌面（当然可以先建在桌面再转移）
3   output文件会在程序运行时自动生成，不必自己新建
*/

//使用文件但不重定向fopen
//略00000

//example days
/*
int y, m, d;

printf("Input year and month:");

scanf("%d%d", &y, &m);

if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
{
    d = 31;
} else if (m==4||m==6||m==9||m==11) {
    d = 30;
} else {
    d = (((y%4==0&&y%100)||y%400==0)?29:28);//非零即真
}

printf("%d年%d月有%d天\n", y, m, d);

//熟悉三元运算符（条件运算符）(相当于简化的if-else)?:的使用
//注意判断相等与否时使用== !=（条件反射检查有没有写错成= !==）
//for中确定循环变量用的是=，不要混淆
//判断表达式非零，有时不必用！=，可利用非零即真，简化代码
*/
/*
关于?:
variable = condition ? expressionA : expressionB
判断condition，若为真（非零），执行A作为结果赋给var，反之执行B作为结果赋给B
*/


//Exercises

//daffodil 水仙花数

/*int b, s, g;
for (int i = 100; i<=999; i++)
{
    b = i/100;
    s = (i-100*b)/10;
    g = i%10;
    if (i==(int)(pow(b,3)+pow(s,3)+pow(g,3)))
        printf("%d\n", i);
}*/

//hanxin

//test
/*int N, a, b, c;
while (scanf("%d%d%d", &a, &b, &c)==3)
{
    printf("p");
}*/

//hanxin_solution


/*
int N, a, b, c;
int j = 0;//count
while (scanf("%d%d%d", &a, &b, &c)==3)
{
for (N = 10; N <= 101; N++)
{
    if (N == 101) {
        if (j) {printf("\n");} 
        printf("Case %d: No answer", ++j);
        break;
    }

    if ((N%3==a)&&(N%5==b)&&(N%7==c)) {
        if (j) {printf("\n");}
        printf("Case %d: %d", ++j, N);
        break;
    }
}
}
*/
//上面利用标志变量j的技巧，规避了首行尾行不必要的空行，并输出了合理的case序号


//inverted triangle

/*int n, i;
scanf("%d", &n);
for(i=n;i>=1;i--)
{
    for(int j = 1;j<=n-i;j++)
        {printf(" ");}
    for(int k = 1;k<=2*i-1;k++)
        {printf("#");}
    printf("\n");
}*/
//5
/*
#########
 #######
  #####
   ###
    #
*/

//sum of subsequence

/*long long n, m;
int ca = 0;
while (scanf("%lld%lld", &n, &m)==2&&n)//%lld
{
double p = 0;//p应在while循环内重置，避免错误的累加
for (long long i = n;i<=m;i++)//i要被赋以ll,故声明为ll而非int
{
    p = p+(1.0/(i*i));//1.0是必要的
}
if (ca) printf("\n");
printf("Case %d: %.5f", ++ca, p);
}*/
/*
这里必须用ll的原因是，2^3<10<2^4,2^18<10e6<2^24,平方，(10e6)^2>2^36>(2^31)-1，整型溢出
整型int 【-(2^31)~(2^31)-1】【-2147483648~2147483647】
*/

//decimal
//略，只需注意(double)...

//permutation

//关键的两两不等判定，我们考虑两种手法
//一种是bool类型&if，一种是bool类型&array，如下

//参见draft-02/03 Appendix per
//02末03初



//一处注记
/*
刘汝佳先生在紫书中指出，变量i定义在循环语句中，因此i在循环体内不可见。这很可能是错误的
i在循环体内是可见且可用的，这一点很容易验证
*/
//应当说i在循环体外不可见。若要可见，则可在循环语句前声明i

//experiments

//01
//略，注意2*i，非2i

//02
/*double i;
for (i = 0; i != 10; i+=0.1)
{
    printf("%.1f\n", i);
}*/
//无限进行，或许直至溢出
//若要按预期输出，有
/*for (int i = 0; i != 10; i++)
{
    printf("%.1f\n", i*0.1);
}*/



//switch (fall-through 见dft03)

int num;
scanf("%d", &num);
switch (num) {  
    case 1:  
        printf("You entered 1.\n");  
        break;  
    case 2:  
        printf("You entered 2.\n");  
        break;  
    case 3:  
        printf("You entered 3.\n");  
        break;  
    default:  
        printf("Not 1/2/3.\n");  
}  



//array 数组

//one-dimension array

//较大数组尽量声明在main函数外，这里我们先考虑在main内声明

int a[5];//a[0], a[1], ...a[4]
memset(a, 0, sizeof(a));//清零
printf("%d\n", a[3]);//打印a[3]
/*memset(a, 1, sizeof(a));
printf("%d\n", a[3]);
可见这并不能将a的所有元素设置为1
若要，考虑如下循环*/
for (int i = 0; i < 5; i++) {a[i] = 1;}
printf("%d\n", a[3]);

//下面我们声明同时初始化一个新的数组

int arrayTest[3] = {1, 2, 3};
//访问
printf("%d%d%d\n", arrayTest[0], arrayTest[1], arrayTest[2]);
//修改
arrayTest[1] = 9;
printf("%d%d%d\n", arrayTest[0], arrayTest[1], arrayTest[2]);
//遍历
for (int i = 0; i < 3; i++)
{
    printf("%d ", arrayTest[i]);
}

printf("\n");

//数组大小为常量而非变量
//索引不得超出数组范围，否则为未定义行为（Undefined Behavior），UB，可能崩溃
//未被初始化的元素会自动初始化为零，如下
int b[8];
printf("%d\n", b[5]);

//two-dimension array

int my2DArr[3][4];//相当于三行四列的矩阵；或抽象地表述为第一维，第二维
printf("%d\n", my2DArr[0][0]);

/*
我们指出，C并不能像Golang那样利用类似Println(a)的语句简便地打印和渲染数组
也没有length(a)之类的函数
若要实现，考虑如下手法
*/

//01

a[1] = 2;a[2] = 3;

printf("[");
for (int i = 0; i < 3; i++)
{
    printf("%d", a[i]);
    if (i < 2) {printf(" ");}
}
printf("]\n");

//02

//注意到数组中所有元素都是同类型的，故第一个元素的大小即代表每个元素的大小，我们有

printf("length = %d\n", sizeof(a) / sizeof(a[0]));//...5
printf("length = %d\n", sizeof(arrayTest) / sizeof(arrayTest[0]));//...3



//Appendix per 01

//Qn.per关键判定的数组解法

/*int a, b, c, d, e, f, g, h, i;
for (int ghi = 123; ghi <= 987; ghi++) {
    int abc = ghi / 3;
    int def = abc*2;
    bool can = true;
    if ((ghi%3 != 0)||(abc < 123)) {can = false;}
g = ghi/100;
h = (ghi - 100*g)/10;
i = ghi%10;
a = abc/100;
b = (abc - 100*a)/10;
c = abc%10;
d = def/100;
e = (def - 100*d);
f = def%10;
if (a*b*c*d*e*f*g*h*i == 0) {can = false;}
int per[9] = {a, b, c, d, e, f, g, h, i};
for (int j = 0; j < 9 && can; j++) {                //一旦false，“&&can”条件就使这个循环结束
    for (int k = j+1; k < 9; k++) {                 //break用以跳出这个循环
        if (per[j]==per[k]) {
            can = false;
            break;
        }
    }
}
if (can) {printf("%d %d %d\n", abc, def, ghi);}
}*/

return 0;
}