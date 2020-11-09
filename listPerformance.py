# coding=utf-8
# Python第一次作业
# Author: Hongzhuo CHEN
# Modified on Oct 21, 2020
# 内容：比较列表不同添加、删除元素方法的时间
import time

times = 1000000  # 重复操作的次数
times1 = 10000  # 有些方法非常慢，所以减少执行次数
size = 2000000  # 列表长度
# +运算的时间
a = list(range(1, size + 1))
start = time.time()
for i in range(1, times + 1):
    a += [i]

end = time.time()
print('Plus: ' + '%.3g' % ((end - start) / times))
del a
# append方法的时间
b = list(range(1, size + 1))
start = time.time()
for i in range(1, times + 1):
    b.append(i)

end = time.time()
print('Append: ' + '%.3g' % ((end - start) / times))
del b
# extend方法的时间
c = list(range(1, size + 1))
start = time.time()
for i in range(1, times + 1):
    c.extend([i])

end = time.time()
print('Extend: ' + '%.3g' % ((end - start) / times))
del c
# TopInsert方法的时间
d = list(range(1, size + 1))
start = time.time()
for i in range(1, times1 + 1):
    d.insert(0, i)

end = time.time()
print('TopInsert: ' + '%.3g' % ((end - start) / times1))
del d
# BottomInsert方法的时间
e = list(range(1, size + 1))
start = time.time()
for i in range(1, times1 + 1):
    e.insert(-1, i)

end = time.time()
print('BottomInsert: ' + '%.3g' % ((end - start) / times1))
del e
# *方法的时间
f = list(range(1, size + 1))
start = time.time()
f = f * 2
end = time.time()
print('*: ' + '%.3g' % ((end - start) / size))
del f
# TopDel方法时间
g = list(range(1, size + 1))
start = time.time()
for i in range(1, times1 + 1):
    del g[0]

end = time.time()
print('TopDel: ' + '%.3g' % ((end - start) / times1))
del g
# BottomDel方法时间
h = list(range(1, size + 1))
start = time.time()
for i in range(1, times + 1):
    del h[-1]

end = time.time()
print('BottomDel: ' + '%.3g' % ((end - start) / times))
del h
# TopPop方法的时间
j = list(range(1, size + 1))
start = time.time()
for i in range(1, times1 + 1):
    j.pop(0)

end = time.time()
print('TopPop: ' + '%.3g' % ((end - start) / times1))
del j
# BottomPop方法的时间
k = list(range(1, size + 1))
start = time.time()
for i in range(1, times + 1):
    k.pop(-1)

end = time.time()
print('BottomPop: ' + '%.3g' % ((end - start) / times))
del k
# TopRemove方法的时间
m = list(range(1, size + 1))
start = time.time()
for i in range(1, times1 + 1):
    m.remove(i)

end = time.time()
print('TopRemove: ' + '%.3g' % ((end - start) / times1))
del m
# BottomDelete方法的时间
n = list(range(1, times1 + 1))
start = time.time()
for i in range(1, times1 + 1):
    n.remove(n[-1])

end = time.time()
print('BottomRemove: ' + '%.3g' % ((end - start) / times1))
del n
