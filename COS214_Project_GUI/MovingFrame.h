#ifndef MOVINGFRAME_H
#define MOVINGFRAME_H
#include <QFrame>
#include <QMouseEvent>

class DraggableFrame;
class DraggableRoad;

class MovingFrame : public QFrame {
    Q_OBJECT

public:
    explicit MovingFrame(QWidget *parent = nullptr) : QFrame(parent) {
    }

    void addToRoads(DraggableRoad* road){
        roads.push_back(road);

    }
    void addToBuildings(DraggableFrame* building){
        buildings.push_back(building);
    }

    void removeFromRoads(DraggableRoad* road){
        roads.removeOne(road);
    }

    void removeFromBuildings(DraggableFrame* building){
        buildings.removeOne(building);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        // Handle mouse press event
        if (event->button() == Qt::LeftButton) {
            m_dragStartPosition = event->pos();
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override {
        // Handle mouse release event
    }

private:
    QPoint m_dragStartPosition;
    QVector<DraggableFrame *> buildings;
    QVector<DraggableRoad *> roads;
};



#endif // MOVINGFRAME_H
