#pragma once
/*文件属性的封装类，将一些重要属性转换为可读形式
 *for windows, 20180720
*/
#include "standard.h"
//一些公共头文件应该放到一个头文件中用于其它的头文件包含

class FilePro {
private:
	bool readOnly;
	//是否为只读
	bool hidden;
	//是否为隐藏
	bool systemFile;
	//系统属性
	bool subdirectory;
	//是否为文件夹
	bool archive;
	//归档属性
	std::string filename;
	//文件或文件夹名
	std::string created;
	//创建时间
	std::string modified;
	//最后修改时间
	std::string attached;
	//最后访问时间
	_fsize_t size;
	//以字节表示的文件大小
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