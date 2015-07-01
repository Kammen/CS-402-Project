//random_rolls.c
//Jeff Skakun 10/24/14
//Class to maintain random rolls
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random_rolls.h"
#include "mersenne_twist.h"

//Make these functions inline??
//Function that returns a random number in a specific range
int rand_range(int min_n, int max_n)
{
    return genrand_int31() % (max_n-min_n+1)+min_n;
}

//Function that returns a random number from 1 to die
int dice_roll(int die)
{
   return (genrand_int31()%die)+1;
}

//Function that returns a random number on [0,1) real interval
double percent_roll()
{
   return genrand_res53();
}