#include "BMPReader.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "using: " << argv[0] << " <path to BMP>" << std::endl;
        return 1;
    }

    BMR_READER_NS::BMPReader bmpReader;

    if (!bmpReader.openBMP(argv[1])) {
        std::cerr << "unable to open " << argv[1];
        return 1;
    }

    bmpReader.displayBMP();
    bmpReader.closeBMP();

    return 0;
}
