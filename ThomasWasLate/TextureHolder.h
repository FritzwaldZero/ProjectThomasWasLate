#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map> //  part of the standard template library 

class TextureHolder
{
private:
//map contianer that holds a related pair of string and texture 
	std::map<std::string, sf::Texture> m_Textures;
	
	// pointer of the same type as the class itself
	static TextureHolder* m_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif TEXTURE_HOLDER_H
