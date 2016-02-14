#include <iostream>
#include <fstream>

using namespace std;

/*
 * Function Name:   IsLowerCase
 * Description:     Determines if the input char is a lowercase char
 */
bool IsLowerCase(char val)
{
    bool isLowerCase = false;

    // 97 = a, 122 = z
    if(val >= 97 && val <= 122)
    {
        isLowerCase = true;
    }
    else
    {
        isLowerCase = false;
    }

    return isLowerCase;
}

/*
 * Function Name: IsUpperCase
 * Description: Determines if the input char is an uppercase char
 */
bool IsUpperCase(char val)
{
    bool isUpperCase = false;

    // 65 = A, 90 = Z
    if(val >= 65 && val <= 90)
    {
        isUpperCase = true;
    }
    else
    {
        isUpperCase = false;
    }

    return isUpperCase;
}

int main(int argc, char *argv[])
{
    ifstream inputFile;

    string line;

    inputFile.open(argv[1]);

    if(!inputFile.is_open())
    {
        cout << "Input file error" << endl;        
    }
    else
    {
        while(getline(inputFile,line))
        {
            unsigned int index = 0;
            
            bool capitalize = true;

            while(index < line.size())
            {
                if(IsUpperCase(line[index]) || IsLowerCase(line[index]))
                {
                    if(capitalize && IsLowerCase(line[index]))
                    {
                        line[index] = line[index] - 32;

                        capitalize = false;
                    }
                    else if(capitalize && IsUpperCase(line[index]))
                    {
                        capitalize = false;    
                    }
                    else if(!capitalize)
                    {
                        capitalize = true;
                    }
                }
                ++index;
            }
            cout << line << endl;
        }
    }

    inputFile.close();

    return 0;
}
