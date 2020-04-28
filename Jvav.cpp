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
        cout << "Please enter the setting language(English/��������):";
        string language;
        cin >> language;
        if (language == "English") {
            goto main;
        }
        else if (language == "��������") {
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
    language = "��������";
    cout << "--------------------------------------------\n";
    cout << "| Jvav������             �汾��1.2 Ԥ����3 |\n";
    cout << "| ���ߣ��ź����ʦ  ��д�ߣ�30266,aa11ss55 |\n";
    cout << "| ͨ������'����'����ð���                 |\n";
    cout << "| ����֧���������͸��£�                   |\n";
    cout << "--------------------------------------------\n";
cn_main:
    cout << "Jvav>";
    cin >> command;
    if (command == "����") {
        cout << "----Jvav����---��(1/1)ҳ----\n";
        cout << "  ���� [ҳ��]:��ȡ����\n  �˳�:�˳�Jvav\n  ���:����ַ�\n  ����:�����ַ��Ա����\n  ����:���߼��汾����\n  ����:����Jvav������\n  ����:��ȡ����Jvav����Ϣ\n";
        cout << "----Jvav����---��(1/1)ҳ----\n";
        goto cn_main;
    }
    else if (command == "�˳�") {
        cout << "��ȷ��Ҫ�˳�Jvav��(��/��)";
        cin >> command;
        if (command == "��") {
            return 0;
        }
        else {
            goto cn_main;
        }
    }
    else if (command == "���") {
        cout << "Jvav>���>";
        cin >> type;
        cout << type << endl;
        goto cn_main;
    }
    else if (command == "����") {
        cout << "Jvav>����>";
        cin >> inputcharacter;
        goto cn_main;
    }
    else if (command == "����") {
        cout << "Jvav��������汾Ϊ1.2Ԥ����1��\n��ֻ��һ����������������Ȼ�����������ʵ���������ź���������������\n�ð汾֧������jdk�����С�\n�ó����д��Ϊ30266��\nGithub��Դ��ַ:github.com/TZG-official/Jvav-Windows(Windows ��Դ����)\n��ҳԴ����:github.com/TZG-official/Jvav\n";
        goto cn_main;
    }
    else if (command == "����") {
        cout << "Jvav>����>���ڻ�ȡ�汾�б�...\n";
        goto upgrade;
    }
    else if (command == "����") {
        cout << "��������Ҫ�л�������(��������/English):";
        cin >> language;
        if (language == "��������") {
            goto cn_main;
        }
        else if (language == "English") {
            system("cls");
            language = "English";
            goto en_main;
        }
        else {
            cout << "δ֪�����ԡ�\n";
            goto cn_main;
        }
    }
    else {
        cout << "δ֪�����\n";
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
        else if (language == "��������") {
            cout << "Jvav>����>�����޷�����֤��������ȡ�汾�б�\n";
            goto cn_main;
        }
    }
    else if (ret > 6) {
        if (language == "English") {
            cout << "Jvav>upgrade>Updated versionavailable for upgrades, please go to https://30266-official.github.io/updates/Jvav.zip download!\n";
            goto main;
        }
        else if (language == "��������") {
            cout << "�и��°汾�ɹ���������ǰ��https://30266-official.github.io/updates/Jvav.zip���أ�\n";
            goto cn_main;
        }
    }
    else if (ret == 6) {
        if (language == "English") {
            cout << "Congratulations! You've upgraded to the latest version!\n";
            goto main;
        }
        else {
            cout << "��ϲ�㣡�������������°汾��\n";
            goto cn_main;
        }
    }
    else {
        if (language == "English") {
            cout << "Jvav>upgrade>Error!We can't get a version list because your version is coming from a future version, so we don't support it.\n";
            goto main;
            cout << ret;
        }
        else if (language == "��������") {
            cout << "Jvav>����>���������޷���ȡ�汾�б���Ϊ���İ汾������δ���İ汾�������ǲ��ṩ֧�֡�\n";
            goto cn_main;
        }
    }
}