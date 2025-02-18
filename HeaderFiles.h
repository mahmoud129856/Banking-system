
typedef struct
{
    char Id[100];
    char Name[100];
    unsigned int age;
    char address[100];
    char acountType[100];
    long int password;

} account;

int userCount = 0;

/**************Global variables***************/

void adminSettings();
void userSettings();
/**************functions  Prototype**********/
#define MAX_USER 100
/*************** define section *************/