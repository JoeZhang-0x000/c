import numpy as np
import  matplotlib.pyplot as plt

l = 5.5
p = 450
x = np.linspace(0,5.5,5501)

M = -p*l/8+p*x/2-p*(x-0.5*l)*(x>0.5*l)
theta = -p*l*x/8+p*x*x/4-p*(x-0.5*l)*(x-0.5*l)/2*(x>0.5*l)
w =-p*l*x*x/16+p*x*x*x/12-p*(x-0.5*l)*(x-0.5*l)*(x-0.5*l)/6*(x>0.5*l)
#旋转
#theta = theta-w[l]/l
#w =w - x*w[l]/l

#画图部分
plt.subplot(2,1,1)
plt.plot(x,M,color='r',linewidth=1)
plt.fill_between(x,0,M)
plt.ylabel("M")
plt.xlabel("x")
plt.ylim(np.max(M*1.1),np.min(M*1.1))
plt.subplot(2,1,2)
plt.plot(x,theta,color='y',label='theta',linewidth=2)
plt.plot(x,w,color='b',label='w',linewidth=3,linestyle='--')
plt.grid()#添加网格
plt.legend()#显示不同的文本
plt.show()