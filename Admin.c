#include "HeaderFiles.h"
char Admin_Entering[5] = "100";

extern u8 counterr;
/****************** admin login ****************/
U Admin_LogIn(char ID[])
{

    char New_ID[10];
    int Result = -2;
    int Flag = 0;
    int Flag1 = 1;
    int choice;
Label1:
    system("cls");

    delay("Welcome Sir!!\n", n);
    delay("please enter your ID:", n);
    fflush(stdin);
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

    label:
        system("cls");
        delay("[1] to Try again\n", n);
        delay("[2] to Main Page\n", n);
        delay("[3] to Exit\n\n", n);
        delay("Enter your Choice:", n);
        fflush(stdin);
        if (scanf("%d", &Choice) != 1)
        {
            delay("Invalid Input!\n", n);
            scanf("%*[^\n]");
            usleep(500000);
            goto label;
        }

        else
        {
            switch (Choice)
            {
            case 1:
                Flag++;
                if (Flag <= 3)
                {
                    goto Label1;
                }
                else
                {
                    usleep(10000000);
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

                    goto label;
                }
                else
                {
                    return (0);
                }
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
            system("cls");
            delay("Invalid Input!", n);
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
    srand(time(NULL));
    if ((userCount < MAX_USER))
    {
        u64 motor = (rand() % 99999) + 1, my;
        u32 id;
        u8 choice = 0, choice1, count, i = 0, numF = 1;
        fflush(stdin);
        system("cls");
        delay("Enter customer name: ", n);
        gets(accounts[userCount].Name);
        delay("Name added successfully", n);
        usleep(800000);
        system("cls");

    invalid:
        system("cls");
        delay("Enter customer id (1-->99999) : ", n);
        if (scanf("%lu", &id) != 1)
        {
            delay("Invalid Input!\n", n);
            usleep(800000);
            scanf("%*[^\n]");
            goto invalid;
        }
        if (id <= 99999 && id > 0)
        {
            if (search1(id) == -1)
            {
                accounts[userCount].Id = id;
                delay("Id added successfully!!", n);
                usleep(800000);
            }
            else
            {
                delay("Invalid!!!Thers is another account With This ID\n", n);
                delay("try this available ID:", n);
                printf("%llu", motor);
                printf("\n");
                usleep(10000000);

                goto invalid;
            }
        }
        else
        {

            delay("Invalid ID", n);
            usleep(800000);
            goto invalid;
        }

    invalid1:
        system("cls");
        delay("Enter customer age:", n);
        if (scanf("%i", &my) != 1)
        {

            printf("Invalid Input!");
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid1;
        }
        else
        {
            if (my >= 21 && my <= 120)
            {
                delay("customer age added successfully!!", n);
                accounts[userCount].age = my;
                usleep(800000);
            }
            else
            {
                system("cls");
                delay("Illegal age!!!", n);
                usleep(800000);
                goto invalid1;
            }
        }

    invalid12:
        system("cls");
        delay("Enter customer Phone number:", n);
        fflush(stdin);
        if (scanf("%llu", &accounts[userCount].phoneNumber) != 1)
        {
            system("cls");
            delay("Invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");

            goto invalid12;
        }
        else
        {
            delay("customer phone number added successfully!!", n);
            usleep(800000);
            system("cls");
        }

    invalid150:

        delay("Enter customer password:", n);
        fflush(stdin);
        if (scanf("%i", &accounts[userCount].password) != 1)
        {
            delay("Invalid Input!", n);
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
            delay("Invalid Input\n!", n);
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
        if (scanf("%i", &choice1) != 1)
        {
            delay("Invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid150;
        }
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

        if (scanf("%i", &choice) != 1)
        {
            delay("Invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid150;
        }
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
        if (scanf("%i", &choice) != 1)
        {
            delay("Invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto invalid150;
        }
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
invalid:
    system("cls");
    delay("Please enter account ID:", n);
    if (scanf("%i", &id) != 1)
    {
        delay("invalid Input!", n);
        usleep(800000);
        scanf("%*[^\n]");
        system("cls");
        goto invalid;
    }
    for (i = 0; i < userCount; i++)
    {
        if (accounts[i].Id == id)
        {

            flag = 1;
        all:

            system("cls");
            delay("1.update name\n", n);
            delay("2. update age\n", n);
            delay("3. update address\n", n);
            delay("4. update account Type\n", n);
            delay("5. update password\n", n);
            delay("6. update balance\n", n);
            delay("7. update all\n", n);
            delay("8. back\n", n);
            delay("\n\nEnter your choice: ", n);

            if (scanf("%i", &choice) != 1)
            {
                delay("invalid Input!", n);
                usleep(800000);
                scanf("%*[^\n]");
                system("cls");
                goto all;
            };

            fflush(stdin);
            switch (choice)
            {
            case 1:
            w:
                system("cls");
                delay("Enter new name: ", n);

                gets(check);

                delay("\n(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                if (scanf("%i", &confirm) != 1)
                {
                    system("cls");
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto w;
                }
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
                default:
                    delay("incorrect choice\n", n);
                    usleep(800000);
                    goto w;
                }

            case 2:
            a:
                system("cls");
                delay("Enter new age: ", n);
                if (scanf("%i", &try) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto a;
                }
                if (try >= 21 && try <= 120)
                {
                    delay("(1). confirm\n", n);
                    delay("(2). back\n", n);
                    delay("\nEnter your choice: ", n);
                    if (scanf("%i", &confirm) != 1)
                    {
                        delay("invalid Input!", n);
                        usleep(800000);
                        scanf("%*[^\n]");
                        system("cls");
                        goto a;
                    }
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

                    default:
                        delay("incorrect choice\n", n);
                        usleep(800000);
                        goto a;
                    }
                }
                else
                {
                    delay("this Age is illegal!!", n);
                    usleep(800000);
                    goto a;
                }

            case 3:
            h:
                system("cls");
                delay("Enter new address: ", n);
                fflush(stdin);
                gets(check);
                delay("\n(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                if (scanf("%i", &confirm) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto h;
                }
                switch (confirm)
                {
                case 1:
                    strcpy(accounts[i].address, check);
                    system("cls");
                    delay(".....updated successfully.....", n);
                    usleep(800000);
                    goto all;

                case 2:
                    system("cls");
                    delay("...NO changes occurred...", n);
                    usleep(800000);
                    goto all;
                default:
                    delay("incorrect choice\n", n);
                    usleep(800000);
                    goto h;
                }

            case 4:
            j:
                system("cls");
                delay("Enter new account type ", n);
                fflush(stdin);
                gets(check);
                delay("\n(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                fflush(stdin);
                if (scanf("%i", &confirm) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto j;
                }
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

                default:
                    delay("incorrect choice\n", n);
                    usleep(800000);
                    goto j;
                }

            case 5:
            k:
                system("cls");
                delay("Enter new password: ", n);
                if (scanf("%llu", &try) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto k;
                }
                delay("\n(1). confirm\n", n);
                delay("(2). back\n", n);
                delay("\nEnter your choice: ", n);
                if (scanf("%i", &confirm) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto k;
                }
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

                default:
                    delay("incorrect choice\n", n);
                    usleep(800000);
                    goto k;
                }

            case 6:
            e:
                system("cls");
                delay("Enter new balance: ", n);
                if (scanf("%llu", &try) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto e;
                }
                delay("\n(1). confirm\n", 20);
                delay("(2). back\n", 20);
                delay("\nEnter your choice: ", n);
                if (scanf("%i", &confirm) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto e;
                }
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

                default:
                    delay("incorrect choice\n", n);
                    usleep(800000);
                    goto e;
                }

            case 7:
                system("cls");
                delay("Enter new name: ", n);
                gets(accounts[i].Name);
                delay("Updated successfully!!", n);
                usleep(800000);

            f:
                system("cls");

                delay("Enter new age: ", n);
                if (scanf("%llu", &try) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto f;
                }
                if (try >= 21 && try <= 120)
                {
                    delay("Updated successfully!!", n);
                    accounts[i].age = try;
                    usleep(800000);
                    system("cls");
                }
                else
                {
                    delay("this age is illegal", n);
                    usleep(800000);
                    goto f;
                }

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

            s:
                system("cls");

                delay("Enter new password: ", n);

                if (scanf("%llu", &accounts[i].password) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto s;
                }
                delay("Updated successfully!!", n);
                usleep(800000);

            q:
                system("cls");

                delay("Enter new balance: ", n);
                if (scanf("%llu", &accounts[i].balance) != 1)
                {
                    delay("invalid Input!", n);
                    usleep(800000);
                    scanf("%*[^\n]");
                    system("cls");
                    goto q;
                }

                delay("Updated successfully!!", n);
                usleep(800000);
                system("cls");

                delay(".....account updated successfully.....", n);
                usleep(800000);
                goto all;

            case 8:
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
    if (scanf("%llu", &all) != 1)
    {
        delay("invalid Input!", n);
        usleep(800000);
        scanf("%*[^\n]");
        system("cls");
        goto Label2;
    }
    Account_ID = search1(all);
    if (Account_ID < MAX_USER && Account_ID >= 0)
    {
        delay("valid Account ID!!", n);
        usleep(800000);
    Label1:
        system("cls");
        delay("Enter Account Password: ", n);
        fflush(stdin);
        if (scanf("%llu", &Password) != 1)
        {
            delay("invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto Label1;
        }
        if (Password == accounts[Account_ID].password)
        {

            delay("Valid Password!!", n);

            usleep(800000);
        f:
            system("cls");
            delay("Account name:", n);
            delay(accounts[Account_ID].Name, n);
            delay("\nAre you sure You want to Delete this Account?\nEnter [1] to Delete:", n);
            if (scanf("%llu", &Choice1) != 1)
            {
                delay("invalid Input!", n);
                usleep(800000);
                scanf("%*[^\n]");
                system("cls");
                goto f;
            }

            switch (Choice1)
            {
            case 1:
                accounts[Account_ID].age = 0;
                accounts[Account_ID].balance = 0;
                accounts[Account_ID].password = 0;
                accounts[Account_ID].Id = 0;
                memset(accounts[Account_ID].phoneNumber, '0', 11);
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
        if (scanf("%d", &Choice) != 1)
        {
            delay("invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
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
    if (scanf("%d", &all) != 1)
    {
        delay("invalid Input!", n);
        usleep(800000);
        scanf("%*[^\n]");
        system("cls");
        goto al;
    }
    IdIndex = search1(all);
    if (IdIndex >= 0)
    {
    again:
        system("cls");
        printf("\n=====================================================================================================================\n");
        printf("%-20s %-15s %-15s %-15s %-15s %-20s", "Holder", "type", "Balance", "age", "address", "Phone number");
        printf("\n=====================================================================================================================\n");
        printf("%-20s %-15s %-15llu %-15lu %-15s 0%-20llu", accounts[IdIndex].Name, accounts[IdIndex].acountType, accounts[IdIndex].balance, accounts[IdIndex].age, accounts[IdIndex].address, accounts[IdIndex].phoneNumber);
        printf("\n=====================================================================================================================\n");

        delay("1.search for another account \n2.Admin options", n);
        delay("\nEnter your choice:", n);
        if (scanf("%d", &see) != 1)
        {
            delay("invalid Input!", n);
            usleep(800000);
            scanf("%*[^\n]");
            system("cls");
            goto again;
        }
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
    if (scanf("%d", &cass) != 1)
    {
        delay("invalid Input!", n);
        usleep(800000);
        scanf("%*[^\n]");
        system("cls");
        goto all;
    }
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
    invalid:
        system("cls");

        delay("1.Admin Moode\n", n);
        delay("2.User Moode\n", n);
        delay("3.Quit\n", n);
        delay("Enter your choice:", n);

        if (scanf("%d", &choice) != 1)
        {
            delay("Invalid input", n);

            scanf("%*[^\n]");
            usleep(800000);
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
