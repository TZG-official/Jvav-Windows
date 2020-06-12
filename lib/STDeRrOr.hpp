/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-06-09 22:55:14 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-06-09 23:23:40
 */
#ifndef _STDERROR_HPP_
#define _STDERROR_HPP_
#include <bits/stdc++.h>
#include "basetype.hpp"

#include "STDiNt.hpp"
#include "STDeRrOr.hpp"
#include "STDbOoL.hpp"
#include "STDcHaR.hpp"
#include "STDsTrInG.hpp"
#include "STDnum.hpp"


class iNt;
class dOuBlE;
class bOoL;
class sTrInG;
class cHaR;

class syntaxError {
   private:
    std::string wstr;

   public:
    syntaxError(std::string What = "Unknown Error") : wstr(What) {}
    std::string what() { return wstr; }
    void print() { std::cout << wstr; }
};

class BadCast : public syntaxError {
   public:
    BadCast(std::string What = "Unknown bad cast error") : syntaxError(What) {}
    void print() { std::cout << what() << std::endl; }
};
#endif