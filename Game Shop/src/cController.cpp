//
// Created by paweł on 6/8/2022.
//

#include "../Include/cController.h"
#include "iostream"


cController::cController()
{
    mBaza = new cBaza(this);
    mWidok = new cView(this);
    std::cout<<mBaza;
}

cController::~cController()
{

}

int cController::run()
{
    while(mWidok->isOpen())
    {
    mWidok->checkEvents();
    }
    delete mBaza;
    delete mWidok;
    return(0);
}

std::string cController::ShowCoolBase()
{
    return mBaza->ShowBase();
}
std::string cController::ShowTitle(int a)
{
    return mBaza->showTitle(a);
}
std::string cController::ShowInfo(int a)
{
    return mBaza->showInfo(a);
}

void cController::Borrow(int a) {
    mBaza->BorrowGame(a);
}

std::string cController::ShowCart() {
    return mBaza->ShowCart();
}

void cController::AddCart(int a) {
    mBaza->AddtoCart(a);
}

std::string cController::ShowCartvalue() {
    return std::to_string(mBaza->getCartValue());
}
