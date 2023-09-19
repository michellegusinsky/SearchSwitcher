#include "IBrowser.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include "SimulateUserUtility.h"

bool IBrowser::ChangeDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const
{
    if (!OpenBrowser())
    {
        std::cerr << "ChangeDefaultSearchEngine: " << "Browser failed to open" << std::endl;

        return false;
    }

    Sleep(1000);

    if (!OpenBrowserSettings())
    {
        std::cerr << "ChangeDefaultSearchEngine: " << "Settings in browser failed to open" << std::endl;

        return false;
    }

    Sleep(1000);

    if (!SelectSearchEngineSettings())
    {
        std::cerr << "ChangeDefaultSearchEngine: " << "Search Engine Settings failed to select" << std::endl;
        return false;
    }

    if (!SetDefaultSearchEngine(entry, shortcut, url))
    {
        std::cerr << "ChangeDefaultSearchEngine: " << "Search Engine failed to select as default" << std::endl;
        return false;
    }
    
    return true;
}

bool IBrowser::OpenBrowser() const
{
    if (GetAppName().empty())
    {
        std::cerr << "OpenBrowser:  app name is empty." << std::endl;
        return false;
    }

    // Simulate user open the 'Run' Command Prompt
    if (!OpenRunCommandPrompt())
    {
        std::cerr << "OpenBrowser:  Run Command Prompt failed to open." << std::endl;
        return false;
    }
    Sleep(500); // wait until the 'Run' app will open
    
    if (!TypeOnKeyboard(GetAppName().c_str()))
    {
        std::cerr << "OpenBrowser:  Type "<< GetAppName() << " in Run Command Prompt failed." << std::endl;
        return false;
    }
    
    return ClickEnter();
}

bool IBrowser::OpenBrowserSettings() const
{
    bool success{ false };
    std::vector<unsigned short> keyCodes = { VK_MENU, 'F' }; // shortcut to open 3 dots menu

    if (ClickKeyOnKeyboard(keyCodes))
    {
        success = GoUp(GetSettingsPositionInMenuFromButtom()) && ClickEnter();
    }

    return success;
}
