//main_test.c
//Jeff Skakun
//Test program for the various functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encounters.h"
#include "npc.h"
#include "player_character.h"
#include "random_rolls.h"
#include "mersenne_twist.h"
#include "combat.h"
#include "map_tiles.h"

//Total # of rolls for testing purposes
const int TOTAL=100000;

//Function to test encounters.c
void encounters_test();

//Function to test npc.c
void npc_test();

//Function to test player_character.c
void player_character_test();

//Function to test random_rolls.c
void random_rolls_test();

//Function to test combat.c
void combat_test();

//Function to test map_tiles.h
void map_test();

main()
{
   //Set seed for mersenne_twist prng
   unsigned long init[4]={time(NULL),(time(NULL)>>1),(time(NULL)<<2),(time(NULL)<<5)}, length=4;
   init_by_array(init, length);
   
   //Load map tiles
   load_map_tiles();
   //test_print();
   
   //encounters_test();
   //npc_test();
   //player_character_test();
   //random_rolls_test();
   //combat_test();
   //map_test();
}

void encounters_test()
{
   int ctr;

   //Test for encounters.c - random_encounters()
   int roll[4]={0,0,0,0};
   printf("encounters.c - random_encounters:\n");
   printf("\tNOTHING_PERCENT  (0): %.2f\n",NOTHING_PERCENT);
   printf("\tWELL_PERCENT     (1): %.2f\n",WELL_PERCENT);
   printf("\tARTIFACT_PERCENT (2): %.2f\n",ARTIFACT_PERCENT);
   printf("\tMONSTER_PERCENT  (3): %.2f\n",MONSTER_PERCENT);
   
   for(ctr=0;ctr<TOTAL;ctr++)
   {
      roll[random_encounter()]++;
   }
   
   double percent=0.0,tpercent=0.0;
   for(ctr=0;ctr<4;ctr++)
   {
      percent=(roll[ctr]*100.0)/TOTAL;
      printf("\t%d: %10d  %.2f%%\n",ctr,roll[ctr],percent);
      tpercent+=percent;
   }
   printf("\tTotal: %14.2f%%\n",tpercent);
   
   printf("\nencounter() test:\n");
   
   character *player=create_character();
   
   if(encounter(player)==-1)
      printf("\nYou died!");
   else
      printf("\nYou are alive!");
}

void npc_test()
{
   int ctr;
   
   for(ctr=0;ctr<10;ctr++)
   {
      printf("\n\nMonster #%d",(ctr+1));
      print_full_monster(create_monster((ctr+1)));
   }
   
   for(ctr=0;ctr<10;ctr++)
   {
      printf("\n\nMonster #%d",(ctr+1));
      print_short_monster(create_monster((ctr+1)));
   }
   printf("\n\n");
   monster *npc=create_monster(5);
   
   print_full_monster(npc);
   modify_npc_health(npc,-5);
   printf("\n\n");
   if(monster_death(npc)<0)
      printf("NOT DEAD\n");
   else
      printf("OOPS");
      
   modify_npc_health(npc,-50);
   
   if(monster_death(npc)<0)
      printf("OOPS");
   else
      printf("Monster dead - worth %d exp",monster_death(npc));
}

void player_character_test()
{
   character *player,*player2;
   
   int x,y;
   
   for(x=1;x<=10;x++)
   {
      printf("\n\nPlayer level %d:",x);
      player=create_character();
      
      for(y=1;y<x;y++)
         increase_character_level(player);
         
      print_full_character(player);
   }
   
   player=create_character();
   
   save_character(player);

   player2=load_character();
   
   printf("\nLOADING:\n");
   
   if(player2==NULL)
      printf("Character does not exist.  Check your spelling\n");
   else
      print_full_character(player2);
   
   /*
   player=create_character();
   
   print_full_character(player);
   
   save_character(player);
   
   player2=load_character();
   
   increase_character_level(player2);
   
   print_full_character(player2);
   
   
   modify_health(player,-10);
   
   printf("\n");
   
   print_full_character(player);
   
   modify_health(player,15);
   
   printf("\n");
   
   print_full_character(player);
   
   modify_experience(player,20);
   
   printf("\n");
   
   print_full_character(player);
   
   modify_experience(player,20);
   
   printf("\n");
   
   print_full_character(player);
   
   printf("\n");
   
   print_level_info(player);
   */
}

void random_rolls_test()
{
   int ctr,num;
   
   int dice[6]={0,0,0,0,0,0};
   
   printf("\nrandom_rolls.c test:\n");
   
   for(ctr=0;ctr<TOTAL;ctr++)
   {
      //dice[dice_roll(6)-1]++;
      dice[rand_range(1,6)-1]++;
   }
   
   double percent=0.0;
   double tpercent=0.0;
   for(ctr=0;ctr<6;ctr++)
   {
      percent=(dice[ctr]*100.0)/TOTAL;
      printf("%d: %d  %.2f%%\n",ctr,dice[ctr],percent);
      tpercent+=percent;
   }
   printf("Total:     %.2f%%\n",tpercent);
}

void combat_test()
{
   int ctr;
   character *player=create_character();
   for(ctr=0;ctr<5;ctr++)
      increase_character_level(player);
   
   init_combat(player);
   print_full_character(player);
}


void map_test()
{   
   //Set seed for mersenne_twist prng
   unsigned long init[4]={time(NULL),(time(NULL)>>1),(time(NULL)<<2),(time(NULL)<<5)}, length=4;
   init_by_array(init, length);
   
   map_tile *map=malloc(sizeof(map_tile));
   
   map=generate_map(1,map);
   
   //print_tile(*map);
   
   char input='y';
   map_tile *t=malloc(sizeof(map_tile));   
   t=map;
   
   while(input!='q')
   {
      //Print map tile
      print_tile(t);
      
      //Check for stairs
      if(t->stairs)
         printf("\nThere are stairs down to the next level here, go (d)own?\n");
      printf("Which way do you want to go?  ");
      scanf("%c",&input);
      
      //Clear input
      while(getchar()!='\n');
      
      switch(input)
      {
         case 'n':
            //Check if north is a valid option
            if(t->n)
            {
               t=t->north_ptr;
            }
            break;
            
         case 'e':
            //Check if east is a valid option
            if(t->e)
            {
               t=t->east_ptr;
            }
            break;
         
         case 's':
            //Check if south is a valid option
            if(t->s)
            {
               t=t->south_ptr;
            }
            break;
            
         case 'w':
            //Check if west is a valid option
            if(t->w)
            {
               t=t->west_ptr;
            }
            break;
            
         case 'd':
            //Check if down is an option
            if(t->stairs)
            {
               printf("time to generate a new map\n");
            }
            break;
         
         default:
            printf("Not a valid option\n");
      }
      printf("\n");
   }
   
}
