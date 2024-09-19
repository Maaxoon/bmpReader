#pragma once

#include "bmpReaderLib.h"
#include <fstream>
#include <string>

BMP_READER_START

class BmpReader
{
public:
	BmpReader();
	void OpenBMP(const std::string& fileName);
	void DisplayBMP();
	void CloseBMP();
	~BmpReader();
};

BMP_READER_END
