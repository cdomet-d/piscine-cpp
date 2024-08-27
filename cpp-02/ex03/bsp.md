## General ressources & definitions

- [Determine if a point is inside a triangle](https://www.youtube.com/watch?v=kkucCUlyIUE) (french | video)

# The global idea
**The goal**
Given four points, three of which form the summits of a triangle, we must determine if the fourth one is inside or outside the triangle. 

The theory for this is to determine the following :

**Given the following triangle :**
![alt text](image.png)
In order to be within the triangle, a point `D` must be
- right of the vector [AB]
- left of the vector [AC]
- on top of the vector [BC]

> A vector is an object that represents a direction and a quantity. It is finite, meaning that the vector AB starts a A and ends at B. For the purpose of this exercice, you can think of them as segments.

## Determining on which side of a vector a point is
To determine if a point is on the right or left side of our vector [AB], we are going to determine the area of the polygon formed by [DA] and [DB].
![alt text](image-1.png)

The area of a vector is calculated with the same formula as with segments, which is 

```math
	area = lenght * width
```

So we must obtain the lenght of both vectors DA and DB. We'll use the distance formula to obtain this information :

```math
	distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
```
Basically, the distance between two points is obtained thusly : 
- `(x2 - x1)^2` is the square of the horizontal distance between the two x points
- `(y2 - y1)^2` is the square of the vertical distance between the two y points
- we then get the sum of that operation and square root it to obtain the distance. 