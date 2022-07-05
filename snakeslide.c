
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rd()
{
    srand(time(NULL));
	int rem;
	rem = rand() % 6 + 1;

	return rem;
}

void displaychart(int curp,char player[4])
{	int i, j, t, c, sft = 0, diceres;
	
		
	if(curp == 100)
	{
		printf("*****Congratulations*****\n\n\nPlayer %s wins\n", player);
		scanf("%*s");
		exit(0);
	}
	
	for(i = 10; i > 0; i--)
	{
		t = i - 1;
		if((sft % 2) == 0)
		{
			c = 0;
			for(j = 10; j >= 1; j--)
			{
				diceres = (i * j) + (t * c++);
				
				if(curp == diceres)
					printf("%s\t", player);
				else
				printf("%d\t", diceres);
		
			}
			sft++;
		}
		else
		{
			c = 9;
			for(j = 1; j <= 10; j++)
			{
				diceres = (i * j) + (t * c--);
				
				if(curp == diceres)
					printf("%s\t", player);
				else
					printf("%d\t", diceres);
			}
		
			
			sft++;
		}
		printf("\n\n");
	}
	printf("--------------------------------------------------------------------------\n");
}

void slide_and_snake(int *cur, int dice, char player[4])
{
    if(*cur < 101)
    {
		if(*cur == 99) *cur = 1;
		if(*cur == 65) *cur = 40;
		if(*cur == 25) *cur = 9;
        if(*cur == 70) *cur = 93;
		if(*cur == 60) *cur = 83;
		if(*cur == 13) *cur = 42;
		
        displaychart(*cur, player);
						
	}
	else
    {
		*cur = *cur - dice;
		printf("Range exceeded of %s.\n", player);
		displaychart(*cur, player);
	}
}

void main()
{
	int i, dice, cur_pos1 = 0, cur_pos2 = 0, ch;

	while(1)
	{	printf("		** SNAKE AND LADDER GAME** \n\n");
		printf("Snakes:- 25 to 9,\t 65 to 40,\t 99 to  1.\nLadder:- 13 to 42,\t 60 to 83,\t 70 to 93.\n\n");
		printf("Choose your option\n");
		printf("1. Player 1 plays\n");
		printf("2. Player 2 plays\n");
		printf("3. Exit\n");
		scanf("%d", &ch);
	
		switch(ch)
		{
			
			case 1:
            {
                dice=rd();
			    system("cls");
				printf("\t\t\t\tDice = %d\n\n",dice);
				if(dice==6)
                {
                    printf("Dice=6: You have earned a chance to play one more time.\n");
                }
                cur_pos1 += dice;

                slide_and_snake(&cur_pos1, dice, "$P1$");
                
                printf("Player 2 position is %d\n",cur_pos2);
			
				break;
            }
                    

			case 2:
            {
                dice=rd();
                system("cls");
                printf("\t\t\t\tDice = %d\n\n",dice);
                if(dice==6)
                {
                    printf("Dice=6: You have earned a chance to play one more time.\n");
                }
                cur_pos2 += dice;
                
                slide_and_snake(&cur_pos2, dice, "$P2$");
                    
                printf("Player 1 position is %d\n",cur_pos1);
                    
				break;
            }
                    

			case 3:
            {   
                exit(0);
				break;
            }
			
            default:printf("Incorrect choice.Try Again\n");
			
		}
		
	}
	
}