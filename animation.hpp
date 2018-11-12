#ifndef ANIMATION_HANDLER_HPP
#define ANIMATION_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration)
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }

    unsigned int getLength() { return endFrame - startFrame; }

};

namespace AnimationHandler
{
    extern std::vector<Animation> animations;

    /* Current time since the animation loop started */
    float t;

    int currentAnim;

    /* Add a new animation */
    void addAnim(Animation& anim);

    /* Update the current frame of the animation. 
     * 'dt' is time since the update was last called 
     * (i.e. the time for one frame to be executed) */
    void update(const float dt);

    /* Change the animation, resetting 't' in the process */
    void changeAnim(const unsigned int animNum);

    /* Current section of the texture that should be displayed */
    extern sf::IntRect bounds;

    /* Pixel dimension of each individual frame */
    extern sf::IntRect frameSize;
}

#endif
