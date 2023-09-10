#include <iostream>
#include <string>
#include <math.h>

#include "qmaths.hpp"

using std::string, std::cout, std::endl;

int enemylvld(string stat, int lvl){

    if(lvl <= 1){
        return 0;
    }

    if(stat == "HP"){
        return (lvl * 5);
    }
    else if(stat == "ATK"){
        return (lvl * 3);
    }
    else if(stat == "DEF"){
        return (lvl * 2);
    }
    else{
        cout << "lvld kinda error" <<endl;
        exit(EXIT_FAILURE);
    }
    
}

