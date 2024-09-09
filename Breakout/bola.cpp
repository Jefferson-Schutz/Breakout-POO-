#include "bola.h"

// Construtor da classe Bola
Bola::Bola(int x, int y, int width, int height)
    : rect(x, y, width, height), ball_dx(0), ball_dy(5) {}  // Inicialmente, a bola sobe

// Retorna o retângulo da bola
QRect Bola::getRect() const {
    return rect;
}

// Retorna a velocidade horizontal da bola
int Bola::getDx() const {
    return ball_dx;
}

// Retorna a velocidade vertical da bola
int Bola::getDy() const {
    return ball_dy;
}

// Move a bola com base na velocidade
void Bola::move(int dx, int dy) {
    rect.moveLeft(rect.left() + dx);
    rect.moveTop(rect.top() + dy);
}

// Define a velocidade da bola
void Bola::setVelocity(int dx, int dy) {
    ball_dx = dx;
    ball_dy = dy;
}

// Aumenta a velocidade da bola com base em um fator
void Bola::increaseSpeed(float factor) {
    ball_dx *= factor;
    ball_dy *= factor;
}
