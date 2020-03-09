#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTUDENTS 100

#include <stdbool.h>
 struct DataMathitis {
    int AM;
    char onoma[MAXSTUDENTS];
     int bathmos;
};
///DEN TO BAZO MAIN GT THE EINAI STO SCOPE TOU MAIN
typedef struct DataMathitis InfoMathiti ;
void print_menu(){
    printf(" Choose from 1 to 4:");
    printf("1. Add new student");
    printf(" 2. Delete student by AM");
    printf(" 3. Print all students");
    printf(" 4. Quit");
}
void add_new_student(InfoMathiti info[MAXSTUDENTS]){
    int Am;
    char onomateponimo[100];
    int bathmos;
    printf("DOSE AM RE \n");
    scanf("%d",&Am);
    printf("DOSE onomateponimo\n");
    scanf("%s",&onomateponimo);  //fgets(onomateponimo , MAXSTUDENTS , stdin);
    printf("poso pires \n");
    scanf("%d",&bathmos);

    int brethikeTOam = false;
    int ThesiKapouNatoBaloANexiXORO;
    for(int k =0 ; k<MAXSTUDENTS ; k++){
        if(info[k].AM == Am){
            brethikeTOam = true;
            ThesiKapouNatoBaloANexiXORO = k;
        }

        if(info[k].AM == -1 && brethikeTOam==false){
         ThesiKapouNatoBaloANexiXORO = k;
        }


    }

    info[ThesiKapouNatoBaloANexiXORO].AM = Am;
    info[ThesiKapouNatoBaloANexiXORO].bathmos = bathmos;
    strcpy(info[ThesiKapouNatoBaloANexiXORO].onoma, onomateponimo);

}
void delete_student(InfoMathiti info[MAXSTUDENTS]){
    int Am;
    printf("DOSE AM  \n");
    scanf("%d",&Am);

    bool BrethikeToPrama =false;
    for(int j=0; j <MAXSTUDENTS ; j++) {

        if(info[j].AM == Am){
            info[j].AM = -1;
            BrethikeToPrama = true;
            break;

        }
    }

    if(!BrethikeToPrama){
        printf("DEn sE bRiKa");
    }
}
void print_students(InfoMathiti info[MAXSTUDENTS]){
 for(int i=0; i<MAXSTUDENTS ; i++){
     if(info[i].onoma != NULL) {
         printf("AM: %d ONOMATEPONIMO:%s Bthmos:%d ", info[i].AM, info[i].onoma, info[i].bathmos);
     }
 }
}

int find_student( int AM ){

}
int main() {

        InfoMathiti info[100];

        //ARXIKOPOIISI
        for(int i=0; i<MAXSTUDENTS;i++){
            info[1].AM = -1;
        }


        int run = 1;
        char choice;
        // INITIALIZE GLOBAL ARRAY HERE !!!
        while (run) {
            print_menu();
            do {
                scanf("%c", &choice);
            } while (choice < '1' || choice > '4');
            switch (choice) {
                case '1':
                    add_new_student(info);
                    break;
                case '2':
                    delete_student(info);
                    break;
                case '3':
                    print_students(info);
                    break;
                case '4':
                    run = 0;
                    break;
            }

        }


        return 0;
    }
