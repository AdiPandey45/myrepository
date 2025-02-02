#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
struct IDinfo
{
    string type;    
    int size; 
    int address;     
};
int main()  
{
    string fname;
    cout << "give the name of the C input file: ";
    getline(cin, fname); 
    ifstream file (fname);
    if (!file.is_open())
    {
        cerr << "!Error! cant open file" << fname << endl;
        return 1;
    }
    map<string, IDinfo> SymbolTable;
    string line;
    int scope = 0;
    int address = 0;
    while (getline(file, line))
    {
        size_t pos = line.find(";");
        if (pos != string::npos)
        {
            string d = line.substr(0, pos);
            pos = d.find_last_of(" \t");
            if (pos != string::npos)
            {
                string ident = d.substr(pos + 1);
                SymbolTable[ident] = {"int", 4, address, scope};
                address += 4;
            }
        }

        if (line.find("{") != string::npos)
        {
            scope++;
        }
        else if (line.find("}") != string::npos)
        {
            scope--;
        }
    }
    cout << "name\ttype\tsize\taddress" << endl;
    for (const auto &entry : SymbolTable)
    {
        cout << entry.first << "\t" << entry.second.type << "\t" << entry.second.size << "\t" << entry.second.address << endl;
    }
    //new change added;
    //okay
    //one more change
}
