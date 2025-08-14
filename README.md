
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
- **HashMap**: Key-value storage implementation using hashing
- **HashSet**: Unique element storage using hashing principles

### Algorithms

#### Sorting Algorithms
- **Bubble Sort**: Simple comparison-based sorting algorithm
- **Insertion Sort**: Builds final sorted array one item at a time
- **Selection Sort**: In-place comparison sorting algorithm
- **Merge Sort**: Divide-and-conquer algorithm with O(n log n) complexity
- **Quick Sort**: Efficient in-place sorting using partitioning

#### Searching Algorithms
- **Binary Search**: O(log n) search in sorted collections
- **Linear Search**: O(n) sequential search algorithm

#### Compression Algorithms
- **Huffman Coding**: Lossless data compression using prefix codes

## 🚀 Getting Started

### Prerequisites
- **C++ Compiler**: GCC 7.0+ or equivalent
- **Java**: JDK 8 or higher
- **IDE**: Any C++/Java compatible IDE (VS Code, IntelliJ IDEA, Eclipse)

### Running the Code

#### C++ Implementation
```bash
# Navigate to the C++ directory
cd Algorithms/[Algorithm_Name]/C++  # For algorithms
cd Data_Structure/[Structure_Name]/C++  # For data structures

# Compile the code
g++ -o program [FileName].cpp

# Run the executable
./program
```

#### Java Implementation
```bash
# Navigate to the Java directory
cd Algorithms/[Algorithm_Name]/Java  # For algorithms
cd Data_Structure/[Structure_Name]/Java  # For data structures

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
| HashMap | Insert/Search: O(1) avg | O(n) | Key-value storage, dictionaries |
| HashSet | Insert/Search: O(1) avg | O(n) | Unique element collections |

### Sorting Algorithms Overview

| Algorithm | Time Complexity | Space Complexity | Stability |
|-----------|----------------|------------------|-----------|
| Bubble Sort | O(n²) | O(1) | Stable |
| Insertion Sort | O(n²) | O(1) | Stable |
| Selection Sort | O(n²) | O(1) | Unstable |
| Merge Sort | O(n log n) | O(n) | Stable |
| Quick Sort | O(n log n) avg | O(log n) | Unstable |

### Other Algorithms

| Algorithm | Time Complexity | Space Complexity | Use Cases |
|-----------|----------------|------------------|-----------|
| Binary Search | O(log n) | O(1) | Sorted collections |
| Linear Search | O(n) | O(1) | Unsorted collections |
| Huffman Coding | O(n log n) | O(n) | Data compression |

## 🔧 Features

- **Multi-language Support**: Implementations in both C++ and Java
- **Comprehensive Coverage**: Essential data structures and algorithms
- **Educational Focus**: Clean, well-commented code for learning
- **Modular Design**: Each implementation in separate directories
- **Main Classes**: Include example usage and testing code
- **Algorithm Variety**: Sorting, searching, and compression techniques
- **Data Structure Diversity**: Both linear and non-linear structures

## 📖 Usage Examples

Each implementation includes a `Main` class/function demonstrating:
- Basic operations (insert, delete, search, sort)
- Edge case handling
- Performance characteristics
- Sample input/output
- Practical use cases

## 📝 Repository Structure

```
.
├── Algorithms
│   ├── Huffman_Coding
│   │   ├── C++
│   │   └── Java
│   ├── Searching
│   │   ├── Binary_Search
│   │   └── Linear_Search
│   └── Sorting
│       ├── Bubble_Sort
│       ├── Insertion_Sort
│       ├── Merge_Sort
│       ├── Quick_Sort
│       └── Selection_Sort
├── Data_Structure
│   ├── Linear
│   │   ├── ArrayList
│   │   ├── LinkedList
│   │   ├── Queue
│   │   └── Stack
│   └── Non_Linear
│       ├── AVL_Tree
│       ├── Binary_Search_Tree
│       ├── Binary_Tree
│       ├── HashMap
│       └── HashSet
└── README.md
```

## 🤝 Contributing

Contributions are welcome! Please feel free to:
- Add new data structures or algorithms
- Improve existing implementations
- Add more language implementations (Python, JavaScript, etc.)
- Enhance documentation and comments
- Fix bugs or optimize code
- Add test cases and examples

**Happy Coding! 🚀**
