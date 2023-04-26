//
// Created by paweł on 6/8/2022.
//

#ifndef TESTOWANIE_CCONTROLLER_H
#define TESTOWANIE_CCONTROLLER_H

#include "cView.h"
#include "cBase.h"


class cController {
    cBaza *mBaza;
    cView *mWidok;


public:
    cController();
    ~cController();

    std::string ShowCoolBase();
    std::string ShowInfo(int a);
    std::string ShowTitle(int a);
    std::string ShowCart();
    std::string ShowCartvalue();
    void AddCart(int a);
    void Borrow(int a);

    int run();

};


#endif //TESTOWANIE_CCONTROLLER_H
