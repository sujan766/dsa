#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int m,n;
struct node
{
int coef;
int ex1,ex2,ex3;
struct node*link;
};
typedef struct node *ppointer;
ppointer a,b,c,temp;
int compare(int x1,int y1,int z1,int x2,int y2,int z2)
{
if((x1==x2)&&(y1==y2)&&(z1==z2))
return 0;
else if(x1>x2)
return 1;
else if(x1<x2)
return -1;
else if(y1>y2)
return 1;
else if(y1<y2)
return -1;
else if(z1>z2)
return 1;
else
return -1;
}
ppointer getnode()
{
ppointer x;
x=(ppointer)malloc(sizeof(struct node));
return x;
}
ppointer attach(int c,int e1,int e2, int e3,ppointer head)
{
ppointer cur;
temp=getnode();
temp->coef=c;
temp->ex1=e1;
temp->ex2=e2;
temp->ex3=e3;
temp->link=NULL;
cur=head->link;
while(cur->link!=head)
{
cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}
ppointer add(ppointer heada,ppointer headb)
{
ppointer starta,startb,headc;
int sum=0,done=0,i=0,j=0;
starta=heada->link;
startb=headb->link;
headc=getnode();
headc->coef=headc->ex1=headc->ex2=headc->ex3=-1;
headc->link=headc;
do
{
switch(compare(starta->ex1,starta->ex2,starta->ex3,startb->ex1,startb->ex2,startb->ex3))
{
case 0: sum=starta->coef+ startb->coef;
if(sum)
headc=attach(sum,starta->ex1,starta->ex2,starta->ex3,headc);
starta=starta->link;
startb=startb->link;
i++;
j++;
if(starta==heada||startb==headb)
done=1;
break;
case 1:headc=attach(starta->coef,starta->ex1,starta->ex2,starta->ex3,headc);
starta=starta->link;
i++;
if(starta==heada)
done=1;
break;
case -1:headc=attach(startb->coef,startb->ex1,startb->ex2,startb->ex3,headc);
startb=startb->link;
j++;
if(startb==headb)
done=1;
break;
}
}
while(!done);
while(i<m)
{
headc=attach(starta->coef,starta->ex1,starta->ex2,starta->ex3,headc);
starta=starta->link;
i++;
}
while(j<n)
{
headc=attach(startb->coef,startb->ex1,startb->ex2,startb->ex3,headc);
startb=startb->link;
j++;
}
return headc;
}
void display(ppointer head)
{
ppointer temp1;
temp1=head->link;
if(temp1==head)
{
printf("\nThere are no terms in polynomial to display\n");
exit(0);
}
else
{
while(temp1!=head)
{
printf("%dx^%dy^%dz^%d",temp1->coef,temp1->ex1,temp1->ex2,temp1->ex3);
temp1=temp1->link;
if(temp1!=head)
printf("+");
}
}
}
int eval(ppointer head)
{
ppointer temp1;
int x,y,z,ans=0;
printf("\nEnter the value of x,y,z\n");
scanf("%d%d%d",&x,&y,&z);
temp1=head->link;
while(temp1!=head)
{
ans=ans+temp1->coef*pow(x,temp1->ex1)*pow(y,temp1->ex2)*pow(z,temp->ex3);
temp1=temp1->link;
}
return ans;
}
int main()
{
int ch,num,co,e1,e2,e3,i,j,result;
while(1)
{
ppointer heada,headb,headc,heade;
heada=getnode();
headb=getnode();
heade=getnode();
heada->coef=heada->ex1=heada->ex2=heada->ex3=-1;
headb->coef=headb->ex1=headb->ex2=headb->ex3=-1;
heade->coef=heade->ex1=heade->ex2=heade->ex3=-1;
heada->link=heada;
headb->link=headb;
heade->link=heade;
printf("\npolynomial operations\n1.Evaluation of polynomial 2.addition of two polynomial\n3.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the number of terms in the polybomial\n");
scanf("%d",&num);
for(i=0;i<num;i++)
{
printf("Enter the coeffient and three exponents ofx,y,z\n");
scanf("%d%d%d%d",&co,&e1,&e2,&e3);
heade=attach(co,e1,e2,e3,heade);
}
display(heade);
result=eval(heade);
printf("The value of polynomial is %d\n",result);
break;
case 2:printf("Enter the number of terms in polybomial a\n");
scanf("%d",&m);
for(i=0;i<m;i++)
{
printf("Enter the coefffient and three exponents of x,y and z\n");
scanf("%d%d%d%d",&co,&e1,&e2,&e3);
heada=attach(co,e1,e2,e3,heada);
}
printf("Enter the number of terms in polynomial b\n");
scanf("%d",&n);
for(j=0;j<n;j++)
{
printf("Enter the coefffient and three exponents of x,y and z\n");
scanf("%d%d%d%d",&co,&e1,&e2,&e3);
headb=attach(co,e1,e2,e3,headb);
}
printf("\n\npolynomial a is\n");
display(heada);
printf("\n\npolynomial b is\n");
display(headb);
headc=add(heada,headb);
printf("\n\nThe resulting polynomial c is\n");
display(headc);
break;
case 3:exit(0);
default:printf("Invalid choice\n");
}
}
return 0;
}

