#include "ChromeBrowser.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include "SimulateUserUtility.h"

bool ChromeBrowser::SelectSearchEngineSettings() const
{
    bool success{ true };

    success = NavigateViaTab();

    Sleep(500);
    //                          5 down + click enter
    return success && GoDown(_searchEnginePositionFromTopSettings) && ClickEnter();
}

bool ChromeBrowser::SetDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const
{
    bool success{ true };
    std::vector<unsigned short> keyCodes = { VK_TAB };

    for (int i = 0; i < 2 && success; ++i)
    {
        success = ClickKeyOnKeyboard(keyCodes);
    }

    // down drop down list
    TypeOnKeyboard(&(entry.c_str()[0]));
    return success;
}
