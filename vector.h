#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <class TYPE>
class Vector
{
// the public constructors and operators
public:
    Vector(); // default constructor
    Vector(const TYPE* data, const size_t size, const size_t capacity); // parameterized constructor
    Vector(const Vector& other); // copy constructor
    Vector& operator =(const Vector& other) const; // assignment operator
    TYPE& operator [](const size_t& idx) const; // access operator
    bool operator ==(const Vector& other) const; // returns true if two vectors are equal
    bool operator !=(const Vector& other) const; // returns true if two vectors are different
    bool operator <(const Vector& other) const; // returns true if first vector is smaller than second vector
    bool operator >(const Vector& other) const; // returns true if first vector is bigger than second vector
    bool operator <=(const Vector& other) const; // returns true if first vector is smaller than or equal to second vector
    bool operator >=(const Vector& other) const; // returns true if first vector is bigger than or equal to second vector
    ~Vector(); // destructor

// iterator and reverse iterator of vector
public:
    class Iterator
    {
        friend class Vector;
    public:
        Iterator(TYPE* position); // constructor
        const TYPE& operator *() const; // const operator to access value of position
        TYPE& operator *(); // operator to access value of position
        const TYPE* operator ->() const; // const operator to access pointer of position
        TYPE* operator ->(); // operator to access pointer of position
        Iterator& operator ++(); // operator to increase address of vector
        Iterator operator ++(int); // operator to return value contained in address of vector
        bool operator ==(const Iterator& other) const; // returns true if two positions are equal
        bool operator !=(const Iterator& other) const; // returns true if two positions are different
        bool operator <(const Iterator& other) const; // returns true if first position is smaller than second position
        bool operator >(const Iterator& other) const; // returns true if first position is bigger than second position
        bool operator <=(const Iterator& other) const; // returns true if first position is smaller than or equal to second position
        bool operator >=(const Iterator& other) const; // returns true if first position is bigger than or equal to second position

    private:
        TYPE* m_position; // pointer pointing to current position in vector
    };

    class Reverse_Iterator
    {
        friend class Vector;
    public:
        Reverse_Iterator(TYPE* position); // constructor
        const TYPE& operator *() const; // const operator to access value of position
        TYPE& operator *(); // operator to access value of position
        const TYPE* operator ->() const; // const operator to access pointer of position
        TYPE* operator ->(); // operator to access pointer of position
        Reverse_Iterator& operator --(); // operator to decrease address of vector
        Reverse_Iterator operator --(int); // operator to return value contained in address of vector
        bool operator ==(const Reverse_Iterator& other) const; // returns true if two positions are equal
        bool operator !=(const Reverse_Iterator& other) const; // returns true if two positions are different
        bool operator <(const Reverse_Iterator& other) const; // returns true if first position is smaller than second position
        bool operator >(const Reverse_Iterator& other) const; // returns true if first position is bigger than second position
        bool operator <=(const Reverse_Iterator& other) const; // returns true if first position is smaller than or equal to second position
        bool operator >=(const Reverse_Iterator& other) const; // returns true if first position is bigger than or equal to second position

    private:
        TYPE* m_position; // pointer pointing to current position in vector
    };

// the public methods
public:
    void assign(const size_t& count, const TYPE& data); // assigns the data to vector as many times as the count
    void push_back(const TYPE& data); // adds element to the back of vector
    void pop_back(); // removes element of the back of vector
    void insert(const TYPE& data, const size_t& position); // inserts element at given position of vector
    void erase(const size_t& position); // erases element at given position of vector
    void sort(); // sorts vector
    void clear(); // clears vector
    void shrink_to_fit(); // if capacity is different than size, capacity becomes equal to size
    void swap(Vector& other);  // swaps two vectors

    TYPE& at(const size_t& pos) const; // accesses element at given position of vector
    size_t size() const; // returns size of vector
    size_t capacity() const; // returns capacity of vector
    bool empty() const; // returns true if vector is empty
    TYPE& front() const; // returns front data of vector
    TYPE& back() const; // returns back data of vector
    Iterator begin() const; // returns iterator to front of vector
    const Iterator cbegin() const; // returns const iterator to front of vector
    Iterator end() const; // returns iterator to back of vector
    const Iterator cend() const; // returns const iterator to back of vector
    Reverse_Iterator rbegin() const; // returns iterator to front of vector
    const Reverse_Iterator crbegin() const; // returns const iterator to front of vector
    Reverse_Iterator rend() const; // returns iterator to back of vector
    const Reverse_Iterator crend() const; // returns const iterator to back of vector
    void print() const; // prints vector

// the private methods
private:
    void copy(const Vector& other); // copies one vector to another
    void resize(const size_t& newCapacity); // resizes vector's capacity

// the private members
private:
    TYPE* m_data; // data of vector
    size_t m_capacity; // capacity of vector
    size_t m_size; // size of vector
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
Vector<TYPE>& Vector<TYPE>::operator =(const Vector& other) const
{
    if(this != &other)
    {
        copy(other);
    }
    return *this;
}

template <class TYPE>
TYPE& Vector<TYPE>::operator [](const size_t& idx) const
{
    return m_data[idx];
}

template <class TYPE>
bool Vector<TYPE>::operator ==(const Vector& other) const
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
bool Vector<TYPE>::operator !=(const Vector& other) const
{
    return !(operator ==(other));
}

template <class TYPE>
bool Vector<TYPE>::operator <(const Vector& other) const
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
bool Vector<TYPE>::operator >(const Vector& other) const
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
bool Vector<TYPE>::operator <=(const Vector& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool Vector<TYPE>::operator >=(const Vector& other) const
{
    return !(operator <(other));
}

template <class TYPE>
Vector<TYPE>::~Vector()
{
    delete[] m_data;
}

template <class TYPE>
Vector<TYPE>::Iterator::Iterator(TYPE* position)
{
    m_position = position;
}

template <class TYPE>
const TYPE& Vector<TYPE>::Iterator::operator *() const
{
    return *m_position;
}

template <class TYPE>
TYPE& Vector<TYPE>::Iterator::operator *()
{
    return *m_position;
}

template <class TYPE>
const TYPE* Vector<TYPE>::Iterator::operator ->() const
{
    return m_position;
}

template <class TYPE>
TYPE* Vector<TYPE>::Iterator::operator ->()
{
    return m_position;
}

template <class TYPE>
typename Vector<TYPE>::Iterator& Vector<TYPE>::Iterator::operator ++()
{
    ++m_position;
    return *this;
}

template <class TYPE>
typename Vector<TYPE>::Iterator Vector<TYPE>::Iterator::operator ++(int)
{
    Iterator res(*this);
    ++(*this);
    return res;
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator ==(const Iterator& other) const
{
    return m_position == other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator !=(const Iterator& other) const
{
    return !(operator ==(other));
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator <(const Iterator& other) const
{
    return m_position < other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator >(const Iterator& other) const
{
    return m_position > other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator <=(const Iterator& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool Vector<TYPE>::Iterator::operator >=(const Iterator& other) const
{
    return !(operator <(other));
}

template <class TYPE>
Vector<TYPE>::Reverse_Iterator::Reverse_Iterator(TYPE* position)
{
    m_position = position;
}

template <class TYPE>
const TYPE& Vector<TYPE>::Reverse_Iterator::operator *() const
{
    return *m_position;
}

template <class TYPE>
TYPE& Vector<TYPE>::Reverse_Iterator::operator *()
{
    return *m_position;
}

template <class TYPE>
const TYPE* Vector<TYPE>::Reverse_Iterator::operator ->() const
{
    return m_position;
}

template <class TYPE>
TYPE* Vector<TYPE>::Reverse_Iterator::operator ->()
{
    return m_position;
}

template <class TYPE>
typename Vector<TYPE>::Reverse_Iterator& Vector<TYPE>::Reverse_Iterator::operator --()
{
    --m_position;
    return *this;
}

template <class TYPE>
typename Vector<TYPE>::Reverse_Iterator Vector<TYPE>::Reverse_Iterator::operator --(int)
{
    Reverse_Iterator res(*this);
    --(*this);
    return res;
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator ==(const Reverse_Iterator& other) const
{
    return m_position == other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator !=(const Reverse_Iterator& other) const
{
    return !(other == *this);
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator <(const Reverse_Iterator& other) const
{
    return m_position < other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator >(const Reverse_Iterator& other) const
{
    return m_position > other.m_position;
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator <=(const Reverse_Iterator& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool Vector<TYPE>::Reverse_Iterator::operator >=(const Reverse_Iterator& other) const
{
    return !(operator <(other));
}

template <class TYPE>
void Vector<TYPE>::assign(const size_t& count, const TYPE& data)
{
    m_size = count;
    m_capacity = count * 2;
    for(size_t i = 0; i < m_size; i++)
    {
        m_data[i] = data;
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
        std::cerr << "Invalid position" << std::endl;
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
        std::cerr << "Invalid position" << std::endl;
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
void Vector<TYPE>::swap(Vector& other)
{
    size_t other_capacity = m_capacity;
    size_t other_size = m_size;
    TYPE* other_data = m_data;
    if(this != &other)
    {
        copy(other);
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
typename Vector<TYPE>::Iterator Vector<TYPE>::begin() const
{
    return Vector<TYPE>::Iterator(m_data);
}

template <class TYPE>
const typename Vector<TYPE>::Iterator Vector<TYPE>::cbegin() const
{
    return Vector<TYPE>::Iterator(m_data);
}

template <class TYPE>
typename Vector<TYPE>::Iterator Vector<TYPE>::end() const
{
    return Vector<TYPE>::Iterator(m_data + m_size);
}

template <class TYPE>
const typename Vector<TYPE>::Iterator Vector<TYPE>::cend() const
{
    return Vector<TYPE>::Iterator(m_data + m_size);
}

template <class TYPE>
typename Vector<TYPE>::Reverse_Iterator Vector<TYPE>::rbegin() const
{
    return Vector<TYPE>::Reverse_Iterator(m_data);
}

template <class TYPE>
const typename Vector<TYPE>::Reverse_Iterator Vector<TYPE>::crbegin() const
{
    return Vector<TYPE>::Reverse_Iterator(m_data);
}

template <class TYPE>
typename Vector<TYPE>::Reverse_Iterator Vector<TYPE>::rend() const
{
    return Vector<TYPE>::Reverse_Iterator(m_data + m_size);
}

template <class TYPE>
const typename Vector<TYPE>::Reverse_Iterator Vector<TYPE>::crend() const
{
    return Vector<TYPE>::Reverse_Iterator(m_data + m_size);
}

template <class TYPE>
void Vector<TYPE>::print() const
{
    for(size_t i = 0; i < m_size; i++)
    {
        std::cout << m_data[i] << " ";
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
