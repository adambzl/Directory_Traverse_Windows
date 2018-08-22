#pragma once
/*文件夹遍历的封装类
 *for windows, 20180720
*/
#include "FilePro.h"

class DirList {
public:
	static std::vector<FilePro> traverse(std::string path);
	static std::vector<std::string> getRoots();
	//获取系统盘符
};