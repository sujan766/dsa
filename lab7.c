#include<stdio.h>
#include<stdlib.h>

struct node
{
char usn[15],name[20],branch[10],phno[15];
int sem;
struct node *link;
};
typedef struct node *nodepointer;
nodepointer temp,first=NULL;
nodepointer getnode()
{
nodepointer x;
x=(nodepointer)malloc(sizeof(struct node));
return x;
}
void read()
{
temp=getnode();
temp->link=NULL;
printf("Enter the usn\n");
scanf("%s",temp->usn);
printf("Enter the name\n");
scanf("%s",temp->name);
printf("Enter the branch\n");
scanf("%s",temp->branch);
printf("Enter the phone number\n");
scanf("%s",temp->phno);
printf("Enter the semester\n");
scanf("%d%*c",&temp->sem);
}
void createsll()
{
int n,i;
printf("Enter the number of students\n");
scanf("%d%*c",&n);
for(i=1;i<=n;i++)
{
printf("Enter the details of students %d\n",i);
read();
if(first==NULL)
first=temp;
else
{
temp->link=first;
first=temp;
}
}
}
void display()
{
int count=0;
nodepointer temp1=first;
printf("Student details are as follows:\n");
if(temp1==NULL)
{
printf("The student details list is empty and count=%d\n",count);
}
else
{
printf("\n________________________________________________\n");
printf("\nUSN\t\tNAME\t\tBRANCH\t\tPHONE\t\tSEM\n");
printf("\n_________________________________________________\n");
while(temp1!=NULL)
{
printf("%s\t%s\t%s\t\t%s\t%d\n",temp1->usn,temp1->name,temp1->branch,temp1->phno,temp1->sem);
count++;
temp1=temp1->link;
}
printf("\n____________________________________________________\n");
printf("Student count=%d\n",count);
}
}
void insertfront()
{
printf("Enter the details of new student to be inserted\n");
read();
if(first==NULL)
first=temp;
else
{
temp->link=first;
first=temp;
}
}
void deletefront()
{
nodepointer temp1=first;
if(temp1==NULL)
{
printf("SLL is empty\n");
}
else
{
printf("The deleted node is of the student usn %s\n",temp1->usn);
first=temp1->link;
free(temp1);
}
}
void insertend()
{
nodepointer last=first;
printf("Enter the details of new student to be inserted\n");
read();
if(last!=NULL)
{
while(last->link!=NULL)
{
last=last->link;
}
last->link=temp;
}
else first=temp;
}
void deleteend()
{
nodepointer temp1=first,pre=NULL;
if(temp1==NULL)
{
printf("SLL is empty\n");
}
else if(temp1->link==NULL)
{
printf("The deleted node is of the student usn %s\n",temp1->usn);
free(temp1);
first=NULL;
}
else
{
while(temp1->link!=NULL)
{
pre=temp1;
temp1=temp1->link;
}
pre->link=NULL;
printf("The deleted element is %s\n",temp1->usn);
free(temp1);
}
}
int main()
{
int ch;
while(1)
{
printf("Single Linked List\n");
printf("MENU\n 1.Create\t 2.Display\t 3.Insert Front\t 4.Delete Front\t 5.Insert End\t 6.Delete End\t 7.Exit\n");
printf("Enter your choice\n");
scanf("%d%*c",&ch);
switch(ch)
{
case 1: createsll();
	break;
case 2: display();
	break;
case 3: insertfront();
	break;
case 4: deletefront();
	break;
case 5: insertend();
	break;
case 6: deleteend();
	break;
case 7: exit(0);
default: printf("Enter a valid choice\n");
}
}
return 0;
}
