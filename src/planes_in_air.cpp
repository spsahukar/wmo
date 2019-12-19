//
//  planes_in_air.cpp
//  wm
//
//  Created by Surya Sahukar on 12/17/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#include "planes_in_air.hpp"

using namespace std;

struct terminal_info *pl_in_air;
int len = 0;
std::map<uint16_t, uint16_t> toff;
std::map<uint16_t, uint16_t> land;
std::map<uint16_t, uint16_t> toff_integral;
std::map<uint16_t, uint16_t> land_integral;


#define DAY_MINS 1440

void init(void)
{
    for (int i = 0; i < DAY_MINS; i++)
    {
        toff[i] = 0;
        land[i] = 0;
        toff_integral[i] = 0;
        land_integral[i] = 0;
    }
}


void parse_data(void)
{
    for (int i = 0; i < len; i++)
    {
        toff[pl_in_air[i].ts_takeoff] = 1;
        land[pl_in_air[i].ts_landing] = 1;
    }
    
    uint32_t temp_to = 0, temp_land = 0;
    
        for (int i = 0; i < DAY_MINS; i++)
        {
            temp_to += toff[i];
            toff_integral[i] = temp_to;
            temp_land += land[i];
            land_integral[i] = temp_land;
            
        }
}

int planes_in_air(uint16_t ts)
{
    return (toff_integral[ts] - land_integral[ts]);
}


void test_driver_planes(void)
{
    //Create Random Dataset
    srand((unsigned int) time(NULL));
    
    uint16_t to_ts_random = 0, land_ts_random = 0;
    uint16_t len_random = rand() % 10 ;
    
    pl_in_air = (struct terminal_info *)malloc(sizeof(len_random));
   
	int i = 0;

	printf("<------------------------------------BEGIN: Timstamp creation Random number debug---------------------------->\n");
	while(i < len_random) 
    {
        to_ts_random = rand() % DAY_MINS;
        land_ts_random = to_ts_random + (rand() % (DAY_MINS - to_ts_random));
		printf("to_ts_random = %u land_ts_random = %u\n", to_ts_random, land_ts_random);
	
		if ((to_ts_random < land_ts_random) && (to_ts_random && land_ts_random))
		{	
        	pl_in_air[i].ts_takeoff = to_ts_random;
        	pl_in_air[i].ts_landing = land_ts_random;
        	len++;
			i++;
		}

    }
    
	printf("<------------------------------------END: Timstamp creation Random number debug---------------------------->\n");
    //Print populated data
    printf("Plane #\t\t\t\t Takeoff_Timestamp\t\t\t\t Landing_Timestamp\n");
    for (int i = 0; i < len_random; i++)
     {
         printf("%d\t\t\t\t %u\t\t\t\t %u\n", i, pl_in_air[i].ts_takeoff, pl_in_air[i].ts_landing);
     }
     
    //Parse Data
    parse_data();
    
    //Get planes in air at random minute of day
    uint16_t ts_random = rand() % DAY_MINS;
    uint16_t in_air = 0;
    in_air = planes_in_air(ts_random);
    
    printf("At Minute of Day: %u, Number of planes in air: %u\n", ts_random, in_air);
    
    
}
