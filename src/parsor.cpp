
#include <algorithm> 
#include "crg.hpp"

#define ext_not_supported file.rfind(".tsv") == -1 && file.rfind(".csv") == -1
#define tsv_file file.rfind(".tsv") != -1
#define csv_file file.rfind(".csv") != -1

using namespace std;

specs specifications_pusher(char *buff_cp)
{
    char *buff = my_strdup(buff_cp);
    specs new_spec;
    char *pch{nullptr};
    string cuter;
    vector<string> pre_sp;

    pch = strtok(buff, "\n");
    cuter = pch;
    cuter.erase(remove(cuter.begin(), cuter.end(), '\r'), cuter.end());
    pch = strdup(cuter.c_str());

    pch = strtok(pch, ",\t");
    while (pch != nullptr) {
        pre_sp.push_back(pch);
        pch = strtok(nullptr, ",\t");
    }
    
    new_spec.setUnit(pre_sp[0]);
    pre_sp.erase(pre_sp.begin());
    new_spec.setTimes(pre_sp);
    return new_spec;
}

company data_order(char *line, int cells)
{
    company new_comp;
    char *pch{nullptr};
    string pch_s;
    vector<string> Data;

    pch = strtok(line, ",\t\r");
    for (int i = 0; pch != nullptr; i++) {
        if (i > 0 && isanum(pch) == false)
            my_error("Make sure that cells only contains numbers\n");
        Data.push_back(pch);
        pch = strtok(nullptr, ",\t\r");
    }

    new_comp.setName(Data[0]);
    Data.erase(Data.begin());
    new_comp.setValues(Data);
    return new_comp;
}

vector<company> data_pusher(char *buff_cp, int cells)
{
    char *buff = my_strdup(buff_cp);
    char *pch{nullptr};
    vector<company> Comps;
    string cuter{buff};
    vector<char*> Data;
    int lines{0};

    cuter.erase(remove(cuter.begin(), cuter.end(), '\r'), cuter.end());
    buff = strdup(cuter.c_str());
    pch = strtok(buff, "\n");
    for (; pch != nullptr; lines++) {
        Data.push_back(pch);
        pch = strtok(nullptr, "\n");
    }
    for (int i{1}; i < lines; i++) {
        Comps.push_back(data_order(Data[i], cells));
    }
    return Comps;
}

int data_checker(char *buff_cp, string file)
{
    char *buff = my_strdup(buff_cp);
    string data{buff};
    char separator;
    int lines{0};
    int *nb_sep{nullptr};
    char *pch{nullptr};
    string pch_s;

    if ((lines = count(data.begin(), data.end(), '\n')) < 3)
        my_error("Sorry but file format is not correct\n");
    nb_sep = new int [lines + 1];
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

HUD parsor(char *av)
{
    string file = av;
    streampos size;
    char *buffer{nullptr};
    ifstream data;
    int cells{0};
    Companies Comps;
    specs s_sp;
    HUD hud;

    if (ext_not_supported)
        my_error("No supported file\nI only accept .tsv and .csv files\n");

    data.open(file, ios::in);
    if (!data.is_open())
        my_error("Sorry but I can't open your file\n");

    data.seekg(0, ios::end);
    size = data.tellg();
    data.seekg(0, ios::beg);
    buffer = new char [int(size) + 1];
    buffer[int(size)] = '\0';
    data.read(buffer, size);
    data.close();

    cells = data_checker(buffer, file);
    Comps = data_pusher(buffer, cells);
    s_sp = specifications_pusher(buffer);
    hud.init(s_sp, Comps);
    return hud;
}