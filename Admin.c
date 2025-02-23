#include "HeaderFiles.h"
char Admin_Entering[5] = "100";

/****************** admin login ****************/
U Admin_LogIn(char ID[])
{
    char New_ID[10];
    int Result = -2;
    int Flag = 1;
    int Flag1 = 1;

    printf("Welcome Sir!!\n");
Label:
    printf("Enter ID: ");
    scanf("%s", &New_ID);
    Result = memcmp(New_ID, Admin_Entering, 3);
    if (Result == 0)
    {
        adminSettings();
    }
    else
    {
        int Choice = 0;
        printf("Invalid ID!!!\n");
    Label1:
        printf("[1] to Try again\n");
        printf("[2] to Main Page\n");
        printf("[3] to Exit\n\n");
        printf("Enter your Choice: ");
        scanf("%i", &Choice);

        switch (Choice)
        {
        case 1:
            Flag++;
            if (Flag < 3)
            {
                goto Label;
            }
            else
            {
                return (0);
            }
            break;
        case 2:
            main();
            break;
        default:
            printf("Invalid Choice!!\n");
            Flag1++;
            if (Flag1 < 3)
            {
                goto Label1;
            }
            else
            {
                return (0);
            }
        }
    }
}

/************* admin function ************/
extern u16 userCount;
U adminSettings()
{
    /*every function will contain option "Go back for admin options"*/

    u8 choice = 0;
    while (1)
    {
        printf("1.create account\n");
        printf("2.update account\n");
        printf("3.delete account\n");
        printf("4.Diplay info of User\n");          // all User inf or choose specific information
        printf("5.loans information & decision\n"); // function will display all loans in a scedual and admin will choose one from them and confirm or refuse
        printf("6.scedualence of loans\n");         // our available loans will be displayed in a sedual
        printf("7.support section & decision\n");   // will show the problems and forward the problem for his section
        printf("8.Go back\n");                      // main menu
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            updateAccount();
            break;
        case 3:
            deleteAccount();
            break;
        case 4:
            displayUserInfo();
            break;
        case 5:
            loanInformation();
            break;
        case 6:
            scheduleLoans();
            break;
        case 7:
            supportSection();
            break;
        case 8:
            systemFace();
            break;
        case 9:
            return 0;
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

/************* create acc ************/
U createAccount()
{
    if ((userCount < MAX_USER))
    {
        u32 id;
        u8 choice = 0, choice1, count, i = 0;

        fflush(stdin);

        printf("Enter customer name: ");
        gets(accounts[userCount].Name);

        for (count = 0; count <= userCount; count++)
        {
        invalid:
            printf("\nEnter customer ID:");
            if (scanf("%lu", &id) != 1)
            {
                printf("Invalid Input!");
                scanf("%*[^\n]");
                goto invalid;
            }
            if ((accounts[count].Id) != id)
            {
                accounts[userCount].Id = id;
                break;
            }
            else
            {
                printf("Invalid!!!Thers is another account With This ID\n");
                printf("try this available ID: '%d'\n", &i);
                goto invalid;
            }
        }
    invalid1:

        printf("Enter customer age:");
        scanf("%i", &accounts[userCount].age);
        fflush(stdin);
        printf("Enter customer address:");
        gets(accounts[userCount].address);

        printf("Enter account type:");
        gets(accounts[userCount].acountType);

    invalid10:
        printf("Enter The initial balance:");
        if (scanf("%llu", &accounts[userCount].balance) != 1)
        {
            printf("Invalid Input\n!");
            scanf("%*[^\n]");
            goto invalid10;
        }

    invalid11:
        printf("Enter initial password:");
        if (scanf("%i", &accounts[userCount].password) != 1)
        {
            printf("Invalid Input\n!");
            scanf("%*[^\n]");
            goto invalid11;
        }

        printf("1. Save The Informatiom\n");
        printf("2. To change \n");
        printf("Enter your choice: ");
        scanf("%i", &choice1);
        switch (choice1)
        {
        case 1:
            printf("\n...You Add new account Successfully...\n");
            userCount++;
            break;
        case 2:
            createAccount();
            break;
        }
        printf("\n(1) Admin option\n");
        printf("(2) To Quit\n");
        printf("Enter your choice: ");
        scanf("%i", &choice);
        switch (choice)
        {
        case 1:
            adminSettings();
        case 2:
            return (0);
            break;
        }
    }
    else
    {
        int choice = 0;
        printf("\nYou can't create new account... The System Is Full !!!\n");
    Invalid:
        printf("\n(1) to Admin option\n");
        printf("(2) to Quit\n");
        printf("Enter your choice: ");
        scanf("%i", &choice);
        switch (choice)
        {
        case 1:
            adminSettings();
            break;
        case 2:
            return (0);
            break;
        default:
            printf("Invalid Input!");
            goto invalid;
        }
    }
}

/**************update*****************/
U updateAccount()
{

    u32 check[20], id;
    u8 flag = 0, i;
    u8 choice, confirm;
    u64 try;

    printf("Please enter your ID: ");
    scanf("%lu", &id);
    for (i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == id)
        {
            flag = 1;
        invalid:
        all:
            printf("\n1.update name\n");
            printf("2. update age\n");
            printf("3. update adderess\n");
            printf("4. update account Type\n");
            printf("5. update password\n");
            printf("6. update balance\n");
            printf("7. update all\n");
            printf("8. back\n");
            printf("\n\nEnter your choice: ");

            scanf("%d", &choice);

            fflush(stdin);
            switch (choice)
            {
            case 1:

                printf("Enter new name: ");

                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].Name, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 2:
                printf("Enter new age: ");
                scanf("%d", &try);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].age = try;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 3:
                printf("Enter new adderess: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].address, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 4:
                printf("Enter new account type ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].acountType, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 5:
                printf("Enter new passowrd: ");
                scanf("%d", &try);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].password = try;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 6:
                printf("Enter new balance: ");
                scanf("%llu", &try);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].balance = try;
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 7:
                printf("\n\nEnter new name: ");
                gets(accounts[i].Name);

                printf("\n\nEnter new age: ");
                scanf("%d", &accounts[i].age);
                fflush(stdin);
                printf("\n\nEnter new adderess: ");
                gets(accounts[i].address);

                printf("\n\nEnter new account type: ");
                gets(accounts[i].acountType);

                printf("\n\nEnter new password: ");
                scanf("%d", &accounts[i].password);

                printf("\n\nEnter new balance: ");
                scanf("%llu", &accounts[i].balance);

                printf("\n\n***Flight schedule updated successfully!***\n\n");
                goto all;

            case 8:
                adminSettings();
                break;

            default:
                printf("Invalid Input!\n");
                goto all;
            }
        }
    }
    if (!flag)
    {
        printf("\naccount not exist in our system!\n\n");
        adminSettings();
    }
}
/**************delete*****************/
U deleteAccount()
{
    int Account_ID;
    int Size = 0;

    int Password;
    int Result = 0;
    int Flag = 0;
    int Flag1 = 0;
    int Flag2 = 0;
    int Flag3 = 0;
    int Choice = 0;
    int Choice1 = 0;

Label2:
    Account_ID = search1();
    if (Account_ID < MAX_USER && Account_ID >= 0)
    {
        printf("valid Account!!\n\n");
    Label1:
        printf("Enter Your Account Password: ");
        fflush(stdin);
        scanf("%i", &Password);
        if (Password == accounts[Account_ID].password)
        {

            printf("Valid Password!!\n\n");
            printf("Are you sure You want to Delet Your Account?\nEnter [1] to Delete:");
            scanf("%i", &Choice1);

            switch (Choice1)
            {
            case 1:
                accounts[Account_ID].age = 0;
                accounts[Account_ID].balance = 0;
                accounts[Account_ID].password = 0;
                accounts[Account_ID].Id = 0;
                memset(accounts[Account_ID].acountType, '0', 100);
                memset(accounts[Account_ID].address, '0', 100);
                memset(accounts[Account_ID].Name, '0', 100);
                memset(accounts[Account_ID].complain, '0', 500);
                userCount--;
                printf("\nAccount Deleted Successfullt!\n\n");
                adminSettings();
                break;

            default:
            {
                printf("Invalid Choise, Try Again Later!!\n");
                adminSettings();
                break;
            }
            }
        }
        else
        {
            printf("Invalid Password!!\n");

        Label:
            printf("[1] to Try again\n");
            printf("[2] to Admin Page\n");
            printf("[3] to Exit\n\n");
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
                    adminSettings();
                    return (0);
                }
                break;
            case 2:
                adminSettings();
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
                    adminSettings();
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
        printf("[2] to Admin Page\n");
        printf("[3] to Exit\n\n");

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
                adminSettings();
                return (0);
            }
            break;
        case 2:
            adminSettings();
            return (0);
            break;
        case 3:
            exit(1);
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
                adminSettings();
                return (0);
            }
        }
    }
}

/**************display info*****************/
U displayUserInfo()
{
    u8 IdIndex;
    IdIndex = search1();
    printf("\n Account Information:\n");
    printf("===============================\n");
    printf(" Account Holder : %s\n", accounts[IdIndex].Name);
    printf(" Current Balance: %d EGP\n", accounts[IdIndex].balance);
    printf(" Account type : %s\n", accounts[IdIndex].acountType);
    printf(" Current age: %d \n", accounts[IdIndex].age);
    printf(" Current adderss: %s \n", accounts[IdIndex].address);

    // printf(" Created Date   : %s\n", account.created_date);
    printf("===============================\n");
}
/**************loan informayion*****************/
U loanInformation()
{
}
/**************schedual pattern*****************/
U scheduleLoans()
{
    accounts[0].Id = 111;
    accounts[0].password = 111;
    u32 A, B;                                          // A >> ID , B >> password
    u8 IDFlag = 0, PASSFlag = 1, i, userIndex, choice; // for check on them
    u64 z;

    userIndex = search1(); // our function to search for index of IDs
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

U supportSection()
{
    u8 i = 0;
    u32 user_id;
    printf("enter the user id \n");
    scanf("%d", &user_id);
    u8 idIndex = search1();

    if (idIndex >= 0)
    {
        printf("%s\n", accounts[idIndex].complain);
        u8 Case;
        try : printf("\n/*//////////////////////*/\n")
            ;
        printf("1.exit:\n");
        printf("2.back to the main menu list:\n");
        printf("3.back to the admin setting:\n");

        scanf("%d", &Case);
        switch (Case)
        {
        case 1:
            return;
            break;
        case 2:
            systemFace();
            break;
        case 3:
            adminSettings();
            break;
        default:
            printf("you have enter the incorrect number \n");
            goto try;
            break;
        }
    }

    else
    {
        printf("the id you have enterd not exist try again \n");
        userSettings();
    }
}
/**************system face*****************/
void systemFace()
{
    int choice = 0;
    while (1)
    {
        printf("1.Admin Moode\n");
        printf("2.User Moode\n");
        printf("3.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Admin_LogIn(Admin_Entering);
            break;
        case 2:
            User_Login();
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
int search1()
{
    u64 id;
    u8 i;
    printf("Enter account ID: ");
    scanf("%d", &id);
    for (i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == id)
        {
            return i;
        }
    }

    return -1;
}
