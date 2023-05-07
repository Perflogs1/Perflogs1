#include<stdio.h>
#include<stdlib.h>
#define MAX_COMPUTERS 10
#define MAX_STUDENTS 10

int hashfunction(int key)
{
    return (key%MAX_COMPUTERS)+21;
}

void printhashtable(int hashtable[][3])
{
    for(int i=0;i<MAX_COMPUTERS;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",hashtable[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int hashtable[MAX_COMPUTERS][3];
    for(int i=0;i<MAX_COMPUTERS;i++)
    {
        hashtable[i][0]=21+i;
    }
    for(int i=0;i<MAX_COMPUTERS;i++)
    {
        hashtable[i][2]=-1;
    }
    
    int c=1;
    int roll;
    while(c<=MAX_STUDENTS)
    {
        printf("Enter the roll no of students: ");
        scanf("%d",&roll);
        int res=hashfunction(roll);
        hashtable[res-21][1]=roll;
        c++;
    }
    printhashtable(hashtable);
    int k=1;
    while(k<=3)
    {
        printf("Enter the roll no of %d(st/nd/th) absent student: ", k);
        scanf("%d",&roll);
        for(int i=0;i<MAX_COMPUTERS;i++)
        {
            if(hashtable[i][1]==roll)
            {
                hashtable[i][1]=0;
            }
        }
        k++;
    }
    printhashtable(hashtable);
    k=1;
    while(k<=3)
    {
        printf("Enter the roll no of %d(st/nd/th) student from another batch: ", k);
        scanf("%d", &roll);
        int temp=hashfunction(roll);
        if(hashtable[temp-21][1]==0)
        {
            hashtable[temp-21][1]=roll;
        }
        else
        {
            if(hashtable[temp-21][1]%MAX_COMPUTERS==temp-21)
            {
                int i=temp-21+1;
                while(i%MAX_COMPUTERS!=temp-21)
                {
                    if(hashtable[i%MAX_COMPUTERS][1]==0)
                    {
                        hashtable[i%MAX_COMPUTERS][1]=roll;
                        hashtable[temp - 21][2] = hashtable[i % MAX_COMPUTERS][0];
                        break;
                    }
                    i++;
                }
            }
            else
            {
                int temp1 = hashtable[temp - 21][1];
                hashtable[temp - 21][1] = roll;
                int p = temp - 21 + 1;
                while(p % MAX_COMPUTERS != temp - 21){
                    if(hashtable[p % MAX_COMPUTERS][1] == 0){
                        hashtable[p % MAX_COMPUTERS][1] = temp1;
                        hashtable[temp1 % MAX_COMPUTERS][2] = p % MAX_COMPUTERS;
                        break;
                    }
                }   p++;
            }
        }
        k++;
    }
    printhashtable(hashtable);
    return 0;
}
