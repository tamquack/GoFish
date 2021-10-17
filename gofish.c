#include <stdio.h>
#include "card.h"
#include "player.h"
#include "deck.h"
#include "gofish.h"
int main(int args, char* argv[]) {
     
     int turncounter = 1;
     int winner = 1;

     char Guess, GuessRank[2],GuessR, bookcheck;
     char YorN[1] ;
     char replay[20] ;
     struct card fish;
	 shuffle();
	 do{
	 reset_player(&user);
	 reset_player(&computer); 
     deal_player_cards(&user);
     deal_player_cards(&computer);
     
     while (1 == 1){
	 hand(&user);
    	 book(&user);
     	 book(&computer);

	 //if (1==1)
	 	if (game_over(&user) == 1 || game_over(&computer) == 1)
			{
			break;
			}
		if (turncounter % 2 == 1) // PLAYER TURN
		{
			user_play(&user); 
			if (search(&computer,GuessRank) == 0)// Guess = 1 if found
			//if (Guess == 0)
			{
				printf("   - Player 2 has no %ss\n",GuessRank);
				fish = deck_instance.list[deck_instance.top_card];
				add_card(&user,next_card());
				printf("   - Go Fish, Player 1 draws %c%c%c\n",fish.rank[0],fish.rank[1],fish.suit);			   
				bookcheck = check_add_book(&user);

				if (bookcheck != '\0')
				{
						printf("   - Player 1 books %c\n  - Player 1 gets another turn\n", bookcheck);
				} 
				
				else
					{
						printf("   - Player 2's turn\n");
						turncounter++;
					}			
			}

			else
			{
			//DispResult(GuessRank); 
				transfer_cards(&computer,&user,GuessRank);
				check_add_book(&user);
				if (bookcheck != '\0')
				{
				printf("   - Player 1 books %c\n", bookcheck);
				}
				printf("   - Player 1 gets another turn\n");
				
			}
		} // end of player turn


		else
		{ // COMPUTER TURN
			GuessR = computer_play(&user);
			printf("Player 2's turn, enter a Rank: \n");
			if (Guess == 0)
			{
				printf("   - Player 1 has no %cs\n",GuessR);
			fish = deck_instance.list[deck_instance.top_card];
			add_card(&computer,next_card());
			printf("   - Go Fish, Player 2 draws %c%c%c\n",fish.rank[0],fish.rank[1],fish.suit);			   
			bookcheck = check_add_book(&computer);

			if (bookcheck != '\0')
				{
					printf("   - Player 2 books %c\n  - Player 2 gets another turn\n", bookcheck);
				}
			else{
				printf("   - Player 1's turnBBB\n");
				turncounter++;

				}
			
			
			}

				else
			{
					//DispResult(GuessR); 
				transfer_cards(&user,&computer,GuessR);
				 
				if (check_add_book(&computer))
					{
					printf("   - Player 2 books %c\n  - Player 2 gets another turn\n", bookcheck); 
					}
				else{
				printf("   - Player 1's turnCCC\n");
				turncounter++;

				}
			}
		}


			

	} // close the while loop
	if (game_over(&computer) == 1)
	{
	winner = 2;
	}
	else
	{
	winner = 1;
	}

	printf("Player %d Wins! %d-%d\nDo you want to play again[Y/N]:\n",winner,7,6);
	scanf("%s",replay);
	while(replay != 'Y' || replay != 'N'){
		if (replay == 'N'){
			break; 
		}
		else if(replay == 'Y'){
			shuffle();
			break;
		}
		else{
			printf("Please enter Y/N:\n");

		}
	}
if (replay == 'N'){
	break; 
} 
    
}while(1);

}

void hand(struct player* target){
	struct hand* temp = target->card_list; 
	printf("\nPlayer 1's Hand:");
	if (target->hand_size == 0){
		printf("\n");
		return; 
	}
for (int i = 0; i < target->hand_size; i++){
	printf(" %s%s%c",temp->top.rank[1], temp->top.rank[0], temp->top.suit );
}
}
void book(struct player* target)
{
	if (target->book == NULL || target->book[0] == '\0' || target == NULL){
		printf("\n"); 
		return;
	}
	for(int i = 0; i < 7 && target->book[i] != '\0'; i ++){
		printf("%s ", target->book[i]); 
	}
	printf("\n"); 
}

void DispResult(){}
