#include<stdio.h>
#include<stdlib.h>
struct faculty{
    char name[100];
    int id;
    char code[100];
    char class[100];
};
struct faculty f[100];
int swap_q=0;
int insertionsert(struct faculty f[],int n)
{
    struct faculty temp;
    int swap=0;
    int j;
    for(int i=1;i<n;i++)
    {
        temp=f[i];
        j=i-1;
        while(j>=0 && f[j].id>temp.id)
        {
            swap++;
            f[j+1]=f[j];
            j--;
        }
        f[j+1]=temp;
    }
}
int partition(struct faculty f[],int low,int high)
{
    struct faculty pivot=f[low];
    struct faculty temp;
    int i=low+1;
    int j=high;
    do{
        while(f[i].id<=pivot.id)
        {
            i++;
        }
        while(f[j].id>pivot.id)
        {
            j--;
        }
        if(i<j)
        {
            temp=f[i];
            f[i]=f[j];
            f[j]=temp;
            swap_q++;
        }
    }while(i<j);
    temp=f[low];
    f[low]=f[j];
    f[j]=temp;
    swap_q+=1;
    return j;
}

void quicksort(struct faculty f[],int low,int high)
{
    int index;
    if(low<high)
    {
        index=partition(f,low,high);
        quicksort(f,0,index-1);
        quicksort(f,index+1,high);
    }
}

void printstructure(struct faculty f[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Info of faculty: %d \n",i+1);
        printf("Name: %s \n",f[i].name);
        printf("Employee id: %d \n",f[i].id);
        printf("Class code: %s \n",f[i].code);
        printf("Class: %s \n",f[i].class);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the no of records you want to enter \n");
    scanf("%d",&n);
    struct faculty f[n];
     for(int i=0;i<n;i++)
    {
        printf("Enter info of faculty %d \n",i+1);
        printf("Name: ");
        scanf("%s",f[i].name);
        printf("Employee id: ");
        scanf("%d",&f[i].id);
        printf("Class code: ");
        scanf("%s",f[i].code);
        printf("Class: ");
        scanf("%s",f[i].class);
    }
    printf("INSERTION SORT \n");
    int s=insertionsert(f,n);
    printf("The no of swaps perfomed %d \n",s);
    printstructure(f,n);
    printf("QUICK SORT \n");
    quicksort(f,0,n-1);
    printf("The no of swaps perfomed %d \n",swap_q);
    printstructure(f,n);
    
    return 0;
}

