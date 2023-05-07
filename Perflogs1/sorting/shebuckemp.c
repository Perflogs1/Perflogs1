#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
    char name[100];
    int emp_id;
    double salary;
};
struct employee e[100];
int swap_s=0;
int swap_b=0;
void shellsort(struct employee e[],int n)
{
    int i,j,k;
    struct employee temp;
    for(i=n/2;i>0;i=i/2)
    {
        for(j=1;j<n;j++)
        {
            for(k=j-1;k>=0;k=k-i)
            {
                if(e[k+1].emp_id>=e[k].emp_id)
                {
                    break;
                }
                else
                {
                    temp=e[k];
                    e[k]=e[k+i];
                    e[k+i]=temp;
                    swap_s++;
                }
            }
        }
    }
}

void printstructure(struct employee e[],int n)
{
    printf("Info details of every employee: \n");
    for(int i=0;i<n;i++)
    {
        printf("Name of employee: %s \n",e[i].name);
        printf("Employee id of employee: %d \n",e[i].emp_id);
        printf("Salary of employee: %.2lf \n",e[i].salary);
    }
    printf("\n");
}


void bucketsort(struct employee e[],int n)
{
    struct employee buckets[100];
    for(int i=0;i<100;i++)
    {
        buckets[i].emp_id=-1;
        strcpy(buckets[i].name," ");
        buckets[i].salary=-1;
    }
    for(int i=0;i<n;i++)
    {
        int index=buckets[i].emp_id-1;
        if(buckets[i].emp_id==-1)
        {
            buckets[index]=e[i];
            swap_b++;
        }
        else
        {
            for(int j=index+1;j<100;j++)
            {
                if(buckets[j].emp_id==-1)
                {
                    buckets[j]=e[i];
                    break;
                }
            }
        }
    }
}

int main()
{
    
     int n;
    printf("Enter the number of records you want to enter: \n");
    scanf("%d",&n);
    struct employee e[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter info for employee %d \n",i+1);
        printf("Enter name: ");
        scanf("%s",e[i].name);
        printf("Enter the employee id: ");
        scanf("%d",&e[i].emp_id);
        printf("Enter the salary: ");
        scanf("%lf",&e[i].salary);
    }
   
       printf("SHELL SORT \n");
    shellsort(e,n);
    printf("the no of swaps perfomed: %d \n",swap_s);
    printstructure(e,n);
    
    printf("BUCKET SORT \n");
    bucketsort(e,n);
    printf("the no of swaps perfomed: %d \n",swap_b);
    printstructure(e,n);
    return 0;
    return 0;
}


