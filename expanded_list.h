//
// Created by anton on 25.10.17.
//

#ifndef LISTS_EXPANDED_LIST_H
#define LISTS_EXPANDED_LIST_H

#include <iostream>
#include <memory>
#include <functional>
#include <string>

namespace ad {


    template <class T>
    class expanded_list {

    private:

        template<class L>
        class Node {

        public:
            L* array_ptr;
            std::shared_ptr<Node<L>> next;
            std::shared_ptr<Node<L>> prev;
            size_t length;

            size_t capacity;

            explicit Node(size_t _capacity = 5) : next(nullptr), prev(nullptr), capacity(_capacity), length(0) {

                array_ptr = new L[capacity];
            }


            bool add(L _data, std::function<bool(const L&, const L&)> compare) {

                if(length == 0) {
                    array_ptr[length++] = _data;
                    return true;
                }

                size_t index = calc_insert_place(_data, compare);

                for(size_t i = length; i > index; --i) {
                    array_ptr[i] = array_ptr[i - 1];
                }

                array_ptr[index] = _data;
                ++length;

                return true;
            }


            bool has_space() {

                return length < capacity;
            }


            bool erase(L _data) {

                if(!length)
                    return false;

                for(int i = 0; i < length; ++i) {
                    if(array_ptr[i] == _data) {
                        for(int j = i; j < length - 1; ++j)
                            array_ptr[j] = array_ptr[j + 1];
                        --length;
                        if(!length)
                            del();

                        return true;
                    }
                }

                return false;
            }


            bool search(L _data) {
                if(!length)
                    return false;

                for(int i = 0; i < length; ++i) {
                    if(array_ptr[i] == _data)
                        return true;
                }

                return false;
            }


            L& operator[](size_t index) {

                if(index >= length)
                    throw std::invalid_argument("Too big to be true");

                return array_ptr[index];
            }


            friend std::ostream& operator<<(std::ostream& stream, Node<L>& element) {

                stream << "[ ";
                for(int i = 0; i < element.length - 1; ++i) {
                    stream << element.array_ptr[i] << ", ";
                }

                stream << element.array_ptr[element.length - 1] << " ]";

            }


            void del(){
                if(this->prev)
                    this->prev->next = this->next;
                if(this->next)
                    this->next->prev = this->prev;
            }


            ~Node() {

                delete[] array_ptr;

            }

        private:

            size_t calc_insert_place(T _data, std::function<bool(const L&, const L&)> compare) {

                if(compare(array_ptr[length - 1], _data))
                    return length;
                if(!compare(array_ptr[0], _data))
                    return 0;

                size_t c_multiply = 2;

                auto right_edge = calc_edge(_data, c_multiply, compare);
                auto left_edge = right_edge / c_multiply;

                if(right_edge == c_multiply)
                    left_edge = 0;

                while (right_edge - left_edge > 1) {

                    auto mdl = (right_edge + left_edge) / 2;

                    if(array_ptr[mdl] == _data)
                        return mdl;

                    if(compare(_data, array_ptr[mdl]))
                        right_edge = mdl;
                    else
                        left_edge = mdl;
                }

                return right_edge;

            }

            size_t calc_edge(T _data, size_t c_multiply, std::function<bool(const L&, const L&)> compare) {

                size_t right_edge = c_multiply;

                while(right_edge < length) {

                    if(!compare(array_ptr[right_edge], _data))
                        break;
                    right_edge *= c_multiply;

                }

                if(right_edge >= length)
                    right_edge = length - 1;

                return right_edge;

            }

        };

    public:

        expanded_list(size_t arrays_size = 3, std::function<bool(const T&, const T&)> compare = std::less<T>()) : head(nullptr),
                                                                                                                  tail(nullptr),
                                                                                                                  length(0),
                                                                                                                  compare_func(compare),
                                                                                                                  size(arrays_size) {}


        void add(T _data) {

            if (head == nullptr) {
                head = std::make_shared<Node<T>>(size);
                head->add(_data, compare_func);
                tail = head;
                ++length;
                return;
            }

            auto ptr = head;

            while(ptr) {

                if(compare_func(_data, ptr->array_ptr[ptr->length - 1])) {

                    if(ptr->has_space()) {
                        ptr->add(_data, compare_func);
                        ++length;

                        return;
                    }

                    auto new_ptr = std::make_shared<Node<T>>(size);

                    if(compare_func(_data, ptr->array_ptr[0])) {
                        if(ptr->prev)
                            if(ptr->prev->has_space()){
                                ptr->prev->add(_data, compare_func);
                                ++length;

                                return;
                            }
                        new_ptr->next = ptr;
                        new_ptr->prev = ptr->prev;

                        if(!ptr->prev)
                            head = new_ptr;
                        else
                            ptr->prev->next = new_ptr;

                        ptr->prev = new_ptr;

                        new_ptr->add(_data, compare_func);
                        ++length;

                        return;
                    }

                    if(ptr->next) {
                        if(ptr->next->has_space()) {
                            ptr->next->add(ptr->array_ptr[--ptr->length], compare_func);
                            ptr->add(_data, compare_func);
                            ++length;

                            return;
                        }
                        ptr->next->prev = new_ptr;
                    }
                    else
                        tail = new_ptr;

                    new_ptr->prev = ptr;
                    new_ptr->next = ptr->next;
                    ptr->next = new_ptr;

                    new_ptr->add(ptr->array_ptr[--ptr->length], compare_func);
                    ptr->add(_data, compare_func);
                    ++length;

                    return;
                }

                ptr = ptr->next;
            }


            ptr = tail;

            if(ptr->has_space()) {
                ptr->add(_data, compare_func);
                ++length;

                return;
            }

            auto new_ptr = std::make_shared<Node<T>>(size);

            tail = new_ptr;

            new_ptr->prev = ptr;
            new_ptr->next;
            ptr->next = new_ptr;

            new_ptr->add(_data, compare_func);
            ++length;
        }


        bool erase(T _data) {

            if(head == nullptr)
                return false;

            auto ptr = head;

            while(ptr) {
                if (!compare_func(ptr->array_ptr[ptr->length - 1], _data)) {
                    if (ptr->erase(_data)) {
                        --length;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                ptr = ptr->next;
            }

            return false;
        }


        bool search(T _data) {


            if(head == nullptr)
                return false;

            auto ptr = head;

            while(ptr) {
                if (!compare_func(ptr->array_ptr[ptr->length - 1], _data)) {
                    return ptr->search(_data);
                }



                ptr = ptr->next;
            }

            return false;
        }


        const T& get_max() {
            if(!length)
                throw std::invalid_argument("empty structure");
            return tail->array_ptr[tail->length - 1];
        }


        const T& get_min() {
            if(!length)
                throw std::invalid_argument("empty structure");
            return head->array_ptr[0];
        }


        const T& operator[](size_t index) {
            if(index >= length)
                throw std::invalid_argument("too big to be true");
            auto ptr = head;
            while(ptr) {

                if(index >= ptr->length)
                    index -= ptr->length;
                else
                    return ptr->array_ptr[index];
                ptr = ptr->next;
            }
        }


        const void print(){

            std::cout << "HEAD: [ " << *head << " ]" << std::endl;
            auto ptr = head;
            while(ptr->next != nullptr) {
                std::cout << *ptr << " -> ";
                ptr = ptr->next;
            }
            std::cout << *ptr << std::endl;
            std::cout << "TAIL: [ " << *tail<< " ]" << std::endl;
        }


        ~expanded_list() = default;


    private:

        std::function<bool(const T&, const T&)> compare_func;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
        size_t length;
        size_t size;
    };

}




#endif //LISTS_EXPANDED_LIST_H
