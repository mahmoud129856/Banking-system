
#define MAX_USER 100
#define MAX_LOANS 100
/*************** define section *************/
typedef struct
{
    char Id[100];
    char Name[100];
    unsigned int age;
    char address[100];
    char acountType[100];
    long int password;

} account;

typedef struct
{
    char name[100];
    char reason[800];
    int type;
} loan;

account accounts[MAX_USER];
loan loans[MAX_LOANS];

int userCount = 0;

/**************Global variables***************/

void adminSettings();
void userSettings();
void adminLogin();
void userLogin();
void createAccount();
void updateAccount();
void deleteAccount();

/**************functions  Prototype**********/
