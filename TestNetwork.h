#ifndef TEST_NETWORK_H
#define TEST_NETWORK_H

#include <AM.h>
#include "TestNetworkC.h"

typedef nx_struct TestNetworkMsg {
  nx_uint8_t source; //-1: tossim_simulator otherwise: node_id

  // topology information sent during initialization
  nx_am_addr_t parents[MAXPARENTS];
  nx_uint8_t totalParents;
  
  nx_am_addr_t children[MAXCHILDREN];
  nx_uint8_t totalChildren;
  
  nx_am_addr_t siblings[MAXSIBLINGS];
  nx_uint8_t totalSiblings;
  nx_uint8_t i_am_primary;
  
  nx_uint8_t message_type; //1:INITIALIZATION  2: READINGSENDTIME 3: DATA
  
  
  //nx_uint16_t data1;
  //nx_float data1;
  nx_uint8_t self_data1;
  nx_uint8_t self_data2;
  
  nx_uint8_t ONE merged_data[TOTALNODES];
  nx_uint8_t ONE merged_index[TOTALNODES];
  
  nx_uint8_t childrenReceive[MAXCHILDREN];
  nx_uint8_t childrenHandle[MAXCHILDREN];
  nx_uint8_t curr_num;

  //nx_uint8_t my_children_prob_bit[MAXCHILDREN];

  nx_uint8_t avg_link_prob;
  
  //nx_uint8_t has_dead_node;

  //nx_uint8_t node_blacklist[MAXCHILDREN];
  
  nx_uint8_t hopcount;
  nx_uint16_t sendCount;
  nx_uint16_t sendSuccessCount;
} TestNetworkMsg;

#endif
