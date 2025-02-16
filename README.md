# Custom Vector Implementation in C++

This project implements a custom `Vector` class in C++ that mimics the functionality of dynamic arrays with additional features. The implementation includes various operations such as insertion, deletion, sorting, set operations, and operator overloading.

---

## Features

- **Dynamic Resizing**: Automatically resizes the vector when needed.
- **Element Operations**:
  - `push_back()`: Add an element to the end.
  - `pop_back()`: Remove the last element.
  - `insert()`: Insert an element at a specific index.
  - `erase()`: Remove an element at a specific index.
- **Sorting**: Sort the vector in ascending order.
- **Set Operations**:
  - `unionOfVectors()`: Compute the union of two vectors.
  - `intersectionOfVectors()`: Compute the intersection of two vectors.
  - `subset()`: Check if one vector is a subset of another.
- **Operator Overloading**:
  - `+`: Vector addition.
  - `-`: Vector subtraction.
  - `==`: Check if two vectors are equal.
  - `>`: Check if one vector is greater than another.
  - `<`: Check if one vector is less than another.
  - `[]`: Access elements using the subscript operator.
- **Error Handling**: Uses exceptions to handle invalid operations (e.g., out-of-bounds access).
- **Unique Elements**: Extract unique elements from the vector.
- **Search**: Check if an element exists in the vector.

---

## Table of Contents

- [How to Use](#how-to-use)
- [Files in the Project](#files-in-the-project)
- [Compilation and Execution](#compilation-and-execution)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

---

## How to Use

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/Custom-Vector-Implementation.git