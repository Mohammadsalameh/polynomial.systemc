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
#include "ModuleIntegral.h"

 //TODO: Place the implementation of your module here

void ModPolyIntegral::do_polyIntegral()
{
    //Rest the code
    //Rest internal variable
    //Rest outputs
    ResultInt.write(0);
    wait();
    while (start.read()==true)
    {
        finish.write(false);
        wait();
        double bound_low=A.read() ;
        wait();
        double bound_high=B.read();
        double low ;
        double high;
        double temp1,temp2,temp3;
        double accu=0;
        double pre_accu=0;
        double mid;

        double sign=1;
        double error=1;

        int k=0;


        if (bound_low<bound_high)
        {
            low=bound_low;
            high=bound_high;
            sign=1;
        }
        else
        {
            low=bound_high;
            high=bound_low;
            sign=-1;
        }

        double l=sign*(high-low);

        //evaluation of the midpoint
        mid=(low+high)/2;
        X.write(mid);
        wait();
        temp3=Y.read();
        //evaluation of low
        X.write(low);
        wait();
        temp1=Y.read();
        //evaluation of high
        X.write(high);
        wait();
        temp2=Y.read();
        double Midpoint=l*temp3;
        double Trapezoid=(l/6)*(temp1+4*temp3+temp2);
        switch(2)
        {
            case 0:
            ResultInt.write(Midpoint);
            wait();
            break;
            case 1:
            ResultInt.write(Midpoint);
            wait();
            break;
            case 2:
            ResultInt.write(Trapezoid);
            wait();
            break;
            case 3 :
            ResultInt.write(Trapezoid);
            wait();
            break;
        }
//                ++k;
//                for(int i=0 ; i<k ; ++i )
//                {
//                    bound1.write(mid[k-i]);
//                    bound2.write(mid[k-i-1]);
//                    temp3=ResultMid.read();
//                    for(int j=0 ; j<k-i ; ++j)
//                    {
//                        mid[k-j+1]=mid[k-j];
//                    }
//                    mid[i+1]=temp3;
//                }
//                for(int i=0 ; i<k ; ++i)
//                {
//                    X.write(mid[i+1]);
//                    wait();
//                    temp1=Y.read();

//                    accu+=((mid[i+1]-mid[i])*temp1);
//                }
//                error=accu-pre_accu;
//                pre_accu=accu;

//        }
//        else
//            break;
            finish.write(true);
            wait();
    }
}
