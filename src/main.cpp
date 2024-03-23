#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Parallax Example",
                            Style::Titlebar | Style::Close);

   /*
    RenderWindow window(VideoMode(800, 600), "Parallax Example",
                            Style::Titlebar | Style::Close | Style::Fullscreen);    
   */                        
    window.setVerticalSyncEnabled(true);

    Texture texture1, texture2, texture3, texture4;
    if (!texture1.loadFromFile("../res/1.png") ||
        !texture2.loadFromFile("../res/2.png") ||
        !texture3.loadFromFile("../res/3.png") ||
        !texture4.loadFromFile("../res/4.png")) {
        // Обработка ошибок загрузки
        return EXIT_FAILURE;
    }

    texture1.setRepeated(true);
    texture2.setRepeated(true);
    texture3.setRepeated(true);
    texture4.setRepeated(true);

    Sprite sprite1(texture1), sprite2(texture2), sprite3(texture3), sprite4(texture4);
    sprite1.setScale(float(window.getSize().x) / texture1.getSize().x, float(window.getSize().y) / texture1.getSize().y);
    sprite2.setScale(float(window.getSize().x) / texture2.getSize().x, float(window.getSize().y) / texture2.getSize().y);
    sprite3.setScale(float(window.getSize().x) / texture3.getSize().x, float(window.getSize().y) / texture3.getSize().y);
    sprite4.setScale(float(window.getSize().x) / texture4.getSize().x, float(window.getSize().y) / texture4.getSize().y);

    Shader parallaxShader;
    parallaxShader.loadFromMemory(
        "uniform float offset;"

        "void main() {"
        "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
        "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
        "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;" // magic
        "    gl_FrontColor = gl_Color;"
        "}"
        , Shader::Vertex);

    float offset = 0.f;

    Clock clock;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case Event::Closed:
                window.close();
                break;
            }
        }

        parallaxShader.setUniform("offset", offset += clock.restart().asSeconds() / 10);

        window.clear();

        // Отрисовка спрайтов в порядке от дальнего к ближнему:
        window.draw(sprite4, &parallaxShader);
        window.draw(sprite3, &parallaxShader);
        window.draw(sprite2, &parallaxShader);
        window.draw(sprite1, &parallaxShader);

        window.display();
    }

    return EXIT_SUCCESS;
}
