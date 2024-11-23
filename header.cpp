#include "struct.h"

duongTron* taoDuongTron(float x, float y, float r)
{
	duongTron* d1 = new duongTron;
	d1->tam->x = x;
	d1->tam->y = y;
	d1->banKinh = r;
	return d1;
}

void xoaDuongTron(duongTron* p)
{
	delete p->tam;
	delete p;
}

void printDuongTron(ostream& os, duongTron* p)
{
	os << "[(" << p->tam->x << "," << p->tam->y << "), " << p->banKinh;
}

duongTron* chuViMax(duongTron** l, int n)
{
	duongTron * max = l[0];
	for (int i = 0; i < n; i++) {
		if (l[i]->banKinh > max->banKinh) {
			max = l[i];
		}
	}
	return max;
}

float tongDienTich(duongTron** l, int n)
{
	float r = 0;
	for (int i = 0; i < n; i++) {
		r += l[i]->banKinh;
	}
	return r * r * PI;
}

int xuatCacDuongTronDTLonHonTrungBinh(duongTron** l, int n)
{
	int count = 0;
	float sTB = tongDienTich(l, n) / n;
	for (int i = 0; i < n; i++) {
		if (l[i]->banKinh * l[i]->banKinh * PI > sTB) {
			count++;
		}
	}
	return count;
}

void xuatCacDuongTronChuViGiam(duongTron** l, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (l[i]->banKinh < l[j]->banKinh) {
				duongTron* temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printDuongTron(cout, l[i]);
		cout << " voi P=" << l[i]->banKinh * 2 * PI << endl;
	}
}

void xoaDsDuongTron(duongTron** l, int n)
{
	for (int i = 0; i < n; i++) {
		xoaDuongTron(l[i]);
	}
	delete[] l;
}
