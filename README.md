# bigInt Library

The `bigInt` class is a C++ library that provides support for working with large integer numbers. It allows arithmetic operations like addition, subtraction, multiplication, and division on big integers. The class overloads various comparison and arithmetic operators to facilitate these operations.

## Usage

To use the `bigInt` library, you need to include the `bigInt` class definition in your C++ program. Here's an example of how to use the `bigInt` class:

```cpp
#include<iostream>
#include "bigint.h"
using namespace std;

// Place the bigInt class definition here...

int main() {
    // Example usage of bigInt
    bigInt num1 = "123456789123456789";
    bigInt num2 = 987654321;
    
    bigInt sum = num1 + num2;
    cout << "Sum: " << sum << endl;
    
    bigInt product = num1 * num2;
    cout << "Product: " << product << endl;
    
    // Perform other operations as needed...
    
    return 0;
}

```
# bigInt Class Functions

## Constructors

- `bigInt()`: Default constructor that initializes the `bigInt` variable to zero.
- `bigInt(const char* num)`: Constructor to convert a char string to a `bigInt`.
- `bigInt(long long int num)`: Constructor to convert an integer to a `bigInt`.
- `bigInt(const bigInt &num)`: Copy constructor to create a `bigInt` from another `bigInt`.
- `bigInt(string num)`: Constructor to convert a string to a `bigInt`.

## Comparison Operators

- `bool operator == (const bigInt &b1, const bigInt &b2)`: Equality check for two `bigInt` numbers.
- `bool operator > (const bigInt &b1, const bigInt &b2)`: Greater than comparison for two `bigInt` numbers.
- `bool operator >= (const bigInt &b1, const bigInt &b2)`: Greater than or equal to comparison for two `bigInt` numbers.
- `bool operator < (const bigInt &b1, const bigInt &b2)`: Less than comparison for two `bigInt` numbers.
- `bool operator <= (const bigInt &b1, const bigInt &b2)`: Less than or equal to comparison for two `bigInt` numbers.
- `bool operator != (const bigInt &b1, const bigInt &b2)`: Inequality check for two `bigInt` numbers.

## Arithmetic Operations

- `bigInt operator + (const bigInt &num)`: Addition of two `bigInt` numbers.
- `bigInt operator - (const bigInt &num)`: Subtraction of two `bigInt` numbers.
- `bigInt operator * (const bigInt &num)`: Multiplication of two `bigInt` numbers.
- `bigInt operator / (const bigInt &num)`: Division of two `bigInt` numbers.

## Input Output Operations

- `void setData()`: Get user input for a `bigInt` number.
- `friend const ostream & operator << (ostream &out, const bigInt &a)`: Output a `bigInt` number to the standard output.
- `friend istream & operator >> (istream &in, bigInt &a)`: Input a `bigInt` number from the standard input.

## Note

The `bigInt` class supports both positive and negative numbers, and it can handle large integer values that are beyond the range of standard integer data types.

To use the `bigInt` class, include the relevant class definition in your C++ program and create `bigInt` objects to perform arithmetic operations on large integers.

Feel free to modify and enhance the library as per your requirements.


