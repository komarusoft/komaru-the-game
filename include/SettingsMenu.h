#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include <vector>

class SettingsMenu {
private:
    sf::RenderWindow& window;
    std::string settingsFilePath;
    sf::Font font;
    sf::Color menuTextColor = sf::Color::White;
    sf::Color hoverMenuTextColor = sf::Color::Yellow;
    sf::Color itemBorderColor = sf::Color::Green;

    std::vector<sf::VideoMode> resolutions;
    uint currentResolutionIndex;
    uint maxResolutionsCount;
    float volume;

public:
    SettingsMenu(sf::RenderWindow& window, sf::Font font, std::string pathToSettings);
    sf::VideoMode getResolutionFromSettings();
    float getVolumeFromSettings();
    void saveSettings();
    void applySettings();
    void selectNextResolution();
    void selectPrevResolution();
    uint getCurrentSelectedResolutionIndex();
};
#endif // SETTINGSMENU_H