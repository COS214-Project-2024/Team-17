#ifndef GAMETHREAD_H
#define GAMETHREAD_H

#include <QThread>
#include "../src/Game.h"

class GameThread : public QThread {
    Q_OBJECT
public:
    GameThread(Game* game) : m_game(game) {}

protected:
    void run() override {
        m_game->start();
    }

private:
    Game* m_game;
};
#endif // GAMETHREAD_H
