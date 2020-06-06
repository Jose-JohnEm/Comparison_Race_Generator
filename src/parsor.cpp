
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1

using namespace std;

int data_checker(char *buff)
{
    string data = buff;
    cout << "The file exists !\n" << data;
}

void parsor(char *av)
{
    string file = av;
    streampos size;
    char *buffer;
    ifstream data;

    if (ext_not_supported)
        my_error("No supported file\nI only accept .tsv and .csv files\n");

    data.open(file, ios::in);
    if (!data.is_open())
        my_error("Sorry but I can't open your file\n");
    size = data.tellg();
    buffer = new char [size];
    data.seekg(0, ios::beg);
    data.read(buffer, data.tellg());
    data_checker(buffer);
}