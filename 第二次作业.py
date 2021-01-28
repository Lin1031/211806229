name_set = set()
with open('./test.txt') as f:
    for i in f:
        if int(i.split()[2]) >= 100:
            name_set.add(i.split()[0])
print(len(name_set))
print("\n".join(name_set))
