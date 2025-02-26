#include "HeaderFiles.h"
u8 counterr = 0;
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
    int i = 0;
    char New_ID, coo[20];

Label2:
    system("cls");
    delay("Welcome Back!!\n", n);

    delay("Enter your ID:", n);

    if (scanf("%d", &seark) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto Label2;
    }

    Account_ID = search1(seark);
    USerIndex = Account_ID;
    if (Account_ID < MAX_USER && Account_ID >= 0)
    {
        delay("valid ID!!", n);
        usleep(800000);
    Label1:
        i = 0;
        system("cls");
        delay("Enter Your Account Password: ", n);

        while (1)
        {

            New_ID = getch();

            if (New_ID == 13)
            {
                coo[i] = '\0';
                break;
            }
            else if (New_ID == 8 && i > 0)
            {
                printf("\b \b");
            }
            else if (i < 19)
            {
                coo[i++] = New_ID;
                printf("*");
            }
        }
        Password = atoi(coo);

        if (Password == accounts[Account_ID].password)

        {

            delay("\nValid Password!!", n);
            usleep(800000);
            userSettings();
        }
        else
        {
            system("cls");
            delay("Invalid Password!!", n);
            usleep(800000);

        Label:
            system("cls");
            delay("[1] to Try again\n", n);
            delay("[2] to Exit\n", n);
            delay("Enter your Choice: ", n);
            fflush(stdin);
            if (scanf("%d", &Choice) != 1)
            {
                delay("Invalid Input!\n", n);
                scanf("%*[^\n]");
                usleep(500000);
                goto Label;
            }

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
                    usleep(1000000);
                    systemFace();
                }
                break;
            case 2:
                return (0);
                break;
            default:
                system("cls");
                delay("Invalid Choice!!\n", n);
                usleep(800000);
                Flag1++;
                if (Flag1 < 3)
                {
                    goto Label;
                }
                else
                {
                    usleep(1000000);
                    systemFace();
                }
                break;
            }
        }
    }
    else
    {
        int Choice = 0;
        system("cls");
        delay("Invlide Account ID!!!", n);
        usleep(800000);
    Label3:
        system("cls");
        delay("[1] to Try Again\n", n);
        delay("[2] to Exit\n\n", n);

        delay("Enter Your Choice: ", n);
        fflush(stdin);
        if (scanf("%d", &Choice) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto Label3;
        }

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
                usleep(1000000);
                systemFace();
            }
            break;
        case 2:
            return (0);
            break;
        default:
            system("cls");
            delay("Invalid Choice!!", n);
            usleep(800000);
            Flag3++;
            if (Flag3 < 3)
            {
                goto Label3;
            }
            else
            {
                usleep(1000000);
                systemFace();
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

label:
    system("cls");
    delay("1.deposits cash\n", n);
    delay("2.withdrawals cash\n", n); // اتاكد ان الرقم اللي هيتسحب ده موجود اصلا ومش مخالف للحد الاقصي للسحب
    delay("3.check balance\n", n);
    delay("4.cash transfer\n", n);    // اتأكد من ان المبلغ المبعوت موجود اصلا في الحساب وان المبلغ مسموح يتبعت
    delay("5.apply for loan\n", n);   // هيظهر جدول ل كل القروض الموجوده في النظالم وهو يختار منهم اللي ىناسبه
    delay("6.tracking loan\n", n);    // بيشوف الفلوس اللي اتدفعت من القرض والفلوس المتبقه عليه للبنك
    delay("7.Customer Support\n", n); // مش بيعمل اكتر من انه بيكتب مسدج ونخزنها منه
    delay("8.go back\n", n);
    delay("9.Exit\n", n);
    delay("\nEnter your choice: ", n);
    if (scanf("%d", &choice) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto label;
    }

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
        delay("Invalid choice", n);
        usleep(800000);
        goto label;
    }
}

/***************** add money *******************/
void depositCash()
{

    u8 i, choice; // for check on them
    u64 z;

negative:
    system("cls");
    delay("$Please,Enter the amount$: ", n);
    if (scanf("%d", &z) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto negative;
    }

    if (z > 0 && z <= 100000)
    {
        accounts[USerIndex].balance += z;
        system("cls");
        delay("Deposit Successful", n);
        usleep(800000);
    label:
        system("cls");
        delay("1.continue \n2.Quit", n);
        if (scanf("%d", &choice) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto label;
        }

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
    o:
        system("cls");
        delay("No money added ,the maximum amount '100.000' '100K' ,please try again! \n ", n);

        delay("1.try again \n2.choose another service\n", n);
        if (scanf("%d", &choice) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto o;
        }

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
    system("cls");
    delay("Enter The Amount of Money you want: ", n);
    if (scanf("%llu", &Balance) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto Label3;
    }

    if (checkIfPossible(Balance) == 1)
    {

        delay("Are you Sure you want to to withdraw this Money[Enter (1) if you Sure]: ", n);
        if (scanf("%d", &Choice) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto Label3;
        }

        if (Choice == 1)
        {
            accounts[AccountID].balance -= Balance;
            system("cls");
            delay("Successfull Operation!!", n);
            usleep(800000);
            userSettings();
        }
        else
        {
            system("cls");
            delay("Invalid Choice!!,Try Agian Later", n);
            usleep(800000);
            userSettings();
        }
    }
    else
    {
        system("cls");
        delay("Invalid, You don't have this money in your Account!!!", n);
        usleep(800000);
        Flag3++;
        if (Flag3 < 3)
        {
            goto Label3;
        }
        else
        {
            usleep(1000000);
            userSettings();
        }
    }
}

/***************** show the money *******************/
void checkBalance()
{
    u8 choice;
    int index = USerIndex;
all:
    system("cls");
    printf("\n Account Information:\n");
    printf("========================================\n");
    printf(" %-25s %-15s\n", "Holder", "Balance");
    printf("========================================\n");
    printf(" %-25s %-15d ", accounts[index].Name, accounts[index].balance);
    printf("\n======================================\n");

    delay("press (1) to continue\n", n);
    if (scanf("%d", &choice) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto all;
    }

    switch (choice)
    {
    case 1:
        userSettings();
    default:
        delay("wrong input\n", n);
        usleep(800000);
        goto all;
    }
}
/***************** send money *******************/
void cashTransfer()
{
    u64 form_id, to_id;
    s8 from_index = USerIndex, to_index = -1, Case;
    u32 amount;
    system("cls");
    delay("Welcome in the transfer money serves ", n);
    usleep(800000);
Label1:
    system("cls");
    delay("Enter the id beneficiary: ", n);
    if (scanf("%llu", &to_id) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto Label1;
    }

    to_index = search1(to_id);
Label2:
    system("cls");
    delay("Enter the mount of transfer money:", n);
    if (scanf("%llu", &amount) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto Label2;
    }
    if (to_index == -1)
    {
        system("cls");
        delay("the id beneficiary not found", n);
        usleep(800000);
        userSettings();
    }

    if (!checkIfPossible(amount))
    {
        system("cls");
        delay("the money in your account not enough", n);
        usleep(800000);
        userSettings();
    }
    else
    {
        accounts[from_index].balance -= amount;
        accounts[to_index].balance += amount;
        delay("transfer successful", n);
    all:
        system("cls");
        delay("if you want to continue enter:1\n", n);
        delay("if you want to exist enter :2\n", n);
        if (scanf("%d", &Case) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto all;
        }
        switch (Case)
        {
        case 1:
            userSettings();
            break;
        case 2:
            return;
            break;
        default:
            delay("the number you  entered incorrect", n);
            usleep(800000);
            goto all;
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

    u32 col[4][4] = {{20.000, 5, 1, 1750}, {30.000, 5, 2, 1750}, {40.000, 6, 2, 1700}, {50.000, 7, 3, 25000}};
    u16 rows;
mine:
    system("cls");
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

    delay("Please ,choose your loan OR press '9' for customer support \n", n);
    if (scanf("%llu", &choice) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto mine;
    }
    switch (choice)
    {

    case 0:

        loans[userIndex].money_loan = 20000;
        loans[userIndex].remaning_balanc = 2000;
        loans[userIndex].interest_rate = 5;
        loans[userIndex].years = 1;
        loans[userIndex].duration_months = 1750;
        loans[userIndex].loan_id = accounts[USerIndex].Id;
        loancount++;
        break;

    case 1:

        loans[userIndex].money_loan = 30000;
        loans[userIndex].remaning_balanc = 3000;
        loans[userIndex].interest_rate = 5;
        loans[userIndex].years = 1.5;
        loans[userIndex].duration_months = 1750;
        loans[userIndex].loan_id = accounts[USerIndex].Id;
        loancount++;
        break;

    case 2:

        loans[userIndex].money_loan = 40000;
        loans[userIndex].remaning_balanc = 40000;
        loans[userIndex].interest_rate = 7;
        loans[userIndex].years = 2;
        loans[userIndex].duration_months = 1700;
        loans[userIndex].loan_id = accounts[USerIndex].Id;
        loancount++;
        break;

    case 3:

        loans[userIndex].money_loan = 100000;
        loans[userIndex].interest_rate = 10;
        loans[userIndex].years = 4;
        loans[userIndex].duration_months = 25000;
        loans[userIndex].loan_id = accounts[USerIndex].Id;
        loans[userIndex].remaning_balanc = 100000;
        loancount++;
        break;

    case 9:

        customerSupport();
        break;
    default:
        delay("Invaild operation \n", n);
        break;
    }

Label12:
    system("cls");
    delay("..... Thanks for using our service .....\n", n);
    delay("1.Goback\n2.Quit", n);
    delay("\nEnter your choice:", n);
    if (scanf("%d", &choice) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto Label12;
    }
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
    u64 id_loan, id_account, valid = 0;
    u8 i = 0;
y:
    system("cls");
    delay("Hello in tracking loan serves for user \n", n);
    usleep(800000);
    system("cls");
    delay("Enter the loan id:", n);
    scanf("%llu", &id_loan);

    for (i = 0; i <= loancount; i++)
    {
        if (loans[i].loan_id == id_loan)
        {
            valid = 1;
            break;
        }
    }

    if (!valid)
    {
        delay("incorrect loan id !!", n);
        usleep(800000);
        u8 count;
    mine:
        system("cls");
        delay("if you want to try again enter :1\n", n);
        delay("if you want to exist enter :2\n", n);
        delay("if you want to go to home enter :3\n", n);
        delay("enter your chose:", n);
        if (scanf("%d", &count) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto mine;
        }
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
            delay("the number you enter in correct ", n);
            break;
        }
    }

    else
    {

        printf("\n=======================================================================================================\n");
        printf("%-25s  %-20s %-15s %-15s %-15s", "Name", "loan ID", "amount", "remain", "Monthly");
        printf("\n=======================================================================================================\n");
        printf("%-25s %-20d %-20d %-15d %-15d ", accounts[USerIndex].Name, loans[i].loan_id, loans[i].money_loan, loans[i].remaning_balanc, loans[i].duration_months);
        printf("\n=======================================================================================================\n");
    }
}

/***************** write a massage from user *******************/
void customerSupport(void)
{
    u8 flag = 0, choice;
    u32 A;
    static u8 comp = 0;

    delay("Please, write your complaints:\n", n);
    fflush(stdin);
    gets(accounts[USerIndex].complain);
    complainName[comp] = USerIndex;
    comp++;
    counterr++;
    printf("\n");
    usleep(800000);

    system("cls");
    delay("...... Thanks for your Note ......", n);
mine:
    system("cls");
    delay("1.continue \n2.Quit\n", n);
    delay("Enter your choice:", n);
    if (scanf("%d", &choice) != 1)
    {
        delay("Invalid Input!\n", n);
        scanf("%*[^\n]");
        usleep(500000);
        goto mine;
    }
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
