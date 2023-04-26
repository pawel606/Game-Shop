//
// Created by paweł on 6/10/2022.
//

#include "../Include/cButton.h"

cButton::cButton(float x, float y, float width, float height, std::string text, sf::Font* font,sf::Color color)
{

    this->shape.setPosition(x,y);
    this->shape.setSize(sf::Vector2f(width,height));
    this->shape.setFillColor(color);
    this->font = font;
    this->shape.setOutlineThickness(2.f);
    this->shape.setOutlineColor(sf::Color::Black);

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(30);

    this->text.setPosition(
            this->shape.getPosition()
    );
}

cButton::~cButton()
{

}

void cButton::Render(sf::RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->text);
}
