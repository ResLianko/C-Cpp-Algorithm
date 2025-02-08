//Chapter 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int t1;

struct Person {
    char name[50];
    int age;
    float height;
    char sex[5];//或char gender;(M, F)
};

typedef struct Student {
    char name[50];
    int rank;
} Student;

void myFunction(){
    static int local_static_p = 0;
    local_static_p++;
    printf("%d\n", local_static_p);
}

int main()
{

//【PRE-dft03】

//注记：此处进行部分语法的预先讨论（基于高三暑假看的一些Golang）

//Begin【】

//01 var C中并没有这种变量声明方式

//02 time 返回当前的北京时间
    time_t rawtime;//声明一个time_t类型的变量rawtime用于存储从标准纪元（通常是1970年1月1日00:00:00 UTC，也称为“Unix epoch”）起经过的秒数
    struct tm *local_time;//声明一个指向tm结构体的指针local_time  
    time(&rawtime);//获取当前时间
  
    // 将当前时间转换为本地时间  
    local_time = localtime(&rawtime);//调用localtime函数将rawtime中的原始时间转换为本地时间并将转换后的时间信息存储到local_time指向的tm结构体中。
  
    // 打印当前时间
    //tm是定义在time.h中的结构体 我们引用它时往往完整地写出struct tm
    printf("当前北京时间: %04d-%02d-%02d %02d:%02d:%02d\n",  
           local_time->tm_year + 1900, // 年份从1900年开始计数  
           local_time->tm_mon + 1,     // 月份从0开始计数  
           local_time->tm_mday,        // 日期  
           local_time->tm_hour,        // 小时  
           local_time->tm_min,         // 分钟  
           local_time->tm_sec);        // 秒 
//->是一个运算符，用于访问指针所指向的结构体中的成员

//关于什么是结构体，什么是指针，见后

//03
/*
slice 切片 不存在于C 其功能可以模拟
range 不存在于C 可考虑for遍历
map 映射（键值对）不存在于C 可用array struct模拟
err 不存在于C error可处理
struct-method 不存在于C cpp有面向对象，见后
*/

//04 func (function) 函数 见不远的后文



//05 struct 结构体 (from structure):集合不同类型的数据

//定义一个结构体Person，见main函数外
//声明一个Person类型的结构体变量watashi
//我们考虑多种方法为结构体变量赋值
struct Person watashi = {"Lianko", 16, 173.0, "girl"};//初始化【1】
printf("%s\n", watashi.name);
printf("%d\n", watashi.age);                            //访问
/*scanf("%s", watashi.name);                            //no &
scanf("%f", &watashi.height);                           //& scanf【2】或者getchar
printf("%s\n", watashi.name);
printf("%d\n", watashi.height);                         //访问*/
strcpy(watashi.name, "lianmaomao");                     //strcpy(对于string)
watashi.age = 17;                                       //【3】直接赋值
printf("%s\n", watashi.name);
printf("%d\n", watashi.age);                            //访问

//typedef 关键字：为结构体类型定义新名字 见main外
//于是可以如下简洁地声明
Student boku;
strcpy(boku.name, "rain");
printf("%s\n", boku.name);
//那么，方才提及的->是什么？这涉及到指针



//06 指针 (pointer) (ptr)

/*指针表示内存中的一个地址*/

int *ptr;                                               //定义了一个指向int类型的指针
int a = 5;                                              //定义普通变量a
int *p = &a;//有&                                       //将普通变量a的内存地址赋给指针变量p(指针变量存储内存地址) p指向a
printf("%d\n", *p);                                     //利用指针【访问】所指变量

//p是指针变量 *p是指针p所指变量的值
//&是取地址的算子(Operator):我们约定计科意义上的算子与数学上一致，都表示运算符而非参与运算的对象

//指针的加减运算以其指向的数据类型的大小为单位
int arr1[10];
int *ptr1 = arr1;//无&              //ptr1指向arr1[0] 【数组首地址】就是首元素地址
ptr1++;                             //p指向arr1[1]
/*p-=2;*/                           //arr1[-1] 此处越界访问，是非法的

//指针的比较运算（强调比较也是运算）
ptr = &arr1[5];
if (ptr1 < ptr) {
    printf("p指向的地址 < q指向的地址\n");
}

//利用指针修改变量
int phi = 1;
printf("%d\n", phi);

int *ptr2 = &phi;
*ptr2 = 2;

printf("%d\n", phi);

//关于指针初步，到此为止，进阶详见后文
//我们指出，访问结构体的成员时，对于结构体变量，使用【 . 】访问，对于指向结构体的指针，使用【 -> 】访问
//声明指向结构体的指针的语法是    struct MyStruct *myPointer;

//End【】



//tips
/*分行的输出，分析结果，可以考虑有几行，每行输出什么
注意输出语句在循环内还是循环外
有限地枚举或分析首尾处的具体情形有助于发现规律，明确结构*/
//while (expression);   表示循环体为空



//字符数组的进一步讨论 见dft5



//function 函数

/*
计科上的函数是包括但不限于数学映射的可复用代码块
定义格式为
返回类型 函数名(参数列表){函数体}
我们在main函数外引入内置函数或定义自定义函数，并在main函数中或自定义函数中调用内置函数或（其他）自定义函数
*/
/*
我们完全可以定义无参数的函数，例如
void sayHello(){
    printf("Hello!\n");
}
也可以定义无返回值的函数，其返回类型为void且无须return语句，除非希望中途退出
其往往用于打印
另外，还存在既无参数又无返回值的函数，如上面的sayHello
*/
/*
一个函数中可以有多个return语句，存在于不同的分支，但一旦遇到return语句，将退出程序
*/
/*
可以在main函数之前定义函数，也可以在main函数之后定义函数并在main函数前声明函数，后者例如
#include

int myFunc(void)

int main(){
...
return 0;
}

int myFunc(void){
    ...
}
*/

//若不先声明，则有时会出错，因为自上而下读取代码的编译器读到函数名时尚不知道函数的存在

//形参 函数定义中声明的形式参数 有些类似占位符
//实参 被传递给被调用函数的实际参数
//自定义函数中的参数列表中的变量（形参）在其他函数中不可见（局部作用域） 函数执行完毕后形参被销毁，其占用的内存将释放

//Examples

//01    计算二维情形下的Euclid范数

/*
#include <stdio.h>
#include <math.h>

double euc(double x, double y)
{
    return sqrt((x*x + y*y));
}

int main()
{
printf("%.3f", euc(1, 1));//1.414
return 0;
}
*/
//另外也可以直接调用 hypot函数
printf("%.3f\n", hypot(1, -1));//1.414
//非二维的情形就不能用hypot 它只接收两个参数

//02    化为秒

/*int toSeconds(int hours, int minutes, int seconds)
{
    int s;
    s = 3600*hours + 60*minutes + seconds;
    return s;
}*/

//03    素数判断（优化版）

/*bool isPrime(int n){
    if (n <= 1)
    {
        return false;
    }
    if (n != 2 && n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}*/

//04    exchange

/*#include <stdio.h>

void swap(int a, int b){
    int t = a;
    a = b;
    b = t;
}

int main()
{
int x = 1, y = 2;
printf("%d %d\n", x, y);        //1 2
swap(x, y);
printf("%d %d\n", x, y);        //1 2
return 0;
}*/
//不难发现，此处并没有实现交换x, y的功能，因为x, y只是被拷贝到了swap函数并参与执行，本身的值并未被修改
//若要修改，不妨考虑如下3种手法

//04-01    利用全局变量
/*
#include <stdio.h>  
int global_x, global_y;  
void swap(){  
    int t = global_x;  
    global_x = global_y;  
    global_y = t;  
}  
int main()  
{ 
    global_x = 1;  
    global_y = 2;  
    printf("%d %d\n", global_x, global_y);        //1 2
    swap();  
    printf("%d %d\n", global_x, global_y);        //2 1  
    return 0;  
}
*/
//然而，这显然不是一个普适的，我们所期望的方法 更优地，考虑使用指针

//04-02    利用指针
/*
#include <stdio.h>
void swap(int *a, int *b){      //以指针为参数的函数（并非所谓的 指针函数 / 函数指针）
    int t = *a;                 //【1】
    *a = *b;  
    *b = t;  
}  
  
int main()  
{  
    int x = 1, y = 2;  
    printf("%d %d\n", x, y);        //1 2  
    swap(&x, &y);//不是传值(pass by value)而是传址(pass by reference)
    printf("%d %d\n", x, y);        //2 1  
    return 0;  
}
//【1】强调，a是指针，*a是指针指向的变量的值，*是解引用操作符
*/

//04-03    引用    （ATTENTION:这个方法只适用于C++ 不适用于C）
//为了不过早地引入cpp，我们将在之后讨论这个问题

//05    判断（多位数正整数）是否高位到低位严格递增
/*
int isIncreased(int num){
while (num != 0)
{
int k = num % 10;
if (k <= num / 10 % 10)
{
    return 0;                                           //已经return 无须break
} else {
    num = num / 10;                                     //下一次迭代自动发生 此处无须continue
}
}
return 1;
}
*/



//Appendix



//01    指针函数与函数指针

//指针函数    返回值为指针的函数
int* getArrayPointer(int size){  
    static int array[100];//定义一个静态数组  
    //注意：这里的数组大小是固定的100，而不是根据size参数动态分配的  
    return array;//返回指向数组首元素的指针  
}
//其中，关于static，见后

//函数指针    指向函数的指针
//若在main函数外声明了【实现二元加法的函数】
/*
int add(int a, int b) {  
    return a + b;  
}
*/
//int (*funcPtr)(int, int);    定义一个指向【接受两个int参数并返回int的函数】的指针
//funcPtr = &add;    or    【funcPtr = add;】    此处在赋值
//int result = funcPtr(5, 3);    调用    （无需我们显式地使用解引用符号 * ）



//02    指针的指针 / 指针的指针的指针 / ...
/*
//指针的指针    一个变量 其存储的是另一个指针变量的地址

    int value = 1;  
    int *p = &value;       // p 是一个指向整数的指针  
    int **pp = &p;         // pp 是一个指向指针的指针，指向 p  
  
    // 通过指针的指针访问和修改值  
    printf("Original value: %d\n", **pp);  // 输出 1
    **pp = 2;            // 修改 value 的值为 2  
    printf("Modified value: %d\n", **pp);  // 输出 2

//指针的指针的指针

    int ***ppp = &pp;      // ppp 是一个指向指针的指针的指针，指向 pp
    printf("%d\n", ***ppp);  // 输出 2
    ***ppp = 200;          // 修改 value 的值为 200  
    printf("%d\n", ***ppp);  // 输出 200  
【注】
ppp  这是一个三级指针  它指向一个二级指针  int **类型  的地址
*ppp  对ppp进行解引用操作  得到它指向的二级指针的值  这个值本身是一个指向整数指针  (int *类型)  的地址  
**ppp  再次对结果进行解引用操作  得到二级指针指向的整数指针的值  这个值是一个整数的地址  
***ppp  最后  对**ppp的结果进行解引用操作  得到整数指针指向的整数值  
*/

//野指针    Wild Pointer
/*
指向未知地址的指针，这些地址可能是随机的、不正确的或者从未被分配的内存地址
由 指针未初始化 / 指针指向的内存已被释放【1】 / 指针指向局部变量且该变量已超出作用域【2】 等引起
【1】例如，使用free()函数释放了通过malloc()分配的内存），但指针的值没有被置为NULL
【2】例如，函数执行结束后局部变量被释放
野指针的危害在于，它们可能指向任意内存位置，导致程序崩溃、数据损坏或安全漏洞
指针指向的内存被释放后没有正确处理(置为NULL)，常称为  悬挂指针  (Dangling Pointer)
*/

//空指针    Null Pointer
int *myNullPtr = NULL;



//语法糖 (Syntactic Sugar) 的一个经典例子
/*对于一维数组a 数组名a是指向第一个元素a[0]的（广义）指针
我们认为 a[i]是*(a+i)的一个语法糖*/
//一个简单的验证
int arrsu[3] = {0, 1, 2};
printf("%d %d %d %d\n", arrsu[1], *(arrsu+1), arrsu[2], *(arrsu+2));//1 1 2 2
//注意到 上文已经提及 【指针的加减运算以其指向的数据类型的大小为单位】



//void main 写法
/*
#include<stdio.h>

void main(){
    int i, n = 15;//...
    long a = 1, b = 1, tmp;

    for (i = 0; i < n; i++) {
        tmp = a, a = b, b += tmp;
    }

    printf("%.3f  %.3f\n", (double)a/tmp, (double)tmp/a);//1.618  0.618
}
//这种写法是不推荐的，我们更推荐 int main-return 0 写法
//上例表明Fibonacci 数列相邻项比值是收敛的
*/



//递归    Recursion    （自调用）

//递归实现阶乘
/*
int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

【或者，更保险地】

unsigned long long factorial(int n) {
    if (n == 0) {  
        return 1;  
    }
    return n * factorial(n - 1);  
}  
*/

//不利用递归 利用迭代（Iteration）实现阶乘
/*
int factorial(int n) {  
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i; 
    }  
    return result;
}
*/
//递归，通常有所谓的基本情况（Base case），也称基线情况，用以结束递归，防止无限递归
//f(f(x))只是f(x)调用了自身，不是递归情形
//递归要求在定义函数时在函数体内调用自身

//递归实现Fibonacci数列
/*
int funcFibonacci(int n){
    if(n == 1 || n == 2)
    return 1;
    return funcFibonacci(n - 1) + funcFibonacci(n - 2);
}
*/

//static初步
//若为局部静态变量：生命周期为整个程序    只初始化一次
//即使声明它的函数调用结束，它的值也不会被销毁    例如main前面的声明的myFunction，每次调用，值都会累加

myFunction();//1
myFunction();//2
myFunction();//3

//全局变量自动初始化为0    局部变量则不会    （声明但不赋初值时）
//验证如下
int t2;
printf("%d\n", t1);//0
printf("%d\n", t2);//0    这可能是环境导致的

//0-1互化
//t    ->    1 - t

/*int main(){...}, "return 0;"不是必要的，这不会导致error或warning
但完全不指定main的返回类型是会出问题的  Warning for no return type for main() / ...
例如#include <stdio.h> 
int main(){int i = 1; while(i < 5) {printf("%d", i);}不会因没有return 0而报错
然而，它是循环结构(loop construct)的特别况，无限循环(infinite loop)
*/

return 0;

}