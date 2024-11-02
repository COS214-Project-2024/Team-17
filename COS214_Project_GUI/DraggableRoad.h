#ifndef DRAGGABLEROAD_H
#define DRAGGABLEROAD_H

#include <QFrame>
#include <QMouseEvent>
#include <QSpinBox>
#include <QWidget>
#include <QLabel>

#include "homepage.h"

class DraggableRoad : public QFrame {
    Q_OBJECT

public:
    explicit DraggableRoad(QWidget *parent = nullptr, QSpinBox *EditXpos = nullptr, QSpinBox *EditYpos = nullptr, HomePage *homePage = nullptr, QVector<DraggableRoad*> roads = QVector<DraggableRoad*>())
        : QFrame(parent), EditXpos(EditXpos), EditYpos(EditYpos), homePage(homePage), roads(roads){
        setFrameShape(QFrame::Box);
        setStyleSheet("background-color: #202020; border: 1px solid grey;");
        setFixedSize(120, 10);  // Set size for the frame
    }

    bool editable = true;
    bool dragging = false;
    QFrame *frame;
    DraggableRoad * next;

    // Method to snap to another road
    void snapToRoad(DraggableRoad *otherRoad) {
        const int snapDistance = 20;  // Snap tolerance in pixels

        // Get positions of current road ends
        QPoint startPos = pos();
        QPoint endPos;
        if(width()!=10){
            endPos = pos() + QPoint(width(), 0);
        }
        else{
            endPos = pos() + QPoint(0, height());
        }

        // Get positions of other road ends
        QPoint otherStartPos = otherRoad->pos();
        QPoint otherEndPos;
        if(otherRoad->width()!=10){
            otherEndPos = otherRoad->pos() + QPoint(otherRoad->width(), 0);
        }
        else{
            otherEndPos = otherRoad->pos() + QPoint(0, otherRoad->height());
        }

        // Snap other road start to current road end if within range
        if ((endPos - otherStartPos).manhattanLength() <= snapDistance) {
            if(width()==10){
                move(otherStartPos - QPoint(0, height()));
            }
            else{
                move(otherStartPos - QPoint(width(), 0));
            }
        }
        // Snap other road end to current road start if within range
        else if ((startPos - otherEndPos).manhattanLength() <= snapDistance) {
            move(otherEndPos);
        }
        // Snap other road end to current road end if within range
        else if ((endPos - otherEndPos).manhattanLength() <= snapDistance) {
            if(!(otherRoad->width()==10&&width()==10)&&!(otherRoad->height()==10&&height()==10)){
                if(width()==10){
                    move(otherEndPos - QPoint(0, height()));
                }
                else{
                    move(otherEndPos - QPoint(width(), 0));
                }
            }
        }
        // Snap other road start to current road start if within range
        else if ((startPos - otherStartPos).manhattanLength() <= snapDistance) {
            if(!(otherRoad->width()==10&&width()==10)&&!(otherRoad->height()==10&&height()==10)){
                move(otherStartPos);
            }
        }
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && editable) {
            dragging = true;
            dragStartPosition = event->pos();  // Store starting position relative to the frame
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (dragging && editable) {
            int dx = event->pos().x() - dragStartPosition.x();
            int dy = event->pos().y() - dragStartPosition.y();

            // Boundary checks
            dx = qMax(qMin(dx, parentWidget()->width() - width() - x()), -x());
            dy = qMax(qMin(dy, parentWidget()->height() - height() - y()), -y());

            // Move the road
            move(x() + dx, y() + dy);
            EditXpos->setValue(x());
            EditYpos->setValue(y());


            for (DraggableRoad *road : roads) {
                if (road != this) {
                    snapToRoad(road);
                }
            }

        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            dragging = false;  // Stop dragging
        }
    }

private:
    QPoint dragStartPosition;  // Position where the drag started
    QSpinBox *EditXpos;
    QSpinBox *EditYpos;
    HomePage *homePage;
    QVector<DraggableRoad *> roads;
};

#endif // DRAGGABLEROAD_H
