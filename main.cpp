
#include <stack>
#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "main.h"

using namespace Game;

int main()
{
    window(sf::VideoMode(800, 600), "City Builder");
    window.setFramerateLimit(60);
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);

    sf::Clock clock;

    while (window.isOpen())
    {
        // The main game loop
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    while(!states.empty()) popState();

    return 0;
}

void pushState(GameState* state)
{
    states.push(state);
}

void popState()
{
    delete states.top();
    states.pop();

    return;
}

void changeState(GameState* state)
{
    if (!states.empty())
        popState();
    pushState(state);

    return;
}

GameState* peekState()
{
    if (states.empty()) return nullptr;
    return states.top();
}
