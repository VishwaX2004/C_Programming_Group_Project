#include <stdio.h>
#include <string.h>

<<<<<<< Updated upstream
// Define file admin.txt
=======
>>>>>>> Stashed changes
#define FILENAME "Admin.txt"

int mainpage();
<<<<<<< Updated upstream
int AdminLoginUI();
void AdminLogin();
void candidate();
=======
int AdminLogin();
void candidate();
void voterRegister();
>>>>>>> Stashed changes

int userinputRL;
int userinputMP;
int AdminInput;
<<<<<<< Updated upstream

// Helper function to remove the newline character from a string read by fgets
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(){

    do {
        printf("\n");
 
        userinputMP = mainpage();

        switch (userinputMP){

                case 1:
                    // If 'Voter Registration / Login' is chosen, enter a new loop
                    do {
                        userinputRL = VoterLogReg();

                        switch (userinputRL){

                            case 1:
                                printf("\n       ----! Registration selected !----\n");
                                break;

                            case 2:
                                printf("\n       ----! Login selected !----\n");
                                break;

                            case 3:
                                break;

                            case 4:
                                printf("Exiting system...\n");
                                userinputMP = 4;
                                break;

                           default:
                                printf("\n");
                                printf("\x1b[1;31m");
                                printf("\n       ----! invalied Choice !----\n");
                                printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
                                printf("\x1b[0m");
                                printf("\n");
                            }

                    // FIXED LOOP CONDITION: Removed redundant check (userinputRL < 1 || userinputRL > 4)
                    } while(userinputRL != 3 && userinputRL != 4);

                    break; 

                case 2:
                    printf("\n       ----! Canditdate Registration selected !----\n");
                    candidate();
                    break;

                case 3:
                    // Admin Login logic
                    printf("\n       ----! Admin Login selected !----\n");
                        do{
                            AdminInput = AdminLoginUI();

                            switch(AdminInput){

                                case 1:
                                    // FIXED ADMIN LOGIN LOGIC
                                    AdminLogin(); // Print header

                                    // Correctly declare user input as strings (character arrays)
                                    char Adminusername[10];
                                    char AdminPassWord[10];
                                    
                                    char file_username[10];
                                    char file_password[10];

                                    printf("\x1b[1;32m");
                                    printf("   --Enter Admin Login Informations-- \n");
                                    printf("\x1b[1;0m");

                                    // Get Username
                                    printf("\x1b[1;36m");
                                    printf("\n  Username : ");
                                    printf("\x1b[1;0m");
                                    // Use fgets for safer input reading
                                    fgets(Adminusername, 10 , stdin);
                                    remove_newline(Adminusername);

                                    // Get Password
                                    printf("\x1b[1;36m");
                                    printf("  Password : ");
                                    printf("\x1b[1;0m");
                                    // Use fgets for safer input reading
                                    fgets(AdminPassWord, 10 , stdin);
                                    remove_newline(AdminPassWord);
                                    
                                    // File reading and comparison
                                    FILE *fptr = fopen("Admin.txt","r");
                                    int login_success = 0;

                                    if (fptr == NULL) {
                                        printf("\n\x1b[1;31m----! Error opening Admin.txt !----\x1b[0m\n");
                                        break;
                                    }
                                    
                                    // Read username from file (first line)
                                    if (fgets(file_username, 10 , fptr) != NULL) {
                                        remove_newline(file_username);

                                        // Read password from file (second line)
                                        if (fgets(file_password, 10 , fptr) != NULL) {
                                            remove_newline(file_password);
                                            
                                            // Compare
                                            if (strcmp(Adminusername, file_username) == 0 && strcmp(AdminPassWord, file_password) == 0) 
                                            {
                                                printf("\n\x1b[1;32m       ----! Admin Login Success !----\x1b[0m\n");
                                                login_success = 1;

                                            } else{
                                                 printf("\n\x1b[1;31m       ----! Invalid Username or Password !----\x1b[0m\n");
                                            }
                                        }
                                    }
                                    
                                    fclose(fptr);
                                    
                                    break;

                                case 4: // Go back to Main Page
                                    printf("\n       ----! Go back to Main Page selected !----\n");
                                    break;

                                case 3: // Exit
                                    printf("Exiting System...\n");
                                    userinputMP = 4; // Set main page input to exit main loop
                                    break;


                                default:
                                     printf("\n");
                                    printf("\x1b[1;31m");
                                    printf("\n       ----! invalied Choice !----\n");
                                    printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
                                    printf("\x1b[0m");
                                    printf("\n");
                            }
                        }while(AdminInput != 4 && AdminInput != 3);

                    break;

                case 4:
                    printf("Exiting system...\n");
                    break;

                default:
                    printf("\n");
                    printf("\x1b[1;31m");
                    printf("\n       ----! invalied Choice !----\n");
                    printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
                    printf("\x1b[0m");
                    printf("\n");

         }
    }while(userinputMP != 4);

    return 0;
=======

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
>>>>>>> Stashed changes
}

struct voter
{
    char NIC[12];
    char name[20];
    int age;
    char password[8];
};

<<<<<<< Updated upstream
=======
int main()
{

    do
    {
        printf("\n");

        userinputMP = mainpage();

        switch (userinputMP)
        {

        case 1:
            voterRegister();
            break;

        case 2:
            printf("\n       ----! Canditdate Registration selected !----\n");
            candidate();
            break;

        case 3:
            printf("\n       ----! Admin Login selected !----\n");
            AdminLogin();

            break;

        case 4:
            printf("Exiting system...\n");
            break;

        default:
            printf("\n");
            printf("\x1b[1;31m");
            printf("\n       ----! invalied Choice !----\n");
            printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
            printf("\x1b[0m");
            printf("\n");
        }
    } while (userinputMP != 4);

    return 0;
}

>>>>>>> Stashed changes
int mainpage()
{

    printf("\n");
    int choiceMP;
<<<<<<< Updated upstream
        printf("\x1b[0m");
        printf("+------------------------------------+\n");
        printf("|                                    |\n");
        printf("|\x1b[1;33m           !!WELCOME!!             \x1b[0m |\n");
        printf("|\x1b[1;33m               TO                  \x1b[0m |\n");
        printf("|\x1b[1;33m   GAMPAHA ELECTION VOTING SYSTEM  \x1b[0m |\n");
        printf("|                                    |\n");
        printf("|------------------------------------|\n");
        printf("|                                    |\n");
        printf("|\x1b[1;36m    1. Voter Registration / Login  \x1b[0m |\n");
        printf("|\x1b[1;36m    2. Canditdate Registration     \x1b[0m |\n");
        printf("|\x1b[1;36m    3. Admin Login                 \x1b[0m |\n");
        printf("|\x1b[1;36m    4. Exit                        \x1b[0m |\n");
        printf("|                                    |\n");
        printf("+------------------------------------+\n");
        printf("\n");
        printf("\x1b[1;32m");
        printf("  Enter Your Choice: ");
        printf("\x1b[1;0m");
        printf("\x1b[1;36m");
        // Replaced scanf with fgets/sscanf for safer input reading of the integer choice.
        char buffer[10];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choiceMP);
        printf("\x1b[0m");
=======
    printf("\x1b[0m");
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|\x1b[1;33m           !!WELCOME!!             \x1b[0m |\n");
    printf("|\x1b[1;33m               TO                  \x1b[0m |\n");
    printf("|\x1b[1;33m   GAMPAHA ELECTION VOTING SYSTEM  \x1b[0m |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|                                    |\n");
    printf("|\x1b[1;36m    1. Voter Registration / Login  \x1b[0m |\n");
    printf("|\x1b[1;36m    2. Canditdate Registration     \x1b[0m |\n");
    printf("|\x1b[1;36m    3. Admin Login                 \x1b[0m |\n");
    printf("|\x1b[1;36m    4. Exit                        \x1b[0m |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    printf("\n");
    printf("\x1b[1;32m");
    printf("  Enter Your Choice: ");
    printf("\x1b[1;0m");
    printf("\x1b[1;36m");
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &choiceMP);
    printf("\x1b[0m");
>>>>>>> Stashed changes

    return choiceMP;
}

int AdminLogin()
{

    printf("\n");
    int choiceAdmin;

    printf("\x1b[0m");
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|\x1b[1;33m         -- Admin Panel --         \x1b[0m |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|                                    |\n");
    printf("|\x1b[1;36m    1. Admin Login    \x1b[0m              |\n");
    printf("|\x1b[1;36m    4. Go back to Main Page        \x1b[0m |\n");
    printf("|\x1b[1;36m    3. Exit                        \x1b[0m |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    printf("\n");
    printf("\x1b[1;32m");
    printf("  Enter Your Choice: ");
    printf("\x1b[1;0m");
    printf("\x1b[1;36m");
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &choiceAdmin);
    printf("\x1b[0m");

    do
    {
        switch (choiceAdmin)
        {

        case 1:
            printf("\n");
            printf("\x1b[0m");
            printf("+------------------------------------+\n");
            printf("|                                    |\n");
            printf("|\x1b[1;33m          -- Admin Panel --     \x1b[0m    |\n");
            printf("|                                    |\n");
            printf("+------------------------------------+\n");
            printf("\n");

            char Adminusername[10];
            char AdminPassWord[10];

            char file_username[10];
            char file_password[10];

            printf("\x1b[1;32m");
            printf("   --Enter Admin Login Informations-- \n");
            printf("\x1b[1;0m");

            printf("\x1b[1;36m");
            printf("\n  Username : ");
            printf("\x1b[1;0m");
            fgets(Adminusername, 10, stdin);
            remove_newline(Adminusername);

            printf("\x1b[1;36m");
            printf("  Password : ");
            printf("\x1b[1;0m");
            fgets(AdminPassWord, 10, stdin);
            remove_newline(AdminPassWord);

            FILE *fptr = fopen("Admin.txt", "r");
            int login_success = 0;

            if (fptr == NULL)
            {
                printf("\n\x1b[1;31m----! Error opening Admin.txt !----\x1b[0m\n");
                break;
            }

            if (fgets(file_username, 10, fptr) != NULL)
            {
                remove_newline(file_username);

                if (fgets(file_password, 10, fptr) != NULL)
                {
                    remove_newline(file_password);

                    if (strcmp(Adminusername, file_username) == 0 && strcmp(AdminPassWord, file_password) == 0)
                    {
                        printf("\n\x1b[1;32m       ----! Admin Login Success !----\x1b[0m\n");
                        login_success = 1;
                    }
                    else
                    {
                        printf("\n\x1b[1;31m       ----! Invalid Username or Password !----\x1b[0m\n");
                    }
                }
            }

            fclose(fptr);

            break;

        case 4:
            printf("\n       ----! Go back to Main Page selected !----\n");
            break;

        case 3:
            printf("Exiting System...\n");
            userinputMP = 4;
            break;

        default:
            printf("\n");
            printf("\x1b[1;31m");
            printf("\n       ----! invalied Choice !----\n");
            printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
            printf("\x1b[0m");
            printf("\n");
        }
    } while (choiceAdmin < 1 || choiceAdmin > 4);
}

void candidate()
{
    FILE *pfile = fopen("Candidates.txt", "a");
    char name[100];
    char nic[15];
    char number[5];
    printf("\x1b[0m");
    printf("+------------------------------------------------------------------------------+\n");
    printf("|                                                                              |\n");
    printf("|                  \x1b[1;33m---Candidate Registration---\x1b[0m                                |\n");
    printf("|                                                                              |\n");
    printf("+ ---------------------------------------------------------------------------- +\n");
    printf("|                                                                              |\n");
    printf("|                     Political Party Details                                  |\n");
    printf("|                                                                              |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("|          |    Party No:   |    Party name                         |          |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("|          |        \x1b[1;31m1\x1b[0m       |    \x1b[1;36mNational People's Power\x1b[0m            |          |\n");
    printf("|          |        \x1b[1;31m2\x1b[0m       |    \x1b[1;36mSamagi Jana Balawegaya\x1b[0m             |          |\n");
    printf("|          |        \x1b[1;31m3\x1b[0m       |    \x1b[1;36mNew Democratic Front\x1b[0m               |          |\n");
    printf("|          |        \x1b[1;31m4\x1b[0m       |    \x1b[1;36mSarvajana Balaya\x1b[0m                   |          |\n");
    printf("|          |        \x1b[1;31m5\x1b[0m       |    \x1b[1;36mDemocratic Tamil National Alliance\x1b[0m |          |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("+ ---------------------------------------------------------------------------- +\n");
    printf("\n                   \x1b[1;32mPlease enter your details below\x1b[0m                            \n");
    printf("\x1b[0m");
    printf("\n                   1. Name: ");
    scanf("%s", name);
    printf("\n                   2. Political Party Name: ");
    scanf(" %s", number);
    printf("\n                   3. NIC: ");
    scanf("%s", nic);
    if (strlen(nic) != 12 || number[0] < '1' || number[0] > '5')
    {
        printf("\n                  *Invalid Input");
    }
    else
    {
        char party[100];

        switch (number[0])
        {
        case '1':
            strcpy(party, "National People's Power");
            break;
        case '2':
            strcpy(party, "Samagi Jana Balawegaya");
            break;
        case '3':
            strcpy(party, "New Democratic Front");
            break;
        case '4':
            strcpy(party, "Sarvajana Balaya");
            break;
        default:
            strcpy(party, "Democratic Tamil National Alliance");
            break;
        }

        printf("\n");
        fprintf(pfile, "%-20s   %-12s    %-2s    %s\n", name, nic, number, party);
        printf("+ ---------------------------------------------------------------------------- +\n");
        printf("|                  \x1b[1;33mYour data saved successfully\x1b[0m                                |\n");
        printf("+------------------------------------------------------------------------------+\n");
    }

    fclose(pfile);
}

void voterRegister()
{

    int choiceRL;

    do
    {
        printf("\n");

        printf("\x1b[0m");
        printf("+------------------------------------+\n");
        printf("|                                    |\n");
        printf("|\x1b[1;33m   GAMPAHA ELECTION VOTING SYSTEM  \x1b[0m |\n");
        printf("|                                    |\n");
        printf("|------------------------------------|\n");
        printf("|                                    |\n");
        printf("|   Are You a New or Existing Voter  |\n");
        printf("|                                    |\n");
        printf("|\x1b[1;36m    1. New Voter (Registration)    \x1b[0m |\n");
        printf("|\x1b[1;36m    2. Exsisting voter (login)     \x1b[0m |\n");
        printf("|\x1b[1;36m    3. Go back to Main Page        \x1b[0m |\n");
        printf("|\x1b[1;36m    4. Exit                        \x1b[0m |\n");
        printf("|                                    |\n");
        printf("+------------------------------------+\n");
        printf("\n");
        printf("\x1b[1;32m");
        printf("  Enter Your Choice: ");
        printf("\x1b[1;0m");
        printf("\x1b[1;36m");
        char buffer[10];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choiceRL);
        printf("\x1b[0m");

<<<<<<< Updated upstream
    return choiceRL;
}


int AdminLoginUI(){

     printf("\n");
     int choiceAdmin;

    printf("\x1b[0m"); // Reset color before prompt
        printf("+------------------------------------+\n");
        printf("|                                    |\n");
        printf("|\x1b[1;33m         -- Admin Panel --         \x1b[0m |\n");
        printf("|                                    |\n");
        printf("|------------------------------------|\n");
        printf("|                                    |\n");
        printf("|\x1b[1;36m    1. Admin Login    \x1b[0m              |\n");
        printf("|\x1b[1;36m    4. Go back to Main Page        \x1b[0m |\n");
        printf("|\x1b[1;36m    3. Exit                        \x1b[0m |\n"); 
        printf("|                                    |\n");
        printf("+------------------------------------+\n");
        printf("\n");
        printf("\x1b[1;32m");
        printf("  Enter Your Choice: ");
        printf("\x1b[1;0m");
        printf("\x1b[1;36m");
        char buffer[10];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choiceAdmin);
        printf("\x1b[0m");

    return choiceAdmin;

}


void AdminLogin(){

    printf("\n");
    printf("\x1b[0m"); // Reset color before prompt
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|\x1b[1;33m          -- Admin Panel --     \x1b[0m    |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    printf("\n");
    
}

void candidate(){
    FILE *pfile = fopen("Candidates.txt", "a");
    char name[100];
    char nic[15];
    char number[5];
    printf("\x1b[0m");
    printf("+------------------------------------------------------------------------------+\n");
    printf("|                                                                              |\n");
    printf("|                  \x1b[1;33m---Candidate Registration---\x1b[0m                                |\n");
    printf("|                                                                              |\n");
    printf("+ ---------------------------------------------------------------------------- +\n");
    printf("|                                                                              |\n");
    printf("|                     Political Party Details                                  |\n");
    printf("|                                                                              |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("|          |    Party No:   |    Party name                         |          |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("|          |        \x1b[1;31m1\x1b[0m       |    \x1b[1;36mNational People's Power\x1b[0m            |          |\n");
    printf("|          |        \x1b[1;31m2\x1b[0m       |    \x1b[1;36mSamagi Jana Balawegaya\x1b[0m             |          |\n");
    printf("|          |        \x1b[1;31m3\x1b[0m       |    \x1b[1;36mNew Democratic Front\x1b[0m               |          |\n");
    printf("|          |        \x1b[1;31m4\x1b[0m       |    \x1b[1;36mSarvajana Balaya\x1b[0m                   |          |\n");
    printf("|          |        \x1b[1;31m5\x1b[0m       |    \x1b[1;36mDemocratic Tamil National Alliance\x1b[0m |          |\n");
    printf("|          +----------------+---------------------------------------+          |\n");
    printf("+ ---------------------------------------------------------------------------- +\n");
    printf("\n                   \x1b[1;32mPlease enter your details below\x1b[0m                            \n");
    printf("\x1b[0m");
    printf("\n                   1. Name: ");
    scanf("%s", name);
    printf("\n                   2. Political Party Name: ");
    scanf(" %s", number);
    printf("\n                   3. NIC: ");
    scanf("%s", nic);
    if(strlen(nic) != 12 || number[0] < '1' || number[0] > '5')
    {
        printf("\n                  *Invalid Input");
    }
    else
    {   
        char party[100];

        switch (number[0])
        {
            case '1':
                strcpy(party, "National People's Power");
                break;
            case '2':
                strcpy(party, "Samagi Jana Balawegaya");
                break;
            case '3':
                strcpy(party, "New Democratic Front");
                break;
            case '4':
                strcpy(party, "Sarvajana Balaya");
                break;
            default:
                strcpy(party, "Democratic Tamil National Alliance");
                break;
        }

        printf("\n");
        //char text[] = "%s   %s    %s    %s", name, nic, number, party;
        fprintf(pfile, "%-20s   %-12s    %-2s    %s\n", name, nic, number, party);
        printf("+ ---------------------------------------------------------------------------- +\n");
        printf("|                  \x1b[1;33mYour data saved successfully\x1b[0m                                |\n");
        printf("+------------------------------------------------------------------------------+\n");
    }

    
    fclose(pfile);
=======
        switch (choiceRL)
        {

        case 1:
            printf("\n       ----! Registration selected !----\n");
            struct voter voter;

            voter.NIC[0] = '\0';
            voter.name[0] = '\0';
            voter.age = 0;
            voter.password[0] = '\0';

            printf("\x1b[0m");
            printf("+-------------------------------------------------+\n");
            printf("|                                                 |\n");
            printf("|\x1b[1;33m            --- Voter Registration ---           \x1b[0m|\n");
            printf("|                                                 |\n");
            printf("|-------------------------------------------------|\n");
            printf("|                                                 |\n");
            printf("|         Please enter your details below         |\n");
            printf("|                                                 |\n");
            printf("+-------------------------------------------------+\n");
            printf("\n\n");

            printf("\x1b[1;32m");
            int count = 0;
            while (1)
            {
                printf("\x1b[1;32m");
                printf("\tNIC:");
                printf("\x1b[1;36m");
                scanf("%s", voter.NIC);
                count = 0;
                while (voter.NIC[count] != '\0')
                {
                    count++;
                }
                if (count == 12)
                {
                    break;
                }
                else
                {
                    printf("\x1b[1;31m");
                    printf("\tInvalid NIC. Please enter a valid NIC number.\n");
                }
            }

            FILE *NICFile = fopen("NIC.txt", "w");
            fprintf(NICFile, "%s\n", voter.NIC);
            fclose(NICFile);

            printf("\n");

            printf("\x1b[1;32m");
            printf("\tName:");
            printf("\x1b[1;36m");
            scanf("%s", voter.name);

            printf("\n");

            while (1)
            {
                printf("\x1b[1;33m");
                printf("\t(Note: You must be at least 18 years old to register to vote)\n");
                printf("\n");
                printf("\x1b[1;32m");
                printf("\tAge:");
                printf("\x1b[1;36m");
                scanf("%d", &voter.age);
                if (voter.age >= 18)
                {
                    break;
                }
                else
                {
                    printf("\x1b[1;31m");
                    printf("\tYou must be at least 18 years old to register to vote. Please enter a valid age.\n");
                    printf("\n");
                    printf("\x1b[1;32m");
                }
            }

            printf("\n");

            int count1 = 0;
            while (1)
            {
                printf("\x1b[1;33m");
                printf("\tSet a Password (max 8 characters)\n");
                printf("\x1b[1;32m");
                printf("\tPassword:");
                printf("\x1b[1;36m");
                scanf("%s", voter.password);
                printf("\n");
                count1 = 0;
                while (voter.password[count1] != '\0')
                {
                    count1++;
                }
                if (count1 <= 8)
                {
                    break;
                }
                else
                {
                    printf("\x1b[1;31m");
                    printf("\t\t\t!!Invalid Password. Please enter a valid password!!\n");
                    printf("\n");
                    printf("\x1b[1;32m");
                }
            }

            FILE *passwordFile = fopen("password.txt", "w");
            fprintf(passwordFile, "%s\n", voter.password);
            fclose(passwordFile);

            printf("\n");

            printf("\x1b[1;32m");
            printf("\t\t\t!!!Voter Registration Successful!!!\n");
            printf("\t\tYou can now log in using your NIC and password....\n");
            printf("\n");
            printf("\x1b[0m");

            while (getchar() != '\n');

            break;

        case 2:
            printf("\n       ----! Login selected !----\n");
            break;

        case 3:
            return;

        case 4:
            printf("Exiting system...\n");
            userinputMP = 4;
            return;

        default:
            printf("\n");
            printf("\x1b[1;31m");
            printf("\n       ----! invalied Choice !----\n");
            printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
            printf("\x1b[0m");
            printf("\n");
        }

    } while (choiceRL != 3 && choiceRL != 4);
>>>>>>> Stashed changes
}