#ifndef FRAMECONTAINER_H
#define FRAMECONTAINER_H
#include <QFrame>
#include <QMouseEvent>
#include <QSpinBox>
#include <QWidget>
#include <QLabel>

#include "homepage.h"

class FrameContainer : public QFrame {
    Q_OBJECT

public:

protected:


private:
    QPoint dragStartPosition;  // Position where the drag started
    QSpinBox *EditXpos;
    QSpinBox *EditYpos;
    HomePage *homePage;
};

#endif // FRAMECONTAINER_H
