#include "BmpReader.h"

BMP_READER_START

BMPReader::BMPReader() : pixels(nullptr) {}

bool BMPReader::openBMP(const std::string& fileName) {
    std::ifstream bmpFile(fileName, std::ios::binary);
    if (!bmpFile) {
        std::cerr << "file opening error" << std::endl;
        return false;
    }

    bmpFile.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    bmpFile.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32) {
        std::cerr << "" << std::endl;
        return false;
    }

    pixels = new std::uint8_t[infoHeader.biSizeImage];
    bmpFile.seekg(fileHeader.bfOffBits, std::ios::beg);
    bmpFile.read(reinterpret_cast<char*>(pixels), infoHeader.biSizeImage);

    return true;
}

#include <windows.h>
#include <iostream>

void BMPReader::displayBMP() const {
    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int padding = infoHeader.biBitCount == 24 ? 0 : 1;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Сохраняем текущие настройки консоли
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalAttributes = consoleInfo.wAttributes;

    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            std::uint8_t* pixelParts = reinterpret_cast<std::uint8_t*>(&pixels[i * (width * (3 + padding)) + j * (3 + padding)]);
            int pixelBrightness = (pixelParts[0] + pixelParts[1] + pixelParts[2]) / 3;

            if (pixelBrightness < BRIGHTNESS_THRESHOLD) {
                // Ставим черный фон
                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                std::cout << " ";
            }
            else {
                // Ставим оригинальный фон
                SetConsoleTextAttribute(hConsole, originalAttributes);
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // Возвращаем настройки консоли на место
    SetConsoleTextAttribute(hConsole, originalAttributes);
}




void BMPReader::closeBMP() {
    delete[] pixels;
    pixels = nullptr;
}

BMPReader::~BMPReader() {
    closeBMP();
}

BMP_READER_END
