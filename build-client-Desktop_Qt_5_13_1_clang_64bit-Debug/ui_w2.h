/********************************************************************************
** Form generated from reading UI file 'w2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W2_H
#define UI_W2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W2
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QListView *lv;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLabel *username_label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *balance_lb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *refresh_pb;
    QSpacerItem *verticalSpacer;
    QPushButton *create_pb;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *money_le;
    QPushButton *topup_pb;
    QSpacerItem *verticalSpacer_2;
    QPushButton *quit_pb;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *W2)
    {
        if (W2->objectName().isEmpty())
            W2->setObjectName(QString::fromUtf8("W2"));
        W2->resize(900, 900);
        horizontalLayout_4 = new QHBoxLayout(W2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lv = new QListView(W2);
        lv->setObjectName(QString::fromUtf8("lv"));

        horizontalLayout_3->addWidget(lv);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(W2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        username_label = new QLabel(W2);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        sizePolicy.setHeightForWidth(username_label->sizePolicy().hasHeightForWidth());
        username_label->setSizePolicy(sizePolicy);
        username_label->setMinimumSize(QSize(0, 50));
        username_label->setFont(font);

        horizontalLayout_2->addWidget(username_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_3 = new QLabel(W2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        balance_lb = new QLabel(W2);
        balance_lb->setObjectName(QString::fromUtf8("balance_lb"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(60);
        sizePolicy2.setHeightForWidth(balance_lb->sizePolicy().hasHeightForWidth());
        balance_lb->setSizePolicy(sizePolicy2);
        balance_lb->setFont(font);

        horizontalLayout_2->addWidget(balance_lb);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        refresh_pb = new QPushButton(W2);
        refresh_pb->setObjectName(QString::fromUtf8("refresh_pb"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(refresh_pb->sizePolicy().hasHeightForWidth());
        refresh_pb->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(36);
        refresh_pb->setFont(font1);

        verticalLayout->addWidget(refresh_pb);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        create_pb = new QPushButton(W2);
        create_pb->setObjectName(QString::fromUtf8("create_pb"));
        sizePolicy3.setHeightForWidth(create_pb->sizePolicy().hasHeightForWidth());
        create_pb->setSizePolicy(sizePolicy3);
        create_pb->setFont(font1);

        verticalLayout->addWidget(create_pb);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        money_le = new QLineEdit(W2);
        money_le->setObjectName(QString::fromUtf8("money_le"));
        money_le->setDragEnabled(false);

        verticalLayout->addWidget(money_le);

        topup_pb = new QPushButton(W2);
        topup_pb->setObjectName(QString::fromUtf8("topup_pb"));
        sizePolicy3.setHeightForWidth(topup_pb->sizePolicy().hasHeightForWidth());
        topup_pb->setSizePolicy(sizePolicy3);
        topup_pb->setFont(font1);

        verticalLayout->addWidget(topup_pb);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        quit_pb = new QPushButton(W2);
        quit_pb->setObjectName(QString::fromUtf8("quit_pb"));
        sizePolicy3.setHeightForWidth(quit_pb->sizePolicy().hasHeightForWidth());
        quit_pb->setSizePolicy(sizePolicy3);
        quit_pb->setFont(font1);

        verticalLayout->addWidget(quit_pb);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(W2);

        QMetaObject::connectSlotsByName(W2);
    } // setupUi

    void retranslateUi(QWidget *W2)
    {
        W2->setWindowTitle(QCoreApplication::translate("W2", "Form", nullptr));
        label->setText(QCoreApplication::translate("W2", "\347\224\250\346\210\267\345\220\215", nullptr));
        username_label->setText(QCoreApplication::translate("W2", "\345\245\275\344\272\272", nullptr));
        label_3->setText(QCoreApplication::translate("W2", "\344\275\231\351\242\235", nullptr));
        balance_lb->setText(QCoreApplication::translate("W2", "0.0", nullptr));
        refresh_pb->setText(QCoreApplication::translate("W2", "\345\210\267\346\226\260", nullptr));
        create_pb->setText(QCoreApplication::translate("W2", "\345\210\233\345\273\272\346\210\277\351\227\264", nullptr));
        topup_pb->setText(QCoreApplication::translate("W2", "\345\205\205\345\200\274", nullptr));
        quit_pb->setText(QCoreApplication::translate("W2", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W2: public Ui_W2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W2_H
