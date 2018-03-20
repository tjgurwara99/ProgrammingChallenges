n = int(input())
xs = map(int, input().strip().split(" "))

res = []
currentNum = -1

for i in xs:
    if i == currentNum:
        currentNum += 1
        while len(res) > 0 and res[-1] == currentNum:
            currentNum += 1
            res.pop()
    else:
        if currentNum > 0:
            res.append(currentNum)
        currentNum = i

res.append(currentNum)

print(len(res))
print(' '.join(map(str, res)))
