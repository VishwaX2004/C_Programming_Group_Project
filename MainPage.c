#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "Admin.txt"

// Function prototypes
int mainpage();
int AdminLogin();
void candidate();
int voterRegister();

// Global variables for user inputs (though local variables within functions are generally preferred)
int userinputRL;
int userinputMP;
int AdminInput;

// Function prototypes for voting status
int hasAlreadyVoted(char *nic);
void recordVote(char *nic);

// Function to check if a voter's NIC exists in the NIC file
int checkVoterExists(const char *nic)
{
    FILE *file = fopen("NIC.txt", "r");
    if (file == NULL)
    {
        return 0; // File doesn't exist, so voter doesn't exist
    }
}

// Function to remove the trailing newline character from a string
void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

// Structure for voter information
struct voter
{
    char NIC[12];
    char name[20];
    int age;
    char password[8];
};

// Function prototypes for voting menu and vote processing
int remenu();
int reswitch();
int update_votes(const char *candidate_name, const char *party_name);

int choice; // Global variable to store the candidate choice

// Main function
int main()
{
    do
    {
        printf("\n");
        userinputMP = mainpage();

        switch (userinputMP)
        {
        case 1:
            printf("\n       ----! Voter Registration and Login Selected !----\n\n");
            voterRegister();
            break;

        case 2:
            printf("\n       ----! Canditdate Registration selected !----\n\n");
            candidate();
            break;

        case 3:
            printf("\n       ----! Admin Login selected !----\n\n");
            AdminLogin();
            break;

        case 4:
            printf("Exiting system...\n\n");
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

// Function to display the main page menu
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
    char buffer[10];
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &choiceMP);
    printf("\x1b[0m");

    return choiceMP;
}

// Function to handle Admin Login and subsequent options
int AdminLogin()
{
    printf("\n");
    int choiceAdmin;
    int adminchoice;

    printf("\x1b[0m");
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|\x1b[1;33m         -- Admin Panel --         \x1b[0m |\n");
    printf("|                                    |\n");
    printf("|------------------------------------|\n");
    printf("|                                    |\n");
    printf("|\x1b[1;36m    1. Admin Login    \x1b[0m              |\n");
    printf("|\x1b[1;36m    2. Go back to Main Page        \x1b[0m |\n");
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

        printf("\n\x1b[1;36m");
        printf("  Password : ");
        printf("\x1b[1;0m");
        fgets(AdminPassWord, 10, stdin);
        remove_newline(AdminPassWord);

        FILE *fptr = fopen("Admin.txt", "r");

        if (fptr == NULL)
        {
            printf("\n\x1b[1;31m----! Error opening Admin.txt !----\x1b[0m\n");
            break;
        }

        // Read username from file
        if (fgets(file_username, 10, fptr) != NULL)
        {
            remove_newline(file_username);

            // Read password from file
            if (fgets(file_password, 10, fptr) != NULL)
            {
                remove_newline(file_password);

                // Compare entered credentials with file credentials
                if (strcmp(Adminusername, file_username) == 0 && strcmp(AdminPassWord, file_password) == 0)
                {
                    printf("\n\x1b[1;32m       ----! Admin Login Success !----\x1b[0m\n");

                    do
                    {
                        // Admin options menu
                        printf("\n\x1b[0m");
                        printf("+------------------------------------+\n");
                        printf("|                                    |\n");
                        printf("|\x1b[1;33m         -- Admin Panel --         \x1b[0m |\n");
                        printf("|                                    |\n");
                        printf("|------------------------------------|\n");
                        printf("|                                    |\n");
                        printf("|\x1b[1;36m    1. See Voting Result    \x1b[0m        |\n");
                        printf("|\x1b[1;36m    2. Reset Voting                \x1b[0m |\n");
                        printf("|\x1b[1;36m    3. Exit                        \x1b[0m |\n");
                        printf("|                                    |\n");
                        printf("+------------------------------------+\n");
                        printf("\n");
                        printf("\x1b[1;32m");
                        printf("  Enter Your Choice: ");
                        printf("\x1b[1;0m");
                        printf("\x1b[1;36m");
                        scanf("%d", &adminchoice);
                        while (getchar() != '\n')
                            ; // Clear buffer

                        switch (adminchoice)
                        {
                        case 1:
                            printf("\n\x1b[1;32m       ----! Voting Results !----\x1b[0m\n\n");

                            FILE *resultsfile = fopen("results.txt", "r");

                            if (resultsfile == NULL)
                            {
                                printf("\x1b[1;31m       ----! Error! no file founded !----\x1b[0m\n");
                            }
                            else
                            {
                                char Result[1000];
                                int content = 0;

                                printf("\n\x1b[1;36m");
                                printf("+---------------------------------------------------------------+\n");
                                printf("|                       VOTING RESULTS                          |\n");
                                printf("+---------------------------------------------------------------+\n");
                                printf("\n\x1b[0m");

                                // Read and display each line from results.txt
                                while (fgets(Result, sizeof(Result), resultsfile) != NULL)
                                {
                                    content = 1;
                                    printf("  %s", Result);
                                }

                                if (!content)
                                {
                                    printf("\x1b[1;33m       No votes recorded yet.\x1b[0m\n");
                                }

                                fclose(resultsfile);
                            }
                            break; // break for case 1

                        case 2:
                            printf("\n\x1b[1;32m       ----! Reset Voting !----\x1b[0m\n");
                            FILE *pfile = fopen("results.txt", "w");
                            fprintf(pfile, ""); // Clear the contents of results.txt
                            fclose(pfile);

                            // Also clear the voted NICs file
                            FILE *voted_nics_file = fopen("voted_nics.txt", "w");
                            fprintf(voted_nics_file, ""); // Clear the contents of voted_nics.txt
                            fclose(voted_nics_file);

                            printf("\n\x1b[1;32m       ----! Votes Reset Successfull !----\x1b[0m\n");
                            break;

                        case 3:
                            printf("\n\x1b[1;32m       ----! Exiting Admin Panel !----\x1b[0m\n");
                            break;

                        default:
                            printf("\n");
                            printf("\x1b[1;31m");
                            printf("\n       ----! invalied Choice !----\n");
                            printf("\x1b[0m");
                            printf("\n");
                        }

                        printf("\n");

                    } while (adminchoice != 3);
                }
                else
                {
                    printf("\n\x1b[1;31m       ----! Invalid Username or Password !----\x1b[0m\n");
                }
            }
        }

        printf("\n");

        fclose(fptr);
        break;

    case 2:
        printf("\n       ----! Go back to Main Page selected !----\n");
        break;

    case 3:
        printf("Exiting System...\n");
        userinputMP = 4; // Set main menu choice to 4 (Exit)
        break;

    default:
        printf("\n");
        printf("\x1b[1;31m");
        printf("\n       ----! invalied Choice !----\n");
        printf("---! Please Enter A Choice Between 1 TO 3 !---\n");
        printf("\x1b[0m");
        printf("\n");
    }

    return 0;
}

// Function to handle candidate registration
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

    while (getchar() != '\n')
        ; // Clear input buffer

    printf("\n                   1. Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    printf("\n                   2. Political Party Number: ");
    scanf("%s", number);

    printf("\n                   3. NIC: ");
    scanf("%s", nic);

    // Basic input validation
    if (strlen(nic) != 12 || number[0] < '1' || number[0] > '5')
    {
        printf("\n                  *Invalid Input");
    }
    else
    {
        char party[100];

        // Determine party name based on number
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
        case '5':
            strcpy(party, "Democratic Tamil National Alliance");
            break;

        default:
            printf("invalid number");
        }

        printf("\n");
        // Write candidate details to file
        fprintf(pfile, "%-20s   %-12s    %-2s    %s\n", name, nic, number, party);
        printf("+ ---------------------------------------------------------------------------- +\n");
        printf("|                  \x1b[1;33mYour data saved successfully\x1b[0m                                |\n");
        printf("+------------------------------------------------------------------------------+\n");
    }

    fclose(pfile);
}

// Function to handle voter registration and login menu
int voterRegister()
{
    int choiceRL;

    do
    {
        // Voter Registration/Login menu
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

        switch (choiceRL)
        {
        case 1:
            // Voter Registration logic
            printf("\n       ----! Registration selected !----\n");
            struct voter voter;

            // Initialize voter struct
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

            // NIC input and validation
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

            // Write NIC to NIC.txt (overwrites previous)
            FILE *NICFile = fopen("NIC.txt", "w");
            fprintf(NICFile, "%s\n", voter.NIC);
            fclose(NICFile);

            printf("\n");

            while (getchar() != '\n')
                ; // Clear input buffer

            // Name input
            printf("\x1b[1;32m");
            printf("\tName:");
            printf("\x1b[1;36m");
            fgets(voter.name, sizeof(voter.name), stdin);
            voter.name[strcspn(voter.name, "\n")] = 0; // Remove newline

            printf("\n");

            // Age input and validation
            while (1)
            {
                printf("\x1b[1;33m");
                printf("\t(Note: You must be at least 18 years old to register to vote)\n");
                printf("\n");
                printf("\x1b[1;32m");
                printf("\tAge:");
                printf("\x1b[1;36m");
                scanf("%d", &voter.age);
                if (voter.age >= 18 && voter.age < 100) // Corrected age validation
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

            // Password input and validation
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

            // Write password to password.txt (overwrites previous)
            FILE *passwordFile = fopen("password.txt", "w");
            fprintf(passwordFile, "%s\n", voter.password);
            fclose(passwordFile);

            printf("\n");

            printf("\x1b[1;32m");
            printf("\t\t\t!!!Voter Registration Successful!!!\n");
            printf("\t\tYou can now log in using your NIC and password....\n");
            printf("\n");
            printf("\x1b[0m");

            while (getchar() != '\n')
                ; // Clear input buffer
            break;

        case 2:
            // Voter Login logic
            printf("\x1b[0m");
            printf("+-------------------------------------------------+\n");
            printf("|                                                 |\n");
            printf("|\x1b[1;33m               --- Voter Login ---               \x1b[0m|\n");
            printf("|                                                 |\n");
            printf("|-------------------------------------------------|\n");
            printf("|                                                 |\n");
            printf("|         Please enter your login details         |\n");
            printf("|                                                 |\n");
            printf("+-------------------------------------------------+\n");
            printf("\n\n");

            FILE *NICfile = fopen("NIC.txt", "r");
            if (NICfile == NULL)
            {
                printf("\x1b[31mError: Unable to open NIC.txt file.\x1b[0m\n");
                return 1;
            }

            char nicFromFile[13];
            char userInputBuffer[13];

            // Read NIC from file
            if (fgets(nicFromFile, sizeof(nicFromFile), NICfile) == NULL)
            {
                printf("\x1b[31mError: Unable to read NIC from file.\x1b[0m\n");
                fclose(NICfile);
                return 1;
            }
            fclose(NICfile);

            nicFromFile[strcspn(nicFromFile, "\n")] = 0; // Remove newline

            // NIC input and validation loop
            int validNIC = 0;
            while (!validNIC)
            {
                printf("\x1b[1;32m");
                printf("NIC: ");
                printf("\x1b[1;36m");
                if (scanf("%12s", userInputBuffer) != 1)
                {
                    printf("\x1b[31m\x1b[1m!!!Input error!!! Please try again.\n\x1b[0m");
                    while (getchar() != '\n')
                        ;
                    continue;
                }

                // A simplified logic to mimic existence check for the *single* registered voter:
                if (nicFromFile[0] == '\0') // If the file was empty (or not properly read)
                {
                    printf("\x1b[31m\x1b[1m!!!NIC not found! Please register first.!!!\n\x1b[0m");
                }
                else
                {
                    printf("\n");

                    while (getchar() != '\n')
                        ; // Clear buffer

                    if (strcmp(userInputBuffer, nicFromFile) == 0)
                    {
                        // Check if this NIC has already voted
                        if (hasAlreadyVoted(userInputBuffer))
                        {
                            printf("\x1b[31m\x1b[1m!!!NIC number already exists and you cannot vote now!!!\x1b[0m\n");
                            return 0; // Exit voterRegister after failed login due to previous vote
                        }

                        printf("\x1b[32m\x1b[1m!!!NIC number is okay!!!\n\x1b[0m");
                        validNIC = 1;
                    }
                    else
                    {
                        printf("\x1b[31m\x1b[1m!!!Invalid NIC!!! Please try again.\n\x1b[0m");
                    }
                }
            }

            // Note: recordVote is called here *before* password check and actual voting,
            // which is incorrect as it immediately marks the NIC as voted.
            // Moving it to after successful voting.

            // Re-open password file for reading
            passwordFile = fopen("password.txt", "r");
            if (passwordFile == NULL)
            {
                printf("\x1b[31mError: Unable to open password.txt file.\x1b[0m\n");
                // Revert the premature recordVote if it was called here. But since I moved it, this is safe.
                return 1;
            }

            char passwordFromFile[10];
            char userPasswordInput[10];

            // Read password from file
            if (fgets(passwordFromFile, sizeof(passwordFromFile), passwordFile) == NULL)
            {
                printf("\x1b[31mError: Unable to read password from file.\x1b[0m\n");
                fclose(passwordFile);
                return 1;
            }
            fclose(passwordFile);

            passwordFromFile[strcspn(passwordFromFile, "\n")] = 0; // Remove newline
            printf("\n");

            // Password input and validation loop
            while (1)
            {
                printf("\x1b[1;32m");
                printf("Password: ");
                printf("\x1b[1;36m");
                if (scanf("%9s", userPasswordInput) != 1)
                {
                    printf("\x1b[31m\t\t\t!!!Input error!!!\n\x1b[0m");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                while (getchar() != '\n')
                    ;

                if (strcmp(userPasswordInput, passwordFromFile) == 0)
                {
                    printf("\x1b[32m");
                    printf("\t\t\t!!!Password is okay!!!\n\n");
                    printf("\x1b[0m");
                    break;
                }
                else
                {
                    printf("\x1b[31m");
                    printf("\t\t\t!!!Invalid Password!!!\n");
                    printf("\x1b[0m");
                }
            }

            printf("\x1b[32m");
            printf("\t\t\t!!!Login Successful!!!\n\n");
            printf("\t\t -- you are now logged in as a voter --\n");
            printf("\t\t\t-- you can vote now --\n");
            printf("\n");
            printf("\x1b[0m");

            // Proceed to voting
            choice = remenu();
            reswitch();

            // After successful voting, record the NIC
            recordVote(userInputBuffer); // Moved to after successful voting
            break;

        case 3:
            return 0; // Go back to main page

        case 4:
            printf("Exiting system...\n");
            userinputMP = 4;
            return 0;

        default:
            printf("\n");
            printf("\x1b[1;31m");
            printf("\n       ----! invalied Choice !----\n");
            printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
            printf("\x1b[0m");
            printf("\n");
        }

    } while (choiceRL != 3 && choiceRL != 4);

    return 0;
}

// Function to display the candidate selection menu
int remenu()
{
    printf("+---------------------------------------------+\n");
    printf("|     \x1b[1;33m     --- Candidate Selection ---   \x1b[1;0m     |\n");
    printf("|---------------------------------------------|\n");
    printf("|                                             |\n");
    printf("| \x1b[1;36m Party 1: National People's Power     \x1b[1;0m      |\n");
    printf("|                                             |\n");
    printf("|   1. Niroshan Silva                         |\n");
    printf("|   2. Lakmali Perera                         |\n");
    printf("|   3. Dilshan Fernando                       |\n");
    printf("|                                             |\n");
    printf("| \x1b[1;36mParty 2: Samagi Jana Balawegaya         \x1b[1;0m    |\n");
    printf("|                                             |\n");
    printf("|   4. Priyanka Dias                          |\n");
    printf("|   5. Chaminda Jayasinghe                    |\n");
    printf("|   6. Nishadi Bandara                        |\n");
    printf("|                                             |\n");
    printf("|  \x1b[1;36mParty 3: New Democratic Front         \x1b[1;0m     |\n");
    printf("|                                             |\n");
    printf("|   7. Asiri Wijesinghe                       |\n");
    printf("|   8. Kavisha Senanayake                     |\n");
    printf("|   9. Ranidu Rajapaksa                       |\n");
    printf("|                                             |\n");
    printf("|  \x1b[1;36mParty 4: Sarvajana Balaya         \x1b[1;0m         |\n");
    printf("|                                             |\n");
    printf("|   10. Tharushi De Silva                     |\n");
    printf("|   11. Nimesh Hewage                         |\n");
    printf("|   12. Sanali Fonseka                        |\n");
    printf("|                                             |\n");
    printf("| \x1b[1;36mParty 5: Democratic Tamil National Alliance \x1b[1;0m|\n");
    printf("|                                             |\n");
    printf("|   13. Supun Dissanayake                     |\n");
    printf("|   14. Manori Gamage                         |\n");
    printf("|   15. Akila Gunawardena                     |\n");
    printf("|                                             |\n");
    printf("|---------------------------------------------|\n");
    printf("|                                             |\n");
    printf("| \x1b[1;32m  ... Be the change you wish to see...  \x1b[1;0m    |\n");
    printf("| \x1b[1;32m        ... Every Vote Counts! ...   \x1b[1;0m       |\n");
    printf("|                                             |\n");
    printf("+---------------------------------------------+\n");

    printf("\n\x1b[1;33m Enter the number of your chosen candidate (1-15): \x1b[1;0m ");

    // Input choice
    if (scanf("%d", &choice) != 1)
    {
        printf("\n\t--- INVALID INPUT! Please enter a number. ---\n");
        while (getchar() != '\n')
            ; // Clear input buffer
        return remenu(); // Recurse for valid input
    }
    while (getchar() != '\n')
        ; // Clear remaining input buffer

    // Simple input validation
    if (choice < 1 || choice > 15)
    {
        printf("\n\t--- INVALID NUMBER! Please choose a number between 1 and 15. ---\n");
        return remenu(); // Recurse for valid input
    }

    return choice;
}

// Function to process the vote based on the chosen candidate
int reswitch()
{
    FILE *voter_file = fopen("voters.txt", "a");
    if (voter_file == NULL)
    {
        perror("Error opening voters.txt");
        return -1;
    }

    const char *candidate = "";
    const char *party = "";

    // Map choice number to candidate and party names
    switch (choice)
    {
    case 1:
        candidate = "Niroshan Silva";
        party = "National People's Power";
        break;
    case 2:
        candidate = "Lakmali Perera";
        party = "National People's Power";
        break;
    case 3:
        candidate = "Dilshan Fernando";
        party = "National People's Power";
        break;
    case 4:
        candidate = "Priyanka Dias";
        party = "Samagi Jana Balawegaya";
        break;
    case 5:
        candidate = "Chaminda Jayasinghe";
        party = "Samagi Jana Balawegaya";
        break;
    case 6:
        candidate = "Nishadi Bandara";
        party = "Samagi Jana Balawegaya";
        break;
    case 7:
        candidate = "Asiri Wijesinghe";
        party = "New Democratic Front";
        break;
    case 8:
        candidate = "Kavisha Senanayake";
        party = "New Democratic Front";
        break;
    case 9:
        candidate = "Ranidu Rajapaksa";
        party = "New Democratic Front";
        break;
    case 10:
        candidate = "Tharushi De Silva";
        party = "Sarvajana Balaya";
        break;
    case 11:
        candidate = "Nimesh Hewage";
        party = "Sarvajana Balaya";
        break;
    case 12:
        candidate = "Sanali Fonseka";
        party = "Sarvajana Balaya";
        break;
    case 13:
        candidate = "Supun Dissanayake";
        party = "Democratic Tamil National Alliance";
        break;
    case 14:
        candidate = "Manori Gamage";
        party = "Democratic Tamil National Alliance";
        break;
    case 15:
        candidate = "Akila Gunawardena";
        party = "Democratic Tamil National Alliance";
        break;
    default:
        printf("\n\t--- INVALID NUMBER! ---\n");
        fclose(voter_file);
        remenu();
        return reswitch();
    }

    // Record the individual vote in voters.txt
    fprintf(voter_file, "%s (%s):1\n", candidate, party);
    fclose(voter_file);

    // Update the final vote count in results.txt
    update_votes(candidate, party);

    printf("\nSUCCESS! You voted for: %s (%s)\n", candidate, party);
    printf("\t--- Thank you for voting! ---\n");

    return choice;
}

// Function to update the vote counts in results.txt
int update_votes(const char *candidate_name, const char *party_name)
{
    FILE *old_file, *new_file;
    char line[256];
    char temp_file[] = "temp_results.txt";
    char search_string[100];
    int vote_updated = 0;
    int current_votes;

    // Create the search string (only candidate name is used for searching in the existing logic)
    snprintf(search_string, sizeof(search_string), "%s", candidate_name);

    // Open the existing results.txt for reading
    old_file = fopen("results.txt", "r");
    // Open a temporary file for writing
    new_file = fopen(temp_file, "w");

    if (new_file == NULL)
    {
        perror("Error opening temporary file");
        if (old_file != NULL)
            fclose(old_file);
        return -1;
    }

    if (old_file != NULL)
    {
        // Read line by line from the old file
        while (fgets(line, sizeof(line), old_file) != NULL)
        {
            // Check if the current line contains the candidate's name
            if (strstr(line, search_string) != NULL)
            {
                // Found the line, read the current vote count
                char *vote_str = strrchr(line, ':');
                if (vote_str != NULL)
                {
                    current_votes = atoi(vote_str + 1);
                    current_votes++;

                    // Write the updated line to the new file
                    fprintf(new_file, "Current Votes for %s:%d\n", candidate_name, current_votes);
                    vote_updated = 1;
                }
                else
                {
                    // If parsing failed, copy the original line
                    fputs(line, new_file);
                }
            }
            else
            {
                // Not the target line, copy the original line
                fputs(line, new_file);
            }
        }
        fclose(old_file);
    }

    // If the candidate was not found, add them with 1 vote
    if (!vote_updated)
    {
        fprintf(new_file, "Current Votes for %s:%d\n", candidate_name, 1);
    }

    fclose(new_file);

    // Replace the old file with the new file
    remove("results.txt");
    rename(temp_file, "results.txt");
    
    return 0; // Return 0 for success
}

// Helper function to check if NIC has already voted
int hasAlreadyVoted(char *nic)
{
    FILE *votedFile = fopen("voted_nics.txt", "r");
    if (votedFile == NULL)
    {
        return 0; // File doesn't exist yet, so no one has voted
    }

    char line[13];
    while (fgets(line, sizeof(line), votedFile) != NULL)
    {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, nic) == 0)
        {
            fclose(votedFile);
            return 1; // NIC found - already voted
        }
    }

    fclose(votedFile);
    return 0; // NIC not found - hasn't voted yet
}

// Helper function to record a vote
void recordVote(char *nic)
{
    FILE *votedFile = fopen("voted_nics.txt", "a");
    if (votedFile == NULL)
    {
        printf("\x1b[31mError: Unable to record vote.\x1b[0m\n");
        return;
    }

    fprintf(votedFile, "%s\n", nic);
    fclose(votedFile);
}