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
//	//��ά���鴫��ֻ��ʡ���У�����ʡ����
//	//����һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ���ж���Ԫ��
//	int arr[3][5] = { 0 };
//	//test(arr);//��ά���鴫��
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

 

//����ָ�� --- ָ������ָ�� - ��ź�����ַ��ָ��
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
//	//&������ �� ������ ���Ǻ�����ַ
//	/*printf("%p\n", &Add);
//	printf("%p\n", Add);*/
//	int (*pa)(int, int) = Add;
//	printf("%d\n", (*pa)(2, 3));//5
//	return 0;
//}

//(*(void (*)())0)();//��0ǿ������ת���ɣ�void(*)()����ָ�����͵ĵ�ַ
					 //����0��ַ���ĸú��� 


//signal��һ����������
//signal�����Ĳ�������������һ����int���ڶ����Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int������������void
//signal�����ķ�������Ҳ��һ������ָ�룺�ú���ָ��ָ��ĺ����Ĳ�����int������������void
void (*signal(int, void(*)(int)))(int);

//��
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
//	int* arr[5];//ָ������
//	int (*pa)(int, int) = Add;//����ָ��
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };//����ָ������
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
//	//1.����ָ��
//	char(*pf)(char*, const char*) = my_strcpy;
//	//����ָ������
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
//	//parr�Ǻ���ָ������
//	int(*parr[])(int, int) = { 0, Add,Sub,Mul,Div,Xor };
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		if(input >= 1 && input <=5 )
//		{
//			printf("������������������>");
//			scanf("%d%d", &x, &y);
//			int ret = parr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//	return 0;
//}


void Calc(int (*pf)(int, int))
{
	int x = 0;
	int y = 0;
	printf("������������������>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pf(x, y));  
}

//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��>");
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
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr;

	int(*pfArr[4])(int, int);//pfArr��һ������ - ����ָ�������
	int (*(*ppfArr)[4])(int, int) = &pfArr;//����ָ������ָ��
	//ppfArr��һ������ָ�룬ָ��ָ���������4��Ԫ��
	//ָ��������ÿ��Ԫ�ص�������һ������ָ�� int (*)(int, int)
	return 0;
}