#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cassert>
#include "friends.h"

bool friends::fimport (const char filepath[], friends::farray &target) {
    assert( std::strlen(filepath) > 0 && target != NULL);

    std::ifstream source (filepath);
    if (source.is_open()) {
        for(int c=0; c < friends::max_friends; c++) {
            getline(source, target[c].name);
            getline(source, target[c].surname);
            getline(source, target[c].address);
            std::string age; getline(source, age);
            target[c].age = std::stoi(age);
        }

        source.close();
        return true;
    }

    return false;
};

bool friends::shipgen (const char filepath[], friends::ftable &target) {
    assert( std::strlen(filepath) > 0 && target != NULL);

    std::ifstream source (filepath);
    if (source.is_open()) {
        for(int r=0; r < friends::max_friends; r++) {
            for(int c=0; c < friends::max_friends; c++)
                target[c][r] = 0;
        }

        int x, y;
        while(source >> x && source >> y) {
            target[x][y] = 1;
            target[y][x] = 1;
        }

        source.close();
        return true;
    }

    return false;
};

void friends::agepr (const farray &peoples, const ftable &friendships) {
    assert(peoples != NULL && friendships != NULL);
    int sum = 0, fnds = 0;

    for(int r=0; r < friends::max_friends; r++) {
        sum = 0, fnds = 0;

        for (int c = 0; c < friends::max_friends; c++) {
            if (friendships[r][c] != 0) {
                fnds++;
                sum+=peoples[c].age;
            }
        }

        if (sum != 0)
            std::cout << "target [" << r << "] medium age is: " <<  sum / fnds << std::endl;
    }

    return;
}