// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#include "systemc.h"
#include "polyInt_tb.h"
#include <poly.h>
#include"iostream"


// TODO: Implement your Testbench here
void tb::TestBenchIntegral()
{
//    reset.write(1);
//    wait();
//    reset.write(0);
//    wait();
    int counter=0;
    double GoldenResult[10]={8/3,0,72/3,0,280/3,0,728/3,0,1512/3,0};
    double Array[10];
    for(int i=0 ; i<10 ; i+2)
    {
        start.write(true);
        wait();
        A.write(i);
        wait();
        B.write(i+2);
        wait();
        Array[i]=Result.read();
    }
    for(int i=0 ; i<10 ; i+2)
    {
       if (Array[i]==GoldenResult[i])
           ++counter;
    }
    if (counter==5)
        cout<<"Testbench is correct"<<".\n";
    else
        cout<<"Testbench is wrong"<<".\n";

    return 0;
}
