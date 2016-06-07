// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>


#ifndef POLYMOD_H
#define POLYMOD_H   
#include "systemc.h"
#include "poly.h"

// TODO: Define your module here
double a,b,c,d,e;
//double A=po.Y;
//double B=p1.Y;
//double C=p2.Y;
//double D=p3.Y;
//double Eo=p4.Y;
const double E=0.1;
const int n = 1000 ;
double So[n],S1[n];//,poly_integral;
bool Tolerance = false ;
double Integral;
//double c=(a+b)/2;
//double d=(a+c)/2;
//double e=(c+b)/2;

//double a = 0;
//double b = 2 ;
SC_MODULE(poly_integeral)
{
    ModPolyEval po,p1;//,p2,p3,p4 ;
    sc_in<double>Aint,Bint,PolyDegree;
    sc_out<double>ResultInt;
    void do_PolyInt()
    {
        Yint.write(do_PolyInt(Aint.read(),Bint.read(),poly_degree));
    }
    SC_CTOR(do_PolyInt):
        po("po"),p1("p1")//,p2("p2"),p3("p3"),p4("p4")
    {
        po.X(Aint);
        p1.X(Bint);
    }
}
#endif // POLYMOD_H
