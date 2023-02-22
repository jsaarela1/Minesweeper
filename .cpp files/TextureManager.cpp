#include "TextureManager.h"

// "redeclare" the variable, so this file knows it exists and can use
unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string filename)
{
	string path = "images/";
	path += filename + ".png";

	textures[filename].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName)
{
	if (textures.find(textureName) == textures.end()) // we didn't find it
		LoadTexture(textureName);

	return textures[textureName];
}

void TextureManager::Clear()
{
	textures.clear();	// get rid of all stored objects
}
