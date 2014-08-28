/**
 * This is an example of using the HMC5883L Arduino library 
 * to control the HMC5883L magnetic sensor.
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

HMC5883L hmc;


void setup()
{
  // Initialize Serial and I2C communications
  Serial.begin(9600);
  hmc.begin();
}


void loop()
{
  int x,y,z;

  // Read magnetic data from HMC5883L sensor
  hmc.read(&x, &y, &z);
  
  // Print out values of each axis
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);
  
  // Delay
  delay(250);
}

