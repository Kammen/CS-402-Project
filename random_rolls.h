//random_rolls.h
//Jeff Skakun 11/6/14
//Class to maintain random rolls

#ifndef RANDOM_ROLLS_H
#define RANDOM_ROLLS_H

//Make these functions inline??
//Function that returns a random number in a specific range
int rand_range(int min_n, int max_n);

//Function that returns a random number from 1 to die
int dice_roll(int die);

//Function that returns a random number from 0.0 to 1.0
double percent_roll();

#endif