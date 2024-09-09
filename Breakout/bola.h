#ifndef BOLA_H
#define BOLA_H

#include <QRect>

// Classe Bola que representa a bola no jogo
class Bola {
public:
    // Construtor para inicializar a bola com posição e tamanho
    Bola(int x, int y, int width, int height);

    // Método para obter o retângulo da bola
    QRect getRect() const;

    // Métodos para obter a velocidade da bola
    int getDx() const;
    int getDy() const;

    // Método para mover a bola
    void move(int dx, int dy);

    // Método para definir a velocidade da bola
    void setVelocity(int dx, int dy);

    // Método para aumentar a velocidade da bola
    void increaseSpeed(float factor);

private:
    QRect rect;    // Retângulo que define a posição e o tamanho da bola
    int ball_dx;   // Velocidade horizontal da bola
    int ball_dy;   // Velocidade vertical da bola
};

#endif // BOLA_H
