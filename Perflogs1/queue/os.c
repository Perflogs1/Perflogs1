#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct queue{
int size;
int f;
int r;
int *arr;
int asize;
};
int isFull(struct queue *q){
if(q->r == q->size-1){
return 1;
}
return 0;
}
int isEmpty(struct queue *q){
if(q->r == q->f){
return 1;

}
return 0;
}
void enqueue(struct queue *q, int val){
if(isFull(q)){
printf("This queue is full");
}
else{
q->r++;
q->arr[q->r] = val;
q->asize++;
}
}
int dequeue(struct queue *q){
int a = -1;
if(isEmpty(q)){
printf("This queue is Empty");
}
else{
q->f++;
a = q->arr[q->f];
q->asize--;
}
return a;
}
void addJob(struct queue *q){
srand ( time(NULL) );
for(int i=1; i<11; i++){
int pages = rand() % 50 + 1;
enqueue(q, pages);
printf("Assigned Job %d with pages %d \n", i, pages);
}
}
void sortQueue(struct queue *q)
{
for (int i = 0; i < q->asize; i++)
{
for(int j = i+1; j<q->asize; j++){
int temp = 0;
if((q->arr[i]) > (q->arr[j])){
int temp = q->arr[i];
q->arr[i] = q->arr[j];
q->arr[j] = temp;
}

}
}
}
void onePrinter(struct queue *q){
float time = 0;
for(int i=0; i<q->asize; i++){
printf("Printer 1 printed job %d of pages %d\n", i+1, q->arr[i]);
time = time + q->arr[i];
}
time = time/10;
printf("Time Required using one printer : %.2f min\n", time);
}
void twoPrinters(struct queue *q){
float time1 = 0;
float time2 = 0;
int i = 0;
while(i < q->asize){
int temp = 0;
if(i < q->asize){
printf("Printer 1 printed job %d of pages %d\n", i+1, q->arr[i]);



time1 = time1 + q->arr[i];
temp++;
}
if(i+1 < q->asize){
printf("Printer 2 printed job %d of pages %d\n", (i+1)+1, q->arr[i+1]);



time2 = time2 + q->arr[i+1];
temp++;
}
i += temp;
}
if(time1>=time2){
printf("Time Required using two printer : %.2f min\n", time1/10);
}
else if(time2>=time1){
printf("Time Required using two printer : %.2f min\n", time2/10);
}
// printf("%f %f \n", time1, time2);
}
void threePrinters(struct queue *q){
float time1 = 0;
float time2 = 0;
float time3 = 0;
int i = 0;

while(i < q->asize){
int temp = 0;
if(i < q->asize){
printf("Printer 1 printed job %d of pages %d\n", i+1, q->arr[i]);



time1 = time1 + q->arr[i];
temp++;
}
if(i+1 < q->asize){
printf("Printer 2 printed job %d of pages %d\n", (i+1)+1, q->arr[i+1]);



time2 = time2 + q->arr[i+1];
temp++;
}
if(i+2 < q->asize){
printf("Printer 3 printed job %d of pages %d\n", (i+2)+1, q->arr[i+2]);



time3 = time3 + q->arr[i+2];
temp++;
}
i += temp;
}
if(time1>=time2 && time1>=time3){
printf("Time Required using three printer : %.2f min\n",

time1/10);
}
else if(time2>=time1 && time2>=time3){
printf("Time Required using three printer : %.2f min\n",

time2/10);
}
else if(time3>=time1 && time3>=time2){
printf("Time Required using three printer : %.2f min\n",

time3/10);
}
// printf("%f %f %f \n", time1, time2, time3);
}
int main() {
struct queue q;
q.size = 100;
q.asize = 0;
q.f = 0;
q.r = -1;
q.arr = (int*) malloc(q.size*sizeof(int));
// enqueue
addJob(&q);

// printf("%d\n", q.asize);
// printf("%d\n", q.r);
// printf("Before Sorting\n");
// while(isEmpty(&q)==0){
// printf("%d\n", q.arr[q.f]);
// dequeue(&q);
// }
sortQueue(&q);
// printf("After Sorting\n");
// while(isEmpty(&q)==0){
// printf("%d\n", q.arr[q.f]);
// dequeue(&q);
// }
printf("One Printer\n");
onePrinter(&q);
printf("Two Printers\n");
twoPrinters(&q);
printf("Three Printers\n");
threePrinters(&q);
return 0;
}
