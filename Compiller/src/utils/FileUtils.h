#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <fstream>

class CFileUtils
{
public:
	static std::string read_file(const char* filePath);
};

#endif // FILEUTILS_H