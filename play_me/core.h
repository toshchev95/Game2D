#pragma once
#include "object.h"
#include "Renderer.h"
#include "space.h"
#include <vector>
#include <map>

using namespace std;

// ����. ������� �����. ������ ����� ������ ���������� � ������������ ����������. �� - ������ ���������.
class Core {
public:
	void init ();	// ���������� ���� ��� ��� �������������
	void update (float dt);		// ���������� ����� � ���. dt - ��������� ����� � �������� �����
	void render ();				// ���������� ����

	Renderer m_renderer;		// ���� ������, ������������ ����������
	State m_current_state;		// ������� ��������� ��������
	Type m_active_type;
	map <string, Space *> m_spaces;	// ��� ������
	vector <Space *> m_current_spaces;	// �������� ������ ������. ������ ��� ��� ���������� ������� ���������� � ���������

	Core () {}	// �����������
	~Core () {	// ����������
		forstl (p, m_spaces) {
			delete p->second;
		}
	}
};

extern Core core;

#define D_OBJ(str) core.m_spaces[(str)]->m_objects
#define D_PLATFORM(type) (type *) D_OBJ("platform")[#type]