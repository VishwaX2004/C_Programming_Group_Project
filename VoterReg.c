#include <stdio.h>

struct voter {
    char NIC[12];
    char name[50];
    int age;
    char password[20];
};

int main() {

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
        // struct voter declaration moved above

        struct voter;

        printf("\tNIC:");  // voter's National Identity Card number
        scanf("%s", &voter.NIC);

        FILE *NICFile = fopen("NIC.txt", "a"); // creates a text file to store NIC numbers
        fprintf(NICFile, "%s\n", voter.NIC);
        fclose(NICFile);

        printf("\n");
        
        printf("\tName:"); // voter's full name
        scanf("%s", &voter.name);
        printf("\n");

        printf("\tAge:"); // voter's age
        scanf("%d", &voter.age);
        printf("\n");

        printf("\tPassword:"); // voter's account password
        scanf("%s", &voter.password);

        FILE *passwordFile = fopen("password.txt", "a");  // creates a text file to store passwords
        fprintf(passwordFile, "%s\n", voter.password);
        printf("\n");






return 0;

}