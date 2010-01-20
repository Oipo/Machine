#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <map>

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    uint8_t AddImage(const Filesystem::path&, const std::string&,
        const uint16_t&, const uint16_t&);
    sf::Image* GetImage(const std::string&);
private:
    std::map<std::string, sf::Image> m_images;
};

#endif