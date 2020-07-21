#pragma once

namespace MyForwardList {

void test(void);

template <typename T>
struct Node
{
    T value;
    Node* next = nullptr;
};

template <typename T>
class MyForwardListIterator
{
public:
    MyForwardListIterator(Node<T>* node)
        : m_Node(node)
    {
    }

    bool operator==(const MyForwardListIterator& other) const
    {
        if (this == &other)
        {
            return true;
        }
        return m_Node == other.m_Node;
    }

    bool operator!=(const MyForwardListIterator& other) const { return !operator==(other); }

    T& operator*() { return m_Node->value; }

    void operator++() { m_Node = m_Node->next; }

private:
    Node<T>* m_Node;
};

template <typename T>
class MyForwardList
{
public:
    MyForwardList() = default;
    ~MyForwardList() = default;

    void push_front(const T& value)
    {
        Node<T>* n = new Node<T>();
        n->value = value;

        if (m_Head != nullptr) n->next = m_Head;

        m_Head = n;
    }

    void reverse()
    {
        Node<T>*prev = nullptr, *next = nullptr, *n = m_Head;

        for (;;)
        {
            next = n->next;
            n->next = prev;

            if (next == nullptr) break;

            prev = n;
            n = next;
        }

        m_Head = n;
    }

    // for iterating
    MyForwardListIterator<T> begin() { return MyForwardListIterator<T>(m_Head); }
    MyForwardListIterator<T> end() { return MyForwardListIterator<T>(nullptr); }

    inline Node<T>* getHead() { return m_Head; }

private:
    Node<T>* m_Head = nullptr;
};

} // namespace MyForwardList
