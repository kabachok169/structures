
#ifndef LISTS_LIST_H
#define LISTS_LIST_H


#include <iostream>
#include <memory>
#include <functional>
#include <fstream>
#include <ctime>


namespace ad {


    template <class T>
    class list {

    private:

        template<class L>
        class Node {

        public:
            L data;
            std::shared_ptr<Node<L>> next;
            std::shared_ptr<Node<L>> prev;


            explicit Node(L _data) : data(_data), next(nullptr), prev(nullptr) {}


            void del(){
                if(this->prev)
                    this->prev->next = this->next;
                if(this->next)
                    this->next->prev = this->prev;
            }


            ~Node() = default;
        };

    public:

        list(std::string file = "/home/anton/projects/bmstu/algs/structures/output", std::function<bool(const T&, const T&)> compare = std::less<T>()) : head(nullptr),
                                                                                 tail(nullptr),
                                                                                 length(0),
                                                                                 compare_func(compare) {
            output.open(file);
        }


        void add(T _data) {

            clock_t start = clock();

            if (head == nullptr) {


                head = std::make_shared<Node<T>> (_data);
                tail = head;
                ++length;

                clock_t end = clock();
                output << (double)(end - start) << std::endl;

                return;
            }

            auto ptr = head;

            while (compare_func(ptr->data, _data)) {

                if(!ptr->next){
                    std::shared_ptr<Node<T>> element(new Node<T>(_data));
                    ptr->next = element;
                    element->prev = ptr;
                    tail = element;
                    ++length;

                    clock_t end = clock();
                    output << (double)(end - start) << std::endl;

                    return;
                }
                ptr = ptr->next;
            }

            std::shared_ptr<Node<T>> element(new Node<T>(_data));

            element->next = ptr;
            element->prev = ptr->prev;
            if(ptr->prev)
                ptr->prev->next = element;
            else
                head = element;
            ptr->prev = element;
            ++length;
            clock_t end = clock();
            output << (double)(end - start) << std::endl;
        }


        bool erase(T _data) {

            clock_t start = clock();
            if (!length) return false;

            auto ptr = head;

            while (ptr->data != _data){
                ptr = ptr->next;
                if(!ptr) {
                    clock_t end = clock();
                    output << (double)(end - start) << std::endl;
                    return false;
                }
            }

            (*ptr).del();
            --length;

            clock_t end = clock();
            output << (double)(end - start) << std::endl;

            return true;
        }


        const bool search(T _data){

            clock_t start = clock();
            if (!length)
                return false;

            auto ptr = head;

            while (ptr->data != _data){
                ptr = ptr->next;
                if(!ptr) {
                    clock_t end = clock();
                    output << (double)(end - start) << std::endl;
                    return false;
                }
            }

            return true;
        }

        const T& operator[](size_t index){

            if(index >= length)
                throw std::invalid_argument("Too big to be true");

            if(length / 2 > index){

                size_t counter = 0;
                auto ptr = head;
                while(counter != index) {
                    ++counter;
                    ptr = ptr->next;
                }

                return ptr->data;
            }
            else{

                size_t counter = length - 1;
                auto ptr = tail;
                while(counter != index) {
                    --counter;
                    ptr = ptr->prev;
                }

                return ptr->data;
            }
        }


        const void print(){
            std::cout << "HEAD: [ " << head->data << " ]" << std::endl;
            auto ptr = head;
            while(ptr->next != nullptr) {
                std::cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            std::cout << ptr->data << std::endl;
            std::cout << "TAIL: [ " << tail->data << " ]" << std::endl;
        }


        ~list() = default;


    private:

        std::fstream output;
        std::function<bool(const T&, const T&)> compare_func;
        std::shared_ptr<Node<T>> head;
        std::shared_ptr<Node<T>> tail;
        size_t length;
    };

}


#endif //LISTS_LIST_H
