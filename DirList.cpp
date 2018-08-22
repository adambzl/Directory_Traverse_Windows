#include "DirList.h"
//����һ���ļ�·�������ظ�·���µ������ļ����ļ���
//�����ص�·����һ���ļ��У�ȡֵΪtrue������Ϊfalse

std::vector<FilePro> DirList::traverse(std::string path) {
	std::vector<FilePro> results;
	_finddata_t file;
	long flag;
	std::string filename = path + "\\*";
	//��Ч���ļ���·�����ٰ���һЩϵͳ�����ļ�
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
	//��ȡϵͳ�̷��ַ�������
	char *driveString = new char[len];
	GetLogicalDriveStrings(len, driveString);
	//��ȡϵͳ�̷��ַ��������ý����ʽΪC:\\0D:\\0E:\\0F:\\0G:\\0
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
		//��λ����һ�ַ���
	}
	delete driveString;
	return results;
}