//
// Created by Leo Suzuki on 18.2.2024.
//

#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
};
