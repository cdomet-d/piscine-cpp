# The merge insertion sort - Ford-Johnson algorithm

- Must take two different types of containers: vectors and dqueue.
- Argument list: unsorted positive intergers sequence
- Must be able to sort any number of positive intergers using merge-insertion sort
- Allow duplicates.
- Disallow non numeric characters.

## Design

templated mergeInsert class containing:
- a container;
- timer class;
- overloaded << operator displaying output of timer class + sorted container.
- parsing methods;
- sorting methods;
- exceptions for error handling
	- isNegative
	- badFormat
	- forbiddenToken
