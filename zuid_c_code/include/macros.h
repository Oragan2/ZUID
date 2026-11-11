//
// Created by antoi on 11/11/2026.
//

#ifndef ZUID_MACROS_H
#define ZUID_MACROS_H

#ifdef _WIN32
  // If we are compiling the DLL, export. If someone else is using it, import.
  #ifdef BUILDING_ZUID_DLL
    #define ZUID_API __declspec(dllexport)
  #else
    #define ZUID_API __declspec(dllimport)
  #endif
#else
  #define ZUID_API
#endif

#endif //ZUID_MACROS_H
