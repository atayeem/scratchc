#include "types.h"

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

) {

    Sprite *out = (Sprite*) malloc(sizeof(Sprite));

    out->isStage = false;

    out->name = name;
    out->layerOrder = layerOrder;
    out->draggable = draggable;

    out->costumes = costumes;
    out->sounds = sounds;
    out->pos = pos;

    out->currentCostume = initCurrentCostume;
    out->volume = initVolume;
    out->visible = initVisible;

    return out;
}


Stage *new_Stage(
    Backdrop backdrops[],
    Sound sounds[],
    int initCurrentBackdrop,
    double initVolume

) {

    Stage *out = (Stage*) malloc(sizeof(Stage));

    if (out == NULL) {
        perror("Failed to allocate memory for stage.");
        return NULL;
    }

    out->isStage = true;
    out->name = "Stage";
    out->layerOrder = 0;
    bool draggable = false;

    // variables, lists, broadcasts and blocks are skipped.
    // They will be handled globally.
    out->costumes = backdrops;
    out->sounds = sounds;
    out->pos = (Position) {0, 0, 0, 0};

    out->currentCostume = initCurrentBackdrop;
    out->volume = initVolume;
    out->visible = true;

    return out;
}