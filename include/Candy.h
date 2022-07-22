#ifndef CANDY_H
#define CANDY_H

#include "Renderer.h"

constexpr CANDY_WIDTH = 68;
constexpr CANDY_HEIGHT = 55;

/**
 * @brief The Candy class which stores methods and variables for each individual Candy on the board.
 */
class Candy{
 public:

    /**
     * @brief Creates a candy object with given texture at given coordinate.
     */
    void placeCandy(const int& XPos, const int& YPos, TextureName tn);

    //TODO: Add Transformation Functions required for Game Logic, swap, move, destroy etc.

    /**
     * @brief Constructor of Candy Object
     * @param renderer Global Renderer object
     */
    Candy(SpriteRenderer &renderer);

    /**
     * @brief Default Destructor for Candy Object
     */
    ~Candy();
};

#endif // CANDY_H
