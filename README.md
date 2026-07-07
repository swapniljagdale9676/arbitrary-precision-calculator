# Arbitrary Precision Calculator (APC)

An **Arbitrary Precision Calculator (APC)** implemented in **C** using **Doubly Linked Lists**. This project performs arithmetic operations on integers of virtually unlimited size, overcoming the limitations of built-in C data types such as `int`, `long`, and `long long`.

---

## 📖 Overview

Traditional C data types can store only numbers up to a fixed limit. When working with extremely large integers, these data types overflow and produce incorrect results.

This project solves that problem by storing **each digit as a node in a Doubly Linked List**, allowing arithmetic operations on numbers containing hundreds or even thousands of digits.

---

## ✨ Features

* ➕ Addition
* ➖ Subtraction
* ✖️ Multiplication
* ➗ Division
* Unlimited integer size (limited only by available memory)
* Efficient carry and borrow handling
* Dynamic memory allocation
* Modular code structure
* Clean and maintainable implementation

---

## 🛠 Technologies Used

* C Programming
* Doubly Linked Lists
* Dynamic Memory Allocation
* Data Structures
* Algorithms
* Pointers

---

## 📂 Project Structure

```
APC->
addition.c
apc.h
Function_definition.c
main.c
Makefile
modulus.c
multiplication.c
subtraction.c
validation_input.c

```


## ⚙️ How It Works

Instead of storing an entire number in a single variable, the calculator stores **each digit** in a separate node of a Doubly Linked List.

Example:

```
Number:
98765432109876543210

Stored as:

NULL <- 9 <-> 8 <-> 7 <-> 6 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> 0 <- NULL
```

Arithmetic operations are then performed digit-by-digit, similar to manual calculations.

---

## 🚀 Supported Operations

### Addition

```
Input:
99999999999999999999
+
1

Output:
100000000000000000000
```

---

### Subtraction

```
Input:
100000000000000000000
-
1

Output:
99999999999999999999
```

---

### Multiplication

```
Input:
123456789
*
987654321

Output:
121932631112635269
```

---

### Division

```
Input:
98765432109876543210
/
10

Output:
9876543210987654321
```

---

## 🧠 Concepts Used

* Doubly Linked List
* Dynamic Memory Allocation
* Pointer Manipulation
* Carry Propagation
* Borrow Handling
* Long Arithmetic
* Algorithm Design
* Modular Programming

---

## 🎯 Learning Outcomes

This project helped me gain practical experience with:

* Designing scalable data structures
* Memory management in C
* Implementing arithmetic algorithms
* Handling edge cases
* Writing modular and reusable code
* Improving problem-solving skills

---

## 🔮 Future Enhancements

* Support for decimal numbers
* Negative number support
* Modulus (%) operation
* Exponentiation
* Square root
* Expression evaluation
* Command-line argument support
* Performance optimization for multiplication and division

---

## 📸 Sample Output

```
---------------------------------------
ARBITRARY PRECISION CALCULATOR
---------------------------------------

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Exit

Enter your choice: 1

Enter Number 1:
99999999999999999999999999

Enter Number 2:
1

Result:
100000000000000000000000000
```

## 👨‍💻 Author

**Swapnil Jagdale**

Electronics & Telecommunication Engineering Student

Passionate about Embedded Systems, C Programming, Data Structures, and Software Development.

---

## ⭐ If you found this project useful, consider giving it a star!
