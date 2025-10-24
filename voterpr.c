#include <stdio.h>
#include <stdlib.h>         //integer to string using atoi
#include <string.h>

// Function 
int remenu();
int reswitch();
int update_votes(const char *candidate_name, const char *party_name); // whatever we dont change candidate name and party in update_votes only read.

int choice;                  //store the integer input from the user

int main() {
    choice = remenu();
    reswitch();
    return 0;
}

                             // Function to display the candidate selection menu and get user input
int remenu() {
    printf("\n");
    printf("+---------------------------------------------+\n");
    printf("|          --- Candidate Selection ---        |\n");
    printf("|---------------------------------------------|\n");
    printf("|                                             |\n");
    printf("| Party 1: National People's Power            |\n");
    printf("|                                             |\n");
    printf("| 1. Niroshan Silva                           |\n");
    printf("| 2. Lakmali Perera                           |\n");
    printf("| 3. Dilshan Fernando                         |\n");
    printf("|                                             |\n");
    printf("| Party 2: Samagi Jana Balawegaya             |\n");
    printf("|                                             |\n");
    printf("| 4. Priyanka Dias                            |\n");
    printf("| 5. Chaminda Jayasinghe                      |\n");
    printf("| 6. Nishadi Bandara                          |\n");
    printf("|                                             |\n");
    printf("| Party 3: New Democratic Front               |\n");
    printf("|                                             |\n");
    printf("| 7. Asiri Wijesinghe                         |\n");
    printf("| 8. Kavisha Senanayake                       |\n");
    printf("| 9. Ranidu Rajapaksa                         |\n");
    printf("|                                             |\n");
    printf("| Party 4: Sarvajana Balaya                   |\n");
    printf("|                                             |\n");
    printf("| 10. Tharushi De Silva                       |\n");
    printf("| 11. Nimesh Hewage                           |\n");
    printf("| 12. Sanali Fonseka                          |\n");
    printf("|                                             |\n");
    printf("| Party 5: Democratic Tamil National Alliance |\n");
    printf("|                                             |\n");
    printf("| 13. Supun Dissanayake                       |\n");
    printf("| 14. Manori Gamage                           |\n");
    printf("| 15. Akila Gunawardena                       |\n");
    printf("|                                             |\n");
    printf("|---------------------------------------------|\n");
    printf("|                                             |\n");
    printf("| -----------!!!!END!!!!!-----------          |\n");
    printf("|                                             |\n");
    printf("+---------------------------------------------+\n");
    printf("\nEnter the number of your chosen candidate (1-15):");
    scanf("%d", &choice);
    
    // Simple input validation
    if (choice < 1 || choice > 15) {
        printf("\n\t--- INVALID NUMBER! Please choose a number between 1 and 15. ---\n");
        return remenu();               // funtion calls it self.
    }
    
    return choice;
}

// Function to handle the user's vote choice
int reswitch() {
    
    FILE *voter_file = fopen("voters.txt", "a");// The voter_file will still be opened in "a" (append) mode  read+write
    if (voter_file == NULL) {
        perror("Error opening voters.txt"); // find system errors and print what is error.. we can use printf but perror is idel.
        return -1;
    }
    
    const char *candidate = "";
    const char *party = "";

    switch (choice) {
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
            remenu();           // call menu funtion 
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

// NEW CORE FUNCTION: Reads and updates the total votes in results.txt
int update_votes(const char *candidate_name, const char *party_name) {
    FILE *old_file, *new_file;  
    char line[256];
    char temp_file[] = "temp_results.txt";          // create temporarily file to stores data.
    char search_string[100];
    int vote_updated = 0;                           //using varible votes update or not.
    int current_votes;

   
    snprintf(search_string, sizeof(search_string), "%s", candidate_name);  // Create the search string......collect different type of data collect and create one string...
    
   
    old_file = fopen("results.txt", "r");            // Open the existing results.txt for reading
   
    new_file = fopen(temp_file, "w");                // Open a temporary file for writing

    if (new_file == NULL) {
        perror("Error opening temporary file");
        if (old_file != NULL) fclose(old_file);
        return -1;      // process is dump... if code is fail sytem gives -1.
    }

    if (old_file != NULL) {
        
        while (fgets(line, sizeof(line), old_file) != NULL) {                              // Read line by line from the old file
           
            if (strstr(line, search_string) != NULL) {      // Check if the current line contains the candidate's name....Something is string search other strings...
                // 
                char *vote_str = strrchr(line, ':');                            // Found the line,if find name then check and  read the current vote count
                if (vote_str != NULL) {
                    current_votes = atoi(vote_str + 1);  // ...ASCII to Integer...check strings and find numbers its convert to integer
                    current_votes++; // Increment the vote count
                    
                    
                    fprintf(new_file, "Current Votes for %s:%d\n", candidate_name, current_votes); // Write the updated line to the new file
                    vote_updated = 1; // find candidate and updated the the value.. 1=updated 0=not updated. 
                } else {
                   
                    fputs(line, new_file);       // If dosent not name.... copy the original line
                }
            } else {
               
                fputs(line, new_file);       // Not the target line, copy the original line
            }
        }
        fclose(old_file);
    }

    
    if (!vote_updated) {  // If the candidate was not found, they must be new, so add them with 1 vote.....New candidate.....
        
        fprintf(new_file, "Current Votes for %s:%d\n", candidate_name, 1);          // This is where a new candidate entry is made with a vote of 1
    }
    
    fclose(new_file);

    
    remove("results.txt");                          // remove old file rename temp_file to results file...
    rename(temp_file, "results.txt");           
    
    return 0;
}