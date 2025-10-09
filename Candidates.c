#include <stdio.h>
#include <string.h>

void logic();

void main()
{

    logic();

}

void logic(){
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

        //char text[] = "%s   %s    %s    %s", name, nic, number, party;
        fprintf(pfile, "%-20s   %-12s    %-2s    %s\n", name, nic, number, party);
        printf("+ ---------------------------------------------------------------------------- +\n");
        printf("|                  \x1b[1;33mYour data saved successfully\x1b[0m                                |\n");
        printf("+------------------------------------------------------------------------------+\n");
    }

    
    fclose(pfile);
}