#include "JVMplus.h"
STATUS_VALUE JvavVirtualMachine::compile() {
    ifstream srcFile;
    srcFile.open(fileName, ios::in);
    if (!srcFile.is_open()) {
        cout << "error: can not open source file. \n" << endl;
        return STATUS_NO_INPUT;
    } else {
        for (int i = 0; i <= 4; i++)
            fileName.pop_back();  //去掉.jvav后缀名
        fileName += ".cpp";
        stringstream ss;
        ss << srcFile.rdbuf();
        std::string fileToCompile = ss.str();
        srcFile.close();

        ifstream resFile;
        resFile.open("C:\\Jvav\\resource\\identifier.res", ios::in);
        if (!resFile.is_open()) {
            cout << "error: Failed to open the identifier definition file. "
                    "\n"
                 << endl;
            return STATUS_NO_IDEN;
        }

        stringstream sr;
        sr << resFile.rdbuf();
        std::string identifier = sr.str();
        resFile.close();

        ofstream local;
        local.open(fileName, std::ios::out | std::ios::app);
        if (!local.is_open())
            cout << "error: can not create temp file. \n" << endl;
        local << identifier << fileToCompile;
        // local << "system(\"pause\");";
        local.close();

        std::string _comArgs = "g++ ";
        if (isStrict) {
            _comArgs +=
                "-Wall -Werror -Wextra -pedantic -Wimplicit-fallthrough "
                "-Wsequence-point -Wswitch-default -Wswitch-unreachable "
                "-Wswitch-enum -Wstringop-truncation -Wbool-compare "
                "-Wtautological-compare -Wfloat-equal -Wshadow=global "
                "-Wpointer-arith -Wpointer-compare -Wcast-align -Wcast-qual "
                "-Wwrite-strings -Wdangling-else -Wlogical-op ";
        }
        if (stdv != 0) {
            switch (stdv) {
                case 17:
                    _comArgs += "-std=c++17 ";
                    break;
                case 11:
                    _comArgs += "-std=c++11 ";
                    break;
                case 14:
                    _comArgs += "-std=c++14 ";
                    break;

                default:
                    break;
            }
        }
        _comArgs += fileName;
        if (compileMode == 1) {
            _comArgs += " -o ";
            _comArgs += oname;
        }
        int result = system(_comArgs.c_str());
        if (compileMode != 1) {
            if (result == 0) {
                system("a.exe");
                system("del a.exe");
            } else if (result == 1) {
                _comArgs = "del " + fileName;
                system(_comArgs.c_str());
                cout << "deleting *.cpp\n";
                return STATUS_NO_GPP;
            }

            _comArgs = "del " + fileName;
            system(_comArgs.c_str());
            cout << endl;
        }else{
            if (result == 0) {
                std::string nametodel = "del ";
                nametodel+=fileName;
                 system(nametodel.c_str());
                std::cout << "\nYour execute file has been generated." << endl;
            } else if (result == 1) {
                std::cout << "\nUnknown Error." << endl;
            }
        }
    }
    return STATUS_SUCCESS;
}