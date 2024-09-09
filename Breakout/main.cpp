#include <QApplication>
#include "jogo.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Jogo jogo;
    jogo.resize(800, 600); // Ajuste o tamanho da janela conforme necessário
    jogo.show();

    return app.exec();
}
