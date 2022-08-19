#include <stdio.h>
// 从第 s 位到第 t 位，输出 n 的比特值
// s > t, s 是高位，t 是低位
void print_bits ( int n, int s, int t )
{
	for( ; s>=t; s-- ) {
		int mask = 1<<s; //生成掩码
		if( mask & n )   //掩码对应的bit值
			putchar('1');
		else 
			putchar('0');
	}
}
// 输出 n 个空格
void print_space(int n)
{
	while( n-->0 )
		printf(" ");
}
// 获取浮点数的符号
int get_float_sign ( float x )
{
	int n = *(int*)&x; //复制到int变量中
	int mask = 1<<31;  //生成符号位的掩码
	return mask & n ? -1 : 1;
}
// 获取浮点数阶码
int get_float_exp ( float x )
{
	int n = *(int*)&x; //复制到int变量中 
	n = (n >> 23) & 0xFF;
	n = n - 127;
	return n;
}
// 获取浮点数的尾数
float get_float_mantissa ( float x )
{
	int n = *(int*)&x; //复制到int变量中
	int e = n & (0XFF<<23); // 阶码段
	n &= ~(0X1FF<<23); // 符号位和阶码段清零
	if( e ) {//不全为0
		n |= 0x7F<<23; // 阶码段置为0X7F（0x7F=01111111, 代表指数为0）
	}
	return *(float*)&n;
}

//输出浮点数
void print_float(float x)
{
	print_bits( *(int*)&x, 31, 31 ); 
	printf("<%c> ", get_float_sign(x)>0?'+':'-');
	print_bits(*(int*)&x, 30, 23 ); print_space(1);
	printf("<%-4d> ", get_float_exp(x));
	print_bits(*(int*)&x, 22, 0 );
	printf(" <%f>\n", get_float_mantissa(x));
}

void print_float_head()
{
	printf("符号 阶码段   <指数> 尾数段                  <尾数>\n");
}

int main()
{
	float fx, man;
	printf("输入一个浮点数:");
	scanf("%f", &fx);
	printf("符号 阶码段   <指数> 尾数段                  <尾数>\n");
	print_float(fx);
	return 0;
} 
