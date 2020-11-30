import glob
import pickle

from cbEval import get_vector
from functions import get_functions

file_funcs = {}
reverse_map = {}
file_lines = {}
files = []

for i in range(1, 9):
    files += glob.glob(f"data/{i}*.c")

tot = len(files)
with open("missing_log.txt", "w") as log, open("used_log.txt", "w") as used:
    for idx, filename in enumerate(files):
        func_vectors = {}
        func_lines = {}
        print(f"{idx+1}/{tot}")
        try:
            func = get_functions(filename)
            for f in func:
                vec = get_vector(func[f], is_file=False)
                func_vectors[f] = vec
                func_lines[f]=func[f].count('\n')
                try:
                    reverse_map[tuple(vec)].append((filename, f))
                except:
                    reverse_map[tuple(vec)] = [(filename, f)]

            file_funcs[filename] = func_vectors
            file_lines[filename] = func_lines
            used.write(filename + "\n")
        except:
            log.write(filename + "\n")

with open("func_vec_map.pkl", "wb") as f:
    pickle.dump(file_funcs, f)
with open("vec_func_map.pkl", "wb") as f:
    pickle.dump(reverse_map, f)
with open("func_line_map.pkl","wb") as f:
    pickle.dump(file_lines,f)
