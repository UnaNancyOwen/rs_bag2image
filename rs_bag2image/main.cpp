#include <iostream>
#include <sstream>

#include "realsense.h"

int main( int argc, char* argv[] )
{
    try{
        RealSense realsense( argc, argv );
        realsense.run();
    } catch( std::exception& ex ){
        std::cout << ex.what() << std::endl;
    }

    return 0;
}