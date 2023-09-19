#include "SimulateUserUtility.h"
#include <windows.h>
#include <iostream>

bool ClickEnter()
{
    return ClickKeyOnKeyboard(VK_RETURN);
}

bool GoDown(int units)
{
    return ClickKeyMultipleTimes(VK_DOWN, units);
}

bool GoUp(int units)
{
    return ClickKeyMultipleTimes(VK_UP, units);
}

bool GoRight(int units)
{
    return ClickKeyMultipleTimes(VK_RIGHT, units);
}

bool NavigateViaTab(int units)
{
    return ClickKeyMultipleTimes(VK_TAB, units);
}

bool OpenRunCommandPrompt()
{
    std::vector<unsigned short> keyCodes = { VK_LWIN, 'R' }; // 'Win' + ''R' is the shortcut to open run command prompt
    return ClickKeyOnKeyboard(keyCodes);;
}

bool FindFirstInPage(const std::string& str)
{
    bool success{ true };

    std::vector<unsigned short> keyCodes = { VK_CONTROL, 'F' }; // shortcut to open 3 dots menu
    success = ClickKeyOnKeyboard(keyCodes);
    Sleep(500);

    TypeOnKeyboard(str.c_str());
    Sleep(500);

    ClickEnter();
    Sleep(100);

    ClickKeyOnKeyboard(VK_ESCAPE);

    return success;
}

bool ClickKeyMultipleTimes(unsigned short keyCode, int numberOftimesToClick)
{
    bool success{ true };

    for (int i = 0; i < numberOftimesToClick && success; ++i)
    {
        success = ClickKeyOnKeyboard(keyCode);
    }
    return success;
}

/// <summary>
/// click means press and release keys on keyboard
/// </summary>
bool ClickKeyOnKeyboard(const std::vector<unsigned short>& keyCodes)
{
    const unsigned int numberOfKeyEvents = keyCodes.size() * 2; // for each key code press event + release event 
    INPUT* inputEvents = new INPUT[numberOfKeyEvents]; // allocating input events array
    ZeroMemory(inputEvents, sizeof(INPUT) * numberOfKeyEvents); // clear the memory in input event array
    
    // fill into the input events array all the requested events
    for (int i = 0; i < keyCodes.size(); ++i)
    {
        // initialize INPUT struct
        inputEvents[i].ki.wScan = 0;
        inputEvents[i].ki.time = 0;
        inputEvents[i].ki.dwExtraInfo = 0;
        // set keyboard event for the press event and release event
        inputEvents[i].type = INPUT_KEYBOARD;
        inputEvents[numberOfKeyEvents - i - 1].type = INPUT_KEYBOARD;
        // set the press key event
        inputEvents[i].ki.wVk = keyCodes.at(i); // virtual-key code for the key
        inputEvents[i].ki.dwFlags = 0; // 0 for key press
        // set the release key event
        inputEvents[numberOfKeyEvents - i - 1].ki.wVk = keyCodes.at(i);
        inputEvents[numberOfKeyEvents - i - 1].ki.dwFlags = KEYEVENTF_KEYUP;
    }
    UINT uSent = SendInput(numberOfKeyEvents, inputEvents, sizeof(INPUT));
    delete[] inputEvents;
    if (uSent != numberOfKeyEvents)
    {
        std::cerr << "ClickKeyOnKeyboard: "<< uSent << " out of " << numberOfKeyEvents << " input events are sent." << std::endl;
        return false;
    }
    return true;
}

/// <summary>
/// click means press and release key on keyboard
/// </summary>
bool ClickKeyOnKeyboard(unsigned short keyCode)
{
    const unsigned int numberOfKeyEvents = 2; // key code press event + release event 
    INPUT inputEvents[2]; // allocating input events array
    ZeroMemory(inputEvents, sizeof(INPUT) * numberOfKeyEvents); // clear the memory in input event array

    // initialize INPUT struct
    inputEvents[0].ki.wScan = 0;
    inputEvents[0].ki.time = 0;
    inputEvents[0].ki.dwExtraInfo = 0;
    // set keyboard event for the press event and release event
    inputEvents[0].type = INPUT_KEYBOARD;
    inputEvents[1].type = INPUT_KEYBOARD;
    // set the press key event
    inputEvents[0].ki.wVk = keyCode; // virtual-key code for the key
    inputEvents[0].ki.dwFlags = 0;// for key press
    // set the release key event
    inputEvents[1].ki.wVk = keyCode;
    inputEvents[1].ki.dwFlags = KEYEVENTF_KEYUP | KEYEVENTF_EXTENDEDKEY;
    UINT uSent = SendInput(numberOfKeyEvents, inputEvents, sizeof(INPUT));
    if (uSent != numberOfKeyEvents)
    {
        std::cerr << "ClickKeyOnKeyboard: " << uSent << " out of " << numberOfKeyEvents << " input events are sent." << std::endl;
        return false;
    }
    return true;
}

bool TypeOnKeyboard(const char* text) {
    INPUT ip[4] = {};

    for (; *text; text++) {
        int startInput = 1; // Assume 1 keyup and keydown pair.
        int nInputs = 2;

        if (HIBYTE(VkKeyScan(*text)) == 1) { // Set up SHIFT key and release
            startInput = 0;
            nInputs = 4;

            ip[0].type = INPUT_KEYBOARD;
            ip[0].ki.dwFlags = KEYEVENTF_SCANCODE;
            ip[0].ki.wScan = MapVirtualKey(VK_LSHIFT, 0);

            ip[3] = ip[0];
            ip[3].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        }

        ip[1].type = INPUT_KEYBOARD;  // Set up key and release
        ip[1].ki.wScan = MapVirtualKey(LOBYTE(VkKeyScan(*text)), 0);
        ip[1].ki.dwFlags = KEYEVENTF_SCANCODE;

        ip[2] = ip[1];
        ip[2].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

        
        UINT uSent = SendInput(nInputs, &ip[startInput], sizeof(INPUT));
        if (uSent != nInputs)
        {
            std::cerr << "Type: " << uSent << " out of " << nInputs << " input events are sent." << std::endl;
            return false;
        }
        Sleep(100);
    }
    Sleep(800);
    return true;
}
