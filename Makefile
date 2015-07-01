# Makefile
# main_test.c; encounters.c; npc.c; player_character.c; random_rolls.c; mersenne_twist.c; combat.c; map_tiles.c
# Jeff Skakun 11/8/14

#CXX = /usr/bin/gcc
#CXX = c:/cygwin/bin/gcc

CXX = gcc

all: main_test ;

main_test:  main_test.o encounters.o npc.o player_character.o random_rolls.o mersenne_twist.o combat.o map_tiles.o ; $(CXX) $^ -o main_test  

main_test.o: main_test.c ; $(CXX) -c $*.c
   
encounters.o: encounters.c ; $(CXX) -c $*.c

npc.o: npc.c ; $(CXX) -c $*.c

player_character.o:  player_character.c ; $(CXX) -c $*.c

random_rolls.o: random_rolls.c ; $(CXX) -c $*.c

mersenne_twist.o: mersenne_twist.c ; $(CXX) -c $*.c

combat.o: combat.c ; $(CXX) -c $*.c

map_tiles.o: map_tiles.c ; $(CXX) -c $*.c

clean: ; rm -f *.o main_test encounters npc player_character random_rolls mersenne_twist combat map_tiles
