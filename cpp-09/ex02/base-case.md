# Content
1. [Grouping elements](#1-grouping-elements)
2. [Inserting elements](#2-inserting-elements)
	- 2.a. [Determining the range in which we perform binary search](#determining-the-range-in-which-we-perform-binary-search)
	- 2.b. [Example](#example)

# 1. Grouping elements

ElemSize = 1;

> Each element has a single number

```
20
09
00
16
04
08
01
05
17
12
06
14
10
03
13
11
```
sortEachElem:
> sort each element on the "max" of its element.
```
09
20
00
16
04
08
01
05
12
17
06
14
03
10
11
13
```

`ElemSize *= 2;`

ElemSize = 2;
> Each element has two numbers

```
09 20
00 16
04 08
01 05
12 17
06 14
03 10
11 13
```
sortEachElem:
> sort each element on the "max" of its element.
```
00 16
09 20
01 05
04 08
06 14
12 17
03 10
11 13
```
`ElemSize *= 2;`

ElemSize = 4;
> Each element has four numbers
```
00 16 09 20
01 05 04 08
06 14 12 17
03 10 11 13
```
sortEachElem:
> sort each element on the "max" of its element.
```
01 05 04 08
00 16 09 20
03 10 11 13
06 14 12 17
```
`ElemSize *= 2;`

ElemSize = 8;
> Each element has eight numbers
```
01 05 04 08 00 16 09 20
03 10 11 13 06 14 12 17
```
sortEachElem:
> sort each element on the "max" of its element.
```
03 10 11 13 06 14 12 17
01 05 04 08 00 16 09 20
```
`ElemSize *= 2;`

ElemSize = 16;
> Each element has sixteen numbers
```
03 10 11 13 06 14 12 17
01 05 04 08 00 16 09 20
```

Cannot form any more pairs:
> exit recursion and start the opposite process

# 2. Inserting elements
`ElemSize /= 2;`

ElemSize = 8;
> Each element has eight numbers
```
b0 | 03 10 11 13 01 04 12 17
a0 | 01 05 04 08 00 16 09 20
```
> We only have two elements, `b0` and `a0` > they can stay like this because they are already sorted on their max. 

`ElemSize /= 2;`

ElemSize = 4;
> Each element has four numbers
```
0 | b0 | 03 10 11 13 
1 | a0 | 01 04 12 17
2 | b1 | 01 05 04 08 
3 | a1 | 00 16 09 20
```
> We have more than two elements: they need to be sorted.

> In another data structure, we put `b0` and every `a`.

```
Structure main;
vector<int> sisterIndex;

main[0] = 03 10 11 13 // b0
main[1] = 01 04 12 17 // a0
main[2] = 00 16 09 20 // a1

sisterIndex[0] = 2 (a1 is at index 2 of main);

// b1 | 01 05 04 08 remains to be placed
```

## Determining the range in which we perform binary search
- When putting the `a`s in main, keep track of the index of each of them so when the times comes to insert the bs we know where their sisters are in main. 
- We aim to insert the current b in the range [0 - index of its sister `a` pair].

The issue is: how do we keep track of where the sister pairs are in main ? 

The idea is to create a new vector called `sisterIndex` that will store the indexes of the `a`s in main. 

The rules are as follow:
	- For the index of each `b` in pend, we can recover at the same index in `sisterIndex` the index of the associated `a` in main.
	- we keep track of only a1 and after, since a0 and b0 are placed together.

## Example
Given the following setting: 

```cpp
arr[0] : {03 06 08 07}
arr[1] : {02 10 05 20}
arr[2] : {04 09 01 25}
arr[3] : {12 27 11 30}
```

We create the following main and pend:

```cpp
main[0] : 03 06 (b0)
main[1] : 08 07 (a0)
main[2] : 05 20 (a1)
main[3] : 01 25 (a2)
main[4] : 11 30 (a3)

pend[0] : 02 10 (b1)
pend[1] : 04 09 (b2)
pend[2] : 12 27 (b3)
```
We create `sisterIndex` and initialize it as we insert the `a`s in main. 
Let's track the current indexes of the `a`s in `main` in a vector called `sisterIndex`.
We get the following values:

```cpp
sisIndex[0] = 2 (a1); // a1 is at index 2 of main
sisIndex[1] = 3 (a2); // a2 is a index 3 of main
sisIndex[2] = 4 (a3); // etc...
```
This side by side comparison confirms that using the index in pend of the `b` we want to insert allows use to find the index of its sister pair, hence determining the maximum range of our binary search.
```
sisIndex[0] = 2 (a1); // a1 is at index 2 of main			pend[0] : 02 10 (b1)
sisIndex[1] = 3 (a2); // a2 is a index 3 of main			pend[1] : 04 09 (b2)
sisIndex[2] = 4 (a3); // etc...								pend[2] : 12 27 (b3)
```
For instance, using Jacobstahl numbers, let's try to insert `b3`, which is at `pend[2]`. 


```cpp
static size_t getInsertionRange(indexOfB) {
	return sisterIndex[indexOfB]; // sisterIndex[2] == 4;
}

size_t indexOfCurrentB = 2; // because our current b is at pend[2]
size_t rangeMax = getInsertionRange(indexOfCurrentB);
```
So we will try to insert b between 0 and 4 in the main. Knowing that our range is always from the start of the main (0) to but excluding the index of the `a` sister pair, our range is [0 - 3];

Lets do it:
```cpp
size_t i = median of range [0 - 3];
for (/* b is not inserted*/)
	if (maxOfB(currentB) > maxOfA[i])
		newRange = median of [i - 3];
	else
		newRange = median of [0 - i];
```
`b3`s place is before `main[4]`, so we insert `pend[2]` at `main[4]`. The new `main` is: 
```cpp
/* before */										/* after */
main[0] : 03 06 (b0)								main[0] : 3 6 (b0)
main[1] : 08 07 (a0)								main[1] : 8 7 (a0)
main[2] : 05 20 (a1)								main[2] : 5 20 (a1)
main[3] : 01 25 (a2) /* b3 > maxA2 && b3 < maxA3 */	main[3] : 1 25 (a2)
main[4] : 11 30 (a3)								main[4] : 12 27 (b3)
													main[5] : 11 30 (a3)
```
Our `sisterIndex` array is invalidated, so we must update it. 

Using the index at which we just inserted our element (which is `4`, in this example), we find its value in sisterIndex:
```cpp
// three is at sisterIndex[1].
for (auto it = sisIndex.find(4); it != sisIndex.end(); ++it)
{
	*it++;
}
```
After updating sisIndex & comparing it with main, we see that the `a`s indexes are correct once more:
```
							main[0] : 3 6 (b0)
							main[1] : 8 7 (a0)
sisIndex[0] = 2 (a1);		main[2] : 5 20 (a1)
sisIndex[1] = 3 (a2);		main[3] : 1 25 (a2)
							main[4] : 12 27 (b3)
sisIndex[2] = 5 (a3);		main[5] : 11 30 (a3)
```
# Inserting using Jacobstahl numbers:

> Making the best of binary search

> To perform a minimal number of comparisons, we need to take into account the following observation about binary search: the maximal number of comparisons needed to perform a binary search on a sorted sequence is the same when the number of elements is 2n and when it is 2n+1−1. For example, looking for an element in a sorted sequence of 8 or 15 elements requires the same number of comparisons.

> Many insertion-based sorting algorithms perform binary searches to find where to insert elements, but most of them don't take that property of binary search into account.

in that [StackExchange post](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort).

Basically, we want to take advantage of the fact that the worst case for binary search increases when its lenghts increases from a power of two to another. For instance, the worst case for an array of size 8 will remain the same until the lenght of the array becomes 16.

Inserting numbers using Jacobstahl sequence allows us to