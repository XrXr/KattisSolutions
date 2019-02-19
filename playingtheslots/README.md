## Playing the Slots

I came up with the solution for this with help from my friend and 3blue1brown's linear algebra vidoes.
Here are some key observations:
  - The optimal solution must have two points touching the edge of the chute.
  - Once there are two points touching the edge, it's always possible to rotate the shape until there is an edge that is parallel with the y axis. (because the shape is convex)
  - The rotation matrix which makes an edge parallel with the y axis can be found by doing change of basis with the target edge and the orthogoal of that edge.

Knowing the above, we can rotate the shape based on every edge on the convex and find the minimum width.


## Other solution

Apprently, it is possible to find the [oriented minimum bounding box](https://en.wikipedia.org/wiki/Minimum_bounding_rectangle) of a shape in linear time.
