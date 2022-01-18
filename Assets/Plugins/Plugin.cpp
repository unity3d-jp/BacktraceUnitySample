
#if _MSC_VER // this is defined when compiling with Visual Studio
#define EXPORT_API __declspec(dllexport) // Visual Studio needs annotating exported functions with this
#else
#define EXPORT_API // XCode does not need annotating exported functions, so define is empty
#endif

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdexcept>

// ------------------------------------------------------------------------
// Plugin itself


// Link following functions C-style (required for plugins)
extern "C"
{

// The functions we will call from Unity.
//
EXPORT_API int PrintANumber(){
	return 5;
}

EXPORT_API int DivideByZero(int a) {
#pragma warning(suppress: 4723)
	return a / 0;
}

EXPORT_API void Segfault() {
	char* p = 0;
#pragma warning(suppress: 6011)
	fputc(*p, stdout);
}

EXPORT_API void Abrt() {
	abort();
}

EXPORT_API void Hang() {
#ifdef _WIN32
    Sleep(10000);
#else
    sleep(10000);
#endif
	
}

EXPORT_API void CppException() {
#pragma warning(suppress: 4297)
	throw std::runtime_error("Here's a runtime error");
}

} // end of export C block
