/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 2A
*/

// Including the necessary header files
#include <stdio.h>
#include <math.h>

// The main function
int main(){
	// Declaring the variables of necessary types
	double x1, y1, x2, y2, x3, y3, area, a, b, c, cosA, cosB, cosC;

	// Promting the user to input the coordinates of the vertices, and storing the input in respective variables.
	printf("Enter the coordinates of vertex 1: ");
	scanf("%lf%lf",&x1,&y1);
	printf("Enter the coordinates of vertex 2: ");
	scanf("%lf%lf",&x2,&y2);
	printf("Enter the coordinates of vertex 3: ");
	scanf("%lf%lf",&x3,&y3);

	// Calculating the area of the triangle so formed by connecting the points.
    area = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;

	// Detecting an edge case where area is 0 and exiting the program if so.
	if (area == 0) {
		printf("The coordinates of the given vertices do not constitute a triange, since the area is %lf.\n", area);
		return 0;
	}
    
	// Taking absolute value of the area.
	if (area<0) area = -area;

	// a. Printing the area of the triangle.
	printf("The area of the triangle is: %lf sq. units.\n", area);

	// Calculating the lengths of the sides of the triangle.
    a = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    b = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    c = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

	// Calculating the cosine of angles of the triangle using cosine rule.
	cosA = (b*b + c*c - a*a)/(2*b*c);
	cosB = (a*a + c*c - b*b)/(2*a*c);
	cosC = (b*b + a*a - c*c)/(2*a*b);

	// b. Checking if the triangle is acute, obtuse or right angled.
	if (cosA>0 && cosB>0 && cosC>0) printf("The triangle is acute angled.\n");
	else if (fabs(cosA - 0)<0.001 || fabs(cosA - 0)<0.001 || fabs(cosA - 0)<0.001) printf("The triangle is right angled.\n");
	else printf("The triangle is obtuse angled.\n");

	// c. Checking if the triangle is an equilateral or isosceles triangle.
	if (a==b && a==c) printf("The triangle is an equilateral triangle.\n");
	else if ((a==b && a!=c) || (a==c && a!=b) || (c==b && a!=c)) printf("The triangle is an isosceles triangle.\n");

    return 0;
}
