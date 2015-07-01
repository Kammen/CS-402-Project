//map_tiles.h
//Jeff Skakun 11/18/14
//Class to maintain the map

#ifndef MAP_TILES_H
#define MAP_TILES_H

#define MAX_LINE_LENGTH 81
#define MAX_NUM_OF_LINES 5
#define MAX_DIRECTIONS_LENGTH 8
#define MAP_DIRECTORY "./Map Tiles/"
#define MAP_MAX_FILE_NAME_LENGTH 35
#define NEW_MAP_TILE_STRING "Tile End"
#define FILE_NUM_MAP_TILES 10
#define MAP_SIZE 16

/*************************
*   Tile Format in File: *
*   Description Line 1   *
*   Description Line 2   *
*   Description Line 3   *
*   Description Line 4   *
*   Description Line 5   *
*   Directions           *
*   Tile End             *                 
*************************/

typedef struct map_tile
{
   //Two dimensional array to hold the description text
   char description[MAX_NUM_OF_LINES][MAX_LINE_LENGTH];
   
   //Dungeon level
   int dungeon_level;
   
   //Map tile contains the stairs down to the next level
   int stairs;
   
   //Directions
   char directions[MAX_DIRECTIONS_LENGTH];
   
   //Contains the tile pack it came from
   int tile_pack;
   
   //Number of directions
   int num_dir;
   
   //Valid directions for connections
   int n;
   int e;
   int s;
   int w;
   
   //Pointer for North
   struct map_tile *north_ptr;
   
   //Pointer for East
   struct map_tile *east_ptr;
   
   //Pointer for South
   struct map_tile *south_ptr;
   
   //Pointer for West
   struct map_tile *west_ptr;
}map_tile;

//Function to load all map tiles
void load_map_tiles();

//Function to load map tiles from specified file
map_tile* load_tile(char *file,map_tile tiles[]);

//Function to return a map tile from specified file
map_tile* get_tile(map_tile *ptr);

//Function to return a map tile from all file
map_tile* get_tile_all(int reset);

//Function to return a map tile from nes file
map_tile* get_tile_nes(int reset);

//Function to return a map tile from new file
map_tile* get_tile_new(int reset);

//Function to return a map tile from nws file
map_tile* get_tile_nws(int reset);

//Function to return a map tile from sew file
map_tile* get_tile_sew(int reset);

//Function to return a map tile from ne file
map_tile* get_tile_ne(int reset);

//Function to return a map tile from nw file
map_tile* get_tile_nw(int reset);

//Function to return a map tile from ns file
map_tile* get_tile_ns(int reset);

//Function to return a map tile from ew file
map_tile* get_tile_ew(int reset);

//Function to return a map tile from sw file
map_tile* get_tile_sw(int reset);

//Function to return a map tile from se file
map_tile* get_tile_se(int reset);

//Function to return a map tile from n file
map_tile* get_tile_n(int reset);

//Function to return a map tile from e file
map_tile* get_tile_e(int reset);

//Function to return a map tile from s file
map_tile* get_tile_s(int reset);

//Function to return a map tile from w file
map_tile* get_tile_w(int reset);

//Function to reset get_tile functions for new map generation
void reset_get_tiles();

//Function to set the variables in a tile
void set_tile_up(map_tile *ptr,int dir,int dung_lvl,int stairs_flag,int num_tiles);

//Function to generate a map for specified dungeon_level
//Rule: When a tile can connect in multiple connections, all but 1 direction
//      is a dead end
map_tile* generate_map(int dungeon_level,map_tile map[]);

//Function to print map tiles --- Test print atm
void print_tile(map_tile *ptr);

#endif