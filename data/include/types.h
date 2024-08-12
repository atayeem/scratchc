#ifndef _S_TYPES_H
#define _S_TYPES_H

#include "includes.h"

// Struct definitions

typedef struct {
    double x;
    double y;
    double size;
    double direction;
    SDL_Audio
} Position;

typedef struct {
    char *name;
    int bitmapResolution;
    char *dataFormat;
    char *file;
    double rotationCenterX;
    double rotationCenterY;
} Costume;

typedef struct {
    char *name;
    char *dataFormat;
    int rate;
    int sampleCount;
} Sound;

typedef struct {
    bool isStage;
    char *name;
    int layerOrder;
    bool draggable;

    // variables, lists, broadcasts and blocks are skipped.
    // They will be handled globally.
    Costume *costumes;
    Sound *sounds;
    Position pos;

    int currentCostume;
    double volume;
    bool visible;
} Target;

typedef Target Sprite;
typedef Target Stage;

// This is a macro because there is no 
// difference between these two things.
#define Backdrop Costume

Sprite *new_Sprite(
    char *name,
    int layerOrder,
    bool draggable,

    Costume costumes[],
    Sound sounds[],
    Position pos,

    int initCurrentCostume,
    double initVolume,
    bool initVisible
);

Stage *new_Stage(
    Backdrop backdrops[],
    Sound sounds[],
    int initCurrentBackdrop,
    double initVolume
);


#endif