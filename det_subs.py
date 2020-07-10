#!/usr/bin/env python
import cv2
import numpy as np
import rospy
from std_msgs.msg import String

def nothing(x):
    pass

cv2.namedWindow("Trackbars")
cv2.createTrackbar("L-H", "Trackbars", 0, 255, nothing)
cv2.createTrackbar("L-S", "Trackbars", 0, 255, nothing)
cv2.createTrackbar("L-V", "Trackbars", 0, 255, nothing)
cv2.createTrackbar("U-H", "Trackbars", 255, 255, nothing)
cv2.createTrackbar("U-S", "Trackbars", 255, 255, nothing)
cv2.createTrackbar("U-V", "Trackbars", 255, 255, nothing)

pub = rospy.Publisher('chatter', String, queue_size=10)
rospy.init_node('talker', anonymous=True)
rate = rospy.Rate(10) # 10hz

while not rospy.is_shutdown() :
    img = cv2.imread('objek-1.png')
    data = img.shape
    width = data[1]
    height = data[0]
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret,thresh1 = cv2.threshold(gray,127,255,0)

    _, contours ,_ = cv2.findContours(thresh1, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cv2.drawContours(img, contours, -1, (0,255,0), 3)
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    l_h = cv2.getTrackbarPos("L-H", "Trackbars")
    l_s = cv2.getTrackbarPos("L-S", "Trackbars")
    l_v = cv2.getTrackbarPos("L-V", "Trackbars")
    u_h = cv2.getTrackbarPos("U-H", "Trackbars")
    u_s = cv2.getTrackbarPos("U-S", "Trackbars")
    u_v = cv2.getTrackbarPos("U-V", "Trackbars")

    lower_color = np.array([l_h, l_s, l_v])
    upper_color = np.array([u_h, u_s, u_v])

    mask = cv2.inRange(hsv, lower_color, upper_color)
    res = cv2.bitwise_and(img,img, mask= mask)
    _ ,contours ,_ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # for cnt in contours:    
    #     cv2.drawContours(thresh1, [cnt], 0, (0,200,200), 5)
    for cnt in contours:    
        #cv2.drawContours(res, [cnt], 0, (0,200,200), 5)
        
    #     x,y,w,h = cv2.boundingRect(cnt)
        # ret,thresh2 = cv2.threshold(thresh1,127,255,cv2.THRESH_TOZERO)
        # if cv2.contourArea(cnt) < 1000:
        #   continue      

    # print("jarak : ",x," ",y," ",width-w," ",height-h)
    # if(x == width-w and y == height-h):
    #     print("sudah center")
    
    #cv2.imshow('frame',img)
    #cv2.imshow('frame1',thresh1)
    # cv2.imshow('frame2',thresh2)
        x,y,w,h = cv2.boundingRect(cnt)
        ret,thresh2 = cv2.threshold(res,127,255,cv2.THRESH_BINARY_INV)
        
        if cv2.contourArea(cnt) > 2000:
            cv2.rectangle(res,(x,y),(x+w,y+h),(0,255,0),5)

    #print("jarak : ",x," ",y," ",width-w," ",height-h)
    data = str(x) + " " + str(y) + " " + str(width-w) + " " + str(height-h)
    #data = [x,y,width-w,height-h]
    #print(a)
    
    rospy.loginfo(data)
    pub.publish(data)
    rate.sleep()        

    if(x == width-w and y == height-h):
        print("sudah center")
    else:
        print("belum")
    
    #cv2.imshow('frame',img)
    cv2.imshow('frame1',res)
    
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break
