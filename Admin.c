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
void reateAccount()
{
}
/**************update*****************/
void updateAccount()
{
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
