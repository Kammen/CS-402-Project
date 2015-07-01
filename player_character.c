//player_character.c
//Jeff Skakun 10/24/14
//Class to maintain a player character's information
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player_character.h"
#include "random_rolls.h"


//Function to create a new player
character* create_character()
{
   //Initialize variables
   character *player;

   player=malloc(sizeof(character));
   
   //Input name
   printf("Enter name (10 char maximum): ");
   scanf("%s",player->name);
   
   //Set initial current and max health to 20
   player->max_health=20;
   player->current_health=20;
   
   //Set player level to 1
   player->player_level=1;
   
   //Set lowest dungeon level reached to 1
   player->dungeon_level=1;
   
   //Set player current experience to 0
   player->current_experience=0;
   
   //Set player experience to next level
   player->next_level_experience=25;
   
   //Set player damage die
   player->damage_die=6;
   
   //Set player damage modifier
   player->damage_modifier=0;
   
   //Set number of rooms explored to 0
   player->rooms_explored=0;
   
   //Set number of monsters killed to 0
   player->monsters_killed=0;
   
   //Player is set to level 1, return player
   return player;
}

//Function to display basic character information
void print_full_character(character *player)
{
   printf("\nPlayer name:          %s",player->name);
   printf("\nPlayer level:         %d",player->player_level);
   printf("\nCurrent hp:           %d/%d",player->current_health,player->max_health);
   printf("\nCurrent Experience:   %d/%d",player->current_experience,player->next_level_experience);
   printf("\nPlayer damage:        d%d+%d",player->damage_die,player->damage_modifier);
   printf("\nLowest level reached: %d",player->dungeon_level);
   printf("\nRooms explored:       %d",player->rooms_explored);
   printf("\nMonsters killed:      %d",player->monsters_killed);
}

//Function to display name, level, health, and experience
void print_level_info(character *player)
{
   printf("\nPlayer name:          %s",player->name);
   printf("\nPlayer level:         %d",player->player_level);
   printf("\nCurrent hp:           %d/%d",player->current_health,player->max_health);
   printf("\nCurrent Experience:   %d/%d",player->current_experience,player->next_level_experience);
}

//Function to increase the player to the next level
void increase_character_level(character *player)
{
   //Increase player level by 1
   player->player_level++;
   
   //Increase player max hp and set current health equal to max (For now by a flat amount)
   player->max_health+=10;
   player->current_health=player->max_health;
   
   //Determine if there is any overflow experience
   int overflow_exp=player->current_experience - player->next_level_experience;
   
   //Reset player current exeperience to 0 and add back any overflow
   if(overflow_exp<0)
      player->current_experience=0;
   else
      player->current_experience=overflow_exp;
   
   //Set next level experience to new value (For now setting equal to 2x old value)
   player->next_level_experience+=25;
   
   //Not sure about damage die - for now won't change
   //Increase damage modifier by 1 every 2 levels
   if((player->player_level)%2==0)
      player->damage_modifier++;
}

//Function to modify the current health of character
//health_change is negative for damage taken
//health_change is positive for damage healed
void modify_player_health(character *player, int health_change)
{
   //Change current_health
   player->current_health+=health_change;
   
   //Check if current_health > max_health
   //Player can't have more than max_health
   if(player->current_health>player->max_health)
      player->current_health=player->max_health;
}

//Function to modify the current player experience
//Will call function to increase player level if current experience
//exceeds next_level_experience
void modify_experience(character *player, int experience_change)
{
   //Change current_experience
   player->current_experience+=experience_change;
   
   //Check to see player has leveled
   if(player->current_experience>player->next_level_experience)
   {
      printf("\nCongratulations!  You leveled.\n");
      increase_character_level(player);
   }
}

//Function to save a character to file
//Creates a .sav file in the a directory.
void save_character(character *player)
{
   //Code to add ".txt" to end of character name
   char file_name[MAX_FILE_NAME_LENGTH];
   
   //Set correct directory
   strcpy(file_name,SAVE_DIRECTORY);
   
   //Add character name to file name
   strcat(file_name,player->name);
   
   //Add .sav to end of file_name
   strcat(file_name,".sav");

   //Create a file with character name.txt
   FILE *outfile=fopen(file_name,"w");
   
   if(outfile==NULL)
      printf("Fail to create file");
   else
   {
      //Save character information to file
      fprintf(outfile,"%s\n",player->name);
      fprintf(outfile,"%d\n",player->current_health);
      fprintf(outfile,"%d\n",player->max_health);
      fprintf(outfile,"%d\n",player->player_level);
      fprintf(outfile,"%d\n",player->dungeon_level);
      fprintf(outfile,"%d\n",player->current_experience);
      fprintf(outfile,"%d\n",player->next_level_experience);
      fprintf(outfile,"%d\n",player->damage_die);
      fprintf(outfile,"%d\n",player->damage_modifier);
      fprintf(outfile,"%d\n",player->rooms_explored);
      fprintf(outfile,"%d\n",player->monsters_killed);
      
      printf("Character saved.\n\n");
   }
   
   //Close file
   fclose(outfile);
}

//Function to load a character from file
character* load_character()
{
   //Initialize variables
   char file_name[MAX_FILE_NAME_LENGTH];
   char player_name[MAX_NAME_LENGTH];
   FILE *infile;
   character *player=NULL;
   
   //Input name of file to load
   printf("\nName of character to load: ");
   scanf("%s",player_name);
   
   //Set correct directory
   strcpy(file_name,SAVE_DIRECTORY);
   
   //Add character name to file name
   strcat(file_name,player_name);
   
   //Add .sav to end of file_name
   strcat(file_name,".sav");
   
   //Open file
   if((infile=fopen(file_name,"r"))==NULL)
      return NULL;
   else
   {
      player=malloc(sizeof(character));
      fscanf(infile,"%s",player->name);
      fscanf(infile,"%d",&player->current_health);
      fscanf(infile,"%d",&player->max_health);
      fscanf(infile,"%d",&player->player_level);
      fscanf(infile,"%d",&player->dungeon_level);
      fscanf(infile,"%d",&player->current_experience);
      fscanf(infile,"%d",&player->next_level_experience);
      fscanf(infile,"%d",&player->damage_die);
      fscanf(infile,"%d",&player->damage_modifier);
      fscanf(infile,"%d",&player->rooms_explored);
      fscanf(infile,"%d",&player->monsters_killed);
      
      printf("Character loaded.");
      
      //Display full player information
      print_full_character(player);
   }
   
   //Close file
   fclose(infile);
   
   return player;
}

//Function to return player character's current hp
int player_current_hp(character *player)
{
   return player->current_health;
}

//Function to return player characters max hp
int player_max_hp(character *player)
{
   return player->max_health;
}

//Function to check if player character is dead
//Returns <=0 if player is dead
//Returns >0 if player is alive
int player_death(character *player)
{
   return player->current_health;
}

//Function to set the dungeon level reached by player
void lowest_dungeon_level(character *player, int level)
{
   player->dungeon_level=level;
}