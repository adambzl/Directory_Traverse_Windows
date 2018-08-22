#include "DirList.h"

int main() {
	std::vector<std::string> roots = DirList::getRoots();
	std::vector<std::string>::iterator it = roots.begin();
	std::cout << "��������: ";
	while (it != roots.end())
		std::cout << *it++ << "\t";
	std::cout << std::endl;
	std::string path;
	char inputPath[100];
	while (1) {
		std::cout << "�����ļ�·��(�˳�exit)��";
		std::cin.getline(inputPath, 100);
		path = std::string(inputPath);
		if (path == "exit")
			break;
		else {
			std::vector<FilePro> results = DirList::traverse(path);
			std::vector<FilePro>::iterator it;
			if (results.empty()) {
				std::cout << "�Ƿ�·��" << std::endl;
			}
			else {
				it = results.begin();
				std::cout << "����\t����ʱ��\t�Ƿ�ΪĿ¼\t��С\t(��������δչʾ)" << std::endl;
				while (it != results.end()) {
					std::cout << (*it).getFilename() << "\t" << (*it).getCreated() << "\t" <<(*it).isSubdirectory()<<"\t"<< (*it).getSize() << std::endl;
					it++;
				}
			}
		}
	}
	
	return 0;
}