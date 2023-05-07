#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[100];
    int emp_id;
    double salary;
};
struct employee e[100];
int swap_h=0;
int swap_m=0;
void heapify(struct employee e[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    struct employee temp;
    while(left<n && e[left].emp_id>e[largest].emp_id)
    {
        largest=left;
    }
    while(right<n && e[right].emp_id>e[largest].emp_id)
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
    struct employee temp;
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(e,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        temp=e[0];
        e[0]=e[i];
        e[i]=temp;
        swap_h++;
        heapify(e,i,0);
    }
}

void merge(struct employee e[],int low,int mid,int high)
{
    
    int n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    struct employee l[n1],r[n2];
    for(int i=0;i<n1;i++)
    {
        l[i]=e[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=e[mid+1+j];
    }
    
    int i,j,k;
    i=j=0;
    k=low;
    while(i<n1&& j<n2)
    {
        if(l[i].emp_id<=r[j].emp_id)
        {
           e[k]=l[i];
           i++;k++;
        }
        else
        {
            e[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        e[k]=l[i];
        i++;
        k++;
        swap_m++;
    }
    while(j<n2)
    {
        e[k]=r[j];
        j++;
        k++;
        swap_m++;
    }
    
}

void mergesort(struct employee e[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergesort(e,low,mid);
        mergesort(e,mid+1,high);
        merge(e,low,mid,high);
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
   
       printf("HEAP SORT \n");
    heapsort(e,n);
    printf("the no of swaps perfomed: %d \n",swap_h);
    printstructure(e,n);
    
    printf("MERGE SORT \n");
    mergesort(e,0,n-1);
    printf("the no of swaps perfomed: %d \n",swap_m);
    printstructure(e,n);
    
    
    return 0;
    
}
