#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <class TYPE>
class Vector
{
// the public constructors and operators
public:
    Vector();
    Vector(const TYPE* data, const size_t size, const size_t capacity);
    Vector(const Vector& other);
    Vector& operator =(const Vector& other);
    TYPE& operator[](const size_t& idx);
    ~Vector();

// the public methods
public:
    void push_back(const TYPE& data);
    void pop_back();
    void insert(const TYPE& data, const size_t& position);
    void erase(const size_t& position);
    void sort();
    void clear();

    size_t getSize() const;
    size_t getCapacity() const;
    bool isEmpty() const;
    TYPE& front() const;
    TYPE& back() const;
    void print() const;

// the private methods
private:
    void copy(const Vector& other);
    void resize(const size_t& newSize);

// the private members
private:
    TYPE* m_data;
    size_t m_size;
    size_t m_capacity;

};

// the public methods
template <class TYPE>
Vector<TYPE>::Vector()
{
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <class TYPE>
Vector<TYPE>::Vector(const TYPE* data, const size_t size, const size_t capacity)
{
    m_size = size;
    m_capacity = capacity;
    m_data = new TYPE[m_size];
    for(size_t i = 0; i < capacity; i++)
    {
        m_data[i] = data[i];
    }
}

template <class TYPE>
Vector<TYPE>::Vector(const Vector& other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <class TYPE>
Vector<TYPE>& Vector<TYPE>::operator=(const Vector& other)
{
    if(this != &other)
    {
        copy(other);
    }
    return *this;
}

template <class TYPE>
TYPE& Vector<TYPE>::operator [](const size_t& idx)
{
    return m_data[idx];
}

template <class TYPE>
Vector<TYPE>::~Vector()
{
    delete[] m_data;
}

template <class TYPE>
void Vector<TYPE>::push_back(const TYPE& data)
{
    if(m_capacity >= m_size)
    {
        resize(m_size * 2);
    }
    m_data[m_capacity] = data;
    m_capacity++;
}

template <class TYPE>
void Vector<TYPE>::pop_back()
{
    TYPE* newData = new TYPE[m_capacity - 1];
    for(size_t i = 0; i < m_capacity - 1; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_capacity--;
}

template <class TYPE>
void Vector<TYPE>::insert(const TYPE& data, const size_t& position)
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
        TYPE* newData = new TYPE[m_size];
        for(size_t i = 0; i <= m_capacity; i++)
        {
            if(i < position)
            {
                newData[i] = m_data[i];
            }
            else if(i == position)
            {
                newData[i] = data;
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

template <class TYPE>
void Vector<TYPE>::erase(const size_t& position)
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

template <class TYPE>
void Vector<TYPE>::sort()
{
    TYPE temp;
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

template <class TYPE>
void Vector<TYPE>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <class TYPE>
size_t Vector<TYPE>::getSize() const
{
    return this->m_size;
}


template <class TYPE>
size_t Vector<TYPE>::getCapacity() const
{
    return m_capacity;
}

template <class TYPE>
bool Vector<TYPE>::isEmpty() const
{
    return m_size == 0;
}

template <class TYPE>
TYPE& Vector<TYPE>::front() const
{
    return m_data[0];
}

template <class TYPE>
TYPE& Vector<TYPE>::back() const
{
    return m_data[m_capacity - 1];
}

template <class TYPE>
void Vector<TYPE>::print() const
{
    for(size_t i = 0; i < m_capacity; i++)
    {
        cout << m_data[i] << " ";
    }
}

// the private methods
template <class TYPE>
void Vector<TYPE>::resize(const size_t& newSize)
{
    m_size = newSize;
    TYPE* newData = new TYPE[m_size];
    for(size_t i = 0; i < m_capacity; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
}

template <class TYPE>
void Vector<TYPE>::copy(const Vector &other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new TYPE[m_size];
    for(size_t i = 0; i < m_capacity; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

#endif // VECTOR_H
