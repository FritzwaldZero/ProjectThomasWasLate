#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_Instance == nullptr); // error managment 
	m_Instance = this; //make sure there one of them and is loaded from memory 
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	// Get a reference to the m_textures map 
	auto& m = m_Instance->m_Textures;

	//create an iterator to hold a key pair 
	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
		// file not found
		// create a new value pair using the filename 
		auto& texture = m[filename];
		texture.loadFromFile(filename);

		return texture;
	}

	
}

