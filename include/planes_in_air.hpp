//
//  planes_in_air.hpp
//  wm
//
//  Created by Surya Sahukar on 12/17/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#ifndef planes_in_air_hpp
#define planes_in_air_hpp

#include <stdio.h>
#include <map>
#include <time.h>  

struct terminal_info {
    uint16_t ts_takeoff;
    uint16_t ts_landing;
};

void init(void);
void parse_data(void);
int planes_in_air(uint16_t);
void test_driver_planes(void);



#endif /* planes_in_air_hpp */
