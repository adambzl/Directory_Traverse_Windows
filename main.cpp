#include "DirList.h"

int main() {
	std::vector<std::string> roots = DirList::getRoots();
	std::vector<std::string>::iterator it = roots.begin();
	std::cout << "本机磁盘: ";
	while (it != roots.end())
		std::cout << *it++ << "\t";
	std::cout << std::endl;
	std::string path;
	char inputPath[100];
	while (1) {
		std::cout << "输入文件路径(退出exit)：";
		std::cin.getline(inputPath, 100);
		path = std::string(inputPath);
		if (path == "exit")
			break;
		else {
			std::vector<FilePro> results = DirList::traverse(path);
			std::vector<FilePro>::iterator it;
			if (results.empty()) {
				std::cout << "非法路径" << std::endl;
			}
			else {
				it = results.begin();
				std::cout << "名称\t创建时间\t是否为目录\t大小\t(其它属性未展示)" << std::endl;
				while (it != results.end()) {
					std::cout << (*it).getFilename() << "\t" << (*it).getCreated() << "\t" <<(*it).isSubdirectory()<<"\t"<< (*it).getSize() << std::endl;
					it++;
				}
			}
		}
	}
	
	return 0;
}