// 共享栈
// 请设计两个顺序栈共享一个存储空间形成的共享栈，
// 完成共享栈的入栈、出栈和判断栈空、输出等四个函数，
// 并在主函数调用以上基本函数进行测试。
#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 12

typedef struct {
	int data[MAXSIZE];
	int top1;
	int top2;
} Dstack;

void initstack(Dstack **s) {
	*s = (Dstack *)malloc(sizeof(Dstack));
	(*s)->top1 = -1;
	(*s)->top2 = MAXSIZE;
}

void empty(Dstack *s) {
	if (s->top1 == -1) {
		printf("stack1:empty\n");
	}
	if (s->top2 == MAXSIZE) {
		printf("stack2:empty\n");
	}
}

void push1(Dstack *s, int n) {
	if (s->top1 == s->top2 - 1) {
		printf("full");
	}
	int i;
	int e = 1;
	for (i = 0; i < n; i++) {
		if (n % 2 != 0) {
			s->top1++;
			s->data[s->top1] = e;
		}
	}
}

void push2(Dstack *s, int n)
{
	if (s->top1 == s->top2 - 1)
	{
		printf("full");
	}
	int i;
	int e = 0;
	for (i = 0; i < n; i++)
	{
		if (n % 2 == 0)
		{
			s->top2--;
			s->data[s->top2] = e;
		}
	}
}

void pop1(Dstack *s, int e)
{
	if (s->top1 == -1)
	{
		printf("NULL");
	}
	e = s->data[s->top1];
	s->top1--;
}

void pop2(Dstack *s, int e)
{
	if (s->top2 == MAXSIZE)
	{
		printf("NULL");
	}
	e = s->data[s->top2];
	s->top2++;
}

void shuchu1(Dstack *s)
{
	int i = 0;
	int x = 0;
	while (s->top1 == -1)
	{
		x = s->data[s->top1];
		s->top1--;
		printf("stack1:%d", x);
	}
	printf("\n");
}

void shuchu2(Dstack *s)
{
	int i = 0;
	int x = 0;
	while (s->top2 == MAXSIZE)
	{
		x = s->data[s->top2];
		s->top2++;
		printf("stack2:%d", x);
	}
	printf("\n");
}

int main()
{
	Dstack *s = NULL;
	initstack(*s);
	empty(s);
	int n = 0;
	int e1 = 0, e2 = 0;
	scanf("%d", &n);
	push1(s, n);
	push2(s, n);
	pop1(s, e1);
	pop2(s, e2);
	shuchu1(s);
	shuchu2(s);
}