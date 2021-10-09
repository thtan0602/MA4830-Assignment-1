#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "GlobalTypes.h"
#include "TableHandler.h"

const float pi = 3.14159265359;

// Convert enum to string for 2D shapes
char *Enum2String_2D(TwoD_Shape s)
{
    char *acceptable_2Dshape[3] = {"CIRCLE", "RECTANGLE", "SQUARE"}; // Acceptable 2D shapes

    return acceptable_2Dshape[s];
}

// Convert enum to string for 3D shapes
char *Enum2String(ThreeD_Shape s)
{
    char *acceptable_3Dshape[6] = {"SPHERE", "CUBOID", "CUBE", "CONE", "PYRAMID", "CYLINDER"}; // Acceptable 3D shapes

    return acceptable_3Dshape[s];
}

// Convert a string into all uppercase
void ToAllUpper(char str[50])
{
    char *str_ptr = str; // Assign a pointer to change the value stored
    while (*str_ptr)
    {
        *str_ptr = (*str_ptr >= 'a' && *str_ptr <= 'z') ? *str_ptr - 32 : *str_ptr;
        *str_ptr++;
    }
}

// Check if input is allowable
float input_check(char input[50])
{
    int length;
    float f;

    length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != ',')
        {
            return (0);
        }
    }

    f = atof(input);

    if (f <= 0)
        return (0);

    return (f);
}

void TwoDimensionCalculation()
{
    char shape[50]; // Shape of subject

    // Allocate memory for 2D Object
    TwoDimensionalObj *TwoD_Obj;
    if ((TwoD_Obj = (TwoDimensionalObj *)malloc(sizeof(TwoDimensionalObj))) == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    // Prompt user's shape input and check if input shape is acceptable
    int loop = true;
    while (loop)
    {
        printf("Please choose shape [circle, rectangle, square]: ");
        scanf("%s", &shape);
        ToAllUpper(shape);
        for (int i = CIRCLE; i <= SQUARE; i++)
        {
            int c = strcmp(shape, Enum2String_2D(i));
            if (c == 0)
            {
                TwoD_Obj->shape = i;
                loop = false;
                break;
            }
        }
        if (loop == true)
            printf("Only these few options are available [\"circle\", \"rectangle\", \"square\"].\n");
    }

    // Input parameter(s) required and calculation for respective shape
    switch (TwoD_Obj->shape)
    {
        char input[50];

    case CIRCLE:
        while (true)
        {
            printf("Please input radius (float is acceptable): ");
            scanf("%s", &input);

            TwoD_Obj->radius = input_check(input);

            if (!TwoD_Obj->radius)
            {
                printf("Please input only positive value.\n");
                continue;
            }

            else
                break;
        }

        TwoD_Obj->circumference = 2 * pi * TwoD_Obj->radius;
        TwoD_Obj->area = pi * TwoD_Obj->radius * TwoD_Obj->radius;
        printf("Diameter of circle = %f, circumference = %f, area = %f\n", 2 * TwoD_Obj->radius, TwoD_Obj->circumference, TwoD_Obj->area);
        printf("\n");
        Table_2D(CIRCLE, TwoD_Obj);
        break;

    case RECTANGLE: // Rectangle
        while (true)
        {
            printf("Please input length (float is acceptable): ");
            scanf("%s", &input);

            TwoD_Obj->length = input_check(input);

            if (!TwoD_Obj->length)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input width (float is acceptable): ");
            scanf("%s", &input);

            TwoD_Obj->width = input_check(input);

            if (!TwoD_Obj->width)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        TwoD_Obj->perimeter = 2 * TwoD_Obj->length + 2 * TwoD_Obj->width;
        TwoD_Obj->area = TwoD_Obj->length * TwoD_Obj->width;
        printf("Perimeter = %f, area = %f\n", TwoD_Obj->perimeter, TwoD_Obj->area);
        printf("\n");
        Table_2D(RECTANGLE, TwoD_Obj);
        break;

    case SQUARE: // Square
        while (true)
        {
            printf("Please input length (float is acceptable): ");
            scanf("%s", &input);

            TwoD_Obj->length = input_check(input);

            if (!TwoD_Obj->length)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        TwoD_Obj->perimeter = 4 * TwoD_Obj->length;
        TwoD_Obj->area = TwoD_Obj->length * TwoD_Obj->length;
        printf("Perimeter = %f, area = %f\n", TwoD_Obj->perimeter, TwoD_Obj->area);
        printf("\n");
        Table_2D(SQUARE, TwoD_Obj);
        break;
    }

    // Free unwanted storage
    free((void *)TwoD_Obj);
}

void ThreeDimensionCalculation()
{
    char shape[50]; // Shape of subject

    // Allocate memory for 3D Object
    ThreeDimensionalObj *ThreeD_Obj;
    if ((ThreeD_Obj = (ThreeDimensionalObj *)malloc(sizeof(ThreeDimensionalObj))) == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    // Prompt user's shape input and check if input shape is acceptable
    int loop = true;
    while (loop)
    {
        printf("Please choose shape [sphere, cuboid, cube, cone, pyramid, cylinder]: ");
        scanf("%s", &shape);
        ToAllUpper(shape);
        for (int i = SPHERE; i <= CYLINDER; i++)
        {
            int c = strcmp(shape, Enum2String(i));
            if (c == 0)
            {
                ThreeD_Obj->shape = i;
                loop = false;
                break;
            }
        }
        if (loop == true)
            printf("Only these few options are available [\"sphere\", \"cuboid\", \"cube\", \"cone\", \"pyramid\", \"cylinder\"].\n");
    }

    // Input parameter(s) required and calculation for respective shape
    switch (ThreeD_Obj->shape)
    {
        char input[50];

    case SPHERE:
        while (true)
        {
            printf("Please input radius (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->radius = input_check(input);

            if (!ThreeD_Obj->radius)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->circumference = 2 * pi * ThreeD_Obj->radius;
        ThreeD_Obj->surface_area = 4 * pi * pow(ThreeD_Obj->radius, 2);
        ThreeD_Obj->volume = 4 * pi * pow(ThreeD_Obj->radius, 3) / 3;
        printf("Diameter of sphere = %f, circumference = %f, surface_area = %f, volume = %f\n", 2 * ThreeD_Obj->radius, ThreeD_Obj->circumference, ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(SPHERE, ThreeD_Obj);
        break;

    case CUBOID:
        while (true)
        {
            printf("Please input width (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->width = input_check(input);

            if (!ThreeD_Obj->width)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input length (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->length = input_check(input);

            if (!ThreeD_Obj->length)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input height (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->height = input_check(input);

            if (!ThreeD_Obj->height)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->perimeter = 4 * (ThreeD_Obj->width + ThreeD_Obj->length + ThreeD_Obj->height);
        ThreeD_Obj->surface_area = 2 * (ThreeD_Obj->width * ThreeD_Obj->length + ThreeD_Obj->width * ThreeD_Obj->height + ThreeD_Obj->length * ThreeD_Obj->height);
        ThreeD_Obj->volume = ThreeD_Obj->width * ThreeD_Obj->length * ThreeD_Obj->height;
        printf("Perimeter = %f, surface_area = %f, volume = %f\n", ThreeD_Obj->perimeter, ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(CUBOID, ThreeD_Obj);
        break;

    case CUBE:
        while (true)
        {
            printf("Please input length (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->length = input_check(input);

            if (!ThreeD_Obj->length)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->perimeter = 12 * ThreeD_Obj->length;
        ThreeD_Obj->surface_area = 6 * pow(ThreeD_Obj->length, 2);
        ThreeD_Obj->volume = pow(ThreeD_Obj->length, 3);
        printf("Perimeter = %f, surface_area = %f, volume = %f\n", ThreeD_Obj->perimeter, ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(CUBE, ThreeD_Obj);
        break;

    case CONE:
        while (true)
        {
            printf("Please input radius (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->radius = input_check(input);

            if (!ThreeD_Obj->radius)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input height (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->height = input_check(input);

            if (!ThreeD_Obj->height)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->surface_area = pi * ThreeD_Obj->radius * (ThreeD_Obj->radius + pow((pow(ThreeD_Obj->radius, 2) + pow(ThreeD_Obj->height, 2)), 0.5));
        ThreeD_Obj->volume = pi * pow(ThreeD_Obj->radius, 2) * ThreeD_Obj->height / 3;
        printf("surface_area = %f, volume = %f\n", ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(CONE, ThreeD_Obj);
        break;

    case PYRAMID:
        while (true)
        {
            printf("Please input length (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->length = input_check(input);

            if (!ThreeD_Obj->length)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input width (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->width = input_check(input);

            if (!ThreeD_Obj->width)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }
        while (true)
        {
            printf("Please input height (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->height = input_check(input);

            if (!ThreeD_Obj->height)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->surface_area = ThreeD_Obj->length * ThreeD_Obj->width + ThreeD_Obj->length * pow(pow(ThreeD_Obj->width / 2, 2) + pow(ThreeD_Obj->height, 2), 0.5) + ThreeD_Obj->width * pow(pow(ThreeD_Obj->length / 2, 2) + pow(ThreeD_Obj->height, 2), 0.5);
        ThreeD_Obj->volume = ThreeD_Obj->length * ThreeD_Obj->width * ThreeD_Obj->height / 3;
        printf("surface_area = %f, volume = %f\n", ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(PYRAMID, ThreeD_Obj);
        break;

    case CYLINDER:
        while (true)
        {
            printf("Please input radius (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->radius = input_check(input);

            if (!ThreeD_Obj->radius)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        while (true)
        {
            printf("Please input height (float is acceptable): ");
            scanf("%s", &input);

            ThreeD_Obj->height = input_check(input);

            if (!ThreeD_Obj->height)
            {
                printf("Please input only positive float\n");
                continue;
            }

            else
                break;
        }

        ThreeD_Obj->surface_area = 2 * pi * ThreeD_Obj->radius * (ThreeD_Obj->radius + ThreeD_Obj->height);
        ThreeD_Obj->volume = pi * pow(ThreeD_Obj->radius, 2) * ThreeD_Obj->height;
        printf("surface_area = %f, volume = %f\n", ThreeD_Obj->surface_area, ThreeD_Obj->volume);
        printf("\n");
        Table_3D(CYLINDER, ThreeD_Obj);
        break;
    }

    // Free unwanted storage
    free((void *)ThreeD_Obj);
}

void main()
{
    char choice[20]; //Choice of 2 or 3 dimension

    printf("Nice to meet you! I am your beloved calculator, what can I calculate for you today?\n");

    do
    {
        printf("\nCalculate 2 or 3 dimensional shape?(or type 'q' to quit) [2/3]: ");
        scanf("%s", &choice);

        if (strcmp(choice, "q") == 0 || strcmp(choice, "Q") == 0)
        {
            printf("See you again! :)\n");
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(choice, "2") == 0)
            TwoDimensionCalculation();
        else if (strcmp(choice, "3") == 0)
            ThreeDimensionCalculation();
        else
            fprintf(stderr, "Error: Please input only value 2 or 3.\n");

    } while (true);
}
