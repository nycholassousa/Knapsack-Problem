#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <vector>

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

void knapSack(int numItems, int weightBound, std::vector<int> &values, std::vector<int> &weights)
{
    std::vector<int> itemsInKnapsack;
    int knapSack[numItems + 1][weightBound + 1];
    int row = numItems;
    int column = weightBound;
    //extra row/col to allow for 0th row/column

    for (int i = 0; i <= numItems; i++)
    {
        for (int j = 0; j <= weightBound; j++)
        {
            if (i == 0 || j == 0)
            {
                //init 0th row and column.
                knapSack[i][j] = 0;
            }

            else if (j >= weights[i - 1])
            {
                //if item can't even fit yet...carry value from previous row up.
                knapSack[i][j] = max(values[i - 1] + knapSack[i - 1][j - weights[i - 1]], knapSack[i - 1][j]);
            }
            else
            {
                //else item can fit...choose the max..
                knapSack[i][j] = knapSack[i - 1][j];
            }
        }
    }

    while (row > 0)
    {
        if (knapSack[row][column] > knapSack[row - 1][column] && knapSack[row][column] > knapSack[row][column - 1])
        {
            //std::cout << knapSack[row][column] << std::endl;
            itemsInKnapsack.push_back(row);
            row--;
            column = column - weights[row];
        }
        else
        {
            row--;
        }
    }

    std::cout << "Valor: " << knapSack[numItems][weightBound] << std::endl << "Produtos Escolhidos: ";

    for (int i = 0; i < itemsInKnapsack.size(); i++)
    {
        if (i == itemsInKnapsack.size() - 1)
        {
            std::cout << itemsInKnapsack[i] << std::endl;
        }
        else
        {
            std::cout << itemsInKnapsack[i] << ",";
        }
    }

}

#endif /* KNAPSACK_H_ */