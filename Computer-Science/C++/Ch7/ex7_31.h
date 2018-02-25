#ifndef ex7_31_h
#define ex7_31_h

class Y;

class X {
  Y *x = nullptr;
}

class Y {
  X x;
}

#endif