#include "fadma.h"

inline double rad_ (double degree) {return degree * Pi / 180;}			// ������� ���� �� �������� � �������
inline double deg_ (double radian) {return radian * 180 / Pi;}			// ������� ���� �� ������ � �������

int fadma_zero_for_err_break = 0;