![image](https://user-images.githubusercontent.com/65768277/227748813-0ea61921-ce93-452a-b71a-3143fd20c3ea.png)
# Age-of-Empires-III-DE-Cheat- by h4xr0x 
- for more cheats join us on discord https://discord.gg/EYCBURUPcm
Age of Empires III: Definitive Edition Mod with Fog of War Remover and Custom GUI.

# Create a new Visual Studio project and select "Win32 Console Application".
- In the project properties, set the "Configuration Type" to "Dynamic Library (.dll)". 

# Create a new header file called "FogOfWarRemover.h".
```
#FogOfWarRemover.h
#pragma once

#include "API/AdvancedGenieHook.h"

class FogOfWarRemover : public AGH::AdvancedGenieHook
{
public:
    virtual bool OnChatMessage(int playerID, const char* message) override;
};

#FogOfWarRemover.cpp
#include "FogOfWarRemover.h"

bool FogOfWarRemover::OnChatMessage(int playerID, const char* message)
{
    if (strcmp(message, "/fow") == 0)
    {
        cegvisvisible(true);
        return true;
    }
    return false;
}

#dllmain.cpp
#include "stdafx.h"
#include "FogOfWarRemover.h"

FogOfWarRemover cheat;

BOOL APIENTRY DllMain(HcheatULE hcheatule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        cheat.Install();
        break;
    case DLL_PROCESS_DETACH:
        cheat.Uninstall();
        break;
    }
    return TRUE;
}
```
# stdafx.h -create a new header file called "stdafx.h
```
#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>


#include <SDKDDKVer.h>
```
# targetver.h -create a new header file called "targetver.h"
```
#pragma once

#include <SDKDDKVer.h>
 
#SDKDDKVer.h -create "SDKDDKVer.h" using Microsoft Visual Studio. This code specifies that the cheat is targeting Windows 7 or later by setting the _WIN32_WINNT macro to 0x0601. This will ensure that the cheat can take advantage of features and APIs that are available in newer versions of Windows.
#pragma once

// Target Windows 7 or later
#include <winsdkver.h>
#define _WIN32_WINNT 0x0601
#include <sdkddkver.h>
```

# camera.h -Create a file called camera.h
```
// In Camera.h
class Camera
{
public:
    void ZoomIn();
    void ZoomOut();
private:
    float m_zoomLevel;
    float m_zoomSpeed;
    const float m_minZoomLevel = 60.0f;
    const float m_maxZoomLevel = 500.0f;
};

// In Camera.cpp
void Camera::ZoomIn()
{
    m_zoomLevel += m_zoomSpeed;
    if (m_zoomLevel > m_maxZoomLevel) {
        m_zoomLevel = m_maxZoomLevel;
    }
}

void Camera::ZoomOut()
{
    m_zoomLevel -= m_zoomSpeed;
    if (m_zoomLevel < m_minZoomLevel) {
        m_zoomLevel = m_minZoomLevel;
    }
}
```
Note:> using the `bind` and `alias` commands. You can also include additional configuration settings in the "user.con" file to customize the game's graphics, audio, and other settings.

# user.con -create a "user.con" file
```
// In user.con
alias +zoomin "camera_zoomin"
alias -zoomin ""
alias +zoomout "camera_zoomout"
alias -zoomout ""

// In the project code
void OnChatMessage(const char* message)
{
    if (strcmp(message, "camera_zoomin") == 0) {
        Camera::GetInstance().ZoomIn();
    }
    else if (strcmp(message, "camera_zoomout") == 0) {
        Camera::GetInstance().ZoomOut();
    }
}

// Fog of War Remover
; Remove fog of war when F5 key is pressed
alias "+fogofwar" "cegviscommander"
alias "-fogofwar" "cegviscommander"
bind "F5" "+fogofwar"
cegviscommander()
{
    cegvisvisible true
}

// Bind the F5 key to remove the fog of war
bind "F5" "+fogofwar"

// Bind the mouse wheel to zoom in and out
bind "MOUSEWHEELUP" "+zoomin"
bind "MOUSEWHEELDOWN" "+zoomout"

// Bind the number keys to change perspective to a specific player
bind "1" "+changeperspective 1"
bind "2" "+changeperspective 2"
bind "3" "+changeperspective 3"
bind "4" "+changeperspective 4"
bind "5" "+changeperspective 5"
bind "6" "+changeperspective 6"
bind "7" "+changeperspective 7"
bind "8" "+changeperspective 8"

// Define the aliases for the custom commands
alias +fogofwar "toggle_fogofwar"
alias -fogofwar ""
alias +zoomin "camera_zoomin"
alias -zoomin ""
alias +zoomout "camera_zoomout"
alias -zoomout ""
alias +changeperspective "change_perspective"
alias -changeperspective ""

// Define the implementation of the custom commands
void toggle_fogofwar() {
    // Toggle the fog of war on or off
    // ...
}

void camera_zoomin() {
    // Zoom the camera in
    // ...
}

void camera_zoomout() {
    // Zoom the camera out
    // ...
}

void change_perspective(int playerIndex) {
    // Change the camera's perspective to the specified player
    // ...
}
```
# user.cfg -create a file called "user.cfg"
```
// Enable the C++ cheat
cheat AoE3cheat

// Remove Fog of War when pressing F5
bind "F5" "injectDll NoFogOfWar.dll"

// Set Camera Settings
bind "CTRL+1" "SetCameraPos 0 0"
bind "CTRL+2" "SetCameraPos 0 20"
bind "CTRL+3" "SetCameraPos 20 0"
bind "CTRL+4" "SetCameraPos 20 20"

// Change Perspective to Players 1-8
bind "ALT+1" "CameraToPlayer 1"
bind "ALT+2" "CameraToPlayer 2"
bind "ALT+3" "CameraToPlayer 3"
bind "ALT+4" "CameraToPlayer 4"
bind "ALT+5" "CameraToPlayer 5"
bind "ALT+6" "CameraToPlayer 6"
bind "ALT+7" "CameraToPlayer 7"
bind "ALT+8" "CameraToPlayer 8"

// Set Min and Max Zoom Levels
set minZoomLevel 60
set maxZoomLevel 500


// Set the camera zoom limits
cameraMinZoom 60
cameraMaxZoom 500
minZoomLevel 60
maxZoomLevel 500

// Inject the DLL file
dll AoE3DLL.dll

// Bind the "F5" key to inject the DLL and remove fog of war
bind F5 "+injectDLL; +removeFog"

// Define the "+injectDLL" command
alias "+injectDLL" "dll AoE3DLL.dll"

// Define the "-injectDLL" command
alias "-injectDLL" ""

// Define the "+removeFog" command
alias "+removeFog" "set fogOfWarEnabled false"

// Define the "-removeFog" command
alias "-removeFog" "set fogOfWarEnabled true"

// Set up the ability to switch perspectives
bind 1 "cameraFollow player1"
bind 2 "cameraFollow player2"
bind 3 "cameraFollow player3"
bind 4 "cameraFollow player4"
bind 5 "cameraFollow player5"
bind 6 "cameraFollow player6"
bind 7 "cameraFollow player7"
bind 8 "cameraFollow player8"
```
# Age of Empires III: Definitive Edition
- For Age of Empires III: Definitive Edition, the user.cfg and 
files should be placed in the following directory:

`%USERPROFILE%\Games\Age of Empires 3 DE\Users\NewProfile\`

Replace NewProfile with the name of the profile you use in the game. If you haven't created a profile yet, the folder might not exist, in which case you can create it yourself.

Note:> that %USERPROFILE% is a Windows environment variable that usually points to C:\Users\your_username\. Something like this:

`C:\Users\your_username\Games\Age of Empires 3 DE\Users\NewProfile\`

# Create a file called "configuration.txt

Note:> For Age of Empires III: Definitive Edition, the configuration.txt file should be placed in the same directory as the game's executable file (AoE3DE_s.exe). By default, #this file is located in the following directory:

"C:\Program Files\Steam\steamapps\common\AoE3DE\"

Note:> If you installed the game in a different directory, you should look for the folder where the game's executable file is located and place the configuration.txt file there. 

# configuration.txt -Create a file called configuration.txt
```
game.opt = "-cheat:AoE3_cheat.dll"
user.con = "user.con"
user.cfg = "user.cfg"
```

- The AoE3_cheat.dll from the C++ project should be placed in the game's installation folder, in the "bin" folder

# Install Age of Empires III: DE HACK

# install.bat 
Create a file called "install.bat" should be placed in the folder containing all of the cheat files (i.e., # AoE3_cheat.dll, configuration.txt, user.cfg, and user.con) are located in the same directory as the batch file. When the # batch file is run, it sets the %USER% and %APPDATA% environment variables, and then copies the cheat files to their correct directories.

```
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
```







