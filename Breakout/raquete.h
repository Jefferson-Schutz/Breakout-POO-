#ifndef RAQUETE_H
#define RAQUETE_H

#include <QRect>

// Classe Raquete que representa a raquete no jogo
class Raquete {
public:
    // Construtor para inicializar a raquete com posição e tamanho
    Raquete(int x, int y, int width, int height);

    // Método para obter o retângulo da raquete
    QRect getRect() const;

    // Método para mover a raquete para a esquerda
    void moveLeft(int distance);

    // Método para mover a raquete para a direita
    void moveRight(int distance);

private:
    QRect rect; // Retângulo que define a posição e o tamanho da raquete
};

#endif // RAQUETE_H
