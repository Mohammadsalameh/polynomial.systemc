// Copyright (C) 2015 University of Kaiserslautern
// Microelectronic System Design Research Group
// 
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
// 
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>
// Markus Steffes <steffesm@rhrk.uni-kl.de>


#include "polyInt.h"
#include "polyInt_tb.h"

//using namespace std;


int sc_main(int argc, char* argv[])
{
  sc_signal<double> ASig, BSig, ResSig;
  sc_signal<bool> StartSig, FinishSig;

  // a clock that has a positive edge only at 10 ns
  sc_clock TestClk("TestClock", 10, SC_NS,0.5, 10, SC_NS);

  // TODO insert your module here
  ModPolyInt DefInt("DefInt");
  DefInt.clk(TestClk);
  DefInt.A(ASig);
  DefInt.B(BSig);
  DefInt.Result(ResSig);
  DefInt.start(StartSig);
  DefInt.finish(FinishSig);
  // TODO insert your testbench here
  tb TestDefInt("TestDefInt");
  TestDefInt.clk(TestClk);
  TestDefInt.A(ASig);
  TestDefInt.B(BSig);
  TestDefInt.Result(ResSig);
  TestDefInt.start(StartSig);
  TestDefInt.finish(FinishSig);

  sc_start();  // run forever

  return 0;

}
