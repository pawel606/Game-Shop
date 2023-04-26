//
// Created by paweł on 5/28/2022.
//

#ifndef TESTOWANIE_CSINGLE_H
#define TESTOWANIE_CSINGLE_H

#include "cGame.h"

class cSingle : public cGame
{
    int mGameLenght;

public:
    cSingle(int,std::string,std::string,std::string,double,bool,int);
    ~cSingle();
    std::string Show();

};


#endif //TESTOWANIE_CSINGLE_H
