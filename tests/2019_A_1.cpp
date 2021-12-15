#include<stdio.h>

int peach(int m){
    //每份数量
    int per;
    //若m-1不是五的倍数，不满足分配要求
    if((m-1)%5!=0)
        return 0;
    per = (m-1)/5;
    //若每份的数量小于1，也不满足分配要求
    if(per<1)
        return 0;
    //扔掉一个桃子，然后取走其中五分之一
    m = m-1-per;
    return m;
}
int main(){
    int i,j,n,tem;
    //设桃子总数为n
    //每只猴子都是把剩余的桃子平均分成五份然后扔掉一个，取走其中一份
    //那么我们可以逆向来思考，就是从第五只猴子开始,先把自己拿的桃子放回去再捡回来1个丢到海里的桃子，就得到了上一次分完剩下的桃子
    //设第五只猴子至少取走了x个桃子
    for(n=1;;n++){
        tem = n;
        for(j=0;j<6;j++){
            //若tem=0,则说明分配失败
            if(tem==0)
                break;
            tem = peach(tem);
        }
        //j=5就是说明第五个猴子也分到桃子了
        if(j<6)
            continue;
        printf("至少有%d个桃子",n);
        break;
    }

    
    return 0;
}