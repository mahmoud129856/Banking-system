
#define MAX_USER 100
#define MAX_LOANS 100
/*************** define section *************/
typedef struct
{
    char Id[100] /*Id of user*/;
    char Name[100];       /*name of user*/
    unsigned int age;     /*of user*/
    char address[100];    /*address of user*/
    char acountType[100]; /*Savings/Checking*/
    long int password;    /*of user*/
    long long balance;
} account;

typedef struct
{
    char name[100];   // user who asked for loan
    char reason[800]; // raason for loan
    int type;         // Savings/Checking
} loan;

account accounts[MAX_USER]; // array of accounts
loan loans[MAX_LOANS];      // array of loans

int userCount = 0; // number of users in system

/**************Global variables***************/

void adminSettings();
void userSettings();
void adminLogin();
void userLogin();
void createAccount();
void updateAccount();
void deleteAccount();
void displayUserInfo();
void loanInformation();
void scheduleLoans();
void supportSection();
void systemFace();
void depositCash();
void withdrawCash();
void checkBalance();
void cashTransfer();
void applyForLoan();
void trackingLoan();
void customerSupport();

/**************functions  Prototype**********/
