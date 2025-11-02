# 📚 Push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations, optimized for the minimum number of moves.

## 🎯 Project Overview

**Push_swap** is a 42 School project that challenges you to sort data on a stack with a limited set of instructions, using the lowest possible number of operations. The project consists of two programs:
- `push_swap`: Outputs the optimal sequence of operations to sort the stack
- `checker`: Validates whether a given sequence of operations correctly sorts the stack

![Image](https://github.com/user-attachments/assets/96ee932f-6443-4aa4-8272-b693aece4511)

## 📋 Table of Contents
- [Features](#-features)
- [Algorithm](#-algorithm)
- [Installation](#-installation)
- [Usage](#-usage)
- [Available Operations](#-available-operations)
- [Project Structure](#-project-structure)
- [Performance](#-performance)
- [Error Handling](#️-error-handling)
- [Make Commands](#️-make-commands)
- [Author](#-author)

## ✨ Features

- **Optimized sorting algorithm** using chunk-based approach for larger datasets
- **Special optimizations** for small stacks (2, 3, and 5 elements)
- **Error handling** for invalid inputs (duplicates, non-integers, overflow)
- **Checker program** to validate operation sequences
- **Custom ft_printf** implementation included
- **Memory leak free** - proper cleanup of allocated resources

## 🧮 Algorithm

The sorting strategy varies based on the stack size:

### Small Stacks (2-3 elements)
- **2 elements**: Simple swap if needed
- **3 elements**: Optimized hardcoded solution (max 2 operations)

### Medium Stacks (4-5 elements)
- Push smallest elements to stack B
- Sort remaining elements in stack A
- Push back to stack A

### Large Stacks (>5 elements)
- **Chunk-based algorithm** with ranking system
- Elements are ranked and divided into chunks
- Push elements to stack B in chunks
- Push back to stack A in descending order
- Optimizations for reverse rotations and smart positioning

## 🔧 Installation

```bash
# Clone the repository
git clone https://github.com/Adavitas/push_swap.git
cd push_swap

# Compile the project
make

# This creates two executables: push_swap and checker
```

### Compilation Flags
The project is compiled with: `-Wall -Wextra -Werror`

## 🚀 Usage

### Push_swap

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Using quotes (single argument)
./push_swap "4 67 3 87 23"

# With negative numbers
./push_swap -5 2 -8 10 3
```

Output: A sequence of operations to sort the stack
```
pb
pb
sa
pa
pa
```

### Checker

```bash
# Validate a sequence of operations
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK (if sorted) or KO (if not sorted)

# Manual input (interactive mode)
./checker 4 67 3 87 23
sa
pb
pa
[Ctrl+D]
# Output: OK or KO
```

## 🎮 Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack A |
| `sb` | Swap the first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of B to A |
| `pb` | Push the first element of A to B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` at the same time |

## 📂 Project Structure

```
push_swap/
├── Makefile                    # Build configuration
├── includes/                   # Header files
│   ├── push_swap.h            # Main header
│   ├── checker.h              # Checker header
│   ├── utils.h                # Utilities header
│   └── ft_printf.h            # Printf header
├── src/
│   ├── push_swap/             # Main program source
│   │   ├── push_swap.c        # Entry point
│   │   ├── ft_sort_algo.c     # Main sorting algorithm
│   │   ├── ft_sort_small.c    # Small stack optimizations
│   │   ├── ft_sort_stack.c    # Stack sorting logic
│   │   ├── ft_init_rank.c     # Ranking system
│   │   ├── ft_utilis_algo.c   # Algorithm utilities
│   │   ├── ft_operations_vol1.c # Operations (sa, sb, pa, pb)
│   │   ├── ft_operations_vol2.c # Operations (ra, rb, rra, rrb)
│   │   └── ft_operations_vol3.c # Base operations
│   └── checker/               # Checker program source
│       ├── checker.c          # Checker entry point
│       ├── ft_operations_check.c # Operation validation
│       ├── get_next_line.c    # Read operations
│       └── get_next_line_utils.c
├── utils/                     # Utility functions
│   ├── ft_check_err.c         # Error checking
│   ├── ft_lib_utils.c         # Library utilities
│   ├── ft_node.c              # Stack node operations
│   ├── ft_split.c             # String splitting
│   └── ft_utilis.c            # General utilities
└── ft_printf/                 # Custom printf implementation
```

## 📊 Performance

Expected number of operations for random lists:

| Stack Size | Max Operations (for top grade) |
|------------|-------------------------------|
| 3 elements | 2-3 operations |
| 5 elements | ≤ 12 operations |
| 100 elements | < 700 operations |
| 500 elements | < 5500 operations |

*Performance may vary based on the specific numbers and their initial order.*

## ⚠️ Error Handling

The program handles various error cases:
- Non-integer arguments
- Integer overflow
- Duplicate numbers
- Empty or invalid input

Error output: `Error\n` to stderr

## 🛠️ Make Commands

```bash
make          # Compile both push_swap and checker
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Recompile everything
```

## 🧪 Testing Examples

```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with 100 random numbers
ARG="4 67 3 87 23 ..."; ./push_swap $ARG | wc -l

# Verify correctness
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## 👨‍💻 Author

**Aleksandre Davitashvili** (Adavitas) - *42 Student*

[![GitHub](https://img.shields.io/badge/GitHub-Adavitas-181717?style=flat&logo=github)](https://github.com/Adavitas)

## 📝 License

This project is part of the 42 School curriculum.

---

*This project was created as part of the 42 School common core curriculum.*
