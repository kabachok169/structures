#include "list.h"
#include "array.h"
#include "expanded_list.h"
#include <string>
#include <ctime>
#include <fstream>

template <class key_type, class value_type>
struct my_pair{

    my_pair(){
        pair.first = 0;
        pair.second = 0;
    }

    my_pair(key_type first, value_type second){
        pair.first = first;
        pair.second = second;
    }

    ~my_pair() = default;


    std::pair<key_type, value_type> pair;

    my_pair& operator=(my_pair<key_type, value_type>& element){
        pair.first = element.pair.first;
        pair.second = element.pair.second;
        return *this;
    }

    friend bool operator==(my_pair<key_type, value_type>& lhs, my_pair<key_type, value_type>& rhs) {
        return lhs.pair.first == rhs.pair.first;
    }

    friend bool operator!=(my_pair<key_type, value_type>& lhs, my_pair<key_type, value_type>& rhs) {
        return lhs.pair.first != rhs.pair.first;
    }

    friend std::ostream& operator<<(std::ostream& stream, const my_pair<key_type, value_type>& element) {

        stream << '{' <<  element.pair.first << ", " << element.pair.second << '}';

    }
};


template <class key_type, class value_type>
bool compare_func(const my_pair<key_type, value_type>& lhs, const my_pair<key_type, value_type>& rhs) {
    return lhs.pair.first < rhs.pair.first;
}



int main(int argc, char* argv[]) {



    std::fstream file_input("/home/anton/projects/bmstu/algs/structures/input");

    std::fstream file_output("/home/anton/projects/bmstu/algs/structures/output");

    std::string input;
    file_input >> input;

    if(input == "list") {
        ad::list<my_pair<int, int>> mylist(compare_func<int, int>);
        int data = 0;
        int key = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> key;
            file_input >> data;

            if(input == "push") {
                auto start = clock();
                mylist.add(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double)(end - start) << std::endl;
            }
            if(input == "pop"){
                auto start = clock();
                mylist.erase(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double)(end - start) << std::endl;
            }
            if(input == "search"){
                auto start = clock();
                mylist.search(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double)(end - start) << std::endl;
            }

        }

        mylist.print();
    }
    else if(input == "array"){
        ad::array<my_pair<int, int>> myarray(1, 1.5, compare_func<int, int>);
        int data = 0, key = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> key;
            file_input >> data;

            if (input == "push") {
                auto start = clock();
                myarray.add(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }
            if (input == "pop") {
                auto start = clock();
                myarray.erase(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }
            if (input == "search") {
                auto start = clock();
                myarray.search(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }

            myarray.print();
            std::cout << std::endl;
        }

        myarray.print();

    }
    else if(input == "elist"){

        ad::expanded_list<my_pair<int, int>> myelist(3, compare_func<int, int>);
        int data = 0, key = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> key;
            file_input >> data;

            if(input == "push"){
                auto start = clock();
                myelist.add(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }
            if(input == "pop"){
                auto start = clock();
                myelist.erase(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }
            if(input == "search"){
                auto start = clock();
                myelist.search(my_pair<int, int>(key, data));
                auto end = clock();
                file_output << (double) (end - start) << std::endl;
            }

            myelist.print();
            std::cout << std::endl;

        }

       myelist.print();
    }

    file_input.close();
    file_output.close();

    return 0;
}