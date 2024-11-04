#include <QFrame>
#include <QMouseEvent>
#include <QSpinBox>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "homepage.h"

class DraggableFrame : public QFrame {
    Q_OBJECT

public:
    explicit DraggableFrame(QWidget *parent = nullptr, QSpinBox *EditXpos = nullptr, QSpinBox *EditYpos = nullptr, HomePage *homePage = nullptr, Building *link = nullptr, UtilityManager* utilLink = nullptr) : QFrame(parent) {
        setFrameShape(QFrame::Box);
        setLineWidth(2);
        setStyleSheet("background-color: #3498db;");
        setFixedSize(120, 100);  // Set size for the frame
        this->EditXpos = EditXpos;
        this->EditYpos = EditYpos;
        this->homePage = homePage;
        this->link = link;
        this->utilLink = utilLink;
    }
    ~DraggableFrame(){
        if(link!=nullptr){
            delete link;
        }
        if(utilLink!=nullptr){
            delete utilLink;
        }

    }
    bool editable = true;
    bool dragging = false;
    bool editMode = false;
    bool showingInfo = false;
    QFrame *frame;

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton && editable) {
            dragging = true;
            dragStartPosition = event->pos();  // Store starting position relative to the frame
        }
        else if(event->button() == Qt::LeftButton && !editable && !editMode){
            //popup info window
            if(!showingInfo && link!=nullptr){
                frame = new QFrame(parentWidget());

                int PopUpX;
                int PopUpY;
                if(x()+width()+161>parentWidget()->width()){
                    PopUpX = x()-161;
                }
                else{
                    PopUpX = x()+width();
                }

                if(y()+height()+111>parentWidget()->height()){
                    PopUpY = y()-111;
                }
                else{
                    PopUpY = y()+height();
                }

                frame->setGeometry(PopUpX, PopUpY, 150, 70);



                frame->setStyleSheet("background-color: rgb(198, 242, 255); color: black;");
                frame->setFrameShape(QFrame::StyledPanel);
                frame->setFrameShadow(QFrame::Raised);

                // Create the labels within the frame

                QLabel *labelElectricityUsage = new QLabel("Electricity usage: " + QString::number(link->getElectricityUsage()) + " per tick", frame);
                labelElectricityUsage->setGeometry(10, 10, 130, 16);

                QLabel *labelIncome = new QLabel("Water usage: " + QString::number(link->getWaterUsage()) + " per tick", frame);
                labelIncome->setGeometry(10, 30, 130, 16);

                QLabel *labelCitizenCount = new QLabel("Citizen count: " + QString::number(link->getCurCitizenCount()), frame);
                labelCitizenCount->setGeometry(10, 50, 130, 16);

                frame->show();
                showingInfo = true;
            }
            else if (link!=nullptr){
                frame->hide();
                frame->deleteLater();
                showingInfo = false;
            }

        }
        else if (event->button() == Qt::RightButton && !editMode && !editable && !showingInfo){
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
            connect(deleteButton, &QPushButton::clicked, this, &DraggableFrame::deleteBuilding);

            frame->show();
            editMode = true;
        }
        else if (event->button() == Qt::LeftButton && editMode){
            frame->hide();
            frame->deleteLater();
            editMode = false;
        }
    }

    void deleteBuilding(){
        if (showingInfo||editMode){
            frame->hide();
            frame->deleteLater();
            showingInfo = false;
        }
        homePage->deleteBuilding(this);
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
    Building *link;
    UtilityManager *utilLink;
};
