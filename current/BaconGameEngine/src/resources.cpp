#include <string>
#include <map>
#include <iostream>
#include <cassert>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <ImageMagick/Magick++.h>
#include <boost/filesystem.hpp>

#include "resources.hpp"

ResourceManager::ResourceManager() {};
ResourceManager::~ResourceManager() {};

uint8_t ResourceManager::AddImage(	
	boost::filesystem::path const& path, 
	std::string const& imgname,
	uint16_t width, 
	uint16_t height) 
{
	if (m_images.end() != m_images.find(imgname))
		return 0;
	
	try {
		// TODO: Put all the converting stuff into another function
		Magick::Image mimage;
		std::cout << "Caching image ";
		mimage.read((path / imgname).string());
		std::cout << path / imgname << std::endl;
		// TODO: Check this doesn't already exist in another function
		boost::filesystem::create_directory((path / "cached").string());
		
		mimage.sample(Magick::Geometry(width, height));
		mimage.depth(8);
		std::string output = (path/"cached"/imgname).string() + ".png";

		mimage.write(output);

		sf::Image* sfimage = new sf::Image;
		sfimage->LoadFromFile(output);
		m_images[imgname] = sfimage;
		return 0;
	}
	catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return 1;
	}
}

sf::Image* ResourceManager::GetImage(const std::string& img) {
	image_map::const_iterator it = m_images.find(img);
	assert( (it != m_images.end()) && "Not in the map!" );
	return it->second;
};
