//map_tiles.c
//Jeff Skakun 11/7/14
//Class to maintain map tile information
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mersenne_twist.h"
#include "random_rolls.h"
#include "map_tiles.h"

//Declare static global variables so I don't have to pass all pointers to all functions
//Initialize pointers for map tiles arrays
static map_tile *all;
static map_tile *nes;
static map_tile *new;
static map_tile *nws;
static map_tile *sew;
static map_tile *ne;
static map_tile *nw;
static map_tile *ns;
static map_tile *ew;
static map_tile *sw;
static map_tile *se;
static map_tile *n;
static map_tile *e;
static map_tile *s;
static map_tile *w;
static map_tile *map;

//Function to load all map tiles
void load_map_tiles()
{
   //Allocate memory
   all=malloc(sizeof(map_tile));
   nes=malloc(sizeof(map_tile));
   new=malloc(sizeof(map_tile));
   nws=malloc(sizeof(map_tile));
   sew=malloc(sizeof(map_tile));
   ne=malloc(sizeof(map_tile));
   nw=malloc(sizeof(map_tile));
   ns=malloc(sizeof(map_tile));
   ew=malloc(sizeof(map_tile));
   sw=malloc(sizeof(map_tile));
   se=malloc(sizeof(map_tile));
   n=malloc(sizeof(map_tile));
   e=malloc(sizeof(map_tile));
   s=malloc(sizeof(map_tile));
   w=malloc(sizeof(map_tile));
   map=malloc(sizeof(map_tile));
   
   //Initialize map tiles array
   map_tile all_tile[FILE_NUM_MAP_TILES];
   map_tile nes_tile[FILE_NUM_MAP_TILES];
   map_tile new_tile[FILE_NUM_MAP_TILES];
   map_tile nws_tile[FILE_NUM_MAP_TILES];
   map_tile sew_tile[FILE_NUM_MAP_TILES];
   map_tile ne_tile[FILE_NUM_MAP_TILES];
   map_tile nw_tile[FILE_NUM_MAP_TILES];
   map_tile ns_tile[FILE_NUM_MAP_TILES];
   map_tile ew_tile[FILE_NUM_MAP_TILES];
   map_tile sw_tile[FILE_NUM_MAP_TILES];
   map_tile se_tile[FILE_NUM_MAP_TILES];
   map_tile n_tile[FILE_NUM_MAP_TILES];
   map_tile e_tile[FILE_NUM_MAP_TILES];
   map_tile s_tile[FILE_NUM_MAP_TILES];
   map_tile w_tile[FILE_NUM_MAP_TILES];
   
   //Load map tiles
   all=load_tile("map_tile_all.map",all);
   nes=load_tile("map_tile_nes.map",nes);
   new=load_tile("map_tile_new.map",new_tile);
   nws=load_tile("map_tile_nws.map",nws_tile);
   sew=load_tile("map_tile_sew.map",sew_tile);
   ne=load_tile("map_tile_ne.map",ne_tile);
   nw=load_tile("map_tile_nw.map",nw_tile);
   ns=load_tile("map_tile_ns.map",ns_tile);
   ew=load_tile("map_tile_ew.map",ew_tile);
   sw=load_tile("map_tile_sw.map",sw_tile);
   se=load_tile("map_tile_se.map",se_tile);
   n=load_tile("map_tile_n.map",n_tile);
   e=load_tile("map_tile_e.map",e_tile);
   s=load_tile("map_tile_s.map",s_tile);
   w=load_tile("map_tile_w.map",w_tile);
}

//Function to return a map tile from specified file
//Can not have the same tile multiple times - causes issues (NOT NEEDED ANYMORE)
map_tile* get_tile(map_tile *ptr)
{
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   //Return random tile
   return (ptr+num);
}

//Function to return a map tile from all file
map_tile* get_tile_all(int reset)
{
   //Variable to record which tiles have been called
   static all_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         all_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(all_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   all_rolls[num]=1;
   return (all+num);
}

//Function to return a map tile from nes file
map_tile* get_tile_nes(int reset)
{
   //Variable to record which tiles have been called
   static nes_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         nes_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(nes_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   nes_rolls[num]=1;
   return (nes+num);
}

//Function to return a map tile from new file
map_tile* get_tile_new(int reset)
{
   //Variable to record which tiles have been called
   static new_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         new_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(new_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   new_rolls[num]=1;
   return (new+num);
}

//Function to return a map tile from nws file
map_tile* get_tile_nws(int reset)
{
   //Variable to record which tiles have been called
   static nws_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         nws_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(nws_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   nws_rolls[num]=1;
   return (nws+num);
}

//Function to return a map tile from sew file
map_tile* get_tile_sew(int reset)
{
   //Variable to record which tiles have been called
   static sew_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         sew_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(sew_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   sew_rolls[num]=1;
   return (sew+num);
}

//Function to return a map tile from ne file
map_tile* get_tile_ne(int reset)
{
   //Variable to record which tiles have been called
   static ne_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         ne_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(ne_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   ne_rolls[num]=1;
   return (ne+num);
}

//Function to return a map tile from nw file
map_tile* get_tile_nw(int reset)
{
   //Variable to record which tiles have been called
   static nw_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         nw_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(nw_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   nw_rolls[num]=1;
   return (nw+num);
}

//Function to return a map tile from ns file
map_tile* get_tile_ns(int reset)
{
   //Variable to record which tiles have been called
   static ns_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         ns_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(ns_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   ns_rolls[num]=1;
   return (ns+num);
}

//Function to return a map tile from ew file
map_tile* get_tile_ew(int reset)
{
   //Variable to record which tiles have been called
   static ew_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         ew_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(ew_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   ew_rolls[num]=1;
   return (ew+num);
}

//Function to return a map tile from sw file
map_tile* get_tile_sw(int reset)
{
   //Variable to record which tiles have been called
   static sw_rolls[FILE_NUM_MAP_TILES];   
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         sw_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   //Check if number has been called before
   while(sw_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   sw_rolls[num]=1;
   return (sw+num);
}

//Function to return a map tile from se file
map_tile* get_tile_se(int reset)
{
   //Variable to record which tiles have been called
   static se_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         se_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   //Check if number has been called before
   while(se_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   se_rolls[num]=1;
   return (se+num);
}

//Function to return a map tile from n file
map_tile* get_tile_n(int reset)
{
   //Variable to record which tiles have been called
   static n_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         n_rolls[ctr]=0;
      
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(n_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   n_rolls[num]=1;
   return (n+num);
}

//Function to return a map tile from e file
map_tile* get_tile_e(int reset)
{
   //Variable to record which tiles have been called
   static e_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         e_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(e_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   e_rolls[num]=1;
   return (e+num);
}

//Function to return a map tile from s file
map_tile* get_tile_s(int reset)
{
   //Variable to record which tiles have been called
   static s_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         s_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   //Check if number has been called before
   while(s_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   s_rolls[num]=1;
   return (s+num);
}

//Function to return a map tile from w file
map_tile* get_tile_w(int reset)
{
   //Variable to record which tiles have been called
   static w_rolls[FILE_NUM_MAP_TILES];
   
   //Reset tile count
   if(reset)
   {
      int ctr;
      for(ctr=0;ctr<FILE_NUM_MAP_TILES;ctr++)
         w_rolls[ctr]=0;
         
      return NULL;
   }
   
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;

   //Check if number has been called before
   while(w_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   w_rolls[num]=1;
   return (w+num);
}

//Function to reset get_tile functions for new map generation
void reset_get_tiles()
{
   get_tile_all(1);
   get_tile_nes(1);
   get_tile_new(1);
   get_tile_nws(1);
   get_tile_sew(1);
   get_tile_ne(1);
   get_tile_nw(1);
   get_tile_ns(1);
   get_tile_ew(1);
   get_tile_sw(1);
   get_tile_se(1);
   get_tile_n(1);
   get_tile_e(1);
   get_tile_s(1);
   get_tile_w(1);
}

//Function to set the variables in a tile
void set_tile_up(map_tile *ptr,int dir,int dung_lvl,int stairs_flag,int num_tiles)
{
   //Set variables
   ptr->num_dir=dir;
   ptr->dungeon_level=dung_lvl;
   ptr->n=0;
   ptr->e=0;
   ptr->s=0;
   ptr->w=0;
   
   //Pointers default to NULL
   ptr->north_ptr=NULL;
   ptr->east_ptr=NULL;
   ptr->south_ptr=NULL;
   ptr->west_ptr=NULL;
   
   //Check for valid directions for connections
   int ctr;
   for(ctr=0;ctr<MAX_DIRECTIONS_LENGTH;ctr++)
   {
      switch(ptr->directions[ctr])
      {
         //Valid north connection
         case 'n':
            ptr->n=1;
            break;
            
         //Valid east connection
         case 'e':
            ptr->e=1;
            break;
         
         //Valid south connection
         case 's':
            ptr->s=1;
            break;
            
         //Valid west connection
         case 'w':
            ptr->w=1;
            break;
      }
   }
   
   //Check for stairs
   if(stairs_flag)
      ptr->stairs=0;
   else
   {
      //If last tile, then stairs must be here
      if(num_tiles==MAP_SIZE)
         ptr->stairs=1;
      else
      {
         double rand_num=percent_roll();
         
         //Base chance is 10% + 5% for each tile without
         if(rand_num<=(.1+(.05*num_tiles)))
            ptr->stairs=1;
         else
            ptr->stairs=0;
      }
   }
}

//Function to generate a map for specified dungeon_level
//Rule: When a tile can connect in multiple connections, all but 1 direction
//      is a dead end
map_tile* generate_map(int dungeon_level,map_tile *head)
{
   //Initialize variables
   int num_tiles=1;
   int tiles_remaining;
   map_tile *map=malloc(sizeof(map_tile));
   map_tile *temp=malloc(sizeof(map_tile));
   
   //Flag to determine if stairs down has been found
   int stair_flag=0;
   
   //Choose random map tile pool for first map tile
   int roll=dice_roll(15);
   switch(roll)
   {
      //First map tile comes from all direction
      case 1:
         map=get_tile_all(0);         set_tile_up(map,4,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from nes direction
      case 2:
         map=get_tile_nes(0);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from new direction
      case 3:
         map=get_tile_new(0);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from nws direction
      case 4:
         map=get_tile_nws(0);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from sew direction
      case 5:
         map=get_tile_sew(0);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ne direction
      case 6:
         map=get_tile_ne(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from nw direction
      case 7:
         map=get_tile_nw(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ns direction
      case 8:
         map=get_tile_ns(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ew direction
      case 9:
         map=get_tile_ew(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from sw direction
      case 10:
         map=get_tile_sw(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from se direction
      case 11:
         map=get_tile_se(0);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from n direction
      case 12:
         map=get_tile_n(0);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from e direction
      case 13:
         map=get_tile_e(0);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from s direction
      case 14:
         map=get_tile_s(0);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from w direction
      case 15:
         map=get_tile_w(0);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
   }

   //Store start of map
   head=map;
   
   //Variable to hold a second random roll
   int roll2;

   while(num_tiles<MAP_SIZE)
   {
      //Determine direction that is not a dead end
      roll=dice_roll(4);

      //Check tiles remaining
      tiles_remaining=MAP_SIZE - num_tiles;

      switch(roll)
      {
         //North is not a dead end
         case 1:
            //Check if north is a valid connection
            if(map->n && map->north_ptr==NULL)
            {
               //Check if east is a valid connection
               if(map->e && map->east_ptr==NULL)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile_w(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->east_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->east_ptr->west_ptr=map;

                  //Check stair flag
                  if(map->east_ptr->stairs)
                     stair_flag=1;
               }

               //Check if south is a valid connection
               if(map->s && map->south_ptr==NULL)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile_n(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->south_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->south_ptr->north_ptr=map;

                  //Check stair flag
                  if(map->south_ptr->stairs)
                     stair_flag=1;
               }

               //Check if west is a valid connection
               if(map->w && map->west_ptr==NULL)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile_e(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->west_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->west_ptr->east_ptr=map;

                  //Check stair flag
                  if(map->west_ptr->stairs)
                     stair_flag=1;
               }

               //Set north connection - need to check how many tiles remain in the map
               //to determine which tiles can connect
               tiles_remaining=MAP_SIZE - num_tiles;

               if(tiles_remaining<=0)
                  tiles_remaining=1;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->north_ptr - need a tile with a south connection
                     map->north_ptr=get_tile_s(0);

                     //Increment number of tiles
                     num_tiles++;

                     //Set up tile
                     set_tile_up(map->north_ptr,1,dungeon_level,stair_flag,num_tiles);

                     //Set connections between tiles
                     map->north_ptr->south_ptr=map;

                     //Check stair flag
                     if(map->north_ptr->stairs)
                        stair_flag=1;
                     break;

                  //Only 2 tiles left in map - this tile must have 2 connections
                  case 2:
                     //Set map->north_ptr - need a tile with a south connectoin
                     //Determine which tile with 2 connections and has a south connection
                     roll2=dice_roll(3);

                     switch(roll2)
                     {
                        //Tile has north and south connection (ns)
                        case 1:
                           //Set up a north and south tile
                           map->north_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connection (se)
                        case 2:
                           //Set up a south and east tile
                           map->north_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connection (sw)
                        case 3:
                           //Set up a south and west tile
                           map->north_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //Only 3 tiles left in map - this tile must have either 2 or 3 connections
                  case 3:
                     //Set map->north_ptr - need a tile with a south connection
                     //Determine which tile with 2 or 3 connections and has a south connection
                     roll2=dice_roll(6);

                     switch(roll2)
                     {
                        //Tile has north and south connection (ns)
                        case 1:
                           //Set up a north and south tile
                           map->north_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connection (se)
                        case 2:
                           //Set up a south and east tile
                           map->north_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connection (sw)
                        case 3:
                           //Set up a south and west tile
                           map->north_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connection (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->north_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connection (nws)
                        case 5:
                           //Set up a north, west, and south tile
                           map->north_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connection (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->north_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //4 or more tiles left in map - this tile can have 2, 3, or 4 connections
                  default:
                     //Set map->north_ptr - need a tile with a south connection
                     //Determine which tile with 2-4 connections and has a south connection
                     roll2=dice_roll(7);

                     switch(roll2)
                     {
                        //Tile has north and south connection (ns)
                        case 1:
                           //Set up a north and south tile
                           map->north_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connection (se)
                        case 2:
                           //Set up a south and east tile
                           map->north_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connection (sw)
                        case 3:
                           //Set up a south and west tile
                           map->north_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connection (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->north_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connection (nws)
                        case 5:
                           //Set up a north, west, and south tile
                           map->north_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connection (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->north_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has all connections (all)
                        case 7:
                           //Set up an all tile
                           map->north_ptr=get_tile_all(0);
                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->north_ptr,4,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->north_ptr->south_ptr=map;

                           //Check stair flag
                           if(map->north_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;
               }

               //Move to next map tile
               map=map->north_ptr;
            }
            break;

         //East is not a dead end
         case 2:
            //Check if east is a valid connection
            if(map->e && map->east_ptr==NULL)
            {
               //Check if north is a valid connection
               if(map->n && map->north_ptr==NULL)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile_s(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->north_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->north_ptr->south_ptr=map;

                  //Check stair flag
                  if(map->north_ptr->stairs)
                     stair_flag=1;
               }

               //Check if south is a valid connection
               if(map->s && map->south_ptr==NULL)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile_n(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->south_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->south_ptr->north_ptr=map;

                  //Check stair flag
                  if(map->south_ptr->stairs)
                     stair_flag=1;
               }

               //Check if west is a valid connection
               if(map->w && map->west_ptr==NULL)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile_e(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->west_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->west_ptr->east_ptr=map;

                  //Check stair flag
                  if(map->west_ptr->stairs)
                     stair_flag=1;
               }

               //Set east connection - need to check how many tiles remain in the map
               //to determine which tiles can connect
               tiles_remaining=MAP_SIZE - num_tiles;

               if(tiles_remaining<=0)
                  tiles_remaining=1;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->east_ptr - need a tile with a west connection
                     map->east_ptr=get_tile_w(0);

                     //Increment number of tiles
                     num_tiles++;

                     //Set up tile
                     set_tile_up(map->east_ptr,1,dungeon_level,stair_flag,num_tiles);

                     //Set connections between tile
                     map->east_ptr->west_ptr=map;

                     //Check stair flag
                     if(map->east_ptr->stairs)
                        stair_flag=1;
                     break;

                  //Only 2 tiles left in map - this tile must have 2 connections
                  case 2:
                     //Set map->east_ptr - need a tile with a west connection
                     //Determine which tile with 2 connections and has a west connection
                     roll2=dice_roll(3);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->east_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 2:
                           //Set up a north and west tile
                           map->east_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connections (sw)
                        case 3:
                           //Set up a south and west tile
                           map->east_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //Only 3 tiles left in map - this tile must have either 2 or 3 connections
                  case 3:
                     //Set map->east_ptr - need a tile with a west connection
                     //Determine which tile with 2 or 3 connections and has a west connection
                     roll2=dice_roll(6);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->east_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 2:
                           //Set up a north and west tile
                           map->east_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connections (sw)
                        case 3:
                           //Set up a south and west tile
                           map->east_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 4:
                           //Set up a north, east, and west tile
                           map->east_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connections (nws)
                        case 5:
                           //Set up a north, west, and south tile
                           map->east_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connections (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->east_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //4 or more tiles left in map - this tile can have 2, 3, or 4 connections
                  default:
                     //Set map->east_ptr - need a tile with a west connection
                     //Determine which tile with 2-4 connections and has a west connection
                     roll2=dice_roll(7);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->east_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 2:
                           //Set up a north and west tile
                           map->east_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and west connections (sw)
                        case 3:
                           //Set up a south and west tile
                           map->east_ptr=get_tile_sw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 4:
                           //Set up a north, east, and west tile
                           map->east_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connections (nws)
                        case 5:
                           //Set up a north, west, and south tile
                           map->east_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connections (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->east_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has all connections (all)
                        case 7:
                           //Set up an all tile
                           map->east_ptr=get_tile_all(0);
                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,4,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tile
                           map->east_ptr->west_ptr=map;

                           //Check stair flag
                           if(map->east_ptr->stairs)
                              stair_flag;
                     }
                     break;
               }

               //Move to next map tile
               map=map->east_ptr;
            }
            break;

         //South is not a dead end
         case 3:
            //Check if south is a valid connection
            if(map->s && map->south_ptr==NULL)
            {
               //Check if north is a valid connection
               if(map->n && map->north_ptr==NULL)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile_s(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->north_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->north_ptr->south_ptr=map;

                  //Check stair flag
                  if(map->north_ptr->stairs)
                     stair_flag=1;
               }

               //Check if east is a valid connection
               if(map->e && map->east_ptr==NULL)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile_w(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->east_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->east_ptr->west_ptr=map;

                  //Check stair flag
                  if(map->east_ptr->stairs)
                     stair_flag=1;
               }

               //Check if west is a valid connection
               if(map->w && map->west_ptr==NULL)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile_e(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->west_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->west_ptr->east_ptr=map;

                  //Check stair flag
                  if(map->west_ptr->stairs)
                     stair_flag=1;
               }

               //Set north connection - need to check how many tiles remain in the map
               //to determine which tiles can connect
               tiles_remaining=MAP_SIZE - num_tiles;

               if(tiles_remaining<=0)
                  tiles_remaining=1;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->south_ptr - need a tile with a north connection
                     map->south_ptr=get_tile_n(0);

                     //Increment number of tiles
                     num_tiles++;

                     //Set up tile
                     set_tile_up(map->south_ptr,1,dungeon_level,stair_flag,num_tiles);

                     //Set connections between tiles
                     map->south_ptr->north_ptr=map;

                     //Check stair flag
                     if(map->south_ptr->stairs)
                        stair_flag=1;
                     break;

                  //Only 2 tiles left in map - this tile must have 2 connections
                  case 2:
                     //Set map->south_ptr - need a tile with a north connection
                     //Determine which tile with 2 connections and has a south connection
                     roll2=dice_roll(3);

                     switch(roll2)
                     {
                        //Tile has north and east connection (ne)
                        case 1:
                           //Set up a north and east tile
                           map->south_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and south connections (ns)
                        case 2:
                           //Set up a north and south tile
                           map->south_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 3:
                           //Set up a north and west tile
                           map->south_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //Only 3 tiles left in map - this tile must have either 2 or 3 connections
                  case 3:
                     //Set map->south_ptr - need a tile with a north connection
                     //Determine which tile with 2 or 3 connections and has a south connection
                     roll2=dice_roll(6);

                     switch(roll2)
                     {
                        //Tile has north and east connection (ne)
                        case 1:
                           //Set up a north and east tile
                           map->south_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and south connections (ns)
                        case 2:
                           //Set up a north and south tile
                           map->south_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 3:
                           //Set up a north and west tile
                           map->south_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connections (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->south_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 5:
                           //Set up a north, east, and west tile
                           map->south_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connections (nws)
                        case 6:
                           //Set up a north, west, and south tile
                           map->south_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //4 or more tiles left in map - this tile can have 2, 3, or 4 connections
                  default:
                     //Set map->south_ptr - need a tile with a north connection
                     //Determine which tile with 2-4 connections and has a south connection
                     roll2=dice_roll(7);

                     switch(roll2)
                     {
                        //Tile has north and east connection (ne)
                        case 1:
                           //Set up a north and east tile
                           map->south_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and south connections (ns)
                        case 2:
                           //Set up a north and south tile
                           map->south_ptr=get_tile_ns(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and west connections (nw)
                        case 3:
                           //Set up a north and west tile
                           map->south_ptr=get_tile_nw(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connections (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->south_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 5:
                           //Set up a north, east, and west tile
                           map->south_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, west, and south connections (nws)
                        case 6:
                           //Set up a north, west, and south tile
                           map->south_ptr=get_tile_nws(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has all connections (all)
                        case 7:
                           //Set up an all tile
                           map->south_ptr=get_tile_all(0);
                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->south_ptr,4,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->south_ptr->north_ptr=map;

                           //Check stair flag
                           if(map->south_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;
               }

               //Move to next map tile
               map=map->south_ptr;
            }
            break;

         //West is not a dead end
         case 4:
            //Check if west is a valid connection
            if(map->w && map->west_ptr==NULL)
            {
               //Check if north is a valid connection
               if(map->n && map->north_ptr==NULL)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile_s(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->north_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->north_ptr->south_ptr=map;

                  //Check stair flag
                  if(map->north_ptr->stairs)
                     stair_flag=1;
               }

               //Check if east is a valid connection
               if(map->e && map->east_ptr==NULL)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile_w(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->east_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->east_ptr->west_ptr=map;

                  //Check stair flag
                  if(map->east_ptr->stairs)
                     stair_flag=1;
               }

               //Check if south is a valid connection
               if(map->s && map->south_ptr==NULL)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile_n(0);

                  //Increment number of tiles
                  num_tiles++;

                  //Set up tile
                  set_tile_up(map->south_ptr,1,dungeon_level,stair_flag,num_tiles);

                  //Set connections between tiles
                  map->south_ptr->north_ptr=map;

                  //Check stair flag
                  if(map->south_ptr->stairs)
                     stair_flag=1;
               }

               //Set north connection - need to check how many tiles remain in the map
               //to determine which tiles can connect
               tiles_remaining=MAP_SIZE - num_tiles;

               if(tiles_remaining<=0)
                  tiles_remaining=1;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->west_ptr - need a tile with an east connection
                     map->west_ptr=get_tile_e(0);

                     //Increment number of tiles
                     num_tiles++;

                     //Set up tile
                     set_tile_up(map->west_ptr,1,dungeon_level,stair_flag,num_tiles);

                     //Set connections between tiles
                     map->west_ptr->east_ptr=map;

                     //Check stair flag
                     if(map->west_ptr->stairs)
                        stair_flag=1;
                     break;

                  //Only 2 tiles left in map - this tile must have 2 connections
                  case 2:
                     //Set map->west_ptr - need a tile with an east connection
                     //Determine which tile with 2 connections and has an east connection
                     roll2=dice_roll(3);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->west_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and east connections (ne)
                        case 2:
                           //Set up a north and east tile
                           map->west_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connections (se)
                        case 3:
                           //Set up a south and east tile
                           map->west_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //Only 3 tiles left in map - this tile must have 2 or 3 connections
                  case 3:
                     //Set map->west_ptr - need a tile with an east connection
                     //Determine which tile with 2 or 3 connections and has an east connection
                     roll2=dice_roll(6);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->west_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and east connections (ne)
                        case 2:
                           //Set up a north and east tile
                           map->west_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connections (se)
                        case 3:
                           //Set up a south and east tile
                           map->west_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connections (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->west_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 5:
                           //Set up a north, east, and west tile
                           map->west_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connections (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->west_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;

                  //4 or more tiles left in map - this tile can have 2, 3, or 4 connections
                  default:
                     //Set map->west_ptr - need a tile with an east connection
                     //Determine which tile with 2-4 connections and has an east connection
                     roll2=dice_roll(7);

                     switch(roll2)
                     {
                        //Tile has east and west connections (ew)
                        case 1:
                           //Set up an east and west tile
                           map->west_ptr=get_tile_ew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north and east connections (ne)
                        case 2:
                           //Set up a north and east tile
                           map->west_ptr=get_tile_ne(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south and east connections (se)
                        case 3:
                           //Set up a south and east tile
                           map->west_ptr=get_tile_se(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,2,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and south connections (nes)
                        case 4:
                           //Set up a north, east, and south tile
                           map->west_ptr=get_tile_nes(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has north, east, and west connections (new)
                        case 5:
                           //Set up a north, east, and west tile
                           map->west_ptr=get_tile_new(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has south, east, and west connections (sew)
                        case 6:
                           //Set up a south, east, and west tile
                           map->west_ptr=get_tile_sew(0);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;

                        //Tile has all connections (all)
                        case 7:
                           //Set up an all tile
                           map->west_ptr=get_tile_all(0);
                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->west_ptr,3,dungeon_level,stair_flag,num_tiles);

                           //Set connections between tiles
                           map->west_ptr->east_ptr=map;

                           //Check stair flag
                           if(map->west_ptr->stairs)
                              stair_flag=1;
                           break;
                     }
                     break;
               }

               //Move to next map tile
               map=map->west_ptr;
            }
            break;
      }
   }
   return head;
}

//Function to add a tile in a specified direction from head
map_tile* add_tile_to_map(map_tile *head,map_tile *new,char direction)
{
   switch(direction)
   {
      case 'n':
         //Connected by north from head
         head->north_ptr=new;
         head->north_ptr->south_ptr=head;
         break;
      case 'e':
         //Connected by east from head
         head->east_ptr=new;
         head->east_ptr->west_ptr=head;
         break;
      case 's':
         //Connected by south from head
         head->south_ptr=new;
         head->south_ptr->north_ptr=head;
         break;
      case 'w':
         //Connected by west from head
         head->west_ptr=new;
         head->west_ptr->east_ptr=head;
         break;
   }

   return head;
}

//Function to print map tiles
void print_tile(map_tile *ptr)
{
   //Initialize variables
   int i;
   
   //Print description
   for(i=0;i<MAX_NUM_OF_LINES;i++)
   {
      printf("Line #%d: %s\n",(i+1),ptr->description[i]);
   }
   
   //Print directions
   printf("Directions: %s\n",ptr->directions);
}

//Function to load map tiles from specified file
map_tile* load_tile(char *file, map_tile tiles[])
{
   //Initialize variables
   char file_name[MAP_MAX_FILE_NAME_LENGTH];
   char line[MAX_LINE_LENGTH];
   FILE *infile;
   int ctr=0;
   int i=0;
   int j=0;
   int k;
   
   //Build file name
   strcpy(file_name,MAP_DIRECTORY);
   strcat(file_name,file);
   
   //Open file
   if((infile=fopen(file_name,"r"))==NULL)
      tiles=NULL;
   else
   {
      while(1)
      {
         //Input line from file
         fgets(line,MAX_LINE_LENGTH,infile);
         
         //Search for new line char and replace with null character
         j=0;         
         while(line[j]!='\n')
            j++;
            
         line[j-1]='\0';
         
         
         
         //Check if we have reached the end of file
         if(feof(infile))
            break;
            
         //Check for start of new tile
         if(strcmp(NEW_MAP_TILE_STRING,line)==0)
         {
            //Increment ctr
            ctr++;
            
            //Reset i
            i=0;
         }
         else
         {
            //Check for direction line
            if(i==5)
            {
               strcpy(tiles[ctr].directions,line);
            }
            else
            {
               //Copy line to description
               k=0;
               while(line[k]!='\0')
               {
                  tiles[ctr].description[i][k]=line[k];
                  k++;
               }
               
               //Add null char to end of description[i]
               tiles[ctr].description[i][k]='\0';
               i++;
            }
         }
      }
   }
   
   //Return pointer to array
   return tiles;
}