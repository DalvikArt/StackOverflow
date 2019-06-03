#include "IOHelper.h"

#define GET_STD_IO_HANDLE(x) x == 0 ? GetStdHandle(STD_INPUT_HANDLE) : x == 1 ? GetStdHandle(STD_OUTPUT_HANDLE) : x
#define CLOSE_STD_IO_HANDLE(x,y) x==0 || x==1 ? CloseHandle(y):0;

DWORD Read(HANDLE hFileOrStdIO, void* pBuffer, DWORD dwLen)
{
	HANDLE hFile = GET_STD_IO_HANDLE(hFileOrStdIO);

	DWORD dwBytesRead;
	ReadFile(hFile, pBuffer, 200, &dwBytesRead, NULL);

	CLOSE_STD_IO_HANDLE(hFileOrStdIO, hFile);

	return dwBytesRead;
}

DWORD Write(HANDLE hFileOrStdIO, void* pBuffer, DWORD dwLen)
{
	HANDLE hFile = GET_STD_IO_HANDLE(hFileOrStdIO);

	DWORD dwBytesWritten;
	WriteFile(hFile, pBuffer, dwLen, &dwBytesWritten, NULL);

	CLOSE_STD_IO_HANDLE(hFileOrStdIO, hFile);

	return dwBytesWritten;
}