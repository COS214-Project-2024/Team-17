#ifndef DRAGGABLEROAD_H
#define DRAGGABLEROAD_H

#include <QFrame>
#include <QMouseEvent>
#include <QSpinBox>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "homepage.h"

class DraggableRoad : public QFrame {
    Q_OBJECT

public:
    explicit DraggableRoad(QWidget *parent = nullptr, QSpinBox *EditXpos = nullptr, QSpinBox *EditYpos = nullptr, HomePage *homePage = nullptr, QVector<DraggableRoad*> roads = QVector<DraggableRoad*>(), RoadComponent *link = nullptr)
        : QFrame(parent), EditXpos(EditXpos), EditYpos(EditYpos), homePage(homePage), roads(roads), link(link){
        setFrameShape(QFrame::Box);
        setStyleSheet("background-color: #202020; border: 1px solid grey;");
        setFixedSize(120, 10);
    }

    ~DraggableRoad(){
        if(link!=nullptr){
            // delete link;
            cout<<"link deleted"<<endl;
        }
    }

    void setLink(RoadComponent *link){
        this->link = link;
    }

    RoadComponent* getLink(){
        return link;
    }


    bool editable = true;
    bool dragging = false;
    QFrame *frame;
    DraggableRoad * next;
    RoadComponent * connectedRoad = nullptr;

    void snapToRoad(DraggableRoad *otherRoad) {
        const int snapDistance = 20;

        QPoint startPos = pos();
        QPoint endPos;
        if(width()!=10&&width()!=15&&width()!=20){
            endPos = pos() + QPoint(width(), 0);
        }
        else{
            endPos = pos() + QPoint(0, height());
        }

        QPoint otherStartPos = otherRoad->pos();
        QPoint otherEndPos;
        if(otherRoad->width()!=10&&otherRoad->width()!=15&&otherRoad->width()!=20){
            otherEndPos = otherRoad->pos() + QPoint(otherRoad->width(), 0);
        }
        else{
            otherEndPos = otherRoad->pos() + QPoint(0, otherRoad->height());
        }

        if ((endPos - otherStartPos).manhattanLength() <= snapDistance) {
            connectedRoad=otherRoad->getLink();
            if(width()==10||width()==15||width()==20){
                move(otherStartPos - QPoint(0, height()));
            }
            else{
                move(otherStartPos - QPoint(width(), 0));
            }
        }
        else if ((startPos - otherEndPos).manhattanLength() <= snapDistance) {
            connectedRoad=otherRoad->getLink();
            move(otherEndPos);
        }
        else if ((endPos - otherEndPos).manhattanLength() <= snapDistance) {
            connectedRoad=otherRoad->getLink();
            if(!((otherRoad->width()==10||otherRoad->width()==15||otherRoad->width()==20)&&(width()==10||width()==15||width()==20))&&!((otherRoad->height()==10||otherRoad->height()==15||otherRoad->height()==20)&&(height()==10||height()==15||height()==20))){
                if(width()==10||width()==15||width()==20){
                    move(otherEndPos - QPoint(0, height()));
                }
                else{
                    move(otherEndPos - QPoint(width(), 0));
                }
            }
        }
        else if ((startPos - otherStartPos).manhattanLength() <= snapDistance) {
            connectedRoad=otherRoad->getLink();
            if(!((otherRoad->width()==10||otherRoad->width()==15||otherRoad->width()==20)&&(width()==10||width()==15||width()==20))&&!((otherRoad->height()==10||otherRoad->height()==15||otherRoad->height()==20)&&(height()==10||height()==15||height()==20))){
                move(otherStartPos);
            }
        }
        else{
            connectedRoad=nullptr;
        }
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && editable) {
            dragging = true;
            dragStartPosition = event->pos();  // Store starting position relative to the frame
        }
        else if(event->button() == Qt::LeftButton && !editable && !editMode){
            //popup edit window

            frame = new QFrame(parentWidget());

            int PopUpX;
            int PopUpY;
            if (x() + width() + 161 > parentWidget()->width()) {
                PopUpX = x() - 161;
            } else {
                PopUpX = x() + width();
            }

            if (y() + height() + 111 > parentWidget()->height()) {
                PopUpY = y() - 111;
            } else {
                PopUpY = y() + height();
            }

            frame->setGeometry(PopUpX, PopUpY, 161, 111);
            frame->setStyleSheet(R"(
                /* Frame styling */
                QFrame {
                    background-color: #f9f9f9; /* Light white shade */
                    color: #333333; /* Dark gray text */
                    border: 1px solid #cccccc; /* Light gray border */
                    border-radius: 8px; /* Rounded corners */
                    padding: 10px;
                }

                /* Label styling */
                QLabel {
                    color: black; /* Slightly darker gray text for labels */
                    font-size: 12px;
                    font-weight: bold;
                    margin-bottom: 5px; /* Space between label and button */
                    border: 0; /* No border */
                }

                /* Button styling */
                QPushButton {
                    background-color: #e6e6e6; /* Light gray background for button */
                    color: #333333; /* Dark gray text */
                    border: 1px solid #aaaaaa; /* Border around button */
                    border-radius: 6px; /* Rounded corners */
                    padding: 5px 10px; /* Button padding */
                }

                QPushButton:hover {
                    background-color: #d0d0d0; /* Slightly darker gray when hovering */
                }

                QPushButton:pressed {
                    background-color: #bfbfbf; /* Darker gray when pressed */
                }
            )");
            frame->setFrameShape(QFrame::StyledPanel);
            frame->setFrameShadow(QFrame::Raised);

            // Create the layout
            QVBoxLayout *layout = new QVBoxLayout(frame);

            // Create the label
            QLabel *labelBuildingType = new QLabel("Delete Building", frame);
            labelBuildingType->setFixedSize(120, 50);  // Optional: keep the label size fixed
            labelBuildingType->setAlignment(Qt::AlignCenter);
            layout->addWidget(labelBuildingType); // Add label to layout

            // Create the "Delete" button
            QPushButton *deleteButton = new QPushButton("Delete", frame);
            deleteButton->setFixedSize(95, 40);  // Optional: keep the button size fixed
            layout->addWidget(deleteButton, 0, Qt::AlignCenter); // Add button centered in layout

            // Set the layout to the frame
            frame->setLayout(layout);

            // Connect the delete button to the deleteBuilding() function
            connect(deleteButton, &QPushButton::clicked, this, &DraggableRoad::deleteBuilding);
            editMode = true;
            frame->show();

        }
        else if (event->button() == Qt::LeftButton && editMode){
            frame->hide();
            frame->deleteLater();
            editMode = false;
        }
    }

    void deleteBuilding(){
        if (editMode){
            frame->hide();
            frame->deleteLater();
            editMode = false;
        }
        homePage->deleteRoad(this);
    }

    void mouseMoveEvent(QMouseEvent *event) override;

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
    RoadComponent *link;
    bool editMode = false;
};

#endif // DRAGGABLEROAD_H
