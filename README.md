# RealtimeAssignment

## ShapeCalculator Code
### Usage:
1.) Compile and run ShapeCalculator.c </br>
2.) Input 2D or 3D for the dimension requirement </br>
3.) Input name of shape (rectangle/circle/square, case <b>INSENSITIVE</b>) </br>
4.) Input required parameters </br>
5.) Result will be printed on screen </br>

### Useful code blocks:
- TwoDimensionalObj (A struct that stores information of 2D object, e.g. shape, radius, perimeter, area, etc).
- ToAllUpper (Convert a string into all uppercase).
- TwoDimensionCalculation (Main function for calculationg all required information of 2D object).

### Remarks:
1. 2/3D requirement can be removed or simplified after we have code for 3D, so it is smarter.
2. <strike> Name of shape is currently differentiated only by the first character, meaning if somebody input robust, it will be treated as rectangle. </strike>
3. <strike>Infinite loop will occur when user inputs non-number value for shape parameter(s).</strike> (Problem comes from scanf() will leave the input in buffer without clearing them if it cannot be read properly, a short loop to clear buffer is added.)