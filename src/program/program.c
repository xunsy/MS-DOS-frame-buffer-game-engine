#include "program.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "core/input/input.h"
#include "utils/utils.h"
#include "assetManager/assetManager.h"

#define __STATIC_ALLOC_IMPLEMENTATION__
#include "core/stackAllocator/staticAlloc.h"

#define ARRAY_MALLOC allocStatic
#define ARRAY_REALLOC reallocStatic
#define __UNIVERSAL_ARRAY_IMPLEMENTATION__
#include "core/array/array.h"

#define STBI_MALLOC(sz) allocStatic(sz)
#define STBI_REALLOC(p, newsz) reallocStatic(p, newsz)
#define STBI_FREE(p) freeStatic(p)

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Program programCreate()
{
    staticAllocatorInit();
    Program this = {0};
    this.graphics = graphicsCreate();

    spritesLoad(this.sprites);

    this.level = levelCreate(this.graphics, this.sprites);
    this.mainMenu = mainMenuCreate(this.graphics, this.sprites);

    return this;
}

void programMainLoop(Program this)
{
    mainMenuUpdate(this.mainMenu);
    levelMainLoop(this.level);
}

void programDestroy(Program this)
{
}
