#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[100];
    int emp_id;
    double salary;
};
struct employee e[100];
int swap_h=0;
void bubblesort(struct employee e[],int n)
{
    int swap=0;
    struct employee temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
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
    printf("the no of swaps perfomed: %d \n",swap);
}

void heapify(struct employee e[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    struct employee temp;
    if(left<n && e[left].emp_id>e[largest].emp_id)
    {
        largest=left;
    }
    if(right<n && e[right].emp_id>e[largest].emp_id)
    {
        largest=right;
    }
    if(largest!=i)
    {
        temp=e[i];
        e[i]=e[largest];
        e[largest]=temp;
        swap_h++;
        heapify(e,n,largest);
    }
}

void heapsort(struct employee e[],int n)
{
    int i;
    struct employee temp;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(e,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        temp=e[0];
        e[0]=e[i];
        e[i]=temp;
        swap_h++;
        heapify(e,i,0);
    }
}

void printstructure(struct employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Information of employee %d \n",i+1);
        printf("Name: %s \n",e[i].name);
        printf("Employee id: %d \n",e[i].emp_id);
        printf("Salary: %.2lf \n",e[i].salary);
    }
    printf("\n");
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
    printf("BUBBLE SORT \n");
    bubblesort(e,n);
    printstructure(e,n);
    
    printf("HEAP SORT \n");
    heapsort(e,n);
    printf("the no of swaps perfomed: %d \n",swap_h);
    printstructure(e,n);
    
    return 0;
    
}
