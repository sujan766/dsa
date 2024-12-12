#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date
{
int dd;
int mm;
int yy;
};
struct calender
{
char day[20];
struct date dmy;
char activity[50];
};
struct calender *cal;
void create();
void read();
void display();
int main()
{
create();
read();
display();
return 0;
}
void create()
{
cal=(struct calender*)malloc(7*sizeof(struct calender));
}
void read()
{
int i;
printf("Enter the details of calender\n");
for(i=0;i<7;i++)
{
printf("Enter the details of day %d\n",i+1);
printf("Enter the day:");
scanf("%s",(cal+i)->day);
printf("Enter the day in dd mm yyyy format:");
scanf("%d%d%d*c",&(cal+i)->dmy.dd,&(cal+i)->dmy.mm,&(cal+i)->dmy.yy);
printf("Enter the activity");
scanf("%s",(cal+i)->activity);
}
}
void display()
{
int i;
printf("Weekly Activity details report are as follows:\n");
printf("Day\tDate\t\tActivity\n");
for(i=0;i<7;i++)
{
printf("%s\t %d-%d-%d\t\t %s\n",(cal+i)->day,(cal+i)->dmy.dd,(cal+i)->dmy.mm,(cal+i)->dmy.yy,(cal+i)->activity);
}
}
