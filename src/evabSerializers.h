#pragma once
#include <evabCoor.h>

namespace evab
{
    /**
     * @brief Serializes element state for 16x8 tile screens
     * 
     * @param aPos Position of the element
     * @param aSize Size of the element
     * @param isFocused Focus state
     * @return unsigned short Serialized state
     */
    unsigned short serialize_16x8(const Coor &aPos, const Coor &aSize, bool isFocused);
    
    /**
     * @brief Deserializes element state for 16x8 tile screens
     * 
     * @param aSerialized Serialized state
     * @param aPos Position of the element (output)
     * @param aSize Size of the element (output)
     * @param isFocused Focus state (output)
     */
    void deserialize_16x8(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);

    /**
     * @brief Serializes element state for 32x4 tile screens
     * 
     * @param aPos Position of the element
     * @param aSize Size of the element
     * @param isFocused Focus state
     * @return unsigned short Serialized state
     */
    unsigned short serialize_32x4(const Coor &aPos, const Coor &aSize, bool isFocused);
    
    /**
     * @brief Deserializes element state for 32x4 tile screens
     * 
     * @param aSerialized Serialized state
     * @param aPos Position of the element (output)
     * @param aSize Size of the element (output)
     * @param isFocused Focus state (output)
     */
    void deserialize_32x4(unsigned short aSerialized, Coor &aPos, Coor &aSize, bool &isFocused);
}
