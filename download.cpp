//* this commented code is the old update.exe by amiriox
//* and the new code is the new update.exe by yuzijiangorz
// /*
// 目前
// */

// #include <ShlObj.h>
// #include <bits/stdc++.h>
// #include <io.h>
// #include <shlwapi.h>
// #include <stdlib.h>
// #include <windows.h>
// using namespace std;
// #define STATUS_SUCCESS 1
// #define STATUS_ERROR -1;

// char *ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn) {
//     LPSTR pszOut = NULL;
//     try {
//         if (lpwszStrIn != NULL) {
//             int nInputStrLen = wcslen(lpwszStrIn);

//             // Double NULL Termination
//             int nOutputStrLen =
//                 WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL,
//                 0, 0, 0) +2;
//             pszOut = new char[nOutputStrLen];

//             if (pszOut) {
//                 memset(pszOut, 0x00, nOutputStrLen);
//                 WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut,
//                                     nOutputStrLen, 0, 0);
//             }
//         }
//     } catch (std::exception e) {
//         cout << "Unknown error." << endl;
//     }
//     return pszOut;
// }

// int replace(std::string cd) {
//     // copy cd\\Jvav-tmp\\... cd\\...
//     string base = "copy ";
//     base+=cd; base+="\\Jvav-tmp\\";

//     string delp(base);
//     delp+="demo-cn.jvav ";
//     string cmd = delp+cd+(string)"\\demo-cn.jvav";
//     system(cmd.c_str());

//     delp=base;
//     delp+="JCP.exe ";
//     cmd = delp+cd+(string)"\\JCP.exe";
//     system(cmd.c_str());

//     delp=base;
//     delp+="README.md ";
//     cmd = delp+cd+(string)"\\README.md";
//     system(cmd.c_str());
// }
// void delOld(std::string cd){
//     string cmd = "del "; cmd+=cd;
//     cmd+="\\JCP.exe";
//     system(cmd.c_str());

//     cmd = "del "; cmd+=cd;
//     cmd+="\\demo-cn.jvav";
//     system(cmd.c_str());

//     cmd = "del "; cmd+=cd;
//     cmd+="\\README.md";
//     system(cmd.c_str());
// }
// int main(int argc, char **argv) {
//     // //初始化
//     system("title JCP Update Installer");
//     if (_access("wget.exe", 0) == -1) {
//         cout << "fatal error : Lost wget.exe" << endl;
//         return 0;
//     } 
//     CHAR c[MAX_PATH];
//     DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
//     std::string direy(c);
//     std::string wgetDir(direy);
//     wgetDir+="\\wget.exe";

//     //system("pause");
//     printf("Begin to update.....\n");
//     Sleep(3000);
//     std::string cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/Jvav.7z";
//     system(cmd.c_str());  //获取
//     cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/7z.exe";
//     system(cmd.c_str());
//     cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/7z.dll";
//     system(cmd.c_str());
//     //解压
//     std::string sevenZDir=direy+"\\7z.exe";
//     std::string jvavDir =direy+"\\Jvav.7z";
//     system("mkdir Jvav-tmp");

//     cmd = sevenZDir; cmd+=" x -y ";cmd+= jvavDir; cmd+=" -o";
//     cmd+=direy; cmd+="\\Jvav-tmp";
//     delOld(direy);
//     system(cmd.c_str());
    
//     replace(direy);

//     cmd=(string)"del "+direy+(string)"\\Jvav-tmp";
//     system(cmd.c_str());
//     cmd=(string)"del "+direy+(string)"\\Jvav.7z";
//     system(cmd.c_str());
//     cmd=(string)"del "+direy+(string)"\\7z.exe";
//     system(cmd.c_str());
//     cmd=(string)"del "+direy+(string)"\\7z.dll";
//     system(cmd.c_str());
//     cout << "更新完毕.您可以删除Jvav-tmp文件夹." << endl;

//     system("pause");
//     return 0;
// }
/*
2020.6.6 21:44 update by yuzijiangorz
add:
    1.可以删除Jvav-tmp文件夹了
    2.导入了lib库(如果你有的话会自动更新)
    3.解决了乱码问题
*/

#include <ShlObj.h>
#include <bits/stdc++.h>
#include <io.h>
#include <shlwapi.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
#define STATUS_SUCCESS 1
#define STATUS_ERROR -1;
/**
 * function: ConvertLPWSTRToLPSTR 
 * type: char*; 
 * do: Convert LPWSTR To LPSTR;
 * args:
 *      1. lpwszStrIn type:LPWSTR used: 转换参数       
 */
char *ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn) {
    LPSTR pszOut = NULL;
    try {
        if (lpwszStrIn != NULL) {
            int nInputStrLen = wcslen(lpwszStrIn);

            // Double NULL Termination
            int nOutputStrLen =
                WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL,
                0, 0, 0) +2;
            pszOut = new char[nOutputStrLen];

            if (pszOut) {
                memset(pszOut, 0x00, nOutputStrLen);
                WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut,
                                    nOutputStrLen, 0, 0);
            }
        }
    } catch (std::exception e) {
        cout << "Unknown error." << endl;
    }
    return pszOut;
}
/**
 * function: replace;
 * type: string;
 * do: replace sources of Jvav
 * args:
 *      1. cd type:string used: 需要替换的目录
 */
int replace(std::string cd) {
    string base = "copy ";
    base+=cd; base+="\\Jvav-tmp\\";

    string delp(base);
    delp+="demo-cn.jvav ";
    string cmd = delp+cd+(string)"\\demo-cn.jvav";
    system(cmd.c_str());

    delp=base;
    delp+="JCP.exe ";
    cmd = delp+cd+(string)"\\JCP.exe";
    system(cmd.c_str());

    delp=base;
    delp+="README.md ";
    cmd = delp+cd+(string)"\\README.md";
    system(cmd.c_str());
}
void delOld(std::string cd){
    string cmd = "del "; cmd+=cd;
    cmd+="\\JCP.exe";
    system(cmd.c_str());

    cmd = "del "; cmd+=cd;
    cmd+="\\demo-cn.jvav";
    system(cmd.c_str());

    cmd = "del "; cmd+=cd;
    cmd+="\\README.md";
    system(cmd.c_str());
}
int main(int argc, char **argv) {
    system("chcp 65001");//解决了结尾乱码的问题
    system("title JCP Update Installer");
    if (_access("wget.exe", 0) == -1) {
        cout << "fatal error : Lost wget.exe" << endl;
        getchar();
        return 0;
    } 
    CHAR c[MAX_PATH];
    DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
    std::string direy(c);
    std::string wgetDir(direy);
    wgetDir+="\\wget.exe";

    //system("pause");
    printf("Begin to update.....\n");
    Sleep(3000);
    std::string cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/Jvav.7z";
    system(cmd.c_str());  //获取
    cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/7z.exe";
    system(cmd.c_str());
    cmd = wgetDir+" http://cdn.yuzijiangorz.xyz/7z.dll";
    system(cmd.c_str());
    //解压
    std::string sevenZDir=direy+"\\7z.exe";
    std::string jvavDir =direy+"\\Jvav.7z";
    system("mkdir Jvav-tmp");

    cmd = sevenZDir; cmd+=" x -y ";cmd+= jvavDir; cmd+=" -o";
    cmd+=direy; cmd+="\\Jvav-tmp";
    delOld(direy);
    system(cmd.c_str());
    
    replace(direy);
    printf("get lib...\n");
    system("del C:\\Jvav\\lib");
    system("rd /s /q C:\\Jvav\\lib");//rd只有删除文件夹的功能，没有删除文件的权限
    system("wget http://cdn.yuzijiangorz.xyz/Jvavlib.7z");
    system("7z.exe x Jvavlib.7z -oC:\\Jvav");
    system("del Jvavlib.7z");
    printf("delete files...\n");
    cmd=(string)"del "+direy+(string)"\\Jvav-tmp";
    system(cmd.c_str());
    cmd=(string)"del "+direy+(string)"\\Jvav.7z";
    system(cmd.c_str());
    cmd=(string)"del "+direy+(string)"\\7z.exe";
    system(cmd.c_str());
    cmd=(string)"del "+direy+(string)"\\7z.dll";
    system(cmd.c_str());
    cmd=(string)"rd /s /q"+direy+(string)"\\Jvav-tmp";//删除Jvav-tmp文件夹
    system(cmd.c_str());
    /**
     * 更新update.exe
     * printf("执行完毕,现在更新update.exe");
     * ofstream outf("ui.bat")
     * outf<<"echo 开始执行...\n";
     * outf<<"del update.exe"
     * outf<<"wget.exe http://cdn.yuzijiangorz.xyz/update.exe";
     * outf<<"echo 下载完毕\n;"
     * outf<<"del %0";
     * outf.close();
     * system("ui.bat");
    */
    cout << "update done." << endl;
    getchar();
    return 0;
}