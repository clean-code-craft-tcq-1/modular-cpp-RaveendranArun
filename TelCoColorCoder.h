#ifndef TELE_COMMUNICATION_COLOUR_CODER
#define TELE_COMMUNICATION_COLOUR_CODER

#include <iostream>
#include <assert.h>

namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    extern const char* MajorColorNames[];
    extern const char* MinorColorNames[];
    extern int numberOfMajorColors;
    extern int numberOfMinorColors;

    class ColorPair 
    {
        private:
            MajorColor m_majorColor;
            MinorColor m_minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor);
            
            MajorColor getMajor();

            MinorColor getMinor();
            
            std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);

    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
}

#endif
