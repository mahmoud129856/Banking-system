#include "HeaderFiles.h"

extern u16 userCount;
extern u16 loancount;
/************** User function *******************/
void userSettings()
{
    u8 choice;
    while (1)
    {
        printf("1.deposits cash\n");
        printf("2.withdrawals cash\n"); // اتاكد ان الرقم اللي هيتسحب ده موجود اصلا ومش مخالف للحد الاقصي للسحب
        printf("3.check balance\n");
        printf("4.cash transfer\n");    // اتأكد من ان المبلغ المبعوت موجود اصلا في الحساب وان المبلغ مسموح يتبعت
        printf("5.apply for loan\n");   // هيظهر جدول ل كل القروض الموجوده في النظالم وهو يختار منهم اللي ىناسبه
        printf("6.tracking loan\n");    // بيشوف الفلوس اللي اتدفعت من القرض والفلوس المتبقه عليه للبنك
        printf("7.Customer Support\n"); // مش بيعمل اكتر من انه بيكتب مسدج ونخزنها منه
        printf("8.go back\n");
        printf("9.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            depositCash();
            break;
        case 2:
            withdrawCash();
            break;
        case 3:
            checkBalance();
            break;
        case 4:
            cashTransfer();
            break;
        case 5:
            applyForLoan();
            break;
        case 6:
            trackingLoan();
            break;
        case 7:
            customerSupport();
            break;
        case 8:
            systemFace();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
/***************** add money *******************/
void depositCash()
{
}
/***************** take off money *******************/
void withdrawCash()
{
}
/***************** show the money *******************/
void checkBalance()
{
}
/***************** send money *******************/
void cashTransfer()
{
    u32 form_id, to_id;
    u8 from_index = 0, to_index = 0;
    u32 amount;

    printf("hello in the transfer money serves\n ");

    printf("\nenter your id: ");
    scanf("%d", &form_id);
    printf("enter the id beneficiary: ");
    scanf("%d", &to_id);
    printf("enter the mount of transfer money:");
    scanf("%d", &amount);
    for (int i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == to_id)
        {
            to_index = i;
        }
        if (accounts[i].Id == form_id)
        {
            from_index = i;
        }
    }
    if (from_index = 0)
    {
        printf("your id not found\n");
        cashTransfer();
    }
    if (to_index = 0)
    {
        printf("the id beneficiary not found\n");
        cashTransfer();
    }
    if (accounts[from_index].balance < amount)
    {
        printf("the mony in your account not enough\n");
        cashTransfer();
    }
    accounts[from_index].balance -= amount;
    accounts[to_index].balance += amount;
    printf("transfer successful\n");
    printf("/*////////////////////////////////////////*/\n");
    u8 Case;
    printf("if you want to continue enter:1\n");
    printf("if you want to exist enter :2\n");

    switch (Case)
    {
    case 1:
        userSettings();
        break;
    case 2:
        return;
        break;
    default:
        printf("the number you  entered incorrect");
        break;
    }
}
/***************** choose loan from schedual *******************/
void applyForLoan()
{
}
/***************** track the installments *******************/
void trackingLoan()
{
    u32 id_loan, id_account;

    printf("hello in traking loan serves for user \n");
    printf("\n/*///////////////////////////*/\n");
    printf("enter your bank id\n");
    scanf("%d", &id_account);
    printf("enter the loan id\n");
    scanf("%d", &id_loan);
    u8 i = 0;
    for (i; i < loancount; i++)
    {
        if ((loans[i].bank_id == id_account) && (loans[i].loan_id == id_loan))
        {
            printf("your name:%s\naccount_id:%d\n loan_id:%d\n amount:%d\n remaning:%d\n duration at month:%d", loans[i].name, loans[i].bank_id, loans[i].loan_id, loans[i].money_loan, loans[i].remaning_balanc, loans[i].duration_months);
        }
    }
    if (i == loancount)
    {
        printf("incorrect account id or loan id ");
        u8 count;
        printf("if you want to try again enter :1\n");
        printf("if you want to exist enter :2\n");
        printf("if you want to go to home enter :3\n");
        printf("enter your chose:");
        scanf("%d", &count);
        switch (count)
        {
        case 1:
            trackingLoan();
            break;
        case 2:
            return;
            break;
        case 3:
            userSettings();
            break;
        default:
            printf("the number you enter in correct ");
            break;
        }
    }
}
/***************** write a massage from user *******************/
void customerSupport(void)
{

    u32 A;
    u8 choice;
    printf("Please ,Enter your ID: \n ");
    scanf("%d", &A);
    for (u8 i = 0; i <= userCount; i++)
    {
        if (A == accounts[i].Id)
        {

            printf("Please, Add your complaints ! \n");
            fflush(stdin);
            gets(accounts[i].complain);

            printf("\n");

            printf("*************** Thanks for your Note ***************");
            printf("1.Back\n2.Exit");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                userSettings();
                break;
            case 2:
                return;
            default:
                printf("invaild choice!");
            }
        }
        else
        {
            printf("invaild user!");
        }
    }
}
