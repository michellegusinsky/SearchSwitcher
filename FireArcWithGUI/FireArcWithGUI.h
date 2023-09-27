#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FireArcWithGUI.h"
#include <QString>

class FireArcWithGUI : public QMainWindow
{
    Q_OBJECT

public:
    FireArcWithGUI(QWidget *parent = nullptr);
    ~FireArcWithGUI();

private slots:
    void on_start_clicked();

private:
    void resetWidgets();
    bool isValid(const std::string& entry, const std::string& shortcut, const std::string& url);
    Ui::FireArcWithGUI ui;
};
