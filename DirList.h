#pragma once
/*�ļ��б����ķ�װ��
 *for windows, 20180720
*/
#include "FilePro.h"

class DirList {
public:
	static std::vector<FilePro> traverse(std::string path);
	static std::vector<std::string> getRoots();
	//��ȡϵͳ�̷�
};