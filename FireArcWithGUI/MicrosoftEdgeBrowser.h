#pragma once
#include "IBrowser.h"
class MicrosoftEdgeBrowser : public IBrowser
{
public:
protected:
	bool SelectSearchEngineSettings() const;
	bool SetDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const;
	const std::string GetAppName() const { return _appName; };
	const int GetSettingsPositionInMenuFromButtom() const { return _settingsPositionFromButtomMenu; }

private:
	const int _searchEnginePositionFromTopSettings{0};
	const int _settingsPositionFromButtomMenu{ 4 };
	const std::string _appName{ "msedge" };
};

