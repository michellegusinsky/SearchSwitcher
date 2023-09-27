#pragma once
#include "IBrowser.h"
class ChromeBrowser : public IBrowser
{
public:
	ChromeBrowser() = default;
protected:
	bool SelectSearchEngineSettings() const;
	bool SetDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const;
	const std::string GetAppName() const { return _appName; };
	const int GetSettingsPositionInMenuFromButtom() const { return _settingsPositionFromButtomMenu; }

private:
	const int _searchEnginePositionFromTopSettings{ 5 };
	const int _settingsPositionFromButtomMenu{ 3 };
	const std::string _appName{ "chrome" };
};

