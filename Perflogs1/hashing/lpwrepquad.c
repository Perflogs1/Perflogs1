#include<stdio.h>
#include<stdlib.h>


int hashFunction(int key,int n){
    return key%n;
}

void printHashTable(int hashTable[][3],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("%d ",hashTable[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int hashTable[n][3];
    for(int i=0;i<n;i++){
        hashTable[i][0]=i;
        hashTable[i][1]=0;
        hashTable[i][2]=-1;
    }
    printHashTable(hashTable,n);
    int k;
    printf("Enter the no. of keys(less than or equal to n): ");
    scanf("%d",&k);
    printf("For linear probing: 1, For Quadratic probing: 2");
    int choice;
    scanf("%d",&choice);
    int c;
    int key;
    switch(choice){
        case 1:
            c=1;
            while(c<=k){
                printf("Enter the %d(th/nd/rd/st) key: ",c);
                scanf("%d",&key);
                int res = hashFunction(key,n);
                if(hashTable[res][1]==0){
                    hashTable[res][1]=key;
                }else{
                    if(hashTable[res][1]%n==res){
                        int i=res+1;
                        while(i%n!=res){
                            if(hashTable[i%n][1]==0){
                                hashTable[i%n][1]=key;
                                hashTable[res][2]=hashTable[i%n][0];
                                break;
                            }
                            i++;
                        }
                    }else{
                        int temp=hashTable[res][1];
                        hashTable[res][1]=key;
                        int i=res+1;
                        while(i%n!=res){
                            if(hashTable[i%n][1]==0){
                                hashTable[i%n][1]=temp;
                                hashTable[temp%n][2]=i%n;
                                break;
                            }
                            i++;
                        }            
                    }
                }
                c++;
            }
            break; 
        
        case 2:
            c=1;
            while(c<=k){
                printf("Enter the %d(th/nd/rd/st) key: ",c);
                scanf("%d",&key);
                int res = hashFunction(key,n);
                if(hashTable[res][1]==0){
                    hashTable[res][1]=key;
                }else{
                    int i=1;
                    while(hashTable[(res+i*i)%n][1]!=0){
                        i+=1;
                    }
                    hashTable[(res+i*i)%n][1]=key;
                }
                c++;
            }
            break;
        default: 
            printf("Enter a valid option");
    }
    // int c=1;
    // int key;
    // while(c<=k){
    //     printf("Enter the %d(th/nd/rd/st) key: ",c);
    //     scanf("%d",&key);
    //     int res = hashFunction(key,n);
    //     if(hashTable[res][1]==0){
    //         hashTable[res][1]=key;
    //     }else{
    //         if(hashTable[res][1]%n==res){
    //             int i=res+1;
    //             while(i%n!=res){
    //                 if(hashTable[i%n][1]==0){
    //                     hashTable[i%n][1]=key;
    //                     hashTable[res][2]=hashTable[i%n][0];
    //                     break;
    //                 }
    //                 i++;
    //             }
    //         }else{
    //             int temp=hashTable[res][1];
    //             hashTable[res][1]=key;
    //             int i=res+1;
    //             while(i%n!=res){
    //                 if(hashTable[i%n][1]==0){
    //                     hashTable[i%n][1]=temp;
    //                     hashTable[temp%n][2]=i%n;
    //                     break;
    //                 }
    //                 i++;
    //             }            
    //         }
    //     }
    //     c++;
    // }
    printf("\n");
    printHashTable(hashTable,n);
}