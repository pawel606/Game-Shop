//
// Created by paweł on 6/10/2022.
//

#ifndef TESTOWANIE_CBUTTON_H
#define TESTOWANIE_CBUTTON_H

#include "C:\SFML\include\SFML\Graphics.hpp"

class cButton {
public:
    sf::Color color;
    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;


    cButton(float x , float y, float width, float height, std::string text,sf::Font *font,sf::Color color);
    ~cButton();
    void Render(sf::RenderTarget* target);
};



#endif //TESTOWANIE_CBUTTON_H
