#ifndef __UTILS_H__
#define __UTILS_H__
#include <math.h>
#include <stdio.h>
static inline PointF positionUpdateIntoCircularMovenent()
{
    PointF this = {0};
    this.x = sinf(glfwGetTime()) * 40.f - 40;
    this.y = cosf(glfwGetTime()) * 40.f - 40;
    return this;
}

static inline void printFPS(Graphics this, double deltaTime)
{
    // needed for rolling average
    static double currentFPS;

    currentFPS = (currentFPS + 1 / deltaTime) / 2;
    {
        char text[1000] = {0};
        snprintf(text, 1000, "fps: %d", (int)floor(currentFPS));
        graphicsPrintString(this, (PointI){100, 0}, text, (Color){0, 0xff, 0xff});
    }
}

static inline double getDeltaTime()
{
    static double lastUpdate = 0;

    double deltaTime = glfwGetTime() - lastUpdate;
    lastUpdate = glfwGetTime();

    return deltaTime;
}

#endif