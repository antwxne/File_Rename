/*
** EPITECH PROJECT, 2024
** Project
** File description:
** Created by antoine,
*/

#include <SFML/Graphics.hpp>

#include <iostream>
#include <filesystem>

#include "Button.hpp"
#include "InputBox.hpp"
#include "RenameClass.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 300),
        "Changer les noms des fichiers");
    UI::Button validateButton("Valider", sf::Color::Green, {100, 50},
        {450, 200});
    UI::Button cancelButton("Annuler", sf::Color::Red, {100, 50}, {250, 200});
    UI::InputBox inputBox("Chemin jusqu'au dossier:", {220, 220, 220, 255},
        {500, 50}, {150, 100});
    sf::Text statusText;
    sf::Font statusTextFont;
    sf::Event event;
    bool evenyHasBeenProcess = false;
    sf::Vector2i mousePos;
    statusTextFont.loadFromFile(UI::FONT_PATH);
    statusText.setFont(statusTextFont);
    statusText.setString("");
    statusText.setPosition(300, 0);

    window.setFramerateLimit(10);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            mousePos = sf::Mouse::getPosition(window);
            if (inputBox.onOver(mousePos) && event.key.control &&
                event.key.code == sf::Keyboard::V) {
                inputBox.setContent(sf::Clipboard::getString());
            }
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (validateButton.onOver(mousePos) &&
                event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left &&
                !inputBox.getContent().empty()) {
                std::cout << "Content == " << inputBox.getContent()
                    << std::endl;
                try {
                    RenameClass::renameFilesByDate(inputBox.getContent());
                    statusText.setFillColor(sf::Color::Green);
                    statusText.setString("Fini");
                } catch (const std::filesystem::filesystem_error &e) {
                    statusText.setFillColor(sf::Color::Red);
                    statusText.setString(
                        inputBox.getContent() + ": Pas de dossier");
                }
            }
            if (cancelButton.onOver(mousePos) &&
                event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left) {
                inputBox.setContent("");
            }
        }
        window.clear(sf::Color::White);
        validateButton.draw(window);
        cancelButton.draw(window);
        inputBox.draw(window);
        window.draw(statusText);
        window.display();
    }
    return 0;
}