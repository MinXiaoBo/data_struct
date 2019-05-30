/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2006-2013. All rights reserved.
 ******************************************************************************************/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/******************************************************************************************
 * ���ԡ���ʾ��С����
 ******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "comparator.h"

#include "checkorder_elem.h"
#include "checkorder_list.h"
#include "checkorder_vector.h"

#include "double_elem.h"
#include "increase_elem.h"
#include "hailstone_elem.h"
#include "increase_list.h"
#include "increase_vector.h"

#include "crc_elem.h"
#include "crc_list.h"
#include "crc_vector.h"

#include "rand.h" //�����

#if defined(DSA_DEBUG) //���뿪�أ����Ƶ������
#define DSA(x)  { x } //���
#else
#define DSA(x) //�����
#endif