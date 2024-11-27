#pragma once

#ifdef OPENCVLIB_EXPORTS
#define OPENCVLIB_API __declspec(dllexport)
#else
#define OPENCVLIB_API __declspec(dllimport)
#endif

extern "C" {
    OPENCVLIB_API void processImage(const char* imagePath);
}

