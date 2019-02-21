#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H

#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

/*  Operator List
 *  ID      Operator                Arguments
 *  1       +                       a + b
 *  2       -                       a - b
 *  3       *                       a * b
 *  4       /                       a / b
 *  5       (
 *  6       )
 *  7       sin                     sin(a)
 *  8       cos                     cos(a)
 *  9       tan                     tan(a)
 *  10      log                     log(a, b)
 *  11      ln                      ln(a)
 *  12      exp                     exp(a)
 *  13      ^                       pow(a,b)
 * */

namespace mathFunc
{
    typedef struct _element
    {
        int type;//0 数字, 1 算符, 2 自变量
        double number;
        int operatorID, argumentID;
    }element;
}

class mathFunction
{

    public:
        mathFunction();
        string rawFunction;
        double get(std::vector<double> argumentValue);
        void generateFunction();
        string argu1, argu2;
        bool hasa1, hasa2;
        void switchMode(int mode);
    private:
        vector<mathFunc::element> func;
        int pow10(int a);
};

#endif // MATHFUNCTION_H
