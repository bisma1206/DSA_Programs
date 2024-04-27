#include<stdio.h>
int add(int n1,int n2);
void main()
{
    int a,b;
    int sum;
    printf("enter values for 'a' and 'b' >");
    scanf("%d %d",&a,&b);
    sum=add(a,b);
    printf("%d+%d=%d",a,b,sum);
}
int add(int n1,int n2)
{
    return n1+n2;
}