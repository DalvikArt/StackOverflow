#pragma once

#include <Windows.h>

DWORD Read(HANDLE hFileOrStdIO, void* pBuffer, DWORD dwLen);

DWORD Write(HANDLE hFileOrStdIO, void* pBuffer, DWORD dwLen);