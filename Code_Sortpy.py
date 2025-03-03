import numpy as np
import time

with open("test_1.inp", 'r') as f1:
    arr = [float(line.strip()) for line in f1]

start = time.time()

a = np.array(arr)
sorted_a = np.sort(a)

end = time.time()

with open("test_1.out", 'w') as f2:
    f2.write("Runtime: " + str(end-start) + "\n")
    for x in sorted_a:
        f2.write(str(x) + '\n')