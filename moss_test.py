import matplotlib.pyplot as plt
import numpy as np

import mosspy

userid = 831327210

m = mosspy.Moss(userid, "c")


# Submission Files
m.addFilesByWildcard("data/*.c")

url = m.send()  # Submission Report URL

print("Report Url: " + url)
