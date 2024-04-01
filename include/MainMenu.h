#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>
// #include <SFML/System/Clock.hpp>
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

    float parallaxSpeed1;
    float parallaxSpeed2;
    float parallaxSpeed3;
    float parallaxSpeed4;
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

    // paralax
    void loadParalaxTextures(const std::string& paralaxTexturePath1, const std::string& paralaxTexturePath2, const std::string& paralaxTexturePath3, const std::string& paralaxTexturePath4);
    void setParalaxSpeeds(float paralaxSpeed1, float paralaxSpeed2, float paralaxSpeed3);
    void initializeParalax();
    void updateParalax();
};
#endif // !MAIN_MENU_H
