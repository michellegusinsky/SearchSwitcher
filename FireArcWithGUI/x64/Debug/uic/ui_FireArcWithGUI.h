/********************************************************************************
** Form generated from reading UI file 'FireArcWithGUI.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIREARCWITHGUI_H
#define UI_FIREARCWITHGUI_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FireArcWithGUI
{
public:
    QLabel *title;
    QLineEdit *entryName;
    QLineEdit *shortcut;
    QLineEdit *url;
    QPushButton *start;
    QLabel *urlRequirment;

    void setupUi(QWidget *FireArcWithGUI)
    {
        if (FireArcWithGUI->objectName().isEmpty())
            FireArcWithGUI->setObjectName("FireArcWithGUI");
        FireArcWithGUI->resize(400, 300);
        title = new QLabel(FireArcWithGUI);
        title->setObjectName("title");
        title->setGeometry(QRect(130, 50, 160, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font.setPointSize(16);
        title->setFont(font);
        title->setLocale(QLocale(QLocale::English, QLocale::Israel));
        title->setTextFormat(Qt::AutoText);
        title->setWordWrap(true);
        entryName = new QLineEdit(FireArcWithGUI);
        entryName->setObjectName("entryName");
        entryName->setGeometry(QRect(50, 100, 300, 24));
        entryName->setStyleSheet(QString::fromUtf8(""));
        entryName->setCursorMoveStyle(Qt::LogicalMoveStyle);
        shortcut = new QLineEdit(FireArcWithGUI);
        shortcut->setObjectName("shortcut");
        shortcut->setGeometry(QRect(50, 150, 300, 24));
        url = new QLineEdit(FireArcWithGUI);
        url->setObjectName("url");
        url->setGeometry(QRect(50, 200, 300, 24));
        start = new QPushButton(FireArcWithGUI);
        start->setObjectName("start");
        start->setEnabled(true);
        start->setGeometry(QRect(150, 260, 100, 24));
        start->setCheckable(false);
        start->setChecked(false);
        urlRequirment = new QLabel(FireArcWithGUI);
        urlRequirment->setObjectName("urlRequirment");
        urlRequirment->setEnabled(true);
        urlRequirment->setGeometry(QRect(50, 230, 211, 16));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        urlRequirment->setPalette(palette);

        retranslateUi(FireArcWithGUI);

        QMetaObject::connectSlotsByName(FireArcWithGUI);
    } // setupUi

    void retranslateUi(QWidget *FireArcWithGUI)
    {
        FireArcWithGUI->setWindowTitle(QCoreApplication::translate("FireArcWithGUI", "Set Default Search Engine", nullptr));
        title->setText(QCoreApplication::translate("FireArcWithGUI", "Search Engine ", nullptr));
        entryName->setText(QString());
        entryName->setPlaceholderText(QCoreApplication::translate("FireArcWithGUI", "Entry Name", nullptr));
        shortcut->setPlaceholderText(QCoreApplication::translate("FireArcWithGUI", "Shortcut", nullptr));
        url->setPlaceholderText(QCoreApplication::translate("FireArcWithGUI", "Url", nullptr));
        start->setText(QCoreApplication::translate("FireArcWithGUI", "Set As Default", nullptr));
        urlRequirment->setText(QCoreApplication::translate("FireArcWithGUI", "The URL must conatain '%s' for query", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FireArcWithGUI: public Ui_FireArcWithGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIREARCWITHGUI_H
