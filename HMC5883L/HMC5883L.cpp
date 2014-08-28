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

#include "HMC5883L.h"


/**
 * @brief
 *    Initialize the HMC5883L sensor.
 */
void HMC5883L::begin()
{
  // Open communication channel with HMC5883L
  Wire.beginTransmission(_HMC5883L_ADDRESS);

  // Select register as mode register
  Wire.write(_HMC5883L_REG_MODE);

  // Write value as continuous measurement mode
  Wire.write(_HMC5883L_MODE_CONTINUOUS);

  // Close communication channel
  Wire.endTransmission();
}


/**
 * @param m_x The megnetic strength value of x-axis.
 * @param m_y The megnetic strength value of y-axis.
 * @param m_z The megnetic strength value of z-axis.
 *
 * @brief
 *    Read the megnetic strength values.
 */
void HMC5883L::read(int* m_x, int* m_y, int* m_z)
{
  // Inform the HMC5883L sensor to read data
  Wire.beginTransmission(_HMC5883L_ADDRESS);
  Wire.write(_HMC5883L_REG_XMSB);
  Wire.endTransmission();

  // Read data from the sensor
  Wire.requestFrom(_HMC5883L_ADDRESS, 6);
  if (Wire.available() >= 6)
  {
    (*m_x) =  Wire.read() << 8; // X msb
    (*m_x) |= Wire.read();      // X lsb
    (*m_z) =  Wire.read() << 8; // Z msb
    (*m_z) |= Wire.read();      // Z lsb
    (*m_y) =  Wire.read() << 8; // Y msb
    (*m_y) |= Wire.read();      // Y lsb
  }
}


