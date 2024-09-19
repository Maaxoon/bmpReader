#pragma once

#include <cstdint>
#include "bmpReaderLib.h"

BMP_READER_START

// ��������� BITMAPFILEHEADER, ������� ������������� � ������ BMP-�����
struct BitMapFileHeader
{
    std::uint16_t Type;        // bfType: ��������� ������� BMP, ������ �������� �������� 0x4D42 (������� 'BM' � ASCII)
    std::uint32_t Size;        // bfSize: ����� ������ ����� BMP � ������
    std::uint16_t Reserved1;   // bfReserved1: ���������������, ������ ���� 0
    std::uint16_t Reserved2;   // bfReserved2: ���������������, ������ ���� 0
    std::uint32_t OffBits;     // bfOffBits: �������� � ������ �� ������ ����� �� ������ ���������� ������
};


// ��������� ��� ������� BMP ������ CORE (16-������ ������)
struct BitMapInfoCore
{
    std::uint32_t Size;        // ������ ��������� � ������
    std::uint16_t Width;       // ������ ����������� � �������� (����������� �����)
    std::uint16_t Height;      // ������ ����������� � �������� (����������� �����)
    std::uint16_t Planes;      // ����� �������� ���������� (��������� ������ 1 ��� BMP)
    std::uint16_t BitCount;    // ���������� ��� �� ������� (��������, 24 ��� true color)
};

// ��������� ��� ������� BMP ������ 3 (32-������ ������)
struct BitMapInfoV3 {
    std::uint32_t Size;        // ������ ��������� � ������
    std::int32_t Width;        // ������ ����������� � �������� (�� ������, ����� ���� ������������� ��� �������� �����)
    std::int32_t Height;       // ������ ����������� � �������� (�� ������)
    std::uint16_t Planes;      // ����� �������� ���������� (��������� ������ 1)
    std::uint16_t BitCount;    // ���������� ��� �� ������� (��������, 24 ��� true color)

    // ����, ����������� � ������ 3:
    std::uint32_t Compression; // ��� ������ (0 � ��� ������, 1 � RLE-8, 2 � RLE-4 � �.�.)
    std::uint32_t SizeImage;   // ������ ������ ����������� � ������ (����� ���� 0 ��� �������� �����������)
    std::int32_t XPelsPerMeter; // �������������� ���������� � �������� �� ����
    std::int32_t YPelsPerMeter; // ������������ ���������� � �������� �� ����
    std::uint32_t ClrUsed;      // ���������� �������������� ������ (0 �������� ������������� ���� ������ �� ���������)
    std::uint32_t ClrImportant; // ���������� ��������� ������ (0 ��������, ��� ��� ����� �����)
};

BMP_READER_END
