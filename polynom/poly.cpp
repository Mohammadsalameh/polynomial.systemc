// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include <iostream>
#include "poly.h"

// TODO: implement your function(s) for your Module here
double compute_poly(const unsigned int poly_degree_1,const double *poly_coeff_1,double x)
{
	double Var1 , Var2=0;//Var2;
        double Xip = 1;
    //sc_out<double> F;
        for (int i=0 ;i<=poly_degree_1;i++)
	{
                Var1 = poly_coeff_1[poly_degree_1]*Xip;
                Var2=x*Xip;
                Xip=Var2;
                Var3=Y+Var1;
                Y=Var3;
	}
        //Var1=5*x;
	//Var2=2*x*x;
	//double F=Var2-Var1+5;
	
    return Var2;
}
