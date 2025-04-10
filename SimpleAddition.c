#include <stdio.h>

#define OFFSET 0.3
#define TIME 100
#define BITWIDTH 64

// 共用体，構造体と同じように使えるがメモリ領域は共有する
// long, double ともに 8byte であることを仮定
// Windows の gcc だと sizeof(long) != sizeof(double) なので注意
typedef union {
  double d;
  long p;
} DL;

// Windows
if (sizeof(double) != sizeof(long)) {
  printf("Size of double doesn't match size of long\n");
  exit(-1);
}

int main(void) {

  // 共用体の型の変数を初期化し，0とする
  DL u;
  u.d = 0.0;

  // バイナリとして変数の変化を表示
  for (int i = 0; i < TIME; i++) {
    printf("%lx\n", u.p);
    u.d += OFFSET;
  }
  printf("%lx\n", u.p);

  // 最終的に理論的結果と一致するかを確認
  if (u.d == TIME * OFFSET) {
    printf("%d * %lf = %lf\n", TIME, OFFSET, TIME*OFFSET);
  } else {
    printf("%d * %lf != %lf\n", TIME, OFFSET, TIME*OFFSET);
  }
}
