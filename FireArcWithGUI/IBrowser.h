#pragma once
#include <string>
class IBrowser
{
public:
	virtual bool ChangeDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const;
	virtual ~IBrowser(){}
protected:
	bool OpenBrowser() const;
	virtual bool OpenBrowserSettings() const;
	virtual bool SelectSearchEngineSettings() const = 0;
	virtual bool SetDefaultSearchEngine(const std::string& entry, const std::string& shortcut, const std::string& url) const = 0;
	virtual const std::string GetAppName() const = 0;
	virtual const int GetSettingsPositionInMenuFromButtom() const = 0;
};

