#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define pi 3.14159265359

// properties
struct ThreeDimensionalObj{ 
    char *shape;
    float radius;
    float width;
    float length;
    float height;
    float circumference;
    float surface_area;
    float volume;
};

void main(){
    char *acceptable_3Dshape[6] = {"SPHERE", "CUBOID", "CUBE", "CONE", "PYRAMID", "CYLINDER"};
 
    char shape[100]; //input shape
    struct ThreeDimensionalObj Three_D_Obj;
    int loop = 1;

    while(loop){

        printf("Please enter the 3D shape that you want:");
        scanf("%s", shape);

        strupr(shape); //Capitalise the letter of the input shape to compare with the acceptable shape

        for(int i=0; i<6; i++){ //for comparing the input shape and the acceptable shape
            int c = strcmp(shape, acceptable_3Dshape[i]);
            if(c == 0){ //if input shape and acceptable shape are the same, strcmp will return 0 henc we break
                loop = 0;
                break;
            } 
        }
        if(loop == 1)
            printf("Only these few options are available [\"sphere\", \"cuboid\", \"cube\", \"cone\", \"pyramid\", \"cylinder\"].\n");
    }

    Three_D_Obj.shape = shape;
    int count = 0;
    
    if(strcmp(Three_D_Obj.shape, "SPHERE") == 0){
            printf("Please input radius(float is acceptable): ");
            scanf("%f",&Three_D_Obj.radius);
            if(Three_D_Obj.radius < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.radius > 0){
                Three_D_Obj.circumference = 2*pi*Three_D_Obj.radius;
                Three_D_Obj.surface_area = 4*pi*pow(Three_D_Obj.radius, 2);
                Three_D_Obj.volume = 4/3*pi*pow(Three_D_Obj.radius, 3);
                printf("Diameter of sphere = %f, circumference = %f, surface_area = %f, volume = %f\n", 2*Three_D_Obj.radius, Three_D_Obj.circumference, Three_D_Obj.surface_area, Three_D_Obj.volume);
            }
    }

    if(strcmp(Three_D_Obj.shape, "CUBOID") == 0){  
            printf("Please input width, length and height(float is acceptable): ");
            scanf("%f %f %f",&Three_D_Obj.width, &Three_D_Obj.length, &Three_D_Obj.height);
            if(Three_D_Obj.width < 0 && Three_D_Obj.length < 0 && Three_D_Obj.height < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.width > 0 && Three_D_Obj.length > 0 && Three_D_Obj.height > 0){
                Three_D_Obj.surface_area = 2*(Three_D_Obj.width*Three_D_Obj.length+Three_D_Obj.width*Three_D_Obj.height+Three_D_Obj.length*Three_D_Obj.height);
                Three_D_Obj.volume = Three_D_Obj.width*Three_D_Obj.length*Three_D_Obj.height;
                printf("surface_area = %f, volume = %f\n", 2*Three_D_Obj.radius, Three_D_Obj.circumference, Three_D_Obj.surface_area, Three_D_Obj.volume);
            }
    }

    if(strcmp(Three_D_Obj.shape, "CUBE") == 0){
            printf("Please input length(float is acceptable): ");
            scanf("%f",&Three_D_Obj.length);
            if(Three_D_Obj.length < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.length > 0){
                Three_D_Obj.surface_area = 6*pow(Three_D_Obj.length, 2);
                Three_D_Obj.volume = pow(Three_D_Obj.length, 3);
                printf("surface_area = %f, volume = %f\n", Three_D_Obj.surface_area, Three_D_Obj.volume);
            }
    }

    if(strcmp(Three_D_Obj.shape, "CONE") == 0){
            printf("Please input radius and height(float is acceptable): ");
            scanf("%f %f",&Three_D_Obj.radius, &Three_D_Obj.height);
            if(Three_D_Obj.radius < 0 && Three_D_Obj.height < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.radius > 0 && Three_D_Obj.height > 0){
                Three_D_Obj.surface_area = pi*Three_D_Obj.radius*(Three_D_Obj.radius+pow((pow(Three_D_Obj.radius, 2)+pow(Three_D_Obj.height, 2)), 0.5));
                Three_D_Obj.volume = pi*pow(Three_D_Obj.radius, 2)*Three_D_Obj.height/3;
                printf("surface_area = %f, volume = %f\n", Three_D_Obj.surface_area, Three_D_Obj.volume);
            }
    }

    if(strcmp(Three_D_Obj.shape, "PYRAMID") == 0){
            printf("Please input width, length and height(float is acceptable): ");
            scanf("%f %f %f",&Three_D_Obj.width, &Three_D_Obj.length, &Three_D_Obj.height);
            if(Three_D_Obj.width < 0 && Three_D_Obj.length < 0 && Three_D_Obj.height < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.width > 0 && Three_D_Obj.length > 0 && Three_D_Obj.height > 0){
                Three_D_Obj.surface_area = Three_D_Obj.length*Three_D_Obj.width+Three_D_Obj.length*pow(pow(Three_D_Obj.width/2, 2)+pow(Three_D_Obj.height, 2), 0.5)+Three_D_Obj.width*pow(pow(Three_D_Obj.length/2, 2)+pow(Three_D_Obj.height, 2), 0.5);
                Three_D_Obj.volume = Three_D_Obj.length*Three_D_Obj.width*Three_D_Obj.height/3;
                printf("surface_area = %f, volume = %f\n", Three_D_Obj.surface_area, Three_D_Obj.volume);
            }
    }
        
    if(strcmp(Three_D_Obj.shape, "CYLINDER") == 0){
            printf("Please input radius and height(float is acceptable): ");
            scanf("%f %f",&Three_D_Obj.radius, &Three_D_Obj.height);
            if(Three_D_Obj.radius < 0 && Three_D_Obj.height < 0) printf("Please enter a positive value.");
            if(Three_D_Obj.radius > 0 && Three_D_Obj.height > 0){
                Three_D_Obj.surface_area = 2*pi*Three_D_Obj.radius*(Three_D_Obj.radius+Three_D_Obj.height);
                Three_D_Obj.volume = pi*pow(Three_D_Obj.radius, 2)*Three_D_Obj.height;
                printf("surface_area = %f, volume = %f\n", Three_D_Obj.surface_area);
            }
    }
}
