#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ssn[10],name[20],dept[10],desg[10],phno[15];
    int sal;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *nodepointer;
nodepointer temp,first=NULL,end=NULL;
nodepointer getnode()
{
    nodepointer x;
    x=(nodepointer)malloc(sizeof(struct node));
    return x;
}
void read()
{
    temp=getnode();
    temp->llink=NULL;
    temp->rlink=NULL;
    printf("Enter the ssn\n");
    scanf("%s",temp->ssn);
    printf("Enter the name\n");
    scanf("%s",temp->name);
    printf("Enter the department\n");
    scanf("%s",temp->dept);
    printf("Enter the designation\n");
    scanf("%s",temp->desg);
    printf("Enter the phone number\n");
    scanf("%s",temp->phno);
    printf("Enter the salary\n");
    scanf("%d%*c",&temp->sal);
}
void createdll()
{
    int n,i;
    printf("Enter the number of employees\n");
    scanf("%d%*c",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the details of employees %d\n",i);
        read();
        if(first==NULL)
        {
            first=temp;
            end=temp;
        }
        else
        {
             end->rlink=temp;
             temp->llink=end;
             end=temp;

        }
    }
}
void displaycount()
{
    int count=0;
    nodepointer temp1=first;
    if(first==NULL)
        printf("DLL is empty and count is %d\n",count);
    else 
    {
        printf("\n____________________________________________________\n");
        printf("\nssn\tname\t\tdept\tdesg\tphno\t\tsal\n");
        printf("\n_____________________________________________________\n");
        while(temp1!=NULL)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%d\n",temp1->ssn,temp1->name,temp1->dept,temp1->desg,temp1->phno,temp1->sal);
            count++;
            temp1=temp1->rlink;
        }
        printf("\n____________________________________________________\n");
        printf("Employee count is %d\n",count);
    }
}
void insertend()
{
    temp=getnode();
    printf("Enter the details of new employee\n");
    read();
    if(first==NULL)
    {
        first=temp;
        end=temp;
    }
    else
    {
        end->rlink=temp;
        temp->llink=end;
        end=temp;
    }
}
void deleteend()
{
    nodepointer temp1=end;
    if(temp1==NULL)
    {
        printf("DLL is empty\n");
    }
    else if(first==end)
    {
        printf("The deleted element is with ssn %s\n",temp1->ssn);
        first=NULL;
        end=NULL;
        free(temp1);
    }
    else
    {
        printf("The deleted element is with ssn %s\n",temp1->ssn);
        end=end->llink;
        end->rlink=NULL;
        free(temp1);
    }
}
void insertfront()
{
    printf("Enter the details of employee\n");
    read();
    if(first==NULL)
    {
        first=temp;
        end=temp;
    }
    else
    {
        temp->rlink=first;
        first->llink=temp;
        first=temp;
    }
}
void deletefront()
{
    nodepointer temp1=first;
    if(first==NULL)
        printf("DLLmis empty\n");
    else if (first==end)
    {
        printf("The deleted element is with ssn %s\n",temp1->ssn);
        first=NULL;
        end=NULL;
        free(temp1);
    }
    else
    {
        printf("The deleted element is with the ssn %s\n",temp1->ssn);
        first=first->rlink;
        first->llink=NULL;
        free(temp1);
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("Double Linked List\n");
        printf("MENU\n1.Create\t2.Display and Count\t3.Insert End\t4.Delete End\t5.Insert Front\t6.Delete Front\t7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d%*c",&ch);
        switch(ch)
        {
            case 1: createdll();
                    break;
            case 2: displaycount();
                    break;
            case 3:insertend();
                    break;
            case 4: deleteend();
                    break;
            case 5: insertfront();
                    break;
            case 6: deletefront();
                    break;
            case 7: exit(0);
            default: printf("Enter the valid choice\n");
        }

    }
    return 0;
}
