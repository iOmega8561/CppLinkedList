#include <iostream>
#include "friends.h"

#define succ 0

int main(int argc, char **argv) {
    friends::farray mygroup; 
    friends::ftable friendships;

    bool rs = friends::fimport("peoples.txt", mygroup);
    if (!rs) { return EXIT_FAILURE; }

    rs = friends::shipgen("friends.txt", friendships);
    if (!rs) { return EXIT_FAILURE; }
    
    friends::agepr(mygroup, friendships);

    return EXIT_SUCCESS;
}