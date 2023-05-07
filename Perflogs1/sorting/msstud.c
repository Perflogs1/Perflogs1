#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[100];
    int roll_no;
    float marks;
};
struct student s[100];
int swap_m=0;
int selectionsort(struct student s[],int n)
{
    struct student temp;
    int i,j,min;
    int swap=0;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(s[j].roll_no<s[min].roll_no)
            {
                min=j;
            }
        }
        temp=s[i];
        s[i]=s[min];
        s[min]=temp;
        swap++;
    }
}

void merge(struct student s[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    struct student l[n1],r[n2];
    for(int i=0;i<n1;i++)
    {
      l[i]=s[low+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=s[mid+1+j];
    }
    
    int i,j,k;
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(l[i].roll_no<=r[j].roll_no)
        {
            s[k]=l[i];
            i++;
        }
        else
        {
            s[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        s[k]=l[i];
        i++;
        k++;
        swap_m++;
    }
    while(j<n2)
    {
        s[k]=r[j];
        j++;
        k++;
        swap_m++;
    }
}

void mergesort(struct student s[],int low,int high)
{
    if(low<high)
    {
       int mid=low+(high-low)/2;
        mergesort(s,low,mid);
        mergesort(s,mid+1,high);
        merge(s,low,mid,high);
    }
}

void printstructure(struct student s[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Info of student %d \n",i+1);
        printf("Name: %s \n",s[i].name);
        printf("Roll no: %d \n",s[i].roll_no);
        printf("Marks: %.2f \n",s[i].marks);
    }
}

int main()
{
    int n;
    printf("Enter the no of records you want to enter: ");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter info for student %d \n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter roll no: ");
        scanf("%d",&s[i].roll_no);
        printf("Enter marks: ");
        scanf("%f",&s[i].marks);
    }
    int swaps=selectionsort(s,n);
    printf("SELECTION SORT \n");
    printf("The no of swaps performed: %d \n",swaps);
    printstructure(s,n);
    printf("MERGE SORT \n");
    mergesort(s,0,n-1);
    printf("The no of swaps performed: %d \n",swap_m);
    printstructure(s,n);
    
    
    return 0;
    
}

