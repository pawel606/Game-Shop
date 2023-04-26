//
// Created by paweł on 5/28/2022.
//
#include "../Include/cBase.h"
#include "../Include/cMulti.h"
#include "../Include/cSingle.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;
cBaza::cBaza(cController * controller)
{
    mControler = controller;
    mCartValue =0;
    string line;
    int line_number=1;
    string gameType; // sprawdzenie czy gra jest multiplayer czy singleplayer - 1 linia

    int GameSize; //2linia
    string Title; //3linia
    string Platform; // 4linia
    string Genre; // 5linia
    bool Availability; // 6 linia
    double Price; // 7 linia
    int extra; // 8 linia

    fstream file;
    file.open("baza.txt",ios::in);
    if(file.good()){
        while (getline(file,line))
        {
            switch (line_number) {
                case 1:
                    gameType = line;
                    break;
                case 2:
                    GameSize = atoi(line.c_str());
                    break;
                case 3:
                    Title = line;
                    break;
                case 4:
                    Platform = line;
                    break;
                case 5:
                    Genre = line;
                    break;
                case 6:
                    Price = atoi(line.c_str());
                    break;
                case 7:
                    Availability = atoi(line.c_str());
                    break;
                case 8:
                    extra = atoi(line.c_str());
                    break;
            }
            if(line_number == 8)
            {
                if(gameType == "M"){
                    cout<<"Gra multi" <<endl;
                    auto *multi = new cMulti (GameSize,Title,Platform,Genre,Price,Availability,extra);
                    //cout<< multi->Show()<<endl;
                    cBaza::Addgame(multi);
                }
                else if (gameType == "S")
                {
                    cout<<"Gra single"<<endl;
                    auto *single = new cSingle(GameSize,Title,Platform,Genre,Price,Availability,extra);
                    cBaza::Addgame(single);
                }
                line_number=0;
            }
            line_number++;
        }
    }
    else cout<<"Blad odwarcia pliku";
    file.close();

}

void cBaza::Addgame(cGame *game)
{
    //cout<<"dodano nowa gre"<<endl;
    mbaza.push_back(game);
}
std::string cBaza::ShowBase()
{
    string tmp;
    for(cGame * g : mbaza)
    {
        tmp = tmp + g->getTitle() + "\n";
    }
    return tmp;
}
cBaza::~cBaza()
{
    for(cGame * g : mbaza)
    {
        delete g;
    }
}

void cBaza::BorrowGame(int index)
{
    mbaza[index]->setAvailability(false);
}

void cBaza::operator+(cGame *g)
{
    Addgame(g);
}

std::string cBaza::showTitle(int a)
{
    return mbaza[a] ->getTitle();
}
std::string cBaza::showInfo(int a)
{
    return mbaza[a] ->Show();
}
double cBaza::gamePrice(int a)
{
    return mbaza[a] -> getPrice();
}

void cBaza::AddtoCart(int a) {
    mkoszyk.push_back(a);
}

std::string cBaza::ShowCart() {
    mCartValue=0;
    string tmp;
    stringstream stream;
    for(int & i : mkoszyk)
    {
        stream << showTitle(i) <<"\t"<< gamePrice(i) <<"zl"<< std::endl;
        mCartValue += gamePrice(i);
    }
    tmp = stream.str();
    return tmp;
}

double cBaza::getCartValue() const {
    return mCartValue;
}

std::ostream & operator << (std::ostream &aWyjscie, const cBaza *baza)
{
    string str;
    for(cGame * g : baza->mbaza)
    {
        str = str + g->Show() + "\n";
    }
    return aWyjscie << str;
}
