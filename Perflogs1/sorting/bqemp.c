#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[100];
    int emp_id;
    double salary;
};

struct employee e[100];
int swap_q=0;
int bubblesort(struct employee e[],int n)
{
    struct employee temp;
    int i,j;
    int swap=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(e[j].emp_id>e[j+1].emp_id)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
                swap++;
            }
        }
    }
    return swap;
}

int partition(struct employee e[],int low,int high)
{
    struct employee pivot=e[low];
    int i=low+1;
    int j=high;
    struct employee temp;
    do{
        while(e[i].emp_id<=pivot.emp_id)
        {
            i++;
        }
        while(e[j].emp_id>pivot.emp_id)
        {
            j--;
        }
        if(i<j)
        {
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
            swap_q++;
        }
    }while(i<j);
    temp=e[low];
    e[low]=e[j];
    e[j]=temp;
    swap_q+=1;
    return j;
}

void quicksort(struct employee e[],int low,int high)
{
    int index;
    if(low<high)
    {
        index=partition(e,low,high);
        quicksort(e,0,high-1);
        quicksort(e,low+1,high);
    }
}

void printstructure(struct employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Info of employee: %d \n",i+1);
        printf("Name: %s \n",e[i].name);
        printf("Employee id: %d \n",e[i].emp_id);
        printf("Salary: %.2lf \n",e[i].salary);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the no of records you want to enter \n");
    scanf("%d",&n);
    struct employee e[n];
     for(int i=0;i<n;i++)
    {
        printf("Enter info of employee %d \n",i+1);
        printf("Name: ");
        scanf("%s",e[i].name);
        printf("Employee id: ");
        scanf("%d",&e[i].emp_id);
        printf("Salary: ");
        scanf("%lf",&e[i].salary);
    }
    int s=bubblesort(e,n);
    printf("The no of swaps perfomed %d \n",s);
    printstructure(e,n);
    
    quicksort(e,0,n-1);
    printf("The no of swaps perfomed %d \n",swap_q);
    printstructure(e,n);
    
    return 0;
}

