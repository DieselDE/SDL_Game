#include <iostream>
#include <SDL.h>

#include "Character.h"

using std::cout, std::endl;

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
SDL_Surface* gForegroundImage = NULL;

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
void switchImage(SDL_Surface* gImage){
    // changes current image
    gCurrentImage = gImage;
}

void projectBattlePlayer(SDL_Surface* gPlayer){
    // adds Player on top of menu ? maybe ?
    gForegroundImage = gPlayer;
}

void projectBattleEnemy(SDL_Surface* gEnemy){
    // adds Enemy on top of menu ? maybe ?
    gForegroundImage = gEnemy;
}

int main(int argc, char* args[]){

    // test out the Character traits
    Character Player;
    Player = Player.create(&Player);
    cout << Player.HP;

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
    gImage1 = SDL_LoadBMP("Battle_Attack.bmp");
    if (gImage1 == NULL){
        printf("Unable to load Battle_Attack.bmp! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // Set int to right image
    int BattleImageState = 0;

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
                    
                    if (e.key.keysym.sym == SDLK_w){
                        // check which image its on and change it, if necesary
                        switch(BattleImageState){
                            case 2: gImage1 = SDL_LoadBMP("Battle_Attack.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 0;
                                    break;

                            case 3: gImage1 = SDL_LoadBMP("Battle_Defend.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 1;
                                    break;

                            default: break;
                        }
                    }

                    else if (e.key.keysym.sym == SDLK_a){
                        // check which image its on and change it, if necesary
                        switch(BattleImageState){
                            case 1: gImage1 = SDL_LoadBMP("Battle_Attack.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 0;
                                    break;

                            case 3: gImage1 = SDL_LoadBMP("Battle_Item.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 2;
                                    break;

                            default: break;
                        }
                    }

                    else if (e.key.keysym.sym == SDLK_s){
                        // check which image its on and change it, if necesary
                        switch(BattleImageState){
                            case 0: gImage1 = SDL_LoadBMP("Battle_Item.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 2;
                                    break;

                            case 1: gImage1 = SDL_LoadBMP("Battle_Flee.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 3;
                                    break;

                            default: break;
                        }
                    }

                    else if(e.key.keysym.sym == SDLK_d){
                        // check which image its on and change it, if necesary
                        switch(BattleImageState){
                            case 0: gImage1 = SDL_LoadBMP("Battle_Defend.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 1;
                                    break;

                            case 2: gImage1 = SDL_LoadBMP("Battle_Flee.bmp");
                                    switchImage(gImage1);
                                    BattleImageState = 3;
                                    break;

                            default: break;
                        }
                    }

                    // Dont change this function! Ever!!!
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

                    else if(e.key.keysym.sym == SDLK_F5 && Player.HP == 100){

                        SDL_SetRenderDrawColor(grenderer, 100, 100 , 100, 255);
                        SDL_Rect testRect = {200, 200, 200, 200};
                        SDL_RenderFillRect(grenderer, &testRect);

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
        SDL_BlitSurface(gForegroundImage, NULL, gScreenSurface, NULL);

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
    }

    // Free resources and close SDL
    close();

    return 0;
}
