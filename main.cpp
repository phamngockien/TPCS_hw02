#include <iostream>
#include <vector>
#include <array>
#include "containers_functions.hpp"

//create a function called "print_container" to print container.
//referenced from Mr. Erik Sevre
template<typename T>
void print_container(const T &t) {
    for (int i = 0; i < t.size(); ++i) {
        std::cout << t[i] << ' ';
    }
    //after for loop the next thing will be printed in a new line
    std::cout << '\n';
}

int main() {
//
// examples of vectors and arrays for testing
//
    std::vector<double> a = {1, 2, 3, 4, 5, 6};
    std::vector<double> b = {10, 10, 10, 10, 10, 10};
    std::array<double,6> c = {1, 2, 3, 4, 5, 6};
    std::array<double,6> d = {1, 1, 1, 1, 1, 1};
    //
    //the results for comparing
    //
    std::vector<double> add_vec = {11, 12, 13, 14, 15, 16};
    std::array<double,6> add_arr = {2, 3, 4, 5, 6, 7};
    //
    // call add function to add the 2 containers
    //
    auto sum = add(a, b);
    auto sum1 = add(c, d);
    // if do a+c or c+b it will not work because of the difference types of parameters
//
    // printing results
  //
    std::cout << "-- test the function to sum the 2 containers --  \n";
    std::cout << "the two initial vectors is: \n";
    print_container(a);
    print_container(b);
    std::cout << "the sum of the two initial vectors is: \n";
    print_container(sum);
    std::cout << "the two initial arrays is: \n";
    print_container(c);
    print_container(d);
    std::cout << "the sum of the two initial arrays is: \n";
    print_container(sum1);
//
    //test max value
  //
    auto max_value = max(a);
    std::cout << "the maximum value of a is: \n";
    std::cout << max_value << std::endl;

    //
    //test evaluate function
    //
    std::vector<double> y = {2, 1, 1, 1, 0, 0,0,1};
    auto x = 2;
    auto poly = evaluate(y, x);
    std::cout << "the container y includes: \n";
    print_container(y);
    std::cout << "the value x is: \n";
    std::cout << x << std::endl;
    // this code is error: print_container(x);
    std::cout << "the evaluation value of y(x) is: \n";
    std::cout << poly << std::endl;
}