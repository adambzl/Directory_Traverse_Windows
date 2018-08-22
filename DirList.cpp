#include "DirList.h"
//给定一个文件路径，返回该路径下的所有文件与文件夹
//若返回的路径是一个文件夹，取值为true，否则为false

std::vector<FilePro> DirList::traverse(std::string path) {
	std::vector<FilePro> results;
	_finddata_t file;
	long flag;
	std::string filename = path + "\\*";
	//有效的文件夹路径至少包含一些系统隐藏文件
	if ((flag = _findfirst(filename.c_str(), &file)) == -1) {
		_findclose(flag);
		return results;
	}
	else {
		do {
			FilePro obj;
			if (file.attrib & 1 == 1)
				obj.setReadOnly(true);
			if ((file.attrib >> 1) & 1 == 1)
				obj.setHidden(true);
			if ((file.attrib >> 2) & 1 == 1)
				obj.setSystemFile(true);
			if ((file.attrib >> 4) & 1 == 1)
				obj.setSubdirectory(true);
			if ((file.attrib >> 5) & 1 == 1)
				obj.setArchive(true);
			std::string filename = path + "\\" + file.name;
			obj.setFilename(filename);
			obj.setCreated(file.time_create);
			obj.setModified(file.time_write);
			obj.setAttached(file.time_access);
			obj.setSize(file.size);
			results.push_back(obj);
		} while (_findnext(flag, &file) == 0);
		_findclose(flag);
		return results;
	}
}

std::vector<std::string> DirList::getRoots() {
	std::vector<std::string> results;
	DWORD len = GetLogicalDriveStrings(0, NULL);
	//获取系统盘符字符串长度
	char *driveString = new char[len];
	GetLogicalDriveStrings(len, driveString);
	//获取系统盘符字符串，所得结果形式为C:\\0D:\\0E:\\0F:\\0G:\\0
	char *p = driveString;
	while (*p != '\0') {
		std::string drive = std::string(p);
		std::string query = drive + "*";
		_finddata_t file;
		long flag;
		if ((flag = _findfirst(query.c_str(), &file)) == -1) {
			p += strlen(p) + 1;
			_findclose(flag);
			continue;
		}
		results.push_back(drive);
		p += strlen(p) + 1;
		_findclose(flag);
		//定位到下一字符串
	}
	delete driveString;
	return results;
}