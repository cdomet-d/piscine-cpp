# CPP Piscine

- [CPP Piscine](#cpp-piscine)
	- [Guidelines](#guidelines)
		- [Compilation](#compilation)
		- [Formatting and Naming](#formatting-and-naming)
		- [Allowed/Forbidden](#allowedforbidden)
		- [Design Requirements](#design-requirements)
		- [General](#general)
	- [General ressources](#general-ressources)
	- [Readmes](#readmes)
		- [CPP02](#cpp02)
		- [CPP03](#cpp03)
		- [CPP06](#cpp06)
		- [CPP07](#cpp07)
		- [CPP08](#cpp08)

## Guidelines

### Compilation

- Use C++ compiler with -Wall, -Wextra, and -Werror flags.
- Code should compile with -std=c++98 flag.

### Formatting and Naming

- Directory structure: ex00, ex01, ...
- Class names: UpperCamelCase.
- File names: Match class names.
- Output messages: End with newline.
- Avoid Norminette-style coding, but write clean, readable code.

### Allowed/Forbidden

- Use standard C++ library, but avoid *printf(),*alloc(), and free().
- No external libraries (C++11, Boost).
- No using namespace or friend keywords (unless explicitly allowed).
- No STL containers or algorithms before Module 08 and 09.

### Design Requirements

- Avoid memory leaks.
- Use Orthodox Canonical Form for classes (except when specified otherwise).
- Function implementations must be in .cpp files.
- Headers should be independently usable with include guards.

### General

- Add additional files if needed.
- Pay attention to examples in guidelines.
- Read all modules before starting.
- Think critically and use your brain!

## General ressources

- [CPP // Oriented programming course](https://www.youtube.com/watch?v=iVLQeWbgbXs&list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN) (video)
- [CPP Standard](https://isocpp.org/)
- [Getting started with C++](https://stungeye.github.io/Programming-1-Notes/docs/05-introduction-to-cpp/01-getting-started.html)
- [Learncpp.com](https://www.learncpp.com/)
- [CPPreference](https://en.cppreference.com/w/)
  - This one a little dense. Use it like a man, to know functions parameters and uses, etc...

## Readmes

### CPP02

- [Canonical Classes](cpp-readmes/cpp02-canonical_classes.md)
- [Binary Space Partion](cpp-readmes/cpp02%20-%20bsp.md)
- [Floating Point Numbers](cpp-readmes/cpp02%20-%20floating_points_numbers.md)
- [Operator Overloading](cpp-readmes/cpp02%20-%20operator_overload.md)

### CPP03

- [Inheritance](cpp-readmes/cpp03%20-%20inheritance.md)
  
### CPP06

- [Casting in CPP](cpp-readmes/cpp06%20-%20cast.md)

### CPP07

- [Templating](cpp-readmes/cpp07%20-%20templates.md)

### CPP08

- [Containers](cpp-readmes/cpp08%20-%20containers.md)
- [Why do we need reverse iterators ?](cpp-readmes/cpp08%20-%20reverse-iterator.md)
