#include <stdio.h>
#include <string.h>

// Define file admin.txt
#define FILENAME "Admin.txt"

// Function prototypes
int VoterLogReg();
int mainpage();
int AdminLoginUI();
void AdminLogin();

// Variables for user inputs
int userinputRL;
int userinputMP;
int AdminInput;

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
}


int mainpage()
{

    printf("\n");
    int choiceMP;
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

    return choiceMP;
}

int VoterLogReg(){

    printf("\n");
    int choiceRL;

        printf("\x1b[0m"); // Reset color before prompt
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