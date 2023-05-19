#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubble_sort(int arr[], int sz)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < sz - 1; x++)
	{
		//一趟冒泡排序
		for (y = 0; y < sz - x - 1; y++)
		{
			if (arr[y] > arr[y + 1])
			{
				int temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;

			}
		}
	}
}

struct Stu
{
	char name[20];
	int age;
};

//void qsort(void* base,
//	size_t num,
//	size_t width,
//	int(* cmp)(const void* elem1, const void* elem2));

int cmp_int(const void* e1, const void* e2)
{
	//比较两个整型值
	return *(int*)e1 - *(int*)e2;
}

//void*类型指针可以接受任意类型的地址
//void*类型指针不能进行解引用操作
//void*类型指针不能进行+-操作

void test1()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2)
{
	//比较两个浮点型数
	/*if (*(float*)e1 == *(float*)e2)
	{
		return 0;
	}
	else if (*(float*)e1 > *(float*)e2)
	{
		return 1;
	}
	else
		return -1;*/
	return ((int)(*(float*)e1 - *(float*)e2));
}

void test2()
{
	float f[] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}

int cmp_stu_by_age(const* e1, const* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const* e1, const* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void test3()
{
	struct Stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	//第一个参数：待排序数组的首元素地址
	//第二个参数：待排序数组的元素个数
	//第三个参数：待排序数组的每个元素大小-单位字节
	//第四个参数：是函数指针，比较两个元素的所用函数的地址-函数指针的参数是待比较的两个元素的地址
}    

//int main()
//{
//	test3();
//	
//	//test2();
//
//	//test1();
//	//bubble_sort(arr, sz);
//	
//	return 0;
//}
 
//int main()
//{
//	//数组名是首元素地址
//	//1.sizeof(数组名)-数组名表示整个数组
//	//2.&数组名-数组名表示整个数组
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));//4*4=16 - sizeof(数组名)计算的是数组总大小
//	//printf("%d\n", sizeof(a + 0));//4/8 - 数组名表示首元素的值，a+0是首元素地址，地址大小是4/8
//	//printf("%d\n", sizeof(*a));//4 - 数组名是首元素地址，*a就是首元素
//	//printf("%d\n", sizeof(a + 1));//4/8 - 数组名表示首元素的值，a+2是第二个元素地址，地址大小就是4/8字节
//	//printf("%d\n", sizeof(a[1]));//4 - 第二个元素大小
//	//printf("%d\n", sizeof(&a));//4/8 - &a取的是数组的地址，地址大小就是4/8字节
//	//printf("%d\n", sizeof(*&a));//16 - 取地址，再解引用，计算的还是数组的大小
//	//printf("%d\n", sizeof(&a + 1));// 4/8 - &a是数组的地址，&a+1虽然地址跳过整个数组，但是还是地址，所以是4/8
//	//printf("%d\n", sizeof(&a[0]));//4/8 &a[0]是第一个元素地址
//	//printf("%d\n", sizeof(&a[0] + 1));//4/8 &a[0]+1
//
//
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//6 - 数组大小
//	//printf("%d\n", sizeof(arr + 0));// 4/8 首元素地址
//	//printf("%d\n", sizeof(*arr));// 1
//	//printf("%d\n", sizeof(arr[1]));// 1 - 第二个元素
//	//printf("%d\n", sizeof(&arr));// 4/8 - 数组大小
//	//printf("%d\n", sizeof(&arr+1));// &arr+1 是跳过整个数组后的地址 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));// 4/8 第二个元素地址
//
//
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", strlen(arr));// 随机值
//	//printf("%d\n", strlen(arr + 0));// 随机值
//	////printf("%d\n", strlen(*arr));//  err
//	////printf("%d\n", strlen(arr[1]));//  err
//	//printf("%d\n", strlen(&arr));//  随机值
//	//printf("%d\n", strlen(&arr + 1));//  随机值-6
//	//printf("%d\n", strlen(&arr[0] + 1));// 随机值-5
//
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));// 7 
//	//printf("%d\n", sizeof(arr + 0));// 4/8 首元素地址
//	//printf("%d\n", sizeof(*arr));// 1
//	//printf("%d\n", sizeof(arr[1]));// 1 - 第二个元素
//	//printf("%d\n", sizeof(&arr));// 4/8 - 数组大小
//	//printf("%d\n", sizeof(&arr+1));// &arr+1 是跳过整个数组后的地址 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));// 4/8 第二个元素地址
//
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", strlen(arr));// 6
//	//printf("%d\n", strlen(arr + 0));// 6
//	////printf("%d\n", strlen(*arr));//  err
//	////printf("%d\n", strlen(arr[1]));//  err
//	//printf("%d\n", strlen(&arr));//  6
//	//printf("%d\n", strlen(&arr + 1));// 随机值
//	//printf("%d\n", strlen(&arr[0] + 1));// 5
//
//	/*char* p = "abcdef";*/
//	//printf("%d\n", sizeof(p));//  4/8 - 计算指针变量p的大小
//	//printf("%d\n", sizeof(p + 1));// 4/8 p+1是字符b的地址
//	//printf("%d\n", sizeof(*p));// 1  第一个字符 - 'a'
//	//printf("%d\n", sizeof(p[0]));// 1  p[0] = *(p + 0)  第一个字符 - 'a'
//	//printf("%d\n", sizeof(&p));// 4/8
//	//printf("%d\n", sizeof(&p + 1));//  4/8
//	//printf("%d\n", sizeof(&p[0] + 1));// 4/8
//
//	//char* p = "abcdef";
//	//printf("%d\n", strlen(p));//  6
//	//printf("%d\n", strlen(p + 1));// 5
//	////printf("%d\n", strlen(*p));//  err
//	////printf("%d\n", strlen(p[0]));//  err
//	//printf("%d\n", strlen(&p));// 随机值
//	//printf("%d\n", strlen(&p + 1));//  随机值
//	//printf("%d\n", strlen(&p[0] + 1));// 5
//
//	//int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a));// 48
//	//printf("%d\n", sizeof(a[0][0]));// 4
//	//printf("%d\n", sizeof(a[0]));// 16 a[0]相当于第一行作为一维数组的数组名，sizeof(a[0])就是计算这个素组的大小
//	//printf("%d\n", sizeof(a[0] + 1));// 4/8 第一行第二个元素地址
//	//printf("%d\n", sizeof(*(a[0] + 1)));// 4 相当于a[0][1]
//	//printf("%d\n", sizeof(a+1));// 4/8 第二行元素地址
//	//printf("%d\n", sizeof(*(a + 1)));// 16  第二行元素大小
//	//printf("%d\n", sizeof(&a[0]+1));// 4/8  第二行元素地址
//	//printf("%d\n", sizeof(*(&a[0] + 1)));//  16  第二行元素大小
//	//printf("%d\n", sizeof(*a));// 16  a是首元素地址 - 第一行地址 - 解引用就是第一行元素大小
//	//printf("%d\n", sizeof(a[3]));//  16 
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d\n", *(a + 1), *(ptr - 1));// 2,5
//	return 0;
//}


//struct Test
//{
//	int num;
//	char* pcname;
//	short sdate;
//	char cha[2];
//	short sba[4];
//}*p;
//
////假设p的值为0x100000,结构体类型的变量大小是20字节  
//int main()
//{
//	printf("%p\n", p + 0x1); //0x100014  0x100000+20（14）
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004  int*类型是4个字节
//	return 0;
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);// 4 ,2000000
//	//ptr1[-1] == *(ptr1+(-1))
//	return 0;
//}

//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };//逗号表达式{1,3,5,0,0,0}
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);//*(p+0) == p[0]   结果: 1
//	return 0;
//}

int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][3] - &a[4][3], &p[4][2] - &a[4][2]);//fffffffc,-4
	//数组a是5行5列，数组p是5行4列
	return 0;
}