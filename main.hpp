// main.hpp
//
namespace Game
{
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    std::stack<GameState*>states;
    sf::RenderWindow window;
}
