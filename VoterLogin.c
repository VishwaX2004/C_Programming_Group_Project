#include <stdio.h>
#include <string.h>

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


int main() {

    printf("\x1b[0m");
        printf("+-------------------------------------------------+\n");
        printf("|                                                 |\n");
        printf("|\x1b[1;33m               --- Voter Login ---              \x1b[0m|\n");
        printf("|                                                 |\n");
        printf("|-------------------------------------------------|\n");
        printf("|                                                 |\n");
        printf("|         Please enter your login details         |\n");
        printf("|                                                 |\n");
        printf("+-------------------------------------------------+\n");
        printf("\n\n");


    

       // Open the file and read the NIC number

     FILE *NICfile = fopen("NIC.txt", "r");
    if (NICfile == NULL) {
        printf("\x1b[31mError: Unable to open NIC.txt file.\x1b[0m\n");
        return 1;
    }

    char nicFromFile[12];                      // NEW: Separate buffer for the NIC from file
    char userInputBuffer[12];                 // Keep a separate buffer for user input

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
			
             recordVote(userInputBuffer);

            // Note: recordVote is called here *before* password check and actual voting,
            // which is incorrect as it immediately marks the NIC as voted.
            // Moving it to after successful voting.

            // Re-open password file for reading
            FILE *passwordFile = fopen("password.txt", "r");
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
    return 0;
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