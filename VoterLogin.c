#include <stdio.h>
#include <string.h>

int hasAlreadyVoted(char *nic);
void recordVote(char *nic);

int checkVoterExists(const char *nic)
{
    FILE *NICfile = fopen("NIC.txt", "r");
    if (NICfile == NULL)
    {
        return 0;                         // File doesn't exist, so voter doesn't exist
    }

    char line[64];
    int found = 0;
    while (fgets(line, sizeof(line), NICfile) != NULL)
    {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, nic) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(NICfile);
    return found;
}

int main() {

       // Open the file and read the NIC number

     FILE *NICFile = fopen("NIC.txt", "r");
    if (NICFile == NULL) {
        printf("\x1b[31mError: Unable to open NIC.txt file.\x1b[0m\n");
        return 1;
    }

    char nicFromFile[12];                      // NEW: Separate buffer for the NIC from file
    char userInputBuffer[12];                 // Keep a separate buffer for user input

   if (fgets(nicFromFile, sizeof(nicFromFile), NICFile) == NULL)
{
    printf("\x1b[31mError: Unable to read NIC from file.\x1b[0m\n");
    fclose(NICFile);
    return 1;
}
    fclose(NICFile);

    // Remove newline character from the NIC read from file
    // as fgets might include it and strcmp will fail the comparison.
    nicFromFile[strcspn(nicFromFile, "\n")] = 0; 

    int validNIC = 0;
    while (!validNIC) {
        printf("\x1b[1;32m");
        printf("NIC: ");
        printf("\x1b[1;36m");
       if (scanf("%12s", userInputBuffer) != 1)
    {
        printf("\x1b[31m\x1b[1m!!!Input error!!! Please try again.\n\x1b[0m");
        while (getchar() != '\n');
        continue;
    }

    if (nicFromFile[0] == '\0')
    {
        printf("\x1b[31m\x1b[1m!!!NIC not found! Please register first.!!!\n\x1b[0m");
    }
    else
    {
        printf("\n");

        while (getchar() != '\n')
            ;

        if (strcmp(userInputBuffer, nicFromFile) == 0)
        {
            // Check if this NIC has already voted
            if (hasAlreadyVoted(userInputBuffer))
            {
                printf("\x1b[31m\x1b[1m!!!NIC number already exists and you cannot vote now!!!\n\x1b[0m");
                return 1; // Exit or handle accordingly
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
       recordVote(userInputBuffer);                        // After successful voting, record the NIC

         FILE *passwordFile = fopen("password.txt", "r"); // opens the text file to read passwords
        char passwordFromFile[9];                      // NEW: Separate buffer for the password from file
        char userPasswordInput[9];                     // Keep a separate buffer for user input
        fgets(passwordFromFile, 9, passwordFile);      // Read password from file into its own buffer
        fclose(passwordFile);

        // Remove newline character from the password read from file
        passwordFromFile[strcspn(passwordFromFile, "\n")] = 0;
        printf("\n");

        while (1) {
        printf("\x1b[1;32m");  // green color
        printf("Password:");
        printf("\x1b[1;36m");  // blue color
        scanf("%8s", userPasswordInput);               // Read user input into the new buffer
        
        if (strcmp(userPasswordInput, passwordFromFile) == 0) {
            printf("\x1b[32m");
            printf("\t\t\t!!!Password is okay!!!\n\n");    // success message
            break;
            printf("\x1b[0m"); // white color
        } else {
            printf("\x1b[31m"); // red color
            printf("\t\t\t!!!Invalid Password!!!\n");        // invalid message
            printf("\x1b[0m"); // white color
        }
    }

        printf("\x1b[32m");
        printf("\t\t\t!!!Login Successful!!!\n\n"); // success message
        printf("\t\t -- you are now logged in as a voter --\n");
        printf("\t\t\t-- you can vote now --\n");
        printf("\n");
        printf("\x1b[0m");  //white color   
        
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
    return 0;               // NIC not found - hasn't voted yet
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
