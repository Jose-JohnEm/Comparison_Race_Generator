
#include <algorithm> 
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1
#define tsv_file file.rfind(".tsv") != -1
#define csv_file file.rfind(".csv") != -1

using namespace std;

company data_order(char *line, int cells)
{
    company new_comp;
    char *pch{nullptr};
    string pch_s;
    vector<string> Data;

    pch = strtok(line, ",\t");
    for (int i = 0; pch != nullptr; i++) {
        Data.push_back(pch);
        cout << pch;
        pch = strtok(nullptr, ",\t");
    }

    new_comp.setName(Data[0]);
    Data.erase(Data.begin());
    new_comp.setValues(Data);
    return new_comp;
}

vector<company> data_pusher(char *buff, int cells)
{
    char *pch{nullptr};
    vector<company> Comps;

    pch = strtok(buff, "\n");
    for (int i{0}; pch != nullptr; i++) {
        if (i != 0)
            Comps.push_back(data_order(strdup(pch), cells));
        pch = strtok(nullptr, "\n");
    }
}

int data_checker(char *buff_cp, string file)
{
    char *buff = strdup(buff_cp);
    string data{buff};
    char separator;
    int lines{0};
    int *nb_sep{nullptr};
    char *pch{nullptr};
    string pch_s;

    if ((lines = count(data.begin(), data.end(), '\n')) < 3)
        my_error("Sorry but file format is not correct\n");
    nb_sep = new int [lines];
    if (tsv_file) separator = '\t';
    else if (csv_file) separator = ',';

    pch = strtok(buff, "\n");
    for (int i{0}; pch != nullptr; i++) {
        pch_s = pch;
        nb_sep[i] = count(pch_s.begin(), pch_s.end(), separator);
        pch = strtok(nullptr, "\n");
    }

    for (int i{1}; i <= lines; i++)
        if (nb_sep[i] != nb_sep[i - 1])
            my_error("Cells on your file are not regular\n");
    cout << "Format is correct\n";
    return nb_sep[0];
}

void parsor(char *av)
{
    string file = av;
    streampos size;
    char *buffer{nullptr};
    ifstream data;
    int cells{0};

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
    cells = data_checker(buffer, file);
    data_pusher(buffer, cells);
}