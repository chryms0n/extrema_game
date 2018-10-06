#include "game_state.hpp"
#include "game_state_start.hpp"
#include "game_state_editor"
#include "main.hpp"

GameStateStart::GameStateStart()
{
    sf::Vector2f pos = sf::Vector2f(Game::window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}

void GameStateStart::draw(const float dt)
{
    Game::window.setView(this->view);

    Game::window.clear(sf::Color::Black);
    Game::window.draw(Game::background);

    return;
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput()
{
    sf::Event event;

    while(Game::window.pollEvent(event))
    {
        switch(event.type)
        {
            /*close the window */
            case sf::Event::Closed:
            {
                Game::window.close(); break;
            }

            /* Resize the window */
            case sf::Event::Resized:
            {
                view.setSize(event.size.width, event.size.height);
                Game::background.setPosition(Game::window.mapPixelToCoords(sf::Vector2i(0, 0)));
                Game::background.setScale(
                        float(event.size.width) 
                        / float(Game::background.getTexture()->getSize().x),
                        float(event.size.height) 
                        / float(Game::background.getTexture()->getSize().y));
                break;
            }

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) Game::window.close();
                break;
            }

            default: break;

            }
        }

    }
    return;
}
