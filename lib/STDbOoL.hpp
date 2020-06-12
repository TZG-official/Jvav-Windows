/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-06-09 22:55:11 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-06-09 23:12:06
 */
#ifndef _STDBOOL_HPP_
#define _STDBOOL_HPP_
#include "basetype.hpp"
#include "STDsTrInG.hpp"
#include <bits/stdc++.h>

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

class bOoL{
    //此类在用户(开发者)使用时,可以进行扩展
    //方法是is和is2的&&和||操作
    private:
     bool is;
     bool is2;
    public:
     bOoL(bool Is=true,bool Is2=false) : is(Is), is2(Is2) {}
     bool getVal() {return is;}
     bool getOtherVal() {return is2;}
     bool aNd() { return (is && is2); }
     bool oR() {return (is || is2); }
     bool operator||(bOoL& o) { return (is || o.is); }
     bool operator&&(bOoL& o) { return (is && o.is); }
     bool operator*(){return getVal(); }
     sTrInG operator,(bOoL o) { return (std::string)"hahaha, you are so foolish! -by.Amiriox(developer)";}
};

#endif