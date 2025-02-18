#include<stdio.h>
void adminSettings();
void userSettings();

typedef struct{
    char Id[100];
    char Name[100];
    unsigned int age;
    char address[100];
    char acountType[100];

}account;


int main(){
    int chouce =0;
    while(1){
    printf("1.Admin Moode\n");
    printf("2.User Moode\n");
    printf("3.Quit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1 :
        adminSettings();
        break;
        case 2 :
        userSettings();
        break;
        default :
        printf("Invalid choice!\n");

    }
}



}

void adminSettings(){
    int chouce =0;
    printf("1.create account\n");
    printf("3.update account\n");
    printf("2.delete account\n");
    printf("3.Diplay info of User\n");
    
    

   

}

void userSettings(){

}