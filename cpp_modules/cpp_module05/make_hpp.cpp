#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
    std::fstream fs;
    std::string str(argv[1]);
    std::string out("#ifndef ");

    argc = 0;
    fs.open(argv[1], std::fstream::out | std::fstream::trunc);
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '.')
            out += '_';
        else
            out += std::toupper(str[i]);
    }
    out += "\n# define ";
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '.')
            out += '_';
        else
            out += std::toupper(str[i]);
    }
    out += "\n\n#endif";
    fs.write(out.c_str(), out.size());
    fs.close();
}