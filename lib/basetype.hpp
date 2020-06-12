/*
 * @Author: AMIRIOX無暝 
 * @Date: 2020-06-09 22:05:18 
 * @Last Modified by: AMIRIOX無暝
 * @Last Modified time: 2020-06-09 23:12:13
 * 由于以下类没有使用new/delete,所以暂时没写复制构造函数
TODO 写复制构造函数和重载`=`运算符 
 */
#ifndef _BASETYPE_HPP_
#define _BASETYPE_HPP_

#include <cmath>
#include <iostream>
#include <string>

#include "STDiNt.hpp"
#include "STDeRrOr.hpp"
#include "STDbOoL.hpp"
#include "STDcHaR.hpp"
#include "STDsTrInG.hpp"
#include "STDnum.hpp"

#define v(x) x.getVal() 

class iNt;
class dOuBlE;
class bOoL;
class sTrInG;
class cHaR;

template <typename T, typename M>
T fake_cast(M y) {
    return (T)y;
}

#endif