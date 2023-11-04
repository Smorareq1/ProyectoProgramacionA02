//
// Created by smora on 4/11/2023.
//

#ifndef PROYECTOAPLICACION02_LINEDATA_H
#define PROYECTOAPLICACION02_LINEDATA_H

#include <string>

class LineData {
public:
    std::string hashedKey;
    std::string restOfLine;

    LineData(const std::string& hashedKey, const std::string& restOfLine)
            : hashedKey(hashedKey), restOfLine(restOfLine) {}
};


#endif //PROYECTOAPLICACION02_LINEDATA_H
