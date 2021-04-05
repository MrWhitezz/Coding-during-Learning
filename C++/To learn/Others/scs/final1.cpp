#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
struct Polynomial
{
	int xishu;//ϵ��
	int zhishu;//ָ��
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
	Polynomial *head = NULL, *p = NULL, *q = NULL, *ptr��*h = NULL;//head:����ͷ��㣻p����ǰ���ڴ����Ľ��
	Polynomial t;
	Polynomial *q;
	while (str[i] != '\0')
	{
		// ÿ�����е�����ʱ����һ���µ���Ŀ�ʼ������ +2x^5��һ��ѭ������һ��
		// �µ�������Ƕ���ʽ�ĵ�һ���Ҳ��������һ�����Ѿ����������
		if (head == NULL) {
			// �Ƕ���ʽ�ĵ�һ����
			head = new Polynomial();
			p = head;
		}
		else {
			// ���ǵ�һ���˵����ʱp����һ����Ľ��
			p->next = new Polynomial();
			p = p->next;
		}
		if (str[i] == '+')
		{
			flag = 1;
			i++;
			// ϵ��������
		}
		else {
			flag = 0;
			i++;
			// ϵ���Ǹ�
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
		//���������ϵ�������浽p->xishu��
	// ��ʱstr[i]��'x'����Ҫ��2������"x^"
		i += 2;

		int tmp = 0;
		for (; str[i] != '+' && str[i] != '-' && str[i] != '\0'; i++)
		{
			tmp = tmp * 10 + (str[i] - '0');
		}
		p->zhishu = tmp;
		// ���������ָ������������p->zhishu�У�����������ϵ��
	}

	// �ȱ������ȷ������Ĳ�����ȷ���ټ�����

	//��һ������
	//��������ָ���Ӵ�С����
	for (; p->next != NULL; k++)
	{
		arr[k].zhishu = p->zhishu;
		arr[k].xishu = p->xishu;
	}
	//ð����������ɽ�������
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
	head->next = NULL;

	for (int l = 0; l < k; l++)
	{
		ptr = head;
		q->zhishu = arr[l].zhishu;
		q->xishu = arr[l].xishu;
		while (ptr->next != NULL)
			ptr = ptr->next;
		q->next = ptr->next;
		ptr->next = q;
	}

	return *head;
}

void PrintPolynomial(const Polynomial &poly)
{
	cout << "���Ϊ��";
	for (const Polynomial *p = &poly; p != NULL; p = p->next) {
		if (p->xishu > 0)
			cout << "+";
		if (p->xishu == 0)
			p = p->next;
		cout << p->xishu << "x" << "^" << p->zhishu;//��ӡ
	}
	cout << endl;
}

int main()
{
	Polynomial poly1 = InitPolynomial("+20x^4-4x^2+1x^1+2x^0");
	PrintPolynomial(poly1);
	return 0;
}