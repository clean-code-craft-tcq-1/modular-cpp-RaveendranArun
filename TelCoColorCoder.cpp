#include "TelCoColorCoder.h"

using namespace TelCoColorCoder;

const char* TelCoColorCoder::MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet" };
int TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* TelCoColorCoder::MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate" };
int TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor) : m_majorColor(major), m_minorColor(minor) { 

}

MajorColor ColorPair::getMajor() {
    return m_majorColor;
}

MinorColor ColorPair::getMinor() {
    return m_minorColor;
}

std::string ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[m_majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[m_minorColor];
    return colorPairStr;
}

ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);

    return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}
