//
// Created by paweł on 5/28/2022.
//

#ifndef TESTOWANIE_CMULTI_H
#define TESTOWANIE_CMULTI_H


#include "cGame.h"


class cMulti : public cGame
{
    bool mInternet = true;

public:
    cMulti(int,std::string,std::string,std::string,double,bool,bool);
    ~cMulti();
    std::string Show();

};


#endif //TESTOWANIE_CMULTI_H
