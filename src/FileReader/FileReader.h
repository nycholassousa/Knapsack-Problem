#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class FileReader {
private:
    std::fstream* file_;
public:
    FileReader(const std::string& file_name);
    ~FileReader();
};

#endif /* FILEREADER_H_ */