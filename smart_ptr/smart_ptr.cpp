#include <iostream>

class shape
{
public:
    char name[10] = "cycle";
};

class stride
{
public:
    char name[20] = "one-by-one";
};

template <typename T>
class smart_ptr
{
public:
    smart_ptr(T *ptr=nullptr)
        : ptr_(ptr) {}
    smart_ptr(smart_ptr &sp) {
        ptr_ = sp.release();
    }
    ~smart_ptr() { delete ptr_; }

    T *get(void) const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    operator bool() const { return ptr_; }
    smart_ptr& operator=(smart_ptr &rhs) {
        smart_ptr(rhs).swap(*this);
        return *this;
    }

private:
    T *release(void) {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(smart_ptr &rhs) {
        std::swap(ptr_, rhs.ptr_);
    }

    T *ptr_;
};

int main(void)
{
    smart_ptr<stride> p_(new stride());
    smart_ptr<stride> p = p_;
    //smart_ptr<stride> p(p_);
    std::cout << "name: " << p.get()->name << std::endl;
    std::cout << "*: " << (*p).name << std::endl;
    std::cout << "->: " << p->name << std::endl;
    std::cout << (p == true) << std::endl;

    return 0;
}

