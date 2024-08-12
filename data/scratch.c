typedef void s_hat;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <pthread.h>
#include <stdbool.h>

#define forever while(true)

#define exec(x, id) \
        pthread_create(id, NULL, x, NULL)

#define await(id) \
        pthread_join(id, NULL)



/**
 * Datatypes:
 * - s_costume
 * - s_sound
 * 
 * - 

*/

