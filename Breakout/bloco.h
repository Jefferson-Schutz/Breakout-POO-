#ifndef BLOCO_H
#define BLOCO_H

#include <QRect>

// Classe Bloco que representa um tijolo no jogo
class Bloco {
public:
    // Construtor para inicializar o bloco com posição e tamanho
    Bloco(int x, int y, int width, int height);

    // Método para obter o retângulo do bloco
    QRect getRect() const;

    // Método para verificar se a bola colidiu com o bloco
    bool isHit(const QRect &ballRect) const;

private:
    QRect rect; // Retângulo que define a posição e o tamanho do bloco
};

#endif // BLOCO_H
