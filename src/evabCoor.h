#ifndef EVAB_COOR_H_
#define EVAB_COOR_H_

namespace evab
{

  /**
   * @brief Coordinate structure for positions and sizes on screen
   */
  struct Coor
  {
    unsigned char X, Y;  ///< X and Y coordinates
    /**
     * @brief Constructor with default values
     * 
     * @param x X coordinate (default 0)
     * @param y Y coordinate (default 0)
     */
    Coor(int x = 0, int y = 0);
  };

}
#endif
