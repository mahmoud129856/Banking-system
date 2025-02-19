#include <stdio.h>
#include <string.h>
/**************** incluse section *****************/

#ifndef TYPEDEF_H_
#define TYPEDEF_H_
typedef unsigned char u8;
typedef char s8;
typedef unsigned long int u32;
typedef long int s32;
typedef unsigned short int u16;
typedef short int s16;
#endif

/**************** Typedef *****************/
#define MAX_USER 100
#define MAX_LOANS 100
/*************** macros. section *************/
typedef struct
{
    u32 Id; /*Id of user*/ // انا عدلت id بدل ما كان array علشان اعرف اعمل check عليه في كل الfunction بسهوله
    u8 Name[100];          /*name of user*/
    u8 age;                /*of user*/
    u8 address[100];       /*address of user*/
    u8 acountType[100];    /*Savings/Checking*/
    u32 password;          /*of user*/
    u32 balance;

} account;

typedef struct
{
    u32 bank_id;         // هنا ضفت bank id علشان اعرف اخزن الloan علي الحساب بتاعه
    u32 loan_id;         // وطبعا لازم يكون فيه id loan علشان لو عاوز اعمل check عليه
    u8 name[100];        // user who asked for loan
    u8 reason[800];      // raason for loan
    u8 type;             // Savings/Checking
    u32 money_loan;      // هنا الفلوس المطلوبه من القرض
    float interest_rate; //%5هنا هخزن الفايده وانت بتعمل القرض بتاعك وهعرضها علي المستخدم الي عاوز يعمل قرض وهنخليها
    u8 duration_months;  // هنخزن هنا المده الي لازم نسدد فيها القرض وهنخليها علي سنتين اقل حاجه
    u32 remaning_balanc;
} loan;

account accounts[MAX_USER]; // array of accounts
loan loans[MAX_LOANS];      // array of loans

u16 userCount = 0; // number of users in system
u16 loancount = 0; // هنا ضفت عدد الloan الي في ال array بتاعتي علشان تسهل عليه عمليت الcheck بردو
/**************Global variables***************/

void adminSettings();
void userSettings();
void adminLogin();
void userLogin();
void createAccount();
void updateAccount();
void deleteAccount();
void displayUserInfo();
void loanInformation();
void scheduleLoans();
void supportSection();
void systemFace();
void depositCash();
void withdrawCash();
void checkBalance();
void cashTransfer();
void applyForLoan();
void trackingLoan();
void customerSupport();

/**************functions  Prototype**********/
