/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *shapeDrawing;
    QPushButton *help;
    QPushButton *settings;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QWidget *displayPage;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *shapeTypeBox;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *polygonButtonShape;
    QPushButton *ellipseButtonShape;
    QPushButton *randomStar;
    QPushButton *triangle;
    QPushButton *rectangle;
    QPushButton *other;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *close;
    QSpacerItem *horizontalSpacer_8;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *propertiesBox;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page1;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *polygonVerticesEdit;
    QGroupBox *shapeTypeBox_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addRandomPolygon;
    QPushButton *addRandomIrregularPolygon;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *shapeTypeBox_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addPolygon;
    QPushButton *clearPolygonData;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *x_pos_lineEdit;
    QLabel *label_2;
    QLineEdit *y_pos_lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_8;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *width_lineEdit;
    QLabel *label_4;
    QLineEdit *height_lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *shapeTypeBox_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addEllipse;
    QPushButton *clearEllipseData;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *page3;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_5;
    QLineEdit *lineEditDepth;
    QSpacerItem *horizontalSpacer_10;
    QSlider *depthStarSlider;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_6;
    QLineEdit *lineEditVertices;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_7;
    QSlider *verticesStarSlider;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *addRandomPolygon_2;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_8;
    QWidget *page4;
    QPushButton *appedTriangle;
    QWidget *page5;
    QWidget *page6;
    QStackedWidget *stackedWidget_3;
    QWidget *page_5;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoomInButtton;
    QPushButton *zoomOutButton;
    QPushButton *zoomToFitButton;
    QPushButton *clearButton;
    QWidget *page_6;
    QWidget *helpPage;
    QPushButton *home;
    QPushButton *aboutQt;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(774, 500);
        MainWindow->setMinimumSize(QSize(720, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        mainPage = new QWidget();
        mainPage->setObjectName(QString::fromUtf8("mainPage"));
        verticalLayout_6 = new QVBoxLayout(mainPage);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_4 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        shapeDrawing = new QPushButton(mainPage);
        shapeDrawing->setObjectName(QString::fromUtf8("shapeDrawing"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(shapeDrawing->sizePolicy().hasHeightForWidth());
        shapeDrawing->setSizePolicy(sizePolicy);
        shapeDrawing->setMinimumSize(QSize(200, 200));
        shapeDrawing->setMaximumSize(QSize(300, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/app_icons/icon_files/shape.png"), QSize(), QIcon::Normal, QIcon::On);
        shapeDrawing->setIcon(icon);
        shapeDrawing->setIconSize(QSize(132, 132));

        horizontalLayout_9->addWidget(shapeDrawing);

        help = new QPushButton(mainPage);
        help->setObjectName(QString::fromUtf8("help"));
        sizePolicy.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy);
        help->setMinimumSize(QSize(200, 200));
        help->setMaximumSize(QSize(300, 300));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/app_icons/icon_files/help.png"), QSize(), QIcon::Normal, QIcon::On);
        help->setIcon(icon1);
        help->setIconSize(QSize(128, 128));

        horizontalLayout_9->addWidget(help);

        settings = new QPushButton(mainPage);
        settings->setObjectName(QString::fromUtf8("settings"));
        sizePolicy.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy);
        settings->setMinimumSize(QSize(200, 200));
        settings->setMaximumSize(QSize(300, 300));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/app_icons/icon_files/settings.png"), QSize(), QIcon::Normal, QIcon::On);
        settings->setIcon(icon2);
        settings->setIconSize(QSize(132, 132));

        horizontalLayout_9->addWidget(settings);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_9);


        verticalLayout_6->addLayout(horizontalLayout_11);

        verticalSpacer_5 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_6->addItem(verticalSpacer_5);

        stackedWidget->addWidget(mainPage);
        displayPage = new QWidget();
        displayPage->setObjectName(QString::fromUtf8("displayPage"));
        verticalLayout_5 = new QVBoxLayout(displayPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 0, 0, 0);
        shapeTypeBox = new QGroupBox(displayPage);
        shapeTypeBox->setObjectName(QString::fromUtf8("shapeTypeBox"));
        shapeTypeBox->setStyleSheet(QString::fromUtf8("QGroupBox#shapeTypeBox\n"
"{\n"
"border-style:none;\n"
"}"));
        horizontalLayout_10 = new QHBoxLayout(shapeTypeBox);
        horizontalLayout_10->setSpacing(2);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(2, 2, 2, 2);
        polygonButtonShape = new QPushButton(shapeTypeBox);
        polygonButtonShape->setObjectName(QString::fromUtf8("polygonButtonShape"));
        polygonButtonShape->setEnabled(false);
        polygonButtonShape->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(polygonButtonShape);

        ellipseButtonShape = new QPushButton(shapeTypeBox);
        ellipseButtonShape->setObjectName(QString::fromUtf8("ellipseButtonShape"));
        ellipseButtonShape->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(ellipseButtonShape);

        randomStar = new QPushButton(shapeTypeBox);
        randomStar->setObjectName(QString::fromUtf8("randomStar"));
        randomStar->setEnabled(true);
        randomStar->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(randomStar);

        triangle = new QPushButton(shapeTypeBox);
        triangle->setObjectName(QString::fromUtf8("triangle"));
        triangle->setEnabled(true);
        triangle->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(triangle);

        rectangle = new QPushButton(shapeTypeBox);
        rectangle->setObjectName(QString::fromUtf8("rectangle"));
        rectangle->setEnabled(true);
        rectangle->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(rectangle);

        other = new QPushButton(shapeTypeBox);
        other->setObjectName(QString::fromUtf8("other"));
        other->setEnabled(true);
        other->setMinimumSize(QSize(80, 22));

        horizontalLayout_10->addWidget(other);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);

        close = new QPushButton(shapeTypeBox);
        close->setObjectName(QString::fromUtf8("close"));
        close->setEnabled(true);
        close->setMinimumSize(QSize(80, 22));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/app_icons/icon_files/home.png"), QSize(), QIcon::Normal, QIcon::On);
        close->setIcon(icon3);

        horizontalLayout_10->addWidget(close);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_5->addWidget(shapeTypeBox);

        splitter = new QSplitter(displayPage);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy1);
        splitter->setStyleSheet(QString::fromUtf8(""));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(200, 0));
        groupBox_2->setMaximumSize(QSize(400, 16777215));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        propertiesBox = new QGroupBox(groupBox_2);
        propertiesBox->setObjectName(QString::fromUtf8("propertiesBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(propertiesBox->sizePolicy().hasHeightForWidth());
        propertiesBox->setSizePolicy(sizePolicy3);
        propertiesBox->setStyleSheet(QString::fromUtf8("QGroupBox#propertiesBox\n"
"{\n"
"border-style:none;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(propertiesBox);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        stackedWidget_2 = new QStackedWidget(propertiesBox);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        verticalLayout_3 = new QVBoxLayout(page1);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        polygonVerticesEdit = new QTextEdit(page1);
        polygonVerticesEdit->setObjectName(QString::fromUtf8("polygonVerticesEdit"));
        polygonVerticesEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";"));

        verticalLayout_3->addWidget(polygonVerticesEdit);

        shapeTypeBox_4 = new QGroupBox(page1);
        shapeTypeBox_4->setObjectName(QString::fromUtf8("shapeTypeBox_4"));
        shapeTypeBox_4->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border-style:none;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(shapeTypeBox_4);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 2, 2, 0);
        addRandomPolygon = new QPushButton(shapeTypeBox_4);
        addRandomPolygon->setObjectName(QString::fromUtf8("addRandomPolygon"));
        addRandomPolygon->setMinimumSize(QSize(80, 22));

        horizontalLayout_4->addWidget(addRandomPolygon);

        addRandomIrregularPolygon = new QPushButton(shapeTypeBox_4);
        addRandomIrregularPolygon->setObjectName(QString::fromUtf8("addRandomIrregularPolygon"));
        addRandomIrregularPolygon->setMinimumSize(QSize(80, 22));

        horizontalLayout_4->addWidget(addRandomIrregularPolygon);

        horizontalSpacer_7 = new QSpacerItem(411, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(shapeTypeBox_4);

        shapeTypeBox_2 = new QGroupBox(page1);
        shapeTypeBox_2->setObjectName(QString::fromUtf8("shapeTypeBox_2"));
        shapeTypeBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border-style:none;\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(shapeTypeBox_2);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        addPolygon = new QPushButton(shapeTypeBox_2);
        addPolygon->setObjectName(QString::fromUtf8("addPolygon"));
        addPolygon->setMinimumSize(QSize(80, 22));

        horizontalLayout_5->addWidget(addPolygon);

        clearPolygonData = new QPushButton(shapeTypeBox_2);
        clearPolygonData->setObjectName(QString::fromUtf8("clearPolygonData"));
        clearPolygonData->setMinimumSize(QSize(80, 22));

        horizontalLayout_5->addWidget(clearPolygonData);

        horizontalSpacer_3 = new QSpacerItem(411, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(shapeTypeBox_2);

        stackedWidget_2->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        verticalLayout_4 = new QVBoxLayout(page2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(page2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font;
        font.setPointSize(10);
        groupBox_3->setFont(font);
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(2);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(14, 20));
        label->setMaximumSize(QSize(14, 20));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        x_pos_lineEdit = new QLineEdit(groupBox_3);
        x_pos_lineEdit->setObjectName(QString::fromUtf8("x_pos_lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, x_pos_lineEdit);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(14, 20));
        label_2->setMaximumSize(QSize(14, 20));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        y_pos_lineEdit = new QLineEdit(groupBox_3);
        y_pos_lineEdit->setObjectName(QString::fromUtf8("y_pos_lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, y_pos_lineEdit);


        horizontalLayout_7->addLayout(formLayout);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_4->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        groupBox_4 = new QGroupBox(page2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font);
        horizontalLayout_8 = new QHBoxLayout(groupBox_4);
        horizontalLayout_8->setSpacing(2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(2);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(40, 20));
        label_3->setMaximumSize(QSize(40, 20));
        label_3->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        width_lineEdit = new QLineEdit(groupBox_4);
        width_lineEdit->setObjectName(QString::fromUtf8("width_lineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, width_lineEdit);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(40, 20));
        label_4->setMaximumSize(QSize(40, 20));
        label_4->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        height_lineEdit = new QLineEdit(groupBox_4);
        height_lineEdit->setObjectName(QString::fromUtf8("height_lineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, height_lineEdit);


        horizontalLayout_8->addLayout(formLayout_2);

        horizontalSpacer_6 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_4->addWidget(groupBox_4);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        shapeTypeBox_3 = new QGroupBox(page2);
        shapeTypeBox_3->setObjectName(QString::fromUtf8("shapeTypeBox_3"));
        shapeTypeBox_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"border-style:none;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(shapeTypeBox_3);
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        addEllipse = new QPushButton(shapeTypeBox_3);
        addEllipse->setObjectName(QString::fromUtf8("addEllipse"));
        addEllipse->setMinimumSize(QSize(80, 22));

        horizontalLayout_6->addWidget(addEllipse);

        clearEllipseData = new QPushButton(shapeTypeBox_3);
        clearEllipseData->setObjectName(QString::fromUtf8("clearEllipseData"));
        clearEllipseData->setMinimumSize(QSize(80, 22));

        horizontalLayout_6->addWidget(clearEllipseData);

        horizontalSpacer_4 = new QSpacerItem(411, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(shapeTypeBox_3);

        verticalSpacer_3 = new QSpacerItem(40, 29, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        stackedWidget_2->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        verticalLayout_9 = new QVBoxLayout(page3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_7);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_5 = new QLabel(page3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(36, 24));
        label_5->setMaximumSize(QSize(30, 24));
        label_5->setFont(font);

        horizontalLayout_12->addWidget(label_5);

        lineEditDepth = new QLineEdit(page3);
        lineEditDepth->setObjectName(QString::fromUtf8("lineEditDepth"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEditDepth->sizePolicy().hasHeightForWidth());
        lineEditDepth->setSizePolicy(sizePolicy4);
        lineEditDepth->setMinimumSize(QSize(80, 24));
        lineEditDepth->setMaximumSize(QSize(80, 24));
        lineEditDepth->setFont(font);
        lineEditDepth->setFocusPolicy(Qt::NoFocus);
        lineEditDepth->setAutoFillBackground(false);
        lineEditDepth->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEditDepth);

        horizontalSpacer_10 = new QSpacerItem(28, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_12);

        depthStarSlider = new QSlider(page3);
        depthStarSlider->setObjectName(QString::fromUtf8("depthStarSlider"));
        depthStarSlider->setMinimum(10);
        depthStarSlider->setMaximum(90);
        depthStarSlider->setSingleStep(5);
        depthStarSlider->setPageStep(5);
        depthStarSlider->setSliderPosition(90);
        depthStarSlider->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(depthStarSlider);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_6 = new QLabel(page3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(48, 24));
        label_6->setMaximumSize(QSize(30, 24));
        label_6->setFont(font);

        horizontalLayout_14->addWidget(label_6);

        lineEditVertices = new QLineEdit(page3);
        lineEditVertices->setObjectName(QString::fromUtf8("lineEditVertices"));
        sizePolicy4.setHeightForWidth(lineEditVertices->sizePolicy().hasHeightForWidth());
        lineEditVertices->setSizePolicy(sizePolicy4);
        lineEditVertices->setMinimumSize(QSize(80, 24));
        lineEditVertices->setMaximumSize(QSize(80, 24));
        lineEditVertices->setFont(font);
        lineEditVertices->setFocusPolicy(Qt::NoFocus);
        lineEditVertices->setAutoFillBackground(false);
        lineEditVertices->setReadOnly(true);

        horizontalLayout_14->addWidget(lineEditVertices);

        horizontalSpacer_12 = new QSpacerItem(28, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);


        verticalLayout_8->addLayout(horizontalLayout_14);

        label_7 = new QLabel(page3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 18));
        label_7->setMaximumSize(QSize(124, 18));
        label_7->setFont(font);

        verticalLayout_8->addWidget(label_7);

        verticesStarSlider = new QSlider(page3);
        verticesStarSlider->setObjectName(QString::fromUtf8("verticesStarSlider"));
        verticesStarSlider->setMinimum(3);
        verticesStarSlider->setMaximum(16);
        verticesStarSlider->setSingleStep(1);
        verticesStarSlider->setPageStep(3);
        verticesStarSlider->setValue(3);
        verticesStarSlider->setSliderPosition(3);
        verticesStarSlider->setOrientation(Qt::Horizontal);
        verticesStarSlider->setInvertedAppearance(false);

        verticalLayout_8->addWidget(verticesStarSlider);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        addRandomPolygon_2 = new QPushButton(page3);
        addRandomPolygon_2->setObjectName(QString::fromUtf8("addRandomPolygon_2"));
        addRandomPolygon_2->setMinimumSize(QSize(80, 22));

        horizontalLayout_13->addWidget(addRandomPolygon_2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_13);

        verticalSpacer_8 = new QSpacerItem(20, 119, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        stackedWidget_2->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        appedTriangle = new QPushButton(page4);
        appedTriangle->setObjectName(QString::fromUtf8("appedTriangle"));
        appedTriangle->setEnabled(true);
        appedTriangle->setGeometry(QRect(60, 120, 80, 22));
        appedTriangle->setMinimumSize(QSize(80, 22));
        stackedWidget_2->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QString::fromUtf8("page5"));
        stackedWidget_2->addWidget(page5);
        page6 = new QWidget();
        page6->setObjectName(QString::fromUtf8("page6"));
        stackedWidget_2->addWidget(page6);

        verticalLayout_2->addWidget(stackedWidget_2);


        horizontalLayout_2->addWidget(propertiesBox);

        splitter->addWidget(groupBox_2);
        stackedWidget_3 = new QStackedWidget(splitter);
        stackedWidget_3->setObjectName(QString::fromUtf8("stackedWidget_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(9);
        sizePolicy5.setVerticalStretch(9);
        sizePolicy5.setHeightForWidth(stackedWidget_3->sizePolicy().hasHeightForWidth());
        stackedWidget_3->setSizePolicy(sizePolicy5);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        verticalLayout = new QVBoxLayout(page_5);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        graphicsView = new QGraphicsView(page_5);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        groupBox = new QGroupBox(page_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer = new QSpacerItem(411, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        zoomInButtton = new QPushButton(groupBox);
        zoomInButtton->setObjectName(QString::fromUtf8("zoomInButtton"));
        zoomInButtton->setMinimumSize(QSize(80, 22));

        horizontalLayout->addWidget(zoomInButtton);

        zoomOutButton = new QPushButton(groupBox);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        zoomOutButton->setMinimumSize(QSize(80, 22));

        horizontalLayout->addWidget(zoomOutButton);

        zoomToFitButton = new QPushButton(groupBox);
        zoomToFitButton->setObjectName(QString::fromUtf8("zoomToFitButton"));
        zoomToFitButton->setMinimumSize(QSize(80, 22));

        horizontalLayout->addWidget(zoomToFitButton);

        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(80, 22));

        horizontalLayout->addWidget(clearButton);


        verticalLayout->addWidget(groupBox);

        stackedWidget_3->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        stackedWidget_3->addWidget(page_6);
        splitter->addWidget(stackedWidget_3);

        verticalLayout_5->addWidget(splitter);

        stackedWidget->addWidget(displayPage);
        helpPage = new QWidget();
        helpPage->setObjectName(QString::fromUtf8("helpPage"));
        home = new QPushButton(helpPage);
        home->setObjectName(QString::fromUtf8("home"));
        home->setEnabled(true);
        home->setGeometry(QRect(500, 70, 80, 24));
        home->setMinimumSize(QSize(80, 22));
        home->setIcon(icon3);
        aboutQt = new QPushButton(helpPage);
        aboutQt->setObjectName(QString::fromUtf8("aboutQt"));
        aboutQt->setEnabled(true);
        aboutQt->setGeometry(QRect(250, 80, 80, 22));
        aboutQt->setMinimumSize(QSize(80, 22));
        stackedWidget->addWidget(helpPage);

        horizontalLayout_3->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 774, 20));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(3);
        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Shapes Display Application", nullptr));
#if QT_CONFIG(tooltip)
        shapeDrawing->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Shapes menu</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        shapeDrawing->setText(QString());
#if QT_CONFIG(tooltip)
        help->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Help</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        help->setText(QString());
#if QT_CONFIG(tooltip)
        settings->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Settings</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        settings->setText(QString());
        shapeTypeBox->setTitle(QString());
        polygonButtonShape->setText(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        ellipseButtonShape->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        randomStar->setText(QCoreApplication::translate("MainWindow", "Star", nullptr));
        triangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        rectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        other->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
#if QT_CONFIG(tooltip)
        close->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Home</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        close->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        groupBox_2->setTitle(QString());
        propertiesBox->setTitle(QString());
        polygonVerticesEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">100,200;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">200,200;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">200,300;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">250,350;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">125,385;</p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">65,300;</p></body></html>", nullptr));
        shapeTypeBox_4->setTitle(QString());
#if QT_CONFIG(tooltip)
        addRandomPolygon->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Generate random  regular polygon</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addRandomPolygon->setText(QCoreApplication::translate("MainWindow", "Random[R]", nullptr));
#if QT_CONFIG(tooltip)
        addRandomIrregularPolygon->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Generate random irregular polygon</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addRandomIrregularPolygon->setText(QCoreApplication::translate("MainWindow", "Random[I]", nullptr));
        shapeTypeBox_2->setTitle(QString());
        addPolygon->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        clearPolygonData->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Position", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Dimensions", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        shapeTypeBox_3->setTitle(QString());
        addEllipse->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        clearEllipseData->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Depth:", nullptr));
        lineEditDepth->setText(QCoreApplication::translate("MainWindow", "90 %", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
        lineEditVertices->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "     (Prominent ones)", nullptr));
        addRandomPolygon_2->setText(QCoreApplication::translate("MainWindow", "Draw star", nullptr));
        appedTriangle->setText(QCoreApplication::translate("MainWindow", "Add Triangle", nullptr));
        groupBox->setTitle(QString());
        zoomInButtton->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
        zoomToFitButton->setText(QCoreApplication::translate("MainWindow", "Zoom to fit", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        home->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Home</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        home->setText(QCoreApplication::translate("MainWindow", "Home", nullptr));
        aboutQt->setText(QCoreApplication::translate("MainWindow", "Qt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
