#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <string>
# include <fstream>
# include <iostream>

class Replace
{
    private:
        std::string in_filename;
        std::string s1;
        std::string s2;
        std::string out_filename;
        std::fstream in_fs;
        std::fstream out_fs;

    public:
        Replace(char *argv1, char *argv2, char *argv3);
        bool is_s1_or_s2_error(void);
        bool fs_open(void);
        bool read_and_write(void);
        ~Replace();
};

#endif