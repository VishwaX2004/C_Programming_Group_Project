#include <stdio.h>
#include <string.h>

int main() {

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


    

       // Open the file and read the NIC number

     FILE *NICfile = fopen("NIC.txt", "r");
    if (NICfile == NULL) {
        printf("\x1b[31mError: Unable to open NIC.txt file.\x1b[0m\n");
        return 1;
    }

    char nicFromFile[12];                      // NEW: Separate buffer for the NIC from file
    char userInputBuffer[12];                 // Keep a separate buffer for user input

    fgets(nicFromFile, 12, NICfile);        // Read NIC from file into its own buffer
    fclose(NICfile);

    // Remove newline character from the NIC read from file
    // as fgets might include it and strcmp will fail the comparison.
    nicFromFile[strcspn(nicFromFile, "\n")] = 0; 

    int validNIC = 0;
    while (!validNIC) {
        printf("\x1b[1;32m");
        printf("NIC: ");
        printf("\x1b[1;36m");
        scanf("%11s", userInputBuffer);
        getchar();   // flush newline from buffer (fixes double invalid message)

        if (strcmp(userInputBuffer, nicFromFile) == 0) {
            printf("\x1b[32m\t\t\t!!!NIC number is okay!!!\n\x1b[0m");
            validNIC = 1;
        } else {
            printf("\x1b[31m\t\t\t!!!Invalid NIC!!! Please try again.\n\x1b[0m");
        }
    }


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
