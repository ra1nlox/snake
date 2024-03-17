#include "Snake.h"

Snake::Snake() {
    // Вписываем в переменную скорость Боба
    m_Speed = 400;

    // Связываем текстуру и спрайт
    m_Texture.loadFromFile("snake_head.png");
    m_Sprite.setTexture(m_Texture);

    // Устанавливаем начальную позицию Боба в пикселях
    m_Position.x = 200;
    m_Position.y = 400;
}

// Делаем приватный спрайт доступным для функции draw()
Sprite Snake::getSprite() {
    return m_Sprite;
}

void Snake::moveLeft() {
    m_LeftPressed = true;
}

void Snake::moveRight() {
    m_RightPressed = true;
}

void Snake::moveUp() {
    m_UpPressed = true;
}

void Snake::moveDown() {
    m_DownPressed = true;
}

void Snake::stopLeft() {
    m_LeftPressed = false;
}

void Snake::stopRight() {
    m_RightPressed = false;
}

void Snake::stopUp() {
    m_UpPressed = false;
}

void Snake::stopDown() {
    m_DownPressed = false;
}

// Двигаем Боба на основании пользовательского ввода в этом кадре,
// прошедшего времени и скорости
void Snake::update(float elapsedTime) {
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }

    if (m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }

    // Теперь сдвигаем спрайт на новую позицию
    m_Sprite.setPosition(m_Position);
}