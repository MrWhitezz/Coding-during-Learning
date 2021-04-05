#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
struct Polynomial
{
	int xishu;//系数
	int zhishu;//指数
	Polynomial *next;
};

struct node
{
	int xishu;
	int zhishu;
};
node arr[10000];

Polynomial InitPolynomial(const char *str)
{
	int i = 0, k = 0;
	int flag;
	Polynomial *head = NULL, *p = NULL, *q = NULL, *ptr, *h = NULL;//head:链表头结点；p：当前正在处理的结点
	Polynomial t;
	while (str[i] != '\0')
	{
		// 每次运行到这里时都是一个新的项的开始，比如 +2x^5，一次循环处理一项
		// 新的项可能是多项式的第一个项，也可能是上一个项已经处理完毕了
		if (head == NULL) {
			// 是多项式的第一个项
			head = new Polynomial();
			p = head;
		}
		else {
			// 不是第一个项，说明此时p是上一个项的结点
			p->next = new Polynomial();
			p = p->next;
		}
		if (str[i] == '+')
		{
			flag = 1;
			i++;
			// 系数是正的
		}
		else {
			flag = 0;
			i++;
			// 系数是负
		}

		if (flag == 1)
		{
			int tmp = 0;
			for (; str[i] != 'x'; i++)
			{
				tmp = tmp * 10 + (str[i] - '0');
			}
			p->xishu = tmp;
		}
		else if (flag == 0)
		{
			int tmp = 0;
			for (; str[i] != 'x'; i++)
			{
				tmp = tmp * 10 + (str[i] - '0');
			}
			p->xishu = -tmp;
		}
		//在这里解析系数并保存到p->xishu中
	// 此时str[i]是'x'，需要加2以跳过"x^"
		i += 2;

		int tmp = 0;
		for (; str[i] != '+' && str[i] != '-' && str[i] != '\0'; i++)
		{
			tmp = tmp * 10 + (str[i] - '0');
		}
		p->zhishu = tmp;
		// 在这里解析指数，并保存在p->zhishu中，过程类似于系数
	}

	// 先别管排序，确保上面的步骤正确了再加排序

	//试一下排序
	//接下来按指数从大到小排列

	p = head;//zxn
	for (; p->next != NULL; k++)
	{
		arr[k].zhishu = p->zhishu;
		arr[k].xishu = p->xishu;
      p = p->next;
   }
   int ArSize = k;// notice that you need to memory k for the Size of the arr
   //冒泡排序来完成降序排列
	bool exchange;
	while (k > 1)
	{
		exchange = false;
		for (int num = 0; num < k - 1; num++)
		{
			if (arr[num].zhishu < arr[num + 1].zhishu)
			{
				node temp = arr[num];
				arr[num] = arr[num + 1];
				arr[num + 1] = temp;
				exchange = true;
			}
		}
		if (!exchange)
			break;
		k--;
	}

   head->xishu = arr[0].xishu;
   head->zhishu = arr[0].zhishu;
   head->next = NULL;

	// for (int l = 0; l < ArSize; l++)
	// {
	// 	ptr = head;
	// 	q->zhishu = arr[l].zhishu;
	// 	q->xishu = arr[l].xishu;
	// 	while (ptr->next != NULL)
	// 		ptr = ptr->next;
	// 	q->next = ptr->next;
	// 	ptr->next = q;
	// } //previous code
   
   //Here is new code
   ptr = head;
   for (int l = 0; l < ArSize; l++)// here we use the Size of arr
   {
      Polynomial *p = new Polynomial;
      p->zhishu = arr[l].zhishu;
      p->xishu = arr[l].xishu;
      p->next = NULL;
      ptr->next = p;
      ptr = p;
   }

   return *head;
}

void PrintPolynomial(const Polynomial &poly)
{
	cout << "The answer is: ";
	for (const Polynomial *p = &poly; p != NULL; p = p->next) {
		if (p->xishu > 0)
			cout << "+";
		if (p->xishu == 0)
			p = p->next;
		cout << p->xishu << "x" << "^" << p->zhishu;//打印
	}
	cout << endl;
}

int main()
{
	Polynomial poly1 = InitPolynomial("+20x^4-4x^2+1x^1+2x^0");
	PrintPolynomial(poly1);
	return 0;
}
