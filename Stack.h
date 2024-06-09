#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element);
    void pop();
    T top() const;
    bool isEmpty() const;
};

template <typename T>
void Stack<T>::push(const T& element) {
    elements.push_back(element);
}

template <typename T>
void Stack<T>::pop() {
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elements.pop_back();
}

template <typename T>
T Stack<T>::top() const {
    if (elements.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elements.back();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return elements.empty();
}

#endif // STACK_H
#pragma once
