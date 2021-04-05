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

Polynomial InitPolynomial(const char *str)
{
	int i = 0;
	int flag;
	Polynomial *head = NULL, *p = NULL; //head:链表头结点；p：当前正在处理的结点
	Polynomial t;
	Polynomial *q;
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
	while (p != NULL)
	{
		if (head->next != NULL)
		{
			if (head->xishu == 0)
				p = head;
			else
				p = head->next;
			while (p->next != NULL && p->next->xishu != 0 && p->xishu < p->next->xishu)
			{
				t = *p;
				p = p->next;
				*p->next = t;
			}
			if (p->next != NULL)
			{
				if (p->zhishu == p->next->zhishu)
					p->next->xishu += p->xishu;
				if (p->next->xishu == 0)
				{
					q = p->next;
					p->next = q->next;
					delete q;
				}
			}
		}
		else
		{
			head->xishu = p->xishu;
			head->zhishu = p->zhishu;
		}
	}

	return *head;
}

void PrintPolynomial(const Polynomial &poly)
{
	cout << "结果为：";
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