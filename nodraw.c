#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "f1.c"


int main() 
{
	
	printf("%s", stage[0]);
	srand(time(NULL)); // to not repeat word in a game
	
	//word list
	char guesswords[][16] = 
	{
		"bro", 
		"college",
		"flabbergasted",
		"black",
		"pinkfloyd",
		"apple",
        "lmao",
        "alabama",
        "bigoof",
        "okay",
        "pseudonym",
        "pocket",
        "dramatist",
        "football",
        "sociopath"
	};
	
	int randomness = rand() % 15; //15 ota word bhayera mathi
	
	int lives = 6;
	int correctn = 0; //initialize new guess
	int correcto = 0;  //initialize old guess
	int sum = 0; // initialize drawing platform
	
	int wordlength = strlen(guesswords[randomness]); //dash
	
	int guessed[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0}; //longest 13 letter wala words
	
	int quit = 0;	//game initialize
	
	int loopy = 0;
	int reguessed = 0; 
	
	char guess[16];
	char enteredletters;	
	
    printf("\n\nHangman!\nNew Game!!");

	while ( correctn < wordlength ) 
    {
		printf("\n\nNew Turn...\nHangman Word:");
	
		for( loopy = 0; loopy < wordlength; loopy++) 
        {
			if(guessed[loopy] == 1) {
				printf("%c",guesswords[randomness][loopy]);				
			} else {
				printf("-");
			}
		
		}	
		
		printf("\n");
	
		printf("Letters Correct:%d\n",correctn);
		printf("Guess a letter:");
		fgets(guess, 16, stdin);
		
		if( strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}
		
		enteredletters = guess[0];
		reguessed = 0; 
		
		printf("letters entered:%c\n",enteredletters);
		
		correcto = correctn;
		
		for( loopy = 0; loopy < wordlength; loopy++) {
		
			if(guessed[loopy] == 1) {
				if(guesswords[randomness][loopy] == enteredletters) {
					reguessed = 1; 
					break;
				} 
				continue;
			}
		
			if( enteredletters == guesswords[randomness][loopy] ) {
				guessed[loopy] = 1;
				correctn++;				
			}		
		
		}	
		system("cls");
        printf("%s", stage[sum]);
		if( correcto == correctn && reguessed == 0) 
		{
		lives--;
		sum++;
        
		printf("Sorry, wrong guess\n");

      	printf("%s", stage[sum]);
	  	if (lives == 0) 
            {
				break;
			}
		} 
		else if( reguessed == 1)
		{
			printf("Already Guessed!!\n");
		} 
		else 
		{
			printf("Correct guess!!\n");
		}
	
	} 
	
	if( quit == 1 ) {	
		printf("\nquit early\n");
	} else if (lives == 0) {
		printf("\nYou lost! The word was: %s\n", guesswords[randomness]);	
	} else  {	
		printf("\nGoodjob! the word was: %s\nYou Win!!!!!\n", guesswords[randomness]);
	} 
	
	return 0;
}