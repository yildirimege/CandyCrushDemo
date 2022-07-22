#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <SDL.h>
#include <vector>
#include <SDL_ttf.h>



enum TextureName // Used to Identify Candy Types.
{
    YELLOW,
    GREEN,
    BLUE,
    RED,
    ORANGE,
    BACKGROUND,
    COUNT
};


/**
 * @brief The SDL_Renderer class used to draw sprites on objects. All class methods will be overloaded
 * for each type.
 */
class SpriteRenderer
{
public:
    /**
     * @brief Draws Background Sprite to the Main Window
     */
    void drawBackground(); //

    /**
     * @brief Draws Candy Sprite to the Object.
     * @param ctype: Candy Type (Enumerated as Colors)
     * @param x: X Coordinate of destination Point (Sprite to be Drawn)
     * @param y: Y Coordinate of destination Point (Sprite to be Drawn)
     */
    void drawCandy(const TextureName& ct, const int& x, const int& y);

    /**
     * @brief Draws the Current Score on a Fixed Position
     * @param score: Player's current score
     */
    void drawScore(const int& score);

    /**
     * @brief Default C-Tor
     */
    SpriteRenderer();

    /**
     * @brief Default D-Tor
     */
    ~SpriteRenderer();

    SDL_Window *window; // Main Window
    SDL_Renderer *renderer; // To call render functions
    std::vector<SDL_Texture*> textures; // To store All Sprites
    TTF_Font *font; // To Display Score.

    std::vector<std::string> texturePaths = {"../assets/blue.png",
                                       "../assets/green.png",
                                       "../assets/orange.png",
                                       "../assets/purple.png",
                                       "../assets/red.png",
                                       "../assets/yellow.png",
                                       "../assets/background.jpg",
                                      };


 private:
     std::unique_ptr<SpriteRenderer> m_RendererManager; // To Call Member Functions via API.

};

struct SDLException;

class MainRenderer : public SpriteRenderer
{


};

#endif // RENDERER_H
