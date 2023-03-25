@echo off

set USER=%USERNAME%
set APPDATA=%LOCALAPPDATA%
set cheat_FOLDER="AoE3_cheat"
set cheat_DLL="AoE3_cheat.dll"
set CONFIG_TXT="configuration.txt"
set USER_CFG="user.cfg"
set USER_CON="user.con"

xcopy /s /y %cheat_DLL% %APPDATA%\Microsoft Games\Age of Empires III DE\bin\cheats\%cheat_FOLDER%\%cheat_DLL%
xcopy /s /y %CONFIG_TXT% %APPDATA%\Microsoft Games\Age of Empires III DE\bin\cheats\%cheat_FOLDER%\%CONFIG_TXT%
xcopy /s /y %USER_CFG% %APPDATA%\Microsoft Games\Age of Empires III DE\Startup\%USER_CFG%
xcopy /s /y %USER_CON% %APPDATA%\Microsoft Games\Age of Empires III DE\Startup\%USER_CON%

echo cheat installation complete!
pause
