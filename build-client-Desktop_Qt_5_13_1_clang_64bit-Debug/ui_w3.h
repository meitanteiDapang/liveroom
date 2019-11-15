/********************************************************************************
** Form generated from reading UI file 'w3.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W3_H
#define UI_W3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W3
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layouto;
    QLabel *pic_label;
    QTableWidget *tableWidget;
    QVBoxLayout *right_layout;
    QVBoxLayout *the_layout;
    QTextBrowser *msg_tb;
    QHBoxLayout *horizontalLayout;
    QLineEdit *msg_le;
    QPushButton *send_pb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *refresh_people_pb;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *rocket_pb;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quit_pb;

    void setupUi(QWidget *W3)
    {
        if (W3->objectName().isEmpty())
            W3->setObjectName(QString::fromUtf8("W3"));
        W3->resize(1000, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(W3->sizePolicy().hasHeightForWidth());
        W3->setSizePolicy(sizePolicy);
        W3->setMinimumSize(QSize(1000, 800));
        W3->setMaximumSize(QSize(1000, 800));
        gridLayout_2 = new QGridLayout(W3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layouto = new QVBoxLayout();
        layouto->setObjectName(QString::fromUtf8("layouto"));
        layouto->setSizeConstraint(QLayout::SetFixedSize);
        pic_label = new QLabel(W3);
        pic_label->setObjectName(QString::fromUtf8("pic_label"));
        pic_label->setMinimumSize(QSize(480, 270));
        pic_label->setMaximumSize(QSize(480, 270));

        layouto->addWidget(pic_label);


        verticalLayout_2->addLayout(layouto);

        tableWidget = new QTableWidget(W3);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(320, 200));
        tableWidget->setMaximumSize(QSize(480, 1000));
        tableWidget->setColumnCount(2);

        verticalLayout_2->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        right_layout = new QVBoxLayout();
        right_layout->setObjectName(QString::fromUtf8("right_layout"));
        right_layout->setSizeConstraint(QLayout::SetFixedSize);
        the_layout = new QVBoxLayout();
        the_layout->setObjectName(QString::fromUtf8("the_layout"));
        msg_tb = new QTextBrowser(W3);
        msg_tb->setObjectName(QString::fromUtf8("msg_tb"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(msg_tb->sizePolicy().hasHeightForWidth());
        msg_tb->setSizePolicy(sizePolicy1);

        the_layout->addWidget(msg_tb);


        right_layout->addLayout(the_layout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msg_le = new QLineEdit(W3);
        msg_le->setObjectName(QString::fromUtf8("msg_le"));

        horizontalLayout->addWidget(msg_le);

        send_pb = new QPushButton(W3);
        send_pb->setObjectName(QString::fromUtf8("send_pb"));

        horizontalLayout->addWidget(send_pb);


        right_layout->addLayout(horizontalLayout);


        gridLayout->addLayout(right_layout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        refresh_people_pb = new QPushButton(W3);
        refresh_people_pb->setObjectName(QString::fromUtf8("refresh_people_pb"));

        horizontalLayout_2->addWidget(refresh_people_pb);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        rocket_pb = new QPushButton(W3);
        rocket_pb->setObjectName(QString::fromUtf8("rocket_pb"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(30);
        sizePolicy2.setHeightForWidth(rocket_pb->sizePolicy().hasHeightForWidth());
        rocket_pb->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(18);
        rocket_pb->setFont(font);

        horizontalLayout_2->addWidget(rocket_pb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        quit_pb = new QPushButton(W3);
        quit_pb->setObjectName(QString::fromUtf8("quit_pb"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(quit_pb->sizePolicy().hasHeightForWidth());
        quit_pb->setSizePolicy(sizePolicy3);
        quit_pb->setFont(font);

        gridLayout->addWidget(quit_pb, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(W3);

        QMetaObject::connectSlotsByName(W3);
    } // setupUi

    void retranslateUi(QWidget *W3)
    {
        W3->setWindowTitle(QCoreApplication::translate("W3", "Form", nullptr));
        pic_label->setText(QCoreApplication::translate("W3", "\346\227\240\347\233\264\346\222\255", nullptr));
        msg_tb->setHtml(QCoreApplication::translate("W3", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        send_pb->setText(QCoreApplication::translate("W3", "\345\217\221\351\200\201", nullptr));
        refresh_people_pb->setText(QCoreApplication::translate("W3", "\345\210\267\346\226\260", nullptr));
        rocket_pb->setText(QCoreApplication::translate("W3", "\347\201\253\347\256\255/500", nullptr));
        quit_pb->setText(QCoreApplication::translate("W3", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W3: public Ui_W3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W3_H
