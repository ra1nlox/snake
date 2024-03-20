#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    Vector2u display_size(1280u, 900u);

    RenderWindow window(VideoMode(display_size.x, display_size.y), "SNAKE");
    window.setSize(display_size);
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}