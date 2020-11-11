import glob
import pickle

from cbEval import get_vector
from functions import get_functions

file_funcs = {}
reverse_map = {}
files = glob.glob("code_pairs_train/*.c")
tot = len(files)

for idx, filename in enumerate(files):
    func_vectors = {}
    print(f"{idx+1}/{tot}")
    try:
        func = get_functions(filename)
        for f in func:
            vec = get_vector(func[f], is_file=False)
            func_vectors[f] = vec
            try:
                reverse_map[tuple(vec)] = (filename, f)
            except:
                reverse_map[tuple(vec)] = [(filename, f)]

        file_funcs[filename] = func_vectors
    except:
        pass

print(file_funcs)
print(reverse_map)

with open("func_vec_map.pkl", "wb") as f:
    pickle.dump(file_funcs, f)
with open("vec_func_map.pkl", "wb") as f:
    pickle.dump(reverse_map, f)
