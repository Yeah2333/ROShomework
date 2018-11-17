#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy

import sys, select, tty, termios
from std_msgs.msg import String

def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key
 

if __name__ == '__main__':

        key_pub = rospy.Publisher('voiceWakeup', String, queue_size=1)
        rospy.init_node("keyboard_driver")
        rate = rospy.Rate(100)
        old_attr = termios.tcgetattr(sys.stdin)
        tty.setcbreak(sys.stdin.fileno())
        print "Publishing keystrokes. Press Ctrl-C to exit..."
        while not rospy.is_shutdown():
                if select.select([sys.stdin], [], [], 0)[0] == [sys.stdin]:
                        key_pub.publish(sys.stdin.read(1))
                rate.sleep()

        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_attr)>
