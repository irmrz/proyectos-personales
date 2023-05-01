from random import seed

#(
seed = 0b1001

for i in range(20):
    print("{:04b}".format(seed))
    newbit = (seed ^ (seed >> 1) ^ (seed >> 2) ^ (seed >> 7)) & 1
    seed = (seed >> 1) | (newbit << 3)