#include<stdio.h>
typedef struct
{
	int date[100];
	int lenth;
}Set;
void cset(Set &s,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		s.date[i]=a[i];
		s.lenth=n;
	}
}
void dispset(Set s)
{
	int i;
	for(i=0;i<s.lenth;i++)
		printf("%d ",s.date[i]);
	printf("\n");
}
int inset(Set s,int e)
{
	int i;
	int found=0;
	for(i=0;i<s.lenth;i++)
		if(s.date[i]==e)
		{
			found = 1;
			break;
		}
	return found;

}
void add(Set s1,Set s2,Set &s3)
{
	int i;
	for(i=0;i<s1.lenth;i++)
	s3.date[i]=s1.date[i];
	s3.lenth=s1.lenth;
	for(i=0;i<s2.lenth;i++)
	if(!inset(s1,s2.date[i] ))
	{
		s3.date[s3.lenth]=s2.date[i];
		s3.lenth++;
	}
}
void sub(Set s1,Set s2,Set &s3)
{
	s3.lenth=0;
	int i;
	for(i=0;i<s1.lenth;i++)
	if(!inset(s2,s1.date[i]))
	{
		s3.date[s3.lenth]=s1.date[i];
		s3.lenth++;
	}
}
void inter(Set s1,Set s2,Set &s3)
{
	s3.lenth=0;
	int i;
	for(i=0;i<s1.lenth;i++)
	if(inset(s2,s1.date[i]))
	{
		s3.date[s3.lenth]=s1.date[i];
		s3.lenth++;
	}
}
int main()
{
	int a[100],n1,i,b[100],n2,x;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	scanf("%d",&a[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	scanf("%d",&b[i]);
	scanf("%d",&x);
	Set s1,s2,s3;
	cset(s1,a,n1);
	cset(s2,b,n2);
	
	dispset(s1);
	dispset(s2);
	if(inset(s1,x)) 
		printf("found");
	else printf("not found");
	add(s1,s2,s3);
	dispset(s3);
	sub(s1,s2,s3);
	dispset(s3);
	inter(s1,s2,s3);
	dispset(s3);
	return 0;
}


