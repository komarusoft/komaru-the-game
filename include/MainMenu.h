#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <SFML/Graphics.hpp>

class MainMenu {
private:
    float menuCoordX;
    float menuCoordY;
    int rangeBetweenMenuItems;
    int maxMenuItemsCount;
    int fontSize;
    int currentSelectedMenuItem;

    sf::Font font;
    sf::Text* mainMenuItems;
    sf::Color menuTextColor = sf::Color::White;
    sf::Color hoverMenuTextColor = sf::Color::Yellow;
    sf::Color itemBorderColor = sf::Color::Green;

    void setInitItems(sf::Text& item, sf::String label, float posX, float posY);

    sf::RenderWindow& window;

public:
    MainMenu(sf::RenderWindow& window, float menuSizeX, float menuSizeY, int maxMenuItemsCount, sf::String* itemNames, int sizeFont = 60, int step = 80);
    ~MainMenu();

    void drawMenu();
    void moveUp();
    void moveDown();
    void setTextMenuColor(sf::Color menuTextColor, sf::Color onHoverMenuTextColor, sf::Color itemBorderColor);
    void alignMenuItems(int posX);
    void getCurrentSelectedMenuIndex();
};

#endif // !MAIN_MENU_H
