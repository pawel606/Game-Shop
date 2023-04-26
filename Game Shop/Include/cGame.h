//
// Created by paweł on 5/28/2022.
//

#ifndef TESTOWANIE_CGAME_H
#define TESTOWANIE_CGAME_H


#include <string>

class cGame {
    int mGameSize;
    std::string mTitle;
    std::string mPlatform;
    std::string mGenre;
    double mPrice;
    bool mAvailability = true;

public:
    cGame(int,std::string,std::string,std::string,double,bool);
    virtual std::string Show();
    virtual ~cGame();
    void setAvailability(bool a);
    std::string getPlatform();
    std::string getTitle();
    double getPrice();
    bool getAvailability();
};


#endif //TESTOWANIE_CGAME_H
