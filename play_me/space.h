#pragma once
#include "object.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

// ����� ��� � ����� �������� �������
struct Space {
	vector <Object *> m_objects_to_update;	// ������������������ ��������, ������� ���� ��������
	vector <Object *> m_objects_to_render;	// ������������������ ��������, ������� ���� ����������
	map <string, Object *> m_objects;	// ���������� �������
	Space (string name);	// �����������
	~Space () {				// ����������
		forstl (p, m_objects) {
			delete p->second;
		}
	}
};