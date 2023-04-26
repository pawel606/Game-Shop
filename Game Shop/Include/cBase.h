//
// Created by paweł on 5/28/2022.
//

#ifndef TESTOWANIE_CBASE_H
#define TESTOWANIE_CBASE_H

#include "cGame.h"
#include <vector>

class cController;

class cBaza {
    std::vector <cGame *> mbaza;
    cController * mControler;
    std::vector<int> mkoszyk;
    double mCartValue;



public:
    cBaza(cController *);
    ~cBaza();
    void Addgame(cGame * g);
    std::string showTitle(int a); //pokazanie tutułu
    std::string showInfo(int a); //pokazanie wszystkich informacji o grze
    std::string ShowBase();  //pokazanie wszystkich gier(tytułów)
    double gamePrice(int a); //wczytanie ceny gry


    void BorrowGame(int index); //wyporzyczenie gry(zmiana mavailability na false)
    void operator + (cGame *g);

    void AddtoCart(int a); //dodanie gry do koszyka (index)
    std::string ShowCart(); // pokazanie koszyka (tytułu oraz ceny)
    double getCartValue() const; //pobranie ceny całego koszyka

    friend std::ostream & operator<< (std::ostream &aWyjscie, const cBaza *aBaza);
};


#endif //TESTOWANIE_CBASE_H
