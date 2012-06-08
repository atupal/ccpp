#include <stdlib.h>
#include <stdio.h>

int main(){
        freopen("input.dat", "r", stdin);
        float shui, dian;
        scanf("%f%f", &shui, &dian);
        int zhuzhi[6];
        int shuiKao[7];
        int dianKao[7];
        float shuiFei[7];
        float dianFei[7];
        shuiKao[6] = 0;
        dianKao[6] = 0;
        dianFei[6] = 0.0;
        shuiFei[6] = 0.0;
        int i;
        for(i = 0; i < 6; ++ i){
                scanf("%d%d", &shuiKao[i], &dianKao[i]);
                shuiFei[i] = (float) shuiKao[i] * shui;
                dianFei[i] = (float) dianKao[i] * dian;
                shuiKao[6] += shuiKao[i];
                dianKao[6] += dianKao[i];
                shuiFei[6] += shuiFei[i];
                dianFei[6] += dianFei[i];
        }
        printf("zhuzhi\tshuiKao\tshuiFei\tdianKao\tdianFei\tTotal\t\n");
        for(int i = 0; i < 6; ++ i){
                printf("%d\t%d\t%f\t%d\t%f\t%f\t\n", zhuzhi[i], shuiKao[i], shuiFei[i], dianKao[i], dianFei[i], dianFei[i] + shuiFei[i]);
        }
        printf("Total\t%d\t%f\t%d\t%f\t%f\t\n", shuiKao[6], shuiFei[6], dianKao[6], dianFei[6], dianFei[6] + shuiFei[6]);
        fclose(stdin);
        return 0;
}
