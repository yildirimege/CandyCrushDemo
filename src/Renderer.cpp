#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>
#include <list>
#include <sstream>

#include "Renderer.h"

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

struct SDLException : public std::exception
{
    std::string message;

    SDLException(const std::string& error) : message(error) {};
};

SpriteRenderer::SpriteRenderer() : window(nullptr), renderer(nullptr), font(nullptr)
{
    std::ostringstream errorMessage;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) // Can not init SDL objects
    {
        errorMessage << "Could not Initialize SDL World, Message: " << SDL_GetError();
        throw new SDLException(errorMessage.str());
    }

    window = SDL_CreateWindow("Hello King!", 100, 100,WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
        errorMessage << "Could not create main window! Message: " << SDL_GetError();
        throw new SDLException(errorMessage.str());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // TODO: Play With Flags
    if(renderer == nullptr)
    {
        errorMessage << "Could not create Renderer! Message: " << SDL_GetError();
        throw new SDLException(errorMessage.str());
    }

    for (int i = 0; i < static_cast<int>(TextureName::COUNT); ++i) // Load all textures. Only 7 textures can exists in our case, 6 candies and 1 background.
    {

    }
}

SpriteRenderer::~SpriteRenderer()
{
    TTF_CloseFont(font); // Close the font file

    for (auto& texture : textures)
    {
        std::free(texture); // Free the texture pointer
    }
    textures.clear(); // Delete the vector

    if(renderer != nullptr) SDL_DestroyRenderer(renderer); // Destroy the renderer if exists.
    if(window != nullptr) SDL_DestroyWindow(window); // Destroy the Window if exists.

}
void SpriteRenderer::drawBackground()
{
    SDL_RenderCopy(renderer, textures[TextureName::BACKGROUND], NULL, NULL);
}

void SpriteRenderer::drawCandy(const TextureName& ct, const int& x, const int& y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;

    SDL_RenderCopy(renderer, textures[ct], NULL, &dst);
}

void SpriteRenderer::drawScore(const int& score)
{
    SDL_Color col;
    col.r = col.g = col.b = 255; // White Text
    col.a = 255; // %100 Opacity
    SDL_Surface *surf = TTF_RenderText_Blended(font, std::to_string(score).c_str(), col);

    if(surf == nullptr) return; // TODO: Custom Exception
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
    if(tex==nullptr) return; // TODO: Custom Exception

    SDL_FreeSurface(surf); // Free Surface object.

    SDL_Rect dst;
    dst.x = 100; // TODO: Check Score Position Manually, currently has random coordinates.
    dst.y = 100;

    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, tex, NULL, &dst); // Draw the text

    SDL_DestroyTexture(tex); // Free  the texture memory.

}


