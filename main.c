#include <stdio.h>

int main()
{
    int chouce = 0;
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
        default:
            printf("Invalid choice!\n");
        }
    }
}
