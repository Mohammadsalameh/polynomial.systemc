// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt.h"

int i;
int num_split=1;
double num_boundary;
double E ;
double temp3[n];

double polyEval(double);


double Split(double(&boundary_1)[n])
{
    ++num_split;
    for(int j=1 ; j<=i ; j++)
    {
        boundary_1[i]=(boundary_1[i-1]+boundary_1[i-1])/2;
        boundary_2[i]=(boundary_1[i-1]+boundary_2[i-1])/2;
    }
}

//double Midpoint(double(&boundary_1)[n] , double(&boundary_1)[n])
//{
//    double length = boundary_1[i]-boundary_1[i];
//    double Mid = (boundary_1[i]+boundary_2[i])/2;
//    double M=length*polyEval(Mid);
//    return M;
//}

double Trapezoid(double (&boundary_1)[n])
{
    for(int i=0 ; i<num_split ; i++)
    {
        double length = boundary_1[i]-boundary_1[i-1];
        double T = length*(polyEval(boundary_1[i])+polyEval(boundary_1[i-1]))/2;
        return T;
    }
}

double Quadrature(double (&boundary_1)[n])
{
    while (condition)
    {
        Split(boundary_1);
        double First_iteration=Trapezoid(boundary_1);
    }

//    temp3[0]=0;
//    double temp1 = (2/3)*Midpoint(boundary_1[i],boundary_1[i]);
//    double temp2 = (1/3)*Trapezoid(boundary_1[i],boundary_1[i]);
//    temp3[i]= temp1 + temp2 ;
//    E=temp3[i]-temp3[i-1];
//    if (E<=0.01 && E>=-0.01)
//        return temp3[i];
//    else
//    {
//        Split(boundary_1,boundary_1);
//    }
}

 //TODO: Place the implementation of your module here

double do_polyInt(double a , double b ,const poly_degree)//, double e)
{

    double boundary_1[n] ;
    //double boundary_2[n] ;
    if (a<b)
    {
    boundary_1[i-1]=a;
    boundary_1[i]=b;
    }
    else
    {
    boundary_1[i-1]=b;
    boundary_1[i]=a;
    }
    num_boundary=2;
    i=1;
    //boundary_2[0]=b;

    //Split(boundary_1,boundary_1);

    if(poly_degree<2)
        return Trapezoid(boundary_1);
    else
        return Quadrature(boundary_1);

//    switch (poly_degree)
//    {
//    case 0 :
//        return Midpoint(boundary_1[0] ,boundary_1[1]);
//        break;
//    case 1 :
//        return Trapezoid(boundary_1[0],boundary_1[1]);
//        break;
//    case 2 :
//        return Simpson(boundary_1[0],boundary_1[1]);
//        break;
//    default :
//        break;
//    }
}
