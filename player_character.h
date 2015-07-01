//player_character.h
//Jeff Skakun 11/6/14
//Class to maintain a player character's information

#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

//Limit name length to 10
#define MAX_NAME_LENGTH 11
#define MAX_FILE_NAME_LENGTH 30
#define SAVE_DIRECTORY "./SAVES/"

typedef struct character
{
   //Limit length of name to 10 characters
   char name[MAX_NAME_LENGTH];
   
   //Store current health of player
   int current_health;
   
   //Store max health of player
   int max_health;
   
   //Store player level
   int player_level;
   
   //Store dungeon level
   int dungeon_level;
   
   //Store current experience
   int current_experience;
   
   //Store experience required to reach next level
   int next_level_experience;
   
   //Store damage die (ex. d6) Do I need to increase like monsters?
   int damage_die;
   
   //Store damage modifier (+1)
   int damage_modifier;
   
   //Store number of rooms explored
   int rooms_explored;
   
   //Store number of monsters killed
   int monsters_killed;
}character;

//Function to create a new player
character* create_character();

//Function to save a character to file
//Creates a .sav file with the name of the character
void save_character(character *player);

//Function to load a character from file
//Will return a null pointer if character failed to load
character* load_character();

//Function to increase the player to the next level
void increase_character_level(character *player);

//Function to display basic character information
void print_full_character(character *player);

//Function to display name, level, health, and experience
void print_level_info(character *player);

//Function to modify the current health of character
//Make it an inline function?
void modify_player_health(character *player, int health_change);

//Function to modify the current player experience
//Will call function to increase player level if current experience
//exceeds next_level_experience
void modify_experience(character *player, int experience_change);

//Function to set the dungeon level reached by player
void lowest_dungeon_level(character *player, int level);

//Function to return player character's current hp
int player_current_hp(character *player);

//Function to return player characters max hp
int player_max_hp(character *player);

//Function to check if player character is dead
//Returns <=0 if player is dead
//Returns >0 if player is alive
int player_death(character *player);

#endif