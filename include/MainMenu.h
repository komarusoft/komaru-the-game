#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

class MainMenu {
private:
    float menuCoordX;
    float menuCoordY;
    int rangeBetweenMenuItems;
    int fontSize;
    int maxMenuItemsCount;
    int currentSelectedMenuItem;

    sf::Font font;
    sf::Text* mainMenuItems;
    sf::Color menuTextColor = sf::Color::White;
    sf::Color hoverMenuTextColor = sf::Color::Yellow;
    sf::Color itemBorderColor = sf::Color::Green;

    // paralax props: #TODO: ПОМЕНЯТЬ ИМЕНА НА НОРМАЛЬНЫЕ, Я НЕ ПОНИМАЮ ЧТО ТАКОЕ 1 2 3 4 НИКИТКА, ДАВАЙ
    sf::Texture parallaxTexture1;
    sf::Texture parallaxTexture2;
    sf::Texture parallaxTexture3;
    sf::Texture parallaxTexture4;

    sf::Sprite parallaxSprite1;
    sf::Sprite parallaxSprite2;
    sf::Sprite parallaxSprite3;
    sf::Sprite parallaxSprite4;

    float parallaxOffset;
    sf::Clock clock;
    sf::Shader parallaxShader;

    void setInitItems(sf::Text& item, sf::String label, float posX, float posY);

    sf::RenderWindow& window;

public:
    MainMenu(sf::RenderWindow& window, float menuSizeX, float menuSizeY, int maxMenuItemsCount, sf::String* itemNames, int sizeFont = 60, int step = 80);
    ~MainMenu();

    void renderMenu();
    void moveUp();
    void moveDown();
    void setTextMenuColor(sf::Color menuTextColor, sf::Color onHoverMenuTextColor, sf::Color itemBorderColor);
    void alignMenuItems(int posX);
    int getCurrentSelectedMenuIndex();

    // parallax
    void loadParallaxTextures(const std::string& parallaxTexturePath1, const std::string& parallaxTexturePath2, const std::string& parallaxTexturePath3, const std::string& parallaxTexturePath4);
    void initializeParallax();
    void updateParallax();
};
#endif // !MAIN_MENU_H
