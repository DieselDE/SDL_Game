#include <iostream>
#include <SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

// The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

// The images
SDL_Surface* gImage1 = NULL;
SDL_Surface* gImage2 = NULL;

// Current displayed image
SDL_Surface* gCurrentImage = NULL;

// Time delay in milliseconds
const int KEY_DELAY = 100;

// Last time a key action occurred
Uint32 lastKeyPressTime = 0;

// Free resources and shut down SDL
void close(){
    // Deallocate surfaces
    SDL_FreeSurface(gImage1);
    SDL_FreeSurface(gImage2);

    // Destroy window
    SDL_DestroyWindow(gWindow);

    // Quit SDL subsystems
    SDL_Quit();
}

// Switches the displayed image
void switchImage(){
    if (gCurrentImage == gImage1)
        gCurrentImage = gImage2;
    else
        gCurrentImage = gImage1;
}

int main(int argc, char* args[]){

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Create window
    gWindow = SDL_CreateWindow("Image Switcher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (gWindow == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Switch to fullscreen mode
    SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);

    // Get window surface
    gScreenSurface = SDL_GetWindowSurface(gWindow);

    SDL_Renderer *grenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    if (!grenderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    // Load images
    gImage1 = SDL_LoadBMP("image1.bmp");
    if (gImage1 == NULL){
        printf("Unable to load image1.bmp! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gImage2 = SDL_LoadBMP("image2.bmp");
    if (gImage2 == NULL){
        printf("Unable to load image2.bmp! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Set the initial image to display
    gCurrentImage = gImage1;

    // Event handler
    SDL_Event e;

    // Loop tag
    bool quit = false;

    // While application is running
    while (!quit){
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0){
            // User requests quit
            if (e.type == SDL_QUIT){
                quit = true;
            }
            // Handle key press events
            else if (e.type == SDL_KEYDOWN){
                // Get the current time
                Uint32 currentTime = SDL_GetTicks();

                // Check if enough time has passed since the last key action
                if (currentTime - lastKeyPressTime >= KEY_DELAY){
                    // Check if the 's' key was pressed
                    if (e.key.keysym.sym == SDLK_s){
                        switchImage();
                    }

                    else if(e.key.keysym.sym == SDLK_F4){

                        SDL_SetRenderDrawColor(grenderer, 197, 22, 5, 255);   
                        SDL_RenderClear(grenderer);
                        SDL_SetRenderDrawColor(grenderer, 145, 200, 228, 255);

                        SDL_Rect foregroundRect1 = {470, 100, 560, 200}, 
                                 foregroundRect2 = {470, 580, 260, 200},
                                 foregroundRect3 = {0, 0, 200, 200},
                                 foregroundRect4 = {0, 560, 200, 300};

                        SDL_RenderFillRect(grenderer, &foregroundRect1);
                        SDL_RenderFillRect(grenderer, &foregroundRect2);

                        SDL_SetRenderDrawColor(grenderer, 0, 0, 0, 200);

                        SDL_RenderFillRect(grenderer, &foregroundRect3);
                        SDL_RenderFillRect(grenderer, &foregroundRect4);

                        SDL_RenderPresent(grenderer);
                    }

                    else if(e.key.keysym.sym == SDLK_ESCAPE){
                        quit = true;
                    }

                    // Update the last key press time
                    lastKeyPressTime = currentTime;
                }
            }
        }

        // Apply the current image to the screen
        SDL_BlitSurface(gCurrentImage, NULL, gScreenSurface, NULL);

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
    }

    // Free resources and close SDL
    close();

    return 0;
}
