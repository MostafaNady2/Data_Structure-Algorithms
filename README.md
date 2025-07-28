# Data Structures & Algorithms

A comprehensive collection of data structures and algorithms implemented in multiple programming languages (C++ and Java) for educational and reference purposes.

## 📁 Project Structure

### Data Structures

#### Linear Data Structures
- **ArrayList**: Dynamic array implementation with automatic resizing
- **LinkedList**: Singly linked list with insertion, deletion, and traversal operations
- **Queue**: FIFO (First In, First Out) data structure implementation
- **Stack**: LIFO (Last In, First Out) data structure implementation

#### Non-Linear Data Structures
- **AVL Tree**: Self-balancing binary search tree with rotation operations
- **Binary Search Tree**: Basic BST with search, insert, and delete operations
- **Binary Tree**: General binary tree implementation with traversal methods

### Algorithms

#### Sorting Algorithms
- **Bubble Sort**: Simple comparison-based sorting algorithm
- **Insertion Sort**: Builds final sorted array one item at a time
- **Selection Sort**: In-place comparison sorting algorithm

## 🚀 Getting Started

### Prerequisites
- **C++ Compiler**: GCC 7.0+ or equivalent
- **Java**: JDK 8 or higher
- **IDE**: Any C++/Java compatible IDE (VS Code, IntelliJ IDEA, Eclipse)

### Running the Code

#### C++ Implementation
```bash
# Navigate to the C++ directory
cd Data_Structure/[Structure_Name]/C++

# Compile the code
g++ -o program [FileName].cpp

# Run the executable
./program
```

#### Java Implementation
```bash
# Navigate to the Java directory
cd Data_Structure/[Structure_Name]/Java

# Compile the Java file
javac [FileName].java

# Run the program
java [ClassName]
```

## 📚 Implementation Details

### Data Structures Overview

| Structure | Time Complexity | Space Complexity | Use Cases |
|-----------|----------------|------------------|-----------|
| ArrayList | Access: O(1), Insert: O(n) | O(n) | Dynamic arrays, frequent access |
| LinkedList | Access: O(n), Insert: O(1) | O(n) | Frequent insertions/deletions |
| Stack | Push/Pop: O(1) | O(n) | Function calls, expression evaluation |
| Queue | Enqueue/Dequeue: O(1) | O(n) | BFS, process scheduling |
| Binary Tree | Search: O(n) | O(n) | Hierarchical data representation |
| BST | Search/Insert: O(log n) avg | O(n) | Ordered data, searching |
| AVL Tree | Search/Insert: O(log n) | O(n) | Guaranteed balanced operations |

### Sorting Algorithms Overview

| Algorithm | Time Complexity | Space Complexity | Stability |
|-----------|----------------|------------------|-----------|
| Bubble Sort | O(n²) | O(1) | Stable |
| Insertion Sort | O(n²) | O(1) | Stable |
| Selection Sort | O(n²) | O(1) | Unstable |

## 🔧 Features

- **Multi-language Support**: Implementations in both C++ and Java
- **Comprehensive Coverage**: Essential data structures and sorting algorithms
- **Educational Focus**: Clean, well-commented code for learning purposes
- **Modular Design**: Each data structure/algorithm in separate files
- **Main Classes**: Include example usage and testing code

## 📖 Usage Examples

Each implementation includes a `Main` class/function demonstrating:
- Basic operations (insert, delete, search)
- Edge case handling
- Performance characteristics
- Sample input/output

## 📝 Code Structure

```
data_structure&algorithms/
├── Data_Structure/
│   ├── Linear/
│   │   ├── ArrayList/
│   │   │   ├── C++/
│   │   │   └── Java/
│   │   ├── LinkedList/
│   │   ├── Queue/
│   │   └── Stack/
│   └── Non_Linear/
│       ├── AVL_Tree/
│       ├── Binary_Search_Tree/
│       └── Binary_Tree/
└── Algorithms/
    └── Sorting/
        ├── Bubble_Sort/
        ├── Insertion_Sort/
        └── Selection_Sort/
```

## 🤝 Contributing

Contributions are welcome! Please feel free to:
- Add new data structures or algorithms
- Improve existing implementations
- Add more language implementations
- Enhance documentation
- Fix bugs or optimize code


**Happy Coding! 🚀**