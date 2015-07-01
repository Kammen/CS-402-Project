//combat.h
//Jeff Skakun 11/7/14
//Class to handle combat

#ifndef COMBAT_H
#define COMBAT_H

#include "player_character.h"
#include "npc.h"

//Base hit and miss chance
#define HIT_CHANCE  .9
#define MISS_CHANCE .1

//Function to initiate combat
//Returns <=0 if player is dead
//Returns >0 if player is still alive
int init_combat(character *player);

//Function to have player attack
//Returns damage dealt if successful attack
int player_attack(character *player);

//Function to have npc attack
//Returns damage dealt if successful attack
int npc_attack(monster *npc);

//Function to display npc and player status (current and max hp)
void display_status(character *player,monster *npc);

#endif