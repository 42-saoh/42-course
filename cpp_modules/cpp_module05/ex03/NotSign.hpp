#ifndef NOTSIGN_HPP
# define NOTSIGN_HPP
# include <exception>

class NotSign : public std::exception
{
    public:
        const char * what() const throw();
};

#endif