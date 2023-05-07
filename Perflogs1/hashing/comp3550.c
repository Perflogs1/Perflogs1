#include<stdio.h>
#include<stdlib.h>
#define MAX_STUDENTS 14
#define MAX_COMPUTERS 15

int hashfunction(int key)
{
    return (key%MAX_COMPUTERS)+36;
}

int main()
{
    int hashtable[MAX_COMPUTERS][2];
    int i=1;
    int roll;
    int k=36;
    for(int j=0;j<MAX_COMPUTERS;j++)
    {
        hashtable[j][0]=k;
        hashtable[j][1]=0;
        k++;
    }
    
    while(i<=MAX_STUDENTS)
    {
        printf("Enter th roll no of student %d: ",i);
        scanf("%d",&roll);
        int res=hashfunction(roll);
        hashtable[res-36][1]=roll;
        i++;
    }
    for(int i=0;i<MAX_COMPUTERS;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",hashtable[i][j]);
        }
        printf("\n");
    }
    int n;
    printf("Enter the no of students absent: ");
    scanf("%d",&n);
    i=1;
    while(i<=n)
    {
        printf("Enter the  %d roll no: ",i);
        scanf("%d",&k);
        for(int i=0;i<MAX_COMPUTERS;i++)
        {
            if(hashtable[i][1]==k)
            {
                hashtable[i][1]=0;
            }
            
        }
        i++;
    }
    k=1;
    int roll1;
    printf("Enter the no of students from new batch: ");
    scanf("%d",&n);
    while(k<=n)
    {
        printf("Enter the %d roll no: ",k);
        scanf("%d",&roll1);
        int temp=hashfunction(roll1);
        if(hashtable[temp-36][1]==0)
        {
            hashtable[temp-36][1]=roll1;
        }
        else
        {
            i=temp-36+1;
            while(i%MAX_COMPUTERS!=temp-36)
            {
                if(hashtable[i%MAX_COMPUTERS][1]==0)
                {
                    hashtable[i%MAX_COMPUTERS][1]=roll1;
                    break;
                }
                i++;
            }
        }
        k++;
    }
    printf("\n Final table is: \n");
    for(int i=0;i<MAX_COMPUTERS;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",hashtable[i][j]);
        }
        printf("\n");
    }
    return 0;
}

