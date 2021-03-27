#include <iostream>
#include <stdexcept>
#include "tokens.h"

using namespace std;


int main(int argc, char** argv){

    Expr::Parser p;

    extern FILE* yyin;

    yyin = fopen(argv[1], "r");

    try{
        p.parse();
    }catch(std::string& s){
        std::cout <<s<< '\n';
    }

    return 0;
}