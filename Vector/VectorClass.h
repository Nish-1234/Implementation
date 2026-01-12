#include <iostream>
#include <stdexcept>

class NewVector
{
public:
    NewVector()
        : m_pArr(nullptr), m_nSize(0), m_nCapacity(0) {}

    NewVector(int count, int value = int())
        : m_nSize(count), m_nCapacity(count)
    {
        m_pArr = new int[m_nCapacity];
        for (int i = 0; i < count; i++)
            m_pArr[i] = value;
    }

    NewVector(const NewVector& obj)
        : m_nSize(obj.m_nSize), m_nCapacity(obj.m_nCapacity)
    {
        m_pArr = new int[m_nCapacity];
        for (int i = 0; i < m_nSize; i++)
            m_pArr[i] = obj.m_pArr[i];
    }

    NewVector& operator=(const NewVector& obj)
    {
        if (this != &obj)
        {
            delete[] m_pArr;
            m_nSize = obj.m_nSize;
            m_nCapacity = obj.m_nCapacity;
            m_pArr = new int[m_nCapacity];
            for (int i = 0; i < m_nSize; i++)
                m_pArr[i] = obj.m_pArr[i];
        }
        return *this;
    }

    ~NewVector()
    {
        delete[] m_pArr;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= m_nSize)
            throw std::out_of_range("Index out of range");
        return m_pArr[index];
    }

    const int& operator[](int index) const
    {
        if (index < 0 || index >= m_nSize)
            throw std::out_of_range("Index out of range");
        return m_pArr[index];
    }

    int size() const { return m_nSize; }
    int capacity() const { return m_nCapacity; }
    bool empty() const { return m_nSize == 0; }

    void push_back(int value)
    {
        if (m_nSize == m_nCapacity)
        {
            int newCapacity = (m_nCapacity == 0) ? 1 : m_nCapacity * 2;
            int* newArr = new int[newCapacity];

            for (int i = 0; i < m_nSize; i++)
                newArr[i] = m_pArr[i];

            delete[] m_pArr;
            m_pArr = newArr;
            m_nCapacity = newCapacity;
        }
        m_pArr[m_nSize++] = value;
    }

    int pop_back()
    {
        if (m_nSize == 0)
            throw std::out_of_range("Vector is empty");
        return m_pArr[--m_nSize];
    }

    void clear()
    {
        m_nSize = 0;
    }

    void print() const
    {
        for (int i = 0; i < m_nSize; i++)
            std::cout << m_pArr[i] << " ";
        std::cout << std::endl;
    }

private:
    int* m_pArr;
    int m_nSize;
    int m_nCapacity;
};
