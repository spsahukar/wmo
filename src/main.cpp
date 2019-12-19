//
//  main.cpp
//  wm
//
//  Created by Surya Sahukar on 12/17/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "planes_in_air.hpp"
#include "rev_ll.hpp"
#include "isPower4.hpp"
#include "reverse_num.hpp"

void help(void)
{
    printf("please check input\n\
    \t to run:\n\
    \t\t ./wmo <q1/q2/q3/q4>\n\
    \t for help:\n\
    \t\t ./wmo help\n");
}

int main(int argc, const char * argv[]) {
    
    if (argc != 2)
    {
        help();
        return -1;
    }

    if (!(strcmp(argv[1] ,"q1")))
        test_driver_planes();
    else if(!(strcmp(argv[1] ,"q2")))
        test_driver_rev_list();
    else if(!(strcmp(argv[1] ,"q3")))
        test_driver_p4();
   	else if(!(strcmp(argv[1] ,"q4")))
       test_driver_rev_num();
   	else if(!(strcmp(argv[1] ,"help")))
		help();
	else
        printf("Check help: ./wm help\n");
	
	return 0;
}
