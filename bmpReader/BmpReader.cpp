#include "BmpReader.h"
#include "BitMapInfo.h"

BMP_READER_START


void BmpReader::OpenBMP(const std::string& fileName)
{
	auto bmpFile = std::ifstream(fileName, std::ios::binary);
	if (!bmpFile.is_open() || !bmpFile.good())
	{
		return;
	}
	BitMapFileHeader header;
	bmpFile.read(reinterpret_cast<char*>(&header), sizeof(header));
	std::uint32_t fileInfoSize;
	bmpFile.read(reinterpret_cast<char*>(&fileInfoSize), sizeof(fileInfoSize));
	if (fileInfoSize == 12)
	{

	}

}

BmpReader::~BmpReader()
{
}

BMP_READER_END
