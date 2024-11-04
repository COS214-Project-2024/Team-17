#include "MovingFrame.h"
#include "DraggableFrame.h"
#include "DraggableRoad.h"

void MovingFrame::mouseMoveEvent(QMouseEvent *event){
    // Handle drag event
    if (event->buttons() & Qt::LeftButton) {
        // Implement your drag logic here
        QPoint offset = event->pos() - m_dragStartPosition;

        for (auto* building : buildings) {
            // if (!building->editable){
                building->move(building->pos() + offset);
            // }
            if(building->showingInfo){
                building->frame->hide();
                building->frame->deleteLater();
                building->showingInfo = false;
            }
        }

        for (auto* road : roads) {
            // if (!road->editable){
                road->move(road->pos() + offset);
            // }
        }

        m_dragStartPosition = event->pos();
    }
}
