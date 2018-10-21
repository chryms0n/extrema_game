#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP


class GameState
{
    public: 
        
        virtual void draw(const float dt) = 0;
        virtual void update(const float dt) = 0;
        virtual void handleInput() = 0;

};
#endif
