//npc.c
//Jeff Skakun 10/27/14
//Class to contain and modify npc information
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "npc.h"
#include "random_rolls.h"


//Function to create a new monster
monster* create_monster(int dungeon_level)
{
   //Initialize variables
   monster *npc;
   
   npc=malloc(sizeof(monster));
   
   //Randomly pick name of monster
   strcpy(npc->name,MONSTER_NAMES[dice_roll(NUM_OF_MONSTERS)-1]);
   
   //Determine monster level
   npc->monster_level=dungeon_level;
   
   //Determine current and max health based on monster level
   npc->current_health=5+npc->monster_level*3;
   npc->max_health=5+npc->monster_level*3;
   
   //Determine experience worth
   npc->experience=5*npc->monster_level;
   
   //Determine damage die - add +1 to die level every 4 levels
   npc->damage_die=4+(npc->monster_level/4);
   
   //Store damage modifier (+1 every other level)
   npc->damage_modifier=0+(npc->monster_level/2);
   
   return npc;
}

//Function to display basic monster information
void print_full_monster(monster *npc)
{
   printf("\nMonster name:         %s",npc->name);
   printf("\nMonster level:        %d",npc->monster_level);
   printf("\nCurrent hp:           %d/%d",npc->current_health,npc->max_health);
   printf("\nExperience:           %d",npc->experience);
   printf("\nMonster damage:       d%d+%d",npc->damage_die,npc->damage_modifier);
}

//Function to print Name and health of monster
void print_short_monster(monster *npc)
{
   printf("\nMonster name:         %s",npc->name);
   printf("\nCurrent hp:           %d/%d",npc->current_health,npc->max_health);
}

//Function to modify the current health of character
//health_change is negative for damage taken
//health_change is positive for damage healed
void modify_npc_health(monster *npc, int health_change)
{
   //Change current_health
   npc->current_health+=health_change;
   
   //Not sure if monsters will have a way to increase health yet
   //Check if current_health > max_health
   //Npc can't have more than max_health
   if(npc->current_health>npc->max_health)
      npc->current_health=npc->max_health;
}

//Check if monster is dead
//Return -1 if monster is alive
//Return monster experience if dead
int monster_death(monster *npc)
{
   //Check monster current health to see if it is dead (<=0)
   if(npc->current_health<=0)
      return npc->experience;
      
   //Monster is not dead
   return -1;
}

//Function to return the npc's current hp
int monster_current_hp(monster *npc)
{
   return npc->current_health;
}
//Function to return the npc's max hp
int monster_max_hp(monster *npc)
{
   return npc->max_health;
}