#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int node_num, tri_bd_num, quad_bd_num, tet_num, pyramid_num, prism_num, hex_num;
	node_num = tri_bd_num = quad_bd_num = tet_num = pyramid_num = prism_num = hex_num = 0;
	ofstream fout("test.ugrid");
	ifstream fin("ugrid_bin.ugrid", ios::binary | ios::in);

	if (!fin.is_open())
	{
		cout << "�ļ�δ��������" << endl;
		return 0;
	}
	if (!fout.is_open())
	{
		cout << "�ļ��������" << endl;
	}

	fin.read((char*)&node_num, sizeof(int));
	fin.read((char*)&tri_bd_num, sizeof(int));
	fin.read((char*)&quad_bd_num, sizeof(int));
	fin.read((char*)&tet_num, sizeof(int));
	fin.read((char*)&pyramid_num, sizeof(int));
	fin.read((char*)&prism_num, sizeof(int));
	fin.read((char*)&hex_num, sizeof(int));

	fout << node_num << " " << tri_bd_num << " " << quad_bd_num << " " << tet_num << " " << pyramid_num << " " << prism_num << " " << hex_num << endl;

	// �߽�����Ŀ��ʵ��Ԫ��Ŀ
	int bd_fac_num = tri_bd_num + quad_bd_num;
	int ele_num = tet_num + pyramid_num + prism_num + hex_num;
	
	// ������
	double* Node = new double[node_num * 3];

	// �����α߽���ĵ�����
	int *tri_bd_fac = new int[tri_bd_num*3];
	// �ı��α߽���ĵ�����
	int* quad_bd_fac = new int[quad_bd_num*4];
	// �߽���Ԫ��Ӧ��surface ID
	int* fac_type = new int[bd_fac_num];
	// �����嵥Ԫ�ĵ�����
	int* tet = new int[tet_num * 4];
	// ��������Ԫ�ĵ�����
	int* pyramid = new int[pyramid_num * 5];
	// ��������Ԫ�ĵ�����
	int* prism = new int[prism_num * 6];
	// �����嵥Ԫ�ĵ�����
	int* hex = new int[hex_num * 8];

	// ��ȡ������
	fin.read((char*)Node, sizeof(double) * 3 * node_num);
	for (auto i = 0; i < node_num; i++)
	{
		fout << Node[i * 3 + 0] << " " << Node[i * 3 + 1] << " " << Node[i * 3 + 2] << endl;
	}

	// ��ȡ�����α߽���ĵ�����
	fin.read((char*)tri_bd_fac, sizeof(int) * 3 * tri_bd_num);
	for (auto i = 0; i < tri_bd_num; i++)
	{
		fout << tri_bd_fac[i * 3 + 0] << " " << tri_bd_fac[i * 3 + 1] << " " << tri_bd_fac[i * 3 + 2] << endl;
	}
	
	// ��ȡ�Ľ��α߽���ĵ�����
	fin.read((char*)quad_bd_fac, sizeof(int) * 4 * quad_bd_num);
	for (auto i = 0; i < quad_bd_num; i++)
	{
		fout << quad_bd_fac[i * 4 + 0] << " " << quad_bd_fac[i * 4 + 1] << " " 
			<< quad_bd_fac[i * 4 + 2]<<" " << quad_bd_fac[i * 4 + 3] << endl;
	}
	
	// ��ȡ�߽���Ԫ��Ӧ�� surface ID
	fin.read((char*)fac_type, sizeof(int)*bd_fac_num);
	for (auto i = 0; i < bd_fac_num; i++)
	{
		fout << fac_type[i] << endl;
	}
	
	// ��ȡ�����嵥Ԫ�ĵ�����
	fin.read((char*)tet, sizeof(int) * 4 * tet_num);
	for (auto i = 0; i < tet_num; i++)
	{
		fout << tet[4 * i + 0] << " " << tet[4 * i + 1] << " "
			<< tet[4 * i + 2] << " " << tet[4 * i + 3] << endl;
	}

	// ��ȡ��������Ԫ�ĵ�����
	fin.read((char*)pyramid, sizeof(int) * 5 * pyramid_num);
	for (auto i = 0; i < pyramid_num; i++)
	{
		fout << pyramid[4 * i + 0] << " " << pyramid[4 * i + 1] << " "
			<< pyramid[4 * i + 2] << " " << pyramid[4 * i + 3] << " "
			<< pyramid[4 * i + 4] << endl;
	}

	// ��ȡ��������Ԫ�ĵ�����
	fin.read((char*)prism, sizeof(int) * 6 * prism_num);
	for (auto i = 0; i < prism_num; i++)
	{
		fout << prism[4 * i + 0] << " " << prism[4 * i + 1] << " "
			<< prism[4 * i + 2] << " " << prism[4 * i + 3] << " "
			<< prism[4 * i + 4] << " " << prism[4 * i + 5] << endl;
	}

	// ��ȡ�����嵥Ԫ�ĵ�����
	fin.read((char*)hex, sizeof(int) * 8 * hex_num);
	for (auto i = 0; i < hex_num; i++)
	{
		fout << hex[4 * i + 0] << " " << hex[4 * i + 1] << " "
			<< hex[4 * i + 2] << " " << hex[4 * i + 3] << " "
			<< hex[4 * i + 4] << " " << hex[4 * i + 5] << " "
			<< hex[4 * i + 6] << " " << hex[4 * i + 7] << endl;
	}

	fin.close();
	fout.close();

	// ������
	delete[] Node;
	delete[] tri_bd_fac;
	delete[] quad_bd_fac;
	delete[] fac_type;
	delete[] tet;
	delete[] pyramid;
	delete[] prism;
	delete[] hex;

	return 0;
}