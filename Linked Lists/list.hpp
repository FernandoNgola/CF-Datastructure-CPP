#include <iostream>

namespace cf
{
    class List
    {
    private:
        /* data */
    public:
        List(/* args */);
        ~List();
        void push_back(int value);
        void push_front(int value);
        bool pop_back();
        bool pop_front();
        size_t size();
        size_t capacity();
    };

} // namespace cf