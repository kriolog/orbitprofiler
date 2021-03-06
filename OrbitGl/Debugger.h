//-----------------------------------
// Copyright Pierric Gimmig 2013-2017
//-----------------------------------
#pragma once

#include "Message.h"
#include <string>
#include <vector>

class Debugger
{
public:
    Debugger();
    ~Debugger();

    void LaunchProcess( const std::wstring & a_ProcessName, const std::wstring & a_Args );
    void MainTick();
    void SendThawMessage();

protected:
    void DebuggerThread( const std::wstring & a_ProcessName, const std::wstring & a_Args );

private:
    OrbitWaitLoop     m_WaitLoop;
    std::atomic<bool> m_LoopReady;
    DWORD             m_ProcessID;
};