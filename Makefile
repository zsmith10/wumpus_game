CC = g++
EXE = wumpus_runner

$(EXE): main.cpp bat.cpp pit.cpp wompus.cpp gold.cpp player.cpp empty_room.cpp room.cpp game.cpp events.cpp events.h room.h bat.h pit.h wompus.h gold.h player.h empty_room.h game.h
				g++ -std=c++11 main.cpp bat.cpp pit.cpp wompus.cpp gold.cpp player.cpp room.cpp events.cpp empty_room.cpp game.cpp -o $(EXE)
