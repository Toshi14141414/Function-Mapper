#include "mathfunction.h"

using namespace mathFunc;

mathFunction::mathFunction()
{
    //generateTestFunction();
    hasa1 = true;
    hasa2 = false;
    argu1 = "x";
    argu2 = "y";
}


int mathFunction::pow10(int a)
{
    int ans = 1, i;
    for(i=0;i<a;i++)
        ans *= 10;
    return ans;
}


void mathFunction::generateFunction()
{
    int i, strType, nowType;//0 number, 1 letter, 2 symbols
    string tmpStr;
    tmpStr = "";
    element e;

    func.clear();

    for(i=0;i<rawFunction.size();i++)
    {
        if(rawFunction.at(i) <= '9' && rawFunction.at(i) >= '0')
        {
            nowType = 0;
        }
        else if((rawFunction.at(i) <= 'z' && rawFunction.at(i) >= 'a') ||
                (rawFunction.at(i) <= 'Z' && rawFunction.at(i) >= 'A'))
        {
            nowType = 1;
        }
        else
        {
            nowType = 2;
        }
        if(nowType == strType)
        {
            tmpStr += rawFunction.at(i);
        }
        else
        {
            if(tmpStr.size() == 0)
            {
                strType = nowType;
                tmpStr += rawFunction.at(i);
                continue;
            }
            switch(strType)
            {
                case 0://number
                {
                    e.type = 0;
                    e.number = 0;
                    int j;
                    for(j=0;j<tmpStr.size();j++)
                    {
                        e.number += (tmpStr.at(tmpStr.size()-j-1) - '0') * pow10(j);
                    }
                    func.push_back(e);
                }
                break;
                case 1://letter
                {
                    if(tmpStr.size() == 1)
                    {
                        if(hasa1 && tmpStr == argu1)
                        {
                            e.type = 2;
                            e.argumentID = 0;
                            func.push_back(e);
                        }
                        if(hasa2 && tmpStr == argu2)
                        {
                            e.type = 2;
                            e.argumentID = 1;
                            func.push_back(e);
                        }
                        //todo: 常数
                    }
                    else
                    {
                        if(tmpStr == "sin")
                        {
                            e.type = 1;
                            e.operatorID = 7;
                            func.push_back(e);
                        }
                        if(tmpStr == "cos")
                        {
                            e.type = 1;
                            e.operatorID = 8;
                            func.push_back(e);
                        }
                        if(tmpStr == "tan")
                        {
                            e.type = 1;
                            e.operatorID = 9;
                            func.push_back(e);
                        }
                        if(tmpStr == "log")
                        {
                            e.type = 1;
                            e.operatorID = 10;
                            func.push_back(e);
                        }
                        if(tmpStr == "ln")
                        {
                            e.type = 1;
                            e.operatorID = 11;
                            func.push_back(e);
                        }
                        if(tmpStr == "exp")
                        {
                            e.type = 1;
                            e.operatorID = 12;
                            func.push_back(e);
                        }
                    }
                }
                break;
                case 2://symbol
                {
                    int j;
                    for(j=0;j<tmpStr.size();j++)
                    {
                        if(tmpStr.at(j) == '+')
                        {
                            e.type = 1;
                            e.operatorID = 1;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == '-')
                        {
                            e.type = 1;
                            e.operatorID = 2;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == '*')
                        {
                            e.type = 1;
                            e.operatorID = 3;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == '/')
                        {
                            e.type = 1;
                            e.operatorID = 4;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == '(')
                        {
                            e.type = 1;
                            e.operatorID = 5;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == ')')
                        {
                            e.type = 1;
                            e.operatorID = 6;
                            func.push_back(e);
                        }
                        if(tmpStr.at(j) == '^')
                        {
                            e.type = 1;
                            e.operatorID = 13;
                            func.push_back(e);
                        }
                    }
                }
                break;
            }
            strType = nowType;
            tmpStr = "";
            tmpStr += rawFunction.at(i);
        }
    }
    switch(strType)
    {
        case 0://number
        {
            e.type = 0;
            e.number = 0;
            int j;
            for(j=0;j<tmpStr.size();j++)
            {
                e.number += (tmpStr.at(tmpStr.size()-j-1) - '0') * pow10(j);
            }
            func.push_back(e);
        }
        break;
        case 1://letter
        {
            if(tmpStr.size() == 1)
            {
                if(hasa1 && tmpStr == argu1)
                {
                    e.type = 2;
                    e.argumentID = 0;
                    func.push_back(e);
                }
                if(hasa2 && tmpStr == argu2)
                {
                    e.type = 2;
                    e.argumentID = 1;
                    func.push_back(e);
                }
                //todo: 常数
            }
            else
            {
                if(tmpStr == "sin")
                {
                    e.type = 1;
                    e.operatorID = 7;
                    func.push_back(e);
                }
                if(tmpStr == "cos")
                {
                    e.type = 1;
                    e.operatorID = 8;
                    func.push_back(e);
                }
                if(tmpStr == "tan")
                {
                    e.type = 1;
                    e.operatorID = 9;
                    func.push_back(e);
                }
                if(tmpStr == "log")
                {
                    e.type = 1;
                    e.operatorID = 10;
                    func.push_back(e);
                }
                if(tmpStr == "ln")
                {
                    e.type = 1;
                    e.operatorID = 11;
                    func.push_back(e);
                }
                if(tmpStr == "exp")
                {
                    e.type = 1;
                    e.operatorID = 12;
                    func.push_back(e);
                }
            }
        }
        break;
        case 2://symbol
        {
            int j;
            for(j=0;j<tmpStr.size();j++)
            {
                if(tmpStr.at(j) == '+')
                {
                    e.type = 1;
                    e.operatorID = 1;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == '-')
                {
                    e.type = 1;
                    e.operatorID = 2;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == '*')
                {
                    e.type = 1;
                    e.operatorID = 3;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == '/')
                {
                    e.type = 1;
                    e.operatorID = 4;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == '(')
                {
                    e.type = 1;
                    e.operatorID = 5;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == ')')
                {
                    e.type = 1;
                    e.operatorID = 6;
                    func.push_back(e);
                }
                if(tmpStr.at(j) == '^')
                {
                    e.type = 1;
                    e.operatorID = 13;
                    func.push_back(e);
                }
            }
        }
        break;
    }

    rawFunction = "";
}

double mathFunction::get(std::vector<double> argumentValue)
{
    stack<mathFunc::element> numberStack, operatorStack;
    int bracketSeal = 0;

    int i;
    bool flag = true, overFlag = false;

    for(i=0;i<func.size();i++)
    {
        switch(func.at(i).type)
        {
            case 0:
                numberStack.push(func.at(i));
            break;
            case 1:
                operatorStack.push(func.at(i));
            break;
            case 2:
                element c;
                c.type = 0;
                c.number = argumentValue.at(func.at(i).argumentID);
                numberStack.push(c);
            break;
        }

        overFlag = false;

        while(operatorStack.size() > 0 && (!overFlag))//符号栈
        {
            switch(operatorStack.top().operatorID)
            {
                //+ - * / log
                case 1:
                case 2:
                case 3:
                case 4:
                case 10:
                case 13:
                    if((numberStack.size() - bracketSeal) >= 2)
                    {
                        element e = operatorStack.top();
                        operatorStack.pop();

                        element b = numberStack.top();
                        numberStack.pop();

                        element a = numberStack.top();
                        numberStack.pop();

                        element c;
                        c.type = 0;

                        if(e.operatorID == 1)
                        {
                            c.number = a.number + b.number;
                        }

                        if(e.operatorID == 2)
                        {
                            c.number = a.number - b.number;
                        }

                        if(e.operatorID == 3)
                        {
                            c.number = a.number * b.number;
                        }

                        if(e.operatorID == 4)
                        {
                            if(b.number == 0) flag = false;
                            else c.number = a.number / b.number;
                        }

                        if(e.operatorID == 10)
                        {
                            c.number = log(b.number)/log(a.number);
                        }

                        if(e.operatorID == 13)
                        {
                            c.number = pow(a.number, b.number);
                        }

                        numberStack.push(c);
                    }
                    else
                        overFlag = true;
                break;

                //sin cos tan ln exp
                case 7:
                case 8:
                case 9:
                case 11:
                case 12:
                    if((numberStack.size() - bracketSeal) >= 1)
                    {
                        element e = operatorStack.top();
                        operatorStack.pop();

                        element a = numberStack.top();
                        numberStack.pop();

                        element c;
                        c.type = 0;

                        if(e.operatorID == 7)
                        {
                            c.number = sin(a.number);
                        }

                        if(e.operatorID == 8)
                        {
                            c.number = cos(a.number);
                        }

                        if(e.operatorID == 9)
                        {
                            c.number = tan(a.number);
                        }

                        if(e.operatorID == 11)
                        {
                            c.number = log(a.number);
                        }

                        if(e.operatorID == 12)
                        {
                            c.number = pow(2.718281828459, a.number);
                        }

                        numberStack.push(c);
                    }
                    else
                        overFlag = true;
                break;

                //(
                case 5:
                    if(operatorStack.top().number != 10)
                    {
                        operatorStack.top().argumentID = bracketSeal;
                        operatorStack.top().number = 10;
                        bracketSeal = numberStack.size();
                    }
                    else
                        overFlag = true;
                break;

                //)
                case 6:
                    operatorStack.pop();
                    if(operatorStack.top().operatorID == 5)
                        bracketSeal = operatorStack.top().argumentID;
                    operatorStack.pop();
                break;
            }
        }
    }

    if(numberStack.size() > 0 && flag)
    {
        element e = numberStack.top();
        numberStack.pop();
        return e.number;
    }
    else
        return 0;
}
