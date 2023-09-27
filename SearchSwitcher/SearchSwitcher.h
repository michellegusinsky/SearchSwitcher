#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SearchSwitcher.h"
#include <QString>

class SearchSwitcher : public QMainWindow
{
    Q_OBJECT

public:
    SearchSwitcher(QWidget *parent = nullptr);
    ~SearchSwitcher();

private slots:
    void on_start_clicked();

private:
    void resetWidgets();
    bool isValid(const std::string& entry, const std::string& shortcut, const std::string& url);
    Ui::SearchSwitcher ui;
};
