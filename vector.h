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
    TYPE& operator [](const size_t& idx);
    bool operator ==(const Vector& other);
    bool operator !=(const Vector& other);
    bool operator <(const Vector& other);
    bool operator >(const Vector& other);
    bool operator <=(const Vector& other);
    bool operator >=(const Vector& other);
    ~Vector();

// the public methods
public:
    void assign(const size_t& count, const TYPE& value);
    void push_back(const TYPE& data);
    void pop_back();
    void insert(const TYPE& data, const size_t& position);
    void erase(const size_t& position);
    void sort();
    void clear();
    void shrink_to_fit();
    void swap( Vector& other );

    TYPE& at(const size_t& pos) const;
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    TYPE& front() const;
    TYPE& back() const;
    void print() const;

// the private methods
private:
    void copy(const Vector& other);
    void resize(const size_t& newCapacity);

// the private members
private:
    TYPE* m_data;
    size_t m_capacity;
    size_t m_size;
};

// the public methods
template <class TYPE>
Vector<TYPE>::Vector()
{
    m_capacity = 0;
    m_size = 0;
    m_data = new TYPE[m_capacity];
}

template <class TYPE>
Vector<TYPE>::Vector(const TYPE* data, const size_t size, const size_t capacity)
{
    m_capacity = capacity;
    m_size = size;
    m_data = new TYPE[m_capacity];
    for(size_t i = 0; i < size; i++)
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
bool Vector<TYPE>::operator ==(const Vector& other)
{
    if(m_capacity == other.m_capacity && m_size == other.m_size)
    {
        for(size_t i = 0; i < m_size; i++)
        {
            if(m_data[i] != other.m_data[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool Vector<TYPE>::operator !=(const Vector& other)
{
    return !(operator ==(other));
}

template <class TYPE>
bool Vector<TYPE>::operator <(const Vector& other)
{
    if(m_capacity < other.m_capacity || m_size < other.m_size)
    {
        return true;
    }
    else if(m_capacity == other.m_capacity && m_size == other.m_size)
    {
        for(size_t i = 0; i < m_size; i++)
        {
            if(m_data[i] < other.m_data[i])
            {
                return true;
            }
        }
    }
    return false;
}

template <class TYPE>
bool Vector<TYPE>::operator >(const Vector& other)
{
    if(m_capacity > other.m_capacity || m_size > other.m_size)
    {
        return true;
    }
    else if(m_capacity == other.m_capacity && m_size == other.m_size)
    {
        for(size_t i = 0; i < m_size; i++)
        {
            if(m_data[i] > other.m_data[i])
            {
                return true;
            }
        }
    }
    return false;
}

template <class TYPE>
bool Vector<TYPE>::operator <=(const Vector& other)
{
    return !(operator >(other));
}

template <class TYPE>
bool Vector<TYPE>::operator >=(const Vector& other)
{
    return !(operator <(other));
}

template <class TYPE>
Vector<TYPE>::~Vector()
{
    delete[] m_data;
}

template <class TYPE>
void Vector<TYPE>::assign(const size_t& count, const TYPE& value)
{
    m_size = count;
    m_capacity = count * 2;
    for(size_t i = 0; i < m_size; i++)
    {
        m_data[i] = value;
    }
}

template <class TYPE>
void Vector<TYPE>::push_back(const TYPE& data)
{
    if(m_size >= m_capacity)
    {
        resize(m_capacity * 2);
    }
    m_data[m_size] = data;
    m_size++;
}

template <class TYPE>
void Vector<TYPE>::pop_back()
{
    TYPE* newData = new TYPE[m_capacity];
    for(size_t i = 0; i < m_size - 1; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    m_size--;
}

template <class TYPE>
void Vector<TYPE>::insert(const TYPE& data, const size_t& position)
{
    if(position < 0 || position > m_size)
    {
        cerr << "Invalid position" << endl;
        return;
    }
    else
    {
        if(m_size >= m_capacity)
        {
            resize(m_capacity * 2);
        }
        TYPE* newData = new TYPE[m_capacity];
        for(size_t i = 0; i <= m_size; i++)
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
        m_size++;
    }
}

template <class TYPE>
void Vector<TYPE>::erase(const size_t& position)
{
    if(position < 0 || position > m_size)
    {
        cerr << "Invalid position" << endl;
        return;
    }
    for(size_t i = 0; i < m_size; i++)
    {
        if(i == position)
        {
            for(size_t j = i; j < m_size; j++)
            {
                m_data[j] = m_data[j + 1];
            }
        }
    }
    m_size--;
}

template <class TYPE>
void Vector<TYPE>::sort()
{
    TYPE temp;
    for(size_t i = 0; i < m_size; i++)
    {
        for(size_t j = 0; j < m_size - i - 1; j++)
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
}

template <class TYPE>
void Vector<TYPE>::shrink_to_fit()
{
    if(m_capacity != m_size)
    {
        m_capacity = m_size;
    }
}

template <class TYPE>
void Vector<TYPE>::swap( Vector& other )
{
    size_t other_capacity = m_capacity;
    size_t other_size = m_size;
    TYPE* other_data = m_data;
    if( this != &other )
    {
        copy( other );
    }
    other.m_capacity = other_capacity;
    other.m_size = other_size;
    other.m_data = other_data;

}

template <class TYPE>
TYPE& Vector<TYPE>::at(const size_t& pos) const
{
    return m_data[pos];
}

template <class TYPE>
size_t Vector<TYPE>::size() const
{
    return m_size;
}

template <class TYPE>
size_t Vector<TYPE>::capacity() const
{
    return m_capacity;
}

template <class TYPE>
bool Vector<TYPE>::empty() const
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
    return m_data[m_size - 1];
}

template <class TYPE>
void Vector<TYPE>::print() const
{
    for(size_t i = 0; i < m_size; i++)
    {
        cout << m_data[i] << " ";
    }
}

// the private methods
template <class TYPE>
void Vector<TYPE>::resize(const size_t& newCapacity)
{
    m_capacity = newCapacity;
    TYPE* newData = new TYPE[m_capacity];
    for(size_t i = 0; i < m_size; i++)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
}

template <class TYPE>
void Vector<TYPE>::copy(const Vector& other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = new TYPE[m_capacity];
    for(size_t i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

#endif // VECTOR_H
