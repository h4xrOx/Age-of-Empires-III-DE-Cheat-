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