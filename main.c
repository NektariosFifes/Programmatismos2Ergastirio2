#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTUDENTS 100

#include <stdbool.h>

//!!!!!!!!!GLOBAL DATA


struct DataMathitis {
    int AM;
    char onoma[MAXSTUDENTS];
    int bathmos;
};
//DEN TO BAZO MAIN GT THE EINAI STO SCOPE TOU MAIN
typedef struct DataMathitis InfoMathiti ;
InfoMathiti info[100];
bool brethikeTOam;
int ThesiKapouNatoBaloANexiXORO;
int indexx=0;
//!!!!!!!!GLOBAL DATA
void print_menu(){
    printf(" Choose from 1 to 4:");
    printf("1. Add new student");
    printf(" 2. Delete student by AM");
    printf(" 3. Print all students");
    printf(" 4. Quit");
}

int find_student(int Am) {


    for (int k = 0; k < MAXSTUDENTS; k++) {
        if (info[k].AM == Am) {
            brethikeTOam = true;
            ThesiKapouNatoBaloANexiXORO = k;
        }
    }
    if(brethikeTOam!=true){
            ThesiKapouNatoBaloANexiXORO = indexx++;
    }

}
void add_new_student(){
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
    ThesiKapouNatoBaloANexiXORO = 0;
    find_student(Am);

    info[ThesiKapouNatoBaloANexiXORO].AM = Am;
    info[ThesiKapouNatoBaloANexiXORO].bathmos = bathmos;
    for(int o=0; o< sizeof(onomateponimo);o++){
        info[ThesiKapouNatoBaloANexiXORO].onoma[o] = onomateponimo[o];
    }
    //allios strcpy(info[ThesiKapouNatoBaloANexiXORO].onoma, onomateponimo);

}



void delete_student(){
    int Am;
    printf("DOSE AM  \n");
    scanf("%d",&Am);

    bool BrethikeToPrama =false;
    find_student(Am);

    if(!BrethikeToPrama){
        printf("DEn sE bRiKa");
    }
}
void print_students(){
    for(int i=0; i<100 ; i++){
        if(info[i].AM != -1) {
            printf("%d\t%s\t%d\n", info[i].AM, info[i].onoma, info[i].bathmos);
        }
    }
}


int main() {


    //ARXIKOPOIISI
    for(int i=0; i<MAXSTUDENTS;i++){
        info[i].AM = -1;
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
                add_new_student();
                break;
            case '2':
                delete_student();
                break;
            case '3':
                print_students();
                //printf("3");
                break;
            case '4':
                run = 0;
                break;
        }

    }


    return 0;
}
