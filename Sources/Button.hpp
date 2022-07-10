//
// Created by antoine on 7/9/22.
//

#ifndef FILE_RENAME_BUTTON_HPP
#define FILE_RENAME_BUTTON_HPP

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <memory>
#include <string>
#include <filesystem>
#include <iostream>

namespace UI {

//const std::string FONT_PATH = std::string(REPO_SOURCE_DIR) + "/build/bin/BebasNeue-Regular.ttf";;
#if _WIN32
    const std::string FONT_PATH = std::filesystem::current_path().string() + "\\BebasNeue-Regular.ttf";
#else
    const std::string FONT_PATH = std::wstring(REPO_SOURCE_DIR) + "/Resources/BebasNeue-Regular.ttf";
#endif

class Button {
public:
    Button(const std::wstring &content, const sf::Color &color,
        const sf::Vector2f &size, const sf::Vector2f &pos
    );

    void draw(sf::RenderWindow &window);

    [[nodiscard]] bool onOver(const sf::Vector2i &mousePos) const;

private:
    std::unique_ptr<sf::Text> _contentText;
    std::unique_ptr<sf::Font> _font;
    std::unique_ptr<sf::RectangleShape> _rect;
};
} // namespace UI

#endif // FILE_RENAME_BUTTON_HPP
