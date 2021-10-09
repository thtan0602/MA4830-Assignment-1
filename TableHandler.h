#ifndef TABLEHANDLER_H
#define TABLEHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GlobalTypes.h"

// Convert float to string
char *Float2String(char strings[50], float property)
{
    strings[0] = '\0';
    snprintf(strings, 50, "%0.4f", property);
    return strings;
}

// Draw table for 2D objects
void Table_2D(int SHAPE, TwoDimensionalObj *TwoDim_Obj)
{
    int i, j, x, column;
    char *s, *first;
    char diameter_output[50];
    char circumference_output[50];
    char area_output[50];
    char perimeter_output[50];
    char circle_str[50] = "CIRCLE";
    char rectangle_str[50] = "RECTANGLE";
    char square_str[50] = "SQUARE";
    char object_str[50] = "OBJECT";
    char circum_str[50] = "CIRCUMFERENCE";
    char diameter_str[50] = "DIAMETER";
    char area_str[50] = "AREA";
    char perimeter_str[50] = "PERIMETER";

    // Convert shapes' numerical properties into string for table representation
    Float2String(diameter_output, TwoDim_Obj->radius * 2);
    Float2String(circumference_output, TwoDim_Obj->circumference);
    Float2String(area_output, TwoDim_Obj->area);
    Float2String(perimeter_output, TwoDim_Obj->perimeter);

    printf("Please kindly refer to the table below: \n");

    switch (SHAPE)
    {
    case CIRCLE:
        column = 4; // Circle has 3 properties + it's name "Circle"
        break;
    case RECTANGLE:
        column = 3; // Rectangle has 2 properties + it's name "Rectangle"
        break;
    case SQUARE:
        column = 3; // Square has 2 properties + it's name "Square"
        break;
    }

    // Allocate memory for char pointer s , 2*2+1 for 5 rows of characters (2 rows of data + 3 lines of border)
    // 20*column + 2: 20 characters for each column + 1 for the last space + 1 for \n
    // last + 1 for the last \0
    if ((s = (char *)malloc(((2 * 2 + 1) * (20 * column + 2) + 1) * sizeof(char))) == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    first = s;

    // Draw tables
    switch (SHAPE)
    {
    case CIRCLE:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s = ' ';  // Assign value to the address pointed by char pointer s
                    s = s + 1; // Address stored in char pointer s + 1 byte to go to the next byte
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s = '-';
                    s = s + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s = '|';
                    s = s + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s = object_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(diameter_str) + 20)
                        *s = diameter_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(circum_str) + 40)
                        *s = circum_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(area_str) + 60)
                        *s = area_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(circle_str))
                        *s = circle_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(diameter_output) + 20)
                        *s = diameter_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(circumference_output) + 40)
                        *s = circumference_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(area_output) + 60)
                        *s = area_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
            }
            *s = '\n';
            s++;
        }
        break;

    case RECTANGLE:

        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s = ' ';
                    s = s + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s = '-';
                    s = s + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s = '|';
                    s = s + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s = object_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_str) + 20)
                        *s = perimeter_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(area_str) + 40)
                        *s = area_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(rectangle_str))
                        *s = rectangle_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_output) + 20)
                        *s = perimeter_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(area_output) + 40)
                        *s = area_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
            }
            *s = '\n';
            s++;
        }
        break;

    case SQUARE:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s = ' ';
                    s = s + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s = '-';
                    s = s + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s = '|';
                    s = s + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s = object_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_str) + 20)
                        *s = perimeter_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(area_str) + 40)
                        *s = area_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(square_str))
                        *s = square_str[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_output) + 20)
                        *s = perimeter_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(area_output) + 40)
                        *s = area_output[j % 20 - 1];
                    else
                        *s = ' ';
                    s = s + 1;
                }
            }
            *s = '\n';
            s++;
        }
        break;
    }
    *s = '\0';
    printf("%s", first); // Print out table
    free(first);         //  Deallocates the memory
}

// Draw table for 3D objects
void Table_3D(int SHAPE, ThreeDimensionalObj *ThreeDim_Obj)
{
    int i, j, x, column;
    char *s_3D, *first_3D;
    char diameter_output[50];
    char circumference_output[50];
    char surface_area_output[50];
    char perimeter_output[50];
    char volume_output[50];
    char sphere_str[50] = "SPHERE";
    char cuboid_str[50] = "CUBOID";
    char cube_str[50] = "CUBE";
    char cone_str[50] = "CONE";
    char pyramid_str[50] = "PYRAMID";
    char cylinder_str[50] = "CYLINDER";
    char object_str[50] = "OBJECT";
    char circum_str[50] = "CIRCUMFERENCE";
    char diameter_str[50] = "DIAMETER";
    char surface_area_str[50] = "SURFACE AREA";
    char perimeter_str[50] = "PERIMETER";
    char volume_str[50] = "VOLUME";

    // Convert shapes' numerical properties into string for table representation
    Float2String(diameter_output, ThreeDim_Obj->radius * 2);
    Float2String(circumference_output, ThreeDim_Obj->circumference);
    Float2String(surface_area_output, ThreeDim_Obj->surface_area);
    Float2String(perimeter_output, ThreeDim_Obj->perimeter);
    Float2String(volume_output, ThreeDim_Obj->volume);

    printf("Please kindly refer to the table below: \n");

    switch (SHAPE)
    {
    case SPHERE:
        column = 5; // Sphere has 4 properties + it's name "Sphere"
        break;
    case CUBOID:
        column = 4; // Cuboid has 3 properties + it's name "Cuboid"
        break;
    case CUBE:
        column = 4; // Cube has 3 properties + it's name "Cube"
        break;
    case CONE:
        column = 3; // Cone has 3 properties + it's name "Cone"
        break;
    case PYRAMID:
        column = 3; // Pyramid has 3 properties + it's name "Pyramid"
        break;
    case CYLINDER:
        column = 3; // Cylinder has 3 properties + it's name "Cylinder"
        break;
    }

    // Allocate memory for char pointer s_3D , 2*2+1 for 5 rows of characters (2 rows of data + 3 lines of border)
    // 20*column + 2: 20 characters for each column + 1 for the last space + 1 for \n
    // last + 1 for the last \0
    if ((s_3D = (char *)malloc(((2 * 2 + 1) * (20 * column + 2) + 1) * sizeof(char))) == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    first_3D = s_3D;

    // Draw tables
    switch (SHAPE)
    {
    case SPHERE:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';     // Assign value to the address pointed by char pointer s_3D
                    s_3D = s_3D + 1; // Address stored in char pointer s_3D + 1 byte to go to the next byte
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(diameter_str) + 20)
                        *s_3D = diameter_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(circum_str) + 40)
                        *s_3D = circum_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 60)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 80 && j <= 100 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 80)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(sphere_str))
                        *s_3D = sphere_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(diameter_output) + 20)
                        *s_3D = diameter_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(circumference_output) + 40)
                        *s_3D = circumference_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 60)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 80 && j <= 100 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 80)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    case CUBOID:

        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_str) + 20)
                        *s_3D = perimeter_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 40)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 60)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(cuboid_str))
                        *s_3D = cuboid_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_output) + 20)
                        *s_3D = perimeter_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 40)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 60)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    case CUBE:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_str) + 20)
                        *s_3D = perimeter_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 40)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 60)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(cube_str))
                        *s_3D = cube_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(perimeter_output) + 20)
                        *s_3D = perimeter_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 40)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 60 && j <= 80 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 60)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    case CONE:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 20)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 40)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(cone_str))
                        *s_3D = cone_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 20)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 40)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    case PYRAMID:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 20)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 40)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(pyramid_str))
                        *s_3D = pyramid_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 20)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 40)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    case CYLINDER:
        for (i = 0; i < 2 * 2 + 1; i++)
        {
            for (j = 0; j < 20 * column + 1; j++)
            {
                if (i % 2 == 0 && j % 20 == 0)
                {
                    *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 0 && j % 20 != 0)
                {
                    *s_3D = '-';
                    s_3D = s_3D + 1;
                }
                else if (i % 2 == 1 && j % 20 == 0)
                {
                    *s_3D = '|';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(object_str))
                        *s_3D = object_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_str) + 20)
                        *s_3D = surface_area_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 1 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_str) + 40)
                        *s_3D = volume_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j <= 20 && j % 20 != 0)
                {
                    if (j <= strlen(cylinder_str))
                        *s_3D = cylinder_str[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 20 && j <= 40 && j % 20 != 0)
                {
                    if (j <= strlen(surface_area_output) + 20)
                        *s_3D = surface_area_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
                else if (i == 3 && j >= 40 && j <= 60 && j % 20 != 0)
                {
                    if (j <= strlen(volume_output) + 40)
                        *s_3D = volume_output[j % 20 - 1];
                    else
                        *s_3D = ' ';
                    s_3D = s_3D + 1;
                }
            }
            *s_3D = '\n';
            s_3D++;
        }
        break;
    }
    *s_3D = '\0';
    printf("%s", first_3D);
    free(first_3D);
}

#endif //TABLEHANDLER_H