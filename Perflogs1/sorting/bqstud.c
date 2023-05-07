#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[100];
    int roll_no;
    float marks;
};
struct student s[100];
int bubblesort(struct student s[],int n)
{
    struct student temp;
    int swap=0;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].roll_no>s[j+1].roll_no)
            {
                swap++;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    return swap;
}


int partition(struct student s[],int low,int high)
{
    struct student pivot=s[low];
    int i=low+1;
    int j=high;
    int swap=0;
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
    }while(i<j);
    temp=s[low];
    s[low]=s[j];
    s[j]=temp;
    swap++;
    printf("The no of swaps are %d \n",swap);
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
        printf(" Name: %s \n",s[i].name);
        printf("Roll no: %d \n",s[i].roll_no);
        printf("Marks: %.2f \n",s[i].marks);
    }
}
int main()
{
    int n;
    printf("Enter the no of records you want to enter \n");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter the roll no: ");
        scanf("%d",&s[i].roll_no);
        printf("Enter the marks: ");
        scanf("%f",&s[i].marks);
    }
    
    
    
    printf("1-Bubble Sort \n");
    int swaps=bubblesort(s,n);
    printf("The total swaps performed %d \n",swaps);
    printstructure(s,n);

    printf("Quick sort \n");
    quicksort(s,0,n-1);
   
    printstructure(s,n);
    return 0;
}


