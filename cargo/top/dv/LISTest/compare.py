import sys
file1 = open(sys.argv[1], 'r')
file2 = open(sys.argv[2], 'r')

data1 = file1.read()
data2 = file2.read()

if (data1 == data2):
    print("Test passed!")
else:
    print("Test failed!")

file1.close()
file2.close()