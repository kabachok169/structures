#include "list.h"
#include "array.h"
#include "expanded_list.h"
#include <string>
#include <ctime>
#include <fstream>
#include <vector>


template <class key_type, class value_type>
std::ostream& operator<<(std::ostream& stream, const std::pair<key_type, value_type>& pair) {
    stream << "{" << pair.first << ", " << pair.second << "}";
    return stream;
}


//template <class key_type, class value_type>
//friend bool operator==(const std::pair<key_type, value_type>& lhs, const std::pair<key_type, value_type>& rhs) {
//    return lhs.first == rhs.first;
//}


template <class key_type, class value_type>
bool compare_func(const std::pair<key_type, value_type>& lhs, const std::pair<key_type, value_type>& rhs) {
    return lhs.first < rhs.first;
}


int main(int argc, char* argv[]) {


    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
    std::fstream file_input(argv[1], std::fstream::in);

    std::fstream file_output(argv[2], std::fstream::out);

    std::string input;
    file_input >> input;

    if(input == "list") {
        ad::list<std::pair<int, int>> mylist(compare_func<int, int>);
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
                mylist.add(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "push " + std::to_string((double)(end - start)) << std::endl;
            }
            if(input == "pop"){
                auto start = clock();
                mylist.erase(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "pop " + std::to_string((double)(end - start)) << std::endl;
            }
            if(input == "search"){
                auto start = clock();
                mylist.search(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "search " + std::to_string((double)(end - start)) << std::endl;
            }

        }

        mylist.print();
    }
    else if(input == "array"){
        ad::array<std::pair<int, int>> myarray(1, 2, compare_func<int, int>);
        int data = 0, key = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> key;
            file_input >> data;

            if (input == "push") {
                auto start = clock();
                myarray.add(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "push " + std::to_string((double)(end - start)) << std::endl;
            }
            if (input == "pop") {
                auto start = clock();
                myarray.erase(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "pop " + std::to_string((double)(end - start)) << std::endl;
            }
            if (input == "search") {
                auto start = clock();
                myarray.search(std::pair<int, int>(key, data));
                auto end = clock();
                file_output << "search " + std::to_string((double)(end - start)) << std::endl;
            }


//            myarray.print();
//            std::cout << std::endl;
        }


        myarray.print();

    }
    else if(input == "elist"){

        ad::expanded_list<std::pair<int, int>> myelist(3, compare_func<int, int>);
        int data = 0, key = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> key;
            file_input >> data;

            if(input == "push"){
                auto start = clock();
                myelist.add(std::make_pair<int, int>(std::move(key), std::move(data)));
                auto end = clock();
                file_output << "push " + std::to_string((double)(end - start)) << std::endl;
            }
            if(input == "pop"){
                auto start = clock();
                myelist.erase(std::make_pair<int, int>(std::move(key), std::move(data)));
                auto end = clock();
                file_output << "pop " + std::to_string((double)(end - start)) << std::endl;
            }
            if(input == "search"){
                auto start = clock();
                myelist.search(std::make_pair<int, int>(std::move(key), std::move(data)));
                auto end = clock();
                file_output << "search " + std::to_string((double)(end - start)) << std::endl;
            }

//            myelist.print();
//            std::cout << std::endl;

        }

       myelist.print();
    }

    file_input.close();
    file_output.close();

    return 0;
}