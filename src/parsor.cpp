
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1
#define tsv_file file.rfind(".tsv")
#define csv_file file.rfind(".csv")

using namespace std;

int data_checker(char *buff, string file)
{
    string data = buff;
    cout << "The file exists !\n";
    char sep;
    auto lines{0};
    int *nb_sep;

    if (lines = data.find_last_of('\n') < 2)
        my_error("Sorry but file format is not correct\n");
    
    nb_sep = new int [lines];
    if (tsv_file) sep = '\t';
    else if (csv_file) sep = ',';
    
    cout << "It seems correct\n";
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

    data.seekg(0, ios::end);
    size = data.tellg();
    data.seekg(0, ios::beg);
    buffer = new char [size];
    data.read(buffer, size);
    data.close();
    data_checker(buffer, file);
}