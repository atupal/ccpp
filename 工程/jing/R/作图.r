#�鿴��������,�滻�ļ�������
read.table(file='E:/download/MoonData.txt',header=F)->pre
plot(x=pre$V1, y=pre$V2, type='p',pch=3)

#�鿴�������������,�滻�ļ�������
read.table(file='E:/src/R/out.txt', header=F)->post
plot(x=post$V1, y=post$V2, type='p',pch=3, col=(post$V3+1))
#col=(post$V3+1))