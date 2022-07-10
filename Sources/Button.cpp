//
// Created by antoine on 7/9/22.
//

#include <iostream>

#include "Button.hpp"

UI::Button::Button(const std::wstring &content, const sf::Color &color,
    const sf::Vector2f &size, const sf::Vector2f &pos
) : _rect(std::make_unique<sf::RectangleShape>(size)),
    _font(std::make_unique<sf::Font>()),
    _contentText(std::make_unique<sf::Text>())
{
    _rect->setFillColor(color);
    _rect->setPosition(pos);
    _font->loadFromFile(UI::FONT_PATH);
    _contentText->setFont(*_font);
    _contentText->setString(content);
    _contentText->setFillColor(sf::Color::White);
    _contentText->setPosition({pos.x + 10, pos.y + 5});
}

void UI::Button::draw(sf::RenderWindow &window)
{
    window.draw(*_rect);
    window.draw(*_contentText);
}

bool UI::Button::onOver(const sf::Vector2i &mousePos) const
{
    auto &color = _rect->getFillColor();

    if (_rect->getGlobalBounds().contains(static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y))) {
        _rect->setFillColor({color.r, color.g, color.b, 100});
        return true;
    } else {
        _rect->setFillColor({color.r, color.g, color.b, 255});
        return false;
    }
}
