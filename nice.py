import psutil
import os
p=psutil.process(os.getpid())
print(p.nice)
p.nice=10
print(p.nice)
