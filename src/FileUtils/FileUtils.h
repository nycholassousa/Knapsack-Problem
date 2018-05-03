#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

bool openFile(std::ifstream &fin, const char *FileName)
{
    fin.open(FileName);
    return fin.is_open();
}

int getNumFromLine(std::string &line)
{
    int num = stoi(line.substr(0));

    if (line.size() != 1)
    {
        line = line.substr(2, line.size() - 1);
    }

    return num;
}

void loadFromFile(std::ifstream &fin, const char *fileName, std::vector<int> &values, std::vector<int> &weights, int &numItems, int &weightBound)
{
    std::string line;
    if (!openFile(fin, fileName))
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    getline(fin, line);
    numItems = getNumFromLine(line);
    weightBound = getNumFromLine(line);

    while (getline(fin, line))
    {
        weights.push_back(getNumFromLine(line));
        values.push_back(getNumFromLine(line));
    }
}

#endif /* FILEUTILS_H_ */