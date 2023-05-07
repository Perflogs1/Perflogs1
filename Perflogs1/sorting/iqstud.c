#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[100];
    int roll_no;
    float marks;
};
struct student s[100];
int swap=0;
int swap1=0;
int partition(struct student s[],int low,int high)
{
    struct student pivot=s[low];
    int i=low+1;
    int j=high;
    struct student temp;
    do{
        while(s[i].roll_no<=pivot.roll_no)
        {
            i++;
        }
        while(s[j].roll_no>pivot.roll_no)
        {
            j--;
        }
        if(i<j)
        {
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            swap++;
        }
    }while(i<=j);
    temp=s[low];
    s[low]=s[j];
    s[j]=temp;
    swap++;
    
    return j;
}

void quicksort(struct student s[],int low,int high)
{
    int index;
    if(low<high)
    {
        index=partition(s,low,high);
        quicksort(s,0,index-1);
        quicksort(s,index+1,high);
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
    printf("\n");
}

int insertionsort(struct student s[],int n)
{
    struct student temp;
    int i,j;
    int swap1=0;
    for(i=1;i<n;i++)
    {
        temp=s[i];
        j=i-1;
        while(j>=0 && s[j].roll_no>temp.roll_no)
        {
            s[j+1]=s[j];
            swap1++;
            j--;
        }
        s[j+1]=temp;
    }
   
}
int main()
{
    int n;
    printf("Enter the no of records you want to enter \n");
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
    
    quicksort(s,0,n-1);
    printf("QUICK SORT \n");
    printf("The no of swaps performed are %d \n",swap);
    printstructure(s,n);
    printf("INSERTION SORT \n");
    int swap2=insertionsort(s,n);
    printf("The no of swaps performed are %d \n",swap2);
    printstructure(s,n);
    return 0;
}
