
#include <algorithm> 
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1
#define tsv_file file.rfind(".tsv") != -1
#define csv_file file.rfind(".csv") != -1

using namespace std;

string **order_infos(char *buff, int lines, int place)
{
    string data = buff;

}

string **data_checker(char *buff, string file)
{
    string data = buff;
    char separator;
    int lines{0};
    int *nb_sep;
    char *pch;
    string pch_s;
    company ab;

    if ((lines = count(data.begin(), data.end(), '\n')) < 3)
        my_error("Sorry but file format is not correct\n");
    nb_sep = new int [lines];
    if (tsv_file) separator = '\t';
    else if (csv_file) separator = ',';

    pch = strtok(buff, "\n");
    for (int i{0}; pch != NULL; i++) {
        pch_s = pch;
        nb_sep[i] = count(pch_s.begin(), pch_s.end(), separator);
        pch = strtok(NULL, "\n");
    }

    for (int i{1}; i <= lines; i++)
        if (nb_sep[i] != nb_sep[i - 1])
            my_error("Cells on your file are not regular\n");

    //return order_infos(buff, lines, nb_sep[0]);
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