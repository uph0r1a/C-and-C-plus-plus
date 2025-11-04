#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    const float pi = 3.14159;
    float radius_circle,length_rectangle,width_rectangle,base_triangle,height_triangle;
    int choice;
    cout<<"Geometry Calculator\n";
    cout<<"\t1. Calculate the Area of a Circle\n";
    cout<<"\t2. Calculate the Area of a Rectangle\n";
    cout<<"\t3. Calculate the Area of a Triangle\n";
    cout<<"\t4. Quit\n";
    cout<<"\tEnter your choice (1-4): ";
loop4:
    cin>>choice;

    switch (choice)
    {
    case 1:
loop1:
        cout<<"Enter the radius of the circle: ";
        cin>>radius_circle;

        if (radius_circle < 0)
        {
            cout<<"Do not accept negative values for the circle's radius\n";
            goto loop1;
        }
        
        cout<<"Area: "<< pi * pow(radius_circle,2);
        break;
    case 2:
loop2:
        cout<<"Enter the length of the rectangle: ";
        cin>>length_rectangle;
        cout<<"Enter the width of the rectangle: ";
        cin>>width_rectangle;

        if (length_rectangle < 0 || width_rectangle < 0)
        {
            cout<<"Do not accept negative values for the rectangle's length or width\n";
            goto loop2;
        }
        cout<<"Area: "<< length_rectangle*width_rectangle;
        break;
    case 3:
loop3:
        cout<<"Enter the length of the triangle's base: ";
        cin>>base_triangle;
        cout<<"Enter the height of the triangle: ";
        cin>>height_triangle;
        
        if (base_triangle < 0 || height_triangle < 0)
        {
            cout<<"Do not accept negative values for the triangle's base or height\n";
            goto loop3;
        }
        cout<<"Area: "<< base_triangle*height_triangle*0.5;
        break;
    case 4:
        break;
    
    default:
        cout<<"Invalid input\n";
        cout<<"Re-enter choice: ";
        goto loop4;
        break;
    }
    return 0;
}
