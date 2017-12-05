//
// Created by anton on 24.10.17.
//

#ifndef LISTS_ARRAY_H
#define LISTS_ARRAY_H

#include <iostream>
#include <memory>
#include <functional>
#include <cmath>
#include <fstream>
#include <ctime>

namespace ad {


    template<class T>
    class array {

    public:

        explicit array(size_t start_size = 1, float amortization_c = 1.5,
                       std::string file = "/home/anton/projects/bmstu/algs/structures/output",
                       std::function<bool(const T &, const T &)> compare = std::less<T>()) : length(0),
                                                                                    amortization(amortization_c),
                                                                                    capacity(start_size),
                                                                                    compare_func(compare) {
            output.open(file);
            array_ptr = new T[capacity];
        }


        void add(T _data) {

            clock_t start = clock();

            if(length >= capacity) {
                try {
                    resize();
                }
                catch (std::bad_alloc&) {
                    throw std::bad_alloc();
                }
            }

            if(length == 0) {
                array_ptr[length] = _data;
                ++length;
                clock_t end = clock();
                output << (double)(end - start) << std::endl;

                return;
            }

            size_t index = calc_insert_place(_data);

            for(size_t i = length; i > index;) {

                array_ptr[i] = array_ptr[--i];

            }

            array_ptr[index] = _data;
            ++length;
            clock_t end = clock();
            output << (double)(end - start) << std::endl;

        }


        bool erase(T _data){

            clock_t start = clock();

            long int index = search(_data);

            if(index < 0) {
                clock_t end = clock();
                output << (double)(end - start) << std::endl;
                return false;
            }

            for(; index < length - 1;) {
                array_ptr[index] = array_ptr[++index];
            }

            --length;
            clock_t end = clock();
            output << (double)(end - start) << std::endl;

            return true;

        }


        long int search(T _data) {                       //binary search

            clock_t start = clock();

            size_t c_multiply = 2;
            size_t right_edge = calc_edge(_data, c_multiply);
            size_t left_edge = right_edge / c_multiply;

            if(right_edge == c_multiply)
                left_edge = 0;

            if(right_edge > length)
                right_edge = length - 1;

            while (left_edge < right_edge) {

                size_t mdl = (right_edge + left_edge) / 2;

                if(array_ptr[mdl] == _data) {
                    clock_t end = clock();
                    output << (double)(end - start) << std::endl;
                    return mdl;
                }

                if(compare_func(_data, array_ptr[mdl]))
                    right_edge = mdl - 1;
                else
                    left_edge = mdl + 1;
            }

            if(array_ptr[right_edge] == _data) {
                clock_t end = clock();
                output << (double)(end - start) << std::endl;
                return right_edge;
            }
            else {
                clock_t end = clock();
                output << (double)(end - start) << std::endl;
                return -1;
            }
        }


        const T& operator[](size_t index){

            if(index >= length)
                throw std::invalid_argument("Too big to be true");

            return array_ptr[index];

        }


        void print() {

            std::cout << "[ ";
            for(size_t i = 0; i < length - 1; ++i) {

                std::cout << array_ptr[i] << ", ";
            }
            std::cout << array_ptr[length - 1] << " ]" << std::endl;

        }


        ~array(){
            delete[] array_ptr;
        }


    private:

        void resize() {

            try {

                if (!capacity) {
                    capacity += 1;
                    array_ptr = new T[capacity];
                    return;
                }

                auto new_ptr = new T[capacity = ceil(capacity * amortization)];

                for (int i = 0; i < length; ++i) {
                    new_ptr[i] = array_ptr[i];
                }

                delete[] array_ptr;
                array_ptr = std::move(new_ptr);
            }
            catch(std::bad_alloc&){

                throw std::bad_alloc();
            }
        }

        size_t calc_insert_place(T _data) {

            if(compare_func(array_ptr[length - 1], _data))
                return length;
            if(!compare_func(array_ptr[0], _data))
                return 0;

            size_t c_multiply = 2;

            auto right_edge = calc_edge(_data, c_multiply);
            auto left_edge = right_edge / c_multiply;

            if(right_edge == c_multiply)
                left_edge = 0;

            while (right_edge - left_edge > 1) {

                auto mdl = (right_edge + left_edge) / 2;

                if(array_ptr[mdl] == _data)
                    return mdl;

                if(!compare_func(array_ptr[mdl], _data))
                    right_edge = mdl;
                else
                    left_edge = mdl;
            }

            return right_edge;

        }

        size_t calc_edge(T _data, size_t c_multiply) {

            size_t right_edge = c_multiply;

            while(right_edge < length) {

                if(!compare_func(array_ptr[right_edge], _data))
                    break;
                right_edge *= c_multiply;

            }

            if(right_edge >= length)
                right_edge = length - 1;

            return right_edge;

        }

        std::fstream output;
        T* array_ptr;
        size_t length;
        float amortization;
        size_t capacity;
        std::function<bool(const T &, const T &)> compare_func;
    };

}

#endif //LISTS_ARRAY_H
