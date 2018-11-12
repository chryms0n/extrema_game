#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

namespace Textures
{
    extern std::map<std::string, sf::Texture> texture_map;
    
    void loadTexture(const std::string& name, const std::string& filename);

    sf::Texture& getTextureRef(const std::string& texture);
}


#endif
