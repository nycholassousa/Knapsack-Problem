#include "FileUtils/FileUtils.h"
#include "Knapsack/Knapsack.h"

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::clog << "Knapsack [SAMPLE_FILE]" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> values;
    std::vector<int> weights;
    std::ifstream fin;
    const char *fileName = argv[1];

    int numItems;
    int weightBound;

    loadFromFile(fin, fileName, values, weights, numItems, weightBound);
    knapSack(numItems, weightBound, values, weights);

    return EXIT_SUCCESS;
}