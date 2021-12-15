#include <iostream>
#include <stdexcept>

struct my_error_msg
{
    void operator()(const char *input) const
    {
        msg = input;
    }
    const char *what(void) const
    {
        return (msg);
    }
    private:
        static const char *msg;
};

template <typename T>
class Vector
{
    private:
        T *data_;
        size_t size_;

    public:
        Vector(size_t size) : size_(size)
        {
            data_ = new T[size_];
            for (int i = 0; i < size_; i++)
                data_[i] = 3;
        }
        const T& at(size_t index) const
        {
            if (index >= size_)
                throw my_error_msg("vector 의 index 가 범위를 초과하였습니다.");
            return (data_[index]);
        }
        ~Vector()
        {
            std::cout << "destoryer" << std::endl;
            delete[] data_;
        }
        void print(void)
        {
            for (int i = 0; i < size_; i++)
                std::cout << data_[i] << std::endl;
        }
};

int main()
{
    Vector<int> a(5);
    int index, data = 0;
    
    std::cin >> index;
    try
    {
        data = a.at(index);
    }
    catch(const my_error_msg &e)
    {
        std::cout << "예외 발생! " << e.what() << std::endl;
    }
    std::cout << "읽은 데이터 : " << data << std::endl;
}