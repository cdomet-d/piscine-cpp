# The merge insertion sort - Ford-Johnson algorithm

- Must take two different types of containers: vectors and dqueue.
- Argument list: unsorted positive intergers sequence
- Must be able to sort any number of positive intergers using merge-insertion sort
- Allow duplicates.
- Disallow non numeric characters.

## Design

templated mergeInsert class containing:

### Variables
- [X] templated container;
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