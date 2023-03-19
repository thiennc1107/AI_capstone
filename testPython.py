import speedController as sp

controller = sp.SpeedController()
controller.set_speed(0, 0)

while True:
    data = input("input speed: ")
    speedArr = data.split(' ')
    speed1 = int(speedArr[0])
    speed2 = int(speedArr[1])
    controller.set_speed(speed1, speed2)