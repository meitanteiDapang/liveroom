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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W3
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *layouto;
    QVBoxLayout *verticalLayout;
    QTextBrowser *msg_tb;
    QHBoxLayout *horizontalLayout;
    QLineEdit *msg_le;
    QPushButton *send_pb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *rocket_pb;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quit_pb;

    void setupUi(QWidget *W3)
    {
        if (W3->objectName().isEmpty())
            W3->setObjectName(QString::fromUtf8("W3"));
        W3->resize(800, 600);
        gridLayout_2 = new QGridLayout(W3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        layouto = new QVBoxLayout();
        layouto->setObjectName(QString::fromUtf8("layouto"));
        layouto->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout->addLayout(layouto, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        msg_tb = new QTextBrowser(W3);
        msg_tb->setObjectName(QString::fromUtf8("msg_tb"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(msg_tb->sizePolicy().hasHeightForWidth());
        msg_tb->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(msg_tb);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        msg_le = new QLineEdit(W3);
        msg_le->setObjectName(QString::fromUtf8("msg_le"));

        horizontalLayout->addWidget(msg_le);

        send_pb = new QPushButton(W3);
        send_pb->setObjectName(QString::fromUtf8("send_pb"));

        horizontalLayout->addWidget(send_pb);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        rocket_pb = new QPushButton(W3);
        rocket_pb->setObjectName(QString::fromUtf8("rocket_pb"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(30);
        sizePolicy1.setHeightForWidth(rocket_pb->sizePolicy().hasHeightForWidth());
        rocket_pb->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        rocket_pb->setFont(font);

        horizontalLayout_2->addWidget(rocket_pb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        quit_pb = new QPushButton(W3);
        quit_pb->setObjectName(QString::fromUtf8("quit_pb"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(quit_pb->sizePolicy().hasHeightForWidth());
        quit_pb->setSizePolicy(sizePolicy2);
        quit_pb->setFont(font);

        gridLayout->addWidget(quit_pb, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(W3);

        QMetaObject::connectSlotsByName(W3);
    } // setupUi

    void retranslateUi(QWidget *W3)
    {
        W3->setWindowTitle(QCoreApplication::translate("W3", "Form", nullptr));
        msg_tb->setHtml(QCoreApplication::translate("W3", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.AppleSystemUIFont';\"><br /></p></body></html>", nullptr));
        send_pb->setText(QCoreApplication::translate("W3", "\345\217\221\351\200\201", nullptr));
        rocket_pb->setText(QCoreApplication::translate("W3", "\347\201\253\347\256\255/500", nullptr));
        quit_pb->setText(QCoreApplication::translate("W3", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W3: public Ui_W3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W3_H
