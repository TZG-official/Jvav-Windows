#ifdef WIN32
#include <direct.h>
#endif
#ifdef __WINDOWS_
#include <direct.h>
#endif
#define cls system("cls")
/*
    Jvav Programmer Ver.02w05c Snapshot
    By 30266
    Compilation time 2020-04-16 21:00
    ----------------------------------
    Jvav Programmer Ver.03w00c Snapshot
    By Amiriox
    Compilation time 2020-05-15 15:24
    ----------------------------------
    Jvav Programmer Ver.2 Release
    By Amiriox
    Compilation time 2020-06-02 12:56
    ----------------------------------
    Jvav Programmer Ver.2.1
    By Amiriox
    Compilation time 2020-06-02 20:00
    ----------------------------------
    Jvav Programmer Ver.2.2 Snapshot
    By Amiriox
    Compilation time 2020-06-03 09:30
    ----------------------------------
    Jvav Programmer Ver.2.2.1
    By Amiriox
    Compilation time 2020-06-04 09:53
    -----------------------------------
    Jvav Programmer Ver.2.3
    By Amiriox
    Compilation time 2020-06-10 10:00
    -----------------------------------
    Jvav Programmer Ver.2.3 ReBuild
    By yuzijiangorz
    Compilation time 2020-6-10 14:39
*/
#include <windows.h>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <io.h>
#include "JVMplus.h"
using namespace std;
string language;
string cn_command, cn_type, cn_input_char;
string command, type, inputcharacter;
const double thisver=2.21;
int main(int argc, char** argv);
int exemain(int x);
void settingmoudle();
map<string, int> settingCommandMap;
void windowsInit(){
    system("chcp 65001");
    if( _access("wget.exe",0)==-1) //方式一律改为wget
    {
        printf("fatal Error: Lost wget.exe ");
        return;
    }
    if(_access("upgrade.exe",0)==-1)
    {
        printf("fatal Error: Lost upgrade.exe");
    }
    std::string folderPath = "C:\\Jvav";
    if (0 != access(folderPath.c_str(), 0)) {
        string command="mkdir "+folderPath;
        int result = system(command.c_str()); 
        if(result==-1) cout << '\n' << "Failed to create folder \'C:\\Jvav\'"<<'\n';
    }
    if (0 != access(folderPath.c_str(), 0)) {
        int result = system("mkdir C:\\Jvav\\lib");
        if(result==-1) cout << endl << "Failed to create folder \'C:\\Jvav\\lib\'"<<endl;
    }
    if (0 != access(folderPath.c_str(), 0)) {
        int result = system("mkdir C:\\Jvav\\resource"); 
        if(result==-1) cout << endl << "Failed to create folder \'C:\\Jvav\\resource\'"<<endl;
    }
    system("wget http://cdn.yuzijiangorz.xyz/identifier.res -O C:\\Jvav\\resource\\identifier.res");

}
void all_init() {
#ifdef __WINDOWS_
    windowsInit();
#endif

#ifdef WIN32
    windowsInit();
#endif

#ifdef linux
    cout << "your os is linux."<<endl;
#endif
}
/*
    void checkupdate
    DO: check the update
    Author: yuzijiangorz
*/
void checkupgrade(){
    system("chcp 65001");
    system("wget http://cdn.yuzijiangorz.xyz/newest.txt");
    FILE *fp=fopen("newest.txt","w");
    double ver;
    fscanf(fp,"Ver %.2f",&ver);
    fclose(fp);
    system("del newest.txt");
    if(ver==thisver){printf("你已经在最新版本\n");}
    if(ver>thisver){
        if(MessageBoxA(NULL,"检测到你的Jvav为旧版，是否更新？","更新",MB_YESNO|MB_ICONEXCLAMATION)==IDOK)
        {
        system("update.exe");
        }
        else
        {
            MessageBoxA(NULL,"不更新，继续","更新",NULL);
        }
    }
}
/*
    void init_
    DO: init the program and check the update
    Author: yuzijiangorz
*/
void init_() {
    
    
        if( _access("wget.exe",0)==-1) //方式一律改为wget
    {
        printf("fatal Error: Lost wget.exe\n ");
        return;
    }
    if(_access("upgrade.exe",0)==-1)
    {
        printf("fatal Error: Lost upgrade.exe\n");
        return;
    }
    settingCommandMap["-strict=false"] = 1;
    settingCommandMap["-strict=true"] = 2;
    settingCommandMap["-std"] = 3;
    checkupgrade();
}
bool tmpstrict = true;
int tmpversion = 0;
void processChangeSettings(string set_c) {
    switch (settingCommandMap[set_c]) {
        case 1: {
            tmpstrict = false;
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Strict Mode already been closed." << endl;
            SetConsoleTextAttribute(
        hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        case 2: {
            tmpstrict = true;
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Strict Mode already been opened.";
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        case 3: {
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "Input 11 or 14 or 17 for jvav standard version: ";
            bool outputWarning = bool(tmpversion);
            cin >> tmpversion;
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "The standard has been set to " << tmpversion << endl;
            if (outputWarning) {
                SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "Warning: Before you set it up, the standard version "
                        "is not the default"
                     << endl;
            }
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
        default: {
            cout << "Unknown Setting Options.\n" << endl;
            break;
        }
    }
};
/*
    void helpmoudle
    DO:output Jvav help page
    Author: yuzijiangorz
*/
void helpmoudle()
{
     cout << "----Jvav help------Page(1/1)---\n";
     cout << "  help [page]:Get help\n  compile [filename]:compile "
                    "source code\n"
                    "leave:Exit Jvav\n  output:Output \n"
                    "jvins [source code filename] [execute filename]: make a "
                    "package for your source code\n"
                    "characters\n  input:Input characters\n  upgrade:Online "
                    "detection of version updates\n  language:setting the "
                    "program "
                    "language\n  info:Jvav information\n";
    cout << "----Jvav help------Page(1/1)---\n";
    exemain(1);
}
/*
    void compilemoudle
    DO:complie Jvav program
    Author: yuzijiangorz
*/
void compilemoudle()
{
            string fileName;
            cin >> fileName;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
                cout << "installing identifier library for your device.\n";
                all_init();
                cout << "Your device has already had identifier library.\n";
                cout << "Please re-execute the compile command.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
           exemain(1);
}
/*
    void settingmoudle
    DO: set the setting
    Author: yuzijiangorz
*/
void settingmoudle(){
            HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "tips: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            // SetConsoleColor( FOREGROUND_RED, BACKGROUND_BLUE |
            // FOREGROUND_GREEN );
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "Warning: ";
            hd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "You are changing your settings\n";
            SetConsoleTextAttribute(
                hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "Please enter the Settings you want to change,\nenter quit "
                    "to quit: \n";
            string tmp;
            cin >> tmp;
            while (tmp != "quit") {
                processChangeSettings(tmp);
                cin >> tmp;
            }
            exemain(1);
}
/*
    void leavemoudle
    DO: leave
    Author: yuzijiangorz
*/
void leavemoudle()
{
     cout << "Are you sure to leave jvav?(y/n)";
            string L;
            cin >> L;
            if (L == "y") {
                return;
            } else {
                cls;
                exemain(1);
            }
        
}
/*
    void output
    DO: output things
    Author: yuzijiangorz
*/
void output()
{
            cout << "Jvav>output>";
            cin >> type;
            cout << type << endl;
            exemain(1);
}
/*
    void jvins
    DO: make .jvav to .exe
    Author: yuzijiangorz
*/
void jvinsmoudle()
{
        string fileName;
            cin >> fileName;
            string _oname;
            cin >> _oname;
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(tmpstrict);
            jvav_compiler.setStandardVersion(tmpversion);
            jvav_compiler.setMakePackageOptions(_oname);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
                cout << "installing identifier library for your device.\n";
                all_init();
                cout << "Your device has already had identifier library.\n";
                cout << "Please re-execute the compile command.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
            exemain(1);
}
/*
    void info
    DO: get info
    Author: yuzijiangorz
*/
void info()
{
    cout<< "Jvav Programm Ver.1.2 Pre1\nIt's just a joke, but we still "
                   "make it, and the joke was first brought by Zhang "
                   "Haoyang.\nThis version supports running away from "
                   "jdk.\nThe person writing the program is 30266 and Amiriox.\n";
    exemain(1);                
}
/*
    void input
    DO: let sb input
    Author: yuzijiangorz
*/
void input()
{
    cout << "Jvav>input>";
    cin >> inputcharacter;
    exemain(1);
}
/*
    void balll
    DO: output Jvav program
    Author: yuzijiangorz
*/
void balll()
{
         cout << "---------------------------------------------\n";
        cout << "| Jvav Program               Ver.2.2.1 Pre1 |\n";
        cout << "| By Dr.ZhangHaoYang      Programmer 30266  |\n";
        cout << "| The author of the JCP & Jvins: Amiriox    |\n";
        cout << "| Enter'help'to get help!                   |\n";
        cout << "| Online push updates are now supported!    |\n";
        cout << "| Compile vav source ile are now supported! |\n";
        cout << "--------------------------------------------\n";
}
/*
    int exemain
    DO: do the exe do
    Author: yuzijiangorz
*/
int exemain(int x){


        cout << "Jvav>";
        cin >> command;
        if (command == "help") {helpmoudle();} 
        else if (command == "compile" || command == "cl") {compilemoudle();} 
        else if (command == "settings" || command == "set") {settingmoudle();} 
        else if (command == "jvins" || command == "jvi") {jvinsmoudle();} 
        else if (command == "leave") {leavemoudle();}
        else if (command == "output") {output();} 
        else if (command == "info") {info();}
        else if (command == "input") {input();} 
        else if (command == "exit" || command == "EXIT") {
            return 0;
        } else {
            cout << "Unknown command\n";
            exemain(1);
        }
}
/*
    int main
    DO: do the main do
    Author: yuzijiangorz
*/
int main(int argc, char** argv) {
        init_();
        balll();
      exemain(argc);
        if(argc!=1)
        {
        string cmd = argv[1];
        if (cmd == "-c") {
            string fileName = argv[2];
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(false);
            jvav_compiler.setStandardVersion(11);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
                cout << "installing identifier library for your device.\n";
                all_init();
                cout << "Your device has already had identifier library.\n";
                cout << "Please re-execute the compile command.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
        } else if (cmd == "-o") {
            string fileName = argv[2];
            string _oname = argv[3];
            JvavVirtualMachine jvav_compiler(fileName);
            jvav_compiler.setStrictMode(false);
            jvav_compiler.setStandardVersion(11);
            jvav_compiler.setMakePackageOptions(_oname);
            STATUS_VALUE compile_result = jvav_compiler.compile();
            if (compile_result == STATUS_SUCCESS) {
                cout << "\nCompile successfully.\n";
            } else if (compile_result == STATUS_NO_GPP) {
                cout << "\nCompiler error or there is no g++ compiler "
                        "environment!\n";
            } else if (compile_result == STATUS_NO_IDEN) {
                cout << "\nThe identifier file is missing, please check if the "
                        "identity.res file is in good condition.\n";
                cout << "installing identifier library for your device.\n";
                all_init();
                cout << "Your device has already had identifier library.\n";
                cout << "Please re-execute the compile command.\n";
            } else if (compile_result == STATUS_NO_INPUT) {
                cout << "\nThere are no such files in the directory.\n";
            } else {
                cout << "\nUnknown Error.\n";
            }
        } else if (cmd == "init") {
            all_init();
            cout << "JCP has been initialized." << endl;
            cout << "Updating Jvav Library...\n\n\n" << endl;
            system("update.exe");
            cout << "\n\n\nAll initialized."<<endl;
        } else if (cmd == "update"){
            system("update.exe");
            all_init();
        }
    }
}