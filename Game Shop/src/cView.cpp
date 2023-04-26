//
// Created by paweł on 6/8/2022.
//

#include "../Include/cView.h"
#include "../Include/cController.h"

#include <iostream>


cView::cView(cController* controller)
{
    mController = controller;
    start();
}
cView::~cView()
{

}

int cView::start()
{
    window.create(sf::VideoMode(600, 600), "Wyporzyczalnia gier");
    window.setActive();
    if (!mTloTexture.loadFromFile("tlo.png"))
        return EXIT_FAILURE;

    if (!mCzcionkaFont.loadFromFile("Inkfree.ttf"))
        return EXIT_FAILURE;

    mLicznikText.setCharacterSize(30);
    mLicznikText.setFont(mCzcionkaFont);
    mLicznikText.setFillColor(sf::Color::Black);

    mkoszyk->shape.setTexture(&mTloTexture);

        createButtons();
    mTloSprite.setTexture(mTloTexture);
    Update();
    return (0);
}

int cView::isOpen()
{
    return window.isOpen();
}

void cView::Update()
{
    window.clear(sf::Color(0,0,0));
    window.draw(mTloSprite);
    showButtons();
    mkoszyk->Render(&window);
    window.display();
}
int cView::checkEvents() {
    if (window.pollEvent(mEvent)) {
        if (mEvent.type == sf::Event::Closed)
            window.close();
        if (mEvent.type == sf::Event::MouseButtonPressed) {
            if (mEvent.mouseButton.button == sf::Mouse::Left) {
                switch(page) {
                    case 1:
                        if (checkIfHoveringOver(buttons[0], mEvent.mouseButton.x, mEvent.mouseButton.y)) {
                        showPage2(0);
                        game = 0;
                        page++;
                        }
                        if (checkIfHoveringOver(buttons[1], mEvent.mouseButton.x, mEvent.mouseButton.y)) {
                        showPage2(1);
                            game = 1;
                        page++;
                        }
                        if (checkIfHoveringOver(buttons[2], mEvent.mouseButton.x, mEvent.mouseButton.y)) {
                        showPage2(2);
                            game = 2;
                        page++;
                        }
                        if (checkIfHoveringOver(buttons[3], mEvent.mouseButton.x, mEvent.mouseButton.y)) {
                        showPage2(3);
                            game = 3;
                        page++;
                        }
                        if (checkIfHoveringOver(buttons[4], mEvent.mouseButton.x, mEvent.mouseButton.y)) {
                            showPage2(4);
                            game = 4;
                          page++;
                        }
                        if(checkIfHoveringOver(mkoszyk,mEvent.mouseButton.x,mEvent.mouseButton.y))
                        {
                            page = 4;
                            showCart();
                        }
                        break;
                    case 2:
                        if(checkIfHoveringOver(mWyporzycz,mEvent.mouseButton.x,mEvent.mouseButton.y))
                        {
                            std::cout<<"Wyporzyczono"<<std::endl;
                            mController->Borrow(game);
                            mController->AddCart(game);
                            showPage3(game);
                            page = 3;
                        }
                        if(checkIfHoveringOver(mPowrot,mEvent.mouseButton.x,mEvent.mouseButton.y))
                        {
                            page = 1;
                            Update();
                        }
                        break;
                    case 3:
                        if(checkIfHoveringOver(mPowrot,mEvent.mouseButton.x,mEvent.mouseButton.y))
                        {
                            page = 1;
                            Update();
                        }
                        break;
                    case 4:
                        if(checkIfHoveringOver(mPowrot,mEvent.mouseButton.x,mEvent.mouseButton.y))
                        {
                            page = 1;
                            Update();
                        }
                        break;
                    }
                }
            }
        }
    return 0;
}
bool cView::checkIfHoveringOver(cButton *przycisk, int aX, int aY) {
    sf::Vector2f position = przycisk->shape.getPosition();
    // sprawdzamy czy kliknieto w przycisk
    if (aX > position.x && aX < (position.x + 250) && aY > position.y && aY < (position.y + 40)) {
        return 1;
    } else {
        return 0;
    }
}

void cView::createButtons()
{
    float y=0;

    for(int i=0;i<5;i++)
    {
        buttons.push_back(new cButton(20, 100+y, 350, 40, mController->ShowTitle(i), &mCzcionkaFont,sf::Color(200,255,255)));
        y = y+40;
        }
}
void cView::showButtons()
{
    for(int i=0;i<5;i++)
    {
        buttons[i]->Render(&window);
    }
}
void cView::showPage2(int a)
{
    window.clear(sf::Color(0, 0, 0));
    window.draw(mTloSprite);
    mLicznikText.setPosition(20, 60);
    mLicznikText.setString(mController->ShowInfo(a));
    window.draw(mLicznikText);

    mWyporzycz->Render(&window);
    mPowrot->Render(&window);
    window.display();
}

void cView::showPage3(int a)
{
    window.clear(sf::Color(0, 0, 0));
    window.draw(mTloSprite);
    mLicznikText.setPosition(20, 60);
    mLicznikText.setString(mController->ShowInfo(a));
    window.draw(mLicznikText);

    mWyporzyczono->Render(&window);
    mPowrot->Render(&window);
    window.display();
}
void cView::showCart()
{
    window.clear(sf::Color(0, 0, 0));
    window.draw(mTloSprite);
    mLicznikText.setPosition(20, 60);
    mLicznikText.setString(mController->ShowCart());
    window.draw(mLicznikText);
    mPowrot->Render(&window);
    auto *mKoniec = new cButton(150, 400, 250, 40,mController->ShowCartvalue() + " zl", &mCzcionkaFont,sf::Color::Green);
    mKoniec->Render(&window);
    window.display();
    delete mKoniec;
}
