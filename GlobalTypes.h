#ifndef GLOBALTYPES_H
#define GLOBALTYPES_H

typedef enum
{
    CIRCLE,
    RECTANGLE,
    SQUARE
} TwoD_Shape;

typedef struct
{
    TwoD_Shape shape;
    float radius;
    float length;
    float width;
    float perimeter;
    float circumference;
    float area;
} TwoDimensionalObj;

typedef enum
{
    SPHERE,
    CUBOID,
    CUBE,
    CONE,
    PYRAMID,
    CYLINDER
} ThreeD_Shape;

typedef struct
{
    ThreeD_Shape shape;
    float radius;
    float length;
    float width;
    float height;
    float circumference;
    float perimeter;
    float surface_area;
    float volume;
} ThreeDimensionalObj;

#endif // GLOBALTYPES_H