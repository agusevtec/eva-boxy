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
     * @param aCount Total number of items
     */
    WindowAlgorithmBase(unsigned char aCount = 0);

    /**
     * @brief Pure virtual method to select an item
     *
     * @param aIndex Index to select
     */
    virtual void Select(unsigned char aIndex) = 0;

    /**
     * @brief Gets the currently selected item index
     *
     * @return Selected index, or -1 if empty
     */
    signed short Selected();

    /**
     * @brief Gets the total number of items
     *
     * @return Total number of items
     */
    unsigned char Count();

    /**
     * @brief Gets the window size
     *
     * @return Window size
     */
    unsigned char WindowSize();

  protected:
    /**
     * @brief Calculates the visual index of an item in the current window
     *
     * @param aPosition Absolute position of the item
     * @return Visual index, or -1 if not visible
     */
    signed char indexInWindow(unsigned char aPosition);

    /**
     * @brief Sets the total number of items
     *
     * @param aCount Total number of items
     */
    void setCount(unsigned char aCount);

    /**
     * @brief Resizes the window
     *
     * @param aWindowSize New window size
     */
    void setWindowSize(unsigned char aWindowSize);

  protected:
    unsigned char mSelected;    ///< Currently selected index
    unsigned char mCount;       ///< Total number of items
    unsigned char mWindowStart; ///< Start of the current window
    unsigned char mWindowSize;  ///< Window size
  };

  /**
   * @brief Flip-page navigation algorithm
   *
   * Pages are flipped in chunks of window size.
   */
  class FlipWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    using WindowAlgorithmBase::WindowAlgorithmBase;
    /**
     * @brief Selects an item using flip-page navigation
     *
     * @param aIndex Index to select
     */
    void Select(unsigned char aIndex) override;
  };

  /**
   * @brief Scroll navigation algorithm
   *
   * Scrolls the window to keep selection visible.
   */
  class ScrollWindowAlgorithm : public WindowAlgorithmBase
  {
  public:
    using WindowAlgorithmBase::WindowAlgorithmBase;
    /**
     * @brief Selects an item using scroll navigation
     *
     * @param aIndex Index to select
     */
    void Select(unsigned char aIndex) override;
  };

}
