#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

//void reverse(char* str)
//{
//	assert(str);
//	int len = strlen(str);
//	char* left = str;
//	char* right = str + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//
//	}
//}
//
//int main()
//{
//	char arr[256] = { 0 };
//	//scanf("%s", arr);
//	gets_s(arr);//��ȡһ��
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	int i = 0;
//	int sum = 0;
//	int ret = 0;
//	for (i = 0; i < n; i++)
//	{
//		//2 22 222 2222 22222
//		ret = ret * 10 + k;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1.����i��λ��
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp /= 10)
//		{
//			n++;
//		}
//		//2.����i��ÿһλn�η�֮�� sum
//		tmp = i; 
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10; 
//		}
//		//3.�ж�i==sum;
//		if (i == sum)
//		{
//			printf("%d\t��ˮ�ɻ���\n", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//��ӡ�ϰ벿��
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < line - 1 - i;j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j < i * 2 + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//��ӡ�°벿��
//	for (i = 0; i < line - 1; i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*
//		for (j = 0; j < 2 * (line - 1 - i) - 1 ; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 1))
		//�������ȫ�����������Խ����ʣ�����Ҫ������left < right
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))
		//�������ȫ��ż�������Խ����ʣ�����Ҫ������left < right
		{
			right--;
		}
		if (left < right)
		{
			int tmp = 0;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//��һ��ѭ�� left = 1,right = 8,��arr[1]��arr[8]���� { 1,9,3,4,5,6,7,8,2,10 }
//	//�ڶ���ѭ�� left = 3,right = 6,��arr[4]��arr[6]���� { 1,9,3,7,5,6,4,8,2,10 }
//	move(arr,sz);
//	print(arr,sz);
//	return 0;
//}


//int main()
//{
//	unsigned char a = 200;//unsigned char 1���ֽ� 0-255
//	//00000000000000000000000011001000
//	unsigned char b = 100;
//	//00000000000000000000000001100100
//	unsigned char c = 0;
//	//    11001000 - a
//	//    01100100 - b
//	//1   00101100 - 44  cֻ��ȡ8λ
//	c = a + b;//��������
//	//00000000000000000000000000101100 
//	printf("%d %d", a + b, c);
//	return 0;
//}


//ʵ�ֺ����������ַ����е�k���ַ�



//����һ
//void left_move(char*arr, int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//1.
//		char tmp = *arr;
//		//2.
//		int j = 0;
//		for (j = 0; j < len; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3.
//		*(arr + len - 1) = tmp;
//	}
//}

//������ - ������ת��
void reverse(char* arr1, char* arr2)
{
	while (arr1<arr2)
	{
		char tmp = *arr1;
		*arr1 = *arr2;
		*arr2 = tmp;
		arr1++;
		arr2--;
	}
}
//ab cdef
//ba fedc
//cdedab
void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1);//�������
	reverse(arr + k, arr + len - 1);//�����ұ�
	reverse(arr, arr + len - 1);//��������
}
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//	printf("%s", arr);
//	return 0;
//}


//1.
//int is_left_move(char* s1, char* s2)
//{
//	int i = 0;
//	int len = strlen(s1);
//	for (i = 0; i < len; i++)
//	{
//		left_move(s1, 1);
//		int ret = strcmp(s1, s2);
//		if (ret == 0)
//			return 1;
//	}
//}

//2.
int is_left_move(char* str1,char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	//step 1 ��str1�ַ�������׷��һ��str1�ַ���
	strncat(str1, str1, len1);
	//step 2 �ж�str2�Ƿ�Ϊstr1���Ӵ�
	char* ret = strstr(str1, str2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//�ж�һ���ַ����Ƿ��������һ���ַ�����ת�õ�
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("YES\n");
//	else
//		printf("NO\n");
//	return 0;
//}

//���Ͼ���  ÿ��ÿ�ж��ǵ�����  ʱ�临�Ӷ�С��O(N)
int Findf(int arr[4][4], int k, int *px,int *py)
{
	int x = 0;
	int y = *py - 1;
	while(x <= *px-1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	//�Ҳ���
	return 0;
}
//int main()
//{
//	int arr[4][4] = { {1,2,3,4},{3,4,5,6},{7,8,9,10}, {11,13,16,19} };
//	int k = 6;
//	int x = 4;
//	int y = 4;
//	
//	//�����Ͳ���
//	int ret = Findf(arr, k, &x, &y);
//	if (1 == ret)
//	{
//		printf("YES\n");
//		printf("�±��ǣ�%d %d\n", x, y);
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}


//size_t == unsigned int
//size_t strlen(const char* string)

//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("haha\n");
//	}
//	else
//	{
//		printf("hehe\n");
//	}
//	return 0;
//}


char* my_strcpy(char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	//while (*str2 != '\0')
	//{
	//	*str1 = *str2;
	//	str1++;
	//	str2++;// - > *str1++ = *str2
	//}
	*str1 = *str2;// '\0'
	char* ret = str1;
	while (*str1++ = *str2++)
	{
		;
	}
	//����Ŀ�ĵؿռ���ʼ��ַ
	return ret;
}

//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "bit";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

char* my_strcat(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1)
	{
		str1++;
	}
	while (*str1++ = *str2++)
	{
		;
	}
	return ret;
}
//int main()
//{
//	char arr1[20] = "Hello";
//	char arr2[] = "World";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;//���
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;//����
	}
	else
	{
		return -1;//С��
	}
	
}

//int main()
//{
//	char p1[] = "abcdee";
//	char p2[] = "abcdef";
//	int ret = my_strcmp(p1, p2);
//	if (ret == 1)
//	{
//		printf("p1>p2\n");
//	}
//	else if (ret == -1)
//	{
//		printf("p1<p2\n");
//	}
//	else if(ret == 0)
//	{
//		printf("p1=p2\n");
//	}
//	return 0;
//}

//strstr
// KMP - �㷨
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* p1 = NULL;
	char* p2 = NULL;
	char* cur = (char*)str1;
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while(*cur)
	{
		p1 = cur;
		p2 = (char*)str2;
		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return cur;
		}
		if (*p1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;
}

//int main()
//{
//	char p1[] = "abcdeefabcdef";
//	char p2[] = "ef";//��һ�γ��ֵĵ�ַ
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�ַ���������\n");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}

//strtok - ���ڷָ��
//int main()
//{
//	char arr[] = "zdz@123456.com";
//	char p[] = "@.";
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	/*char* ret = strtok(arr, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);*/
//  return 0;
//}

//int main()
//{
//	//0 - No error
//	//1 - Operation not permitted
//	//2 - No such file or directory
//	//3 - No such process
//	//����
//	//errno ��һ��ȫ�ֵĴ��������
//	//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//	
//	
//	char* ret = strerror(errno);
//	printf("%s\n", ret);
//
//	/*FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}*/
//	return 0;
//}

#include <ctype.h>

//int main()
//{
//	//char ch1 = toupper('a');//ת��д
//	//char ch2 = tolower('A');//תСд
//	//putchar(ch1);
//	//putchar('\n');
//	//putchar(ch2);
//	/*char s1 = 'A';
//	char s2 = '2';
//	int ret1 = isupper(s1);
//	int ret2 = isdigit(s2);
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);*/
//	
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}


struct S
{
	char name[20];
	int age;
};

void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;

	assert(dest);
	assert(src);

	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//
//c���Ա�׼
//memcpy   ֻҪ����  ���ص����ڴ濽���Ϳ���
//memmove  �����ص��ڴ�Ŀ���
//


//int main()
//{
//	/*int arr1[] = { 1,2,3,4,5 };
//	int arr2[5] = { 0 };
//	memcpy(arr2, arr1,sizeof(arr1));*/
//	struct S s1[] = { {"����",20},{"����",30} };
//	struct S s2 [3] = {0};
//	my_memcpy(s2, s1, sizeof(s1));
//	return 0;
//}


void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (count--)
	{
		if (dest < src)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
		else
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 3, arr, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//memcmp


//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,5 };
//	int ret = memcmp(arr1, arr2,5);
//	printf("%d\n", ret);
//	return 0;
//}



//memset  �ڴ�����

//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);
//	return 0;
//}