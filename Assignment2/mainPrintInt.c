#include<stdio.h>
#include "myl.h"

int main(){

	char m[150];
	printf("Enter string to print\n");
	scanf ("%[^\n]%*c", m);
	int k=printStr(m);
	printf("length %d\n",k);

	int n;
	printf("Enter int to read\n");
	int p=readInt(&n);
	printf("return value %d\n",p);
	
	int x;
	printf("Enter int to print\n");
	scanf("%d",&x);
	int r=printInt(x);
	printf("length %d\n",r);

	float s;
	printf("Enter float to read\n");
	int pq=readFlt(&s);
	printf("return value %d\n",pq);

	float pr;
	printf("Enter float to print\n");
	scanf("%f",&pr);
	int cv=printFlt(pr);
	printf("length %d\n",cv);

	return 0;
}
