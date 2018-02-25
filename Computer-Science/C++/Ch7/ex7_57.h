#ifndef ex7_57_h
#define ex7_57_h

#include <string>

using std::string;

class Accout {
  public:
    void calculate () { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

  private:
    string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate { return todayRate; }
}

double Accout::interestRate = initRate();

#endif