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
    for (uint8_t i = 0; i < maxMenuItemsCount; i++) {
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

MainMenu::MainMenu(sf::RenderWindow& window, float menux, float menuy,
    int maxMenuItemsCount, sf::String* itemsName, int sizeFont, int step)
        : window(window)
        , menuCoordX(menux)
        , menuCoordY(menuy)
        , fontSize(sizeFont)
        , rangeBetweenMenuItems(step)
        , maxMenuItemsCount(maxMenuItemsCount) {

    if (!font.loadFromFile("res/fonts/slkscr.ttf"))
        exit(1);

    mainMenuItems = new sf::Text[maxMenuItemsCount];
    for (int i = 0, ypos = menuCoordY; i < maxMenuItemsCount; i++, ypos += rangeBetweenMenuItems)
        setInitItems(mainMenuItems[i], itemsName[i], menuCoordX, ypos);

    currentSelectedMenuItem = 0;
    mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
}

MainMenu::~MainMenu() {
    delete[] mainMenuItems;
}

void MainMenu::moveUp() {
    currentSelectedMenuItem--;

    if (currentSelectedMenuItem >= 0) {
        mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
        mainMenuItems[currentSelectedMenuItem + 1].setFillColor(menuTextColor);
    } else {
        mainMenuItems[0].setFillColor(menuTextColor);
        currentSelectedMenuItem = maxMenuItemsCount - 1;
        mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
    }
}

void MainMenu::moveDown() {
    currentSelectedMenuItem++;

    if (currentSelectedMenuItem < maxMenuItemsCount) {
        mainMenuItems[currentSelectedMenuItem - 1].setFillColor(menuTextColor);
        mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
    } else {
        mainMenuItems[maxMenuItemsCount - 1].setFillColor(menuTextColor);
        currentSelectedMenuItem = 0;
        mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
    }
}

void MainMenu::drawMenu() {
    for (int i = 0; i < maxMenuItemsCount; i++)
        window.draw(mainMenuItems[i]);
}

void MainMenu::setTextMenuColor(sf::Color menuTextColor, sf::Color onHoverMenuTextColor, sf::Color itemBorderColor) {
    this->menuTextColor = menuTextColor;
    this->hoverMenuTextColor = onHoverMenuTextColor;
    this->itemBorderColor = itemBorderColor;

    for (int i = 0; i < maxMenuItemsCount; i++) {
        mainMenuItems[i].setFillColor(menuTextColor);
        mainMenuItems[i].setOutlineColor(itemBorderColor);
    }

    mainMenuItems[currentSelectedMenuItem].setFillColor(hoverMenuTextColor);
}

int MainMenu::getCurrentSelectedMenuIndex() {
    return currentSelectedMenuItem;
}
