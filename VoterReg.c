#include <stdio.h>

struct voter {  // structure to hold voter details
    char NIC[12];   // National Identity Card number
    char name[20];  // voter's full name
    int age;
    char password[8]; // voter's account password
};

int main() {

    struct voter voter;

    voter.NIC[0] = '\0';  // initialize NIC to empty string
    voter.name[0] = '\0';  // initialize name to empty string
    voter.age = 0;  // initialize age to 0
    voter.password[0] = '\0';  // initialize password to empty string   



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
        // struct voter declaration moved above

        struct voter;


        printf("\x1b[1;32m");  //green color
        int count = 0;
        while (1) {  // loop to ensure NIC is not empty and has correct length
            printf("\x1b[1;32m");  //green color
            printf("\tNIC:");  // voter's National Identity Card number
            printf("\x1b[1;36m");   //blue color
            scanf("%s", voter.NIC);
            count = 0;
            while (voter.NIC[count] != '\0') {
                count++;
            }
            if (count == 12) {
                break;
            } else {
                printf("\x1b[1;31m"); //red color
                printf("\tInvalid NIC. Please enter a valid NIC number.\n"); //invalid message
            }
        }
        
        
        FILE *NICFile = fopen("NIC.txt", "w"); // creates a text file to store NIC numbers
        fprintf(NICFile, "%s\n", voter.NIC);
        fclose(NICFile);

        printf("\n");
        
        printf("\x1b[1;32m");
        printf("\tName:"); // voter's full name
        printf("\x1b[1;36m");
        scanf("%s", &voter.name);

        printf("\n");

       while (1) {  // loop to ensure age is 18 or above
            printf("\x1b[1;33m");  //yellow color
            printf("\t(Note: You must be at least 18 years old to register to vote)\n");  //printing note
            printf("\n");
            printf("\x1b[1;32m");
            printf("\tAge:"); // voter's age
            printf("\x1b[1;36m");
            scanf("%d", &voter.age);
            if (voter.age >= 18 && voter.age <= 100) {
                break;
            } else {
                printf("\x1b[1;31m"); //red color
                printf("\tYou must be at least 18 years old to register to vote. Please enter a valid age.\n"); //invalid message
                printf("\n");
                printf("\x1b[1;32m");  //green color
            }
        }
        
        printf("\n");

        int count1 = 0;
        while (1) {  // loop to ensure password is not empty and has correct length
            printf("\x1b[1;33m");
            printf("\tSet a Password (max 8 characters)\n"); // instruction to set password
            printf("\x1b[1;32m");
            printf("\tPassword:"); // voter's account password
            printf("\x1b[1;36m");
            scanf("%s", &voter.password);
            printf("\n");
            count1 = 0;
            while (voter.password[count1] != '\0') {
                count1++;
            }
            if (count1 <= 8) {
                break;
            } else {
                printf("\x1b[1;31m"); //red color
                printf("\t\t\t!!Invalid Password. Please enter a valid password!!\n"); //invalid message
                printf("\n");
                printf("\x1b[1;32m");
            }
        }

        FILE *passwordFile = fopen("password.txt", "w");  // creates a text file to store passwords
        fprintf(passwordFile, "%s\n", voter.password);

        printf("\n");

        printf("\x1b[1;32m");
        printf("\t\t\t!!!Voter Registration Successful!!!\n"); // success message
        printf("\t\tYou can now login as a voter using your NIC and password...\n");
        printf("\n");
        printf("\x1b[0m");  //white color

return 0;

}