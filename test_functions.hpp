//
// Created by Pham Ngoc Kien on 10/2/2018.
//
// SNU-ID: 2018-36543
//
// Homework 02
// The codes here have been uploaded to https://github.com/phamngockien/TPCS2018/commits/master
// In this homework we will use template to solve several problems related to containers,
// using the vector object from the standard template library (STL)
// in the std (standard) namespace.

#ifndef TPCS_HW02_TEST_FUNCTIONS_HPP
#define TPCS_HW02_TEST_FUNCTIONS_HPP
#include <iostream>
#include <functional>
#include <vector>
#include "containers_functions.hpp"
//
//create a function called "print_container" to print container.
//referenced from Mr. Erik Sevre
//
template<typename T>
void print_container(const T &t) {
    for (auto v:t)
    {
        std::cout << v <<" ";
    }
    std::cout << '\n';
}
//
// 2 test functions for function "add" 2 containers
//
//
// first, test with 2 vectors
//
bool test_f1() {
    //
    // examples of vectors for testing
    // 2 vectors must have the same size
    //
    std::vector<double> a = {1, 2, 3, 4, 5, 6};
    std::vector<double> b = {10, 10, 10, 10, 10, 10};
    //
    //the results for comparing
    //
    std::vector<double> add_vec = {11, 12, 13, 14, 15, 16};
    //
    // call "add" function to add the 2 containers
    //
    auto sum = add(a, b);
    //
    // printing results
    //
    std::cout << "-- test the function to sum 2 containers --  \n";
    std::cout << "-- with the containers are vectors --  \n";
    std::cout << "the two initial vectors is: \n";
    print_container(a);
    print_container(b);
    std::cout << "the sum of the two initial vectors is: \n";
    print_container(sum);
    std::cout << "------end of test function No 1 ------------------ \n";
    //
    // the test is failed if the difference
    // between any calculated element and the comparing result
    // exceeds the acceptable tolerance 10^-18
    //
        for (int i = 0; i <a.size() ; ++i)
        {
            if(sum[i] > add_vec[i]+1e-18 || sum[i] < add_vec[i]-1e-18)
            {
                return false;
            }
        }
        return true;
}
//
// second, test with 2 arrays
//
bool test_f2() {
    //
    // examples of arrays for testing
    // 2 arrays must have the same size
    //
    std::array<double,6> c = {1, 2, 3, 4, 5, 6};
    std::array<double,6> d = {1,1,1,1,1,1};
    //
    //the results for comparing
    //
    std::array<double,6> add_arr = {2, 3, 4, 5, 6, 7};
    //
    // call "add" function to add the 2 arrays
    //
    auto sum1 = add(c, d);
    //
    // printing results
    //
    std::cout << "-- test the function to sum 2 containers --  \n";
    std::cout << "-- with the containers are arrays --  \n";
    std::cout << "the two initial arrays is: \n";
    print_container(c);
    print_container(d);
    std::cout << "the sum of the two initial arrays is: \n";
    print_container(sum1);
    std::cout << "------end of test function No 2 ------------------ \n";
    // the test is failed if the difference
    // between any calculated element and the comparing result
    // exceeds the acceptable tolerance 10^-18
    //
   for (int i = 0; i <c.size() ; ++i)
    {
      if(sum1[i] > add_arr[i]+1e-18 || sum1[i] < add_arr[i]-1e-18)
      {
          return true;
      }
    }
    return true;
}
//
// 2 test functions for function "max" of a container
//
//
// first, test if the result = largest value of container
//
bool test_f3()
{
    //
    // examples of a vector and an array for testing
    //
    std::vector<double> a = {1, 2, 3, 6, 5, 4};
    std::array<double,6> c = {10, 2, 3, 4, 5, 6};
    //
    //the results for comparing
    //
    double max_a=6;
    double max_c=10;
    //
    // call "max" function to find the largest value of container
    // first for vector a, second for array c
    //
    auto max_value = max(a);
    auto max_value1 = max(c);
    //
    // print results
    //
    std::cout << "-- test if the function can find the true largest value of a container --  \n";
    std::cout << "-- example vector a is:  --  \n";
    print_container(a);
    std::cout << "the maximum value of vector a is: \n";
    std::cout << max_value << std::endl;
    std::cout << "-- example array c is:  --  \n";
    print_container(c);
    std::cout << "the maximum value of array c is: \n";
    std::cout << max_value1 << std::endl;
    std::cout << "------end of test function No 3 ------------------ \n";
    //
    // the test is failed if result is not equal to the largest value of container
    //
    if(max_value != max_a || max_value1 != max_c)
    {
        return false;
    }
    return true;
}
//
// second, test if the result >= any value of container
//
bool test_f4()
{
    //
    // examples of a vector and an array for testing
    //
    std::vector<double> a = {1, 2, 7, 6, 5, 4,2};
    std::array<double,6> c = {10, 2, 3, 18, 5, 6};
    //
    // call "max" function to find the largest value of container
    // first for vector a, second for array c
    //
    auto max_value = max(a);
    auto max_value1 = max(c);
    //
    // print results
    //
    std::cout << "-- test if the largest value of a container found by  the function --  \n";
    std::cout << "-- is equal to or larger than any value of the example container --  \n";
    std::cout << "-- example vector a is:  --  \n";
    print_container(a);
    std::cout << "the maximum value of vector a is: \n";
    std::cout << max_value << std::endl;
    std::cout << "-- example array c is:  --  \n";
    print_container(c);
    std::cout << "the maximum value of array c is: \n";
    std::cout << max_value1 << std::endl;
    std::cout << "------end of test function No 4 ------------------ \n";
    //
    // the test is failed if result is smaller than any value of container
    //
    //
    // in vector container
    //
    for (int i = 0; i <a.size() ; ++i)
    {
        if(max_value < a[i])
        {
            return false;
        }
    }
    //
    // in array container
    //
    for (int i = 0; i <c.size() ; ++i)
    {
        if(max_value1 < c[i])
        {
            return false;
        }
    }
    return true;
}
//
// 2 test functions for function "evaluate"
// which evaluates the result for a container y with scalar x for input
// Suppose we want to have a polynomial y=a0+a1.x^1+a2.x^2+a3.x^3+⋯
// first, test with container y is a vector
//
bool test_f5() {
    //
    // examples of vector y and scalar x for testing
    //
    std::vector<double> y = {2, 1, 1, 1, 0, 0,0,1};
    auto x = 2;
    //
    //the result for comparing
    //
    double y_x=144;
    //
    // call "evaluate" function to calculate y(x)
    //
    auto poly = evaluate(y, x);
    // print results
    std::cout << "-- test function to calculate y(x) with container y is a vector --  \n";
    std::cout << "the vector y includes: \n";
    print_container(y);
    std::cout << "the value x is: \n";
    std::cout << x << std::endl;
    std::cout << "the evaluation value of y(x) is: \n";
    std::cout << poly << std::endl;
    std::cout << "------end of test function No 5 ------------------ \n";
    //
    // the test is failed if the difference
    // between any calculated result and the comparing result
    // exceeds the acceptable tolerance 10^-18
    //
    if(poly > y_x+1e-18 || poly < y_x-1e-18)
    {
        return false;
    }
    return true;
}
//
// second, test with container y is an array
//
bool test_f6() {
    //
    // examples of array y and scalar x for testing
    //
    std::array<double,6> y = {1, 1, 1, 0, 0, 0};
    auto x = 1;
    //
    //the result for comparing
    //
    double y_x=3;
    //
    // call "evaluate" function to calculate y(x)
    //
    auto poly = evaluate(y, x);
    // print results
    std::cout << "-- test function to calculate y(x) with container y is an array --  \n";
    std::cout << "the array y includes: \n";
    print_container(y);
    std::cout << "the value x is: \n";
    std::cout << x << std::endl;
    std::cout << "the evaluation value of y(x) is: \n";
    std::cout << poly << std::endl;
    std::cout << "------end of test function No 6 ------------------ \n";
    //
    // the test is failed if the difference
    // between any calculated result and the comparing result
    // exceeds the acceptable tolerance 10^-18
    //
    if(poly > y_x+1e-18 || poly < y_x-1e-18)
    {
        return false;
    }
    return true;
}
// Run tests on a function and named input
bool run_test(
        std::function<bool(void)> fnc,
        std::string function_name)
{
    bool val = fnc();
    if (val){
        std::cout << "[OK] : test of function PASSED -> " << function_name << '\n';
    } else {
        std::cout << "[XX] : test of function FAILED -> " << function_name << '\n';
    }
    return val;
}


bool run_all_tests() {
    std::vector<bool> results;
    results.push_back( run_test(test_f1, "test f1") );
    results.push_back( run_test(test_f2, "test f2") );
    results.push_back( run_test(test_f3, "test f3") );
    results.push_back( run_test(test_f4, "test f4") );
    results.push_back( run_test(test_f5, "test f5") );
    results.push_back( run_test(test_f6, "test f6") );
    bool one_is_false = false;
    for (auto r : results) {
        if (!r) { one_is_false = true; }
    }

    if (!one_is_false) {
        std::cout << "all tests passed, yay\n";
        return true;
    } else {
        std::cout << "There was a failure :(\n";
        return false;
    }
}
#endif //TPCS_HW02_TEST_FUNCTIONS_HPP
