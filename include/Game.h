#ifndef GAME_H
#define GAME_H

#include <sstream>

#include "Renderer.h"
#include "Candy.h"

constexpr int CANDY_TYPES = 6; // To be used as an upper bound in random candy generator.
constexpr int ROWS =9, COLS=9; // 9x9 Grid, same as in the first level of Candy Crush!

class Game
{
public:
    /**
     * @brief C-Tor of Game Object
     * @param renderer : Renderer object which is responsible of Sprite Drawings
     */
    Game(SpriteRenderer &renderer);

    /**
     * @brief Default D-Tor of Game Object.
     */
    ~Game();

    /**
     * @brief Runs the game!
     */
    void run();

};

#endif // CANDY_H
