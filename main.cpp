//
// main.h
//
//  Created on: 01/09/2021
//      Author: Angel Rico
//

#include "app.h"

int main(int argc, char* argv[]) {
    App *init = new App();
    init->start();

    delete init;
    return 0;
}

// g++ main.cpp 