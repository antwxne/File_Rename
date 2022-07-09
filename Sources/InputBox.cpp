//
// Created by antoine on 7/9/22.
//

#include "InputBox.hpp"
#include "Button.hpp"

UI::InputBox::InputBox(const std::string & desctiption, const sf::Color &color, const sf::Vector2f &size,
    const sf::Vector2f &pos
) : _rect(std::make_unique<sf::RectangleShape>(size)),
    _contentText(std::make_unique<sf::Text>()),
    _descriptionText(std::make_unique<sf::Text>()),
    _font(std::make_unique<sf::Font>())
{
    _rect->setFillColor(color);
    _rect->setOutlineColor(sf::Color::Black);
    _rect->setOutlineThickness(2);
    _rect->setPosition(pos);
    _font->loadFromFile(UI::FONT_PATH);

    _contentText->setFont(*_font);
    _contentText->setString("");
    _contentText->setFillColor(sf::Color::Black);
    _contentText->setPosition({pos.x + 10, pos.y + 5});

    _descriptionText->setFont(*_font);
    _descriptionText->setString(desctiption);
    _descriptionText->setFillColor(sf::Color::Black);
    _descriptionText->setPosition({pos.x, pos.y - 50});
}

bool UI::InputBox::onOver(const sf::Vector2i &mousePos) const
{
    const auto &color = _rect->getFillColor();

    if (_rect->getGlobalBounds().contains(static_cast<float>(mousePos.x),
        static_cast<float>(mousePos.y))) {
        _rect->setFillColor({color.r, color.g, color.b, 100});
        return true;
    } else {
        _rect->setFillColor({color.r, color.g, color.b, 255});
        return false;
    }
}

void UI::InputBox::setContent(const std::string &content)
{
    _contentText->setString(content);
    _content = content;
}

const std::string &UI::InputBox::getContent() const
{
    return _content;
}

void UI::InputBox::draw(sf::RenderWindow &window) const
{
    window.draw(*_rect);
    window.draw(*_contentText);
    window.draw(*_descriptionText);
}
