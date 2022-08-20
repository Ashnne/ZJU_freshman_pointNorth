#include <stdio.h>
// �ӵ� s λ���� t λ����� n �ı���ֵ
// s > t, s �Ǹ�λ��t �ǵ�λ
void print_bits ( int n, int s, int t )
{
	for( ; s>=t; s-- ) {
		int mask = 1<<s; //��������
		if( mask & n )   //�����Ӧ��bitֵ
			putchar('1');
		else 
			putchar('0');
	}
}
// ��� n ���ո�
void print_space(int n)
{
	while( n-->0 )
		printf(" ");
}
// ��ȡ�������ķ���
int get_float_sign ( float x )
{
	int n = *(int*)&x; //���Ƶ�int������
	int mask = 1<<31;  //���ɷ���λ������
	return mask & n ? -1 : 1;
}
// ��ȡ����������
int get_float_exp ( float x )
{
	int n = *(int*)&x; //���Ƶ�int������ 
	n = (n >> 23) & 0xFF;
	n = n - 127;
	return n;
}
// ��ȡ��������β��
float get_float_mantissa ( float x )
{
	int n = *(int*)&x; //���Ƶ�int������
	int e = n & (0XFF<<23); // �����
	n &= ~(0X1FF<<23); // ����λ�ͽ��������
	if( e ) {//��ȫΪ0
		n |= 0x7F<<23; // �������Ϊ0X7F��0x7F=01111111, ����ָ��Ϊ0��
	}
	return *(float*)&n;
}

//���������
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
	printf("���� �����   <ָ��> β����                  <β��>\n");
}

int main()
{
	float fx, man;
	printf("����һ��������:");
	scanf("%f", &fx);
	printf("���� �����   <ָ��> β����                  <β��>\n");
	print_float(fx);
	return 0;
} 
