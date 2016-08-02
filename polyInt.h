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

SC_MODULE (ModPolyIntegral)
{
    //Rest port
    sc_in<bool>reset;

    //clock port
    sc_in<bool>clk;

    //control signals
    sc_in<bool>start;
    sc_out<bool>finish;

    //Input & Output ports
    sc_in<double>A,B/*,PolyDegree*/;
    sc_out<double>ResultInt;

    //Interface to evaluation integral module
    sc_out<double> X;
    sc_in<double> Y;

    void do_polyIntegral();
 //    void do_PolyInt()
 //    {
 //        Yint.write(do_PolyInt(Aint.read(),Bint.read(),poly_degree));
 //    }

    SC_CTOR(ModPolyIntegral)
    {
        SC_THREAD(do_polyIntegral);
        sensitive<</*clk.pos()<<*/A<<B<<Y<<start;
    }
}

SC_MODULE(ModPolyInt)
{
    //clock port
    sc_in<bool>clk;

    //sc_in<double>reset;
    sc_in<double> A,B/*Degree*/;
    sc_out<double>Result;

    //interface ports
    sc_in<bool>start;
    sc_out<bool>finish;

    ModPolyEval P;
    ModPolyIntegral I;

    sc_signal<double> XSig;//in(x1)
    sc_signal<double> YSig;//out(Y)

    SC_CTOR(ModPolyInt):
        P("P"),I("I")
    {
        P.X(XSig);
        P.Y(YSig);

        I.X(XSig);
        I.Y(YSig);

        //I.reset(reset);
        I.clk(clk);
        I.start(start);
        I.finish(finish);
        I.A(A);
        I.B(B);
//        I.PolyDegree(Degree);
        I.ResultInt(Result);
    }

}

#endif // POLYMOD_H
