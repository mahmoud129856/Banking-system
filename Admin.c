#include "HeaderFiles.h"
char Admin_Entering[5] = "100";
char motor[20] = {'11'};
extern u8 counterr;
/****************** admin login ****************/
U Admin_LogIn(char ID[])
{

    char New_ID[10];
    int Result = -2;
    int Flag = 1;
    int Flag1 = 1;
Label:
    system("cls");

    delay("Welcome Sir!!\n", n);
    delay("please enter your ID:", n);
    scanf("%s", &New_ID);
    Result = memcmp(New_ID, Admin_Entering, 3);
    if (Result == 0)
    {
        adminSettings();
    }
    else
    {
        system("cls");
        int Choice = 0;
        delay("Invalid ID\n", n);
        usleep(800000);
        system("cls");
    Label1:
        delay("[1] to Try again\n", n);
        delay("[2] to Main Page\n", n);
        delay("[3] to Exit\n\n", n);
        delay("Enter your Choice:", n);

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
                usleep(1000000);
                systemFace();
            }
            break;
        case 2:
            systemFace();
            break;
        default:
            system("cls");
            delay("Invalid Choice!!\n", n);
            usleep(800000);
            Flag1++;
            if (Flag1 < 3)
            {
                system("cls");

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
        system("cls");
        delay("1.create account\n", n);
        delay("2.update account\n", n);
        delay("3.delete account\n", n);
        delay("4.Diplay info of User\n", n);
        delay("5.loans information & decision\n", n);
        delay("6.support section & decision\n", n);
        delay("7.LogOut\n", n);
        delay("8.Exit\n", n);
        delay("Enter your choice: ", n);
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid Input!\n\n");
            scanf("%*[^\n]");
            usleep(500000);
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
            delay("Invalid choice! Try again.", n);
            usleep(800000);
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
        system("cls");
        delay("Enter customer name: ", n);
        gets(accounts[userCount].Name);
        delay("Name added successfully", n);
        usleep(800000);
        system("cls");

    invalid:
        system("cls");
        delay("Enter customer id:", n);
        if (scanf("%lu", &id) != 1)
        {
            delay("Invalid Input!\n", n);
            usleep(800000);
            scanf("%*[^\n]");
            goto invalid;
        }
        if (search1(id) == -1)
        {
            accounts[userCount].Id = id;
            delay("Id added successfully!!", n);
            usleep(800000);
            system("cls");
        }
        else
        {
            delay("Invalid!!!Thers is another account With This ID\n", n);
            delay("try this available ID:", n);
            delay(motor, n);
            printf("\n");
            usleep(1000000);
            motor[0] += 3;
            goto invalid;
        }

    invalid1:

        delay("Enter customer age:", n);
        if (scanf("%i", &accounts[userCount].age) != 1)
        {
            printf("Invalid Input!");
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid1;
        }
        else
        {
            delay("customer age added successfully!!", n);
            usleep(800000);
            system("cls");
        }

    invalid15:

        delay("Enter customer Phone number:", n);
        if (scanf("%i", &accounts[userCount].phoneNumber) != 1)
        {
            printf("Invalid Input!");
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid15;
        }
        else
        {
            delay("customer Phone number added successfully!!", n);
            usleep(800000);
            system("cls");
        }

    invalid150:

        delay("Enter customer password:", n);
        fflush(stdin);
        if (scanf("%i", &accounts[userCount].password) != 1)
        {
            printf("Invalid Input!");
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid150;
        }
        else
        {
            delay("customer password added successfully!!", n);
            usleep(800000);
            system("cls");
        }

        fflush(stdin);
        delay("Enter customer address:", n);
        gets(accounts[userCount].address);
        delay("Address added successfully!!\n", n);
        usleep(800000);
        system("cls");

        delay("Enter account type:", n);
        gets(accounts[userCount].acountType);
        delay("account type added successfully!!", n);
        usleep(800000);
        system("cls");

    invalid10:
        delay("Enter the initial balance:", n);
        if (scanf("%llu", &accounts[userCount].balance) != 1)
        {
            printf("Invalid Input\n!");
            scanf("%*[^\n]");
            usleep(800000);
            system("cls");
            goto invalid10;
        }
        else
        {
            delay("initial balance added successflly!!", n);
            usleep(800000);
            system("cls");
        }

        delay("1.Save information\n", n);
        delay("2.discard \n", n);
        delay("Enter your choice:", n);
        scanf("%i", &choice1);
        switch (choice1)
        {
        case 1:
            system("cls");
            delay("...You Add new account Successfully...", n);
            usleep(800000);

            userCount++;
            break;
        case 2:
            createAccount();
            break;
        }
        system("cls");
        delay("(1) Admin option\n", n);
        delay("(2) To Quit\n", n);
        delay("Enter your choice:", n);

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
        system("cls");
        delay("You can't create new account... The System Is Full !!!", n);
        usleep(800000);
    Invalid:
        system("cls");
        delay("(1) to Admin option\n", n);
        delay("(2) to Quit\n", n);
        delay("Enter your choice:", n);
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
            delay("Invalid Input!", n);
            usleep(800000);

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
    system("cls");
    delay("Please enter account ID:", n);
    scanf("%lu", &id);
    for (i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == id)
        {

            flag = 1;
        invalid:
        all:

            system("cls");
            delay("1.update name\n", n);
            delay("2. update age\n", n);
            delay("3. update address\n", n);
            delay("4. update account Type\n", n);
            delay("5. update Phone number\n", n);
            delay("6. update password\n", n);
            delay("7. update balance\n", n);
            delay("8. update all\n", n);
            delay("9. back\n", n);
            delay("\n\nEnter your choice: ", n);

            scanf("%d", &choice);

            fflush(stdin);
            switch (choice)
            {
            case 1:
                system("cls");
                delay("Enter new name: ", n);

                gets(check);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    system("cls");
                    strcpy(accounts[i].Name, check);
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 2:
                system("cls");
                delay("Enter new age: ", n);
                scanf("%d", &try);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].age = try;
                    system("cls");
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    printf("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 3:
                system("cls");
                delay("Enter new address: ", n);
                gets(check);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].address, check);
                    system("cls");
                    printf(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 4:
                system("cls");
                delay("Enter new account type ", n);
                gets(check);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].acountType, check);
                    system("cls");
                    delay("...updated successfully...", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 5:
                system("cls");
                delay("Enter new Phone number: ", n);
                scanf("%d", &try);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].phoneNumber = try;
                    system("cls");
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 6:
                system("cls");
                delay("Enter new password: ", n);
                scanf("%d", &try);
                delay("(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    accounts[i].password = try;
                    system("cls");
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 7:
                delay("Enter new balance: ", n);
                scanf("%llu", &try);
                delay("(1). confirm\n", 20);
                delay("(2). back\n", 20);
                delay("\nEnter your choice: ", n);
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:

                    accounts[i].balance = try;
                    system("cls");
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                }

            case 8:
                system("cls");
                delay("Enter new name: ", n);
                gets(accounts[i].Name);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay("Enter new age: ", n);
                scanf("%d", &accounts[i].age);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                fflush(stdin);
                delay("Enter new adderess: ", n);
                gets(accounts[i].address);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay("Enter new account type: ", n);
                gets(accounts[i].acountType);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay("Enter new Phone number: ", n);
                scanf("%d", &accounts[i].phoneNumber);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay("Enter new password: ", n);
                scanf("%d", &accounts[i].password);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay("Enter new balance: ", n);
                scanf("%llu", &accounts[i].balance);
                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay(".....account updated successfully.....", n);
                goto all;

            case 9:
                adminSettings();
                break;

            default:
                system("cls");
                delay("Invalid Input!\n", n);
                usleep(800000);
                goto all;
            }
        }
    }
    if (!flag)
    {
        delay("account not exist in our system!", n);
        usleep(800000);
        adminSettings();
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
    system("cls");
    delay("Enter account Id:", n);
    scanf("%d", &all);
    Account_ID = search1(all);
    if (Account_ID < MAX_USER && Account_ID >= 0)
    {
        delay("valid Account ID!!", n);
        usleep(800000);
    Label1:
        system("cls");
        delay("Enter Your Account Password: ", n);
        fflush(stdin);
        scanf("%i", &Password);
        if (Password == accounts[Account_ID].password)
        {

            delay("Valid Password!!", n);
            delay("Account name:", n);
            delay(accounts[Account_ID].Name, n);
            delay("\nAre you sure You want to Delete this Account?\nEnter [1] to Delete:", n);
            scanf("%i", &Choice1);

            switch (Choice1)
            {
            case 1:
                accounts[Account_ID].age = 0;
                accounts[Account_ID].balance = 0;
                accounts[Account_ID].password = 0;
                accounts[Account_ID].Id = 0;
                accounts[Account_ID].phoneNumber = 0;
                memset(accounts[Account_ID].acountType, '0', 100);
                memset(accounts[Account_ID].address, '0', 100);
                memset(accounts[Account_ID].Name, '0', 100);
                memset(accounts[Account_ID].complain, '0', 500);
                userCount--;
                system("cls");
                delay("Account Deleted Successfully!", n);
                usleep(800000);
                adminSettings();
                break;

            default:
            {
                system("cls");
                delay("Invalid Choise, Try Again Later!!", n);
                usleep(800000);
                adminSettings();
                break;
            }
            }
        }
        else
        {

            delay("Invalid Password!!", n);
            usleep(800000);

        Label:
            system("cls");
            delay("[1] to Try again\n", n);
            delay("[2] to Admin Page\n", n);
            delay("[3] to Exit\n", n);
            delay("Enter your Choice: ", n);
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
                    system("cls");
                    usleep(1000000);
                    adminSettings();
                }
                break;
            case 2:
                adminSettings();
                break;
            default:
                delay("Invalid Choice!!", n);
                Flag1++;
                if (Flag1 < 3)
                {
                    goto Label;
                }
                else
                {
                    system("cls");
                    usleep(1000000);
                    adminSettings();
                }
                break;
            }
        }
    }
    else
    {
        int Choice = 0;

        delay("Invlide Account ID!!!", n);
    Label3:
        system("cls");
        delay("[1] to Try Again\n", n);
        delay("[2] to Admin Page\n", n);
        delay("[3] to Exit\n", n);

        delay("Enter Your Choice: ", n);
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
                system("cls");
                usleep(1000000);
                adminSettings();
            }
            break;
        case 2:
            adminSettings();

            break;
        case 3:
            exit(1);
            break;
        default:
            delay("Invalid Choice!!", n);
            Flag3++;
            if (Flag3 < 3)
            {
                goto Label3;
            }
            else
            {
                system("cls");
                usleep(1000000);
                adminSettings();
            }
        }
    }
}

/**************display info*****************/
U displayUserInfo()
{
    int IdIndex, see;
    int all;
al:
    system("cls");
    delay("Enter account id:", n);
    scanf("%d", &all);
    IdIndex = search1(all);
    if (IdIndex >= 0)
    {
        system("cls");
        printf("\n=====================================================================================================================\n");
        printf("%-20s %-15s %-15s %-15s %-15s %-20s", "Holder", "type", "Balance", "age", "address", "Phone number");
        printf("\n=====================================================================================================================\n");
        printf("%-20s %-15s %-15llu %-15lu %-15s %-20llu", accounts[IdIndex].Name, accounts[IdIndex].acountType, accounts[IdIndex].balance, accounts[IdIndex].age, accounts[IdIndex].address, accounts[IdIndex].phoneNumber);
        printf("\n=====================================================================================================================\n");
    again:
        delay("1.search for another account \n2.Admin options", n);
        delay("\nEnter your choice:", n);
        scanf("%d", &see);
        switch (see)
        {
        case 1:

            goto al;
            break;
        case 2:
            adminSettings();
            break;
        default:
            delay("Invalid input", n);
            system("cls");
            goto again;
        }
    }
    else
    {
        system("cls");
        delay("Account not found", n);
        usleep(800000);
        adminSettings();
    }
}
/**************loan informayion*****************/
U loanInformation()
{
}
/**************support section*****************/

U supportSection()
{
    u8 i = 0, cass, choice;
    u16 counter = sizeof(complainName) / sizeof(complainName[0]);

all:
    system("cls");

    printf("====================\n");
    printf("%-5s %-25s", "No", "Name");
    printf("\n====================\n");
    for (i = 0; i < counterr; i++)
    {
        printf("%-5d %-25s\n", i + 1, accounts[complainName[i]].Name);
    }
    printf("====================\n");
    delay("choose customer:", n);
    scanf("%d", &cass);
    switch (cass)
    {
    case 1:
    {

        system("cls");
        delay(accounts[complainName[0]].complain, n);
        printf("\n");
        delay("1.Call him \n2.Go back", n);
        delay("\nEnter your choice:", n);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("%llu", accounts[complainName[0]].phoneNumber);
            usleep(1000000);
            break;
        case 2:
            adminSettings();
            break;
        }
        break;
    }
    case 2:
    {

        system("cls");
        delay(accounts[complainName[1]].complain, 20);
        printf("\n");
        delay("1.Call him \n2.Go back", n);
        delay("\nEnter your choice:", n);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("%llu", accounts[complainName[1]].phoneNumber);
            usleep(1000000);
            break;
        case 2:
            adminSettings();
        }
        break;
    }
    case 3:
    {

        system("cls");
        delay(accounts[complainName[2]].complain, 20);
        printf("\n");
        delay("1.Call customer \n2.Go back", n);
        delay("\nEnter your choice:", n);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("%llu", accounts[complainName[2]].phoneNumber);
            usleep(1000000);
            break;
        case 2:
            adminSettings();
        }
        break;
    }

    case 4:
    {

        system("cls");
        delay(accounts[complainName[3]].complain, 20);
        printf("\n");
        delay("1.Call him \n2.Go back", n);
        delay("\nEnter your choice:", n);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("%llu", accounts[complainName[3]].phoneNumber);
            usleep(1000000);
            break;
        case 2:
            adminSettings();
        }
        break;
    }
    }
al:
    system("cls");
    delay("1.see another complain \n2.Go bak", n);
    delay("\nEnter your choice:", n);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        goto all;
        break;
    case 2:
        adminSettings();
        break;
    default:
        delay("Invalid input", n);
        usleep(800000);
        goto al;
    }
}

/**************system face*****************/
void systemFace()
{
    u8 choice = 0;
    while (1)
    {
        system("cls");

    invalid:
        delay("1.Admin Moode\n", n);
        delay("2.User Moode\n", n);
        delay("3.Quit\n", n);
        delay("Enter your choice:", n);

        if (scanf("%d", &choice) != 1)
        {
            delay("Invalid input", n);

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
            delay("Invalid choice!", n);
            usleep(800000);
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
void delay(const char *text, int Delay)
{
    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        usleep(Delay * 1000);
        text++;
    }
}
