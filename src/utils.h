#ifndef H_UTILS
#define H_UTILS

#include <raylib.h>
#include <math.h>

static inline bool RunAtFPS(float fps)
{
    return floorf(((GetTime()) - floorf(GetTime())) * fps) != floorf(((GetTime() - floorf(GetTime())) * fps)-(GetFrameTime()*fps));
}

#endif