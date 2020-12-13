import serial

def toDegree(degree):
    degrees = int(degree/100)
    gps = degrees + ((degree - (degrees * 100)) / 60)
    return gps

def parseGPS(str):
    if str.find('GGA') > 0:
        print(str)
	print(str[17:27],str[28:29],str[30:41],str[42:43])
        lat = float(str[17:27])
        lon = float(str[30:41])
        latDir = str[28:29]
        lonDir = str[42:43]
        print("%.6f"%toDegree(lat),latDir,"%.6f"%toDegree(lon),lonDir)


serialPort = serial.Serial("/dev/serial0", 38400, timeout = 0.5)

while True:
    str = serialPort.readline()
    parseGPS(str)
