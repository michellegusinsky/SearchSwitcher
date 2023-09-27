#include "SearchSwitcher.h"
#include "MicrosoftEdgeBrowser.h"
#include <regex>


SearchSwitcher::SearchSwitcher(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.urlRequirment->setVisible(false);
}

SearchSwitcher::~SearchSwitcher()
{}

void SearchSwitcher::on_start_clicked()
{
    resetWidgets();
    QString entryName = ui.entryName->text();
    QString shortcut = ui.shortcut->text();
    QString url = ui.url->text();

    if (isValid(entryName.toStdString(), shortcut.toStdString(), url.toStdString()))
    {
        MicrosoftEdgeBrowser msEdge;
        msEdge.ChangeDefaultSearchEngine(entryName.toStdString(), shortcut.toStdString(), url.toStdString());
    }
}

void SearchSwitcher::resetWidgets()
{
    ui.entryName->setStyleSheet("border: 1px solid black");
    ui.shortcut->setStyleSheet("border: 1px solid black");
    ui.url->setStyleSheet("border: 1px solid black");
    ui.urlRequirment->setVisible(false);
}

bool SearchSwitcher::isValid(const std::string& entry, const std::string& shortcut, const std::string& url)
{
    bool isValid{ true };
    if (entry.empty() )
    {
        ui.entryName->setStyleSheet("border: 1px solid red");
        isValid = false;
    }
    if (shortcut.empty())
    {
        ui.shortcut->setStyleSheet("border: 1px solid red");
        isValid = false;
    }
    if (url.empty())
    {
        ui.url->setStyleSheet("border: 1px solid red");
        isValid = false;
    }
    if (url.find("%s") == std::string::npos)
    {
        // URL with %s in place of query
        ui.urlRequirment->setVisible(true);
        isValid = false;
    }
    return isValid;
}
