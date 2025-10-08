#include <stdio.h>

// Function prototypes
int VoterLogReg();
int mainpage();

// Variables for user inputs
int userinputRL;
int userinputMP;

int main(){

    do {
        printf("\n");
 
        userinputMP = mainpage();

        switch (userinputMP){

                case 1:
                    // If 'Voter Registration / Login' is chosen, enter a new loop
                    // to handle the options within VoterLogReg.
                    do {
                        userinputRL = VoterLogReg();

                        switch (userinputRL){

                            case 1:
                                // New Voter (Registration) logic goes here
                                // For now, just a placeholder message
                                printf("\n       ----! Registration selected !----\n");
                                break;

                            case 2:
                                // Existing voter (login) logic goes here
                                printf("\n       ----! Login selected !----\n");
                                break;

                            case 3:
                                // Go back to Main Page
                                // This 'break' exits the inner do-while loop for VoterLogReg()
                                break;

                            case 4:
                                printf("Exiting system...\n");
                                // Set userinputMP to 4 to also exit the main do-while loop
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

                    } while(userinputRL != 3 && userinputRL != 4 && (userinputRL < 1 || userinputRL > 4));

                    break; // break from the mainpage switch case 1

                case 2:
                    // Canditdate Registration logic
                    printf("\n       ----! Canditdate Registration selected !----\n");
                    break;

                case 3:
                    // Admin Login logic
                    printf("\n       ----! Admin Login selected !----\n");
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
    // Continue loop until user chooses 'Exit' (case 4)
    }while(userinputMP != 4);

    return 0; // Standard practice to return 0 from main
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
        // Using %*c to consume the newline left by previous inputs if any, though
        // not strictly necessary here since mainpage() is called first.
        scanf("%d", &choiceMP);
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
        scanf("%d", &choiceRL);
        printf("\x1b[0m");

    return choiceRL;
}