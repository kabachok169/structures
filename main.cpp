#include "list.h"
#include "array.h"
#include "expanded_list.h"
#include <string>

int main() {

    std::string input;

//    std::cin >> input;
    input = "elist";

    if(input == "list") {
        ad::list<int> mylist;
        int data = 0;
        int n = 0;
        std::cin >> n;

        for (int i = 0; i < n; ++i) {
            std::cin >> data;
            mylist.add(data);

        }


        std::cout << mylist[2] << std::endl;

        mylist.erase(20);
        std::cout << mylist.search(15) << std::endl;
        std::cout << mylist.search(20) << std::endl;
        mylist.print();
    }
    else if(input == "array"){
        ad::array<int> myarray;
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

        ad::expanded_list<int> myelist;
        int data = 0;
        int n = 0;
        std::cin >> n;

        for (int i = 0; i < n; ++i) {
            std::cin >> data;
            myelist.add(data);
        }

        myelist.print();


    }




    return 0;
}