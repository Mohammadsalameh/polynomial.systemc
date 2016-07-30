// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>

#ifndef POLYINT_TB_H
#define POLYINT_TB_H   
#include "systemc.h"

// TODO: Define your Testbench Module here
SC_MODULE(tb)
{
    //Reset Port
//    sc_out<bool>reset;

    //ports connected to input ports of the tested module
    sc_out<double>A,B;
    //ports connected to output ports of the tested module
    sc_in<double>Result;
    //communication & interface ports
    sc_in<bool>finish;
    sc_out<bool>start;

    void TestBenchIntegral();
    SC_CTOR(tb)
    {
        SC_METHOD(TestBenchIntegral);
        sensitive << A << B << Result << finish ;
    }
}

#endif // POLYINT_TB_H
