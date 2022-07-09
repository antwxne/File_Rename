//
// Created by antoine on 7/9/22.
//

#ifndef CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_INPUTBOX_HPP
#define CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_INPUTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

namespace UI {
class InputBox {
public:
    InputBox(const std::string & desctiption,const sf::Color &color,
        const sf::Vector2f &size, const sf::Vector2f &pos
    );
    [[nodiscard]] bool onOver(const sf::Vector2i &mousePos) const;
    void setContent(const std::string &content);
    [[nodiscard]] const std::string &getContent() const;
    void draw(sf::RenderWindow &window) const;
private:
    std::unique_ptr<sf::Text> _contentText;
    std::unique_ptr<sf::Text> _descriptionText;
    std::unique_ptr<sf::Font> _font;
    std::unique_ptr<sf::RectangleShape> _rect;
    std::string _content;
};
}

#endif //CHANGER_LES_NOMS_DES_FICHIERS_PAR_DATE_INPUTBOX_HPP
