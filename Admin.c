#include "HeaderFiles.h"

/************* admin function ************/
void adminSettings()
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
void createAccount()
{
}
/**************update*****************/
void updateAccount()
{

    u32 id;
    u8 flag = 0, i;
    u8 check[20], choice, confirm;

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
            printf("5. update passward\n");
            printf("6. update all\n");
            printf("7. back\n");
            printf("\n\nEnter your choice: ");

            scanf("%d", &choice);

            fflush(stdin);
            switch (choice)
            {
            case 1:

                printf("Enter new departure city: ");

                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(trip[i].departureCity, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 2:
                printf("Enter new departure time: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(trip[i].departureTime, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 3:
                printf("Enter new arrival city: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(trip[i].arrivalCity, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 4:
                printf("Enter new arrival time: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(trip[i].arrivalTime, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 5:
                printf("Enter new flight date: ");
                gets(check);
                printf("(1). confirm\n");
                printf("(2). back\n");
                printf("\nEnter your choice: ");
                scanf("%d", &confirm);
                switch (confirm)
                {
                case 1:
                    strcpy(trip[i].flightDate, check);
                    printf("\n******updated successfully******\n\n");
                    goto all;

                case 2:
                    printf("\n***NO changes occurred***\n");
                    goto all;
                }

            case 6:
                printf("\n\nEnter new departure city: ");
                gets(trip[i].departureCity);

                printf("Enter new departure time: ");
                gets(trip[i].departureTime);
                printf("Enter new arrival city: ");
                gets(trip[i].arrivalCity);

                printf("Enter new arrival time: ");
                gets(trip[i].arrivalTime);

                printf("Enter new flight date: ");
                gets(trip[i].flightDate);

                printf("\n\n***Flight schedule updated successfully!***\n\n");
                goto all;

            case 7:
                admin_Settings();
                break;

            default:
                printf("Invalid Input!");
                goto all;
            }
        }
    }
    if (!flag)
    {
        printf("\nFlight schedule not found!\n\n");
        admin_Settings();
    }
}
/**************delete*****************/
void deleteAccount()
{
}
/**************display info*****************/
void displayUserInfo()
{
}
/**************loan informayion*****************/
void loanInformation()
{
}
/**************schedual pattern*****************/
void scheduleLoans()
{
}
/**************tech support*****************/
void supportSection()
{
}
