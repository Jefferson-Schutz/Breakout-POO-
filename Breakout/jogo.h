#ifndef JOGO_H
#define JOGO_H

#include <QWidget>
#include <QList>
#include <QTimer>
#include "bola.h"
#include "raquete.h"
#include "bloco.h"

// Classe Jogo que gerencia o estado e a lógica do jogo
class Jogo : public QWidget {
    Q_OBJECT

public:
    explicit Jogo(QWidget *parent = nullptr);
    ~Jogo() override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateGame();

private:
    void moveBall();
    void checkCollision();
    void adjustBallSpeed(int hitPos);
    void drawScore(QPainter &painter); // Desenhar o placar
    bool gameOver;  // Variável para verificar se o jogo acabou
    bool Win; //Variavel de vitória

    Bola *ball; // Instância da bola
    Raquete *paddle; // Instância da raquete
    QList<Bloco *> bricks; // Lista de tijolos
    QTimer *timer; // Timer para atualização do jogo
    float speedMultiplier; // Multiplicador para velocidade da bola
    int score = 0; // Placar do jogo
    float speedPlus = 0 ;
};

#endif // JOGO_H
