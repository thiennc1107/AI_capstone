import serial
import random
import time
import speedController as sp

speedCtrl = sp.SpeedController()
speedCtrl.set_speed(0, 0)
speedCtrl.set_speed(10,10)
time.sleep(3)
speedCtrl.set_speed(20, 10)
time.sleep(1)
speedCtrl.set_speed(10,10)
time.sleep(3)
speedCtrl.set_speed(0, 0)


