#include "external_sort.h"

ExternSort::ExternSort()
    : j{1},
    tmp{0},
    write_count{10}
{
}

void ExternSort::randomNumbers()
{
    path = "myFile.txt";
    const std::size_t size_of_file = 125;
    fileOut.open(path);
    if(!fileOut.is_open())
    {
        std::cout << "Error creating file!" << std::endl;
    }
    else
    {
        for(int i = 0; i < size_of_file - 1; ++i)
        {
            fileOut << rand() % 1000000 << std::endl;
        }
        fileOut << rand() % 2225;
    }
}
 
void ExternSort::createInitialRuns()
{
    fileIn.open(path);
    if(!fileIn.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
    }
    else
    {
        while(!fileIn.eof())
        {
            for(int i = 0; i < write_count; ++i)
            {
                fileIn >> tmp;
                myFile.insert(tmp);
            }
            std::ofstream exportFiles(std::to_string(j) + ".txt");
            for(iter = myFile.begin(); iter != myFile.end(); ++iter)
            {
                exportFiles << *iter << std::endl;
            }
            myFile.clear();
            ++j;
            
        }
        fileIn.close();
        merge();
    }
}
void ExternSort::merge()
{
    std::ifstream newFile[j - 1];
    std::ofstream finalFile("Final.txt");
    int minimum = INT_MAX;
    for(int i = 1; i < j - 1; ++i)
    {
        newFile[i].open(std::to_string(i) + ".txt");
        while(!newFile[i].eof())
        {
            newFile[i] >> tmp;
            myFile.insert(tmp);
        }
        newFile[i].close();
    }
    
    for(iter = myFile.begin(); iter != myFile.end(); ++iter)
    {
        finalFile << *iter << std::endl;
    }
    
    for(int i = 0; i < j; ++i)
    {
        std::remove((std::to_string(i) + ".txt").c_str());
    }
    
}

