
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
/**************** incluse section *****************/

#ifndef TYPEDEF_H_
#define TYPEDEF_H_
typedef unsigned char u8;
typedef char s8;
typedef unsigned long int u32;
typedef long int s32;
typedef unsigned short int u16;
typedef short int s16;
typedef unsigned long long int u64;
typedef void U;
typedef float f32;
typedef double f64;
#endif

/**************** Typedef *****************/
#define MAX_USER 100
#define MAX_LOANS 100
#define MAX_AMOUNT_PER_TRANSACTION 100000
#define n 10 // time of writing
/*************** macros. section *************/
typedef struct
{
    u32 Id; /*Id of user*/ // انا عدلت id بدل ما كان array علشان اعرف اعمل check عليه في كل الfunction بسهوله
    u8 Name[100];          /*name of user*/
    u32 age;               /*of user*/
    u8 address[100];       /*address of user*/
    u8 acountType[100];    /*Savings/Checking*/
    u32 password;          /*of user*/
    u64 balance;
    u32 complain[500];
    u64 phoneNumber;

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
    f32 years;
} loan;

account accounts[MAX_USER]; // array of accounts
loan loans[MAX_LOANS];      // array of loans
u16 complainName[MAX_USER];

/**************Global variables***************/
U adminSettings();
U Admin_LogIn(char ID[]);
U createAccount();
//============================================ update and its functions =====================================================
U updateAccount();
U Idcheck(u8 index);
u8 Namecheck(u8 index);
U Addresscheck(u8 index);
U Agecheck(u8 index);
U Acccheck(u8 index);
U Balancecheck(u8 index);
U Passcheck(u8 index);
//===========================================================================================================================
U deleteAccount();
U displayUserInfo();
U loanInformation();
U scheduleLoans();
U supportSection();
U systemFace();
u8 checkIfPossible();
/**************Admin functions  Prototype**********/
U userSettings();
U User_Login(void);
U depositCash();
U withdrawCash();
U checkBalance();
U cashTransfer();
U applyForLoan();
U trackingLoan();
U customerSupport();
s8 search1(seark);
int (*ptr)(U);
U delay(const char *text, int Delay);
u16 stringcheck(char arr[100]);
/**************User functions  Prototype**********/
