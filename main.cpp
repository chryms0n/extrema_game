#include "main.hpp"


std::stack<GameState*> Game::states = std::stack<GameState*>();
sf::RenderWindow Game::window(sf::VideoMode(800, 600), "City Builder");

sf::Sprite Game::background;

sf::Clock Game::clock;

int main()
{
    Game::window.setFramerateLimit(60);

    Game::pushState(new GameStateStart());

    while (Game::window.isOpen())
    {
        // The main game loop
        sf::Time elapsed = Game::clock.restart();
        float dt = elapsed.asSeconds();

        //if (peekState() == nullptr) continue;
        Game::peekState()->handleInput();
        Game::peekState()->update(dt);
        
        sf::Event event;
        while (Game::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Game::window.close();
        }

        Game::window.clear();
        //window.draw(circle);
        Game::window.display();
    }

    while(!Game::states.empty()) Game::popState();

    return 0;
}

void Game::pushState(GameState* state)
{
    states.push(state);
}

void Game::popState()
{
    delete states.top();
    states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if (!states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if (states.empty()) return nullptr;
    return states.top();
}

void loadTextures()
{
    Textures::loadTexture("background","./media/background.png");

}


