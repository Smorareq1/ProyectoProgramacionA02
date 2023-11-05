//
// Created by smora on 4/11/2023.
//

#include "LineData.h"

LineData::LineData(const std::string& hashedKey, const std::string& restOfLine)
        : hashedKey(hashedKey), restOfLine(restOfLine) {}

bool LineData::operator<(const LineData& other) const {
    return hashedKey < other.hashedKey;
}