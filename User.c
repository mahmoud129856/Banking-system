#include "HeaderFiles.h"

u8 USerIndex; // to share index of user on all functios
U User_Login(void)
{
    static int Account_ID;
    int Password;
    int Result = 0;
    int Flag = 0;
    int Flag1 = 0;
    int Flag2 = 0;
    int Flag3 = 0;
    int Choice = 0;
    int seark;

    printf("Welcome Back!!\n\n");
Label2:
    printf("Enter your ID:");
    scanf("%d", &seark);

    Account_ID = search1(seark);
    USerIndex = Account_ID;
    if (Account_ID < MAX_USER && Account_ID >= 0)
    {
        printf("valid Account!!\n\n");
    Label1:
        printf("Enter Your Account Password: ");

        scanf("%i", &Password);
        if (Password == accounts[Account_ID].password)

        {
            printf("Valid Password!!\n\n");
            userSettings();
        }
        else
        {
            printf("Invalid Password!!\n");

        Label:
            printf("[1] to Try again\n");
            printf("[2] to Exit\n\n");
            printf("Enter your Choice: ");
            fflush(stdin);
            scanf("%i", &Choice);

            switch (Choice)
            {
            case 1:
                Flag++;
                if (Flag < 3)
                {
                    goto Label1;
                }
                else
                {
                    ptr();
                }
                break;
            case 2:
                return (0);
                break;
            default:
                printf("Invalid Choice!!\n");
                Flag1++;
                if (Flag1 < 3)
                {
                    goto Label;
                }
                else
                {
                    return (0);
                }
                break;
            }
        }
    }
    else
    {
        int Choice = 0;

        printf("Invlide Account ID!!!\n\n");
    Label3:
        printf("[1] to Try Again\n");
        printf("[2] to Exit\n\n");

        printf("Enter Your Choice: ");
        fflush(stdin);
        scanf("%i", &Choice);
        switch (Choice)
        {
        case 1:
            Flag2++;
            if (Flag2 < 3)
            {
                goto Label2;
            }
            else
            {
                return (0);
            }
            break;
        case 2:
            return (0);
            break;
        default:
            printf("Invalid Choice!!\n\n");
            Flag3++;
            if (Flag3 < 3)
            {
                goto Label3;
            }
            else
            {
                return (0);
            }
        }
    }
}

/****************** user login ****************/
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

    u8 i, choice; // for check on them
    u64 z;

negative:
    printf("\n\n$Please,Enter the amount$ \n");
    scanf("%d", &z);
    if (z > 0 && z <= 100000)
    {
        accounts[USerIndex].balance += z;
        printf("Deposit Successful\n");
        printf("1.continue \n2.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            userSettings();
            break;
        case 2:
            return;
        }
    }
    else
    {
        printf("No money added ,the maximum amount '100.000' '100K' ,please try again! \n ");

        printf("1.try again \n2.choose another service\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            goto negative;
            break;
        case 2:
            userSettings();
        }
    }
}
/***************** take off money *******************/
void withdrawCash()
{

    int AccountID;
    int Password;
    int Balance = 0;
    int Flag = 0;
    int Flag1 = 0;
    int Flag2 = 0;
    int Flag3 = 0;
    int Flag4 = 0;
    int Choice = 0;

    AccountID = USerIndex;

Label3:
    printf("Enter The Amount of Money you want: ");
    scanf("%i", &Balance);
    if (checkIfPossible(Balance) == 1)
    {
        printf("Are you Sure you want to to withdraw this Money[Enter (1) if you Sure]: ");
        scanf("%i", &Choice);
        if (Choice == 1)
        {
            accounts[AccountID].balance -= Balance;
            printf("Successfull Operation!!\n");
            userSettings();
        }
        else
        {
            printf("Invalid Choice!!,Try Agian Later\n\n");
            userSettings();
        }
    }
    else
    {
        printf("Invalid, You don't have this money in you Account!!!\n");
        Flag3++;
        if (Flag3 < 3)
        {
            goto Label3;
        }
        else
        {
            userSettings();
        }
    }
}

/***************** show the money *******************/
void checkBalance()
{

    int index = USerIndex;
    printf("\n Account Information:\n");
    printf("===============================\n");
    printf(" Account Holder : %s\n", accounts[index].Name);
    printf(" Current Balance: %d EGP\n", accounts[index].balance);
    printf("===============================\n");
}
/***************** send money *******************/
void cashTransfer()
{
    u32 form_id, to_id;
    s8 from_index = USerIndex, to_index = -1;
    u32 amount;

    printf("hello in the transfer money serves\n ");

    printf("enter the id beneficiary: ");
    scanf("%d", &to_id);
    to_index = search1(to_id);
    printf("enter the mount of transfer money:");
    scanf("%d", &amount);
    if (to_index == -1)
    {
        printf("the id beneficiary not found\n");
        userSettings();
    }

    if (!checkIfPossible(amount))
    {
        printf("the mony in your account not enough\n");
        userSettings();
    }
    else
    {
        accounts[from_index].balance -= amount;
        accounts[to_index].balance += amount;
        printf("transfer successful\n");
        printf("/*////////////////////////////////////////*/\n");
        u8 Case;
        printf("if you want to continue enter:1\n");
        printf("if you want to exist enter :2\n");
        scanf("%d", &Case);
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
}

/***************** choose loan from schedual *******************/
void applyForLoan()
{

    u32 A, B;                                          // A >> ID , B >> password
    u8 IDFlag = 0, PASSFlag = 1, i, userIndex, choice; // for check on them
    u64 z;

    userIndex = USerIndex; // our function to search for index of IDs
    if (userIndex >= 0)
    {
        IDFlag = 1;
    }
    printf("Please,Enter Your Password :");
    scanf("%d", &B);
    // if( B == accounts[userIndex].password)
    //   PASSFlag =1;

    if (IDFlag)
    {
        if (PASSFlag)
        {

            u32 col[4][4] = {{20.000, 5, 1, 1750}, {30.000, 5, 2, 1750}, {40.000, 6, 2, 1700}, {50.000, 7, 3, 25000}};
            u16 rows;
            u16 choice;

            printf("\n\n\n");
            printf("    %-16s  %-16s %-16s %-16s \n\n", "Amount 'K'", "Interest R", "year", "monthly");
            for (rows = 0; rows < 4; rows++)
            {
                printf("%d.\t", rows);

                for (int i = 0; i < 4; i++)
                {
                    printf(" %-14d ", col[rows][i]);
                }

                printf("\n\n\n");
            }

            printf("Please ,choose your loan OR press '9' for customer support \n");
            scanf("%d", &choice);
            switch (choice)
            {

            case 0:

                loans[userIndex].money_loan = 20000;
                loans[userIndex].interest_rate = 5;
                loans[userIndex].years = 1;
                loans[userIndex].duration_months = 1750;
                break;

            case 1:

                loans[userIndex].money_loan = 30000;
                loans[userIndex].interest_rate = 5;
                loans[userIndex].years = 1.5;
                loans[userIndex].duration_months = 1750;
                break;

            case 2:

                loans[userIndex].money_loan = 40000;
                loans[userIndex].interest_rate = 7;
                loans[userIndex].years = 2;
                loans[userIndex].duration_months = 1700;
                break;

            case 3:

                loans[userIndex].money_loan = 100000;
                loans[userIndex].interest_rate = 10;
                loans[userIndex].years = 4;
                loans[userIndex].duration_months = 25000;
                break;

            case 9:

                customerSupport();
                break;
            default:
                printf("Invaild operation \n");
                break;
            }
        }

        else
        {
            printf("incorrect Password! \n");
        }
    }

    else
    {
        printf("invaild ID !\n");
    }

    printf("\n****** Thanks for using our service ******\n");
    printf("1.Goback\n2.Quit");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        userSettings();
        break;
    case 2:
        return;
        break;
    }
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
    u8 flag = 0, choice;
    u32 A;
id:
    printf("Please ,Enter your ID: \n ");
    scanf("%d", &A);
    for (int i = 0; i <= userCount; i++)
    {
        if (A == accounts[i].Id)
        {
            flag = 1;
        }
        if (flag)
        {
            printf("Please, Add your complaints ! \n");
            fflush(stdin);
            gets(accounts[i].complain);

            printf("\n");

            printf("*************** Thanks for your Note ***************\n\n");
            printf("1.continue \n2.Quit");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                userSettings();
                break;
            case 2:
                return;
                break;
            }
        }
        else
        {
            printf("invaild ID!\n");
            printf("1.try again \n2.choose another service\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                goto id;
                break;
            case 2:
                userSettings();
            }
        }
    }
}

/******************check transaction ****************/
u8 checkIfPossible(u64 amount)
{
    u8 Mflag = 0, Lflag = 0, final = -1;
    u8 count;
    for (count = 0; count < userCount; count++)
    {
        if (accounts[count].balance >= amount)
        {
            Mflag = 1;
        }
        if (MAX_AMOUNT_PER_TRANSACTION >= amount)
        {
            Lflag = 1;
        }
        if (Mflag && Lflag)
        {
            final = 1;
        }
    }
    return final;
}
