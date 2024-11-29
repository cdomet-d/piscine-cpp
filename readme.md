## Compiling:

- Use C++ compiler with -Wall, -Wextra, and -Werror flags.
- Code should compile with -std=c++98 flag.

## Formatting and Naming:

- Directory structure: ex00, ex01, ...
- Class names: UpperCamelCase.
- File names: Match class names.
- Output messages: End with newline.
- Avoid Norminette-style coding, but write clean, readable code.

## Allowed/Forbidden:

- Use standard C++ library, but avoid *printf(), *alloc(), and free().
- No external libraries (C++11, Boost).
- No using namespace or friend keywords (unless explicitly allowed).
- No STL containers or algorithms before Module 08 and 09.

## Design Requirements:

- Avoid memory leaks.
- Use Orthodox Canonical Form for classes (except when specified otherwise).
- Function implementations must be in .cpp files.
- Headers should be independently usable with include guards.

## General:

- Add additional files if needed.
- Pay attention to examples in guidelines.
- Read all modules before starting.
- Think critically and use your brain!

## Glossary
### Overhead (and runtime overhead)
- Overhead is the ressources needed to set up an operation. In computing, it refers to additional cost of resource usage incurred by certain implementation designs.
- Runtime overhead is overhead occuring as the program is running.

### Object-Oriented Programming

- **Class** : User-defined type encapsulating data and methods
- **Object** : Instance of a class
- **Constructor** : Special method called when object is created
- **Destructor** : Special method called when object is destroyed
- **Inheritance** : Mechanism for deriving new classes from existing classes
- **Polymorphism** : Ability of objects to take multiple forms
- **Encapsulation** : Hiding internal object details
- **Virtual Method** : Method that can be overridden in derived classes


# Ressources
- [Learncpp.com](https://www.learncpp.com/)
- [CPP // Oriented programming course](https://www.youtube.com/watch?v=iVLQeWbgbXs&list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN) (video)
- [CPP Standard](https://isocpp.org/)

--
Memory Management

    Stack: Memory region for automatic storage duration variables
    Heap: Memory region for dynamic memory allocation
    Pointer: Variable storing memory address of another variable
    Reference: Alias for an existing variable
    nullptr: Null pointer literal
    Memory Leak: Failure to release dynamically allocated memory

Object-Oriented Programming

    Class: User-defined type encapsulating data and methods
    Object: Instance of a class
    Constructor: Special method called when object is created
    Destructor: Special method called when object is destroyed
    Inheritance: Mechanism for deriving new classes from existing classes
    Polymorphism: Ability of objects to take multiple forms
    Encapsulation: Hiding internal object details
    Virtual Method: Method that can be overridden in derived classes

Type System

    Auto: Keyword for automatic type deduction
    Const: Qualifier preventing modification of a variable
    Static: Keyword for class-level or persistent variables
    Volatile: Qualifier indicating variable can change unexpectedly

Memory Allocation

    new: Operator for dynamic memory allocation
    delete: Operator for releasing dynamically allocated memory
    Smart Pointer: Automatic memory management pointer
    Unique Pointer: Exclusive ownership smart pointer
    Shared Pointer: Reference-counted smart pointer

Templates

    Template: Mechanism for generic programming
    Template Specialization: Custom implementation for specific types
    Template Metaprogramming: Compile-time computation using templates

Standard Library Concepts

    STL: Standard Template Library
    Container: Data structure holding collection of objects
    Iterator: Object for traversing container elements
    Algorithm: Predefined operations on containers

Advanced Concepts

    Lambda: Anonymous function object
    Namespace: Logical grouping of related code
    Exception: Error handling mechanism
    Move Semantics: Efficient transfer of resources
    Rvalue Reference: Reference to temporary objects

Compilation

    Compile-Time: Processing done before program execution
    Runtime: Processing during program execution
    Inline: Suggestion to compiler for function inlining
    Constexpr: Compile-time evaluated expressions

Modern C++ Features

    Range-Based For: Simplified iteration over containers
    Decltype: Operator to deduce type of an expression
    Noexcept: Specifier indicating no exceptions are thrown
    Nullptr: Strongly-typed null pointer
