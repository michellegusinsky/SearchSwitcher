#include "MicrosoftEdgeBrowser.h"
#include "SimulateUserUtility.h"
#include <Windows.h>

bool MicrosoftEdgeBrowser::SelectSearchEngineSettings() const
{
    bool success{ false };

    // Go to privacy, search and services
    success = NavigateViaTab();
    if (success && GoDown() && ClickEnter())
    {
        // Go to Address bar and search
        FindFirstInPage("Address bar ");
        success = NavigateViaTab(1) && ClickEnter();
        // Go to Manage search engines
        success = success && FindFirstInPage("engines") && NavigateViaTab() && ClickEnter();
    }
    return success;
}

bool MicrosoftEdgeBrowser::SetDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const
{
    bool success{ false };

    // Click the 'Add' button to add new search engine
    success = NavigateViaTab(2) && ClickEnter();
    // Fill the Form:
    // fill search engine entry:
    success = success && TypeOnKeyboard(entry.c_str());
    // fill shortcut entry
    success = success && NavigateViaTab() && TypeOnKeyboard(shortcut.c_str());
    // fill url entry:
    success = success && NavigateViaTab() && TypeOnKeyboard(url.c_str());
    // submit the form
    success = success && ClickEnter();

    // Make default
    success = success && FindFirstInPage(url) && GoRight();
    success = success && ClickEnter(); // select the 'More actions' 3 dot button
    Sleep(100);
    success = success && ClickEnter(); // select the 'make default' button

    return success;
}
