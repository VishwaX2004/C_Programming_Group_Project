#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void candidate();

void main()
{

    candidate();

}

void candidate()
{
    FILE *pfile = fopen("Candidates.txt", "a");
    char name[100];
    char nic[15];
    char number[5];
    int party_number; // Use an integer for the number for better control

    if (pfile == NULL) {
        printf("\n\x1b[1;31m----! Error opening Candidates.txt !----\x1b[0m\n");
        return;
    }

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

    // Clear input buffer before the first input (This was already present)
    // while (getchar() != '\n'); // Removed this as it was after mainpage input, which is now fixed in mainpage.

    printf("\n                   1. Name: ");
    fgets(name, sizeof(name), stdin);
    remove_newline(name); // Remove newline

    printf("\n                   2. Political Party Number: ");
    // Use fgets to read the number as a string, then convert/validate
    fgets(number, sizeof(number), stdin);
    remove_newline(number);
    party_number = atoi(number); // Convert to integer for easier validation

    printf("\n                   3. NIC: ");
    // Use fgets to read the NIC
    fgets(nic, sizeof(nic), stdin);
    remove_newline(nic);

    // Basic input validation
    // Changed condition to use party_number and strlen(nic)
    if (strlen(nic) != 12 || party_number < 1 || party_number > 5)
    {
        printf("\n                  \x1b[1;31m*Invalid NIC length (must be 12) or Invalid Party Number (must be 1-5).\x1b[0m\n");
    }
    else
    {
        char party[100];

        // Determine party name based on number
        switch (party_number) // Use the converted integer
        {
        case 1:
            strcpy(party, "National People's Power");
            break;
        case 2:
            strcpy(party, "Samagi Jana Balawegaya");
            break;
        case 3:
            strcpy(party, "New Democratic Front");
            break;
        case 4:
            strcpy(party, "Sarvajana Balaya");
            break;
        case 5:
            strcpy(party, "Democratic Tamil National Alliance");
            break;

        default:
            // Should not happen due to validation above, but good practice
            strcpy(party, "Unknown Party");
            printf("\n\x1b[1;31minvalid number - data not saved\x1b[0m\n");
            fclose(pfile);
            return;
        }

        printf("\n");
        // Write candidate details to file, using the original string representation for party number
        fprintf(pfile, "%-20s   %-12s    %-2s    %s\n", name, nic, number, party);
        printf("+ ---------------------------------------------------------------------------- +\n");
        printf("|                  \x1b[1;33mYour data saved successfully\x1b[0m                                |\n");
        printf("+------------------------------------------------------------------------------+\n");
    }

    fclose(pfile);
}
