//
// Created by paweł on 5/28/2022.
//

#include <sstream>
#include "../Include/cMulti.h"
#include "iostream"

using namespace std;

cMulti::cMulti(int gameSize,string title, string platform,string genre, double price,bool availability,bool internet)
        : cGame(gameSize,title,platform,genre,price,availability) , mInternet(internet)
{
    //cout<<"Konstruktor Multi"<<endl;
}



cMulti::~cMulti()
{
    //cout<<"Destruktor Multi"<<endl;
}

string cMulti::Show()
{
    string output;
    stringstream stream_output;
    stream_output << cGame::Show() + "\nPolaczenie internetowe:\tWymagane"<<endl;
    output = stream_output.str();
    return output;
}
