#include "Engine.h"

void Engine::input() {
    // Обрабатываем нажатие Escape
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_Window.close();
    }

    // Обрабатываем нажатие клавиш движения
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        m_Snake.stopUp();
        m_Snake.stopDown();
        m_Snake.stopRight();
        m_Snake.moveLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        m_Snake.stopUp();
        m_Snake.stopDown();
        m_Snake.stopLeft();
        m_Snake.moveRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        m_Snake.stopLeft();
        m_Snake.stopRight();
        m_Snake.stopDown();
        m_Snake.moveUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::S)) {
        m_Snake.stopLeft();
        m_Snake.stopRight();
        m_Snake.stopUp();
        m_Snake.moveDown();
    }
}