# Implementation

C++ implementation of data structures.

## NewVector – Custom C++ Vector Implementation

## 📌 Overview

`NewVector` is a simplified custom implementation of `std::vector<int>` written in C++.  
This project demonstrates **dynamic memory management**, **Rule of Three**, and **basic container design**.

It is intended for **learning internals of STL containers** and **C++ interview preparation**.

---

## 🚀 Features

- Dynamic array allocation
- Automatic capacity growth
- Bounds-checked element access
- Deep copy support
- Efficient memory reuse

---

## 🧱 Class Interface

### Constructors

- `NewVector()`  
  Creates an empty vector.
- `NewVector(int count, int value)`  
  Creates a vector with `count` copies of `value`.
- Copy constructor  
  Performs deep copy of another vector.

### Operators

- `operator[]` – Access or modify element (with bounds check)
- Assignment operator – Deep copy assignment

### Member Functions

- `size()` – Returns number of elements
- `capacity()` – Returns allocated capacity
- `empty()` – Checks if vector is empty
- `push_back(value)` – Adds element at the end
- `pop_back()` – Removes and returns last element
- `clear()` – Removes all elements (keeps memory)
- `print()` – Displays vector contents
-
