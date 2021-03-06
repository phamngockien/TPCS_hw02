//
// Created by Pham Ngoc Kien on 10/2/2018.
//
// SNU-ID: 2018-36543
//
// Homework 02
// The codes here have been uploaded to https://github.com/phamngockien/TPCS_hw02
// In this homework we will use template to solve several problems related to containers,
// using the vector object from the standard template library (STL)
// in the std (standard) namespace.
//
#include <cmath> // for power calculation
//
// definition of header file
//
#ifndef TPCS_HW02_CONTAINERS_FUNCTIONS_HPP
#define TPCS_HW02_CONTAINERS_FUNCTIONS_HPP

//
// Homework 02-part01
// This function is to add two containers called "add"
//
template<typename T>
//
// input type T of to containers a and b,
// output type T
//
auto add(const T &a, const T &b) -> T
{
    T result = a;
    for (int i = 0; i < a.size(); ++i)
    {
        result[i] += b[i];
    }
    return result;
}

//
// Homework 02-part02
// Function to find the largest value in a container
//
template<typename T>
//
// input type T of container a,
// output type T
//
auto max(const T &a) -> typename T::value_type
{
    typename T::value_type largest = a[0];
    for (auto r:a)
    {
        if (largest < r)
        {
            largest = r;
        }
    }
    return largest;
}

//
// Homework 02-part03
// This function will evaluate the result for a container y with scalar x for input
// Suppose we want to have a polynomial y=a0+a1.x^1+a2.x^2+a3.x^3+⋯
// and store the coefficients in a container y=[a0,a1,a2,a3,…]
// This function returns the result of y(x) based on the coefficients in the container
//
template<typename Container, typename ring>
//
// input type Container of to container y and type ring of scalar x,
// output type ring
//
auto evaluate(const Container &y, const ring &x) -> ring
{
    auto result = 0;
    for (int i = 0; i < y.size(); ++i)
    {
        result += y[i] * pow(x, i);
    }
    return result;
}
//
// end of the header file
//
#endif //TPCS_HW02_CONTAINERS_FUNCTIONS_HPP
