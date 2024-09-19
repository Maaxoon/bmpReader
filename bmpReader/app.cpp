#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class BMPReader {
private:
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    unsigned char* pixelData;

public:
    BMPReader() : pixelData(nullptr) {}

    bool openBMP(const std::string& fileName) {
        std::ifstream file(fileName, std::ios::binary);
        if (!file) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return false;
        }

        // Чтение заголовков
        file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
        file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

        if (infoHeader.biBitCount != 24 && infoHeader.biBitCount != 32) {
            std::cerr << "Поддерживаются только 24 и 32 бита на пиксель!" << std::endl;
            return false;
        }

        // Выделение памяти для данных пикселей
        pixelData = new unsigned char[infoHeader.biSizeImage];
        file.seekg(fileHeader.bfOffBits, std::ios::beg);
        file.read(reinterpret_cast<char*>(pixelData), infoHeader.biSizeImage);

        file.close();
        return true;
    }

    void displayBMP() const {
        int width = infoHeader.biWidth;
        int height = infoHeader.biHeight;
        int padding = (4 - (width * (infoHeader.biBitCount / 8)) % 4) % 4;

        for (int i = height - 1; i >= 0; i--) {
            for (int j = 0; j < width; j++) {
                unsigned char* pixel = &pixelData[(i * (width * 3 + padding)) + j * 3];
                if (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0) {
                    std::cout << "#"; // Черный цвет
                }
                else if (pixel[0] == 255 && pixel[1] == 255 && pixel[2] == 255) {
                    std::cout << " "; // Белый цвет
                }
            }
            std::cout << std::endl;
        }
    }

    void closeBMP() {
        delete[] pixelData;
        pixelData = nullptr;
    }

    ~BMPReader() {
        closeBMP();
    }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <путь к файлу BMP>" << std::endl;
        return 1;
    }

    BMPReader bmp;
    if (bmp.openBMP(argv[1])) {
        bmp.displayBMP();
        bmp.closeBMP();
    }

    return 0;
}
