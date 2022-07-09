/*
** EPITECH PROJECT, 2024
** Project
** File description:
** Created by antoine,
*/

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::CircleShape circle(15);
    circle.setFillColor(sf::Color::Red);
    sf::Event event;
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}