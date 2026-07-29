// Tests/SerializersTests.cpp
#include <AUnit.h>
#include <evabSerializers.h>

using namespace evab;

test(SerializersTests, Serialize16x8_ValidPositionAndSize_ReturnsCorrectSerialized)
{
    Coor pos(5, 3);
    Coor size(4, 2);
    bool focused = true;
    
    unsigned short result = serialize_16x8(pos, size, focused);
    
    // Bit 0: visibility (1)
    assertTrue((result >> 0) & 1);
    // Bit 1: focused (1)
    assertTrue((result >> 1) & 1);
    // Bits 2-5: X (5)
    assertEqual(5, (result >> 2) & 0x0F);
    // Bits 6-8: Y (3)
    assertEqual(3, (result >> 6) & 0x07);
    // Bits 9-12: sizeX-1 (3)
    assertEqual(3, (result >> 9) & 0x0F);
    // Bits 13-15: sizeY-1 (1)
    assertEqual(1, (result >> 13) & 0x07);
}

test(SerializersTests, Deserialize16x8_ValidSerialized_RestoresCorrectValues)
{
    unsigned short serialized = 0b0010100011010011; // Example
    
    Coor pos, size;
    bool focused;
    
    deserialize_16x8(serialized, pos, size, focused);
    
    assertEqual(4, pos.X);
    assertEqual(3, pos.Y);
    assertEqual(5, size.X);
    assertEqual(2, size.Y);
    assertTrue(focused);
}

test(SerializersTests, Serialize32x4_ValidPositionAndSize_ReturnsCorrectSerialized)
{
    Coor pos(10, 2);
    Coor size(8, 3);
    bool focused = false;
    
    unsigned short result = serialize_32x4(pos, size, focused);
    
    // Bit 0: visibility (1)
    assertTrue((result >> 0) & 1);
    // Bit 1: focused (0)
    assertFalse((result >> 1) & 1);
    // Bits 2-6: X (10)
    assertEqual(10, (result >> 2) & 0x1F);
    // Bits 7-8: Y (2)
    assertEqual(2, (result >> 7) & 0x03);
    // Bits 9-13: sizeX-1 (7)
    assertEqual(7, (result >> 9) & 0x1F);
    // Bits 14-15: sizeY-1 (2)
    assertEqual(2, (result >> 14) & 0x03);
}

test(SerializersTests, Deserialize32x4_ValidSerialized_RestoresCorrectValues)
{
    unsigned short serialized = 0b1110010001010011;
    
    Coor pos, size;
    bool focused;
    
    deserialize_32x4(serialized, pos, size, focused);
    
    assertEqual(20, pos.X);
    assertEqual(0, pos.Y);
    assertEqual(19, size.X);
    assertEqual(4, size.Y);
    assertTrue(focused);
}
