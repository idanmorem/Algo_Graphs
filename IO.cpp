#include "IO.h"

void IO::graphDefenitionInput()
{
    int numbersInput[3];
    getline(std::cin, inputString);
    int edge [2];

    int i = 0;
    int j = 0;
    while ( !std::cin.eof())
    {
        while (inputString.length() > 0)
        {
            if (isdigit(inputString[0]))
            {
                if(i < 3) // the input is not an edge
                {
                    numbersInput[i] = std::stoi(inputString);
                    inputString = inputString.substr(std::to_string(numbersInput[i]).length(), inputString.length() - std::to_string(numbersInput[i]).length());
                    i++;
                    if(i == 3)
                        analyzeDefinitionInput(numbersInput);
                }
                else //the input is edge
                {

                }

            }
            else if (isblank(inputString[0]))
            {
                inputString = inputString.substr(1, inputString.length() - 1);
            }
            else
            {
                 std::cout << "Invalid input";
                 exit(1);
            }
        }
        getline(std::cin, inputString);
    }

}

void IO::analyzeDefinitionInput(int* input)
{
    if (input[0] < 1)
    {
        std::cout << "Invalid input";
        exit(1);
    }

    if (input[1] < 1 || input[1] > input[0])
    {
        std::cout << "Invalid input";
        exit(1);
    }

    if (input[2] < 1 || input[2] > input[0])
    {
        std::cout << "Invalid input";
        exit(1);
    }
}

