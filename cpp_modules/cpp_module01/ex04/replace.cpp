#include "replace.hpp"

Replace::Replace(char *argv1, char *argv2, char *argv3)
    : in_filename(argv1), s1(argv2), s2(argv3)
{
    out_filename = in_filename + ".replace";
}

Replace::~Replace()
{
    in_fs.close();
    out_fs.close();
}

bool Replace::is_s1_or_s2_error(void)
{
    if (s1 == "" || s2 == "")
        return (true);
    return (false);
}

bool Replace::fs_open(void)
{
    in_fs.open(in_filename, std::fstream::in);
    if (in_fs.fail())
    {
        std::cout << "'" << in_filename << "' file open fail" << std::endl;
        return (1);
    }
    out_fs.open(out_filename, std::fstream::out | std::fstream::trunc);
    if (out_fs.fail())
    {
        std::cout << "'" << out_filename << "' file open fail" << std::endl;
        return (1);
    }
    return (0);
}

bool Replace::read_and_write(void)
{
    char buffer[100001];
    bool is_full;
    int s1_size = s1.size();
    int s2_size = s2.size();
    
    do
    {
        memset(buffer, 0, 100001);
        is_full = false;
        in_fs.read(buffer, 100000);
        int size = in_fs.gcount();
        if (in_fs.bad())
            return (true);
        if (!in_fs.eof() && size == 100000)
            is_full = true;
        if (size != 0)
        {
            std::string out_str;
            out_str.reserve(size * 3);
            out_str = buffer;
            int i = 0;
            while (1)
            {
                i = out_str.find(s1, i);
                if (i == -1)
                    break ;
                out_str.erase(i, s1_size);
                out_str.insert(i, s2);
                i += s2_size;
            }
            out_fs.write(out_str.c_str(), out_str.size());
            if (out_fs.bad())
                return (true);
        }
    }
    while (is_full);
    return (false);
}