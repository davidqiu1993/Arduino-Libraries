/**
 * This is an Arduino library to control the HMC5883L 
 * magnetic sensor.
 *
 * Author: David Qiu
 * Email: david@davidqiu.com
 * Email: dicong.qiu@intel.com
 * Website: http://www.davidqiu.com
 *
 * Copyright (C) 2014, David Qiu. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License.
 *
 * You may obtain a copy of the License at 
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
 * See the License for the specific language governing permissions and 
 * limitations under the License.
 */

#ifndef _HMC5883L_H_
#define _HMC5883L_H_

#include <Wire.h>    // I2C Arduino Library

#define _HMC5883L_ADDRESS 0x1E          // I2C 7bit address of HMC5883L

#define _HMC5883L_REG_MODE 0x02         // Address of mode register
#define _HMC5883L_REG_XMSB 0x03         // Address of X MSB register

#define _HMC5883L_MODE_CONTINUOUS 0x00  // Identifier of continuous measurement mode

/**
 * The HMC5883L magnetic sensor class.
 */
class HMC5883L
{
public:
  void begin();
  void read(int* m_x, int* m_y, int* m_z);
};

#endif // _HMC5883L_H_

