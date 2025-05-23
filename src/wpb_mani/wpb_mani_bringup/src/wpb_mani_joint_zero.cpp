/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2017-2020, Waterplus http://www.6-robot.com
*  All rights reserved.
* 
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
* 
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the WaterPlus nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  FOOTPRINTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/
/*!******************************************************************
 @author    Wangkang
 ********************************************************************/

#include <ros/ros.h>
#include "driver/WPB_Mani_driver.h"
#include <math.h>

static CWPB_Mani_driver m_wpb_mani;
static int arManiPos[5];
static int arManiSpeed[5];

int main(int argc, char** argv)
{
    ros::init(argc,argv,"wpb_mani_joint_zero");

    ros::NodeHandle n_param("~");
    std::string strSerialPort;
    n_param.param<std::string>("serial_port", strSerialPort, "/dev/ftdi");
    m_wpb_mani.Open(strSerialPort.c_str(),115200);

    for(int i=0;i<5;i++)
    {
        arManiPos[i] = 0;
        arManiSpeed[i] = 2000;
    }
    arManiPos[4] = -4000;

    int nCount = 0;
    ros::NodeHandle n;
    ros::Rate r(1);
    while(n.ok())
    {
        m_wpb_mani.SetManiSpd(arManiSpeed[0] , arManiSpeed[1] , arManiSpeed[2] , arManiSpeed[3] , arManiSpeed[4] );
        m_wpb_mani.SendManiPos( arManiPos[0] , arManiPos[1] , arManiPos[2] , arManiPos[3] , arManiPos[4] );

        ROS_INFO("[wpb_mani_joint_zero] nCount = %d",nCount);
        nCount ++;

        ros::spinOnce();
        r.sleep();
    }
}
