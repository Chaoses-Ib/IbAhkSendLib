﻿#pragma once
#include <detours/detours.h>
#include <IbWinCppLib/WinCppLib.hpp>
using ib::Byte;

constexpr int debug = ib::debug_runtime;

ib::DebugOStream<> DebugOStream() {
    return { L"IbAhkSendLib: " };
}

template<typename T>
LONG IbDetourAttach(_Inout_ T* ppPointer, _In_ T pDetour) {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach((void**)ppPointer, pDetour);
    return DetourTransactionCommit();
}

template<typename T>
LONG IbDetourDetach(_Inout_ T* ppPointer, _In_ T pDetour) {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach((void**)ppPointer, pDetour);
    return DetourTransactionCommit();
}