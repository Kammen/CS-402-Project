//encounters.h
//Jeff Skakun 11/6/14
//Class to determine random encounters on moving tiles

#ifndef ENCOUNTERS_H
#define ENCOUNTERS_H

#include "player_character.h"

//Needed?
#define NUM_OF_ENCOUNTERS 4

/*
   List of possible encounters and % of happening
      Nothing             35-70%
      Well (Full heal)    3%
      Artifact (Gain Exp) 2%
      Monster (Combat)    25-60%
*/

#define NOTHING_PERCENT .35
#define WELL_PERCENT .03
#define ARTIFACT_PERCENT .02
#define MONSTER_PERCENT .60

// Maybe return encounter # and let calling function deal??
//Function to determine which encounter is selected
//Returns 0=nothing, 1=well, 2=artifact, 3=combat
int random_encounter();

//Function that will call related functions for the various encounters
//Returns -1 if player is dead
//Returns 1 if player is still alive
int encounter(character *player);


#endif