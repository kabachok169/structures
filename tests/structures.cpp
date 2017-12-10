#include "../array.h"
#include "../list.h"
#include "../expanded_list.h"

#include "main_test.hpp"


template <class key_type, class value_type>
std::ostream& operator<<(std::ostream& stream, std::pair<key_type, value_type>& pair) {
    stream << "{" << pair.first << ", " << pair.second << "}";
    return stream;
}


template <class key_type, class value_type>
bool compare_func(const std::pair<key_type, value_type>& lhs, const std::pair<key_type, value_type>& rhs) {
    return lhs.first < rhs.first;
}


TEST_CASE( "Testing array" ) {
    SECTION("Add") {
        ad::array<std::pair<int, int>> mylist(1, 2, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(25, 45));
        REQUIRE(mylist[3] == std::pair<int, int>(76, 2));
    }

    SECTION("Erase") {
        ad::array<std::pair<int, int>> mylist(1, 2, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));
        mylist.erase(std::pair<int, int>(25, 45));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(76, 2));
    }

    SECTION("Search") {
        ad::array<std::pair<int, int>> mylist(1, 2, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(!mylist.search(std::pair<int, int>(0, 0)));
        REQUIRE(mylist.search(std::pair<int, int>(5, 26)));
    }
}


TEST_CASE( "Testing list" ) {
    SECTION("Add") {
        ad::list<std::pair<int, int>> mylist(compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(25, 45));
        REQUIRE(mylist[3] == std::pair<int, int>(76, 2));
    }

    SECTION("Erase") {
        ad::list<std::pair<int, int>> mylist(compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));
        mylist.erase(std::pair<int, int>(25, 45));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(76, 2));
    }

    SECTION("Search") {
        ad::list<std::pair<int, int>> mylist(compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(!mylist.search(std::pair<int, int>(0, 0)));
        REQUIRE(mylist.search(std::pair<int, int>(5, 26)));
    }
}


TEST_CASE( "Testing e_list" ) {
    SECTION("Add") {
        ad::expanded_list<std::pair<int, int>> mylist(3, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(25, 45));
        REQUIRE(mylist[3] == std::pair<int, int>(76, 2));
    }

    SECTION("Erase") {
        ad::expanded_list<std::pair<int, int>> mylist(3, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));
        mylist.erase(std::pair<int, int>(25, 45));

        REQUIRE(mylist[0] == std::pair<int, int>(2, 1));
        REQUIRE(mylist[1] == std::pair<int, int>(5, 26));
        REQUIRE(mylist[2] == std::pair<int, int>(76, 2));
    }

    SECTION("Search") {
        ad::expanded_list<std::pair<int, int>> mylist(3, compare_func<int, int>);

        mylist.add(std::pair<int, int>(5, 26));
        mylist.add(std::pair<int, int>(2, 1));
        mylist.add(std::pair<int, int>(25, 45));
        mylist.add(std::pair<int, int>(76, 2));

        REQUIRE(!mylist.search(std::pair<int, int>(0, 0)));
        REQUIRE(mylist.search(std::pair<int, int>(5, 26)));
    }
}
