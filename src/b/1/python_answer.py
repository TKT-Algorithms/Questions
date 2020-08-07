a,b = input().split(" ")
c = input().split(" ")
c.append(b)
c.append(0)
for i in range(len(c)):
	c[i] = int(c[i])
c.sort(reverse=True)
d = 0
for i in range(len(c)-1):
	if i == 0:
		if (c[i] - c[i+1])*2 > d:
			d = (c[i] - c[i+1])*2
	elif i == len(c)-2:
		if (c[i] - c[i+1])*2 > d:
			d = (c[i] - c[i+1])*2
	else:
		if (c[i] - c[i+1]) > d:
			d = (c[i] - c[i+1])
print(d/2)
