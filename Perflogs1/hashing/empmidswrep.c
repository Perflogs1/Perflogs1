#include <stdio.h>
#include <stdlib.h>
int data[30], flag[30], chain[30];
int size;
int insert(int x)
{
int start;
int count = 0;
int i, j;
start = x % size;
if (flag[start] == 0)
{
data[start] = x;
flag[start] = 1;
}
else if (data[start] % size == x % size)
{
j = start;
while (flag[j] == 1 && count < size)
{
j = (j + 1) % size;
count++;
}
if (count == size)
{
printf("Hash Table is Full\n");
return 0;

}
while (chain[start] != -1)
{
start = chain[start];
}
data[j] = x;
flag[j] = 1;
chain[start] = j;
}
else
{
j = start;
count = 0;
while (flag[j] == 1 && count < size)
{
j = (j + 1) % size;
count++;
}
if (count == size)
{
printf("Hash Table is Full\n");
return 0;
}
i = data[start] % size;
while (chain[i] != start)
{
i = chain[i];
}
chain[i] = chain[start];
while (chain[i] != -1)
{
i = chain[i];
}
data[j] = data[start];
flag[j] = 1;
chain[i] = j;
data[start] = x;
chain[start] = -1;
}
return 0;
}
void display()
{
for (int i = 0; i < size; i++)
{
if (flag[i] == 1)
{

printf("%d %d %d\n", i, data[i], chain[i]);
}
else
{
printf("%d ----- %d\n", i, chain[i]);
}
}
}
int main()
{
int opt;
printf("Enter the size of Hash Table: \n");
scanf("%d", &size);
for (int i = 0; i < size; i++)
{
flag[i] = 0;
chain[i] = -1;
}
while (1)
{
printf("\nPress 1. Insert\t 2. Display \t 4. Exit \n");
scanf("%d", &opt);
switch (opt)
{
case 1:
int x;
printf("Enter the data which is to be inserted: \n");
scanf("%d", &x);
insert(x);
break;
case 2:
display();
break;
case 4:
exit(0);
}
}
}