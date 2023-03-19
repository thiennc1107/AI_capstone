import serial

class SpeedController():
    def __init__(self) -> None:
      self.serial = ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
      self.serial.reset_input_buffer()
      self.serial.flush()
      self.speed_left = 0
      self.speed_right = 0
    def set_speed(self, left: int, right: int):
       self.speed_left = left
       self.speed_right = right
       speedArr = [str(left), str(right)]
       speedStr = " ".join(speedArr)
       self.serial.write(bytes(speedStr,'utf-8'))