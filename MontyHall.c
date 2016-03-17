/*************************************
   Monty Hall Problem
   Bokwon Yoon, Mar. 17, 2016
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int n, count, NN = 0;
    int carpos, selpos, openpos;

    if (argc == 2) NN = atoi(argv[1]);
    if (NN <= 0) NN = 100000; 

    srand(time(NULL));
    
    count = 0;
    for (n = 0; n < NN; n++) {
        carpos = random()%3;
        selpos = random()%3;
        if (carpos == selpos) count++;
    }
    printf("unswap: %.3f %\n", (double)count/(double)NN*100.0);

    count = 0;
    for (n = 0; n < NN; n++) {
        carpos = random()%3;
        selpos = random()%3;
        // The show host knows where the car is.
        if (carpos == selpos) {
            // If the quiz player's selection is the car, 
            // the show host will open any of the other two doors
            // and quiz player will open the other of the two
            openpos = (selpos+random()%2+1)%3; 
            if (selpos == 0) {
                selpos = (openpos == 1) ? 2 : 1;
            } else if (selpos == 1) {
                selpos = (openpos == 2) ? 0 : 2;
            } else {
                selpos = (openpos == 0) ? 1 : 0;
            }
        } else {
            // If the quiz player's selection is NOT the car, 
            // the show host will open the door of the room with a goat
            // and quiz player will open the other door of the room with the car
            if (selpos == 0) {
                openpos = (carpos == 1) ? 2 : 1;
                selpos = (openpos == 1) ? 2 : 1;
            } else if (selpos == 1) {
                openpos = (carpos == 2) ? 0 : 2;
                selpos = (openpos == 2) ? 0 : 2;
            } else {
                openpos = (carpos == 0) ? 1 : 0;
                selpos = (openpos == 0) ? 1 : 0;
            }
        }
        if (carpos == selpos) count++;
    }
    printf("  swap: %.3f %\n", (double)count/(double)NN*100.0);

    return 0;
}
