#pragma once

// #ifdef ON_SOLAR_ENGINE
//     #ifdef SOLAR_BUILD_DLL 
//         #define SOLAR_API __declspec(dllexport)
//     #else
//         #define SOLAR_API __declspec(dllimport)
//     #endif
// #else
//     #error Support only window
// #endif

#if ON_SOLAR_ENGINE
    #if DYNAMIC_BUILD
        #ifdef _MSC_VER
            #define SOLAR_API __declspec(dllexport)
        #else
            #define SOLAR_API __attribute__((visibility)("default"))
        #endif
    #else 
        #define SOLAR_API
    #endif
#else
    #if DYNAMIC_IMPORT
        #ifdef _MSC_VER
            #define SOLAR_API __declspec(dllimport)
        #else
            #define SOLAR_API
        #endif
    #else 
        #define SOLAR_API
    #endif
#endif