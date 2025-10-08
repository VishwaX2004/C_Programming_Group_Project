#include <stdio.h>
#include <ctype.h>

// mainpage() is user defined function to print the mainpage ui
// userinputMP is the user input of the MainPage Ui
char mainpage();
char userinputMP;

int main(){

    // do while used to loop function one time before see conditions
    do {
        printf("\n");
        // mainpage() now handles the invalid input loop for non-numeric data
        userinputMP = mainpage();

        switch (userinputMP){

            case '1':
                printf("%d",1);
                break;
            case '2':
                printf("%d",2);
                break;
            case '3':
                printf("%d",3);
                break;
            case '4':
                printf("%d",4);
                break;
            default:
                // This 'default' now only handles numeric input outside the 1-4 range
                printf("\n");
                printf("\x1b[1;31m");
                printf("\n       ----! invalied Choice !----\n");
                printf("---! Please Enter A Choice Between 1 TO 4 !---\n");
                printf("\x1b[0m");
                printf("\n"); 
            }

    }while(userinputMP<'1' || userinputMP>'4');
}


// mainpage function retrun int value
char mainpage()
{
    char choiceMP;
   

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
        scanf("%c", &choiceMP);
        printf("\x1b[0m");

        if(isdigit(choiceMP)){

            choiceMP=choiceMP;

        }else{

            choiceMP=0;
        }

 
    return choiceMP;
}