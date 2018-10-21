// game state editor c++ source file

#include "./game_state.hpp"
#include "./game_state_editor.hpp"

GameStateEditor::GameStateEditor()
{
    sf::Vector2f pos = Game::window.getSize();
    this->gameView.setSize(pos);
    this.guiView.setSize(pos);
    pos *= 0.5f;
    this->gameView.setCenter(pos);
    this->guiView.setCenter(pos);
}

void GameStateEditor::draw(const float dt)
{
    Game::window.clear(sf::Color::Black);
    Game::window.draw(Game::background);
    
    return;
}

void GameStateEditor::update(const float dt)
{
    return;
}

void GameStateEditor::handleInput()
{
    sf::Event event;

    while(Game::pollEvent(event))
    {
        switch event.type()
        {
            case sf::Event::Closed:
            {
                Game::window.close(); break;
            }

            case sf::Event::Resized:
            {
                gameView.setSize(event.size.width, event.size.height);
                guiView.setSize(event.size.width, event.size.height);
                Game::background.setPosition(Game::window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
                Game::background.setScale(
                        event.size.width / float(Game::background.getTexture()->getSize().x),
                        event.size.height / float(Game::background.getTexture()->getSize().y));
                break;
            }

            default: break;
        

        }
    }
    return;
}
