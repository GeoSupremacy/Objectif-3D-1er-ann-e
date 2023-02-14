#include "WebClient.h"
#include "WebCallback.h"
#pragma comment (lib,"urlmon.lib")
#include <urlmon.h>
#include "Exception.h"
#include "Process.h"


#pragma region constructor/destructor
Core::Net::WebClient::WebClient(const Url& _url)
{
	url = _url;
}
Core::Net::WebClient::WebClient(const WebClient& _copy)
{
	url = _copy.url;
}
#pragma endregion constructor/destructor
#pragma region methods
void Core::Net::WebClient::DownloadFile(const PrimitiveType::FString& _pathFile)
{
	const std::wstring _urlWstr = url.Path().ToWString();
	const LPCWSTR _uri = _urlWstr.c_str();
	const std::wstring  _pathWstr = _pathFile.ToWString();
	const LPCWSTR _path = _pathWstr.c_str();
	WebCallback* _callback = new WebCallback();
	_callback->OnDownloadProgress.AddDynamic(&OnDownloadProgress, &Action<float>::Invoke);

	const HRESULT _result = URLDownloadToFile(nullptr, _uri, _path, 0, nullptr);
	if (!_result) throw Exception("[WebClient] => url doesn't valid");
	else
	{
		
		Diagnostics::Process::Start(_pathFile, "");
	}
}
#pragma endregion methods


