#include "HeaderFiles.h"
u16 userCount = 0; // number of users in system
u16 loancount = 0; // هنا ضفت عدد الloan الي في ال array بتاعتي علشان تسهل عليه عمليت الcheck بردو

int main()
{
    systemFace();

    return 0;
}

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
            adminSettings();
            break;
        case 2:
            userSettings();
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
/****************** admin login ****************/
U adminLogin()
{
}

/****************** user login ****************/

U userLogin()
{
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