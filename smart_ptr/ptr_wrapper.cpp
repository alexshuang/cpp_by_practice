#include <iostream>

class shape
{
public:
    char name[10] = "cycle";
};

class ptr_wrapper
{
public:
    ptr_wrapper(shape *ptr)
        : ptr_(ptr) {}
    ~ptr_wrapper() { delete ptr_; }
    shape *get(void) {
        return ptr_;
    }
private:
    shape *ptr_;
};

shape *foo(void)
{
    return new shape();
}

int main(void)
{
    ptr_wrapper p_shape(foo());
    std::cout << "name: " << p_shape.get()->name << std::endl;

    return 0;
}

