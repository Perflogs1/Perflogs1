#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct faculties{
    char name[30];
    int empid;
    char desi[30];
};
int i = 0;
struct faculties temp[12];
struct faculties faculties1[] =  {
        {"Professor A",1233, "Professor"},
        {"Associate Professor B", 1231,"Associate Professor"},
        {"Assistant Professor C", 3221,"Assistant Professor"},
        {"Professor D", 1231,"Professor"},
        {"Associate Professor E", 4354,"Associate Professor"},
        {"Assistant Professor F", 1111,"Assistant Professor"},
        {"Assistant Professor G",3123,"Assistant Professor"},
        {"Associate Professor H", 1245,"Assistant Professor"},
        {"Professor I",3432, "Professor"},
        {"Assistant Professor J",1234, "Assistant Professor"},
        {"Associate Professor K",1232, "Associate Professor"},
        {"Professor L",1254, "Professor"}
    };
     void proff(){
        for(i ; i<12; i++){
          for(int j = 0; j<12; j++){
            if(strcmp(faculties1[j].desi, "Professor" ) == 0){
                temp[i] = faculties1[j];
                faculties1[j].desi[0] = '\0';
                i++;
                return;
            }
          }
           return;
         }

     }
    void assoc(){
        for(i; i<12; i++ ){
          for(int j = 0; j<12; j++){
            if(strcmp(faculties1[j].desi, "Associate Professor" )== 0){
               temp[i] = faculties1[j];
               faculties1[j].desi[0] = '\0';
               i++;
               return;
            }
     }
     return;
    }
    }
     void assis(){
        for(i ; i<12; i++){
          for(int j = 0; j<12; j++){
            if(strcmp(faculties1[j].desi, "Assistant Professor" ) == 0){
                temp[i] = faculties1[j];
                faculties1[j].desi[0] = '\0';
                i++;
                return;
            }
          }
          return;
         }

     }

 void sort(){
     int c = 0;
     while(c< 12){
    proff();
    assoc();
    assis();
    assis();
    assoc();
    assis();
    assis();
    c++;
     }
     return;

    }

int main(){
    sort();
    for(int i = 0; i < 12; i++){
      faculties1[i] = temp[i];
    }
        for(int i = 0; i < 12; i++){
        printf(" %s %d %s \n", faculties1[i].name, faculties1[i].empid, faculties1[i].desi);
    }

}
