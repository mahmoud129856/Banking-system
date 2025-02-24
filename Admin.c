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
    invalid:
        printf("1.create account\n");
        printf("2.update account\n");
        printf("3.delete account\n");
        printf("4.Diplay info of User\n");          // all User inf or choose specific information
        printf("5.loans information & decision\n"); // function will display all loans in a scedual and admin will choose one from them and confirm or refuse        // our available loans will be displayed in a sedual
        printf("6.support section & decision\n");   // will show the problems and forward the problem for his section
        printf("7.Go back\n");                      // main menu
        printf("8.Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Input!\n\n");
            scanf("%*[^\n]");
            goto invalid;
        }
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
            supportSection();
            break;
        case 7:
            systemFace();
            break;
        case 8:
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
        fgets(accounts[userCount].Name, sizeof(accounts[userCount].Name), stdin);

    invalid:

        printf("\nEnter customer ID:");
        if (scanf("%lu", &id) != 1)
        {
            printf("Invalid Input!");
            scanf("%*[^\n]");
            goto invalid;
        }
        if (search1(id) == -1)
        {
            accounts[userCount].Id = id;
        }
        else
        {
            printf("Invalid!!!Thers is another account With This ID\n");
            printf("try this available ID: '%d'\n", &i);
            goto invalid;
        }

    invalid1:

        printf("Enter customer age:");
        if (scanf("%i", &accounts[userCount].age) != 1)
        {
            printf("Invalid Input!");
            scanf("%*[^\n]");
            goto invalid1;
        }

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

u8 Namecheck(u8 index)
{
    u8 confirm;
    u32 check[50];
    printf("Enter new name: ");
    gets(check);
invalid1:
    printf("(1). confirm\n");
    printf("(2). back\n");
    printf("\nEnter your choice: ");
    if (scanf("%u", &confirm) != 1)
    {
        printf("Invalid Input!\n\n");
        scanf("%*[^\n]");
        goto invalid1;
    }
    switch (confirm)
    {
    case 1:
    {
        strcpy(accounts[index].Name, check);
        printf("\n******updated successfully******\n\n");
    }

    case 2:
    {
        printf("\n***NO changes occurred***\n");
        return 1;
    }
    }
}

Acccheck(u8 index)
{

    u8 confirm;
    u32 check[50];
    printf("Enter new account type: ");
    gets(check);
invalid:
    printf("(1). confirm\n");
    printf("(2). back\n");
    printf("\nEnter your choice: ");
    if (scanf("%u", &confirm) != 1)
    {
        printf("Invalid Input!\n\n");
        scanf("%*[^\n]");
        goto invalid;
    }
    switch (confirm)
    {
    case 1:
        strcpy(accounts[index].acountType, check);
        printf("\n******updated successfully******\n\n");
        break;

    case 2:
        printf("\n***NO changes occurred***\n");
        break;
    }
}

Passcheck(u8 index)
{

    u8 confirm;
    u64 check;
invalid:
    printf("Enter new password:");
    scanf("%llu", &check);
    printf("(1). confirm\n");
    printf("(2). back\n");
    printf("\nEnter your choice: ");
    if (scanf("%u", &confirm) != 1)
    {
        printf("Invalid Input!\n\n");
        scanf("%*[^\n]");
        goto invalid;
    }
    switch (confirm)
    {
    case 1:
        accounts[index].password = check;
        printf("\n******updated successfully******\n\n");
        break;

    case 2:
        printf("\n***NO changes occurred***\n");
        break;
    }
}

Balancecheck(u8 index)
{

    u8 confirm;
    u64 check;
invalid:
    printf("Enter new balance:");
    scanf("%llu", &check);
    if (check >= 0)
    {
        printf("(1). confirm\n");
        printf("(2). back\n");
        printf("\nEnter your choice: ");
        if (scanf("%u", &confirm) != 1)
        {
            printf("Invalid Input!\n\n");
            scanf("%*[^\n]");
            goto invalid;
        }
        switch (confirm)
        {
        case 1:
            accounts[index].balance = check;
            printf("\n******updated successfully******\n\n");
            break;

        case 2:
            printf("\n***NO changes occurred***\n");
            break;
        }
    }
    else
    {
        printf("Are you kidding me!!");
    }
}

Agecheck(u8 index)
{

    u8 confirm;
    u32 check;
invalid:
    printf("Enter new age:");
    scanf("%u", &check);
    if (check >= 21)
    {
        printf("(1). confirm\n");
        printf("(2). back\n");
        printf("\nEnter your choice: ");
        if (scanf("%d", &confirm) != 1)
        {
            printf("Invalid Input!\n\n");
            scanf("%*[^\n]");
            goto invalid;
        }
        switch (confirm)
        {
        case 1:
            accounts[index].age = check;
            printf("\n******updated successfully******\n\n");
            break;

        case 2:
            printf("\n***NO changes occurred***\n");
            break;
        }
    }
    else
    {
        printf("Sorry! , this under legal age\n");
    }
}

Addresscheck(u8 index)
{

    u8 confirm;
    u32 check[50];
invalid:
    printf("Enter new Address: ");
    gets(check);

    printf("(1). confirm\n");
    printf("(2). back\n");
    printf("\nEnter your choice: ");
    if (scanf("%d", &confirm) != 1)
    {
        printf("Invalid Input!\n\n");
        scanf("%*[^\n]");
        goto invalid;
    }
    switch (confirm)
    {
    case 1:
        strcpy(accounts[index].address, check);
        printf("\n******updated successfully******\n\n");

        break;
    case 2:
        printf("\n***NO changes occurred***\n");
        break;
    }
}

//=============================delete===================================
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
    int all;

Label2:
    printf("Enter account Id:");
    scanf("%d", &all);
    Account_ID = search1(all);
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
    int all;
    printf("Enter account id:");
    scanf("%d", &all);
    IdIndex = search1(all);
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
/**************support section*****************/

U supportSection()
{
    u8 i = 0;
    u32 user_id;
    printf("enter the user id \n");
    scanf("%d", &user_id);
    u8 idIndex = search1(user_id);

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
    u8 choice = 0;
    while (1)
    {
    invalid:
        printf("1.Admin Moode\n");
        printf("2.User Moode\n");
        printf("3.Quit\n");
        printf("Enter your choice:");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Input!\n");
            scanf("%*[^\n]");
            goto invalid;
        }
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
s8 search1(u64 x)
{
    u8 i;
    for (i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == x)
        {
            return i;
        }
    }

    return -1;
}
