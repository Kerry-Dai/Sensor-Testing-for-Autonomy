import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Import data using Pandas (install with: pip install pandas)
data = pd.read_csv("data.csv")
#print(data)

# Retrieve data columns
D = data.to_numpy()
USdist = D[:,0]

#create time array - US takes readings every 0.1s
lengthDist = len(USdist)
time = np.arange(0.1,lengthDist*0.1,0.1)

#plot
plt.plot(time,USdist)
plt.xlabel("time (s)")
plt.ylabel("Distance (m)")
plt.show()