/*������Դ��https://www.math.wustl.edu/~victor/mfmm/fourier/fft.c*/
/*��ʢ�ٴ�ѧ�Ľ�ѧ����*/
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define q 8      /* 2^q �㣬256 */
#define N (1<<q)  /* N�� FFT, iFFT */

typedef float real;
typedef struct {
    real Re;
    real Im;
} complex;

#ifndef PI
# define PI 3.14159265358979323846264338327950288
#endif

/*Ϊ�˸���˵������˼�룬������õݹ�ʵ�֣���������ΪN<=1*/
void fft(complex* v, int n, complex* tmp)
{
    if (n > 1) {   /* N��С��1��ֱ�ӷ���*/
        int k, m;    complex z, w, * vo, * ve;
        ve = tmp; vo = tmp + n / 2;
        for (k = 0; k < n / 2; k++) {
            ve[k] = v[2 * k];
            vo[k] = v[2 * k + 1];
        }
        fft(ve, n / 2, v);  /* FFT ż������ v[] */
        fft(vo, n / 2, v);  /* FFT ż������ v[] */
        for (m = 0; m < n / 2; m++) {
            w.Re = cos(2 * PI * m / (double)n);
            w.Im = -sin(2 * PI * m / (double)n);
            z.Re = w.Re * vo[m].Re - w.Im * vo[m].Im; /* Re(w*vo[m]) */
            z.Im = w.Re * vo[m].Im + w.Im * vo[m].Re; /* Im(w*vo[m]) */
            v[m].Re = ve[m].Re + z.Re;
            v[m].Im = ve[m].Im + z.Im;
            v[m + n / 2].Re = ve[m].Re - z.Re;
            v[m + n / 2].Im = ve[m].Im - z.Im;
        }
    }
    return;
}

/*Ϊ�˸���˵������˼�룬������õݹ�ʵ�֣���������ΪN<=1*/
void ifft(complex* v, int n, complex* tmp)
{
    if (n > 1) {
        int k, m;    complex z, w, * vo, * ve;
        ve = tmp; vo = tmp + n / 2;
        for (k = 0; k < n / 2; k++) {
            ve[k] = v[2 * k];
            vo[k] = v[2 * k + 1];
        }
        ifft(ve, n / 2, v);  /* FFT ż������ v[] */
        ifft(vo, n / 2, v);  /* FFT �������� v[] */
        for (m = 0; m < n / 2; m++) {
            w.Re = cos(2 * PI * m / (double)n);
            w.Im = sin(2 * PI * m / (double)n);
            z.Re = w.Re * vo[m].Re - w.Im * vo[m].Im; /* Re(w*vo[m]) */
            z.Im = w.Re * vo[m].Im + w.Im * vo[m].Re; /* Im(w*vo[m]) */
            v[m].Re = ve[m].Re + z.Re;
            v[m].Im = ve[m].Im + z.Im;
            v[m + n / 2].Re = ve[m].Re - z.Re;
            v[m + n / 2].Im = ve[m].Im - z.Im;
        }
    }
    return;
}

#define SAMPLE_RATE (10000.0f)
int main(void)
{
    complex v[N], scratch[N];
    float amp[N];
    int k;

    /*ģ��һ������ϵͳ��������Ϊ10KHz���������źţ�500Hz/2kHz*/
    for (k = 0; k < N; k++) {
        v[k].Re = 1 * sin(2 * PI * 500 * k / SAMPLE_RATE) + 0.5 * sin(2 * PI * 2000 * k / SAMPLE_RATE);
        v[k].Im = 0;//ʵ���źŴ���ʱ���鲿��Ϊ0
    }

    /*���ģ���ź�*/
    for (int i = 0; i < N; i++)
    {
        printf("%f,", v[i].Re);
    }
    printf("\n");
    fft(v, N, scratch);

    for (int i = 0; i < N; i++)
    {
        printf("%f,", sqrt(v[i].Re * v[i].Re + v[i].Im * v[i].Im));
    }
    printf("\n");
    while (1);
}

