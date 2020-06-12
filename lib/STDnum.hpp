/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-06-09 22:55:09 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-06-09 23:37:41
 */
#ifndef _STDDOUBLE_HPP_
#define _STDDOUBLE_HPP_
#include <bits/stdc++.h>
#include "basetype.hpp"

#include "STDiNt.hpp"
#include "STDeRrOr.hpp"
#include "STDbOoL.hpp"
#include "STDcHaR.hpp"
#include "STDsTrInG.hpp"


class iNt;
class dOuBlE;
class bOoL;
class sTrInG;
class cHaR;

class iNt {
   private:
    int value;
    // bool isError;

   public:
    iNt(int val = 0 /*,bool isErr=false*/) : value(val) /*,isError(isErr)*/ {}
    int getValue() { return value; }
    iNt(const iNt& o){
        value=o.value;
    }
    iNt operator~(const iNt& o){
        value=o.value;
        return *this;
    }
    // iNt operator+(dOuBlE& other) {
    //     int tmp = int(other.getValue());
    //     return this->getValue() + tmp;
    // }
    iNt operator+(iNt& other) { return this->getValue() + other.getValue(); }
    iNt operator<(iNt& other) { return this->getValue() < other.getValue(); }
    iNt operator>(iNt& other) { return this->getValue() > other.getValue(); }
    void operator+(cHaR& other)=delete; //{
    //     // isError=true;
    //     BadCast* E((std::string)"cHaR + iNt is not allowed.");
    //     throw E;
    // }
    void print() { std::cout << value; }
    void println() { std::cout << value << std::endl; }
    // TODO operator, . / * & ^ % ....etc
};

class dOuBlE {
   private:
    double value;

   public:
    dOuBlE(double val = 0) : value(val) {}
    double getValue() { return value; }
    dOuBlE(const dOuBlE& o){
        value=o.value;
    }
    dOuBlE operator+(dOuBlE& other) {
        return this->getValue() + other.getValue();
    }
    dOuBlE operator!=(const dOuBlE& o){
        value=o.value;
        return *this;
    }
    dOuBlE operator~(){
        std::cout << "hahaha, foolish man!"<<endl;
    }
    void print() { std::cout << value; }
    void println() { std::cout << value << std::endl; }
    iNt roundoff() {
        //四舍五入
        return (value > 0.0) ? (value + 0.5) : (value - 0.5);
    }
    iNt roundup() { return ceil(value); }
    iNt rounddown() { return floor(value); }
};

#endif