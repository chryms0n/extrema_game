// main.hpp
#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <stack>

#include "./game_state.hpp"
#include "./game_state_start.hpp"
#include "./game_state_editor.hpp"
#include "./texture_manager.hpp"

namespace Game
{
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void loadTextures();

    extern std::stack<GameState*> states;
    extern sf::RenderWindow window;
    extern sf::Clock clock;

    extern sf::Sprite background;
}

#endif
