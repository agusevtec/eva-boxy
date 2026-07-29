#pragma once
namespace evab
{

    /**
     * @brief On/Off pictogram set (2 states)
     */
    class AlbumOnOff
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-1)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 2; ///< Number of pictograms
    };

    /**
     * @brief Rainbowmeter pictogram set (7 states)
     */
    class AlbumRainbowmeter
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-6)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7; ///< Number of pictograms
    };

    /**
     * @brief Fan pictogram set (3 states)
     */
    class AlbumFan
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-2)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 3; ///< Number of pictograms
    };

    /**
     * @brief Battery pictogram set (7 states)
     */
    class AlbumBattery
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-6)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 7; ///< Number of pictograms
    };

    /**
     * @brief Lamp pictogram set (6 states)
     */
    class AlbumLamp
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-5)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 6; ///< Number of pictograms
    };

    /**
     * @brief Progress pictogram set (9 states)
     */
    class AlbumProgress
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-8)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 9; ///< Number of pictograms
    };

    /**
     * @brief Speaker pictogram set (4 states)
     */
    class AlbumSpeaker
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-3)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4; ///< Number of pictograms
    };

    /**
     * @brief Signal pictogram set (4 states)
     */
    class AlbumSignal
    {
    public:
        /**
         * @brief Gets pictogram by index
         *
         * @param aIndex Index (0-3)
         * @return Pointer to pictogram data
         */
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 4; ///< Number of pictograms
    };

    class AlbumRoundmeter
    {
    public:
        static const unsigned char *GetTile(unsigned char aIndex);
        static constexpr unsigned char Count = 13;
    };

}
