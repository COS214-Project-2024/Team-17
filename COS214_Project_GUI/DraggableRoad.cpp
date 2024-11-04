#include "DraggableRoad.h"

#include "DraggableFrame.h"

void DraggableRoad::mouseMoveEvent(QMouseEvent *event) {
    if (dragging && editable) {
        int dx = event->pos().x() - dragStartPosition.x();
        int dy = event->pos().y() - dragStartPosition.y();

        // New position if movement is allowed
        int newX = x() + dx;
        int newY = y() + dy;

        // Boundary checks
        if (newX < 0) newX = 0;
        if (newY < 0) newY = 0;
        if (newX > parentWidget()->width() - width()) newX = parentWidget()->width() - width();
        if (newY > parentWidget()->height() - height()) newY = parentWidget()->height() - height();

        // Check for overlaps with other buildings
        bool overlap = false;
        for (DraggableFrame *other : homePage->getBuildings()) {
            QRect thisRect(newX, newY, width(), height());
            QRect otherRect(other->x(), other->y(), other->width(), other->height());

            if (thisRect.intersects(otherRect)) {
                overlap = true;
                break;
            }
        }

        for (DraggableRoad *other : homePage->getRoads()) {
            if (other != this) {
                QRect thisRect(newX, newY, width(), height());
                QRect otherRect(other->x(), other->y(), other->width(), other->height());

                if (thisRect.intersects(otherRect)) {
                    overlap = true;
                    break;
                }
            }
        }

        if (!overlap) {
            move(newX, newY);
            EditXpos->setValue(newX);
            EditYpos->setValue(newY);
        }


        for (DraggableRoad *road : roads) {
            if (road != this) {
                snapToRoad(road);
            }
        }

    }
}
