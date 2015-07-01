//main_test.c
//Jeff Skakun
//Test program for the various functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encounters.h"
#include "npc.h"
#include "player_character.h"
#include "random_rolls.h"
#include "mersenne_twist.h"
#include "combat.h"
#include "map_tiles.h"

//Total # of rolls for testing purposes
const int TOTAL=100000;

//Function to test encounters.c
void encounters_test();

//Function to test npc.c
void npc_test();

//Function to test player_character.c
void player_character_test();

//Function to test random_rolls.c
void random_rolls_test();

//Function to test combat.c
void combat_test();

//Function to test map_tiles.h
void map_test();

//Function to print main menu
char print_main_menu();

//Function to print directions
void print_directions();

//Function to create a new character
character* new_character();

//Function to play the game
int play_game(character *player);

main()
{
   //test_print();
   
   //encounters_test();
   //npc_test();
   //player_character_test();
   //random_rolls_test();
   //combat_test();
   //map_test();
   
   //Load map tiles
   load_map_tiles();
   
   //Initialize variables
   char choice='\0';
   character *player=NULL;
   int flag=1;
   int game_start=0;
   int i=1;
   
   //Loop for initial menu choice
   while(flag)
   {
      choice=print_main_menu();      
      switch(choice)
      {
         //Start a new game - need to create a new character
         case '1':
            player=create_character();
            
            //Clear buffer
            while(getchar()!='\n');
            
            flag=0;
            game_start=1;
            break;
            
         //Continue a previous game - need to load a character
         case '2':
            player=load_character();

            //Clear buffer
            while(getchar()!='\n');
               
            //Check for valid character
            if(player==NULL)
               printf("\nCharacter wasn't found.\n\n");
            else               
            {
               printf("\n");
               flag=0;
               game_start=1;
            }
            break;
            
         //Exit
         case '3':
               printf("\nThank you for playing!");
               flag=0;
            break;
         
         //Invalid choice
         default:
            printf("\nInvalid choice.\n");
      }
   }
   
   //Game starts
   flag=1;
   
   if(game_start)
   {
      //Display initial instructions
      print_directions();
      
      //Give time for player to read instructions
      printf("Press enter to continue. . .");
      getchar();
      
      while(i)
      {
         //Start the game
         i=play_game(player);
      }
   }
}

//Function to print main menu
char print_main_menu()
{
   //Initialize variables
   char choice;
   
   //Main menu
   printf("Hello adventurer! Welcome to the dungeon.\n");
   printf("\t1) Start a new game\n");
   printf("\t2) Continue a previous game\n");
   printf("\t3) Exit\n");
   printf("Choice: ");
   scanf("%c",&choice);
   
   //Clear buffer
   while(getchar()!='\n');
   
   return choice;
}

//Function to print directions
void print_directions()
{
   printf("\nDirections and tips:\n");
   printf("Moving: The available directions for each tile will be printed at the bottom.\n");
   printf("\tn for North, e for East, s for South, w for West, d for down (when you find the stairs)\n");
   printf("Other commands are available:\n");
   printf("Enter c to display various information about your character\n");
   printf("Enter p to save your character\n");
   printf("Enter i to display these instructions again\n");
   printf("Enter q to quit the game - Caution: this does not save your game before quitting!\n\n");
}

//Function to create a new character
character* new_character()
{
   character *p;
   p=create_character();
   
   return p;
}

//Function to play the game
//Return 0 if player is dead or player quit
//Return 1 if player decends
int play_game(character *player)
{
   //Set seed for mersenne_twist prng
   unsigned long init[4]={time(NULL),(time(NULL)>>1),(time(NULL)<<2),(time(NULL)<<5)}, length=4;
   init_by_array(init, length);
   
   //Initialize variables
   int dung_lvl=player->dungeon_level;   
   map_tile *map=malloc(sizeof(map_tile));
   map_tile *current=malloc(sizeof(map_tile));
   char input='y';
   int flag=1;
   
   //Loop to play the game
   while(1)
   {
      //Generate the map
      map=generate_map(dung_lvl,map);
      current=map;
      
      //Print dungeon level
      printf("\nWelcome to level %d, %s\n",dung_lvl,player->name);
      
      //Loop to traverse the map
      while(input!='q')
      {
         //Check for character leveling
         modify_experience(player,0);
         
         //Print map tile
         print_tile(current);
         
         //Increase rooms explored
         player->rooms_explored++;
         
         //Check for stairs
         if(current->stairs)
            printf("There are stairs down to the next level here, go down?\n");
         printf("Which way do you want to go? ");
         scanf("%c",&input);
         
         //Clear buffer
         while(getchar()!='\n');
         
         switch(input)
         {
            //Player goes north
            case 'N':
            case 'n':
               //Check if north is a valid option
               if(current->n)
               {
                  current=current->north_ptr;
                  
                  //Check random encounter
                  flag=encounter(player);
               }
               else
                  printf("Sorry, there is no path north.\n");
               break;
               
            //Player goes east
            case 'E':
            case 'e':
               //Check if east is a valid option
               if(current->e)
               {
                  current=current->east_ptr;
                  
                  //Check random encounter
                  flag=encounter(player);
               }
               else
                  printf("Sorry, there is no path east.\n");
               break;
               
            //Player goes south
            case 'S':
            case 's':
               //Check if south is a valid option
               if(current->s)
               {
                  current=current->south_ptr;
                  
                  //Check random encounter
                  flag=encounter(player);
               }
               else
                  printf("Sorry, there is no path south.\n");
               break;
               
            //Player goes west
            case 'W':
            case 'w':
               //Check if west is a valid option
               if(current->w)
               {
                  current=current->west_ptr;
                  
                  //Check random encounter
                  flag=encounter(player);
               }
               else
                  printf("Sorry, there is no path west.\n");
               break;
               
            //Player goes down a level
            case 'D':
            case 'd':
               //Check if down is a valid option
               if(current->stairs)
               {
                  //Modify lowest level reached
                  lowest_dungeon_level(player,++dung_lvl);
                  
                  //Reset map tiles
                  reset_get_tiles();
                  return 1;
               }
               else
                  printf("Sorry, there are no stairs here.\n");
               break;
               
            //Print character information
            case 'C':
            case 'c':
               //Print character information
               print_level_info(player);
               printf("\n");
               break;
               
            //Save character
            case 'P':
            case 'p':
               //Save character
               save_character(player);
               break;
               
            //Print directions again
            case 'I':
            case 'i':
               //Print directions
               print_directions();
               break;
               
            //Quit
            case 'Q':
            case 'q':
               //Player quit
               printf("\nGoodbye, Thank you for playing.");
               return 0;
               break;
            
            //Invalid choice
            default:
               printf("\nInvalid choice - i to display directions.\n");
         }
         
         //Check for player death
         if(flag==-1)
         {
            //Player dead
            printf("\nYou are dead.  Goodbye.\n");
            return 0;
         }
      }
   }

}
