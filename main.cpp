#include <iostream>
#include <SDL.h>

using namespace std;

struct InitResult {
    SDL_Window *window;
    SDL_Renderer *renderer;
};

InitResult init(){
    InitResult result;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        result.window = nullptr;
        result.renderer = nullptr;
        return result;
    }

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, 0);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        result.window = nullptr;
        result.renderer = nullptr;
        return result;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        result.window = nullptr;
        result.renderer = nullptr;
        return result;
    }

    result.window = window;
    result.renderer = renderer;
    return result;
}

void close(SDL_Window *window, SDL_Renderer *renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y) {
    SDL_Rect dstRect = { x, y, 0, 0 };
    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}

int main(int argc, char** argv){
    int r = 0, g = 0, b = 0;
    bool isRunning = true;
    SDL_Event event;

    InitResult result = init();
    if (result.window == nullptr || result.renderer == nullptr) {
        return 1;
    }
    SDL_Surface* imageSurface = SDL_LoadBMP("image1.bmp");
    if(imageSurface == nullptr){
        cout << "SDL Error:" << SDL_GetError() << endl;
        close(result.window, result.renderer);
        return 1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(result.renderer, imageSurface);
    if(texture == nullptr){
        cout << "SDL Error:" << SDL_GetError() << endl;
        close(result.window, result.renderer);
        return 1;
    }
    SDL_FreeSurface(imageSurface);

    renderTexture(texture, result.renderer, 600, 450);

    while (isRunning){
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_w){
                        r = 255;
                    }
                    if (event.key.keysym.sym == SDLK_a){
                        g = 255;
                    }
                    if (event.key.keysym.sym == SDLK_s){
                        b = 255;
                    }
                    if (event.key.keysym.sym == SDLK_d){
                        r = 0;
                        g = 0;
                        b = 0;
                    }
                    if (event.key.keysym.sym == SDLK_ESCAPE){
                        isRunning = false;
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(result.renderer, r, g, b, 255);
        SDL_RenderClear(result.renderer);
        SDL_RenderPresent(result.renderer);
    }

    close(result.window, result.renderer);
    return 0;
}
