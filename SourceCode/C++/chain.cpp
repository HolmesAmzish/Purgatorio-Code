// File: chain.cpp
// Date: 2024.03.13
// Author:  Nulla

#include <iostream>

using namespace std;

template <class T>
struct chainNode {
    T element;
    chainNode<T>  *next;

    chainNode() {}
    chainNode (const T& element) {
        this->element = element;
    }
    chainNode (const T& element, chianNode<T> * next) {
        this->element = element;
        this->next = next;
    }
};

template<class T>
class chain : publiv linearList<T> {
    public:
    // 构造函数，复制构造函数和析构函数
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();
    
    // 抽象数据类型ADT的方法
    bool empty() const {
        return listSize == 0;
    }
    int size() const {
        return listSize;
    }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;    // the first node
    int listSize;   // the number of elements in the list

};