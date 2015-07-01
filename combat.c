//combat.c
//Jeff Skakun 11/7/14
//Class to handle combat
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "combat.h"
#include "player_character.h"
#include "npc.h"
#include "random_rolls.h"
#include "mersenne_twist.h"

//Function to initiate combat
//Returns -1 if player is dead
//Returns 1 if player is still alive
int init_combat(character *player)
{
   printf("Initiating combat:\n");
   
   //Create monster
   monster *npc=create_monster(player->dungeon_level);

   int npc_death_check;
   
   //Combat loop - Breaks on monster or player death
   while(1)
   {
      //Display current health of player and npc
      display_status(player,npc);
      
      //Player attacks - modify npc health
      modify_npc_health(npc,(-1*player_attack(player)));
      
      //Check if monster is dead
      npc_death_check=monster_death(npc);
      if(npc_death_check!=-1)
      {
         //Monster is dead - end combat and add exp to player
         printf("\nThe %s is vanquished!  You earned %d experience.\n\n",npc->name,npc_death_check);
         modify_experience(player,npc_death_check);
         
         //Increase player's monster killed count
         player->monsters_killed++;
         
         return 1;
      }
      
      //Monster is not dead, he gets an attack         
      printf("\n");
      modify_player_health(player,(-1*npc_attack(npc)));
      
      //Check if player is dead
      if(player_death(player)<=0)
      {
         //Player died
         return -1;
      }
            
      printf("\nPress enter to attack again...");
      getchar();
   }
}

//Function to display npc and player status (current and max hp)
void display_status(character *player,monster *npc)
{
   //Prints player and npc's current and max hp
   printf("\n%s: %d/%d\t%s: %d/%d\n",player->name,player->current_health,player->max_health
                                    ,npc->name,npc->current_health,npc->max_health);
}

//Function to have player attack
//Returns damage dealt if successful attack
int player_attack(character *player)
{
   //Initialize variables
   int damage=0;
   int die1,die2;
   
   //Generate a roll from 0-99
   int atk=percent_roll()*100+1;
   
   //Display the attack roll
   printf("%10.10s: Attack roll - %3d:",player->name,atk);
   
   //Check if attack missed
   if(atk<(MISS_CHANCE*100))
   {
      printf(" Miss!!");
      return damage;
   }
   else
   {
      //Attack hit - check for crit
      if(atk==100)
      {
         //Attack crit, roll double damage die
         die1=dice_roll(player->damage_die);
         die2=dice_roll(player->damage_die);
         damage=die1+die2+player->damage_modifier;
         printf(" Crit!! - You deal (%d+%d)+%d=%d damage",die1,die2,player->damage_modifier,damage);
         return damage;
      }
      else
      {
         //Attack did not crit, roll normal damage
         die1=dice_roll(player->damage_die);
         damage=die1+player->damage_modifier;
         printf(" Hit!! - You deal %d+%d=%d damage",die1,player->damage_modifier,damage);
         return damage;
      }
   }
}

//Function to have npc attack
//Returns damage dealt if successful attack
int npc_attack(monster *npc)
{
   //Initialize variables
   int damage=0;
   int die1,die2;
   
   //Generate a roll from 0-99
   int atk=percent_roll()*100+1;
   
   //Display the attack roll
   printf("%10s: Attack roll - %3d:",npc->name,atk);
   
   //Check if attack missed
   if(atk<(MISS_CHANCE*100))
   {
      printf(" Miss!!");
      return damage;
   }
   else
   {
      //Attack hit - check for crit
      if(atk==100)
      {
         //Attack crit, roll double damage die
         die1=dice_roll(npc->damage_die);
         die2=dice_roll(npc->damage_die);
         damage=die1+die2+npc->damage_modifier;
         printf(" Crit!! - You take (%d+%d)+%d=%d damage",die1,die2,npc->damage_modifier,damage);
         return damage;
      }
      else
      {
         //Attack did not crit, roll normal damage
         die1=dice_roll(npc->damage_die);
         damage=die1+npc->damage_modifier;
         printf(" Hit!! - You take %d+%d=%d damage",die1,npc->damage_modifier,damage);
         return damage;
      }
   }
}