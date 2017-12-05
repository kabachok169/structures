#include "list.h"
#include "array.h"
#include "expanded_list.h"
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {

    std::fstream file_input("/home/anton/projects/bmstu/algs/structures/input");
    std::string input;
    file_input >> input;
//    input = "elist";

    if(input == "list") {
        ad::list<int> mylist(argv[1]);
        int data = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> data;

            if(input == "push")
                mylist.add(data);
            if(input == "pop")
                mylist.erase(data);
            if(input == "search")
                mylist.search(data);

        }


        std::cout << mylist[2] << std::endl;

        mylist.erase(20);
        std::cout << mylist.search(15) << std::endl;
        std::cout << mylist.search(20) << std::endl;
        mylist.print();
    }
    else if(input == "array"){
        ad::array<int> myarray(1, 1.5, argv[1]);
        int data = 0;
        int n = 0;
        std::cin >> n;

        for (int i = 0; i < n; ++i) {
            std::cin >> data;
            myarray.add(data);
        }

        myarray.print();

        int k = 0;
        std::cin >> k;
        std::cout << myarray.search(k) << std::endl;
        myarray.print();


    }
    else if(input == "elist"){

        ad::expanded_list<int> myelist(3, argv[1]);
        int data = 0;
        int n = 0;
        file_input >> n;

        for (int i = 0; i < n; ++i) {
            file_input >> input;
            file_input >> data;

            if(input == "push")
                myelist.add(data);
            if(input == "pop")
                myelist.erase(data);
            if(input == "search")
                myelist.search(data);

        }

//        std::cout << myelist.erase(20) << std::endl;
//        std::cout << myelist.search(15) << std::endl;
//        std::cout << myelist.search(20) << std::endl;

       myelist.print();


    }




    return 0;
}