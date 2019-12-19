//
//  rev_ll.hpp
//  wm
//
//  Created by Surya Sahukar on 12/18/19.
//  Copyright © 2019 Surya Sahukar. All rights reserved.
//

#ifndef rev_ll_hpp
#define rev_ll_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

struct node {
    int data;
    struct node *next;
};

struct node*  rev_list(struct node *);
void test_driver_rev_list(void);


#endif /* rev_ll_hpp */
