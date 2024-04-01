#include "../include/MainMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

int main() {
    RenderWindow window;
    window.create(VideoMode(1920, 1080), "Komaru the game");

    window.setMouseCursorVisible(true);

    float width = VideoMode::getDesktopMode().width;
    float height = VideoMode::getDesktopMode().height;

#pragma region main menu setting up
    RectangleShape background(Vector2f(width, height));

    Font font;
    if (!font.loadFromFile("res/fonts/slkscr.ttf"))
        return 5;
    Text h1;
    h1.setFont(font);

    InitText(h1, width / 2 - 100, 50, "Komaru the game", 60, Color(237, 147, 0), 3);

    String name_menu[]{"Start", "Settings", "About", "Exit"};
    // TODO: add support for another resolution
    MainMenu mainmenu(window, width / 2 - 100, height / 2, 4, name_menu, 100, 120);
    mainmenu.setTextMenuColor(Color(237, 147, 0), Color::Red, Color::Black);

    mainmenu.loadParallaxTextures("res/main_menu_res/1.png", "res/main_menu_res/2.png", "res/main_menu_res/3.png", "res/main_menu_res/4.png");
    mainmenu.setParalaxSpeeds(0.1f, 0.5f, 1.0f);
    mainmenu.initializeParallax();

    mainmenu.alignMenuItems(2);

    float offset = 0.f;

    Clock clock;
#pragma endregion
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    mainmenu.moveUp();
                }
                if (event.key.code == Keyboard::Down) {
                    mainmenu.moveDown();
                }
                if (event.key.code == Keyboard::Return) {
                    std::cout << "u press enter" << std::endl;
                    // Переходим на выбранный пункт меню
                    switch (mainmenu.getCurrentSelectedMenuIndex()) {
                        case 0:
                            std::cout << "u clicked start" << std::endl;
                            // GamеStart();
                            break;
                        case 1:
                            std::cout << "u clicked settings" << std::endl;
                            // Options();
                            break;
                        case 2:
                            std::cout << "u clicked about" << std::endl;

                            // About_Game();
                            break;
                        case 3:
                            window.close();
                            break;
                    }
                }
            }
        }

        mainmenu.updateParallax();
        window.clear();
        mainmenu.renderMenu();
        window.display();
    }

    return 0;
}

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font,
    Color menu_text_color, int bord, Color border_color) {
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(border_color);
}