
#include <algorithm> 
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1
#define tsv_file file.rfind(".tsv")
#define csv_file file.rfind(".csv")

using namespace std;

bool regular_cells_checker(char sep)
{

}

int data_checker(char *buff, string file)
{
    string data = buff;
    cout << "The file exists !\n";
    char sep{','};
    auto lines{0};
    int *nb_sep;
    char *pch;
    string pch_s;

    if ((lines = count(data.begin(), data.end(), '\n')) < 3)
        my_error("Sorry but file format is not correct\n");
    nb_sep = new int [lines];
    if (tsv_file) sep = '\t';
    else if (csv_file) sep = ',';
    
    pch = strtok(buff, "\n");
     cout << sep << "\n";
    for (int i{0}; pch != NULL; i++) {
        pch_s = pch;
        nb_sep[i] = count(pch_s.begin(), pch_s.end(), sep);
        cout << nb_sep[i] << "\n";
        pch = strtok(NULL, "\n");
    }
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