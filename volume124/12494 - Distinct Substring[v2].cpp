#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
using namespace std;
int MinExp(const char *s, const int slen) {
	int i = 0, j = 1, k = 0, x, y, tmp;
	while(i < slen && j < slen && k < slen) {
		x = i + k;
		y = j + k;
		if(x >= slen)	x -= slen;
		if(y >= slen)	y -= slen;
		if(s[x] == s[y]) {
			k++;
		} else if(s[x] > s[y]) {
			i = j+1 > i+k+1 ? j+1 : i+k+1;
			k = 0;
			tmp = i, i = j, j = tmp;
		} else {
			j = i+1 > j+k+1 ? i+1 : j+k+1;
			k = 0;
		}
	}
	return i;
}
int main() {
    int t;
    char s[1005], ss[1005];
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        int len = strlen(s);
        int i, j, k;
        set<string> S[205];
        for(i = 0; i < len; i++) {
            for(j = 0; i+j < len; j++) {
                //s[i...i+j]
                int pos = MinExp(s+i, j+1)+i;
                //puts("");
                for(k = 0; k <= j; k++) {
                    ss[k] = s[pos];
                    pos++;
                    if(pos == i+j+1)    pos = i;
                }
                ss[k] = '\0';
                S[k].insert(ss);
            }
        }
        int ret = 0;
        for(i = 0; i <= len; i++)
            ret += S[i].size();
        printf("%d\n", ret);
    }
    return 0;
}
