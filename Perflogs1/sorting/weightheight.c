#include<stdio.h>
#include<stdlib.h>
#define size 100
struct employee{
    char name[100];
    float weight;
    float height;
    float avg;
};
void bubblesort(struct employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
        e[i].avg=(e[i].weight+e[i].height)/2.0;
    }
    struct employee temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(e[j].avg>e[j+1].avg)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}

void printstructure(struct employee e[],int n)
{
    printf("The employee details \n");
    for(int i=0;i<n;i++)
    {
        printf("Name: %s \n",e[i].name);
        printf("Weight: %.2f \n",e[i].weight);
        printf("Height: %.2f \n",e[i].height);
        printf("Average: %.2f \n",e[i].avg);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct employee e[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter employee details \n");
        printf("Enter the name: ");
        gets(&e[i].name);
        gets(&e[i].name);
        printf("Enter the height: ");
        scanf("%f",&e[i].height);
        printf("Enter the weight: ");
        scanf("%f",&e[i].weight);
    }
    
    bubblesort(e,n);
    printstructure(e,n);
    return 0;
}


