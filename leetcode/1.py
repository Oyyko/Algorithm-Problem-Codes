nums = []
for i in range(1, 100000):
    p1 = int(str(i)+str(i)[::-1])**2
    p2 = int(str(i)[:-1]+str(i)[::-1])**2
    if(str(p1) == str(p1)[::-1]):
        nums.append(p1)
    if(str(p2) == str(p2)[::-1]):
        nums.append(p2)

print(nums)

ans = []

for i in nums:
    if((len(str(i))) % 2 == 0):
        ans.append(i)

print(ans)
