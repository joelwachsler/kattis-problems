n, m = 3, 15
x = [6 , -3, 1]
p = []
total = 0

for y in x:
	p.append(abs(y))

while len(p) > 0:
	m -= min(p)
	total += m
	print(p)
	print(m)
	p.remove(min(p))
print(total)