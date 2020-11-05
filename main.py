import pickle

from cbEval import get_vector
from functions import get_functions

file_funcs = {}
func_vectors = {}

filename = "test.c"
func = get_functions(filename)
for f in func:
    func_vectors[f] = get_vector(func[f], is_file=False)

file_funcs[filename] = func_vectors
print(file_funcs)

with open("func_vec_map.pkl", "wb") as f:
    pickle.dump(file_funcs, f)
