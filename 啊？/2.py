shuaizi1 = [1, 2, 3, 4, 5, 6]
shuaizi2 = [1, 2, 3, 4, 5, 6]
shuaizi3 = [1, 2, 3, 4, 5, 6]
dict1 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
gailv = []
cishu = 0
he = 0
for a in range(0, 6):
    for b in range(0, 6):
        for c in range(0, 6):
            he = shuaizi1[a] + shuaizi1[b] + shuaizi1[c]
            print("可能的结果：", he)
            dict1[he] += 1
            cishu += 1

print(dict1)
ex = 0        
print("各项的总次数：", cishu)
for i in range(3, len(dict1) - 1):
    ex += (dict1[i] / cishu) * i


print("E(x)为：", ex)

