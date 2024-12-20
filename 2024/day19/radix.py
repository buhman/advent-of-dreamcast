from pprint import pprint

with open('input.txt', 'r') as f:
    s = f.read()

patterns = s.strip().split('\n\n')[0].split(", ")

def radix_add(d, s):
    c = s[0]
    tail = s[1:]

    if c not in d:
        d[c] = {}

    if not tail:
        pass
        #d[c].append(None)
    else:
        radix_add(d[c], tail)

tree = dict()

#print("max", max(map(len, patterns)))

for pattern in patterns:
    radix_add(tree, pattern)

def print_tree(d, indent, s):
    indent2 = indent + "  "
    indent3 = indent2 + "  "

    if d is None:
        return

    print(indent + "switch (s[ix++]) {")
    for key, value in d.items():
        print(indent + f"case '{key}':")
        if s + key in patterns:
            print(indent2 + "matches |= (1 << (ix - 1));")
        print(indent2 + "if (ix >= length) {")
        print(indent3 + "return matches;")
        print(indent2 + "}")
        print_tree(value, indent2, s + key)
        print(indent2 + "break;")

    print(indent + "default:")
    print(indent2 + "break;")
    print(indent + "}")

#print(patterns)
print("static uint32_t count_substring_matches(const char * s, int length)")
print("{")
print("  int ix = 0;")
print("  uint32_t matches = 0;")
print("  if (ix >= length)")
print("    return matches;")
print_tree(tree, "  ", "")
print("  return matches;")
print("}")
