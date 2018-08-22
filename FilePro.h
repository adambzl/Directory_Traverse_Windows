#pragma once
/*�ļ����Եķ�װ�࣬��һЩ��Ҫ����ת��Ϊ�ɶ���ʽ
 *for windows, 20180720
*/
#include "standard.h"
//һЩ����ͷ�ļ�Ӧ�÷ŵ�һ��ͷ�ļ�������������ͷ�ļ�����

class FilePro {
private:
	bool readOnly;
	//�Ƿ�Ϊֻ��
	bool hidden;
	//�Ƿ�Ϊ����
	bool systemFile;
	//ϵͳ����
	bool subdirectory;
	//�Ƿ�Ϊ�ļ���
	bool archive;
	//�鵵����
	std::string filename;
	//�ļ����ļ�����
	std::string created;
	//����ʱ��
	std::string modified;
	//����޸�ʱ��
	std::string attached;
	//������ʱ��
	_fsize_t size;
	//���ֽڱ�ʾ���ļ���С
public:
	FilePro() :readOnly(false), hidden(false), systemFile(false), subdirectory(false), archive(false), size(0) {}
	void setReadOnly(bool readOnly) {
		this->readOnly = readOnly;
	}
	void setHidden(bool hidden) {
		this->hidden = hidden;
	}
	void setSystemFile(bool systemFile) {
		this->systemFile = systemFile;
	}
	void setSubdirectory(bool subdirectory) {
		this->subdirectory = subdirectory;
	}
	void setArchive(bool archive) {
		this->archive = archive;
	}
	void setFilename(std::string filename) {
		this->filename = filename;
	}
	void setCreated(time_t time);
	void setModified(time_t time);
	void setAttached(time_t time);
	void setSize(_fsize_t size) {
		this->size = size;
	}
	bool isReadOnly() { return readOnly; }
	bool isHidden() { return hidden; }
	bool isSystemFile() { return systemFile; }
	bool isSubdirectory() { return subdirectory; }
	bool isArchive() { return archive; }
	_fsize_t getSize() { return size; }
	std::string getFilename() { return filename; }
	std::string getCreated() { return created; }
	std::string getModified() { return modified; }
	std::string getAttached() { return attached; }
};