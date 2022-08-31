#ifndef FRIENDS_H_
#define FRIENDS_H_

#include <string>

namespace friends {
    const int max_str = 101;
    const int max_friends = 10;

    struct persona {
        std::string name;
        std::string surname;
        std::string address;
        short int age;
    };

    typedef struct persona farray[max_friends];
    typedef short int ftable[max_friends][max_friends];

    bool fimport(const char filepath[], farray &target);
    bool shipgen(const char filepath[], ftable &target);
    void agepr(const farray &peoples, const ftable &friendships);
}

#endif /*FRIENDS_H_*/