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
09 | 20
00 | 16
04 | 08
01 | 05
12 | 17
01 | 04
03 | 10
11 | 13
```
sortEachElem:
> sort each element on the "max" of its element.
```
00 | 16
09 | 20
01 | 05
04 | 08
01 | 04
12 | 17
03 | 10
11 | 13
```
`ElemSize *= 2;`

ElemSize = 4;
> Each element has four numbers
```
00 16 | 09 20
01 05 | 04 08
01 04 | 12 17
03 10 | 11 13
```
sortEachElem:
> sort each element on the "max" of its element.
```
01 05 | 04 08
00 16 | 09 20
03 10 | 11 13
01 04 | 12 17
```
`ElemSize *= 2;`

ElemSize = 8;
> Each element has eight numbers
```
03 10 11 13 | 01 04 12 17
01 05 04 08 | 00 16 09 20
```
sortEachElem:
> sort each element on the "max" of its element.
```
03 10 11 13 | 01 04 12 17
01 05 04 08 | 00 16 09 20
```
`ElemSize *= 2;`

ElemSize = 16;
> Each element has sixteen numbers
```
03 10 11 13 01 04 12 17 | 01 05 04 08 00 16 09 20
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
main[0] = 03 10 11 13 // b0
main[1] = 01 04 12 17 // a0
main[2] = 00 16 09 20 // a1

// b1 | 01 05 04 08 remains to be placed


```
index of b + 2 = index of its brother a in main 