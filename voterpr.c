#include<stdio.h>

	int remenu();  //create user define function for candidate selection interface
    int reswitch();  //create user define function for switch case


	int choice;

	int main(){
        FILE *voter_flie= fopen("voters.txt","a");  //create flie for store voters 
       FILE *result_flie= fopen("results.txt","a"); //create flie for update the result
		
       choice=remenu();
        reswitch();
	
       
    
	return 0;
  

}

	int remenu(){
		
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
	printf("\nEnter the number of your chosen candidate(1-15):");   
	scanf("%d",&choice);    //get user choice and scan 
	
	return choice;
	}
    int reswitch(){
        switch(choice){
		case(1):
		 printf("SUCCESS! You voted for:  Niroshan Silva  (National People's Power )\n");
         printf("\n--- Thank you for voting! ---\n");
		 break;
		case(2):
		printf("SUCCESS! You voted for:  Lakmali Perera   (National People's Power )\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(3):
		printf("SUCCESS! You voted for:  Dilshan Fernando  (National People's Power )\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(4):
		printf("SUCCESS! You voted for:  Priyanka Dias   (Samagi Jana Balawegaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(5):
		printf("SUCCESS! You voted for:  Chaminda Jayasinghe  (Samagi Jana Balawegaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(6):
		printf("SUCCESS! You voted for:  Nishadi Bandara  (Samagi Jana Balawegaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(7):
		printf("SUCCESS! You voted for:  Asiri Wijesinghe  (New Democratic Front)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(8):
		printf("SUCCESS! You voted for:  Kavisha Senanayake   (New Democratic Front)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(9):
		printf("SUCCESS! You voted for:  Ranidu Rajapaksa   (New Democratic Front)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(10):
		printf("SUCCESS! You voted for:  Tharushi De Silva   (Sarvajana Balaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(11):
		printf("SUCCESS! You voted for:  Nimesh Hewage  (Sarvajana Balaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(12):
		printf("SUCCESS! You voted for:  Sanali Fonseka  (Sarvajana Balaya)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(13):
		printf("SUCCESS! You voted for:  Supun Dissanayake  ( Democratic Tamil National Alliance)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(14):
		printf("SUCCESS! You voted for:  Manori Gamage   ( Democratic Tamil National Alliance)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		case(15):
		printf("SUCCESS! You voted for:  Akila Gunawardena  ( Democratic Tamil National Alliance)\n");
         printf("\n--- Thank you for voting! ---\n");
		break;
		default:
        printf("\n--- INVALID NUMBER! ---\n");
        remenu();   //call function 
        reswitch(); //call function itself

       
	return choice;	
	    }
    }