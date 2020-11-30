import pickle

from functions import get_functions, get_parsed_lines

func_clusters = pickle.load(open("clusters.pkl", "rb"))


def printSummary(file: str):
    functions = get_functions(file)
    plag_lines = 0
    plag_groups = {}
    for f in functions:
        chk = (file, f)
        for j in func_clusters[1:]:
            if chk in j:
                plag_lines += len(list(filter(lambda x: x, functions[f].split("\n"))))
                plag_groups[f] = j
                break

    plag_fraction = plag_lines / get_parsed_lines(file)
    print(f"{file} is estimated to be {plag_fraction*100:.2f}% plagiarised")
    print("The following possible sources for plagiarism were detected -")
    for func, sources in plag_groups.items():
        print(f"{func}:")
        for source in sources:
            if source[0] != file:
                print(f"\t{source[0]}\t:{source[1]}")
