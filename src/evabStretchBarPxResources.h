#pragma once

namespace evab
{
    /**
     * @brief Vertical progress bar pictogram set
     */
    class VerticalProgressBarTileset
    {
    public:
        /**
         * @brief Gets pictogram for vertical progress bar
         *
         * @param blockType Block type (1=start, 2=middle, 3=end)
         * @param fillNumber Fill level (0-4)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    /**
     * @brief Horizontal progress bar pictogram set
     */
    class HorizontalProgressBarTileset
    {
    public:
        /**
         * @brief Gets pictogram for horizontal progress bar
         *
         * @param blockType Block type (1=start, 2=middle, 3=end)
         * @param fillNumber Fill level (0-4)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    /**
     * @brief Vertical scroll bar pictogram set
     */
    class VerticalScrollBarTileset
    {
    public:
        /**
         * @brief Gets pictogram for vertical scroll bar
         *
         * @param blockType Block type (1=start, 2=middle, 3=end)
         * @param fillNumber Fill level (0-4)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char blockType, unsigned char fillNumber);
    };

    /**
     * @brief Horizontal scroll bar pictogram set
     */
    class HorizontalScrollBarTileset
    {
    public:
        /**
         * @brief Gets pictogram for horizontal scroll bar
         *
         * @param blockType Block type (1=start, 2=middle, 3=end)
         * @param fillNumber Fill level (0-4)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char blockType, unsigned char fillNumber);
    };

};
