#include <bits/stdc++.h>
using namespace std;

struct SkyTree {
  int weight;
  int height;
};

void sum(int *num) {
  cout << "num: " << num << endl;
  cout << "num*: " << *num << endl;
  *num += 10;
}

void pointer() {
  int num = 100;
  int* p = &num;
  cout << "p: " << p << endl;
  cout << "*p: " << *p << endl;
}

void modifySkyTreeProps(const SkyTree &skyTreeProps) {
  cout << "skyTreeProps: " << &skyTreeProps << endl;
  cout << "height: " << skyTreeProps.height << endl;
}

int main() {
  // ポインタ変数とアドレス演算子
  int i = 42;
  int* p = &i;
  int r1 = *p;
  cout << p << endl;
  cout << r1 << endl;

  // 関数へのポインタ渡し
  sum(&i);

  // ポインタ変数
  pointer();

  // 構造体
  const struct SkyTree skyTree = {100, 634};
  cout << "&skyTree: " << &skyTree << endl;
  cout << "skyTree.height: " << skyTree.height << endl;
  modifySkyTreeProps(skyTree);
}