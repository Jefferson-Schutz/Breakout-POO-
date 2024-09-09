#include "raquete.h"

// Construtor da classe Raquete
Raquete::Raquete(int x, int y, int width, int height)
    : rect(x, y, width, height) {}

// Retorna o retângulo da raquete
QRect Raquete::getRect() const {
    return rect;
}

// Move a raquete para a esquerda
void Raquete::moveLeft(int distance) {
    rect.moveLeft(rect.left() - distance);
}

// Move a raquete para a direita
void Raquete::moveRight(int distance) {
    rect.moveLeft(rect.left() + distance);
}
