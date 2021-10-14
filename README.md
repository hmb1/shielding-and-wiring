# shielding-and-wiring

## Part One

Some small components to go into weather satellites require shielding.  The shielding comes in thin sheets which can be easily cut up and rearranged.  But it’s expensive so it’s best to order only the right amount.

Each item is a box (cuboid) with three dimensions in millimetres: length, width, and height.  To cover the surface area of the box therefore requires `2 * length * width + 2 * width * height + 2 * length * height`.  But there’s a convention that you also allow some slack in your provision equal to the area of the smallest side.

Therefore:
* a box with dimensions 2x3x4 has sides of area 6, 8 and 12, so it needs 52 mm<sup>2</sup> plus slack of 6mm<sup>2</sup>, a total of 58 mm<sup>2</sup>
* a box with dimensions 1x10x1 has sides of area 1, 10 and 10, so it needs 42 mm<sup>2</sup> plus slack of 1 mm<sup>2</sup>, a total of 43 mm<sup>2</sup>
* a box with dimensions 5x7x4 has sides of area 20, 28 and 35, so it needs 166 mm<sup>2</sup> plus slack of 20 mm<sup>2</sup>, a total of 186 mm<sup>2</sup>

So if your list of boxes was:

```
2x3x4
1x10x1
5x7x4
```

then the total required provision would be 287 mm<sup>2</sup>.

Please write some code that calculates a total required provision of shielding in mm<sup>2</sup> for a group of boxes.  Box size is defined as 3 numbers separated by x.  There are several example inputs provided for you to try out -- see the files in this repo called [example1.txt](example1.txt), [example2.txt](example2.txt), and [example3.txt](example3.txt). We’ve also provided some expected results to help you check your code, in the file called [expected-results.md](expected-results.md).

## Part Two

These components also require some wiring.  It has been determined that an adequate allowance is the same number of millimetres of wire as the volume of the box in mm<sup>3</sup>, plus a slack provision equal to the smallest circumference of the box (which is equal to twice the shortest edge plus twice the next shortest edge).

Therefore:
* a box with dimensions 2x3x4 has volume of `2*3*4` = 24 mm<sup>3</sup> and shortest circumference of `2*2 + 2*3` = 10 mm, so it needs a total of 34 mm of wire
* a box with dimensions 1x10x1 has volume of `1*10*1` = 10 mm<sup>3</sup> and shortest circumference of `2*1 + 2*1` = 4 mm, so it needs a total of 14 mm of wire
* a box with dimensions 5x7x4 has volume of `5*7*4` = 140 mm<sup>3</sup> and shortest circumference of `2*4 + 2*5` = 18 mm, so it needs a total of 158 mm of wire


So with the same list of boxes as above your total required provision would be 206 mm.

Please write some code to calculate the required provision of wiring for a group of boxes.  You can use the same example inputs again -- we’ve provided some expected results for this too.
