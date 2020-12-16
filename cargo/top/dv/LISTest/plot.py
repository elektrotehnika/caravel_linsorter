import sys
import matplotlib.pyplot as plt

file1 = open(sys.argv[1],"r")  
data = file1.read()
file1.close()

dataInt = []
for i in range(len(data)//5):
    dataInt.append(int(data[i*5:i*5+4],16))

plt.plot(dataInt)
plt.ylabel('N')
plt.show()