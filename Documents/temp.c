//Function to generate a map for specified dungeon_level
//Rule: When a tile can connect in multiple connections, all but 1 direction
//      is a dead end
map_tile* generate_map(int dungeon_level,map_tile *head)
{
   //Initialize variables
   int num_tiles=1;
   int tiles_remaining;
   map_tile *map=malloc(sizeof(map_tile));
   
   //Flag to determine if stairs down has been found
   int stair_flag=0;
   
   //Choose random map tile pool for first map tile
   int roll=dice_roll(15);
   switch(roll)
   {
      //First map tile comes from all direction
      case 1:
         map=get_tile(all);
         set_tile_up(map,4,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from nes direction
      case 2:
         map=get_tile(nes);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from new direction
      case 3:
         map=get_tile(new);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from nws direction
      case 4:
         map=get_tile(nws);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from sew direction
      case 5:
         map=get_tile(sew);
         set_tile_up(map,3,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ne direction
      case 6:
         map=get_tile(ne);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from nw direction
      case 7:
         map=get_tile(nw);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ns direction
      case 8:
         map=get_tile(ns);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from ew direction
      case 9:
         map=get_tile(ew);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from sw direction
      case 10:
         map=get_tile(sw);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from se direction
      case 11:
         map=get_tile(se);
         set_tile_up(map,2,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
      
      //First map tile comes from n direction
      case 12:
         map=get_tile(n);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from e direction
      case 13:
         map=get_tile(e);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from s direction
      case 14:
         map=get_tile(s);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
         
      //First map tile comes from w direction
      case 15:
         map=get_tile(w);
         set_tile_up(map,1,dungeon_level,stair_flag,num_tiles);
         
         //Stairs can't be on first tile
         map->stairs=0;
         break;
   }

   //Store start of map
   head=map;

   //print_tile(map);
   
   //Variable to hold a second random roll
   int roll2;

   while(num_tiles<MAP_SIZE)
   {
      //Determine direction that is not a dead end
      roll=dice_roll(4);

      switch(roll)
      {
         //North is not a dead end
         case 1:
            //Check if north is a valid connection
            if(map->n)
            {
               //Check if east is a valid connection
               if(map->e)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile(w);

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
               if(map->s)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile(n);

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
               if(map->w)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile(e);

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
               if(num_tiles==MAP_SIZE)
                  break;
               tiles_remaining=MAP_SIZE - num_tiles;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->north_ptr - need a tile with a south connection
                     map->north_ptr=get_tile(s);

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
                           map->north_ptr=get_tile(ns);

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
                           map->north_ptr=get_tile(se);

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
                           map->north_ptr=get_tile(sw);

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
                           map->north_ptr=get_tile(ns);

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
                           map->north_ptr=get_tile(se);

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
                           map->north_ptr=get_tile(sw);

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
                           map->north_ptr=get_tile(nes);

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
                           map->north_ptr=get_tile(nws);

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
                           map->north_ptr=get_tile(sew);

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
                           map->north_ptr=get_tile(ns);

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
                           map->north_ptr=get_tile(se);

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
                           map->north_ptr=get_tile(sw);

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
                           map->north_ptr=get_tile(nes);

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
                           map->north_ptr=get_tile(nws);

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
                           map->north_ptr=get_tile(sew);

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
                           map->north_ptr=get_tile(all);

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
            if(map->e)
            {
               //Check if north is a valid connection
               if(map->n)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile(s);

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
               if(map->s)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile(n);

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
               if(map->w)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile(e);

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
               if(num_tiles==MAP_SIZE)
                  break;
               tiles_remaining=MAP_SIZE - num_tiles;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->east_ptr - need a tile with a west connection
                     map->east_ptr=get_tile(w);

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
                           map->east_ptr=get_tile(ew);

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
                           map->east_ptr=get_tile(nw);

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
                           map->east_ptr=get_tile(sw);

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
                           map->east_ptr=get_tile(ew);

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
                           map->east_ptr=get_tile(nw);

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
                           map->east_ptr=get_tile(sw);

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
                           map->east_ptr=get_tile(new);

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
                           map->east_ptr=get_tile(nws);

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
                           map->east_ptr=get_tile(sew);

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
                           map->east_ptr=get_tile(ew);

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
                           map->east_ptr=get_tile(nw);

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
                           map->east_ptr=get_tile(sw);

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
                           map->east_ptr=get_tile(new);

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
                           map->east_ptr=get_tile(nws);

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
                           map->east_ptr=get_tile(sew);

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
                           map->east_ptr=get_tile(all);

                           //Increment number of tiles
                           num_tiles++;

                           //Set up tile
                           set_tile_up(map->east_ptr,4,dungeon_level,stair_flag,num_tiles);

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
            if(map->s)
            {
               //Check if north is a valid connection
               if(map->n)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile(s);

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
               if(map->e)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile(w);

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
               if(map->w)
               {
                  //Set map->west_ptr - need a tile with an east connection
                  map->west_ptr=get_tile(e);

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
               if(num_tiles==MAP_SIZE)
                  break;
               tiles_remaining=MAP_SIZE - num_tiles;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->south_ptr - need a tile with a north connection
                     map->south_ptr=get_tile(n);

                     //Increment number of tiles
                     num_tiles++;

                     //Set up tile
                     set_tile_up(map->south_ptr,1,dungeon_level,stair_flag,num_tiles);

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
                           map->south_ptr=get_tile(ne);

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
                           map->south_ptr=get_tile(ns);

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
                           map->south_ptr=get_tile(nw);

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
                           map->south_ptr=get_tile(ne);

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
                           map->south_ptr=get_tile(ns);

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
                           map->south_ptr=get_tile(nw);

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
                           map->south_ptr=get_tile(nes);

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
                           map->south_ptr=get_tile(new);

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
                           map->south_ptr=get_tile(nws);

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
                           map->south_ptr=get_tile(ne);

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
                           map->south_ptr=get_tile(ns);

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
                           map->south_ptr=get_tile(nw);

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
                           map->south_ptr=get_tile(nes);

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
                           map->south_ptr=get_tile(new);

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
                           map->south_ptr=get_tile(nws);

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
                           map->south_ptr=get_tile(all);

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
            if(map->w)
            {
               //Check if north is a valid connection
               if(map->n)
               {
                  //Set map->north_ptr - need a tile with a south connection
                  map->north_ptr=get_tile(s);

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
               if(map->e)
               {
                  //Set map->east_ptr - need a tile with a west connection
                  map->east_ptr=get_tile(w);

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
               if(map->s)
               {
                  //Set map->south_ptr - need a tile with a north connection
                  map->south_ptr=get_tile(n);

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
               if(num_tiles==MAP_SIZE)
                  break;
               tiles_remaining=MAP_SIZE - num_tiles;

               //Limit possible connecting tiles
               switch(tiles_remaining)
               {
                  //Only 1 tile left in map - this tile must be a dead end
                  case 1:
                     //Set map->west_ptr - need a tile with an east connection
                     map->west_ptr=get_tile(e);

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
                           map->west_ptr=get_tile(ew)

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
                           map->west_ptr=get_tile(ne);

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
                           map->west_ptr=get_tile(se);

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
                           map->west_ptr=get_tile(ew)

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
                           map->west_ptr=get_tile(ne);

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
                           map->west_ptr=get_tile(se);

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
                           map->west_ptr=get_tile(nes);

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
                           map->west_ptr=get_tile(new);

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
                           map->west_ptr=get_tile(sew);

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
                           map->west_ptr=get_tile(ew)

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
                           map->west_ptr=get_tile(ne);

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
                           map->west_ptr=get_tile(se);

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
                           map->west_ptr=get_tile(nes);

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
                           map->west_ptr=get_tile(new);

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
                           map->west_ptr=get_tile(sew);

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
                           map->west_ptr=get_tile(all);

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
}
