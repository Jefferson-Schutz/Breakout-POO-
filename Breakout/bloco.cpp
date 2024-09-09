#include "bloco.h"

// Construtor da classe Bloco
Bloco::Bloco(int x, int y, int width, int height)
    : rect(x, y, width, height) {}

// Retorna o retângulo do bloco
QRect Bloco::getRect() const {
    return rect;
}

// Verifica se a bola colidiu com o bloco
bool Bloco::isHit(const QRect &ballRect) const {
    return rect.intersects(ballRect);
}
