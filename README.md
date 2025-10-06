# String Abstract Data Type (ADT) – Data Structures & Algorithms Project

This project implements a **String Abstract Data Type (ADT)** in **C**, simulating built-in string behavior through a user-defined structure and dynamic memory allocation.

## 🧠 Features
- Encapsulated string structure with length and capacity tracking.
- Supports operations:
  - `Create()`, `Destroy()`
  - `Retrieve()`, `Print()`
  - `Concatenate()`, `Copy()`, `Compare()`
  - `Length()`, `Capacity()`
- Demonstrates memory management using `malloc()` and `free()`.
- Interactive console testing for multiple string operations.

## 🧰 Technologies Used
- **C Programming**
- **Dynamic Memory Allocation**
- **Pointer Manipulation**
- **Data Encapsulation**
- **Modular Design (Header + Source)**

## 💻 Example Usage
```c
string str1 = Create("Hello", 15);
string str2 = Create("World", 15);
Print(Concatenate(str1, str2));
Destroy(str1);
Destroy(str2);
