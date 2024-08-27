## General ressources & definitions

## Time for some geometry
We are going to solve this problem using geometry and pain. 
For this, we are going to need a few concepts, which you skip if you're already familiar with. The goal is to use **vectors** to determine the **barycentric coordinates** of a point P as related to three **vertices** A, B and C.

## Definitions

### 1. Euclidean Vector
- [Eclidean vectors](https://en.wikipedia.org/wiki/Euclidean_vector)

Vectors, in geometry, are objects that have a given *lenght* and a *direction*. They can be added and scaled. It's basically the distance going from a point A to a point B in space. Vectors can be many things, but in the current situation, this definition is enough. 

### 2. Vertices
- [Vertices of a triangle](https://mathmonks.com/triangle/vertices-of-a-triangle)
> singular is *vertex*, so a vertex, several vertices

In geometry, a vertex is a point where two straight lines intersect. A triangle being composed of three lines, it possesses three vertices. 

### 3. Barycentric Coordinates

A barycentric coordinate represent a point as the weighted sum of the vertices of a simplex.

> a simplex is a triangle or tetrahedron in any dimension you want (2D, 3D).

Given a triangle ABC, you can get the barycentric coordinate of any point in the triangle with the following equation (which is called a *convex combination*).

```math
	barycentric = A1 * A + B1 * B + C1 * C
```
1. For a point to be inside the triangle, A1, B1 and C1 must be >= 0. If one of them is <= 0, it means the point is outside the triangle.
2. A1 + B1 + C1 must be == 1.

> Why the fuck are we talking about weight and mass ? 

In the context of barycentric coordinates, weight or mass has nothing to do with physical mass. They just serve to describe a point's position relative to the vertices of a shape. It's called that because barycentric comes the the greek barus, meaning weight. There's nothing more to it. 

So, if we can decide to place a point P in the triangle using the barycentric coordinates, if we can deduce the barycentric coordinates of an existing point, then we should be able to determine wether P is inside the triangle, or out, which is the entire point of this fuckery. 