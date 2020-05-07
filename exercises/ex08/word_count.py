import sys

if not len(sys.argv) > 1:
    exit()

word_count = {}

try:
    with open(sys.argv[1]) as f:
        for line in f:
            for word in line.split():
                if not word in word_count:
                    word_count[word] = 1
                else:
                    word_count[word] += 1

    print(word_count)
except expression as identifier:
    print("Unexpected error:", sys.exc_info()[0])
    raise