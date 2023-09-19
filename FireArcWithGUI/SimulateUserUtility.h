#pragma once
#include <vector>
#include <string>

bool ClickEnter();
bool GoDown(int units = 1);
bool GoUp(int units = 1);
bool GoRight(int units = 1);
bool NavigateViaTab(int units = 1);
bool OpenRunCommandPrompt();
bool FindFirstInPage(const std::string& str);


bool ClickKeyMultipleTimes(unsigned short keyCode, int numberOftimesToClick);
bool ClickKeyOnKeyboard(const std::vector<unsigned short>& keyCodes);
bool ClickKeyOnKeyboard(unsigned short keyCodes);
bool TypeOnKeyboard(const char* text);
