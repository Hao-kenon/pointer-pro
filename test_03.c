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
		//һ��ð������
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
	//�Ƚ���������ֵ
	return *(int*)e1 - *(int*)e2;
}

//void*����ָ����Խ����������͵ĵ�ַ
//void*����ָ�벻�ܽ��н����ò���
//void*����ָ�벻�ܽ���+-����

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
	//�Ƚ�������������
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
	//��һ���������������������Ԫ�ص�ַ
	//�ڶ��������������������Ԫ�ظ���
	//�����������������������ÿ��Ԫ�ش�С-��λ�ֽ�
	//���ĸ��������Ǻ���ָ�룬�Ƚ�����Ԫ�ص����ú����ĵ�ַ-����ָ��Ĳ����Ǵ��Ƚϵ�����Ԫ�صĵ�ַ
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
//	//����������Ԫ�ص�ַ
//	//1.sizeof(������)-��������ʾ��������
//	//2.&������-��������ʾ��������
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));//4*4=16 - sizeof(������)������������ܴ�С
//	//printf("%d\n", sizeof(a + 0));//4/8 - ��������ʾ��Ԫ�ص�ֵ��a+0����Ԫ�ص�ַ����ַ��С��4/8
//	//printf("%d\n", sizeof(*a));//4 - ����������Ԫ�ص�ַ��*a������Ԫ��
//	//printf("%d\n", sizeof(a + 1));//4/8 - ��������ʾ��Ԫ�ص�ֵ��a+2�ǵڶ���Ԫ�ص�ַ����ַ��С����4/8�ֽ�
//	//printf("%d\n", sizeof(a[1]));//4 - �ڶ���Ԫ�ش�С
//	//printf("%d\n", sizeof(&a));//4/8 - &aȡ��������ĵ�ַ����ַ��С����4/8�ֽ�
//	//printf("%d\n", sizeof(*&a));//16 - ȡ��ַ���ٽ����ã�����Ļ�������Ĵ�С
//	//printf("%d\n", sizeof(&a + 1));// 4/8 - &a������ĵ�ַ��&a+1��Ȼ��ַ�����������飬���ǻ��ǵ�ַ��������4/8
//	//printf("%d\n", sizeof(&a[0]));//4/8 &a[0]�ǵ�һ��Ԫ�ص�ַ
//	//printf("%d\n", sizeof(&a[0] + 1));//4/8 &a[0]+1
//
//
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//6 - �����С
//	//printf("%d\n", sizeof(arr + 0));// 4/8 ��Ԫ�ص�ַ
//	//printf("%d\n", sizeof(*arr));// 1
//	//printf("%d\n", sizeof(arr[1]));// 1 - �ڶ���Ԫ��
//	//printf("%d\n", sizeof(&arr));// 4/8 - �����С
//	//printf("%d\n", sizeof(&arr+1));// &arr+1 ���������������ĵ�ַ 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));// 4/8 �ڶ���Ԫ�ص�ַ
//
//
//	//char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", strlen(arr));// ���ֵ
//	//printf("%d\n", strlen(arr + 0));// ���ֵ
//	////printf("%d\n", strlen(*arr));//  err
//	////printf("%d\n", strlen(arr[1]));//  err
//	//printf("%d\n", strlen(&arr));//  ���ֵ
//	//printf("%d\n", strlen(&arr + 1));//  ���ֵ-6
//	//printf("%d\n", strlen(&arr[0] + 1));// ���ֵ-5
//
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));// 7 
//	//printf("%d\n", sizeof(arr + 0));// 4/8 ��Ԫ�ص�ַ
//	//printf("%d\n", sizeof(*arr));// 1
//	//printf("%d\n", sizeof(arr[1]));// 1 - �ڶ���Ԫ��
//	//printf("%d\n", sizeof(&arr));// 4/8 - �����С
//	//printf("%d\n", sizeof(&arr+1));// &arr+1 ���������������ĵ�ַ 4/8
//	//printf("%d\n", sizeof(&arr[0] + 1));// 4/8 �ڶ���Ԫ�ص�ַ
//
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", strlen(arr));// 6
//	//printf("%d\n", strlen(arr + 0));// 6
//	////printf("%d\n", strlen(*arr));//  err
//	////printf("%d\n", strlen(arr[1]));//  err
//	//printf("%d\n", strlen(&arr));//  6
//	//printf("%d\n", strlen(&arr + 1));// ���ֵ
//	//printf("%d\n", strlen(&arr[0] + 1));// 5
//
//	/*char* p = "abcdef";*/
//	//printf("%d\n", sizeof(p));//  4/8 - ����ָ�����p�Ĵ�С
//	//printf("%d\n", sizeof(p + 1));// 4/8 p+1���ַ�b�ĵ�ַ
//	//printf("%d\n", sizeof(*p));// 1  ��һ���ַ� - 'a'
//	//printf("%d\n", sizeof(p[0]));// 1  p[0] = *(p + 0)  ��һ���ַ� - 'a'
//	//printf("%d\n", sizeof(&p));// 4/8
//	//printf("%d\n", sizeof(&p + 1));//  4/8
//	//printf("%d\n", sizeof(&p[0] + 1));// 4/8
//
//	//char* p = "abcdef";
//	//printf("%d\n", strlen(p));//  6
//	//printf("%d\n", strlen(p + 1));// 5
//	////printf("%d\n", strlen(*p));//  err
//	////printf("%d\n", strlen(p[0]));//  err
//	//printf("%d\n", strlen(&p));// ���ֵ
//	//printf("%d\n", strlen(&p + 1));//  ���ֵ
//	//printf("%d\n", strlen(&p[0] + 1));// 5
//
//	//int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a));// 48
//	//printf("%d\n", sizeof(a[0][0]));// 4
//	//printf("%d\n", sizeof(a[0]));// 16 a[0]�൱�ڵ�һ����Ϊһά�������������sizeof(a[0])���Ǽ����������Ĵ�С
//	//printf("%d\n", sizeof(a[0] + 1));// 4/8 ��һ�еڶ���Ԫ�ص�ַ
//	//printf("%d\n", sizeof(*(a[0] + 1)));// 4 �൱��a[0][1]
//	//printf("%d\n", sizeof(a+1));// 4/8 �ڶ���Ԫ�ص�ַ
//	//printf("%d\n", sizeof(*(a + 1)));// 16  �ڶ���Ԫ�ش�С
//	//printf("%d\n", sizeof(&a[0]+1));// 4/8  �ڶ���Ԫ�ص�ַ
//	//printf("%d\n", sizeof(*(&a[0] + 1)));//  16  �ڶ���Ԫ�ش�С
//	//printf("%d\n", sizeof(*a));// 16  a����Ԫ�ص�ַ - ��һ�е�ַ - �����þ��ǵ�һ��Ԫ�ش�С
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
////����p��ֵΪ0x100000,�ṹ�����͵ı�����С��20�ֽ�  
//int main()
//{
//	printf("%p\n", p + 0x1); //0x100014  0x100000+20��14��
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004  int*������4���ֽ�
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
//	int a[3][2] = { (0,1),(2,3),(4,5) };//���ű��ʽ{1,3,5,0,0,0}
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);//*(p+0) == p[0]   ���: 1
//	return 0;
//}

int main()
{
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][3] - &a[4][3], &p[4][2] - &a[4][2]);//fffffffc,-4
	//����a��5��5�У�����p��5��4��
	return 0;
}