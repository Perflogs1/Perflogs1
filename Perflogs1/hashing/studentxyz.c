#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
struct student{
    int id;
    long PRN;
    int rollno;
    char name[100];
    char year[50];
};
struct student hashtable[size];

void init()
{
    for(int i=0;i<size;i++)
    {
        hashtable[i].id=-1;
        hashtable[i].PRN=0;
        hashtable[i].rollno=0;
        strcpy(hashtable[i].name," ");
        strcpy(hashtable[i].year," ");
    }
}

void insert(int id,long PRN,int rollno,char *name,char *year)
{
    int index=id%size;
    int i=0;
    while(hashtable[index].id!=-1)
    {
        index=(id+(++i))%size;
    }
    hashtable[index].id=id;
    hashtable[index].PRN=PRN;
    hashtable[index].rollno=rollno;
    strcpy(hashtable[index].name,name);
    strcpy(hashtable[index].year,year);
}

void display()
{
    for(int i=0;i<size;i++)
    {
        printf("Index: %d \n",i);
        printf("ID: %d \n",hashtable[i].id);
        printf("PRN no: %ld \n",hashtable[i].PRN);
        printf("Roll no: %d \n",hashtable[i].rollno);
        printf("Student Name: %s \n",hashtable[i].name);
        printf("Year: %s \n",hashtable[i].year);
    }
}

int main()
{
    int n;
    printf("Enter the size of the students: ");
    scanf("%d",&n);
    //struct student hashtable[n];
    int id,rollno;
    long PRN;
    char name[50],year[50];
    printf("Enter student details: \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter ID: ");
        scanf("%d",&id);
        printf("Enter PRN no: ");
        scanf("%ld",&PRN);
        printf("Enter Roll no: ");
        scanf("%d",&rollno);
        printf("Enter name: ");
        scanf("%s",name);
        printf("Enter Year: ");
        scanf("%s",year);
        insert(id,PRN,rollno,name,year);
    }
    
    display();
    return 0;
}
