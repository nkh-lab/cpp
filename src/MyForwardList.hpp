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

    inline Node<T>* getHead() { return m_Head; }

private:
    Node<T>* m_Head = nullptr;
};

} // namespace MyForwardList
