//
// Created by paweł on 5/28/2022.
//

#include "../Include/cSingle.h"
#include <iostream>
#include <sstream>

using namespace std;

cSingle::cSingle(int gameSize,string title, string platform,string genre, double price,bool availability,int gameLenght)
        : cGame(gameSize,title,platform,genre,price,availability) , mGameLenght(gameLenght)
{
    //cout<<"Konstruktor single"<<endl;
}

cSingle::~cSingle()
{
    //cout<<"Destruktor single"<<endl;
}

string cSingle::Show()
{
    string output;
    stringstream stream_output;
    stream_output << cGame::Show() + "\n Dlugosc gry:\t" << mGameLenght << "h"<<endl;
    output = stream_output.str();
    return output;
}
