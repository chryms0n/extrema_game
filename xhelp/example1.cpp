#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <stdio.h>

class customRect
{
    private:
        sf::RectangleShape m_shape;
        sf::Vector2f m_velocity;
    public:
        sf::Rect<float> getRect() const;
        sf::RectangleShape getRectShape();
        sf::Vector2f getPosition();
        sf::Vector2f getSize();
        void setVelocity(const sf::Vector2f& speed);
        sf::Vector2f getVelocity();
        void move(const sf::Vector2f& offset);
        customRect getIntersection(const customRect& rect);

        customRect(const sf::Vector2f& position, const sf::Vector2f& size=sf::Vector2f(40.0f, 40.0f));
};

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(60);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    // Create a graphical text to display
    //sf::Font font;
    //if (!font.loadFromFile("arial.ttf"))
    //    return EXIT_FAILURE;
    //sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    //sf::Music music;
    //if (!music.openFromFile("nice_music.ogg"))
    //    return EXIT_FAILURE;
    // Play the music
    //music.play();
    
    customRect rectShape1(sf::Vector2f(150.0f, 50.0f));
    customRect rectShape2(sf::Vector2f(450.0f, 50.0f));



    sf::Clock clock;
    clock.restart();

    const sf::Vector2f& spritePosition = sprite.getPosition();
    std::printf("Sprite position: (%f, %f)\n", spritePosition.x, spritePosition.y);

    float spriteSpeed = 0.04f;

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed || spritePosition.y >= 400.0f)
            {
                std::printf("closing window: %d, %d\n", event.type == sf::Event::Closed, spritePosition.y >= 400.0f);
                window.close();
                std::printf("final sprite position: (%f, %f)\n", spritePosition.x, spritePosition.y);
                return EXIT_SUCCESS;
            }

        }

        sprite.move(0, 1.0f * spriteSpeed * clock.getElapsedTime().asMilliseconds() );

        rectShape1.move(sf::Vector2f(1.0f, 1.0f)); 
        clock.restart();

        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        //window.draw(text);
        // Update the window
        window.display();
    }    
    return EXIT_SUCCESS;
} 

sf::Rect<float> customRect::getRect() const
{
    return sf::Rect<float>(this->m_shape.getPosition(), this->m_shape.getSize());
}

sf::Vector2f customRect::getPosition()
{
    return this->m_shape.getPosition();
}

sf::RectangleShape customRect::getRectShape()
{
    return this->m_shape;
}

sf::Vector2f customRect::getSize()
{
    return this->m_shape.getSize();
}

sf::Vector2f customRect::getVelocity()
{
    return this->m_velocity;
}

void customRect::move(const sf::Vector2f& offset)
{
    this->m_shape.setPosition(this->m_shape.getPosition() + offset);
    
}

void customRect::setVelocity(const sf::Vector2f& speed)
{
    this->m_velocity = speed;
}

customRect customRect::getIntersection(const customRect& rect) 
{
    sf::Rect<float> otherRect = rect.getRect();
    sf::Rect<float> intersectionRect;
    this->getRect().intersects(otherRect, intersectionRect);
    return customRect(   sf::Vector2f(intersectionRect.left, intersectionRect.top),
                         sf::Vector2f(intersectionRect.width, intersectionRect.height)   );
}

customRect::customRect(const sf::Vector2f& position, const sf::Vector2f& size)
{
    this->m_shape = sf::RectangleShape(size);
    this->m_shape.setPosition(position);

    this->m_velocity = sf::Vector2f();
}
