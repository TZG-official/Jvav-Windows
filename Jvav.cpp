/*
    Jvav Programmer Ver.02w05c Snapshot
    By 30266
    Compilation time 2020-04-28 11:30
    GCC O5
*/
#include <iostream>
#include<fstream>
#include <windows.h>
using namespace std;
int main()
{
    cout << "Initializing program...\n";
    string language,command, type, inputcharacter;
    language = "English";
    cout << "Configuring the online update service...\n";
    system("del upgrade.txt");
    system("cls");
    /*en_main*/
    en_main:
    cout << "--------------------------------------------\n";
    cout << "| Jvav Program                Ver.1.2 Pre2 |\n";
    cout << "| By Dr.ZhangHaoYang      Programmer 30266 |\n";
    cout << "| Enter'help'to get help!                  |\n";
    cout << "| Online push updates are now supported!   |\n";
    cout << "--------------------------------------------\n";
main:
    cout << "Jvav>";
    cin >> command;
    if (command == "help") {
        cout << "----Jvav help------Page(1/1)---\n";
        cout << "  help [page]:Get help\n  leave:Exit Jvav\n  output:Output characters\n  input:Input characters\n  upgrade:Online detection of version updates\n  language:setting the program language\n  info:Jvav information\n";
        cout << "----Jvav help------Page(1/1)---\n";
        goto main;
    }
    else if (command == "leave") {
        cout << "Are you sure to leave jvav?(y/n)";
        string L;
        cin >> L;
        if (L == "y") {
            return 0;
        }
        else {
            goto main;
        }
    }
    else if (command == "output") {
        cout << "Jvav>output>";
        cin >> type;
        cout << type << endl;
        goto main;
    }
    else if (command == "info") {
        cout << "Jvav Programm Ver.1.2 Pre1\nIt's just a joke, but we still make it, and the joke was first brought by Zhang Haoyang.\nThis version supports running away from jdk.\nThe person writing the program is 30266.\n";
        goto main;
    }
    else if (command == "input") {
        cout << "Jvav>input>";
        cin >> inputcharacter;
        goto main;
    }
    else if (command == "upgrade") {
        cout << "Jvav>upgrade>Getting a version list...\n";
        goto upgrade;
    }
    else if (command == "language") {
        cout << "Please enter the setting language(English/简体中文):";
        string language;
        cin >> language;
        if (language == "English") {
            goto main;
        }
        else if (language == "简体中文") {
            system("cls");
            goto ch;
        }
        else {
            cout << "Unknown language.\n";
            goto main;
        }
    }
    else {
        cout << "Unknown command\n";
        goto main;
    }

    /*cn_main*/
ch:
    language = "简体中文";
    cout << "--------------------------------------------\n";
    cout << "| Jvav编译器             版本：1.2 预览版3 |\n";
    cout << "| 作者：张浩洋大师  编写者：30266,aa11ss55 |\n";
    cout << "| 通过输入'帮助'来获得帮助                 |\n";
    cout << "| 现已支持在线推送更新！                   |\n";
    cout << "--------------------------------------------\n";
cn_main:
    cout << "Jvav>";
    cin >> command;
    if (command == "帮助") {
        cout << "----Jvav帮助---第(1/1)页----\n";
        cout << "  帮助 [页码]:获取帮助\n  退出:退出Jvav\n  输出:输出字符\n  输入:输入字符以便调用\n  更新:在线检测版本更新\n  语言:设置Jvav的语言\n  关于:获取关于Jvav的信息\n";
        cout << "----Jvav帮助---第(1/1)页----\n";
        goto cn_main;
    }
    else if (command == "退出") {
        cout << "你确定要退出Jvav吗？(是/否)";
        cin >> command;
        if (command == "是") {
            return 0;
        }
        else {
            goto cn_main;
        }
    }
    else if (command == "输出") {
        cout << "Jvav>输出>";
        cin >> type;
        cout << type << endl;
        goto cn_main;
    }
    else if (command == "输入") {
        cout << "Jvav>输入>";
        cin >> inputcharacter;
        goto cn_main;
    }
    else if (command == "关于") {
        cout << "Jvav编程器，版本为1.2预览版1。\n这只是一个梗，但是我们依然把它变成了现实。最早是张浩洋提出的这个梗。\n该版本支持脱离jdk的运行。\n该程序编写者为30266。\nGithub开源地址:github.com/TZG-official/Jvav-Windows(Windows 端源代码)\n网页源代码:github.com/TZG-official/Jvav\n";
        goto cn_main;
    }
    else if (command == "更新") {
        cout << "Jvav>更新>正在获取版本列表...\n";
        goto upgrade;
    }
    else if (command == "语言") {
        cout << "请输入您要切换的语言(简体中文/English):";
        cin >> language;
        if (language == "简体中文") {
            goto cn_main;
        }
        else if (language == "English") {
            system("cls");
            language = "English";
            goto en_main;
        }
        else {
            cout << "未知的语言。\n";
            goto cn_main;
        }
    }
    else {
        cout << "未知的命令！\n";
        goto cn_main;
    }
/*upgrade*/
    upgrade:
    system("java -jar upgrade.jar > upgrade.txt");
    ifstream readFile("upgrade.txt");
    int ret;
    readFile >> ret;
    readFile.close();
    if (ret == -1) {
        if (language == "English") {
            cout << "Jvav>upgrade>Error! The update failed! Because the version list cannot be obtained on the authentication server!\n";
            goto main;
        }
        else if (language == "简体中文") {
            cout << "Jvav>更新>错误！无法从认证服务器获取版本列表！\n";
            goto cn_main;
        }
    }
    else if (ret > 6) {
        if (language == "English") {
            cout << "Jvav>upgrade>Updated versionavailable for upgrades, please go to https://30266-official.github.io/updates/Jvav.zip download!\n";
            goto main;
        }
        else if (language == "简体中文") {
            cout << "有更新版本可供升级，请前往https://30266-official.github.io/updates/Jvav.zip下载！\n";
            goto cn_main;
        }
    }
    else if (ret == 6) {
        if (language == "English") {
            cout << "Congratulations! You've upgraded to the latest version!\n";
            goto main;
        }
        else {
            cout << "恭喜你！你已升级至最新版本！\n";
            goto cn_main;
        }
    }
    else {
        if (language == "English") {
            cout << "Jvav>upgrade>Error!We can't get a version list because your version is coming from a future version, so we don't support it.\n";
            goto main;
            cout << ret;
        }
        else if (language == "简体中文") {
            cout << "Jvav>更新>错误！我们无法获取版本列表，因为您的版本是来自未来的版本，故我们不提供支持。\n";
            goto cn_main;
        }
    }
}