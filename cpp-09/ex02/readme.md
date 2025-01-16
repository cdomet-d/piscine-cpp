# The merge insertion sort - Ford-Johnson algorithm

- Must take two different types of containers: vectors and dqueue.
- Argument list: unsorted positive intergers sequence
- Must be able to sort any number of positive intergers using merge-insertion sort
- Allow duplicates.
- Disallow non numeric characters.

## Design

templated mergeInsert class containing:

### Variables
- [X] templated Container< InnerContainer < int > >;
- [X] timer class;

### Methods
- [ ] parsing methods;
- [ ] sorting methods;

### Exceptions
- [X] exceptions for error handling
	- [X] isNegative
	- [X] badFormat
	- [X] forbiddenToken

- [ ] overloaded << operator displaying output of timer class + sorted container.

# Concepts
## Template template parameters
- [Template template parameters](https://fbb-git.github.io/cppannotations/cppannotations/html/cplusplus23.html): see __23.4.2. Policy Classes: template template parameters.__

The syntaxe is as follows: 
```cpp
template < typename Container, template < typename > class InnerContainer,
		   typename Type = int >
```