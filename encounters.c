//encounters.c
//Jeff Skakun 10/29/14
//Class to determine random encounters on moving tiles
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encounters.h"
#include "random_rolls.h"
#include "mersenne_twist.h"
#include "player_character.h"

/*
   List of possible encounters and % of happening
      Nothing             35-70%
      Well (Full heal)    3%
      Artifact (Gain Exp) 2%
      Monster (Combat)    25-60%
*/

// Maybe return encounter # and let calling function deal??
//Function to determine which encounter is selected
//Returns 0=nothing, 1=well, 2=artifact, 3=combat
int random_encounter()
{
   double nothing=NOTHING_PERCENT;
   double well=WELL_PERCENT+nothing;
   double artifact=ARTIFACT_PERCENT+well;
   double monster=artifact;
   
   //Determine the random number
   double rand_num=percent_roll();
   
   //Let 0.0-0.35 be nothing
   if(rand_num<=nothing)
      return 0;
      
   //Let 0.35-0.38 be well
   else if(rand_num<=well)
      return 1;
      
   //Let 0.38-0.40 be artifact
   else if(rand_num<=artifact)
      return 2;
   
   //Let 0.40-.99 be combat
   else
      return 3;
}

//Function that will call related functions for the various encounters
//Returns -1 if player is dead
//Returns 1 if player is still alive
int encounter(character *player)
{
   //Switch statement to determine random encounter
   switch(random_encounter())
   {
      //Nothing happens
      case 0:
         printf("\nNothing happens.\n\n");
         break;
      
      //Player finds a well
      case 1:
         printf("\nYou drink from a well.  You feel much better.\n\n");
         
         //Set players health to full
         //modify_player_health(player,player->max_health); -Do I need to have a function call???
         player->current_health=player->max_health;
         break;
         
      //Player finds an artifact
      case 2:
         printf("\nYou find an ancient artifact!  You feel smarter for some reason.\n\n");
         
         //Increase player experience by 10*dungeon level
         //modify_player_experience(player,(player->dungeon_level)*10); -Do i need to have a function call???
         player->current_experience+=player->dungeon_level*10;
         break;
         
      //Combat
      case 3:
         printf("\nA monster appears from nowhere and attacks you!\n");
         
         //Return if player is dead or alive
         return init_combat(player);
   }
   
   //Player is still alive
   return 1;
}