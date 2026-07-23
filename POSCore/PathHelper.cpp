#include "PathHelper.h"
#include <Windows.h>
#include <ShlObj.h>

std::string PathHelper::GetDesktopPath()
{
    PWSTR path = nullptr;

    HRESULT result =
        SHGetKnownFolderPath(
            FOLDERID_Desktop,
            0,
            nullptr,
            &path);

    if (FAILED(result))
    {
        return "";
    }

    std::wstring desktopPath(path);

    CoTaskMemFree(path);

    return std::string(
        desktopPath.begin(),
        desktopPath.end());
}