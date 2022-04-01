from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg 

from pyfirmata import Arduino, util

import time

port = 'COM3'
board = Arduino(port)

it =util.Iterator(board)
it.start()


app=QtGui.QApplication([])
win = pg.GraphicsWindow(title='Potenciómetro')
p=win.addPlot(title= 'Gráfica Del Potenciometro En Tiempo Real')
curva=p.plot(pen='y')

p.setRange(yRange=[0,100])
dataX=[]
dataY=[]
lastY=0

analogo=board.get_pin('a:0:i')


def Update():
    global curva, dataX, dataY, lastY, nuevoDato
    
    dato=analogo.read()
    if dato is not None:
        nuevoDato=dato*100
        print(nuevoDato)
        time.sleep(1)
        if nuevoDato ==100:
            for x in range(1):
                board.digital[13].write (1)
                time.sleep(0.5)
                board.digital[13].write (0)
                time.sleep(0.5)
    else:
        nuevoDato=0
        
        
    dataX.append(nuevoDato)
    dataY.append(lastY)
    lastY+=1
    
    if len(dataX)>200:
        dataX=dataX[:-1]
        dataY=dataY[:-1]
        

        
    curva.setData(dataY,dataX)
    QtGui.QApplication.processEvents()
    
while True:
    try:
        Update()
        
    except KeyboardInterrupt:
        pg.QtGui.QApplication.exec_()
        board.exit()