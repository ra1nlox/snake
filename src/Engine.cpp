#include "Engine.h"

Engine::Engine() {
    // Получаем разрешение экрана, создаем окно SFML и View
    // Vector2f resolution;
    // resolution.x = VideoMode::getDesktopMode().width;
    // resolution.y = VideoMode::getDesktopMode().height;
    Vector2u resolution;
    resolution.x = 800u;
    resolution.y = 600u;

    m_Window.create(VideoMode(resolution.x, resolution.y),
                    "Simple Game Engine",
                    Style::Default);

    m_Window.setSize(sf::Vector2u(800, 600));
    // m_Window.setPosition(sf::Vector2i(resolution.x / 2 - resolution.x, resolution.y / 2 - resolution.y));

    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    // m_BackgroundTexture.loadFromFile("background.jpg");

    // Связываем спрайт и текстуру
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::start() {
    // Расчет времени
    Clock clock;

    while (m_Window.isOpen()) {
        // Перезапускаем таймер и записываем отмеренное время в dt
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}