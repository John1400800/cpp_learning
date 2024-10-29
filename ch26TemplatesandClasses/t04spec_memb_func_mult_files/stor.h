// stor.h
#ifndef STORAGE_H
#define STORAGE_H
template <typename T>
class Storage {
    T value{};
public:
    Storage(const T &value);

    template <typename U>
    friend class Storage;

    template <typename U>
    Storage(const Storage<U> &stor);

    void print(std::ostream &out);
};
#endif // STORAGE_H
