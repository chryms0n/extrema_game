// main.hpp

#include <stack>
#include <SFML/Graphics.hpp>

#include "game_state.hpp"

namespace Game
{
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    extern std::stack<GameState*>states;
    extern sf::RenderWindow window;
    extern sf::Clock clock;
}

