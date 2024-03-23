#include "../include/MainMenu.h"

void MainMenu::setInitItems(sf::Text& item, sf::String label, float posX, float posY) {
    item.setFont(font);
    item.setFillColor(menuTextColor);
    item.setString(label);
    item.setCharacterSize(fontSize);
    item.setPosition(posX, posY);
    item.setOutlineThickness(3);
    item.setOutlineColor(itemBorderColor);
}

/*TODO: додати опис можливых параметрів
 *	0 - по правому краю
 * 	1 - по лівому краю
 *	2 - по центру
 */
void MainMenu::alignMenuItems(int posX) {
    float nullx = 0;
    for (uint8_t i = 0; i < maxMenuItemCount; i++) {
        switch (posX) {
            case 0:
                nullx = 0;
                break;
            case 1:
                nullx = mainMenuItems[i].getLocalBounds().width;
                break;
            case 2:
                nullx = mainMenuItems[i].getLocalBounds().width / 2;
                break;

                mainMenuItems[i].setPosition(mainMenuItems[i].getPosition().x - nullx,
                    mainMenuItems[i].getPosition().y);
        }
    }
}

MainMenu::MainMenu(sf::RenderWindow& window, float menuSizeX, float menuSizeY,
    int maxMenuItemsCount, sf::String* itemsName, int sizeFont, int step)
        : window(window) {
}

MainMenu::~MainMenu() {
    delete[] mainMenuItems;
}