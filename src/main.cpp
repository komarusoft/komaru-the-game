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
    // Background #TODO: change to paralax
    RectangleShape background(Vector2f(width, height));
    Texture texture_window;
    if (!texture_window.loadFromFile("res/main_menu_res/4.png"))
        return 4;
    background.setTexture(&texture_window);

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
    mainmenu.alignMenuItems(2);

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

        window.clear();
        window.draw(background);
        window.draw(h1);
        mainmenu.drawMenu();
        window.display();
    }

    return 0;

#pragma region paralax
    // RenderWindow window(VideoMode(800, 600), "Parallax Example",
    //     Style::Titlebar | Style::Close);

    // /*
    //  RenderWindow window(VideoMode(800, 600), "Parallax Example",
    //                          Style::Titlebar | Style::Close | Style::Fullscreen);
    // */
    // window.setVerticalSyncEnabled(true);

    // Texture texture1, texture2, texture3, texture4;
    // if (!texture1.loadFromFile("../res/main_menu_res/1.png") || !texture2.loadFromFile("../res/main_menu_res/2.png") || !texture3.loadFromFile("../res/main_menu_res/3.png") || !texture4.loadFromFile("../res/main_menu_res/4.png")) {
    //     // Обработка ошибок загрузки
    //     return EXIT_FAILURE;
    // }

    // texture1.setRepeated(true);
    // texture2.setRepeated(true);
    // texture3.setRepeated(true);
    // texture4.setRepeated(true);

    // Sprite sprite1(texture1), sprite2(texture2), sprite3(texture3), sprite4(texture4);
    // sprite1.setScale(float(window.getSize().x) / texture1.getSize().x, float(window.getSize().y) / texture1.getSize().y);
    // sprite2.setScale(float(window.getSize().x) / texture2.getSize().x, float(window.getSize().y) / texture2.getSize().y);
    // sprite3.setScale(float(window.getSize().x) / texture3.getSize().x, float(window.getSize().y) / texture3.getSize().y);
    // sprite4.setScale(float(window.getSize().x) / texture4.getSize().x, float(window.getSize().y) / texture4.getSize().y);

    // Shader parallaxShader;
    // parallaxShader.loadFromMemory(
    //     "uniform float offset;"

    //     "void main() {"
    //     "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
    //     "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
    //     "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
    //     "    gl_FrontColor = gl_Color;"
    //     "}",
    //     Shader::Vertex);

    // float offset = 0.f;

    // Clock clock;
    // while (window.isOpen()) {
    //     Event event;
    //     while (window.pollEvent(event)) {
    //         switch (event.type) {
    //             case Event::Closed:
    //                 window.close();
    //                 break;
    //         }
    //     }

    //     parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 10);

    //     window.clear();

    //     // Отрисовка спрайтов в порядке от дальнего к ближнему:
    //     window.draw(sprite4, &parallaxShader);
    //     window.draw(sprite3, &parallaxShader);
    //     window.draw(sprite2, &parallaxShader);
    //     window.draw(sprite1, &parallaxShader);

    //     window.display();
    // }

    // return EXIT_SUCCESS;
#pragma endregion
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