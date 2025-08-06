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

See my readmes at [cpp-readmes](https://github.com/cdomet-d/cpp-readmes)
