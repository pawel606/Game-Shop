//
// Created by paweł on 5/28/2022.
//

#include "../Include/cGame.h"
#include <iostream>
#include <sstream>

using namespace std;


cGame::cGame(int gameSize,string title, string platform,
             string genre, double price,bool availability):mGameSize(gameSize),mTitle(title),
                                                           mPlatform(platform),mGenre(genre),mPrice(price),mAvailability(availability)
{
}

cGame::~cGame()
{
}

string cGame::Show()
{
    string output;
    string Available;
    stringstream stream_output;
    if(mAvailability) Available="Gra dostepna ";
    else Available = "Gra nie dostepna ";
    stream_output <<"Tutul:\t"<< mTitle << "\nPlatforma:\t" << mPlatform << "\nGatunek:\t" << mGenre << "\nWielkosc gry:\t"
    << mGameSize << "\nCena:\t" << mPrice << "zl\nDostepnosc:\t"<<Available;
    output = stream_output.str();
    return output;
}

void cGame::setAvailability(bool a)
{
    mAvailability = a;
}
string cGame::getPlatform()
{
    return mPlatform;
}
bool cGame::getAvailability()
{
    return mAvailability;
}

std::string cGame::getTitle()
{
    return mTitle;
}

double cGame::getPrice()
{
    return mPrice;
}