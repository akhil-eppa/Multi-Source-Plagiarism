import pickle

import matplotlib.pyplot as plt
import numpy as np
from numpy import unique
from sklearn.cluster import DBSCAN

a = pickle.load(open("func_vec_map.pkl", "rb"))
b = pickle.load(open("vec_func_map.pkl", "rb"))

X = []

for file in a:
    for func in a[file]:
        X.append(a[file][func])

X = np.array(X)

# model = GaussianMixture(n_components=4)
# model = MeanShift()
# model = AgglomerativeClustering(n_clusters=i)
# model = KMeans(n_clusters=5)
model = DBSCAN(eps=0.7, min_samples=4)
yhat = model.fit_predict(X)
clusters = unique(yhat)
function_clusters = []

for i in clusters:
    all_funcs = sum((b[tuple(func)] for func in X[yhat == i]), [])
    function_clusters.append(all_funcs)
    print(i, len(all_funcs))

print("The following functions are found to be similar -")
for idx, i in enumerate(function_clusters[1:], 1):
    print(f"Cluster {idx}")
    for j in i:
        print(f"\t{j[0]}\t:\t{j[1]}")

with open("clusters.pkl", "wb") as cluster:
    pickle.dump(function_clusters, cluster)

# for cluster in clusters:
#     # get row indexes for samples with this cluster
#     row_ix = np.where(yhat == cluster)
#     print(len(row_ix[0]))
#     # create scatter of these samples
#     pyplot.scatter(X[row_ix, 0], X[row_ix, 1])
# show the plot
# plt.scatter(X[:, 0], X[:, 1], c=yhat, cmap="Paired")
# plt.show()

# tsne = TSNE()
# X_2d = tsne.fit_transform(X)

# plt.scatter(X_2d[:,0],X_2d[:,1])
# plt.show()
