#pragma once

namespace evab
{

  /**
   * @brief Abstract base class for window navigation algorithms
   * 
   * Provides common functionality for list box navigation strategies.
   */
  class WindowAlgorithmBase
  {
  public:
    /**
     * @brief Constructor for window algorithm base
     */
    WindowAlgorithmBase();
    
    /**
     * @brief Pure virtual method to select an item
     * 
     * @param aIndex Index to select
     */
    virtual void Select(signed char aIndex) = 0;
    
    /**
     * @brief Gets the currently selected item index
     * 
     * @return Selected index, or -1 if empty
     */
    signed char Selected();
    
    /**
     * @brief Gets the total number of items
     * 
     * @return Total number of items
     */
    signed char Count();
    
    /**
     * @brief Gets the window size
     * 
     * @return Window size
     */
    signed char WindowSize();

  protected:
    /**
     * @brief Calculates the visual index of an item in the current window
     * 
     * @param aPosition Absolute position of the item
     * @return Visual index, or -1 if not visible
     */
    signed char indexInWindow(signed char aPosition);
    
    /**
     * @brief Sets the total number of items
     * 
     * @param Count Total number of items
     */
    void setCount(signed char Count);
    
    /**
     * @brief Resizes the window
     * 
     * @param aWindowSize New window size
     */
    void resizeWindow(signed char aWindowSize);

  protected:
    signed char mSelected;     ///< Currently selected index
    signed char mCount;        ///< Total number of items
    signed char mWindowStart;  ///< Start of the current window
    signed char mWindowSize;   ///< Window size
  };

  /**
   * @brief Flip-page navigation algorithm
   * 
   * Pages are flipped in chunks of window size.
   */
  class FlipWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    /**
     * @brief Selects an item using flip-page navigation
     * 
     * @param aIndex Index to select
     */
    void Select(signed char aIndex) override;
  };

  /**
   * @brief Scroll navigation algorithm
   * 
   * Scrolls the window to keep selection visible.
   */
  class ScrollWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    /**
     * @brief Selects an item using scroll navigation
     * 
     * @param aIndex Index to select
     */
    void Select(signed char aIndex) override;
  };

}
