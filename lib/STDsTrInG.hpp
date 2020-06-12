/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-06-09 23:01:09 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-06-09 23:38:19
 */
#ifndef _STDSTRING_HPP_
#define _STDSTRING_HPP_
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
class BadCast;

class sTrInG{
    private:
     std::string str;
    public:
     sTrInG() = delete;
     sTrInG(const std::string st){ str=st; }
     std::string getStr(){
         return str;
     }
     void print(){
         std::cout << str;
     }
     void println(){
         std::cout << str << std::endl;
     }
};

class cHaR {
   private:
    char value;

   public:
    cHaR() = delete;
    explicit cHaR(char origin) : value(origin) {}
    char getValue () { return value; }
    sTrInG operator+(cHaR& other) {
        std::string tmp;
        tmp+=value;
        tmp+=(other.getValue());
        return tmp;
    }
    void operator+(iNt& other)=delete; //{
    //     // isError=true;
    //     BadCast* E((std::string)"cHaR + iNt is not allowed.");
    //     throw E;
    // }
};

#endif