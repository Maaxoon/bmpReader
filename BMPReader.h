#pragma once

#include "bmpReaderLib.h"
#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>

BMP_READER_START

class BMPReader {
private:
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    std::uint8_t* pixels;

public:
    const int BRIGHTNESS_THRESHOLD = 200;

    BMPReader();

    bool openBMP(const std::string& fileName);

    void displayBMP() const;

    void closeBMP();

    ~BMPReader();
};

BMP_READER_END
