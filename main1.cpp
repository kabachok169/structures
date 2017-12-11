#include "list.h"
#include "array.h"
#include "expanded_list.h"
#include <string>
#include <ctime>
#include <fstream>
#include <vector>


template <class key_type, class value_type>
class my_pair {

public:

    friend bool operator==(const my_pair& lhs, const my_pair & rhs) {
        return lhs.first == rhs.first;
    }

    friend bool operator!=(const my_pair& lhs, const my_pair & rhs) {
        return lhs.first != rhs.first;
    }

    friend std::ostream& operator<<(std::ostream& out, const my_pair & obj) {
        out << "{"<< obj.first << ", " << obj.second << "}";
        return out;
    }

    my_pair() = default;

    my_pair(const key_type& _key, const value_type& _value) : first(_key), second(_value) {}

    explicit my_pair(const key_type& _key) : first(_key), second(0) {}

    my_pair(const my_pair<key_type, value_type>& obj) = default;

    ~my_pair() = default;


    key_type first;
    value_type second;
};


template <class key_type, class value_type>
bool compare_func(const my_pair<key_type, value_type>& lhs, const my_pair<key_type, value_type>& rhs) {
    return lhs.first < rhs.first;
}


int main(int argc, char* argv[]) {


    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;

//    std::fstream file_input("../input", std::fstream::in);
    std::fstream file_input(argv[1], std::fstream::in);

//    std::fstream file_output("../output", std::fstream::out);
    std::fstream file_output(argv[2], std::fstream::out);

    std::string input;



    ad::list<my_pair<int, int>> mylist(compare_func<int, int>);
    ad::array<my_pair<int, int>> myarray(1, 1.5, compare_func<int, int>);
    ad::expanded_list<my_pair<int, int>> myelist(5, compare_func<int, int>);
    int data = 0;
    int key = 0;
    int n = 0;
    file_input >> n;

    for (int i = 0; i < n; ++i) {
        file_input >> input;
        file_input >> key;

        if (input == "push") {
            file_input >> data;
            auto start = clock();
            mylist.add(my_pair<int, int>(key, data));
            auto end = clock();
            file_output << "push " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myarray.add(my_pair<int, int>(key, data));
            end = clock();
            file_output << "push " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myelist.add(my_pair<int, int>(key, data));
            end = clock();
            file_output << "push " + std::to_string((double) (end - start)) << std::endl;
        }
        if (input == "pop") {
            auto start = clock();
            mylist.erase(my_pair<int, int>(key));
            auto end = clock();
            file_output << "pop " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myarray.erase(my_pair<int, int>(key));
            end = clock();
            file_output << "pop " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myelist.erase(my_pair<int, int>(key));
            end = clock();
            file_output << "pop " + std::to_string((double) (end - start)) << std::endl;
        }
        if (input == "search") {
            auto start = clock();
            mylist.search(my_pair<int, int>(key));
            auto end = clock();
            file_output << "search " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myarray.search(my_pair<int, int>(key));
            end = clock();
            file_output << "search " + std::to_string((double) (end - start)) << std::endl;
            start = clock();
            myelist.search(my_pair<int, int>(key));
            end = clock();
            file_output << "search " + std::to_string((double) (end - start)) << std::endl;
        }
    }

//        mylist.print();



//       myelist.print();



    file_input.close();
    file_output.close();

    return 0;
}