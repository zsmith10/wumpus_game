#include <iostream>
#include <vector>
#include <string>

#include "events.h"
#include "room.h"
#include "game.h"
#include <stdlib.h>
/***************************************************************
 * Filename: prog.cpp
 * Author: Zachary Smith
 * Date: 5/10/2020
 * Decription: Game where you buy and sell as many animals
 * Input: animal type, amount of animals
 * Output: monkey num, sloth num, otter num, adult num, baby num, balance
 * ************************************************************/
int main(int argc, char const *argv[]){
   bool debug;
   string word = argv[2];
   if(word  == "true" || word  == "True"){
      debug = true;
   }
   else if(word  == "false" || word  == "False"){
      debug = false;
   }
   int dim = strtol(argv[1],NULL,10);
   Game g1(1,2,1,2,dim,debug,3);
   g1.run_game();
   return 0;
}
