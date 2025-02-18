

/************** User function *******************/
void userSettings()
{
    int choice;
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
            mainMenu();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}