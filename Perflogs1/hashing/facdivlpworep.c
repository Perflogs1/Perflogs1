#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#define MAX 10
struct faculty{
    int id;
    char name[100];
    char department[100];
    char designation[100];
};
struct faculty hashtable[MAX];
void init()
{
    for(int i=0;i<MAX;i++)
    {
        hashtable[i].id=-1;
        strcpy(hashtable[i].name," ");
        strcpy(hashtable[i].department," ");
        strcpy(hashtable[i].designation," ");
    }
}

void insert(int id,char *name,char *department,char *designation)
{
    int index=id%MAX;
    int i=0;
    while(hashtable[index].id!=-1)
    {
        index=(id+(++i))%MAX;
    }
    hashtable[index].id=id;
    strcpy(hashtable[i].name,name);
    strcpy(hashtable[i].department,department);
    strcpy(hashtable[i].designation,designation);
    
}


int search(int id)
{
    int index=id%MAX;
    int i=0;
    while(hashtable[index].id!=id)
    {
        if(hashtable[i].id==-1)
        {
            return -1;
        }
        index=(id+(++i))%MAX;
    }
    return index;
}

void display()
{
    printf("Faculty details are: \n");
    for(int i=0;i<MAX;i++)
    {
        printf("Index: %d \n",i);
        printf("ID: %d \n",hashtable[i].id);
        printf("Name: %s \n",hashtable[i].name);
        printf("Department: %s \n",hashtable[i].department);
        printf("Designation: %s \n",hashtable[i].designation);
        printf("Chaining: %d \n",hashtable[i].id%MAX);
    }
}


int main()
{
    init();
    int i;
    int choice=0;
    while(1)
    {
        printf("The menu choices are: \n");
        printf("1-Insert details of the faculty \n");
        printf("2-Search the details of the faculty \n");
        printf("3-Display details of the faculty \n");
        printf("4-Exitting the program \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                int id;
                char name[20], department[20], designation[20];
                printf("\nEnter faculty ID: ");
                scanf("%d", &id);
                printf("Enter faculty name: ");
                fflush(stdin);
                gets(name);
                gets(name);
                // scanf("%s", name);
                printf("Enter faculty department: ");
                scanf("%s", department);
                printf("Enter faculty designation: ");
                fflush(stdin);
                gets(designation);
                gets(designation);
                // scanf("%s", designation);
                insert(id, name, department, designation);
            break;
            }
            case 2:
            int id;
            printf("Enter the index/key to be searched: ");
            scanf("%d",&id);
            int index=search(id);
            if(index==-1)
            {
                printf("Record not found \n");
            }
            else
            {
                printf("Faculty with ID %d found at : %d \n",id,index);
                printf("Name: %s \n",hashtable[index].name);
                printf("Department: %s \n",hashtable[index].department);
                printf("Designation: %s \n",hashtable[index].designation);
            }
            break;
            
            case 3:
            printf("Displaying all details: \n");
            display();
            break;
            
            case 4:
            exit(1);
            break;
            
            default:
            printf("Invalid choice,enter again \n");
            break;
            
        }
    }
    return 0;
}


