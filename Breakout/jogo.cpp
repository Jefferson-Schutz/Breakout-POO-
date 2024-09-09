#include "jogo.h"
#include <QPainter>
#include <QKeyEvent>

// Construtor da classe Jogo
Jogo::Jogo(QWidget *parent)
    : QWidget(parent), speedMultiplier(1.0), gameOver (false), Win (false) {
    // Inicializa a bola com posição e tamanho
    ball = new Bola(390, 350, 20, 20);

    // Inicializa a raquete com posição e tamanho
    paddle = new Raquete(370, 550, 90, 10);

    // Inicializa os tijolos
    int brickWidth = 60;
    int brickHeight = 15;
    int spacing = 10;
    int columns = 10;
    int rows = 5;

    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            bricks.append(new Bloco(50 + i * (brickWidth + spacing), 30 + j * (brickHeight + spacing), brickWidth, brickHeight));
        }
    }

    // Inicializa o timer para atualizar o jogo
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Jogo::updateGame);
    timer->start(16); // Aproximadamente 60 FPS
}

// Destruidor da classe Jogo
Jogo::~Jogo() {
    delete ball;
    delete paddle;
    qDeleteAll(bricks); // Remove e deleta todos os tijolos
    delete timer;
}

// Função chamada para desenhar o jogo
void Jogo::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    // Desenha a bola
    painter.setBrush(Qt::red);
    painter.drawEllipse(ball->getRect());

    // Desenha a raquete
    painter.setBrush(Qt::blue);
    painter.drawRect(paddle->getRect());

    // Desenha os tijolos
    painter.setBrush(Qt::green);
    for (const Bloco *brick : bricks) {
        painter.drawRect(brick->getRect());
    }

    // Desenha o placar
    drawScore(painter);

    // Desenha a mensagem "Game Over" no centro da tela
    if (gameOver) {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 30, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "Game Over");
        return;  // Não desenha mais nada se o jogo terminou
    }

    //Denseha a mensagem de Vitória
    if (Win){
        painter.setPen(Qt::green);
        painter.setFont(QFont("Arial", 30, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "You Win!!");
        return;  // Não desenha mais nada se o jogo terminou
    }
}

// Função chamada quando uma tecla é pressionada
void Jogo::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    // Move a raquete para a esquerda ou direita
    if (key == Qt::Key_Left && paddle->getRect().left() > 0) {
        paddle->moveLeft(10);
    } else if (key == Qt::Key_Right && paddle->getRect().right() < width()) {
        paddle->moveRight(10);
    }

    QWidget::keyPressEvent(event);
}

// Função chamada periodicamente para atualizar o estado do jogo
void Jogo::updateGame() {
    moveBall();
    checkCollision();
    update();
}

// Move a bola com base na velocidade
void Jogo::moveBall() {
    ball->move(ball->getDx(), ball->getDy());

    // Verifica colisão com as bordas da janela
    if (ball->getRect().left() <= 0 || ball->getRect().right() >= width()) {
        ball->setVelocity(-ball->getDx(), ball->getDy());
    }
    if (ball->getRect().top() <= 0) {
        ball->setVelocity(ball->getDx(), -ball->getDy());
    }

    // Verifica se a bola caiu
    if (ball->getRect().bottom() >= height()) {
        gameOver = true; // Jogo terminou
        timer->stop(); // Fim de jogo
    }
}

// Verifica colisões da bola com a raquete e os tijolos
void Jogo::checkCollision() {
    // Colisão com a raquete
    if (ball->getRect().intersects(paddle->getRect())) {
        int hitPos = ball->getRect().center().x() - paddle->getRect().left();
        adjustBallSpeed(hitPos);
        ball->setVelocity(ball->getDx(), -ball->getDy()); // Muda a direção vertical, mas mantém o mesmo valor absoluto
    }

    // Colisão com os tijolos
    for (int i = 0; i < bricks.size(); ++i) {
        if (bricks[i]->isHit(ball->getRect())) {
            delete bricks[i];
            bricks.removeAt(i); // Remove e deleta o tijolo atingido
            ball->setVelocity(ball->getDx(), (-ball->getDy() + speedPlus));
            //speedPlus += 0.05; Bugou a direção da balinha quando bate nas quinas dos tijolos

            // Aumenta a velocidade da bola em 2%
            //speedMultiplier *= 1.02;
           //ball->increaseSpeed(1.02);

            score += 10; // Incrementa o placar

            break;
        }
    }
}

// Ajusta a velocidade da bola com base na posição de impacto na raquete
void Jogo::adjustBallSpeed(int hitPos) {
    int paddleWidth = paddle->getRect().width();
    // Calcula o fator de velocidade com base na posição de impacto na raquete
    float relativeHitPos = (2.0f * hitPos) / paddleWidth - 1.0f;

    // Ajusta a velocidade horizontal com base na posição de impacto
    int speedFactor = 3; // Fator de multiplicação para ajustar a intensidade da mudança de velocidade
    ball->setVelocity(static_cast<int>(relativeHitPos * speedFactor), ball->getDy());

    // Certifica-se de que a bola não pare completamente
    if (ball->getDx() == 0) {
        ball->setVelocity((relativeHitPos > 0) ? 1 : -1, ball->getDy());
    }
}
// Desenha o placar no canto superior direito
void Jogo::drawScore(QPainter &painter) {
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    painter.drawText(width() - 100, 20, QString("Score: %1").arg(score));
    //Ao quebrar o ultimo tijolo esse if é verdadeiro e finaliza o jogo com a mensagem de vitória.
    if (score == 500){
        Win = true;
        timer->stop(); // Fim de jogo
    }
}

