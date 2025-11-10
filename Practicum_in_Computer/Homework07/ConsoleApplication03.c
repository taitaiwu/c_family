# include <stdio.h>

int main (void) //98
{
    int by, bm, bd, ey, em, ed;
    int i;
    int sum = 0;
    int begin, end;
    
    printf("請輸入西元開始日期(yyyy/mm,dd)為...");
    scanf("%d/%d/%d", &by, &bm, &bd);
    printf("請輸入西元結束日期(yyyy/mm,dd)為...");
    scanf("%d/%d/%d", &ey, &em, &ed);
    
    if (by % 400 == 0) begin = by;
    else begin = by + 400 - (by % 400);
    
    if (ey % 400 == 0) end = ey;
    else end = ey - ey % 400;
    
    sum = 97 * ((end - begin) / 400);
    
    for (i = end+1; i <= ey; i++)
    {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) sum++;
    }
    
    if (bm > 3 && (((by % 4 == 0 && by % 100 != 0) || (by % 400 == 0)))) sum--;
    if (em > 2 && (((ey % 4 == 0 && ey % 100 != 0) || (ey % 400 == 0)))) sum++;
    
    printf("此期間的2月29日共有 %d 次", sum);
}
