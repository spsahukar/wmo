//
//  reverse_num.cpp
//  wm
//
//  Created by Surya Sahukar on 12/18/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#include "reverse_num.hpp"

uint8_t rev_num1(uint8_t num)
{
    uint8_t result = 0;
    uint8_t pos = 0;
    
    while (num > 0)
    {
        result = result << 1;
        result = result | (num & 0x1);
        num = num >> 1;
        pos++;
    }
    result = result << (8 - pos);
    return result;
}

uint8_t rev_num2(uint8_t num)
{
    uint8_t result = 0;
    
    num = ((num & 0xAA) >> 1) | ((num & 0x55) << 1);
    num = ((num & 0xCC) >> 2) | ((num & 0x33) << 2);
    num = ((num & 0xF0) >> 4) | ((num & 0x0F) << 4);
    
    result = num;
    return result;
}

void test_driver_rev_num(void)
{
    srand((unsigned int) time(NULL));
    uint8_t num = rand() % 255;
    uint8_t result1 = rev_num1(num);
    uint8_t result2 = rev_num2(num);
    
    printf("Orig num: 0x%x Result1:  0x%x Result2: 0x%x\n",  num, result1, result2);

}
