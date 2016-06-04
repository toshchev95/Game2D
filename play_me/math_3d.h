#ifndef MATH_3D_H
#define	MATH_3D_H

#define v3f Vector3<float> // ���������� ������ �� float
#define v3i Vector3<int>	// ���������� ������ �� int

template <class T>
struct Vector2;		// ��������������� ������ ���������� ��������

template <class T>
struct Vector3		// ���������� �������
{
    T x;		// ����������
    T y;
    T z;
	Vector3 () {}	// ������ �����������
	Vector3 (T _x, T _y, T _z) {	// ����������� 3-� ���������
		x = _x;
		y = _y;
		z = _z;
	}
	Vector3 (Vector2 <T> v2);		// ����������� ���������� ����������� ������� �� �����������
	Vector3& operator = (const Vector3& r);		// ��������� ������������, +=, -=, *=, /=, +, -, *, /, ==, !=
	Vector3& operator += (const Vector3& r); 
	Vector3& operator -= (const Vector3& r); 
	Vector3& operator *= (const float r); 
	Vector3& operator /= (const float r);
	Vector3 operator + (const Vector3& r); 
	Vector3 operator - (const Vector3& r); 
	Vector3 operator * (const float r); 
	Vector3 operator / (const float r); 
	bool operator == (const Vector3& r) {return x == r.x && y == r.y && z == r.z;}
	bool operator != (const Vector3& r) {return x != r.x || y != r.y || z != r.z;}
};

template <class T>
Vector3 <T>& Vector3<T>::operator = (const Vector3 <T>& r) {
	x = r.x;
	y = r.y;
	z = r.z;
	return (*this);
}

template <class T>
Vector3 <T>& Vector3 <T>::operator += (const Vector3 <T>& r) {
	x += r.x;
	y += r.y;
	z += r.z;
	return (*this);
}

template <class T>
Vector3 <T>& Vector3 <T>::operator -= (const Vector3 <T>& r) {
	x -= r.x;
	y -= r.y;
	z -= r.z;
	return (*this);
}

template <class T>
Vector3 <T>& Vector3 <T>::operator *= (const float r) {
	x *= r;
	y *= r;
	z *= r;
	return (*this);
}

template <class T>
Vector3 <T>& Vector3 <T>::operator /= (const float r) {
	x /= r;
	y /= r;
	z /= r;
	return (*this);
}

template <class T>
Vector3 <T> Vector3 <T>::operator + (const Vector3 <T>& r) {
	return Vector3 <T> (x + r.x, y + r.y, z + r.z);
}

template <class T>
Vector3 <T> Vector3 <T>::operator - (const Vector3 <T>& r) {
	return Vector3 <T> (x - r.x, y - r.y, z - r.z);
}

template <class T>
Vector3 <T> Vector3 <T>::operator * (const float r) {
	return Vector3 <T> (x * r, y * r, z * r);
}

template <class T>
Vector3 <T> Vector3 <T>::operator / (const float r) {
	return Vector3 <T> (x / r, y / r, z / r);
}

template <class T>
Vector3 <T>::Vector3 (Vector2 <T> v2) {
	x = v2.x;
	y = v2.y;
	z = 0;
}

struct v2f;

struct v2i		// ���������� �������
{
    int x;	// ����������
    int y;
	
	v2i () {}		// ������ �����������
	v2i (int _x, int _y) {		//����������� ���������
		x = _x;
		y = _y;
	}
	v2i (Vector3 <int> v3) {  // ����������� ������� ����������� ������� �� �����������
		x = v3.x;
		y = v3.y;
	}
	v2i& operator = (const v2i& r);		// ���������
	v2i& operator += (const v2i& r);
	v2i& operator -= (const v2i& r);
	v2i& operator *= (const float r);
	v2i& operator /= (const float r);
	v2i operator + (const v2i& r);
	v2i operator - (const v2i& r);
	v2i operator - ();
	v2i operator * (const float r);
	v2i operator / (const float r);
	bool operator == (const v2i& r) {return x == r.x && y == r.y;}
	bool operator != (const v2i& r) {return x != r.x || y != r.y;}
	v2i (const v2f &v);
};

struct v2f		// ���������� �������
{
    float x;	// ����������
    float y;
	
	v2f () {}		// ������ �����������
	v2f (float _x, float _y) {		//����������� ���������
		x = _x;
		y = _y;
	}
	v2f (Vector3 <float> v3) {  // ����������� ������� ����������� ������� �� �����������
		x = v3.x;
		y = v3.y;
	}
	v2f& operator = (const v2f& r);		// ���������
	v2f& operator += (const v2f& r);
	v2f& operator -= (const v2f& r);
	v2f& operator *= (const float r);
	v2f& operator /= (const float r);
	v2f operator + (const v2f& r);
	v2f operator - (const v2f& r);
	v2f operator - ();
	v2f operator * (const float r);
	v2f operator / (const float r);
	bool operator == (const v2f& r) {return x == r.x && y == r.y;}
	bool operator != (const v2f& r) {return x != r.x || y != r.y;}
	v2f (const v2i &v) {
		x = v.x;
		y = v.y;
	}
};

float length (v2i v);
float length (v2f v);

#define me (*this)
#define FOR(z, N)   for (int z = 0; z < N; ++z)

// ������� 4 �� 4
struct Matrix4f
{
    float m[4][4];
    void operator *= (Matrix4f w);
};

// �������, �������� ���������� ��������. ������������� ���������
struct Vertex_tex {
	v3f pos;
	v2f tex_coord;
	Vertex_tex () {}
	Vertex_tex (v3f _pos, v2f _tex_coord) {
		pos = _pos;
		tex_coord = _tex_coord;
	}
};

// ������������� �� ���������, ������������� ���� ���������. ������ ���������. ������
template <class T>
struct Rect {
	Vector2 <T> pos;  // ������� ����� �����
	Vector2 <T> size;	// ������ ������
	Rect () {}
	Rect (Vector2 <T> _pos, Vector2 <T> _size) {
		pos = _pos;
		size = _size;
	}
	//����������� �� ����� ��������������
	bool operator << (Vector2 <T> v) {
		return v.x >= pos.x && v.x < pos.x + size.x &&
			v.y >= pos.y && v.y < pos.y + size.y;
	}
};

#endif	/* MATH_3D_H */