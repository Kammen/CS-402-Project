map_tile get_tile_value(map_tile *ptr)
{
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   return *(ptr+num);
}

//Function to return a map tile from specified file
//Can not have the same tile multiple times - causes issues
map_tile* get_tile(map_tile *ptr)
{
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   static all_rolls[FILE_NUM_MAP_TILES];
   static nes_rolls[FILE_NUM_MAP_TILES];
   static new_rolls[FILE_NUM_MAP_TILES];
   static nws_rolls[FILE_NUM_MAP_TILES];
   static sew_rolls[FILE_NUM_MAP_TILES];
   static ne_rolls[FILE_NUM_MAP_TILES];
   static nw_rolls[FILE_NUM_MAP_TILES];
   static ns_rolls[FILE_NUM_MAP_TILES];
   static ew_rolls[FILE_NUM_MAP_TILES];
   static sw_rolls[FILE_NUM_MAP_TILES];
   static se_rolls[FILE_NUM_MAP_TILES];
   static n_rolls[FILE_NUM_MAP_TILES];
   static e_rolls[FILE_NUM_MAP_TILES];
   static s_rolls[FILE_NUM_MAP_TILES];
   static w_rolls[FILE_NUM_MAP_TILES];


   //Return random tile
   return (ptr+num);
}

map_tile* get_tile_all()
{
   //Generate a random number
   int num=dice_roll(FILE_NUM_MAP_TILES)-1;
   
   static all_rolls[FILE_NUM_MAP_TILES];

   //Check if number has been called before
   while(all_rolls[num])
      num=dice_roll(FILE_NUM_MAP_TILES)-1;

   all_rolls[num]=1;
   return (all+num);

}
map_tile* get_tile_nes()
{

}
map_tile* get_tile_new()
{
   
}
map_tile* get_tile_nws()
{
   
}
map_tile* get_tile_sew()
{
   
}
map_tile* get_tile_ne()
{
   
}
map_tile* get_tile_nw()
{
   
}
map_tile* get_tile_ns()
{
   
}
map_tile* get_tile_ew()
{
   
}
map_tile* get_tile_sw()
{
   
}
map_tile* get_tile_se()
{
   
}
map_tile* get_tile_n()
{
   
}
map_tile* get_tile_e()
{
   
}
map_tile* get_tile_s()
{
   
}
map_tile* get_tile_w()
{
   
}





















//Predefined layout for map #1
map_tile* layout_one(map_tile *head,int dungeon_level)
{
   //Initialize variables
   int num_tiles=0;
   int flag=0;
   map_tile *map=malloc(sizeof(map_tile));
   map_tile *t1=malloc(sizeof(map_tile));
   map_tile *t2=malloc(sizeof(map_tile));
   map_tile *t3=malloc(sizeof(map_tile));
   map_tile *t4=malloc(sizeof(map_tile));
   map_tile *t5=malloc(sizeof(map_tile));
   map_tile *t6=malloc(sizeof(map_tile));
   map_tile *t7=malloc(sizeof(map_tile));
   map_tile *t8=malloc(sizeof(map_tile));
   map_tile *t9=malloc(sizeof(map_tile));
   map_tile *t10=malloc(sizeof(map_tile));
   map_tile *t11=malloc(sizeof(map_tile));
   map_tile *t12=malloc(sizeof(map_tile));
   map_tile *t13=malloc(sizeof(map_tile));
   map_tile *t14=malloc(sizeof(map_tile));
   map_tile *t15=malloc(sizeof(map_tile));
   map_tile *t16=malloc(sizeof(map_tile));

   //Get map tiles
   t1=get_tile(n);
   t2=get_tile(all);
   t3=get_tile(s);
   t4=get_tile(ew);
   t5=get_tile(e);
   t6=get_tile(sew);
   t7=get_tile(w);
   t8=get_tile(ns);
   t9=get_tile(new);
   t10=get_tile(w);
   t11=get_tile(se);
   t12=get_tile(all);
   t13=get_tile(e);
   t14=get_tile(w);
   t15=get_tile(ns);
   t16=get_tile(n);

   //Set tiles up
   set_tile_up(t1,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t2,4,dungeon_level,flag,++num_tiles);
   set_tile_up(t3,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t4,2,dungeon_level,flag,++num_tiles);
   set_tile_up(t5,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t6,3,dungeon_level,flag,++num_tiles);
   set_tile_up(t7,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t8,2,dungeon_level,flag,++num_tiles);
   set_tile_up(t9,3,dungeon_level,flag,++num_tiles);
   set_tile_up(t10,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t11,2,dungeon_level,flag,++num_tiles);
   set_tile_up(t12,4,dungeon_level,flag,++num_tiles);
   set_tile_up(t13,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t14,1,dungeon_level,flag,++num_tiles);
   set_tile_up(t15,2,dungeon_level,flag,++num_tiles);
   set_tile_up(t16,1,dungeon_level,flag,++num_tiles);

   //Set connections
   head=t1;

   t1->north_ptr=t2;

   t2->north_ptr=t3;
   t2->east_ptr=t6;
   t2->south_ptr=t1;
   t2->west_ptr=t4;

   t3->south_ptr=t2;

   t4->east_ptr=t2;
   t4->west_ptr=t5;

   t5->east_ptr=t4;

   t6->east_ptr=t7;
   t6->south_ptr=t8;
   t6->west_ptr=t2;

   t7->west_ptr=t6;

   t8->north_ptr=t6;
   t8->south_ptr=t9;

   t9->north_ptr=t8;
   t9->east_ptr=t10;
   t9->west_ptr=t11;

   t10->west_ptr=t9;

   t11->east_ptr=t9;
   t11->south_ptr=t12;

   t12->north_ptr=t11;
   t12->east_ptr=t14;
   t12->south_ptr=t15;
   t12->west_ptr=t13;

   t13->east_ptr=t12;

   t14->west_ptr=t12;

   t15->north_ptr=t12;
   t15->south_ptr=t16;

   t16->north_ptr=t15;

   //Return head
   return head;
}

//Predefined layout for map #1
map_tile* layout_one(map_tile *head,int dungeon_level)
{
   //Initialize variables
   int num_tiles=0;
   int flag=0;
   map_tile *map=malloc(sizeof(map_tile));
   map_tile *tt1=malloc(sizeof(map_tile));
   map_tile *tt2=malloc(sizeof(map_tile));
   map_tile *tt3=malloc(sizeof(map_tile));
   map_tile *tt4=malloc(sizeof(map_tile));
   map_tile *tt5=malloc(sizeof(map_tile));
   map_tile *tt6=malloc(sizeof(map_tile));
   map_tile *tt7=malloc(sizeof(map_tile));
   map_tile *tt8=malloc(sizeof(map_tile));
   map_tile *tt9=malloc(sizeof(map_tile));
   map_tile *tt10=malloc(sizeof(map_tile));
   map_tile *tt11=malloc(sizeof(map_tile));
   map_tile *tt12=malloc(sizeof(map_tile));
   map_tile *tt13=malloc(sizeof(map_tile));
   map_tile *tt14=malloc(sizeof(map_tile));
   map_tile *tt15=malloc(sizeof(map_tile));
   map_tile *tt16=malloc(sizeof(map_tile));
   
   map_tile t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16;
   
   //Get map tiles
   t1=get_tile_value(n);
   tt1=&t1;
   t2=get_tile_value(all);
   tt2=&t2;
   t3=get_tile_value(s);
   tt3=&t3;
   t4=get_tile_value(ew);
   tt4=&t4;
   t5=get_tile_value(e);
   tt5=&t5;
   t6=get_tile_value(sew);
   tt6=&t6;
   t7=get_tile_value(w);
   tt7=&t7;
   t8=get_tile_value(ns);
   tt8=&t8;
   t9=get_tile_value(new);
   tt9=&t9;
   t10=get_tile_value(w);
   tt10=&t10;
   t11=get_tile_value(se);
   tt11=&t11;
   t12=get_tile_value(all);
   tt12=&t12;
   t13=get_tile_value(e);
   tt13=&t13;
   t14=get_tile_value(w);
   tt14=&t14;
   t15=get_tile_value(ns);
   tt15=&t15;
   t16=get_tile_value(n);
   tt16=&t16;

   //Set tiles up
   set_tile_up(tt1,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt2,4,dungeon_level,flag,++num_tiles);
   set_tile_up(tt3,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt4,2,dungeon_level,flag,++num_tiles);
   set_tile_up(tt5,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt6,3,dungeon_level,flag,++num_tiles);
   set_tile_up(tt7,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt8,2,dungeon_level,flag,++num_tiles);
   set_tile_up(tt9,3,dungeon_level,flag,++num_tiles);
   set_tile_up(tt10,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt11,2,dungeon_level,flag,++num_tiles);
   set_tile_up(tt12,4,dungeon_level,flag,++num_tiles);
   set_tile_up(tt13,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt14,1,dungeon_level,flag,++num_tiles);
   set_tile_up(tt15,2,dungeon_level,flag,++num_tiles);
   set_tile_up(tt16,1,dungeon_level,flag,++num_tiles);

   //Set connections
   head=tt1;

   tt1->north_ptr=tt2;

   tt2->north_ptr=tt3;
   tt2->east_ptr=tt6;
   tt2->south_ptr=tt1;
   tt2->west_ptr=tt4;

   tt3->south_ptr=tt2;

   tt4->east_ptr=tt2;
   tt4->west_ptr=tt5;

   tt5->east_ptr=tt4;

   tt6->east_ptr=tt7;
   tt6->south_ptr=tt8;
   tt6->west_ptr=tt2;

   tt7->west_ptr=tt6;

   tt8->north_ptr=tt6;
   tt8->south_ptr=tt9;

   tt9->north_ptr=tt8;
   tt9->east_ptr=tt10;
   tt9->west_ptr=tt11;

   tt10->west_ptr=tt9;

   tt11->east_ptr=tt9;
   tt11->south_ptr=tt12;

   tt12->north_ptr=tt11;
   tt12->east_ptr=tt14;
   tt12->south_ptr=tt15;
   tt12->west_ptr=tt13;

   tt13->east_ptr=tt12;

   tt14->west_ptr=tt12;

   tt15->north_ptr=tt12;
   tt15->south_ptr=tt16;

   tt16->north_ptr=tt15;
   
   //print_tile(tt1);   
   //print_tile(tt16);
   print_tile(head);
   return head;
}

//Predefined layout for map #1
map_tile* layout_one(map_tile *head,int dungeon_level)
{
   //Initialize variables
   int num_tiles=0;
   int flag=0;
   map_tile *map=malloc(sizeof(map_tile));
   map_tile *t1=malloc(sizeof(map_tile));
   map_tile *t2=malloc(sizeof(map_tile));
   map_tile *t3=malloc(sizeof(map_tile));
   map_tile *t4=malloc(sizeof(map_tile));
   map_tile *t5=malloc(sizeof(map_tile));
   map_tile *t6=malloc(sizeof(map_tile));
   map_tile *t7=malloc(sizeof(map_tile));
   map_tile *t8=malloc(sizeof(map_tile));
   map_tile *t9=malloc(sizeof(map_tile));
   map_tile *t10=malloc(sizeof(map_tile));
   map_tile *t11=malloc(sizeof(map_tile));
   map_tile *t12=malloc(sizeof(map_tile));
   map_tile *t13=malloc(sizeof(map_tile));
   map_tile *t14=malloc(sizeof(map_tile));
   map_tile *t15=malloc(sizeof(map_tile));
   map_tile *t16=malloc(sizeof(map_tile));