#include <iostream>
#include <fstream>

#define NUMBER_OF_POINTS 50
#define CSV_FILE "csvfile.csv"

int main(int argc, char const *argv[])
{
    std::ofstream myfile;
    myfile.open(CSV_FILE);
    for(int i= 0; i< NUMBER_OF_POINTS; i++)
    {
        myfile << i << "," << i+1 << "\n";
    }
    myfile.close();
    return 0;
}