# Topic [Hacker Rank](https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true) <- click here

## Mã tham khảo

```cpp
int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    long cost = 0; // initial cost
    int i = 0;// count 
    while(cost<s){
        int tmp =(p-i*d)>m? p-i*d:m;
        cost+=tmp;
        if(cost>s) break;
        i++; 
    }
    return i;
}
```


