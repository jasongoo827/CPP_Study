#include <bits/stdc++.h>

using namespace std;

typedef struct {
	char cerial[51];
}DATA;

int n;
DATA CSet[1001];

int getSum(DATA a)
{
	int sum = 0;
	for (int i = 0; i < strlen(a.cerial); i++) {
		if (0<=a.cerial[i]-'0'&& a.cerial[i] - '0' <=9) {
			sum += a.cerial[i] - '0';
		}
	}
	return sum;
}

bool cmp(DATA a, DATA b)
{
	if (strlen(a.cerial) < strlen(b.cerial)) return true;
	else if (strlen(a.cerial) == strlen(b.cerial)) {
		if (getSum(a) < getSum(b)) return true;
		else if (getSum(a) == getSum(b)) {
			if (strcmp(a.cerial, b.cerial) < 0) return true;
		}
	}
	return false;
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &CSet[i].cerial);
	}
	sort(CSet, CSet + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%s\n", &CSet[i].cerial);
	}
	
}