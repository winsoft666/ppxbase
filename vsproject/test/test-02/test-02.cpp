// test for :
// logging
//
#include "stdafx.h"
#include "base/logging.h"
#include "base/logging_file_sink_win.h"
#include "base/process_util.h"
#include "base/file_util.h"
#include "base/os_ver.h"
#include "base/ini.h"
#include <iostream>
using namespace std;


int main()
{
    ppx::base::LogMessage::AddLogToStream(ppx::base::LoggingFileSinkWin::GetSink(), ppx::base::LS_INFO);

	PPX_LOG(LS_INFO) << "log1";

	PPX_LOG_GLE(LS_INFO) << "LOG2";


    ppx::base::OSVersion osver;
    ppx::base::OSVer ver = osver.GetOsVersion();

    PROCESS_INFORMATION pi;
    //bool  ret = ppx::base::EasyCreateProcess(TEXT("\"C:\\Program Files (x86)\\SteamBox\\SteamBoxFullSetup(12).exe\" /installdir \"C:\Program Files(x86)\SteamBox\\"), &pi);
    bool  ret = ppx::base::EasyCreateProcess(TEXT("C:\\Program Files (x86)\\SteamBox\\SteamBoxFullSetup(12).exe /installdir \"C:\\Program Files(x86)\\SteamBox\\\""), &pi);
    DWORD gle = GetLastError();

    ppx::base::Ini ini;
    ini.SetIniFilePath(TEXT("D:\\test.ini"));
    RECT r;
    bool b = ini.ReadRect(TEXT("app"), TEXT("size"), r);

    ppx::base::tstring str;
    b = ini.ReadString(TEXT("app"), TEXT("name"), str);

    int width;
    width = ini.ReadInt(TEXT("app"), TEXT("namea"), 0);

    ppx::base::RecursiveTerminateProcess(TEXT("F:\\111"), false);

    getchar();
    return 0;
}

