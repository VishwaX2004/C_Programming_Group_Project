#include <stdio.h>

int adminchoice;

int main(){
    
                    // Admin successfully logged in - display admin sub-menu
                    do
                    {
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
                        case 1: // See Voting Result
                            printf("\n\x1b[1;32m       ----! Voting Results !----\x1b[0m\n\n");

                            // Open results.txt for reading
                            FILE *resultsfile = fopen("results.txt", "r");

                            if (resultsfile == NULL)
                            {
                                printf("\x1b[1;31m       ----! Error! no file founded !----\x1b[0m\n");
                            }
                            else
                            {
                                char Result[1000];
                                int content = 0;

                                // Display results header
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
                            break; // End of case 1

                        case 2: // Reset Voting
                            printf("\n\x1b[1;32m       ----! Reset Voting !----\x1b[0m\n");
                            // Open results.txt in 'w' (write) mode to clear its content
                            FILE *pfile = fopen("results.txt", "w");
                            fprintf(pfile, ""); // Write nothing, effectively clearing the file
                            fclose(pfile);
                            // NOTE: This only clears results.txt. It doesn't clear voters.txt or voted_nics.txt.
                            printf("\n\x1b[1;32m       ----! Votes Reset Successfull !----\x1b[0m\n");
                            break;

                        case 3: // Exit Admin Panel
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

                    } while (adminchoice != 3); // Loop until admin chooses to exit
 
}