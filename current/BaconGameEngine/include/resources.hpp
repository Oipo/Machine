#ifndef _RESOURCES_HPP_INCLUDED
#define _RESOURCES_HPP_INCLUDED

class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    uint8_t AddImage(const boost::filesystem::path&, const std::string&,
        uint16_t, uint16_t);
    sf::Image* GetImage(const std::string&);
private:
    typedef std::map<std::string, sf::Image*> image_map;
    image_map m_images;
};

#endif
