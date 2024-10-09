#include <cstdlib>
#include <cstdint>
#include <array>
#include <iostream>

template <typename T>
class Auto_ptr {
    T *ptr_;
public:
    Auto_ptr(T* ptr=nullptr)
        : ptr_{ptr}
    { }

    ~Auto_ptr() {
        delete ptr_;
    }

    Auto_ptr(const Auto_ptr&) = delete;
    Auto_ptr& operator=(const Auto_ptr&) = delete;

    Auto_ptr(Auto_ptr&& a) noexcept
        : ptr_{ a.ptr_ }
    {
        a.ptr_ = nullptr;
    }

    Auto_ptr& operator=(Auto_ptr&& a) noexcept
    {
        if (this == &a)
            return *this;
        delete ptr_;
        ptr_ = a.ptr_;
        a.ptr_ = nullptr;
        return *this;
    }

    T& operator*() const {
        return *ptr_;
    }
};

template <typename T>
class Elem {
    static size_t currId;
    T *data_{ nullptr };
    const size_t id_;
public:
    Elem()
        : data_{ nullptr }, id_{ currId++ }
    {
    }
    Elem(T data)
        : data_{ new T{data} }, id_{ currId++ }
    {
        std::cout << "Elem: " << id_ << " acquired\n";
    }

    ~Elem() {
        delete data_;
        std::cout << "Elem: " << id_ << " destroyed\n";
    }

    Elem(const Elem& el)
        : data_{el.data_ ? new T{ *el.data } : nullptr}, id_{ currId++ }
    {
        std::cout << "Elem: " << id_ << " copy"
            " from elem: " << el.id_ << "\n";
    }

    Elem& operator=(const Elem& el) {
        if (this == &el)
            return *this;
        delete data_;
        data_ = el.data_ ? new T{ *el.data } : nullptr;
        return *this;
    }

    Elem(Elem&&) = delete;
    Elem& operator=(Elem&&) = delete;

    friend bool operator<(const Elem& el1, const Elem& el2) {
        return *el1.data_ < *el2.data_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Elem& el) {
        return out << *el.data_;
    }
};

template <typename T>
size_t Elem<T>::currId{ 0 };

template <typename T>
T&& move(T& res) {
    return static_cast<T&&>(res);
}

template <typename T>
void swap(T& a, T& b) {
    T temp{ move(a) };
    a     = move(b);
    b     = move(temp);
}

template <typename T, typename Compare>
void selSort(T start, T end, Compare comp) {
    for (T curr = start; curr != end; ++curr) {
        T min = curr;
        for (T next = curr + 1; next != end; ++next)
            if (comp(*next, *min))
                min = next;
        swap(*curr, *min);
    }
}

constexpr size_t len{4};
constexpr std::array<uint32_t, len> iniArr{4, 1, 3, 2};

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, Auto_ptr<Elem<T>> (&arr)[N]) {
    for (size_t i{0}; i < N; ++i)
        std::cout << (i > 0 ? ", " : "") << *arr[i];
    return out;
}

int main() {
    Auto_ptr<Elem<uint32_t>> arr[len];
    for (size_t i{0}; i < len; ++i)
        arr[i] = Auto_ptr<Elem<uint32_t>>{ new Elem<uint32_t>{iniArr[i]} };

    std::cout << arr << '\n';
    selSort(arr, arr+len,
                [](const Auto_ptr<Elem<uint32_t>>& a,
                   const Auto_ptr<Elem<uint32_t>>& b) {
                return *a < *b;
            });
    std::cout << arr << '\n';

    return EXIT_SUCCESS;
}
