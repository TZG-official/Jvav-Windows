#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#define STATUS_VALUE int
#define STATUS_SUCCESS 1   //成功
#define STATUS_NO_INPUT 2  //没有或不合法的输入
#define STATUS_NO_IDEN 3   //标识符文件(identifier.res)丢失
#define STATUS_NO_GPP 0    //没有g++环境

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::stringstream;

class JvavVirtualMachine {
    // Jvav Compile Platform
   private:
    std::string fileName;
    bool isStrict;
    int stdv;
    int compileMode;
    std::string oname;

   public:
    JvavVirtualMachine(std::string fName, bool iss = true, int stdversion=0, int comMode=0)
        : fileName(fName), isStrict(iss), stdv(stdversion), compileMode(comMode) {}
    STATUS_VALUE compile();
    void setStrictMode(bool a){
        isStrict=a;
    }
    void setStandardVersion(int ver){
        stdv=ver;
    }
    void setMakePackageOptions(std::string name){
        setCompileMode(1);
        setExecuteFileName(name);
    }
    void setCompileMode(int mode){
        compileMode=mode;
    }
    void setExecuteFileName(std::string on){
        oname = on;
    }
    // TODO : 带有-o参数的直接生成可执行文件
};