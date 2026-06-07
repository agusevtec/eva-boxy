#include <evabElementBase.h>

namespace evab
{
    // Политика ориентации
    struct VerticalPolicy
    {
        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.Y - 2) * 3 + 2;
        }
        
        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X, aPos.Y + aSize.Y - index - 1};
        }
        
        static constexpr unsigned char BLOCK_START = 1;
        static constexpr unsigned char BLOCK_MIDDLE = 2;
        static constexpr unsigned char BLOCK_END = 3;
    };
    
    struct HorizontalPolicy
    {
        static unsigned short CalculateResolution(Coor aSize)
        {
            return 3 + (aSize.X - 2) * 3 + 2;
        }
        
        static Coor GetTilePosition(Coor aPos, Coor aSize, unsigned char index, unsigned char total)
        {
            return {aPos.X + index, aPos.Y};
        }
        
        static constexpr unsigned char BLOCK_START = 1;
        static constexpr unsigned char BLOCK_MIDDLE = 2;
        static constexpr unsigned char BLOCK_END = 3;
    };
    
    // Основной класс
    template<typename TileSet, typename OrientationPolicy>
    class StretchBar : public ElementBase
    {
    public:
        StretchBar(unsigned char aValue) : mValue(aValue) {}
        
        void SetValue(unsigned char aValue) { mValue = aValue; }
        
    private:
        void drawer(IScreen *aScreen, Coor aPos, Coor aSize, unsigned char aIsFocused) override
        {
            unsigned short resolution = OrientationPolicy::CalculateResolution(aSize);
            unsigned short normalizedValue = min((int)(resolution * mValue / 95), (int)resolution);
            
            unsigned char totalBlocks = (OrientationPolicy::BLOCK_START == OrientationPolicy::BLOCK_END) 
                                      ? 1 
                                      : (aSize.Y - 2);
            
            // Начальный блок
            aScreen->Picto(OrientationPolicy::GetTilePosition(aPos, aSize, 0, totalBlocks),
                          TileSet::GetTile(OrientationPolicy::BLOCK_START, 
                                         blockFill(0, normalizedValue)),
                          aIsFocused);
            
            // Средние блоки
            for (unsigned char i = 1; i < totalBlocks - 1; i++)
            {
                aScreen->Picto(OrientationPolicy::GetTilePosition(aPos, aSize, i, totalBlocks),
                              TileSet::GetTile(OrientationPolicy::BLOCK_MIDDLE, 
                                             blockFill(i, normalizedValue)),
                              aIsFocused);
            }
            
            // Конечный блок
            if (totalBlocks > 1)
            {
                aScreen->Picto(OrientationPolicy::GetTilePosition(aPos, aSize, totalBlocks - 1, totalBlocks),
                              TileSet::GetTile(OrientationPolicy::BLOCK_END, 
                                             blockFill(totalBlocks - 1, normalizedValue)),
                              aIsFocused);
            }
        }
        
        char blockFill(unsigned char blockNumber, unsigned short normalizedValue)
        {
            unsigned char fillSteps = TileSet::FILL_STEPS;
            if (normalizedValue / fillSteps < blockNumber) return 0;
            if (normalizedValue / fillSteps > blockNumber) return fillSteps;
            return normalizedValue % fillSteps;
        }
        
        unsigned char mValue;
    };
    
    // Удобные алиасы
    template<typename TileSet>
    using VStretchBar = StretchBar<TileSet, VerticalPolicy>;
    
    template<typename TileSet>
    using HStretchBar = StretchBar<TileSet, HorizontalPolicy>;
    
    // Конкретные типы
    using VProgressBar = VStretchBar<TileSetVProgressBar>;
    using HProgressBar = HStretchBar<TileSetHProgressBar>;
    using VScrollBar = VStretchBar<TileSetVScrollbar>;
    using HScrollBar = HStretchBar<TileSetHScrollbar>;
}