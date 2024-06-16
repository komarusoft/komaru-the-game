#include "../include/SettingsMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow& window, sf::Font font, std::string pathToSettings)
        : window(window)
        , font(font)
        , settingsFilePath(pathToSettings) {

    this->resolutions = sf::VideoMode::getFullscreenModes();
}

uint SettingsMenu::getCurrentSelectedResolutionIndex() {
    return currentResolutionIndex;
}