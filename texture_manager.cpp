#include "texture_manager.hpp"

using namespace Textures;

std::map<std::string, sf::Texture> Textures::texture_map = std::map<std::string, sf::Texture>();

void Textures::loadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture tex;
    tex.loadFromFile(filename);
    
    texture_map[name] = tex;
    
    return;
}

sf::Texture& getTextureRef(const std::string& texture)
{
    return texture_map.at(texture);
}
