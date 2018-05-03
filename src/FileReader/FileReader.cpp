#include "FileReader.h"

FileReader::FileReader(const std::string &file_name)
{
    this->file_ = new std::fstream(file_name, std::ios::in);
}

FileReader::~FileReader()
{
    delete this->file_;
}