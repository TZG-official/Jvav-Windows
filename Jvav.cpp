/*
    Jvav Program Language
    Origin idea from TheZihanGu
    Author: APJifengc
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <sstream>
#include <list>
#include <regex>
#include "stdarg.h"
#include <iomanip>
using namespace std;
enum vartype {
    INT = 'I',
    FLOAT = 'F',
    DOUBLE = 'D',
    CHAR = 'C',
    STRING = 'S',
    BOOL = 'B',
    LONG = 'L',
    VOID = 'V'
};
list<string> vartypes({ "int","double","float","bool","string","char","long" });
struct func {
    map<string, vartype> args;
    vector<string> code;
    vartype retType;
};

map<string, string> publicVarMap;
map<string, func> funcMap;

const int usagec_en = 6;
const char* usage_en[6] = {
    "Usage: jvav bnmfile [args...]",
    "       (Execute Binary Module)",
    "    Or jvav -jvav jvavfile [args...]",
    "       (Execute jvav file)",
    "    Or jvav -jvr jvrfile [args...]",
    "       (Execute jvr file)"
};

const int usagec_zh_cn = 6;
const char* usage_zh_cn[6] = {
    "用法：jvav bnmfile [args...]",
    "      (执行二进制模块)",
    "   或 jvav -jvav jvavfile [args...]",
    "      (执行 jvav 文件)",
    "   或 jvav -jvr jvrfile [args...]",
    "      (执行 jvr 文件)"
};

const int usagec_zh_tw = 6;
const char* usage_zh_tw[6] = {
    "用法: jvav bnmfile [args...]",
    "      (執行二進制模塊)",
    "   或 jvav -jvav jvavfile [args...]",
    "      (執行 jvav 文件)",
    "   或 jvav -jvr jvrfile [args...]",
    "      (執行 jvr 文件)"
};

int usagec;
const char** usage;

ifstream fin;

string doubleToString(double val) {
    ostringstream out;
    out.precision(12);
    out << val;
    return out.str();
}

//摘自网络
vector<string> split(const string& s, char delimiter)
{
    vector<std::string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool isdouble(string x) {
    double y;
    try {
        y = stod(x);
    }
    catch (const std::exception&) {
        return false;
    }
    if (y == int(y) || doubleToString(y)._Equal(doubleToString(float(y))) || y == long(y)) return false;
    return true;
}

bool isfloat(string x) {
    float y;
    try {
        y = stof(x);
    }
    catch (const std::exception&) {
        return false;
    }
    if (y == int(y) || y == long(y) || isdouble(x)) return false;
    return true;
}

bool isint(string x) {
    int y;
    try {
        y = stoi(x);
    }
    catch (const std::exception&) {
        return false;
    }
    return true;
}

bool islong(string x) {
    long y;
    size_t wsize;
    try {
        y = (long)stoll(x,&wsize);
    }
    catch (const std::exception&) {
        return false;
    }
    return true;
}

void checkIdentifierName(char* name) {
    bool lowerUpperCase = false;
    for (int i = 0; i < string(name).length(); i++) {
        if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == '_' || (name[i] >= '0' && name[i] <= '9')) {
            lowerUpperCase = !lowerUpperCase;
            if (name[i] == '_' || (name[i] >= '0' && name[i] <= '9')) {
                lowerUpperCase = false;
            }
            else if (lowerUpperCase) {
                if (!(name[i] >= 'a' && name[i] <= 'z')) {
                    cerr << "Syntax error: Invaild identifier " << name << ". Please use lOwEr_uPpEr_cAsE style." << endl;
                    exit(-10086);
                }
            }
            else {
                if (!(name[i] >= 'A' && name[i] <= 'Z')) {
                    cerr << "Syntax error: Invaild identifier " << name << ". Please use lOwEr_uPpEr_cAsE style." << endl;
                    exit(-10086);
                }
            }
        }
        else {
            cerr << "Syntax error: Invaild identifier " << name << ". Only 0-9, a-z, A-Z, _ are allowed." << endl;
            exit(-10086);
        }
    }
}

vartype getVarType(string value, bool error=true) {
    regex rc("\'.\'"),
        rs("\".*\""),
        rb("true|false");
    if (regex_match(value, rc)) return CHAR;
    if (regex_match(value, rs)) return STRING;
    if (regex_match(value, rb)) return BOOL;
    if (isdouble(value)) return DOUBLE;
    if (isfloat(value)) return FLOAT;
    if (isint(value)) return INT;
    if (islong(value)) return LONG;
    if (error) {
        cerr << "Syntax error: Value " << value << " is not available." << endl;
        exit(-10086);
    }
    else return VOID;
}

vartype getValueType(string value, bool error = true) {
    regex rc("."),
        rs(".*"),
        rb("0|1");
    if (regex_match(value, rc)) return CHAR;
    if (regex_match(value, rs)) return STRING;
    if (regex_match(value, rb)) return BOOL;
    if (isdouble(value)) return DOUBLE;
    if (isfloat(value)) return FLOAT;
    if (isint(value)) return INT;
    if (islong(value)) return LONG;
    if (error) {
        cerr << "Syntax error: Value " << value << " is not available." << endl;
        exit(-10086);
    }
    else return VOID;
}

string formatValue(string type) {
    string result;
    if (strcmp(type.c_str(), "int") == 0) result = "0";
    if (strcmp(type.c_str(), "float") == 0) result = "0.0";
    if (strcmp(type.c_str(), "double") == 0) result = "0.0";
    if (strcmp(type.c_str(), "char") == 0) result = "\0";
    if (strcmp(type.c_str(), "string") == 0) result = "";
    if (strcmp(type.c_str(), "bool") == 0) result = "0";
    if (strcmp(type.c_str(), "long") == 0) result = "0";
    return result;
}

string vartypeToString(vartype type) {
    switch (type) {
    case INT:
        return "int";
    case FLOAT:
        return "float";
    case DOUBLE:
        return "double";
    case CHAR:
        return "char";
    case STRING:
        return "string";
    case BOOL:
        return "bool";
    case VOID:
        return "void";
    case LONG:
        return "long";
    }
}

vartype stringToVartype(string varType, bool allowVoid, bool error=true) {
    vartype type;
    if (strcmp(varType.c_str(), "int") == 0) type = INT;
    else if (strcmp(varType.c_str(), "float") == 0) type = FLOAT;
    else if (strcmp(varType.c_str(), "double") == 0) type = DOUBLE;
    else if (strcmp(varType.c_str(), "bool") == 0) type = BOOL;
    else if (strcmp(varType.c_str(), "string") == 0) type = STRING;
    else if (strcmp(varType.c_str(), "char") == 0) type = CHAR;
    else if (strcmp(varType.c_str(), "long") == 0) type = LONG;
    else if (strcmp(varType.c_str(), "void") == 0 && allowVoid) type = VOID;
    else {
        if (error) {
            cerr << "Syntax error: " << varType << " is not declear." << endl;
            exit(-10086);
        }
        else return vartype(10086);
    }
    return type;
}

string convertValue(string value, vartype type, vartype totype) {
    if (type == totype) return value;
    switch (totype) {
    case INT:
        int a;
        try
        {
            a = stoi(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to int type." << endl;
            exit(-10086);
        }
        return to_string(a);
    case LONG:
        long l;
        try
        {
            l = (long)stoll(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to long type." << endl;
            exit(-10086);
        }
        return to_string(l);
    case FLOAT:
        float f;
        try
        {
            f = stof(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to float type." << endl;
            exit(-10086);
        }
        return doubleToString(f);
    case DOUBLE:
        double d;
        try
        {
            d = stod(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to double type." << endl;
            exit(-10086);
        }
        return doubleToString(d);
    case BOOL:
        switch (type) {
        case INT:
        case LONG:
        case FLOAT:
        case DOUBLE:
        case CHAR:
            if (value == "0") return "0";
            else return "1";
        default:
            cerr << "Syntax error: Unable to convert " << value << " to bool type." << endl;
            exit(-10086);
        }
    case CHAR:
        switch (type) {
        case INT:
        case LONG:
        case FLOAT:
        case DOUBLE:
            int c;
            try
            {
                c = stoi(value);
            }
            catch (const std::exception&)
            {
                cerr << "Syntax error: Unable to convert " << value << " to int type." << endl;
                exit(-10086);
            }
            if (c <= 255) {
                return string(1,char(c));
            }
            else {
                cerr << "Syntax error: Unable to convert " << value << " to int type." << endl;
                exit(-10086);
            }
        default:
            cerr << "Syntax error: Unable to convert " << value << " to int type." << endl;
            exit(-10086);
        }
    case STRING:
        return value;
    }
}

string formatValue(string type, string value) {
    string result;
    vartype varType = stringToVartype(type,false,false);
    vartype var = getVarType(value,false);
    if (var == VOID || varType == vartype(10086)) return "\u0250";
    switch (varType)
    {
    case INT:
        if (value._Equal("true")) return "1";
        if (value._Equal("false")) return "0";
        int a;
        try
        {
            a = stoi(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to int type." << endl;
            exit(-10086);
        }
        return to_string(a);
    case LONG:
        if (value._Equal("true")) return "1";
        if (value._Equal("false")) return "0";
        long l;
        try
        {
            l = (long)stoll(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to long type." << endl;
            exit(-10086);
        }
        return to_string(l);
    case FLOAT:
        if (value._Equal("true")) return "1.0";
        if (value._Equal("false")) return "0.0";
        float f;
        try
        {
            f = stof(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to float type." << endl;
            exit(-10086);
        }
        return doubleToString(f);
    case DOUBLE:
        if (value._Equal("true")) return "1.0";
        if (value._Equal("false")) return "0.0";
        double d;
        try
        {
            d = stod(value);
        }
        catch (const std::exception&)
        {
            cerr << "Syntax error: Unable to convert " << value << " to double type." << endl;
            exit(-10086);
        }
        return doubleToString(d);
    case BOOL:
        if (value._Equal("0")) return "0";
        if (var == INT || var == DOUBLE || var == FLOAT || var == LONG || var == BOOL) return "1";
        else {
            cerr << "Syntax error: Unable to convert " << value << " to bool type." << endl;
            exit(-10086);
        }
    case CHAR:
        if (var == CHAR) return value.substr(1, 1);
        if (var == INT || var == LONG || stoll(value) <= 256) return to_string((char)stoi(value));

    case STRING:
        if (var == STRING) return value.substr(1, value.length() - 2);
        if (var == CHAR) return value.substr(1, 1);
        if (var == BOOL) {
            if (value._Equal("true")) return "1";
            else return "0";
        }
        return value;
    }
}

void* getValue(string str) {
    const char* type = str.substr(0, 1).c_str();
    const char* value = str.substr(1).c_str();
    if (type == "I") {
        return new int(stoi(value));
    }
    else if (type == "F") {
        return new float(stof(value));
    }
    else if (type == "D") {
        return new double(stod(value));
    }
    else if (type == "B") {
        return new bool(stoi(value));
    }
    else if (type == "C") {
        return new char(value[0]);
    }
    else if (type == "S") {
        return new string(value);
    }
    else if (type == "L") {
        return new long(stol(value));
    }
    else {
        cerr << "Unknown error." << str << endl;
        exit(-10099);
    }
}

void regVar(map<string, string> &Map, string name, vartype type) {
    checkIdentifierName((char*)name.c_str());
    if (Map[name] != "") {
        cerr << "Syntax error: Variable " << name << " already exists." << endl;
        exit(-10086);
    }
    Map[name] = string(1, type) + formatValue(vartypeToString(type));
    return;
}

void setVar(map<string, string>& Map, string name, string value) {
    if (Map[name] == "") {
        cerr << "Syntax error: Variable " << name << " is not exist." << endl;
        exit(-10086);
    }
    char* type = (char*)(value.substr(0, 1).c_str());
    Map[name] = string(type) + formatValue(vartypeToString(getVarType(value)), value);
    return;
}

void setVar(map<string, string>& Map, string name, vartype type, string value) {
    if (Map[name] == "") {
        cerr << "Syntax error: Variable " << name << " is not exist." << endl;
        exit(-10086);
    }
    Map[name] = char(type) + value;
    return;
}

string getVar(map<string, string>& Map, string name) {
    if (Map[name] == "") {
        cerr << "Syntax error: Variable " << name << " is not exist." << endl;
        exit(-10086);
    }
    string value = Map[name];
    return value;
}

string runFunc(func function, vector<string> args) {
    vector<string> codes = function.code;
    vartype retType = function.retType;
    map<string, string> varMap;
    for (int i = 0; i < codes.size(); i++) {
        string code = codes[i];
        string firstWord;
        istringstream iss(code);
        iss >> firstWord;
        if (firstWord == "var") {
            string varType,varName;
            iss >> varType >> varName;
            regVar(varMap, varName, stringToVartype(varType,false));
        }
        else if (firstWord == "set") {
            string varName, varType, varValue;
            iss >> varName >> varType;
            getline(iss, varValue);
            varValue = varValue.substr(1);
            if (varType == "var") {
                string var = getVar(varMap, varValue);
                string value = convertValue(var.substr(1), vartype(varMap[varValue].at(0)), vartype(varMap[varName].at(0)));
                setVar(varMap, varName, vartype(varMap[varName].at(0)), value);
            }
            else if (varType == "input") {
                string input;
                if (varType == "word") {
                    cin >> input;
                }
                else {
                    getline(cin, input);
                }
                input = convertValue(input, getValueType(input), vartype(varMap[varName].at(0)));
                setVar(varMap, varName, vartype(varMap[varName].at(0)), input);
            }
            else {
                string value = convertValue(varValue, stringToVartype(varType,false), vartype(varMap[varName].at(0)));
                setVar(varMap,varName,stringToVartype(varType,false),value);
            }
        }
        else if (firstWord == "ret") {
            string varType, varValue;
            iss >> varType;
            getline(iss, varValue);
            varValue = varValue.substr(1);
            if (varType == "var") {
                string var = getVar(varMap, varValue);
                string value = convertValue(var.substr(1), vartype(varMap[varValue].at(0)), retType);
                return char(retType) + value;
            }
            else if (varType == "input") {
                string input;
                if (varType == "word") {
                    cin >> input;
                }
                else {
                    getline(cin, input);
                }
                input = convertValue(input, getValueType(input), vartype(retType));
                return char(retType) + input;
            }
            else {
                string value = convertValue(varValue, stringToVartype(varType, false), retType);
                return char(retType) + value;
            }
        }
        else if (firstWord == "out") {
            string varType, varValue;
            iss >> varType;
            getline(iss, varValue);
            varValue = varValue.substr(1);
            if (varType == "var") {
                cout << getVar(varMap, varValue).substr(1);
            }
            else if (varType == "input") {
                string input;
                if (varType == "word") {
                    cin >> input;
                }
                else {
                    getline(cin, input);
                }
                getValueType(input);
                cout << input;
            }
            else {
                cout << varValue;
            }
        }
    }
}

int main(int argc, char** argv) {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    string lc = setlocale(LC_ALL, "");
    if (lc.find("China")) {
        usage = usage_zh_cn;
        usagec = usagec_zh_cn;
    }
    else if (lc.find("Traditional")) {
        usage = usage_zh_tw;
        usagec = usagec_zh_tw;
    }
    else {
        usage = usage_en;
        usagec = usagec_en;
    }
    if (argc == 1) {
        for (int i = 0; i < usagec; i++) {
            cout << usage[i] << endl;
        }
        return 0;
    }
    else if (strcmp(argv[1],"-jvr")==0) {
        cout << "Not done yet. Please wait." << endl;
    }
    else if (strcmp(argv[1],"-jvav")==0) {
        if (argc == 2) {
            cerr << "Error: -jvav requires jvav file specification" << endl;
            for (int i = 0; i < usagec; i++) {
                cout << usage[i] << endl;
            }
            return -10086;
        }
        fin.open(argv[2]);
        if (fin.fail()) {
            cerr << "Error: Can't find or can't access jvavfile " << argv[2] << endl;
            return -10086;
        }
        string line;
        int depth;
        getline(fin, line);
        if (strcmp(line.c_str(), "#Language Jvav Made By Dr.ZhangHaoYang") != 0) {
            cerr << "Syntax error: No author declear. \n"
                 << "              Please enter \"#Language Jvav Made By Dr.ZhangHaoYang\" in the first line" << endl;
            return -10086;
        }
        func* currentFunc = NULL;
        int linec = 0;
        do {
            linec++;
            getline(fin, line);
            if (strcmp(line.c_str(), "") == 0) continue;
            depth = 0;
            while (line.at(0) == ' ') {
                depth++;
                line = line.substr(1);
            }
            if (line.at(0) == '#') {
                continue;
            }
            istringstream iss(line);
            if (depth == 0) //全局变量&函数
            {                                                            
                string varType;
                iss >> varType;
                vartype type = stringToVartype(varType,true);
                string name;
                getline(iss, name);
                if (name == "") {
                    cerr << "Syntax error: No variable or function name." << endl;
                    return -10086;
                }
                name = name.substr(1);
                int parenthesis = 0;
                bool isClosed = true;
                for (int i = 0; i < name.length(); i++) {
                    if (name.at(i) == '(') {
                        parenthesis++;
                        isClosed = false;
                    }
                    if (name.at(i) == ')') {
                        isClosed = true;
                    }
                }
                if (parenthesis == 0 && type == VOID) {
                    cerr << "Syntax error: void cannot use in a variable." << endl;
                    return -10086;
                }
                if (isClosed == false) {
                    cerr << "Syntax error: Parentheses don't match.";
                    return -10086;
                }
                if (parenthesis > 0) { //Functions
                    vector<string> splitStr = split(name, '(');
                    string funcName = splitStr[0];
                    vector<string> args = split(splitStr[1].substr(0,splitStr[1].length()-1), ',');
                    func function;
                    function.retType = type;
                    for (string str : args) {
                        istringstream iss(str);
                        string argType,argName;
                        iss >> argType >> argName;
                        pair<string, vartype> argPair;
                        argPair.first = argName;
                        argPair.second = stringToVartype(argType, false);
                        function.args.insert(argPair);
                    }
                    funcMap[funcName] = function;
                    currentFunc = &funcMap[funcName];
                }
                else { //Global Variables
                    currentFunc = NULL;
                    regVar(publicVarMap, name, type);
                }
            }
            else {
                string code;
                string firstWord;
                vector<string> splitText = split(line, ' ');
                iss >> firstWord;
                if (strcmp(firstWord.c_str(),"int") == 0 || strcmp(firstWord.c_str(),"float") == 0 || strcmp(firstWord.c_str(),"double") == 0 || strcmp(firstWord.c_str(),"bool") == 0 ||
                    strcmp(firstWord.c_str(),"string") == 0 || strcmp(firstWord.c_str(),"char") == 0 || strcmp(firstWord.c_str(),"long") == 0) {
                    string varname;
                    iss >> varname;
                    checkIdentifierName((char*)varname.c_str());
                    code = "var " + firstWord + " " + varname;
                    currentFunc->code.push_back(code);
                    string other;
                    iss >> other;
                    if (strcmp(other.c_str(),"=") == 0) {
                        string value;
                        getline(iss, value);
                        value = value.substr(1);
                        if (value._Equal("inputWord")) {
                            code = "set " + varname + " input word";
                        }
                        else if (value._Equal("inputLine")) {
                            code = "set " + varname + " input line";
                        }
                        else {
                            string valueFormat = formatValue(firstWord, value);
                            if (valueFormat == "\u0250") {
                                checkIdentifierName((char*)value.c_str());
                                code = "set " + varname + " var " + value;
                            }
                            else {
                                code = "set " + varname + " " + firstWord + " " + valueFormat;
                            }
                        }
                        currentFunc->code.push_back(code);
                    }
                    else if (strcmp(other.c_str(), "") != 0){
                        cerr << "Syntax error: " << other << " shouldn't be here." << endl;
                        return -10086;
                    }
                }
                else if (splitText.size() >= 3 && strcmp(splitText[1].c_str(), "=") == 0) {
                    string varName = firstWord;
                    checkIdentifierName((char*)varName.c_str());
                    string value;
                    iss >> value;
                    getline(iss, value);
                    value = value.substr(1);
                    if (value._Equal("inputWord")) {
                        code = "set " + varName + " input word";
                    }
                    else if (value._Equal("inputLine")) {
                        code = "set " + varName + " input line";
                    }
                    else {
                        string varType = vartypeToString(getVarType(value, false));
                        string valueFormat = formatValue(varType, value);
                        if (valueFormat == "\u0250") {
                            checkIdentifierName((char*)value.c_str());
                            code = "set " + varName + " var " + value;
                        }
                        else {
                            code = "set " + varName + " " + varType + " " + valueFormat;
                        }
                    }
                    currentFunc->code.push_back(code);
                }
                else if (firstWord._Equal("return")) {
                    string value;
                    string valueFormat;
                    getline(iss, value);
                    value = value.substr(1);
                    if (value._Equal("inputWord")) {
                        code = "ret input word";
                    }
                    else if (value._Equal("inputLine")) {
                        code = "ret input line";
                    }
                    else {
                        string varType = vartypeToString(getVarType(value, false));
                        valueFormat = formatValue(varType, value);
                        if (valueFormat == "\u0250") {
                            checkIdentifierName((char*)value.c_str());
                            code = "ret var " + value;
                        }
                        else {
                            code = "ret " + varType + " " + valueFormat;
                        }
                    }
                    currentFunc->code.push_back(code);
                }
                else if (firstWord._Equal("output")) {
                    string value;
                    string valueFormat;
                    getline(iss, value);
                    value = value.substr(1);
                    if (value._Equal("inputWord")) {
                        code = "out input word";
                    }
                    else if (value._Equal("inputLine")) {
                        code = "out input line";
                    }
                    else {
                        string varType = vartypeToString(getVarType(value, false));
                        valueFormat = formatValue(varType, value);
                        if (valueFormat == "\u0250") {
                            checkIdentifierName((char*)value.c_str());
                            code = "out var " + value;
                        }
                        else {
                            code = "out " + varType + " " + valueFormat;
                        }
                    }
                    currentFunc->code.push_back(code);
                }
            }
        } while (!fin.eof());
        if (funcMap.count("mAiN") != 1) {
            cerr << "Syntax error: There is no mAiN function." << endl;
            return -10086;
        }
        if (funcMap["mAiN"].retType != INT) {
            cerr << "Syntax error: The mAiN function's return type must be int." << endl;
            return -10086;
        }
        vector<string> args;
        for (int argi = 2; argi < argc; argi++) args.push_back(argv[argi]);
        return stoi(runFunc(funcMap["mAiN"], args).substr(1));
    }
    else {
        cout << "Not done yet. Please wait." << endl;
    }
    for (int i=0;i< funcMap["mAiN"].code.size();i++) {
        cout << funcMap["mAiN"].code[i] << endl;
    }
    return 0;
}