#pragma once 

#include<memory>
#include<stdint.h>
#include<set>
#include<random>
#include<limits>
#include<vector>
#include<string>
#include<bitset>
#include<cassert>
#include<assert.h>
#include<sstream>
#include<istream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<map>
#include<stack>

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL 
#endif

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

#ifdef SOLAR_ENABLE_ASSERTS
	#define SOLAR_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SOLAR_CORE_ASSERT(x, ...) { if(!(x)) { CORE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SOLAR_ASSERT(x, ...)
	#define SOLAR_CORE_ASSERT(x, ...)
#endif

#define SOLAR_EVENT_BIND(function) std::bind(&function, this, std::placeholders::_1)

#define DYNAMIC_CAST(value, type) std::dynamic_pointer_cast<type>(value)

namespace Solar
{
    template<typename T> using Ref = std::shared_ptr<T>;
    template<typename T> using Scope = std::unique_ptr<T>;
}