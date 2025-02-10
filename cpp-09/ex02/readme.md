# The merge insertion sort - Ford-Johnson algorithm

- Must take two different types of containers: vectors and dqueue.
- Argument list: unsorted positive intergers sequence
- Must be able to sort any number of positive intergers using merge-insertion sort
- Allow duplicates.
- Disallow non numeric characters.

## Design

templated mergeInsert class containing:

### Variables
- [X] templated Container< typename InnerContainer < int > >;
- [X] timer class;

### Methods
- [X] parsing methods;
- [X] sorting methods;

### Exceptions
- [X] exceptions for error handling
	- [X] isNegative
	- [X] badFormat
	- [X] forbiddenToken

- [X] overloaded << operator displaying output of timer class + sorted container.

# Concepts
## Template template parameters
- [Template template parameters](https://fbb-git.github.io/cppannotations/cppannotations/html/cplusplus23.html): see __23.4.2. Policy Classes: template template parameters.__

The syntaxe is as follows: 
```cpp
template < typename Container, template < typename > class typename InnerContainer,
		   typename Type = int >
```

# Recursive pairing function design:

This is pseudocode meant to visualize the behavior of the container.

```cpp
std::vector<std::vector<int>> container;

container[0] = {5, 10, 2, 0, 59, 18}

// first recursive call 
container[0] = {5, 10}
container[1] = {2, 0}
container[2] = {59,18}

// container.size() is 3;

// second recursive call
container[0] = {{5, 10}, {2, 0}}
container[1] = {59,18}

// container.size() is 2;

// exit since we can't make any more pairs.
```
# Ford-Johnson steps as per the Art of Computer Programming

For `n` elements:
1. Make pairwise comparisons of [n/2] disjoint pair of elements (if n is odd, leave one element out)
2. sort the [n/2] larger numbers found in 1. by merge insertion (using Ford-Johnson)
3. Name the elements `a1, a2, a3, ..., a[n/2], b1, b2 ... b[n/2]`. `b1` and the `a`s are the "main chain", the `b`s are the "pend chain". Insert the pend into the main, using binary insertion and taking the indexes from Jacobsthal suite.