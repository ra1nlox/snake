#include "Engine.h"

void Engine::input() {
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_Window.close();
    }

    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_Snake.moveLeft();
    } else {
        m_Snake.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_Snake.moveRight();
    } else {
        m_Snake.stopRight();
    }
}