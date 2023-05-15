#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test(int arr[3][5])
{

}
void test1(int arr[][5])
{

}
//void test2(int arr[3][])//err
//{
//
//}
//void test3(int *arr)//err
//{
//
//void test4(int **arr)//err
//{
//
//}
void test5(int (*arr)[5])
{

}

//int main()
//{
//	//二维数组传参只能省略行，不能省略列
//	//对于一个二维数组，可以不知道有多少行，但是必须知道一行有多少元素
//	int arr[3][5] = { 0 };
//	//test(arr);//二维数组传参
//	//test1(arr);
//	//test2(arr);
//	//test3(arr);
//	//test4(arr);
//	test5(arr);
//	return 0;
//}


//void test1(int* p)
//{
//
//}
//void test2(char* p)
//{
//
//}
//int main()
//{
//	int a = 0;
//	int* p1 = &a;
//	test1(&a);//ok
//	test1(p1);
//	char ch = 'w';
//	char* pc = &ch;
//	test2(&ch);
//	test2(pc);
//	return 0;
//}

 

//函数指针 --- 指向函数的指针 - 存放函数地址的指针
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;
//	//printf("%d\n", Add(a, b));
//
//	//&函数名 和 函数名 都是函数地址
//	/*printf("%p\n", &Add);
//	printf("%p\n", Add);*/
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3));//5
//	return 0;
//}

//(*(void (*)())0)();//把0强制类型转换成：void(*)()函数指针类型的地址
					 //调用0地址处的该函数 


//signal是一个函数声明
//signal函数的参数有两个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回类型是void
//signal函数的返回类型也是一个函数指针：该函数指针指向的函数的参数是int，返回类型是void
void (*signal(int, void(*)(int)))(int);

//简化
typedef void(*signal_t)(int);
signal_t signal(int, signal_t);


//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{ 
//	int* arr[5];//指针数组
//	int (*pa)(int, int) = Add;//函数指针
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };//函数指针数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", parr[i](6, 3));
//	}
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src);
//int main()
//{
//	//1.函数指针
//	char(*pf)(char*, const char*) = my_strcpy;
//	//函数指针数组
//	char(*pfarr[4])(char*, const char*);
//}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}

void menu()
{
	printf("****************************\n");
	printf("****  1.Add      2.Sub  ****\n");
	printf("****  3.Mul      4.Div  ****\n");
	printf("****  5.Xor      0.exit ****\n");
	printf("****************************\n");
}


//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//parr是函数指针数组
//	int(*parr[])(int, int) = { 0, Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		if(input >= 1 && input <=5 )
//		{
//			printf("请输入两个操作数：>");
//			scanf("%d%d", &x, &y);
//			int ret = parr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//	return 0;
//}


void Calc(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数：>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));  
}

//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr;

	int(*pfArr[4])(int, int);//pfArr是一个数组 - 函数指针的数组
	int (*(*ppfArr)[4])(int, int) = &pfArr;//函数指针数组指针
	//ppfArr是一个数组指针，指针指向的数组有4个元素
	//指向的数组的每个元素的类型是一个函数指针 int (*)(int, int)
	return 0;
}