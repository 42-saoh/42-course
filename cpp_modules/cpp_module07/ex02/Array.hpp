#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *content;
        unsigned int _size;

    public:
        Array() : _size(0)
        {
            content = new T[0];
        }
        Array(unsigned int size) : _size(size)
        {
            content = new T[_size];
        }
        Array(const Array &a) : _size(a.size())
        {
            T *temp = new T[_size];
            for (unsigned int i = 0; i < a.size(); i++)
                temp[i] = a[i];
            content = temp;
        }
        ~Array()
        {
            delete[] content;
        }
        unsigned int size(void) const
        {
            return (_size);
        }
        T &operator[](const int i) const
        {
            if (i < 0 || static_cast<const unsigned int>(i) >= _size)
                throw std::range_error("Out of range");
            return (content[i]);
        }
        Array &operator=(const Array &a)
        {
            if (content)
                delete[] content;
            content = 0;
            _size = a.size();
            T *temp = new T[_size];
            for (unsigned int i = 0; i < a.size(); i++)
                temp[i] = a[i];
            content = temp;
            return (*this);
        }
};

#endif