#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector
{
// the public constructors and operators
public:
    Vector();
    Vector(const T* _data, const size_t _size, const size_t _capacity);
    Vector(const Vector& other);
    Vector& operator =(const Vector& other);
    T& operator[](size_t idx);
    ~Vector();

// the public methods
public:
    void push_back(const T& _data);
    void pop_back();
    void insert(const T& _data, const size_t position);
    void erase(const size_t position);
    void sort();
    void clear();

    size_t getSize() const;
    size_t getCapacity() const;
    bool isEmpty() const;
    T& front() const;
    T& back() const;
    void print();

// the private methods
private:
    void copy(const Vector& other);
    void resize(size_t newSize);

// the private members
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

};

// the public methods
template <typename T>
Vector<T>::Vector()
{
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
Vector<T>::Vector(const T* _data, const size_t _size, const size_t _capacity)
{
    m_size = _size;
    m_capacity = _capacity;
    m_data = new T[_size];
    for(size_t i = 0; i < _capacity; i++)
    {
        m_data[i] = _data[i];
    }
}

template <typename T>
Vector<T>::Vector(const Vector &other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if(this != &other)
    {
        copy(other);
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator [](size_t idx)
{
    return m_data[idx];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
    m_data = nullptr;
}

template <typename T>
void Vector<T>::push_back(const T& _data)
{
    if(m_capacity >= m_size)
    {
        resize(m_size * 2);
    }
    m_data[m_capacity] = _data;
    m_capacity++;
}

template <typename T>
void Vector<T>::pop_back()
{
    T* newData = new T[m_capacity - 1];
    for(size_t i = 0; i < m_capacity - 1; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity--;
}

template <typename T>
void Vector<T>::insert(const T& _data, const size_t position)
{
    if(position < 0 || position > m_capacity)
    {
        cerr << "Invalid position" << endl;
        return;
    }
    else
    {
        if(m_capacity >= m_size)
        {
            resize(m_size * 2);
        }
        T* newData = new T[m_size];
        for(size_t i = 0; i <= m_capacity; i++)
        {
            if(i < position)
            {
                newData[i] = m_data[i];
            }
            else if(i == position)
            {
                newData[i] = _data;
            }
            else
            {
                newData[i] = m_data[i - 1];
            }
        }
        delete[] m_data;
        m_data = newData;
        m_capacity++;
    }
}

template <typename T>
void Vector<T>::erase(size_t position)
{
    if(position < 0 || position > m_capacity)
    {
        cerr << "Invalid position" << endl;
        return;
    }
    for(size_t i = 0; i < m_capacity; i++)
    {
        if(i == position)
        {
            for(size_t j = i; j < m_capacity; j++)
            {
                m_data[j] = m_data[j + 1];
            }
        }
    }
    m_capacity--;
}

template <typename T>
void Vector<T>::sort()
{
    T temp;
    for(size_t i = 0; i < m_capacity; i++)
    {
        for(size_t j = 0; j < m_capacity - i - 1; j++)
        {
            if(m_data[j] > m_data[j + 1])
            {
                temp = m_data[j];
                m_data[j] = m_data[j + 1];
                m_data[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void Vector<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return this->m_size;
}


template <typename T>
size_t Vector<T>::getCapacity() const
{
    return m_capacity;
}

template <typename T>
bool Vector<T>::isEmpty() const
{
    return m_size == 0;
}

template <typename T>
T& Vector<T>::front() const
{
    return m_data[0];
}

template <typename T>
T& Vector<T>::back() const
{
    return m_data[m_capacity - 1];
}

template <typename T>
void Vector<T>::print()
{
    for(size_t i = 0; i < m_capacity; i++)
    {
        cout << m_data[i] << " ";
    }
}

// the private methods
template <typename T>
void Vector<T>::resize(size_t newSize)
{
    m_size = newSize;
    T* newData = new T[m_size];
    for(size_t i = 0; i < m_capacity; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
}

template <typename T>
void Vector<T>::copy(const Vector &other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_size];
    for(size_t i = 0; i < m_capacity; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

#endif // VECTOR_H
