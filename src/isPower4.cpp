//
//  isPower4.cpp
//  wm
//
//  Created by Surya Sahukar on 12/18/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#include "isPower4.hpp"

bool isPower4(uint32_t num)
{
    uint8_t pos = 0, set_bits = 0;
    while (num > 0)
    {
        if ( num & 0x1)
            set_bits++;
        pos++;
        num = num >> 1;
    }
    pos--;
    
    if (!(pos % 2) && set_bits == 1)
        return true;
    else
        return false;
    
}
void test_driver_p4(void)
{
    srand((unsigned int) time(NULL));
    int num = 0;
    int cnt = rand() % 10;
    bool result = false;

    for (int i = 0; i < cnt; i++)
    {
        num = rand() % 64;
        result = isPower4(num);
        if(result == true)
            printf("%d is power of 4\n", num);
        else
            printf("%d is not power of 4\n", num);
    }
}
