# Referencias a a las librerias
 from bmp_280 import BMP280
 from time import sleep
 import RPi.GPIO as GPIO
 import time
 import mysql.connector
 #configuracion base de datos
 mydb=mysql.connector.connect(
 host="34.27.235.22"
 user="root"
 password="hola"
 database="iot_proyect"
 )
 ## SENSORPRESION
 bmp =BMP280(port=1, mode=BMP280.FORCED_MODE,
 oversampling_p=BMP280.OVERSAMPLING_P_x16,
 oversampling_t=BMP280.OVERSAMPLING_T_x1,
 filter=BMP280.IIR_FILTER_OFF,
 standby=BMP280.T_STANDBY_1000)
 # MOTOR
 GPIO.setmode(GPIO.BOARD)
 Motor1 = 16 #Entrada
 Motor2 = 18 #Entrada
Motor3 = 22 #Habilitar
 Motor4 = 17 #Entrada
 Motor5 = 19 #Entrada
 Motor6 = 23 #Habilitar
 #Establecemos el set up del motor como salida
 GPIO.setup(Motor1, GPIO.OUT)
 GPIO.setup(Motor2, GPIO.OUT)
 GPIO.setup(Motor3, GPIO.OUT)
 GPIO.setup(Motor4, GPIO.OUT)
 GPIO.setup(Motor5, GPIO.OUT)
 GPIO.setup(Motor6, GPIO.OUT)
 # CONFIGURACION Y SENSOR DEDISTANCIA
 GPIO_TRIGGER = 23
 GPIO_ECHO = 24
 GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
 GPIO.setup(GPIO_ECHO, GPIO.IN)
 GPIO.output(GPIO_TRIGGER, False)
 # Configuración para guardar datos
 sFileStamp = time.strftime('%Y%m%d%H')
 sFileName = 'out/' + 'out' + sFileStamp + '.txt'
 f = open(sFileName, 'a')
 f.write('TimeStamp,Value' + '\n')
 print("Inicia la toma de datos")
 print("Inicia la toma de datos")
 try:
 while True:
 print("Acerque el objeto para medir la distancia")
 # Medir distancia
GPIO.output(GPIO_TRIGGER, True)
 time.sleep(0.00001)
 GPIO.output(GPIO_TRIGGER, False)
 start = time.time()
 while GPIO.input(GPIO_ECHO) == 0:
 start = time.time()
 while GPIO.input(GPIO_ECHO) == 1:
 stop = time.time()
 elapsed = stop- start
 distance = (elapsed * 34300) / 2
 # Leer presión
 pressure = bmp.read_pressure()
 # Leer temperatura
 temp=bmp.read_temperature()
 TimeStamp = time.strftime('%Y%m%d%H%M%S')
 f.write(sTimeStamp + ',' + str(distance)'\n')
 #Imprimir valores
 print("Presión(hPa): " + str(pressure))
 print("Temperatura (°C): " + str(temp))
 print(" Distancia: " + str(distance))
 #Abrir base de datos mysql e insercion
 cursor=mydb.cursor()
 sql="INSERT INTO temperatura(temperatura,fecha) VALUES
 (%s,CURRENT_TIMESTAMP)"
 val=(temp,)
 cursor.execute(sql,val)
 mydb.commit()
 print("Dato de temperatura insertado")
sql1="INSERT INTO presion(presion,fecha) VALUES
 (%s,CURRENT_TIMESTAMP)"
 val1=(pressure,)
 cursor.execute(sql1,val1)
 mydb.commit()
 print("Dato de presion insertado")
 sql2="INSERT INTO distancia(distancia,fecha)
 VALUES(%s,CURRENT_TIMESTAMP)"
 val2(distance,)
 cursor.execute(sql2,val2)
 mydb.commit()
 print("Dato de distancia insertado")
 #ambos motores se accionan
 GPIO.output(Motor1, GPIO.HIGH)
 GPIO.output(Motor2, GPIO.LOW)
 GPIO.output(Motor3, GPIO.HIGH)
 GPIO.output(Motor4, GPIO.HIGH)
 GPIO.output(Motor5, GPIO.LOW)
 GPIO.output(Motor6, GPIO.HIGH)
 # Avanzar hasta cierta distancia
 if distance < 10:
 print("Obstáculo detectado. Deteniendo motores y girando.")
 # Detener motores
 GPIO.output(Motor1, GPIO.LOW)
 GPIO.output(Motor2, GPIO.LOW)
 GPIO.output(Motor3, GPIO.LOW)
 GPIO.output(Motor4, GPIO.LOW)
 GPIO.output(Motor5, GPIO.LOW)
GPIO.output(Motor6, GPIO.LOW)
 # Girar
 GPIO.output(Motor1, GPIO.HIGH)
 GPIO.output(Motor2, GPIO.LOW)
 GPIO.output(Motor3, GPIO.HIGH)
 GPIO.output(Motor4, GPIO.LOW)
 GPIO.output(Motor5, GPIO.LOW)
 GPIO.output(Motor6, GPIO.LOW)
 sleep(3)
 except KeyboardInterrupt:
 print('\n' + 'Termina la captura de datos.' + '\n')
 f.close()
 GPIO.cleanup()