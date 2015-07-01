   Do I need a switch statement?? Use if statements to determine
      //Switch statement based on number of directions on tile
      switch(map[ctr].num_dir)
      {
         
         
         //Current map tile can connect in 3 directions
         case 3:
            //Determine which direction is not a deadend
            //Will keep rolling until it receives a valid direction
            roll=dice_roll(4);
            
            //Switch statement for direcctions
            switch(roll)
            {
               //North is not a deadend
               case 1:
                  //Check if north is a valid direction
                  if(map[ctr].n)
                  {
                     //Check if there is a south connection
                     if(map[ctr].s)
                     {
                        //Set South tile
                        //Get a tile that has north connection
                        temp=get_tile(n);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.north_ptr=&map[ctr];
                        map[ctr].south_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check if there is a west connection
                     if(map[ctr].w)
                     {
                        //Set West tile
                        //Get a tile that has east connection
                        temp=get_tile(e);
                        
                        //Increment number of tiles
                        num_tiles++;
                     
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.east_ptr=&map[ctr];
                        map[ctr].west_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check if there is an east connection
                     if(map[ctr].e)
                     {
                        //Set East tile
                        //Get a tile that has west connection
                        temp=get_tile(w);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=&map[ctr];
                        map[ctr].east_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                           
                     //Set North tile - not a deadend unless we have reached map size
                     //Check remaining number of tiles open in current map
                     tiles_remaining=MAP_SIZE-num_tiles;
                     
                     //Limit possible connecting tiles
                     switch(tiles_remaining)
                     {
                        case 1:
                           //Only 1 tile remaining, connecting tile must be a deadend
                           //Get a tile that has south connection
                           temp=get_tile(s);
                           
                           //Increment number of tiles
                           num_tiles++;
                           
                           //Set up temporary tile
                           set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                           
                           //Connect tiles
                           temp.north_ptr=NULL;
                           temp.east_ptr=NULL;
                           temp.west_ptr=NULL;
                           temp.south_ptr=&map[ctr];
                           map[ctr].north_ptr=&temp;
                                             
                           //Check stair flag
                           if(temp.stairs)
                              stair_flag=1;
                           break;
                           
                        case 2:
                           //Only 2 tiles remaining, connecting tile must have 2 connections
                           //Determine which tile with 2 connections that has a south connection.
                           roll2=dice_roll(3);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                              
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has South and East connections
                              case 2:
                                 //Set up a South and East tile
                                 temp=get_tile(se);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                  
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                        case 3:
                           //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                           //Determine which tile with either 2 or 3 connections that must has a
                           //South connection
                           roll2=dice_roll(6);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has South and East connections
                              case 2:
                                 //Set up a South and East tile
                                 temp=get_tile(se);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                           default:
                              //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                              //Determine which tile that must have a South connection
                              roll2=dice_roll(7);
                              
                              switch(roll2)
                              {
                                  //Tile has North and South connections
                                  case 1:
                                    //Set up a North and South tile
                                    temp=get_tile(ns);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has South and East connections
                                 case 2:
                                    //Set up a South and East tile
                                    temp=get_tile(se);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has South and West connections
                                 case 3:
                                    //Set up a South and West tile
                                    temp=get_tile(sw);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.east_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a North, East, and South connections
                                 case 4:
                                    //Set up North, East, and South tile
                                    temp=get_tile(nes);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                     
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                      stair_flag=1;
                                    break;
                                 
                                 //Tile has a North, West, and South connections
                                 case 5:
                                    //Set up North, West, and South tile
                                    temp=get_tile(nws);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                   
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a South, East, and West connections
                                 case 6:
                                    //Set up South, East, and West tile
                                    temp=get_tile(sew);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                      
                                 //Tile has all connections
                                 case 7:
                                    //Set up an all tile
                                    temp=get_tile(all);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.south_ptr=&map[ctr];
                                    map[ctr].north_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                              }
                              break;
                     }
                     
                     //Set next map tile
                     ctr++;
                     map[ctr]=*map[ctr-1].north_ptr;
                  }
                  break;
                  
               //South is not a deadend
               case 2:
                  //Check for valid south connection
                  if(map[ctr].s)
                  {
                     //Check for valid north connection
                     if(map[ctr].n)
                     {
                        //Set North tile
                        //Get a tile that has south connection
                        temp=get_tile(s);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.north_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.south_ptr=&map[ctr];
                        map[ctr].north_ptr=&temp;
                        
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid west connection
                     if(map[ctr].w)
                     {   
                        //Set West tile
                        //Get a tile that has east connection
                        temp=get_tile(e);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.east_ptr=&map[ctr];
                        map[ctr].west_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid east connection
                     if(map[ctr].e)
                     {
                        //Set East tile
                        //Get a tile that has west connection
                        temp=get_tile(w);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=&map[ctr];
                        map[ctr].east_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                        
                     //Set South tile - not a deadend unless we have reached map size
                     //Check remaining number of tiles open in current map
                     tiles_remaining=MAP_SIZE-num_tiles;
                     
                     //Limit possible connecting tiles
                     switch(tiles_remaining)
                     {
                        case 1:
                           //Only 1 tile remaining, connecting tile must be a deadend
                           //Get a tile that has north connection
                           temp=get_tile(n);
                           
                           //Increment number of tiles
                           num_tiles++;
                           
                           //Set up temporary tile
                           set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                           
                           //Connect tiles
                           temp.south_ptr=NULL;
                           temp.east_ptr=NULL;
                           temp.west_ptr=NULL;
                           temp.north_ptr=&map[ctr];
                           map[ctr].south_ptr=&temp;
                                             
                           //Check stair flag
                           if(temp.stairs)
                              stair_flag=1;
                           break;
                           
                        case 2:
                           //Only 2 tiles remaining, connecting tile must have 2 connections
                           //Determine which tile with 2 connections that have a north connection.
                           roll2=dice_roll(3);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a North and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has North and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                        case 3:
                           //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                           //Determine which tile with either 2 or 3 connections that must have a
                           //North connection
                           roll2=dice_roll(6);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a North and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has North and West connections
                              case 3:
                                 //Set up a North and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(new);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                           default:
                              //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                              //Determine which tile that must have a South connection
                              roll2=dice_roll(7);
                              
                              switch(roll2)
                              {
                                  //Tile has North and South connections
                                  case 1:
                                    //Set up a North and South tile
                                    temp=get_tile(ns);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has North and East connections
                                 case 2:
                                    //Set up a North and East tile
                                    temp=get_tile(ne);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has North and West connections
                                 case 3:
                                    //Set up a North and West tile
                                    temp=get_tile(nw);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.east_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a North, East, and South connections
                                 case 4:
                                    //Set up North, East, and South tile
                                    temp=get_tile(nes);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has a North, West, and South connections
                                 case 5:
                                    //Set up North, West, and South tile
                                    temp=get_tile(nws);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a North, East, and West connections
                                 case 6:
                                    //Set up South, East, and West tile
                                    temp=get_tile(new);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has all connections
                                 case 7:
                                    //Set up an all tile
                                    temp=get_tile(all);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=&map[ctr];
                                    map[ctr].south_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                              }
                              break;
                     }  
                  
                     //Set next map tile
                     ctr++;
                     map[ctr]=*map[ctr-1].south_ptr;
                  }
                  break;
               
               //East is not a deadend
               case 3:
                  //Check for valid east connection
                  if(map[ctr].e)
                  {
                     //Check for valid south connection
                     if(map[ctr].s)
                     {
                        //Set South tile
                        //Get a tile that has north connection
                        temp=get_tile(n);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.north_ptr=&map[ctr];
                        map[ctr].south_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid west connection
                     if(map[ctr].w)
                     {
                        //Set West tile
                        //Get a tile that has east connection
                        temp=get_tile(e);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.east_ptr=&map[ctr];
                        map[ctr].west_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid north connection
                     if(map[ctr].n)
                     {
                        //Set North tile
                        //Get a tile that has south connection
                        temp=get_tile(s);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.west_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.south_ptr=&map[ctr];
                        map[ctr].north_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                        
                     //Set East tile - not a deadend unless we have reached map size
                     //Check remaining number of tiles open in current map
                     tiles_remaining=MAP_SIZE-num_tiles;
                     
                     //Limit possible connecting tiles
                     switch(tiles_remaining)
                     {
                        case 1:
                           //Only 1 tile remaining, connecting tile must be a deadend
                           //Get a tile that has west connection
                           temp=get_tile(w);
                           
                           //Increment number of tiles
                           num_tiles++;
                           
                           //Set up temporary tile
                           set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                           
                           //Connect tiles
                           temp.north_ptr=NULL;
                           temp.east_ptr=NULL;
                           temp.west_ptr=NULL;
                           temp.west_ptr=&map[ctr];
                           map[ctr].east_ptr=&temp;
                                             
                           //Check stair flag
                           if(temp.stairs)
                              stair_flag=1;
                           break;
                           
                        case 2:
                           //Only 2 tiles remaining, connecting tile must have 2 connections
                           //Determine which tile with 2 connections that has a west connection.
                           roll2=dice_roll(3);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and West connections
                              case 2:
                                 //Set up a North and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                        case 3:
                           //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                           //Determine which tile with either 2 or 3 connections that must have a
                           //West connection
                           roll2=dice_roll(6);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and West connections
                              case 2:
                                 //Set up a North and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and West connections
                              case 4:
                                 //Set up North, East, and West tile
                                 temp=get_tile(new);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                           default:
                              //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                              //Determine which tile that must have a West connection
                              roll2=dice_roll(7);
                              
                              switch(roll2)
                              {
                                  //Tile has East and West connections
                                  case 1:
                                    //Set up a East and West tile
                                    temp=get_tile(ew);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.south_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                 
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has North and West connections
                                 case 2:
                                    //Set up a North and West tile
                                    temp=get_tile(nw);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.south_ptr=NULL;
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has South and West connections
                                 case 3:
                                    //Set up a South and West tile
                                    temp=get_tile(sw);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a North, East, and West connections
                                 case 4:
                                    //Set up North, East, and West tile
                                    temp=get_tile(new);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has a North, West, and South connections
                                 case 5:
                                    //Set up North, West, and South tile
                                    temp=get_tile(nws);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a South, East, and West connections
                                 case 6:
                                    //Set up South, East, and West tile
                                    temp=get_tile(sew);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has all connections
                                 case 7:
                                    //Set up an all tile
                                    temp=get_tile(all);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=&map[ctr];
                                    map[ctr].east_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                              }
                              break;
                     }
                     
                     //Set next map tile
                     ctr++;
                     map[ctr]=*map[ctr-1].east_ptr;
                  }
                  break;
               
               //West is not a deadend
               case 4:
                  //Check for valid west connection
                  if(map[ctr].w)
                  {
                     //Check for valid south connection
                     if(map[ctr].s)
                     {
                        //Set South tile
                        //Get a tile that has north connection
                        temp=get_tile(n);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.north_ptr=&map[ctr];
                        map[ctr].south_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid north connection
                     if(map[ctr].n)
                     {
                        //Set North tile
                        //Get a tile that has south connection
                        temp=get_tile(s);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.east_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.south_ptr=&map[ctr];
                        map[ctr].north_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Check for valid east connection
                     if(map[ctr].e)
                     {
                        //Set East tile
                        //Get a tile that has west connection
                        temp=get_tile(w);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.north_ptr=NULL;
                        temp.west_ptr=&map[ctr];
                        map[ctr].east_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                     }
                     
                     //Set West tile - not a deadend unless we have reached map size
                     //Check remaining number of tiles open in current map
                     tiles_remaining=MAP_SIZE-num_tiles;
                     
                     //Limit possible connecting tiles
                     switch(tiles_remaining)
                     {
                        case 1:
                           //Only 1 tile remaining, connecting tile must be a deadend
                           //Get a tile that has east connection
                           temp=get_tile(e);
                           
                           //Increment number of tiles
                           num_tiles++;
                           
                           //Set up temporary tile
                           set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                           
                           //Connect tiles
                           temp.north_ptr=NULL;
                           temp.east_ptr=NULL;
                           temp.west_ptr=NULL;
                           temp.west_ptr=&map[ctr];
                           map[ctr].east_ptr=&temp;
                                             
                           //Check stair flag
                           if(temp.stairs)
                              stair_flag=1;
                           break;
                           
                        case 2:
                           //Only 2 tiles remaining, connecting tile must have 2 connections
                           //Determine which tile with 2 connections that have a east connection.
                           roll2=dice_roll(3);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a South and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and East connections
                              case 3:
                                 //Set up a South and East tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                        case 3:
                           //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                           //Determine which tile with either 2 or 3 connections that must have a
                           //East connection
                           roll2=dice_roll(6);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a North and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and East connections
                              case 3:
                                 //Set up a South and East tile
                                 temp=get_tile(se);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, East, and West connections
                              case 5:
                                 //Set up North, East, and Wesst tile
                                 temp=get_tile(new);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                           
                           default:
                              //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                              //Determine which tile that must have a East connection
                              roll2=dice_roll(7);
                              
                              switch(roll2)
                              {
                                  //Tile has East and West connections
                                  case 1:
                                    //Set up a East and West tile
                                    temp=get_tile(ew);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.south_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has North and East connections
                                 case 2:
                                    //Set up a North and East tile
                                    temp=get_tile(ne);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.south_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has South and East connections
                                 case 3:
                                    //Set up a South and East tile
                                    temp=get_tile(sw);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.north_ptr=NULL;
                                    temp.west_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a North, East, and South connections
                                 case 4:
                                    //Set up North, East, and South tile
                                    temp=get_tile(nes);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                       
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                 
                                 //Tile has a North, East, and West connections
                                 case 5:
                                    //Set up North, East, and West tile
                                    temp=get_tile(nws);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has a South, East, and West connections
                                 case 6:
                                    //Set up South, East, and West tile
                                    temp=get_tile(sew);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.west_ptr=NULL;
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                                    
                                 //Tile has all connections
                                 case 7:
                                    //Set up an all tile
                                    temp=get_tile(all);
                                    
                                    //Increment number of tiles
                                    num_tiles++;
                                    
                                    //Set up temporary tile
                                    set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                    
                                    //Connect tiles
                                    temp.east_ptr=&map[ctr];
                                    map[ctr].west_ptr=&temp;
                                    
                                    //Check stair flag
                                    if(temp.stairs)
                                       stair_flag=1;
                                    break;
                              }
                              break;
                     }
                     
                     //Set next map tile
                     ctr++;
                     map[ctr]=*map[ctr-1].west_ptr;
                  }
                  break;
            }
            break;
         
         //Current map tile can connect in all directions
         case 4:
            //Determine which direction is not a deadend
            roll=dice_roll(4);
            
            //Switch statement for directions
            switch(roll)
            {
               //North is not a deadend
               case 1:
                  //Set South tile
                  //Get a tile that has north connection
                  temp=get_tile(n);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.north_ptr=&map[ctr];
                  map[ctr].south_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set West tile
                  //Get a tile that has east connection
                  temp=get_tile(e);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.east_ptr=&map[ctr];
                  map[ctr].west_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set East tile
                  //Get a tile that has west connection
                  temp=get_tile(w);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=&map[ctr];
                  map[ctr].east_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set North tile - not a deadend unless we have reached map size
                  //Check remaining number of tiles open in current map
                  tiles_remaining=MAP_SIZE-num_tiles;
                  
                  //Limit possible connecting tiles
                  switch(tiles_remaining)
                  {
                     case 1:
                        //Only 1 tile remaining, connecting tile must be a deadend
                        //Get a tile that has south connection
                        temp=get_tile(s);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.north_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.south_ptr=&map[ctr];
                        map[ctr].north_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                        break;
                        
                     case 2:
                        //Only 2 tiles remaining, connecting tile must have 2 connections
                        //Determine which tile with 2 connections that has a south connection.
                        roll2=dice_roll(3);
                        
                        switch(roll2)
                        {
                            //Tile has North and South connections
                            case 1:
                              //Set up a North and South tile
                              temp=get_tile(ns);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has South and East connections
                           case 2:
                              //Set up a South and East tile
                              temp=get_tile(se);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and West connections
                           case 3:
                              //Set up a South and West tile
                              temp=get_tile(sw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                     case 3:
                        //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                        //Determine which tile with either 2 or 3 connections that must has a
                        //South connection
                        roll2=dice_roll(6);
                        
                        switch(roll2)
                        {
                            //Tile has North and South connections
                            case 1:
                              //Set up a North and South tile
                              temp=get_tile(ns);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has South and East connections
                           case 2:
                              //Set up a South and East tile
                              temp=get_tile(se);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and West connections
                           case 3:
                              //Set up a South and West tile
                              temp=get_tile(sw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a North, East, and South connections
                           case 4:
                              //Set up North, East, and South tile
                              temp=get_tile(nes);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.west_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has a North, West, and South connections
                           case 5:
                              //Set up North, West, and South tile
                              temp=get_tile(nws);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a South, East, and West connections
                           case 6:
                              //Set up South, East, and West tile
                              temp=get_tile(sew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.south_ptr=&map[ctr];
                              map[ctr].north_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                        default:
                           //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                           //Determine which tile that must have a South connection
                           roll2=dice_roll(7);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has South and East connections
                              case 2:
                                 //Set up a South and East tile
                                 temp=get_tile(se);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has all connections
                              case 7:
                                 //Set up an all tile
                                 temp=get_tile(all);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=&map[ctr];
                                 map[ctr].north_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                  }
                  
                  //Set next map tile
                  ctr++;
                  map[ctr]=*map[ctr-1].north_ptr;
                  break;
                  
               //South is not a deadend
               case 2:
                  //Set North tile
                  //Get a tile that has south connection
                  temp=get_tile(s);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.north_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.south_ptr=&map[ctr];
                  map[ctr].north_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set West tile
                  //Get a tile that has east connection
                  temp=get_tile(e);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.east_ptr=&map[ctr];
                  map[ctr].west_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set East tile
                  //Get a tile that has west connection
                  temp=get_tile(w);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=&map[ctr];
                  map[ctr].east_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set North tile - not a deadend unless we have reached map size
                  //Check remaining number of tiles open in current map
                  tiles_remaining=MAP_SIZE-num_tiles;
                  
                  //Limit possible connecting tiles
                  switch(tiles_remaining)
                  {
                     case 1:
                        //Only 1 tile remaining, connecting tile must be a deadend
                        //Get a tile that has north connection
                        temp=get_tile(n);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.south_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.north_ptr=&map[ctr];
                        map[ctr].south_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                        break;
                        
                     case 2:
                        //Only 2 tiles remaining, connecting tile must have 2 connections
                        //Determine which tile with 2 connections that have a north connection.
                        roll2=dice_roll(3);
                        
                        switch(roll2)
                        {
                            //Tile has North and South connections
                            case 1:
                              //Set up a North and South tile
                              temp=get_tile(ns);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and East connections
                           case 2:
                              //Set up a North and East tile
                              temp=get_tile(ne);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has North and West connections
                           case 3:
                              //Set up a South and West tile
                              temp=get_tile(nw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                     case 3:
                        //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                        //Determine which tile with either 2 or 3 connections that must have a
                        //North connection
                        roll2=dice_roll(6);
                        
                        switch(roll2)
                        {
                            //Tile has North and South connections
                            case 1:
                              //Set up a North and South tile
                              temp=get_tile(ns);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and East connections
                           case 2:
                              //Set up a North and East tile
                              temp=get_tile(ne);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has North and West connections
                           case 3:
                              //Set up a North and West tile
                              temp=get_tile(nw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a North, East, and South connections
                           case 4:
                              //Set up North, East, and South tile
                              temp=get_tile(nes);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.west_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has a North, West, and South connections
                           case 5:
                              //Set up North, West, and South tile
                              temp=get_tile(nws);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a North, East, and West connections
                           case 6:
                              //Set up South, East, and West tile
                              temp=get_tile(new);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.north_ptr=&map[ctr];
                              map[ctr].south_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                        default:
                           //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                           //Determine which tile that must have a South connection
                           roll2=dice_roll(7);
                           
                           switch(roll2)
                           {
                               //Tile has North and South connections
                               case 1:
                                 //Set up a North and South tile
                                 temp=get_tile(ns);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a North and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has North and West connections
                              case 3:
                                 //Set up a North and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(new);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has all connections
                              case 7:
                                 //Set up an all tile
                                 temp=get_tile(all);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=&map[ctr];
                                 map[ctr].south_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                  }
                  
                  //Set next map tile
                  ctr++;
                  map[ctr]=*map[ctr-1].south_ptr;
                  break;
                  
               //East is not a deadend
               case 3:
                  //Set South tile
                  //Get a tile that has north connection
                  temp=get_tile(n);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.north_ptr=&map[ctr];
                  map[ctr].south_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set West tile
                  //Get a tile that has east connection
                  temp=get_tile(e);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.east_ptr=&map[ctr];
                  map[ctr].west_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set North tile
                  //Get a tile that has south connection
                  temp=get_tile(s);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.west_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.south_ptr=&map[ctr];
                  map[ctr].north_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set East tile - not a deadend unless we have reached map size
                  //Check remaining number of tiles open in current map
                  tiles_remaining=MAP_SIZE-num_tiles;
                  
                  //Limit possible connecting tiles
                  switch(tiles_remaining)
                  {
                     case 1:
                        //Only 1 tile remaining, connecting tile must be a deadend
                        //Get a tile that has west connection
                        temp=get_tile(w);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.north_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.west_ptr=&map[ctr];
                        map[ctr].east_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                        break;
                        
                     case 2:
                        //Only 2 tiles remaining, connecting tile must have 2 connections
                        //Determine which tile with 2 connections that has a west connection.
                        roll2=dice_roll(3);
                        
                        switch(roll2)
                        {
                            //Tile has East and West connections
                            case 1:
                              //Set up a East and West tile
                              temp=get_tile(ew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.south_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and West connections
                           case 2:
                              //Set up a North and West tile
                              temp=get_tile(nw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and West connections
                           case 3:
                              //Set up a South and West tile
                              temp=get_tile(sw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                     case 3:
                        //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                        //Determine which tile with either 2 or 3 connections that must have a
                        //West connection
                        roll2=dice_roll(6);
                        
                        switch(roll2)
                        {
                            //Tile has East and West connections
                            case 1:
                              //Set up a East and West tile
                              temp=get_tile(ew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.south_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and West connections
                           case 2:
                              //Set up a North and West tile
                              temp=get_tile(nw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and West connections
                           case 3:
                              //Set up a South and West tile
                              temp=get_tile(sw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a North, East, and West connections
                           case 4:
                              //Set up North, East, and West tile
                              temp=get_tile(new);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has a North, West, and South connections
                           case 5:
                              //Set up North, West, and South tile
                              temp=get_tile(nws);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.east_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a South, East, and West connections
                           case 6:
                              //Set up South, East, and West tile
                              temp=get_tile(sew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=&map[ctr];
                              map[ctr].east_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                        default:
                           //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                           //Determine which tile that must have a West connection
                           roll2=dice_roll(7);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                              
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and West connections
                              case 2:
                                 //Set up a North and West tile
                                 temp=get_tile(nw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and West connections
                              case 3:
                                 //Set up a South and West tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and West connections
                              case 4:
                                 //Set up North, East, and West tile
                                 temp=get_tile(new);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, West, and South connections
                              case 5:
                                 //Set up North, West, and South tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has all connections
                              case 7:
                                 //Set up an all tile
                                 temp=get_tile(all);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=&map[ctr];
                                 map[ctr].east_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                  }
                  
                  //Set next map tile
                  ctr++;
                  map[ctr]=*map[ctr-1].east_ptr;
                  break;
                  
               //West is not a deadend
               case 4:
                  //Set South tile
                  //Get a tile that has north connection
                  temp=get_tile(n);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.north_ptr=&map[ctr];
                  map[ctr].south_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set North tile
                  //Get a tile that has south connection
                  temp=get_tile(s);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.east_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=NULL;
                  temp.south_ptr=&map[ctr];
                  map[ctr].north_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set East tile
                  //Get a tile that has west connection
                  temp=get_tile(w);
                  
                  //Increment number of tiles
                  num_tiles++;
                  
                  //Set up temporary tile
                  set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                  
                  //Connect tiles
                  temp.south_ptr=NULL;
                  temp.east_ptr=NULL;
                  temp.north_ptr=NULL;
                  temp.west_ptr=&map[ctr];
                  map[ctr].east_ptr=&temp;
                                    
                  //Check stair flag
                  if(temp.stairs)
                     stair_flag=1;
                     
                  //Set West tile - not a deadend unless we have reached map size
                  //Check remaining number of tiles open in current map
                  tiles_remaining=MAP_SIZE-num_tiles;
                  
                  //Limit possible connecting tiles
                  switch(tiles_remaining)
                  {
                     case 1:
                        //Only 1 tile remaining, connecting tile must be a deadend
                        //Get a tile that has east connection
                        temp=get_tile(e);
                        
                        //Increment number of tiles
                        num_tiles++;
                        
                        //Set up temporary tile
                        set_tile_up(&temp,1,dungeon_level,stair_flag,num_tiles);
                        
                        //Connect tiles
                        temp.north_ptr=NULL;
                        temp.east_ptr=NULL;
                        temp.west_ptr=NULL;
                        temp.west_ptr=&map[ctr];
                        map[ctr].east_ptr=&temp;
                                          
                        //Check stair flag
                        if(temp.stairs)
                           stair_flag=1;
                        break;
                        
                     case 2:
                        //Only 2 tiles remaining, connecting tile must have 2 connections
                        //Determine which tile with 2 connections that have a east connection.
                        roll2=dice_roll(3);
                        
                        switch(roll2)
                        {
                            //Tile has East and West connections
                            case 1:
                              //Set up a East and West tile
                              temp=get_tile(ew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.south_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and East connections
                           case 2:
                              //Set up a South and East tile
                              temp=get_tile(ne);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and East connections
                           case 3:
                              //Set up a South and East tile
                              temp=get_tile(sw);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                     case 3:
                        //Only 3 tiles remaining, connecting tiles must have either 2 or 3 connections
                        //Determine which tile with either 2 or 3 connections that must have a
                        //East connection
                        roll2=dice_roll(6);
                        
                        switch(roll2)
                        {
                            //Tile has East and West connections
                            case 1:
                              //Set up a East and West tile
                              temp=get_tile(ew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.south_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has North and East connections
                           case 2:
                              //Set up a North and East tile
                              temp=get_tile(ne);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has South and East connections
                           case 3:
                              //Set up a South and East tile
                              temp=get_tile(se);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.west_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a North, East, and South connections
                           case 4:
                              //Set up North, East, and South tile
                              temp=get_tile(nes);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.west_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                           
                           //Tile has a North, East, and West connections
                           case 5:
                              //Set up North, East, and Wesst tile
                              temp=get_tile(new);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.south_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                              
                           //Tile has a South, East, and West connections
                           case 6:
                              //Set up South, East, and West tile
                              temp=get_tile(sew);
                              
                              //Increment number of tiles
                              num_tiles++;
                              
                              //Set up temporary tile
                              set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                              
                              //Connect tiles
                              temp.north_ptr=NULL;
                              temp.east_ptr=&map[ctr];
                              map[ctr].west_ptr=&temp;
                              
                              //Check stair flag
                              if(temp.stairs)
                                 stair_flag=1;
                              break;
                        }
                        break;
                        
                        default:
                           //4 or more tiles remaining, connecting tiles can have all connections (no deadend)
                           //Determine which tile that must have a East connection
                           roll2=dice_roll(7);
                           
                           switch(roll2)
                           {
                               //Tile has East and West connections
                               case 1:
                                 //Set up a East and West tile
                                 temp=get_tile(ew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.south_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has North and East connections
                              case 2:
                                 //Set up a North and East tile
                                 temp=get_tile(ne);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.south_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has South and East connections
                              case 3:
                                 //Set up a South and East tile
                                 temp=get_tile(sw);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,2,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.north_ptr=NULL;
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a North, East, and South connections
                              case 4:
                                 //Set up North, East, and South tile
                                 temp=get_tile(nes);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                              
                              //Tile has a North, East, and West connections
                              case 5:
                                 //Set up North, East, and West tile
                                 temp=get_tile(nws);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has a South, East, and West connections
                              case 6:
                                 //Set up South, East, and West tile
                                 temp=get_tile(sew);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,3,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.west_ptr=NULL;
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                                 
                              //Tile has all connections
                              case 7:
                                 //Set up an all tile
                                 temp=get_tile(all);
                                 
                                 //Increment number of tiles
                                 num_tiles++;
                                 
                                 //Set up temporary tile
                                 set_tile_up(&temp,4,dungeon_level,stair_flag,num_tiles);
                                 
                                 //Connect tiles
                                 temp.east_ptr=&map[ctr];
                                 map[ctr].west_ptr=&temp;
                                 
                                 //Check stair flag
                                 if(temp.stairs)
                                    stair_flag=1;
                                 break;
                           }
                           break;
                  }
                  
                  //Set next map tile
                  ctr++;
                  map[ctr]=*map[ctr-1].west_ptr;
                  break;
            }
      }