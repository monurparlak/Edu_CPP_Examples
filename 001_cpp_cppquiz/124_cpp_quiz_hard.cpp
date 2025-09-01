/*
Question #124
Difficulty: 3
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: 2

Reason:
- `X` has two full specializations: `X<A>` and `X<B>`  
- `g` is a **template template parameter** with default argument: `template<typename T = B>`  
- Call `g<X>()`:
  - Inside `g`, `C<>` → uses default template argument **B** (from `template<typename T = B> class C`)  
  - So `X<B>::f()` is called → prints **2**

- Important:
  - Default template argument of **template template parameter** is used, not the one in `X` itself
  - Even though `X` defaults to `A`, `g` overrides the default to `B`.

If Wrong:
- Many assume it calls `X<A>::f()` because `X`'s primary template default is `A`; actually, the **template template parameter default argument applies**, so `B` is used.

Reference:
C++23 §17.9.3 — Template template parameters and default arguments
*/

#include <iostream>
using namespace std;

struct A {};
struct B {};

template<typename T = A>
struct X;

template<>
struct X<A> { static void f() { cout << 1; } };

template<>
struct X<B> { static void f() { cout << 2; } };

template<template<typename T = B> class C>
void g() { C<>::f(); }

int main() {
    g<X>(); // Output: 2
}
