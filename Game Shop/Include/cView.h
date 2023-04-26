//
// Created by paweł on 6/8/2022.
//

#ifndef TESTOWANIE_CVIEW_H
#define TESTOWANIE_CVIEW_H

#include <C:\SFML\include\SFML\Graphics.hpp>
#include "../Include/cButton.h"


class cController;

class cView {
    cController * mController;
    int start();
    static bool checkIfHoveringOver(cButton *przycisk, int aX, int aY);
    int page = 1;
    int game;


public:
    cView(cController *);
    ~cView();

    int isOpen();
    void Update();
    int checkEvents();

    std::vector<cButton*> buttons;
    void createButtons();
    void showButtons();


    sf::RenderWindow window;
    sf::Event mEvent;
    sf::Sprite mTloSprite;
    sf::Texture mTloTexture;
    sf::Font mCzcionkaFont;
    sf::Text mLicznikText;
    cButton *mPowrot = new cButton(0, 560, 250, 40,"Powrot do menu", &mCzcionkaFont,sf::Color::White);
    cButton *mWyporzycz = new cButton(150, 400, 250, 40,"Wyporzycz gre ", &mCzcionkaFont,sf::Color::Green);
    cButton *mWyporzyczono = new cButton(75, 400, 450, 40,"Gra zostala dodana do koszyka", &mCzcionkaFont,sf::Color::Green);
    cButton *mkoszyk = new cButton(500, 560, 100, 40,"Koszyk", &mCzcionkaFont,sf::Color(100,255,100));

    void showPage2(int a);
    void showPage3(int a);
    void showCart();

};


#endif //TESTOWANIE_CVIEW_H
