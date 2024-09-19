#pragma once

#include <cstdint>
#include "bmpReaderLib.h"

BMP_READER_START

// Структура BITMAPFILEHEADER, которая располагается в начале BMP-файла
struct BitMapFileHeader
{
    std::uint16_t Type;        // bfType: сигнатура формата BMP, обычно содержит значение 0x4D42 (символы 'BM' в ASCII)
    std::uint32_t Size;        // bfSize: общий размер файла BMP в байтах
    std::uint16_t Reserved1;   // bfReserved1: зарезервировано, должно быть 0
    std::uint16_t Reserved2;   // bfReserved2: зарезервировано, должно быть 0
    std::uint32_t OffBits;     // bfOffBits: смещение в байтах от начала файла до начала пиксельных данных
};


// Структура для формата BMP версии CORE (16-битная версия)
struct BitMapInfoCore
{
    std::uint32_t Size;        // Размер структуры в байтах
    std::uint16_t Width;       // Ширина изображения в пикселях (беззнаковое целое)
    std::uint16_t Height;      // Высота изображения в пикселях (беззнаковое целое)
    std::uint16_t Planes;      // Число цветовых плоскостей (допустимо только 1 для BMP)
    std::uint16_t BitCount;    // Количество бит на пиксель (например, 24 для true color)
};

// Структура для формата BMP версии 3 (32-битная версия)
struct BitMapInfoV3 {
    std::uint32_t Size;        // Размер структуры в байтах
    std::int32_t Width;        // Ширина изображения в пикселях (со знаком, может быть отрицательной для инверсии строк)
    std::int32_t Height;       // Высота изображения в пикселях (со знаком)
    std::uint16_t Planes;      // Число цветовых плоскостей (допустимо только 1)
    std::uint16_t BitCount;    // Количество бит на пиксель (например, 24 для true color)

    // Поля, добавленные в версии 3:
    std::uint32_t Compression; // Тип сжатия (0 — без сжатия, 1 — RLE-8, 2 — RLE-4 и т.д.)
    std::uint32_t SizeImage;   // Размер данных изображения в байтах (может быть 0 для несжатых изображений)
    std::int32_t XPelsPerMeter; // Горизонтальное разрешение в пикселях на метр
    std::int32_t YPelsPerMeter; // Вертикальное разрешение в пикселях на метр
    std::uint32_t ClrUsed;      // Количество использованных цветов (0 означает использование всех цветов по умолчанию)
    std::uint32_t ClrImportant; // Количество важнейших цветов (0 означает, что все цвета важны)
};

BMP_READER_END
