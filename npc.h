//npc.h
//Jeff Skakun 11/6/14
//Class to contain and modify npc information

#ifndef NPC_H
#define NPC_H

#define MAX_MONSTER_NAME_LENGTH 21
#define NUM_OF_MONSTERS 13

//Hardwired list of monster names - potential to add more and/or move to file and import list
static const char MONSTER_NAMES[NUM_OF_MONSTERS][MAX_MONSTER_NAME_LENGTH]=
         {"Skeleton",
          "Ogre",
          "Orc",
          "Basilisk",
          "Cyclops",
          "Wisp",
          "Gargoyle",
          "Golem",
          "Troll",
          "Imp",
          "Minotaur",
          "Vampire",
          "Zombie"};

typedef struct monster
{
   //Limit length of name to 10 characters
   char name[MAX_MONSTER_NAME_LENGTH];
   
   //Store current health of player
   int current_health;
   
   //Store max health of player
   int max_health;
   
   //Store player level
   int monster_level;
   
    //Store damage die (ex. d6)
   int damage_die;
   
   //Store damage modifier (+1)
   int damage_modifier;
   
   //Store amount of experience the monster is worth
   int experience;
}monster;

//Function to create a new monster
monster* create_monster(int dungeon_level);

//Function to modify the current health of character
//Make it an inline function?
void modify_npc_health(monster *npc, int health_change);

//Function to display basic monster information
void print_full_monster(monster *npc);

//Function to print Name and health of monster
void print_short_monster(monster *npc);

//Check if monster is dead
//Return -1 if monster is alive
//Return monster experience if dead
int monster_death(monster *npc);

//Function to return the npc's current hp
int monster_current_hp(monster *npc);

//Function to return the npc's max hp
int monster_max_hp(monster *npc);
#endif