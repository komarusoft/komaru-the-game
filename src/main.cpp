#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Triangle");

  // Создание треугольника
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(100, 0));
  triangle.setPoint(1, sf::Vector2f(0, 200));
  triangle.setPoint(2, sf::Vector2f(200, 200));
  triangle.setFillColor(sf::Color::Green);

  float speed = 100.0f; // Скорость движения треугольника

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Движение треугольника
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      movement.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      movement.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      movement.y += speed;

    // Ограничение движения внутри окна
    sf::Vector2f pos = triangle.getPosition() + movement;
    if (pos.x >= 0 && pos.x <= window.getSize().x - 200 && pos.y >= 0 &&
        pos.y <= window.getSize().y - 200) {
      triangle.move(movement);
    }

    window.clear();
    window.draw(triangle);
    window.display();
  }

  return 0;
}
